#include "distributewindow.h"
#include "ui_distributewindow.h"
#include<QRegExpValidator>
#include<QMessageBox>
#include"loginwindow.h"
#include<QCloseEvent>

DistributeWindow::DistributeWindow(QJsonObject pkg,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DistributeWindow)
{
    ui->setupUi(this);
    this->setFixedSize(400,400);           //设置窗口大小
    /*窗口基本设置*/
    this->setWindowTitle("分配包裹");
    this->setWindowModality(Qt::WindowModal);

    ui->nameLabel->setText("不存在");
    ui->phoneLabel->setText("不存在");

    //初始化
    this->thePkg = pkg;
    sendCourierReq();

    /*禁止用户名框输入中文*/
    QRegExp regx1("[a-zA-Z0-9]+$");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->lineUsername);
    ui->lineUsername->setValidator( validator1 );

    connect(ui->lineUsername,&QLineEdit::textChanged,this,&DistributeWindow::searchCourier);
    connect(ui->btn_Confirm,&QPushButton::clicked,this,&DistributeWindow::sendDistributeReq);
}

void DistributeWindow::sendCourierReq(){
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",11);
    QJsonObject info;
    info.insert("type",1);
    info.insert("aim","ALL");

    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
//    qDebug() << abyte;
    LoginWindow::con->write(abyte);
    /*绑定逻辑*/
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&DistributeWindow::initCourierList);
}

void DistributeWindow::initCourierList(){
    //首先解绑
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&DistributeWindow::initCourierList);

    //读入并构造Json对象
    QByteArray tmp = LoginWindow::con->readAll();
//    qDebug() << tmp;
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();

    if(obj["status"].toInt() != 200){
        QMessageBox::critical(this,"错误","服务器忙");
    }
    else{
        //传入Json对象
        QJsonArray courier = obj["message"].toArray();
        for(auto item = courier.constBegin();item != courier.constEnd();item++){
            this->courierList.insert((*item).toObject()["username"].toString(),
                    (*item).toObject());
        }
        return;
    }
}



//查找并渲染快递员
void DistributeWindow::searchCourier(){
    if(courierList.contains(ui->lineUsername->text())){
        ui->nameLabel->setText(courierList[ui->lineUsername->text()]["name"].toString());
        ui->phoneLabel->setText(courierList[ui->lineUsername->text()]["phone"].toString());
    }
    else {
        ui->nameLabel->setText("不存在");
        ui->phoneLabel->setText("不存在");
    }
}

void DistributeWindow::sendDistributeReq(){

    if(ui->lineUsername->text().length() == 0 ||
            !courierList.contains(ui->lineUsername->text())){
        QMessageBox::critical(this,"不存在","请输入有效的快递员账号");
        return;
    }

    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",9);
    QJsonObject info;
    info.insert("username","admin");
    info.insert("type",1);


    QJsonArray message;
    QJsonObject item;
    item.insert("index",thePkg["index"].toString());
    item.insert("username",ui->lineUsername->text());
    message.append(item);

    info.insert("message",message);


    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    LoginWindow::con->write(abyte);
    /*绑定逻辑*/
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&DistributeWindow::distributeConfirm);
}


//确认揽收
void DistributeWindow::distributeConfirm(){
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&DistributeWindow::distributeConfirm);


    //读入并构造Json对象
    QByteArray tmp = LoginWindow::con->readAll();
//    qDebug() << tmp;
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();


    if(obj["status"].toInt() != 200){
        QMessageBox::critical(this,"错误","服务器忙");
    }
    else{
        //传入Json对象
        bool result = obj["message"].toArray()[0].toObject()["result"].toBool();
        if(result){
            QMessageBox::about(this,"分配成功","您已经分配了所选的包裹");
            this->close();
        }
        else{
            QMessageBox::critical(this,"分配失败","未能成功分配");
        }
        return;
    }
}

//发出信号
void DistributeWindow::closeEvent(QCloseEvent *e){
    emit distributeFinish();
    e->accept();
}

DistributeWindow::~DistributeWindow()
{
    delete ui;
}
