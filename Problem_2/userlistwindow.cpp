#include "userlistwindow.h"
#include "ui_userlistwindow.h"
#include"userinfowindow.h"
#include"courier.h"
#include<QMessageBox>

UserListWindow::UserListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserListWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("用户表格");
    this->setWindowModality(Qt::WindowModal);

    /*设置页面信息*/
    this->setWindowTitle("用户信息");
    this->admin = -1;
    /*初始化表格*/
    ui->ClientListTb->setColumnCount(4);
    ui->ClientListTb->setHorizontalHeaderLabels(QStringList()<<"用户账号"<<"用户密码"<<"用户姓名"<<"用户电话");
    ui->ClientListTb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ClientListTb->setCornerButtonEnabled(false);
    /*隐藏删除按钮*/
    ui->widget->hide();
    /*表格逻辑*/
    connect(ui->ClientListTb,&QTableWidget::itemDoubleClicked,this,&UserListWindow::showDetailInfo);
    /*展示信息*/
    showClientInfo();
}

UserListWindow::UserListWindow(int admin,QWidget *parent):
    QDialog(parent),
    ui(new Ui::UserListWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("快递员表格");
    this->setWindowModality(Qt::WindowModal);

    /*设置页面信息*/
    this->setWindowTitle("快递员信息");
    this->admin = admin;

    /*初始化表格*/
    ui->ClientListTb->setColumnCount(4);
    ui->ClientListTb->setHorizontalHeaderLabels(QStringList()<<"快递员账号"<<"快递员密码"<<"快递员姓名"<<"快递员电话");
    ui->ClientListTb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ClientListTb->setCornerButtonEnabled(false);

    /*表格逻辑*/
    connect(ui->ClientListTb,&QTableWidget::itemDoubleClicked,this,&UserListWindow::showDetailInfo);
    /*删除逻辑*/
    connect(ui->btn_del,&QPushButton::clicked,[=](){
        int row = ui->ClientListTb->currentRow();
        if(row < 0 || row >= ui->ClientListTb->rowCount()){
            QMessageBox::critical(this,"删除失败","请稍后重试");
            return ;
        }
        if(Courier::deleteCourier(ui->ClientListTb->item(row,0)->text())){
            QMessageBox::about(this,"删除成功","此快递员已经被删除了");
            showCourierInfo();
        }
        else{
            QMessageBox::critical(this,"删除失败","请稍后重试");
        }

    });
    /*展示信息*/
    showCourierInfo();
}

void UserListWindow::showCourierInfo(){ //展示快递员信息
    int len = Courier::courierList.size();
    ui->ClientListTb->setRowCount(len);
    if(len == 0){
        return;
    }
    int col;
    int row = 0;
    /*填充table*/
    for(auto i = Courier::courierList.constBegin();i != Courier::courierList.constEnd(); i++,row++){
        col = 0;
        //qDebug()<< pkg[i]->getIndex();
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getUsername()));
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getPassword()));
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getName()));
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()->getPhoneNum()));
    }
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
    if(admin == -1){
    //查看用户详细信息
        UserInfoWindow *userInfo = new UserInfoWindow(
                    Client::clientList[tmp],0,this);
        userInfo->show();
     }
    else{
    //查看快递员详细信息
        UserInfoWindow *userInfo = new UserInfoWindow(
                   Courier::courierList[tmp],2,this);
        userInfo->show();

    }
}
UserListWindow::~UserListWindow()
{
    delete ui;
}
