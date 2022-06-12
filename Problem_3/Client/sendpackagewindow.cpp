#include "sendpackagewindow.h"
#include "ui_sendpackagewindow.h"
#include<QMessageBox>
#include<QRegExpValidator>
#include"loginwindow.h"
#include<QDebug>
#include<QComboBox>

SendPackageWindow::SendPackageWindow(QJsonObject client,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendPackageWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("发送快递");
    this->setWindowModality(Qt::WindowModal);
    this->resize(600,800);

    /*初始化成员*/
    this->theClient = client;

    /*初始化页面*/
    initSenderInfo();
    sendInitRequest();
    /*对搜索框限制*/
    /*禁止用户名框输入中文*/
    QRegExp regx1("[a-zA-Z0-9]+$");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->RecvUserName_Line);
    ui->RecvUserName_Line->setValidator( validator1 );
    /*设置价格*/
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->Price_Label->setPalette(pa);
    ui->Price_Label->setText("7.5");
    /*绑定按钮逻辑*/
    connect(ui->btn_Confirm_2,&QPushButton::clicked,[=](){
        sendPackage();
    });
    connect(ui->btn_Cancel_2,&QPushButton::clicked,[=](){
        this->hide();
        this->destroy();
    });
    connect(ui->RecvUserName_Line,&QLineEdit::textChanged,[=](){
        showRecvInfo();
    });
    /*动态计算金额*/
    //connect(ui->numberOfPkg,&QDoubleSpinBox::valueChanged,[=](){});
    connect(ui->typeOfPkg,static_cast<void (QComboBox::*)(int index)>(&QComboBox::activated),
            this,&SendPackageWindow::showPrice);
    connect(ui->numberOfPkg,static_cast<void (QDoubleSpinBox::*)(double d)>(&QDoubleSpinBox::valueChanged),
            this,&SendPackageWindow::showPrice);
}
/*初始化发送方信息*/
void SendPackageWindow::initSenderInfo(){
    /*初始化页面*/
    ui->SenderUsername_Label->setText(theClient["username"].toString());
    ui->SenderName_Label->setText(theClient["name"].toString());
    ui->SenderPhoneNum_Label->setText(theClient["phone"].toString());
}


/*请求所有可能的接收者信息*/
void SendPackageWindow::sendInitRequest(){
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",7);
    QJsonObject info;
    info.insert("type",2);
    info.insert("aim","ALL");

    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    LoginWindow::con->write(abyte);
    /*绑定逻辑*/
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&SendPackageWindow::initTotalUser);
}

void SendPackageWindow::initTotalUser(){
    //首先解绑
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&SendPackageWindow::initTotalUser);
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
        QJsonArray client = obj["message"].toArray();
        for(auto item = client.constBegin();item != client.constEnd();item++){
            QList<QString> list;
            list.append((*item).toObject()["name"].toString());
            list.append((*item).toObject()["phone"].toString());
            list.append((*item).toObject()["address"].toString());
            this->totalUser.insert((*item).toObject()["username"].toString(),
                    list);
        }
        return;
    }
}

/*展示接收方信息*/
void SendPackageWindow::showRecvInfo(){
    if(totalUser.contains(ui->RecvUserName_Line->text())){
        QString recver = ui->RecvUserName_Line->text();
        ui->RecvName_Label->setText(totalUser[recver][0]);
        ui->RecvPhoneNum_Label->setText(totalUser[recver][1]);
        ui->RecvAddr_Label->setText(totalUser[recver][2]);
    }
    else{
        /*当接收方不存在时*/
        ui->RecvName_Label->setText("不存在");
        ui->RecvPhoneNum_Label->setText("不存在");
        ui->RecvAddr_Label->setText("不存在");
    }
}

/*发送包裹*/
void SendPackageWindow::sendPackage(){

    //判断输入是否合法
    if(!totalUser.contains(ui->RecvUserName_Line->text())){
        QMessageBox::critical (this,"出错","用户不存在");
        return;
    }
    //检查是不是自己
    if(ui->RecvUserName_Line->text() == theClient["username"].toString()){
        QMessageBox::about(this,"发包裹失败","您没必要给自己发快递");
        return;
    }

    if(ui->remark_Edit->toPlainText().length() == 0 ||
            ui->remark_Edit->toPlainText().length() > 200){
        QMessageBox::critical (this,"出错","备注不能为空且长度不能大于200");
        return;
    }

    if(ui->Price_Label->text().toDouble() <= 0.01){
        QMessageBox::critical (this,"出错","请设置有效的数量");
        return;
    }

    if(ui->Price_Label->text().toDouble() > theClient["balance"].toDouble()){
        QMessageBox::critical (this,"出错","余额不足，请充值后再试");
        return;
    }


    //构造报文并发送
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",6);
    QJsonObject info;
    info.insert("sender",theClient["username"].toString());
    info.insert("recver",ui->RecvUserName_Line->text());
    info.insert("type",ui->typeOfPkg->currentIndex());
    info.insert("number",ui->numberOfPkg->value());
    info.insert("remark",ui->remark_Edit->toPlainText());

    //插入到obj中
    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    //qDebug() << abyte;
    LoginWindow::con->write(abyte);
    /*绑定逻辑*/
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&SendPackageWindow::showResult);
}

//结果显示
void SendPackageWindow::showResult(){
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&SendPackageWindow::showResult);

    //读入并构造Json对象
    QByteArray tmp = LoginWindow::con->readAll();
    qDebug() << tmp;
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();

    //判断
    if(obj["status"].toInt() == 200){
        QJsonArray message = obj["message"].toArray();
        if(message[0].toObject()["result"].toInt() == 1){
            QMessageBox::about(this,"发送成功","快递单号:" + message[0].toObject()["index"].toString());
            emit sendFinish();
            this->close();
        }
        else{
            QMessageBox::critical(this,"错误","可以试试多充点钱");
        }
    }
    else{
        QMessageBox::critical(this,"错误","服务器忙");
    }

}

/*动态计算价格*/
void SendPackageWindow::showPrice(int){
    double price = 0.0;
    switch (ui->typeOfPkg->currentIndex()) {
    case 0:
        price = 7.5 * ui->numberOfPkg->value();
        break;
    case 1:
        price = 2 * ui->numberOfPkg->value();
        break;
    case 2:
        price = 5 * ui->numberOfPkg->value();
        break;
    default:
        break;
    }
    ui->Price_Label->setText(QString::number(price));
}
SendPackageWindow::~SendPackageWindow()
{
    delete ui;
}
