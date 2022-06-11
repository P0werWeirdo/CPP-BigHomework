#include "signforpackagewindow.h"
#include "ui_signforpackagewindow.h"
#include<QMessageBox>
#include"package.h"
#include<QCheckBox>
#include"packageinfowindow.h"
#include"userinfowindow.h"
#include"distributewindow.h"

SignForPackageWindow::SignForPackageWindow(User *c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignForPackageWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("签收快递");
    this->setWindowModality(Qt::WindowModal);

    /*初始化类内对象*/
    theUser = c;

    /*初始化表格*/
    initTable();

    /*初始化逻辑*/
    initLogic();

    /*展示未签收包裹*/
    showAllPkg();

}

void SignForPackageWindow::initTable(){
    /*初始化表格*/
    if(theUser->getType() == 1){
        ui->PkgListTb->setColumnCount(4);
        ui->PkgListTb->setHorizontalHeaderLabels(QStringList()<<"快递单号"<<"发送方账号"<<"发送方姓名"<<"价格");
    }
    else if(theUser->getType() == 2){
        ui->PkgListTb->setColumnCount(4);
        ui->PkgListTb->setHorizontalHeaderLabels(QStringList()<<"快递单号"<<"发送方账号"<<"发送方姓名"<<"是否签收");
    }
    else{
        ui->PkgListTb->setColumnCount(5);
        ui->PkgListTb->setHorizontalHeaderLabels(QStringList()<<"快递单号"<<"发送方账号"<<"发送方姓名"<<"价格"<<"是否揽收");
    }
    ui->PkgListTb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->PkgListTb->setCornerButtonEnabled(false);
}

void SignForPackageWindow::initLogic(){
    /*初始化逻辑*/
    if(theUser->getType() == 1){    //管理员
        ui->btn_Sign->setText("分配包裹");
        connect(ui->btn_Sign,&QPushButton::clicked,this,&SignForPackageWindow::distributePkg);
    }
    else if(theUser->getType() == 2){   //客户
        connect(ui->btn_Sign,&QPushButton::clicked,[=](){
            if(signAllPkg()){
                QMessageBox::about(this,"签收成功","您已经签收了所选的包裹");
                this->close();
            }
            else{
                QMessageBox::critical(this,"签收失败","部分包裹未能签收");
                showAllPkg();
            }
        });
    }
    else{       //快递员
        ui->btn_Sign->setText("揽收全部");
        connect(ui->btn_Sign,&QPushButton::clicked,[=](){
            if(collectAllPkg()){
                QMessageBox::about(this,"揽收成功","您已经揽收了所选的包裹");
                emit collectFinish();
                this->close();
            }
            else{
                QMessageBox::critical(this,"揽收失败","部分包裹未能揽收");
                showAllPkg();
            }
        });
    }
    connect(ui->PkgListTb,&QTableWidget::itemDoubleClicked,this,&SignForPackageWindow::showDetailInfo);
}

//分配包裹
void SignForPackageWindow::distributePkg(){
    int row = ui->PkgListTb->currentRow();
    if(row < 0 || row >= ui->PkgListTb->rowCount()){
        QMessageBox::critical(this,"错误","请先选择一个包裹");
        return;
    }
    if(!Package::packageList.contains(ui->PkgListTb->item(row,0)->text())){
        QMessageBox::critical(this,"错误","包裹不存在");
        return;
    }

    Package *pkg = Package::packageList[ui->PkgListTb->item(row,0)->text()];

    //展示分配窗口
    DistributeWindow *newWindow = new DistributeWindow(pkg,this);
    connect(newWindow,&DistributeWindow::distributeFinish,[=](){
        showAllPkg();
    });
    newWindow->show();
}

void SignForPackageWindow::showDetailInfo(QTableWidgetItem *item){
    /*展示详细信息*/
    if(item->column() == 0){
        PackageInfoWindow *pkgInfo = new PackageInfoWindow(
                    Package::packageList[item->text()],this);
        pkgInfo->show();

    }
    else if(item->column() == 1){
        UserInfoWindow *userInfo = new UserInfoWindow(
                    Client::clientList[item->text()],1,this);
        userInfo->show();
    }
}

