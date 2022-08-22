#include "loginwindow.h"
#include "ui_loginwindow.h"
#include<QFile>
#include<QDebug>
#include"adminwindow.h"
#include"registerwindow.h"
#include"clientwindow.h"
#include<QRegExpValidator>
#include"courierwindow.h"
#include<QHostAddress>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>
QTcpSocket* LoginWindow::con;

LoginWindow::LoginWindow(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("登录界面");       //设置窗口标题
    this->setFixedSize(400,250);           //设置窗口大小
    /*设置默认响应*/
    ui->Login_PushButton->setFocus();
    ui->Login_PushButton->setDefault(true);

    /*禁止用户名框输入中文*/
    QRegExp regx1("[a-zA-Z0-9]+$");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->Username_Line);
    ui->Username_Line->setValidator( validator1 );
    /*密码输入错误提示*/
    ui->Input_Error->hide();
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->Input_Error->setPalette(pa);

    /*设置默认选项*/
    ui->btn_Client->click();
    /*绑定信号*/
    connect(ui->Login_PushButton,&QPushButton::clicked,this,&LoginWindow::userLogin);
    connect(ui->Quit_PushButton_2,&QPushButton::clicked,this,[=](){
        this->close();
    });
    connect(ui->btn_Register,&QPushButton::clicked,this,&LoginWindow::userRegister);

    /*初始化连接*/
    initConnect();
}

bool LoginWindow::userLogin(){

    if(ui->Username_Line->text().length() == 0 ||
            ui->Password_Line->text().length() == 0){
        ui->Input_Error->setText("用户名和密码不得为空");
        ui->Input_Error->show();
        return false;
    }


    if(ui->btn_Client->isChecked()){        //根据radio按钮判断是否选中
        /*构造Json字符串*/
        QJsonObject obj;
        obj.insert("target",3);
        QJsonObject user;
        user.insert("username",ui->Username_Line->text());
        user.insert("password",ui->Password_Line->text());
        obj.insert("user",user);
        QJsonDocument doc;
        doc.setObject(obj);
        QByteArray abyte = doc.toJson(QJsonDocument::Compact);
        con->write(abyte);
        connect(con,&QTcpSocket::readyRead,this,&LoginWindow::clientLogin);
    }
    else if(ui->btn_Courier->isChecked()){  //快递员判定
        /*构造Json字符串*/
        QJsonObject obj;
        obj.insert("target",2);
        QJsonObject user;
        user.insert("username",ui->Username_Line->text());
        user.insert("password",ui->Password_Line->text());
        obj.insert("user",user);
        QJsonDocument doc;
        doc.setObject(obj);
        QByteArray abyte = doc.toJson(QJsonDocument::Compact);
        con->write(abyte);
        connect(con,&QTcpSocket::readyRead,this,&LoginWindow::courierLogin);
    }
    else{//管理员
        /*构造Json字符串*/
        QJsonObject obj;
        obj.insert("target",1);
        QJsonObject user;
        user.insert("username",ui->Username_Line->text());
        user.insert("password",ui->Password_Line->text());
        obj.insert("user",user);
        QJsonDocument doc;
        doc.setObject(obj);
        QByteArray abyte = doc.toJson(QJsonDocument::Compact);
        con->write(abyte);
        connect(con,&QTcpSocket::readyRead,this,&LoginWindow::adminLogin);
    }
    return false;
}

//管理员登录
void LoginWindow::adminLogin(){
//    qDebug()<<"管理员选中";

    //解除绑定
    disconnect(con,&QTcpSocket::readyRead,this,&LoginWindow::adminLogin);

    //读入并构造Json对象
    QByteArray tmp = con->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();
//    qDebug()<< obj["status"].toInt();
    if(obj["status"].toInt() != 200){
        ui->Input_Error->setText("管理员不存在或密码错误");
        ui->Input_Error->show();
    }
    else{
        ui->Input_Error->hide();
        //传入操作
        QJsonObject admin = obj["message"].toArray()[0].toObject();
        AdminWindow *aw = new AdminWindow(admin,this);  //挂到对象树上
        connect(aw,&AdminWindow::adminExit,[=](){
            ui->Password_Line->setText("");
            this->show();
        });
        ui->Input_Error->hide();
        aw->setModal(true);
        this->hide();
        aw->show();
    }
}

//客户登录
void LoginWindow::clientLogin(){
    disconnect(con,&QTcpSocket::readyRead,this,&LoginWindow::clientLogin);

    //读入并构造Json对象
    QByteArray tmp = con->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();

    if(obj["status"].toInt() != 200){
        ui->Input_Error->setText("用户不存在或密码错误");
        ui->Input_Error->show();
    }
    else{
        //传入Json对象
        QJsonObject client = obj["message"].toArray()[0].toObject();
        ClientWindow *cw = new ClientWindow(client,this); //挂到对象树上
        connect(cw,&ClientWindow::clientExit,[=](){
            ui->Password_Line->setText("");
            ui->Input_Error->hide();
            this->show();
        });
        ui->Input_Error->hide();
        cw->show();
        this->hide();
        return;
    }
}
//快递员
void LoginWindow::courierLogin(){
    disconnect(con,&QTcpSocket::readyRead,this,&LoginWindow::courierLogin);

    //读入并构造Json对象
    QByteArray tmp = con->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();

    if(obj["status"].toInt() != 200){
        ui->Input_Error->setText("快递员不存在或密码错误");
        ui->Input_Error->show();
    }
    else{
        //传入Json对象
        QJsonObject courier = obj["message"].toArray()[0].toObject();
        CourierWindow *cw = new CourierWindow(courier,this);
        connect(cw,&CourierWindow::courierExit,[=](){
            ui->Password_Line->setText("");
            this->show();
        });
        ui->Input_Error->hide();
        cw->setModal(true);
        this->hide();
        cw->show();
    }
}

void LoginWindow::userRegister(){      //用户注册函数
     RegisterWindow *rw = new RegisterWindow(this);
     connect(rw,&RegisterWindow::hasFinish,[=](){
         this->show();
     });
     rw->show();
     this->hide();
}

void LoginWindow::initConnect(){
    //与服务器连接
    con = new QTcpSocket(this);
    con->connectToHost(QHostAddress("127.0.0.1"),8000);

    connect(con, SIGNAL(readyRead()), &loop, SLOT(quit()));
    connect(con, SIGNAL(disconnected()), &loop, SLOT(quit()));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
