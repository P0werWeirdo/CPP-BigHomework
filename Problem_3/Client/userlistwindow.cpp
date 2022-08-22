#include "userlistwindow.h"
#include "ui_userlistwindow.h"
#include"userinfowindow.h"
#include<QMessageBox>
#include"loginwindow.h"

UserListWindow::UserListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserListWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("用户表格");
    this->setWindowModality(Qt::WindowModal);

    /*设置页面信息*/
    this->setWindowTitle("用户信息");
    this->admin = -1;
    /*初始化表格*/
    ui->ClientListTb->setColumnCount(4);
    ui->ClientListTb->setHorizontalHeaderLabels(QStringList()<<"用户账号"<<"用户密码"<<"用户姓名"<<"用户电话");
    ui->ClientListTb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ClientListTb->setCornerButtonEnabled(false);
    /*隐藏删除按钮*/
    ui->widget->hide();
    /*表格逻辑*/
    connect(ui->ClientListTb,&QTableWidget::itemDoubleClicked,this,&UserListWindow::showDetailInfo);

    /*发送请求*/
    sendClientReq();
}

UserListWindow::UserListWindow(int admin,QWidget *parent):
    QDialog(parent),
    ui(new Ui::UserListWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("快递员表格");
    this->setWindowModality(Qt::WindowModal);

    /*设置页面信息*/
    this->setWindowTitle("快递员信息");
    this->admin = admin;

    /*初始化表格*/
    ui->ClientListTb->setColumnCount(4);
    ui->ClientListTb->setHorizontalHeaderLabels(QStringList()<<"快递员账号"<<"快递员密码"<<"快递员姓名"<<"快递员电话");
    ui->ClientListTb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ClientListTb->setCornerButtonEnabled(false);

    /*表格逻辑*/
    connect(ui->ClientListTb,&QTableWidget::itemDoubleClicked,this,&UserListWindow::showDetailInfo);

    /*删除逻辑*/
    connect(ui->btn_del,&QPushButton::clicked,[=](){
        int row = ui->ClientListTb->currentRow();
        if(row < 0 || row >= ui->ClientListTb->rowCount()){
            QMessageBox::critical(this,"删除失败","请稍后重试");
            return ;
        }
        qDebug()<<"删";
        sendDeleteCourier();
    });
    /*发送请求*/
    sendCourierReq();
}


void UserListWindow::showInfo(){
    int len = userList.size();
    ui->ClientListTb->setRowCount(len);
    if(len == 0){
        return;
    }
    int col;
    int row = 0;
    /*填充table*/
    for(auto i = userList.constBegin();i != userList.constEnd(); i++,row++){
        col = 0;
        //qDebug()<< pkg[i]->getIndex();
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()["username"].toString()));
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()["password"].toString()));
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()["name"].toString()));
        ui->ClientListTb->setItem(row,col++,new QTableWidgetItem(i.value()["phone"].toString()));
    }
}

//发送查询客户和快递员的请求
void UserListWindow::sendClientReq()const{
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",7);
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
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&UserListWindow::initClientList);
}

void UserListWindow::sendCourierReq()const{
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
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&UserListWindow::initCourierList);
}

//对请求进行处理
void UserListWindow::initClientList(){
    //首先解绑
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&UserListWindow::initClientList);

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
        QJsonArray client = obj["message"].toArray();
        this->userList.clear();
        for(auto item = client.constBegin();item != client.constEnd();item++){
            this->userList.insert((*item).toObject()["username"].toString(),
                    (*item).toObject());
        }
        showInfo();
        return;
    }
}

void UserListWindow::initCourierList(){
    //首先解绑
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&UserListWindow::initCourierList);

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
        this->userList.clear();
        for(auto item = courier.constBegin();item != courier.constEnd();item++){
            this->userList.insert((*item).toObject()["username"].toString(),
                    (*item).toObject());
        }
        showInfo();
        return;
    }
}

void UserListWindow::showDetailInfo(QTableWidgetItem *item){

    QString tmp = ui->ClientListTb->item(item->row(),0)->text();
    if(admin == -1){
    //查看用户详细信息
        UserInfoWindow *userInfo = new UserInfoWindow(
                    userList[tmp],1,2,this);
        userInfo->show();
     }
    else{
    //查看快递员详细信息
        UserInfoWindow *userInfo = new UserInfoWindow(
                   userList[tmp],3,3,this);
        userInfo->show();
    }
}

void UserListWindow::sendDeleteCourier()const{
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",12);
    QJsonObject info;
    info.insert("type",1);
    int row = ui->ClientListTb->currentRow();
    info.insert("aim",ui->ClientListTb->item(row,0)->text());

    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    LoginWindow::con->write(abyte);
    /*绑定逻辑*/
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&UserListWindow::recvDeleteResult);
}

void UserListWindow::recvDeleteResult(){
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&UserListWindow::recvDeleteResult);


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
        bool result = obj["message"].toArray()[0].toObject()["result"].toBool();
        if(result){
            QMessageBox::about(this,"删除成功","此快递员已经被删除了");
            sendCourierReq();
        }
        else{
            QMessageBox::critical(this,"删除失败","请重新尝试");
        }
        return;
    }
}


UserListWindow::~UserListWindow()
{
    delete ui;
}
