#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "sendpackagewindow.h"
#include"addmoney.h"
#include"packagelistwindow.h"
#include"signforpackagewindow.h"
#include"changepassword.h"
#include"loginwindow.h"
#include<QMessageBox>
ClientWindow::ClientWindow(QJsonObject c,QDialog *parent) :
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
       this->close();
    });

//    //发送包裹
    connect(ui->btn_SendPkg,&QPushButton::clicked,[=](){
        SendPackageWindow* sdw = new SendPackageWindow(theClient,this);
        sdw->show();
        connect(sdw,&SendPackageWindow::sendFinish,[=](){
            this->freshUserRequest();
        });
    });
            //充值操作
    connect(ui->btn_addMoney,&QPushButton::clicked,[=](){       //充值操作
        AddMoney* ad = new AddMoney(theClient,this);
        connect(ad,&AddMoney::addFinish,[=](){
            this->freshUserRequest();
        });
        ad->show();
    });

   //查询自己包裹操作
    connect(ui->btn_Check,&QPushButton::clicked,[=](){
        PackageListWindow *pklw = new PackageListWindow(theClient,2,this);
        pklw->show();
    });

    //签收自己包裹操作
    connect(ui->btn_Recv,&QPushButton::clicked,[=](){
        SignForPackageWindow *sfw = new SignForPackageWindow(theClient,2,this);
        sfw->show();
    });

//    //修改密码
    connect(ui->btnChangePassword,&QPushButton::clicked,[=](){
        ChangePassword* cg = new ChangePassword(theClient,2,this);
        cg->show();
    });
}

void ClientWindow::showInfo(){
    /*渲染信息*/
    ui->Username_Line->setText(theClient["username"].toString());
    ui->NameLine->setText(theClient["name"].toString());
    ui->PhoneNum_Line->setText(theClient["phone"].toString());
    ui->Balance_Line->setText(QString::number(theClient["balance"].toDouble()));
}

//刷新
void ClientWindow::freshUserRequest()const{
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",7);
    QJsonObject info;
    info.insert("aim",ui->Username_Line->text());
    info.insert("type",1);
    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    LoginWindow::con->write(abyte);
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&ClientWindow::freshSuccess);
}

void ClientWindow::freshSuccess(){
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&ClientWindow::freshSuccess);

    //重新初始化本窗口的User
    //读入并构造Json对象
    QByteArray tmp = LoginWindow::con->readAll();
    qDebug() << tmp;
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();

    if(obj["status"].toInt() != 200){
        QMessageBox::critical(this,"连接异常","获取新的用户信息失败");
    }
    else{
        theClient = obj["message"].toArray()[0].toObject();
        showInfo();
    }
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

