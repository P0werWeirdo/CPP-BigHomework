#include "userinfowindow.h"
#include "ui_userinfowindow.h"
#include"packagelistwindow.h"
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
    connect(ui->btn_Check,&QPushButton::clicked,[=](){
        PackageListWindow *newWindow = new PackageListWindow(this,theUser,3);
        newWindow->show();
    });

    showInfo();
}

void UserInfoWindow::showInfo(){

    /*如果是用户查询， 则隐藏余额部分，和查询快递部分*/
    if(status == 1){
        ui->Blance_Line->hide();
        ui->Balance_Line2->hide();
        ui->widget_8->hide();
    }
    /*设置基本的信息*/
    ui->Username_Line->setText(theUser->getUsername());
    ui->Name_Line->setText(theUser->getName());
    ui->PhoneNum_Line->setText(theUser->getPhoneNum());
    ui->Blance_Line->setText(QString::number(theUser->getBalance()));

    /*如果是快递员，则跳过地址部分*/
    if(status != 2){
        ui->Addr_Line->setText(((Client*)(theUser))->getAddress());
    }
    else{
        ui->Addr_Line->hide();
        ui->label_Addr->hide();
    }

}

UserInfoWindow::~UserInfoWindow()
{
    delete ui;
}
