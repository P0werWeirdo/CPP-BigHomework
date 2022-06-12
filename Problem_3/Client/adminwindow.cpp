#include "adminwindow.h"
#include "ui_adminwindow.h"
#include"administrator.h"
#include"packagelistwindow.h"
#include"userlistwindow.h"
#include"changepassword.h"
#include"registerwindow.h"
#include"signforpackagewindow.h"

AdminWindow::AdminWindow(QJsonObject admin,QDialog *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    //this->setFixedSize(600,400);
    this->setWindowTitle("管理员界面");
    /*初始化*/
    this->admin = admin;

    /*绑定按键逻辑*/
    //搜索包裹
    connect(ui->btn_SearchPkg,&QPushButton::clicked,this,&AdminWindow::searchPkg);
    //搜索用户
    connect(ui->btn_SearchUser,&QPushButton::clicked,this,&AdminWindow::searchUser);
    //退出
    connect(ui->btn_Exit,&QPushButton::clicked,[=](){
       emit adminExit();
       this->hide();
       this->destroy();
    });
    //修改密码
    connect(ui->btn_ChangePassword,&QPushButton::clicked,[=](){
        ChangePassword* cg = new ChangePassword(admin,1,this);
        cg->show();
    });
    //添加快递员
    connect(ui->btn_AddCollector,&QPushButton::clicked,[=](){
        RegisterWindow *newWindow = new RegisterWindow(1,this);
        newWindow->show();
    });
    //查看快递员
    connect(ui->btn_SearchCollector,&QPushButton::clicked,[=](){
        UserListWindow *newWindow = new UserListWindow(1,this);
        newWindow->show();
    });
    //分配包裹
    connect(ui->btn_Distribute,&QPushButton::clicked,[=](){
        SignForPackageWindow *newWindow = new SignForPackageWindow(this->admin,1,this);
        newWindow->show();
    });
    /*展示信息*/
    showInfo();
}

/*展示信息*/
void AdminWindow::showInfo(){
    ui->Username_Line->setText(admin["username"].toString());
    ui->Name_Line->setText(admin["name"].toString());
    ui->PhoneNum_Line->setText(admin["phone"].toString());
    ui->Balance_Line->setText(QString::number( admin["balance"].toDouble()));
}

/*查找包裹*/
void AdminWindow::searchPkg(){
    PackageListWindow* pkglist = new PackageListWindow(this->admin,1,this);
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
