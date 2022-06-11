#include "sendpackagewindow.h"
#include "ui_sendpackagewindow.h"
#include<QMessageBox>
#include<QRegExpValidator>
#include"administrator.h"
#include<QDebug>
SendPackageWindow::SendPackageWindow(QWidget *parent,Client* theClient) :
    QDialog(parent),
    ui(new Ui::SendPackageWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("发送快递");
    this->setWindowModality(Qt::WindowModal);

    if(theClient == NULL){
        QMessageBox::critical (this,"出错","没有用户");
        this->hide();
        this->destroy();
    }

    /*初始化成员*/
    this->theClient = theClient;
    if(this->theClient == NULL){
        QMessageBox::critical (this,"出错","没有用户");
        this->hide();
        this->destroy();
    }

    /*初始化页面*/
    initSenderInfo();
    /*对搜索框限制*/
    /*禁止用户名框输入中文*/
    QRegExp regx1("[a-zA-Z0-9]+$");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->RecvUserName_Line);
    ui->RecvUserName_Line->setValidator( validator1 );
    /*设置价格*/
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->Price_Label->setPalette(pa);
    ui->Price_Label->setText("15");
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
}
/*初始化发送方信息*/
void SendPackageWindow::initSenderInfo(){
    /*初始化页面*/
    ui->Index_label->setText(Package::createTotalPackage());
    ui->SenderUsername_Label->setText(theClient->getUsername());
    ui->SenderName_Label->setText(theClient->getName());
    ui->SenderPhoneNum_Label->setText(theClient->getPhoneNum());
}

/*展示接收方信息*/
void SendPackageWindow::showRecvInfo(){
    if(Client::clientList.contains(ui->RecvUserName_Line->text())){
        Client* recv = Client::clientList[ui->RecvUserName_Line->text()];
        ui->RecvName_Label->setText(recv->getName());
        ui->RecvPhoneNum_Label->setText(recv->getPhoneNum());
        ui->RecvAddr_Label->setText(recv->getAddress());
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
    //发送包裹并进行差错校验
    //判断钱够不够
//    qDebug() << theClient->getBalance();
//    qDebug() << ui->Price_Label->text().toDouble();
//    qDebug() << (theClient->getBalance() < ui->Price_Label->text().toDouble());
    if( theClient->getBalance() - ui->Price_Label->text().toDouble() >= 0){
        //判断输入是否合法
        if(Client::clientList.contains(ui->RecvUserName_Line->text())){
            //检查是不是自己
            if(Client::clientList[ui->RecvUserName_Line->text()] == theClient){
                QMessageBox::about(this,"发包裹失败","您没必要给自己发快递");
                return;
            }

            if(ui->remark_Edit->toPlainText().length() == 0 ||
                    ui->remark_Edit->toPlainText().length() > 200){
                QMessageBox::critical (this,"出错","备注不能为空且长度不能大于200");
                return;
            }
            //发送快递结束
            if(theClient->sendPackage(Client::clientList[ui->RecvUserName_Line->text()],ui->remark_Edit->toPlainText(),15)){
                QMessageBox::about(this,"发包裹成功","请可在<我的快递>功能查询快递状态");
                emit sendFinish();
                this->close();
                this->deleteLater();
            }
            else{
                QMessageBox::critical(this,"发包裹失败","请稍后重试");
            }

        }
        else{
            QMessageBox::critical (this,"出错","用户不存在");
        }
    }
    else{
        QMessageBox::critical (this,"余额不足","余额不足,请充值后再试");
    }
}
SendPackageWindow::~SendPackageWindow()
{
    delete ui;
}
