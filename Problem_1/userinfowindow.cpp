#include "userinfowindow.h"
#include "ui_userinfowindow.h"
#include<QMessageBox>
#include<QString>
UserInfoWindow::UserInfoWindow(User *theUser,char status,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInfoWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("用户信息");
    this->setWindowModality(Qt::WindowModal);
    /*判断*/

    /*接收参数*/
    this->theUser = theUser;
    this->status = status;
    /*初始化按钮逻辑*/
    connect(ui->btn_Quit,&QPushButton::clicked,[=](){
        this->hide();
        this->destroy();
    });

    showInfo();
}

void UserInfoWindow::showInfo(){

    /*如果是用户查询， 则隐藏余额部分*/
    if(status == 1){
        ui->Blance_Line->hide();
        ui->Balance_Line2->hide();
    }
    /*设置基本的信息*/
    ui->Username_Line->setText(theUser->getUsername());
    ui->Name_Line->setText(theUser->getName());
    ui->PhoneNum_Line->setText(theUser->getPhoneNum());
    ui->Blance_Line->setText(QString::number(theUser->getBalance()));
    ui->Addr_Line->setText(((Client*)(theUser))->getAddress());
}

UserInfoWindow::~UserInfoWindow()
{
    delete ui;
}
