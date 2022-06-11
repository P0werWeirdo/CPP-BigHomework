#include "signforpackagewindow.h"
#include "ui_signforpackagewindow.h"
#include<QMessageBox>
#include"package.h"
#include<QCheckBox>
#include"packageinfowindow.h"
#include"userinfowindow.h"

SignForPackageWindow::SignForPackageWindow(Client *c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignForPackageWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("签收快递");
    this->setWindowModality(Qt::WindowModal);

    /*初始化类内对象*/
    theClient = c;

    /*初始化表格*/
    ui->PkgListTb->setColumnCount(4);
    ui->PkgListTb->setHorizontalHeaderLabels(QStringList()<<"快递单号"<<"发送方账号"<<"发送方姓名"<<"是否签收");
    ui->PkgListTb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->PkgListTb->setCornerButtonEnabled(false);

    /*初始化逻辑*/
    connect(ui->btn_Sign,&QPushButton::clicked,[=](){
        if(signAllPkg()){
            QMessageBox::about(this,"签收成功","您已经签收了所选的包裹");
            this->close();
            this->deleteLater();
        }
        else{
            QMessageBox::critical(this,"签收失败","部分包裹未能签收");
            showAllPkg();
        }
    });
    connect(ui->PkgListTb,&QTableWidget::itemDoubleClicked,this,&SignForPackageWindow::showDetailInfo);

    /*展示未签收包裹*/
    showAllPkg();

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

bool SignForPackageWindow::signAllPkg()const{
    QList<Package *> tmp;
    int totalRow = ui->PkgListTb->rowCount();
    for(int i = 0;i < totalRow;i++){
        //被选中的入列
        if(ui->PkgListTb->item(i,3)->checkState() == Qt::Checked){
            if(theClient->getMyPackage().contains(ui->PkgListTb->item(i,0)->text())){
                tmp.push_back(theClient->getMyPackage()[ui->PkgListTb->item(i,0)->text()]);
              }
        }
    }

    return Package::recvpkgList(tmp);
}

void SignForPackageWindow::showAllPkg(){

    QMap<QString, Package *> map = theClient->getMyPackage();

    /*计算总共行数*/
    int totalRow = 0;
    for(auto i = map.constBegin(); i != map.constEnd(); i++){
            if(i.value()->getStatus() == 1 && i.value() ->getRecver() == theClient){
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
        if(i.value()->getStatus() == 1 && i.value() ->getRecver() == theClient){
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

SignForPackageWindow::~SignForPackageWindow()
{
    delete ui;
}
