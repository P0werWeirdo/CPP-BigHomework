#include "courierwindow.h"
#include "ui_courierwindow.h"
#include "changepassword.h"
#include"signforpackagewindow.h"
#include"packagelistwindow.h"

CourierWindow::CourierWindow(Courier *c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourierWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("用户");
    theCourier = c;
    /*渲染信息*/
    showInfo();
    /*绑定按钮逻辑*/
    connect(ui->btn_Exit,&QPushButton::clicked,[=](){
       emit courierExit();
       this->hide();
       this->destroy();
    });

   //查询自己包裹操作
    connect(ui->btn_Check,&QPushButton::clicked,[=](){
        PackageListWindow *pklw = new PackageListWindow(this,theCourier,1);
        pklw->show();
    });

    //派件操作
    connect(ui->btn_Collect,&QPushButton::clicked,[=](){
        SignForPackageWindow *sfw = new SignForPackageWindow(theCourier,this);
        connect(sfw,&SignForPackageWindow::collectFinish,this,&CourierWindow::showInfo);
        sfw->show();
    });

    //修改密码
    connect(ui->btnChangePassword,&QPushButton::clicked,[=](){
        ChangePassword* cg = new ChangePassword(theCourier,this);
        cg->show();
    });
}


void CourierWindow::showInfo(){
    /*渲染信息*/
    ui->Username_Line->setText(theCourier->getUsername());
    ui->NameLine->setText(theCourier->getName());
    ui->PhoneNum_Line->setText(theCourier->getPhoneNum());
    ui->Balance_Line->setText(QString::number(theCourier->getBalance()));
}


CourierWindow::~CourierWindow()
{
    delete ui;
}
