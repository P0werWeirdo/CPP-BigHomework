#include "changepassword.h"
#include "ui_changepassword.h"
#include<QMessageBox>
#include"loginwindow.h"
ChangePassword::ChangePassword(QJsonObject user,int type,QDialog *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    /*窗口基本设置*/
    this->setWindowTitle("修改密码");
    this->setWindowModality(Qt::WindowModal);
    this->setFixedSize(500,300);

    /*初始化内部成员*/
    this->theUser = user;
    this->type = type;
    /*初始化按钮逻辑*/
    connect(ui->btn_Cancel,&QPushButton::clicked,[=](){
        this->close();
    });

    connect(ui->btn_Confirm,&QPushButton::clicked,[=](){
        checkPassword();
    });

}

void ChangePassword::checkPassword(){
    //一些错误处理

    if(ui->newPassword->text() != ui->newPassword2->text()){
        QMessageBox::critical(this,"错误","两次密码输入不一致");
        return;
    }

    if(ui->newPassword->text().length() < 6 || ui->newPassword->text().length() > 20){
        QMessageBox::critical(this,"错误","新密码长度必须为6~20");
        return;
    }

    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",13);
    QJsonObject info;
    info.insert("username",theUser["username"].toString());
    info.insert("type",this->type);
    info.insert("oldPassword",ui->oldPassword->text());
    info.insert("newPassword",ui->newPassword->text());

    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    LoginWindow::con->write(abyte);
    /*绑定逻辑*/
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&ChangePassword::recvResponse);




//    if(theUser->changePassword(ui->oldPassword->text(),ui->newPassword->text())){
//        QMessageBox::about(this,"修改成功","密码已经修改成功!");
//        this->hide();
//        this->destroy();
//    }
//    else{
//        QMessageBox::about(this,"修改失败","请稍后重试");
//    }
}

void ChangePassword::recvResponse(){
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&ChangePassword::recvResponse);
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
            QMessageBox::about(this,"成功","您成功修改了密码");
            this->close();
        }
        else{
            QMessageBox::critical(this,"失败","请检查输入");
        }
        return;
    }


}



ChangePassword::~ChangePassword()
{
    delete ui;
}
