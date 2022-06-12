#include "registerwindow.h"
#include"loginwindow.h"
#include "ui_registerwindow.h"
#include<QCloseEvent>
#include<QMessageBox>
#include<QRegExpValidator>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>
RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("注册界面");
    this->setWindowModality(Qt::WindowModal);

    /*输入错误提示初始化*/
    ui->Input_Error->hide();
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->Input_Error->setPalette(pa);

    /*禁止用户名框输入中文*/
    QRegExp regx1("[a-zA-Z0-9]+$");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->Username_Line);
    ui->Username_Line->setValidator( validator1 );
    /*设置电话框只能输入数字*/
    QRegExp regx2("[0-9]+$");
    QValidator* validator2 = new QRegExpValidator(regx2, ui->PhoneNum_Line);
    ui->PhoneNum_Line->setValidator(validator2);

    /*绑定窗口按钮逻辑*/
    connect(ui->btn_Confirm,&QPushButton::clicked,this,&RegisterWindow::clientRequest);
    connect(ui->btn_Cancel,&QPushButton::clicked,[=](){
        this->close();
    });
}

//占位参数用于区分
RegisterWindow::RegisterWindow(int admin,QWidget *parent):
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("注册快递员");
    this->setWindowModality(Qt::WindowModal);

    /*输入错误提示初始化*/
    ui->Input_Error->hide();
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->Input_Error->setPalette(pa);

    /*隐藏地址，上移按钮，设置窗口大小*/
    ui->label_Addr->hide();
    ui->Addr_Line->hide();

    /*禁止用户名框输入中文*/
    QRegExp regx1("[a-zA-Z0-9]+$");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->Username_Line);
    ui->Username_Line->setValidator( validator1 );
    /*设置电话框只能输入数字*/
    QRegExp regx2("[0-9]+$");
    QValidator* validator2 = new QRegExpValidator(regx2, ui->PhoneNum_Line);
    ui->PhoneNum_Line->setValidator(validator2);

    /*绑定窗口按钮逻辑*/
    connect(ui->btn_Confirm,&QPushButton::clicked,this,&RegisterWindow::courierRequest);
    connect(ui->btn_Cancel,&QPushButton::clicked,[=](){
        this->close();
    });
}

void RegisterWindow::clientRequest(){
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",4);
    QJsonObject user;
    user.insert("username",ui->Username_Line->text());
    user.insert("password",ui->Password_Line->text());
    user.insert("name",ui->Name_Line->text());
    user.insert("phone",ui->PhoneNum_Line->text());
    user.insert("address",ui->Addr_Line->toPlainText());
    obj.insert("user",user);

    //发送
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    LoginWindow::con->write(abyte);
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&RegisterWindow::clientResHandle);
}

void RegisterWindow::clientResHandle() {            //处理
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&RegisterWindow::clientResHandle);

    //解读Json
    QByteArray tmp = LoginWindow::con->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();

    if(obj["status"].toInt() == 200){
        QJsonArray message = obj["message"].toArray();
        registerClient(message[0].toObject()["result"].toInt());
    }
    else{
        QMessageBox::critical(this,"失败","服务器出错");
    }
}


void RegisterWindow::courierRequest(){
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",5);
    QJsonObject user;
    user.insert("username",ui->Username_Line->text());
    user.insert("password",ui->Password_Line->text());
    user.insert("name",ui->Name_Line->text());
    user.insert("phone",ui->PhoneNum_Line->text());
    obj.insert("user",user);

    //发送
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    LoginWindow::con->write(abyte);
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&RegisterWindow::courierResHandle);
}



void RegisterWindow::courierResHandle(){            //处理

    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&RegisterWindow::courierResHandle);

    //解读Json
    QByteArray tmp = LoginWindow::con->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();

    if(obj["status"].toInt() == 200){
        QJsonArray message = obj["message"].toArray();
        registerCourier(message[0].toObject()["result"].toInt());
    }
    else{
        QMessageBox::critical(this,"失败","服务器出错");
    }
}


//注册用户
void RegisterWindow::registerClient(int result){
    int tmp = result;
    //判断是否成功注册，并给予提示消息
    switch (tmp) {
    case 1:
        ui->Input_Error->setText("用户名长度为4~20");
        break;
    case 2:
        ui->Input_Error->setText("用户名已存在");
        break;
    case 3:
        ui->Input_Error->setText("密码长度为6~20");
        break;
    case 4:
        ui->Input_Error->setText("手机号格式有误");
        break;
    case 5:
        ui->Input_Error->setText("姓名不能为空");
        break;
    case 6:
        ui->Input_Error->setText("地址不能为空");
        break;
    case 7:
        ui->Input_Error->setText("地址过长");
        break;
    default:
        QMessageBox::about(this, "注册成功", "您已完成注册");
        this->close();
        break;
    }
    ui->Input_Error->show();
}

//注册快递员
void RegisterWindow::registerCourier(int result){
    int tmp = result;
    //判断是否成功注册，并给予提示消息
    switch (tmp) {
    case 1:
        ui->Input_Error->setText("用户名长度为4~20");
        break;
    case 2:
        ui->Input_Error->setText("用户名已存在");
        break;
    case 3:
        ui->Input_Error->setText("密码长度为6~20");
        break;
    case 4:
        ui->Input_Error->setText("手机号格式有误");
        break;
    case 5:
        ui->Input_Error->setText("姓名不能为空");
        break;
    default:
        QMessageBox::about(this, "注册成功", "您成功注册了快递员:" + ui->Username_Line->text());
        this->close();
        break;
    }
    ui->Input_Error->show();
}

void RegisterWindow::closeEvent(QCloseEvent *event){
    emit hasFinish();
    event->accept();
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}
