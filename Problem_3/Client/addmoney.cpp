#include "addmoney.h"
#include "ui_addmoney.h"
#include<QMessageBox>
#include"loginwindow.h"

AddMoney::AddMoney(QJsonObject c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMoney)
{
    ui->setupUi(this);
    this->setWindowTitle("充值窗口");
    this->setWindowModality(Qt::WindowModal);
    /*初始化提示*/
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->Tips_Label->setPalette(pa);
    /*初始化内部成员*/
    theClient = c;
    /*初始化按钮逻辑*/
    connect(ui->btn_Confirm,&QPushButton::clicked,[=](){
        addReq();
    });
}


void AddMoney::addReq()const{  //充值操作检测
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",10);

    //构造info
    QJsonObject info;
    info.insert("username",theClient["username"].toString());
    info.insert("type",2);

    //构造message
    QJsonArray message;
    QJsonObject item;
    item.insert("money",ui->MoneyNum->value());
    message.append(item);
    info.insert("message",message);

    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    LoginWindow::con->write(abyte);
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&AddMoney::addRes);

}

void AddMoney::addRes(){  //充值回应
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&AddMoney::addRes);


    QByteArray tmp = LoginWindow::con->readAll();
//    qDebug() << tmp;
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();

    int status = obj["status"].toInt();
    bool result = obj["message"].toArray()[0].toObject()["result"].toBool();

    if(status != 200){
        QMessageBox::critical(this,"充值失败","服务器忙");
    }


    if(result){
        QMessageBox::about(this,"充值成功","您已经成功充值");
        emit addFinish();
        this->close();
        this->deleteLater();
    }
    else{
        QMessageBox::critical(this,"充值失败","请重新尝试");
    }
}

AddMoney::~AddMoney()
{
    delete ui;
}
