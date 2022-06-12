#include "courierwindow.h"
#include "ui_courierwindow.h"
#include "changepassword.h"
#include"signforpackagewindow.h"
#include"packagelistwindow.h"
#include"signforpackagewindow.h"
#include"loginwindow.h"
#include<QMessageBox>
CourierWindow::CourierWindow(QJsonObject courier,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourierWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("快递员");
    this->theCourier = courier;
    /*渲染信息*/
    showInfo();
    /*绑定按钮逻辑*/
    connect(ui->btn_Exit,&QPushButton::clicked,[=](){
       emit courierExit();
       this->close();
    });

   //查询自己包裹操作
    connect(ui->btn_Check,&QPushButton::clicked,[=](){
        PackageListWindow *pklw = new PackageListWindow(courier,3,this);
        pklw->show();
    });

    //派件操作
    connect(ui->btn_Collect,&QPushButton::clicked,[=](){
        SignForPackageWindow *sfw = new SignForPackageWindow(theCourier,3,this);
        connect(sfw,&SignForPackageWindow::collectFinish,this,&CourierWindow::freshUserRequest);
        sfw->show();
    });

    //修改密码
    connect(ui->btnChangePassword,&QPushButton::clicked,[=](){
        ChangePassword* cg = new ChangePassword(theCourier,3,this);
        cg->show();
    });
}


void CourierWindow::showInfo(){
    /*渲染信息*/
    ui->Username_Line->setText(theCourier["username"].toString());
    ui->NameLine->setText(theCourier["name"].toString());
    ui->PhoneNum_Line->setText(theCourier["phone"].toString());
    ui->Balance_Line->setText(QString::number(theCourier["balance"].toDouble()));
}

void CourierWindow::freshUserRequest(){       //刷新信息
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",11);
    QJsonObject info;
    info.insert("aim",ui->Username_Line->text());
    info.insert("type",1);
    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    LoginWindow::con->write(abyte);
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&CourierWindow::freshSuccess);
}

void CourierWindow::freshSuccess(){
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&CourierWindow::freshSuccess);

    //重新初始化本窗口的User
    //读入并构造Json对象
    QByteArray tmp = LoginWindow::con->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();

    if(obj["status"].toInt() != 200){
        QMessageBox::critical(this,"连接异常","获取新的用户信息失败");
    }
    else{
        theCourier = obj["message"].toArray()[0].toObject();
        showInfo();
    }
}

CourierWindow::~CourierWindow()
{
    delete ui;
}
