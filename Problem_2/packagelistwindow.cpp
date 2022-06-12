#include "packagelistwindow.h"
#include "ui_packagelistwindow.h"
#include"package.h"
#include"user.h"
#include<QMap>
#include<QTableWidget>
#include<QDebug>
#include<packageinfowindow.h>
#include<userinfowindow.h>
//status 0代表管理员 1代表用户
PackageListWindow::PackageListWindow(QWidget *parent,User* tu,char status) :
    QDialog(parent),
    ui(new Ui::PackageListWindow)
{
    ui->setupUi(this);

    /*初始化页面成员*/
    this->theUser = tu;
    this->status = status;

    /*设置页面信息*/
    this->setWindowModality(Qt::WindowModal);
    this->setWindowTitle("快递信息");
    ui->rb_Username->click();
    ui->date_Date->setDate(QDate::currentDate());
    ui->date_Date->hide();
    ui->box_Status->hide();
    /*设置搜索栏只能输入数字和字母*/
    QRegExp regx1("[a-zA-Z0-9]+$");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->line_Search);
    ui->line_Search->setValidator( validator1 );

    /*设置默认显示的快递表*/
    if(status == 0){
        theMap = Package::packageList;
    }
    else{
        theMap = theUser->getMyPackage();
    }
    /*初始化表格*/
    ui->PkgListTb->setColumnCount(4);
    ui->PkgListTb->setHorizontalHeaderLabels(QStringList()<<"快递单号"<<"发送方账号"<<"接收方账号"<<"状态");
    ui->PkgListTb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->PkgListTb->setCornerButtonEnabled(false);

    /*初始化按键逻辑*/
    connect(ui->btn_Default,&QPushButton::clicked,[=](){
        showMyPkg();
    });
    connect(ui->btn_Search,&QPushButton::clicked,this,&PackageListWindow::searchAndShow);
    //连接radioButton
    connect(ui->rb_Index,&QRadioButton::clicked,[=](){
        ui->line_Search->show();
        ui->date_Date->hide();
        ui->box_Status->hide();
    });
    connect(ui->rb_Username,&QRadioButton::clicked,[=](){
        ui->line_Search->show();
        ui->date_Date->hide();
        ui->box_Status->hide();
    });
    connect(ui->rb_Time,&QRadioButton::clicked,[=](){
        ui->line_Search->hide();
        ui->date_Date->show();
        ui->box_Status->hide();
    });
    connect(ui->rb_Status,&QRadioButton::clicked,[=](){
        ui->line_Search->hide();
        ui->date_Date->hide();
        ui->box_Status->show();
    });


    /*初始化表格逻辑*/
    if(status != 3){
        connect(ui->PkgListTb,&QTableWidget::itemDoubleClicked,this,&PackageListWindow::showDetailInfo);
    }
    /*初始化快递表*/
    showMyPkg();
}

/*查看详细信息*/
void PackageListWindow::showDetailInfo(QTableWidgetItem *item){

    if(item->column() == 0){
        PackageInfoWindow *pkgInfo = new PackageInfoWindow(
                    Package::packageList[item->text()],this);
        pkgInfo->show();

    }
    else if(item->column() == 1 || item->column() == 2){
        UserInfoWindow *userInfo = new UserInfoWindow(
                    Client::clientList[item->text()],this->status,this);
        userInfo->show();
    }
}

/*展示包裹*/
void PackageListWindow::showList(QList<Package*> pkg){
    /*无项目直接return*/
    int len = pkg.length();
    ui->PkgListTb->setRowCount(len);
    if(len == 0){
        return;
    }
    int col;
    /*填充table*/
    for(int i = 0;i < len; i++){
        col = 0;
        //qDebug()<< pkg[i]->getIndex();
        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(pkg[i]->getIndex()));
        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(pkg[i]->getSender()->getUsername()));
        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(pkg[i]->getRecver()->getUsername()));
        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(pkg[i]->getStatusString()));
    }
}

/*展示我的包裹*/
void PackageListWindow::showMyPkg(){
    QList<Package *> tmp;
    //转化为QList

    QMap<QString,Package *>::const_iterator i = theMap.constBegin();

    while(i != theMap.constEnd()){
        tmp.push_back(i.value());
        i++;
    }
    showList(tmp);
    return;
}

/*展示搜索结果*/
void PackageListWindow::searchAndShow(){
    QList <Package*> showPkgList;
    if(ui->rb_Index->isChecked()){  //按快递号查找
        if( theMap.contains(ui->line_Search->text()) ){
            showPkgList.push_back(theMap[ui->line_Search->text()]);
        }

    }
    else if(ui->rb_Username->isChecked()){  //按用户名
        for(auto iter = theMap.constBegin(); iter != theMap.constEnd();iter++){
            if(iter.value()->getSender()->getUsername() == ui->line_Search->text() ||
                    iter.value()->getRecver()->getUsername() == ui->line_Search->text()){
                showPkgList.push_back(iter.value());
            }
        }

    }
    else if(ui->rb_Time->isChecked()){                                   //按时间
        QDate tmp = ui->date_Date->date();
        for(auto iter = theMap.constBegin(); iter != theMap.constEnd();iter++){
            if(iter.value()->getSendTime().date() == tmp || iter.value()->getCollectTime().date() == tmp
                    || iter.value()->getRecvTime().date() == tmp){
                showPkgList.push_back(iter.value());
            }
        }
    }
    else{   //按状态
        char status = ui->box_Status->currentIndex() + 1;
        for(auto iter = theMap.constBegin(); iter != theMap.constEnd();iter++){
            if(iter.value()->getStatus() == status){
                showPkgList.push_back(iter.value());
            }
        }

    }

    return showList(showPkgList);
}

PackageListWindow::~PackageListWindow()
{
    delete ui;
}