//签收包裹
bool SignForPackageWindow::signAllPkg()const{
    QList<Package *> tmp;
    Client *theClient = (Client *)this->theUser;
    int totalRow = ui->PkgListTb->rowCount();
    for(int i = 0;i < totalRow;i++){
        //被选中的入列
        if(ui->PkgListTb->item(i,3)->checkState() == Qt::Checked){
            if(theClient->getMyPackage().contains(ui->PkgListTb->item(i,0)->text())){
                tmp.push_back(theClient->getMyPackage()[ui->PkgListTb->item(i,0)->text()]);
              }
        }
    }

    return theClient->recvPackage(tmp);
}

//揽收包裹
bool SignForPackageWindow::collectAllPkg()const{
    QList<Package *> tmp;
    Courier *theCourier = (Courier *)this->theUser;
    int totalRow = ui->PkgListTb->rowCount();
    for(int i = 0;i < totalRow;i++){
        //被选中的入列
        if(ui->PkgListTb->item(i,4)->checkState() == Qt::Checked){
            if(theCourier->getMyPackage().contains(ui->PkgListTb->item(i,0)->text())){
                tmp.push_back(theCourier->getMyPackage()[ui->PkgListTb->item(i,0)->text()]);
              }
        }
    }

    return theCourier->collectPackage(tmp);
}

//展示包裹
void SignForPackageWindow::showAllPkg(){

    QMap<QString, Package *> map = theUser->getMyPackage();
    if(theUser->getType() == 1){            //管理员
        /*计算总共行数*/
        int totalRow = 0;
        for(auto i = map.constBegin(); i != map.constEnd(); i++){
                if(i.value()->getStatus() == 3 && i.value() ->getCollector() == NULL){
                    totalRow ++;
                }
        }
        ui->PkgListTb->setRowCount(totalRow);
        //是否有分配权限
        if(totalRow == 0){
            ui->btn_Sign->hide();
        }
        else{
            ui->btn_Sign->show();
        }
        //渲染
        int row = 0,col = 0;
        for(auto i = map.constBegin(); i != map.constEnd(); i++){
            col = 0;
            if(i.value()->getStatus() == 3 && i.value() ->getCollector() == NULL){
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getIndex()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getSender()->getUsername()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getSender()->getName()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(QString::number(i.value()->getPrice())));
                row++;
            }
        }
    }
    else if(theUser->getType() == 2){
        /*计算总共行数*/
        int totalRow = 0;
        for(auto i = map.constBegin(); i != map.constEnd(); i++){
                if(i.value()->getStatus() == 1 && i.value() ->getRecver() == theUser){
                    totalRow ++;
                }
        }
        ui->PkgListTb->setRowCount(totalRow);
        //是否有签收权限
        if(totalRow == 0){
            ui->btn_Sign->hide();
        }
        else{
            ui->btn_Sign->show();
        }

        int row = 0,col = 0;
        for(auto i = map.constBegin(); i != map.constEnd(); i++){
            col = 0;
            if(i.value()->getStatus() == 1 && i.value() ->getRecver() == theUser){
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getIndex()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getSender()->getUsername()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getSender()->getName()));
                QTableWidgetItem *checkbox = new QTableWidgetItem;
                checkbox->setCheckState(Qt::Unchecked);
                ui->PkgListTb->setItem(row,col++,checkbox);
                row++;
            }
        }
    }
    else{
        /*计算总共行数*/
        int totalRow = 0;
        for(auto i = map.constBegin(); i != map.constEnd(); i++){
                if(i.value()->getStatus() == 3){
                    totalRow ++;
                }
        }
        ui->PkgListTb->setRowCount(totalRow);
        //是否有签收权限
        if(totalRow == 0){
            ui->btn_Sign->hide();
        }
        else{
            ui->btn_Sign->show();
        }

        int row = 0,col = 0;
        for(auto i = map.constBegin(); i != map.constEnd(); i++){
            col = 0;
            if(i.value()->getStatus() == 3){
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getIndex()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getSender()->getUsername()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getSender()->getName()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(QString::number(i.value()->getPrice())));
                QTableWidgetItem *checkbox = new QTableWidgetItem;
                checkbox->setCheckState(Qt::Unchecked);
                ui->PkgListTb->setItem(row,col++,checkbox);
                row++;
            }
        }
    }

}

SignForPackageWindow::~SignForPackageWindow()
{
    delete ui;
}
