#include "adminwindow.h"
#include "ui_adminwindow.h"
#include"administrator.h"
#include"packagelistwindow.h"
#include"userlistwindow.h"
#include"changepassword.h"

AdminWindow::AdminWindow(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    //this->setFixedSize(600,400);

    /*绑定按键逻辑*/
    connect(ui->btn_SearchPkg,&QPushButton::clicked,this,&AdminWindow::searchPkg);
    connect(ui->btn_SearchUser,&QPushButton::clicked,this,&AdminWindow::searchUser);
    connect(ui->btn_Exit,&QPushButton::clicked,[=](){
       emit adminExit();
       this->hide();
       this->destroy();
    });
    connect(ui->btn_ChangePassword,&QPushButton::clicked,[=](){
        User *tmp = &Administrator::admin;
        ChangePassword* cg = new ChangePassword(tmp,this);
        cg->show();
     });

    /*展示信息*/
    showInfo();
}

/*展示信息*/
void AdminWindow::showInfo(){
    ui->Username_Line->setText(Administrator::admin.getUsername());
    ui->Name_Line->setText(Administrator::admin.getName());
    ui->PhoneNum_Line->setText(Administrator::admin.getPhoneNum());
    ui->Balance_Line->setText(QString::number(Administrator::admin.getBalance()));
}

/*查找包裹*/
void AdminWindow::searchPkg(){
    User* tmp = &Administrator::admin;
    PackageListWindow* pkglist = new PackageListWindow(this,tmp,0);
    pkglist->show();
}

/*查找用户*/
void AdminWindow::searchUser(){
    UserListWindow *userlist = new UserListWindow(this);
    userlist->show();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}
