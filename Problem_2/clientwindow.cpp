#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "sendpackagewindow.h"
#include"addmoney.h"
#include"packagelistwindow.h"
#include"signforpackagewindow.h"
#include"changepassword.h"

ClientWindow::ClientWindow(QDialog *parent,Client *c) :
    QDialog(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("用户");
    theClient = c;
    /*渲染信息*/
    showInfo();
    /*绑定按钮逻辑*/
    connect(ui->btn_Exit,&QPushButton::clicked,[=](){
       emit clientExit();
       this->hide();
       this->destroy();
    });

    //发送包裹
    connect(ui->btn_SendPkg,&QPushButton::clicked,[=](){
        SendPackageWindow* sdw = new SendPackageWindow(this,theClient);
        sdw->show();
        connect(sdw,&SendPackageWindow::sendFinish,[=](){
            this->showInfo();
        });
    });
            //充值操作
    connect(ui->btn_addMoney,&QPushButton::clicked,[=](){       //充值操作
        AddMoney* ad = new AddMoney(theClient,this);
        connect(ad,&AddMoney::addFinish,[=](){
            this->showInfo();
        });
        ad->show();
    });

   //查询自己包裹操作
    connect(ui->btn_Check,&QPushButton::clicked,[=](){
        PackageListWindow *pklw = new PackageListWindow(this,theClient,1);
        pklw->show();
    });

    //签收自己包裹操作
    connect(ui->btn_Recv,&QPushButton::clicked,[=](){
        SignForPackageWindow *sfw = new SignForPackageWindow(theClient,this);
        sfw->show();
    });

    //修改密码
    connect(ui->btnChangePassword,&QPushButton::clicked,[=](){
        ChangePassword* cg = new ChangePassword(theClient,this);
        cg->show();
    });
}

void ClientWindow::showInfo(){
    /*渲染信息*/
    ui->Username_Line->setText(theClient->getUsername());
    ui->NameLine->setText(theClient->getName());
    ui->PhoneNum_Line->setText(theClient->getPhoneNum());
    ui->Balance_Line->setText(QString::number(theClient->getBalance()));
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

