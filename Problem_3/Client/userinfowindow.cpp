#include "userinfowindow.h"
#include "ui_userinfowindow.h"
#include"packagelistwindow.h"
#include<QMessageBox>
#include<QString>
#include<QDebug>
#include"loginwindow.h"

UserInfoWindow::UserInfoWindow(QJsonObject theUser,char status,int type,QWidget *parent) :
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
        PackageListWindow *newWindow = new PackageListWindow(theUser,type,this);
        newWindow->show();
    });

    showInfo();
}

UserInfoWindow::UserInfoWindow(QString username,char status,int type,QWidget *parent):
    QDialog(parent),
    ui(new Ui::UserInfoWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("用户信息");
    this->setWindowModality(Qt::WindowModal);
    /*判断*/

    /*接收参数*/
    //this->theUser = theUser;
    this->status = status;

    /*初始化按钮逻辑*/
    connect(ui->btn_Quit,&QPushButton::clicked,[=](){
        this->hide();
        this->destroy();
    });
    connect(ui->btn_Check,&QPushButton::clicked,[=](){
        PackageListWindow *newWindow = new PackageListWindow(theUser,type,this);
        newWindow->show();
    });

    sendSearchReq(username);
   // showInfo();
}

//发送查询请求
void UserInfoWindow::sendSearchReq(QString username)const{
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",7);
    QJsonObject info;
    info.insert("type",status);
    info.insert("aim",username);

    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    LoginWindow::con->write(abyte);
    /*绑定逻辑*/
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&UserInfoWindow::initUser);
}

//初始化类内用户
void UserInfoWindow::initUser(){
    //首先解绑
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&UserInfoWindow::initUser);
    //读入并构造Json对象
    QByteArray tmp = LoginWindow::con->readAll();
    qDebug() << tmp;
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();

    if(obj["status"].toInt() != 200){
        QMessageBox::critical(this,"错误","服务器忙");
    }
    else{
        //传入Json对象
        this->theUser = obj["message"].toArray()[0].toObject();
        showInfo();
        return;
    }
}



void UserInfoWindow::showInfo(){

    /*如果是用户查询， 则隐藏余额部分，和查询快递部分*/
    if(status == 2){
        ui->Blance_Line->hide();
        ui->Balance_Line2->hide();
        ui->widget_8->hide();
    }
    /*设置基本的信息*/
    ui->Username_Line->setText(theUser["username"].toString());
    ui->Name_Line->setText(theUser["name"].toString());
    ui->PhoneNum_Line->setText(theUser["phone"].toString());
    ui->Blance_Line->setText(QString::number(theUser["balance"].toDouble()));

    /*如果是快递员，则跳过地址部分*/
    if(status != 3){
        ui->Addr_Line->setText(theUser["address"].toString());
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
