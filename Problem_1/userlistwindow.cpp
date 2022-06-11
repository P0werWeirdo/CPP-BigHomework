#include "userlistwindow.h"
#include "ui_userlistwindow.h"
#include"userinfowindow.h"
UserListWindow::UserListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserListWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("用户表格");
    this->setWindowModality(Qt::WindowModal);

    /*设置页面信息*/
    this->setWindowTitle("用户信息");

    /*初始化表格*/
    ui->ClientListTb->setColumnCount(4);
    ui->ClientListTb->setHorizontalHeaderLabels(QStringList()<<"用户账号"<<"用户密码"<<"用户姓名"<<"用户电话");
    ui->ClientListTb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ClientListTb->setCornerButtonEnabled(false);
    /*表格逻辑*/
    connect(ui->ClientListTb,&QTableWidget::itemDoubleClicked,this,&UserListWindow::showDetailInfo);
    /*展示信息*/
    showClientInfo();
}

void UserListWindow::showClientInfo(){
    int len = Client::clientList.size();
    ui->ClientListTb->setRowCount(len);
    if(len == 0){
        return;
    }
    int col;
    int row = 0;
    /*填充table*/
    for(auto i = Client::clientList.constBegin();i != Client::clientList.constEnd(); i++,row++){
        col = 0;
        //qDebug()<< pkg[i]->getIndex();
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getUsername()));
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getPassword()));
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getName()));
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getPhoneNum()));
    }
}

void UserListWindow::showDetailInfo(QTableWidgetItem *item){

    QString tmp = ui->ClientListTb->item(item->row(),0)->text();
    //查看用户详细信息
        UserInfoWindow *userInfo = new UserInfoWindow(
                    Client::clientList[tmp],0,this);
        userInfo->show();
}
UserListWindow::~UserListWindow()
{
    delete ui;
}
