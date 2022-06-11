#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"package.h"
#include"client.h"
#include"courier.h"
#include"administrator.h"
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("服务器端");
    this->setFixedSize(600,600);
    /*初始化类内成员*/
    hasConnect = false;

    /*初始化数据*/
    initData();

    /*初始化窗口*/
    initWindow();

    /*初始化服务器*/
    initServer();
}

void MainWindow::initWindow(){
    ui->log->setReadOnly(true);
    ui->log->append("服务端启动中......");
}

//服务端数据初始化
void MainWindow::initData()const{
    Administrator::initAdmin();
    Client::initClientList();
    Courier::initCourierList();
    Package::initPackage();
}

void MainWindow::initServer(){          //初始化服务器
    listen = new QTcpServer(this);
    if(listen->listen(QHostAddress("127.0.0.1"),8000)){
        ui->log->append(QString("%1: 服务端启动完成").arg(QTime::currentTime().toString()));
    }
    else{
        ui->log->append(QString("%1: 服务端启动失败，请重启").arg(QTime::currentTime().toString()));
    }
    connect(listen, &QTcpServer::newConnection, [=](){
        if(!hasConnect){
           hasConnect=true;
           ui->log->append(QString("%1: 与客户端建立连接").arg(QTime::currentTime().toString()));
        }else{
           return;
        }
        con = listen->nextPendingConnection();


        //利用json首发数据
        ui->log->append(QString("%1: 向客户端发送数据").arg(QTime::currentTime().toString()));
        connect(con, &QTcpSocket::readyRead, [=](){
            QByteArray byte = con->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(byte);
            QJsonObject obj = doc.object();

        });

        connect(con, &QTcpSocket::disconnected, [=](){
            ui->log->append(QString("%1: 与客户端断开连接").arg(QTime::currentTime().toString()));
            hasConnect = false;
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

