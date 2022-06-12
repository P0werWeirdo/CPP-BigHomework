#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"package.h"
#include"client.h"
#include"courier.h"
#include"administrator.h"
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonDocument>
#include<QDebug>

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


        //利用json收发数据
        ui->log->append(QString("%1: 向客户端发送数据").arg(QTime::currentTime().toString()));
        connect(con, &QTcpSocket::readyRead, [=](){
            QByteArray byte = con->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(byte);
            QJsonObject obj = doc.object();
            qDebug() <<byte;
            switch (obj["target"].toInt()) {
            case 1://管理员要登录
                adminLogin(obj["user"].toObject());
                break;
            case 2: //快递员
                courierLogin(obj["user"].toObject());
                break;
            case 3://客户要登录
                clientLogin(obj["user"].toObject());
                break;
            case 4: //注册新客户
                clientRegister(obj["user"].toObject());
                break;
            case 5: //注册新快递员
                courierRegister(obj["user"].toObject());
                break;
            case 6://发送包裹
                sendPackage(obj["info"].toObject());
                break;
            case 7: //查询用户
                searchClient(obj["info"].toObject());
                break;
            case 8: //查询包裹
                searchPackage(obj["info"].toObject());
                break;
            case 9: //处理包裹
//                qDebug()<< byte;
                dealWithPackage(obj["info"].toObject());
                break;
            case 10:    //充钱钱
                addMoney(obj["info"].toObject());
                break;
            case 11:    //查询快递员
                searchCourier(obj["info"].toObject());
                break;
            case 12:
                qDebug()<<byte;
                deleteCourier(obj["info"].toObject());
                break;
            case 13:
                changePassword(obj["info"].toObject());
                break;
            default:
                break;
            }
        });

        connect(con, &QTcpSocket::disconnected, [=](){
            ui->log->append(QString("%1: 与客户端断开连接").arg(QTime::currentTime().toString()));
            hasConnect = false;
        });
    });
}

//用户登录请求
void MainWindow::adminLogin(QJsonObject admin){
    //打印提示信息
    ui->log->append(QString("%1: 用户以管理员身份尝试登录").arg(QTime::currentTime().toString()));

//    qDebug() << admin["username"].toString() << admin["password"].toString();
    if(admin["username"].toString() == Administrator::admin.getUsername()
            && admin["password"].toString() == Administrator::admin.getPassword()){
        QJsonObject res;
        res.insert("status",200);
        //构造message
        QJsonArray message;
        QJsonObject item;
        item.insert("username",Administrator::admin.getUsername());
        item.insert("name",Administrator::admin.getName());
        item.insert("phone",Administrator::admin.getPhoneNum());
        item.insert("balance",Administrator::admin.getBalance());
        message.append(item);
        res.insert("message",message);
        //转为Documen
        QJsonDocument doc2;
        doc2.setObject(res);
        QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
        qDebug() << abyte;
        con->write(abyte);
        ui->log->append(QString("%1: 管理员登录成功").arg(QTime::currentTime().toString()));
    }
    else{
        QJsonObject res;
        res.insert("status",400);
        QJsonDocument doc2;
        doc2.setObject(res);
        QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
        con->write(abyte);
    }
}
//客户登录请求
void MainWindow::clientLogin(QJsonObject client){
    //提示消息
    ui->log->append(QString("%1: 用户以客户身份请求登录").arg(QTime::currentTime().toString()));
    qDebug() << client["username"].toString() << client["password"].toString();

    //进行登录
    QString username = client["username"].toString();
    QString password = client["password"].toString();
    if(Client::clientList.contains(username) == true &&
            Client::clientList[username]->getPassword() == password){

        QJsonObject res;
        res.insert("status",200);

        //构造message
        QJsonArray message;
        QJsonObject item;
        item.insert("username",Client::clientList[username]->getUsername());
        item.insert("name",Client::clientList[username]->getName());
        item.insert("phone",Client::clientList[username]->getPhoneNum());
        item.insert("balance",Client::clientList[username]->getBalance());
        item.insert("address",Client::clientList[username]->getAddress());
        message.append(item);
        res.insert("message",message);

        //转为Document
        QJsonDocument doc2;
        doc2.setObject(res);
        QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
        qDebug() << abyte;
        con->write(abyte);
        ui->log->append(QString("%1: 用户%2登录成功").arg(QTime::currentTime().toString(),
                                                    client["username"].toString()));
    }
    else{
        //构造登录失败的信息
        QJsonObject res;
        res.insert("status",400);
        QJsonDocument doc2;
        doc2.setObject(res);
        QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
        con->write(abyte);
    }

}

//快递员登录
void MainWindow::courierLogin(QJsonObject courier){
    //提示消息
    ui->log->append(QString("%1: 用户以快递员身份请求登录").arg(QTime::currentTime().toString()));
    qDebug() << courier["username"].toString() << courier["password"].toString();

    //进行登录
    QString username = courier["username"].toString();
    QString password = courier["password"].toString();
    if(Courier::courierList.contains(username) == true &&
            Courier::courierList[username]->getPassword() == password){

        QJsonObject res;
        res.insert("status",200);

        //构造message
        QJsonArray message;
        QJsonObject item;
        item.insert("username",Courier::courierList[username]->getUsername());
        item.insert("name",Courier::courierList[username]->getName());
        item.insert("phone",Courier::courierList[username]->getPhoneNum());
        item.insert("balance",Courier::courierList[username]->getBalance());
        message.append(item);
        res.insert("message",message);

        //转为Document
        QJsonDocument doc2;
        doc2.setObject(res);
        QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
        qDebug() << abyte;
        con->write(abyte);
        ui->log->append(QString("%1: 快递员%2登录成功").arg(QTime::currentTime().toString(),
                                                     courier["username"].toString()));
    }
    else{
        //构造登录失败的信息
        QJsonObject res;
        res.insert("status",400);
        QJsonDocument doc2;
        doc2.setObject(res);
        QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
        con->write(abyte);
    }
}

//客户注册
void MainWindow::clientRegister(QJsonObject client){
    ui->log->append(QString("%1: 用户请求注册").arg(QTime::currentTime().toString()));

    //注册操作
    QString username = client["username"].toString();
    QString password = client["password"].toString();
    QString name = client["name"].toString();
    QString phoneNum = client["phone"].toString();
    QString address = client["address"].toString();
    int result = Client::registerNewClient(username,password,name,phoneNum,address);


    QJsonObject res;
    res.insert("status",200);

    //构造message
    QJsonArray message;
    QJsonObject item;
    item.insert("result",result);

    message.append(item);
    res.insert("message",message);

    //转为Document
    QJsonDocument doc2;
    doc2.setObject(res);
    QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    con->write(abyte);

}

//快递员注册
void MainWindow::courierRegister(QJsonObject courier){
    ui->log->append(QString("%1: 管理员请求注册快递员%2").arg(QTime::currentTime().toString(),courier["username"].toString()));

    //注册操作
    QString username = courier["username"].toString();
    QString password = courier["password"].toString();
    QString name = courier["name"].toString();
    QString phoneNum = courier["phone"].toString();
    int result = Courier::registerNewCourier(username,password,name,phoneNum);


    QJsonObject res;
    res.insert("status",200);

    //构造message
    QJsonArray message;
    QJsonObject item;
    item.insert("result",result);

    message.append(item);
    res.insert("message",message);

    //转为Document
    QJsonDocument doc2;
    doc2.setObject(res);
    QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    con->write(abyte);
}

//查询用户
void MainWindow::searchClient(QJsonObject client){
    ui->log->append(QString("%1: 查询用户").arg(QTime::currentTime().toString()));
    //查看用户类型和查询对象
    int type = client["type"].toInt();
    QString aim = client["aim"].toString();

    QJsonObject res;
    QJsonArray message;

    if(aim == "ALL"){   //全部人
        //构造message
        res.insert("status",200);
        for(auto i = Client::clientList.cbegin();i != Client::clientList.cend();i++){
            QJsonObject item;
            item.insert("username",(*i)->getUsername());
            item.insert("name",(*i)->getName());
            if(type == 1){
                item.insert("password",(*i)->getPassword());
                item.insert("balance",(*i)->getBalance());
            }
            item.insert("phone",(*i)->getPhoneNum());
            item.insert("address",(*i)->getAddress());
            message.append(item);
        }


    }
    else if(Client::clientList.contains(aim)){  //当是某个人
        res.insert("status",200);//找到了

        //构造Json并发送
        Client *theClient = Client::clientList[aim];
        QJsonObject item;
        item.insert("username",theClient->getUsername());
        item.insert("name",theClient->getName());
        if(type == 1){
            item.insert("password",theClient->getPassword());
            item.insert("balance",theClient->getBalance());
        }
        item.insert("phone",theClient->getPhoneNum());
        item.insert("address",theClient->getAddress());
        message.append(item);
    }
    else{
        res.insert("status",404);
    }
    res.insert("message",message);

    //转为Document
    QJsonDocument doc2;
    doc2.setObject(res);
    QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    con->write(abyte);
}

//发送包裹
void MainWindow::sendPackage(QJsonObject package){    //发送包裹
    ui->log->append(QString("%1: 发送包裹").arg(QTime::currentTime().toString()));
    //先提取信息
    QString sender = package["sender"].toString();
    QString recver = package["recver"].toString();
    int type = package["type"].toInt() + 1;
    double number = package["number"].toDouble();
    QString remark = package["remark"].toString();

    QJsonObject res;
    QJsonArray message;
    res.insert("status",200);
    //查看有没有这人
    if(!Client::clientList.contains(sender) ||
            !Client::clientList.contains(recver)){
        QJsonObject item;
        item.insert("result",0);
        message.append(item);
    }
    else{
        Client *theClient = Client::clientList[sender];
        QString index = theClient->sendPackage(Client::clientList[recver],remark,number,type);

        QJsonObject item;//临时存储
        if(index == ""){    //发送失败了
            item.insert("result",0);
        }
        else{               //发送成功
            item.insert("result",1);
            item.insert("index",index);
        }
        message.append(item);
    }
    res.insert("message",message);

    //转为Document
    QJsonDocument doc2;
    doc2.setObject(res);
    QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
//    qDebug() << abyte;
    con->write(abyte);
}

//查询包裹
void MainWindow::searchPackage(QJsonObject user){
    ui->log->append(QString("%1: 查询包裹").arg(QTime::currentTime().toString()));
    //先提取信息
    QString username = user["username"].toString();
    int type = user["type"].toInt();

    QJsonObject res;
    QJsonArray message;
   // res.insert("status",200);

    if(type == 1){  //管理员

        res.insert("status",200);
        for(auto i = Administrator::admin.getMyPackage().cbegin();
            i != Administrator::admin.getMyPackage().cend(); i++){
            QJsonObject item;
            item.insert("index",(*i)->getIndex());

            //发送方信息
            item.insert("senderUsername",(*i)->getSender()->getUsername());
            item.insert("senderName",(*i)->getSender()->getName());
            item.insert("senderTime",(*i)->getSendTime().toSecsSinceEpoch());

            //揽收人员
            if((*i)->getCollector() != NULL){
                item.insert("collectorUsername",(*i)->getCollector()->getUsername());
                item.insert("collectorName",(*i)->getCollector()->getName());
            }
            else{
                item.insert("collectorUsername","");
                item.insert("collectorName","");
            }

            //揽收时间
            item.insert("collectorTime",(*i)->getCollectTime().toSecsSinceEpoch());

            //接受方信息
            item.insert("recverUsername",(*i)->getRecver()->getUsername());
            item.insert("recverName",(*i)->getRecver()->getName());
            item.insert("recverTime",(*i)->getRecvTime().toSecsSinceEpoch());

            //快递的基本信息
            item.insert("address",(*i)->getAddr());
            item.insert("status",(*i)->getStatus());
            item.insert("price",(*i)->getPrice());
            item.insert("remark",(*i)->getRemark());

            message.append(item);
        }
    }
    else if(type == 2){ //客户
        if(Client::clientList.contains(username)){
            res.insert("status",200);
            for(auto i = Client::clientList[username]->getMyPackage().cbegin();
                i != Client::clientList[username]->getMyPackage().cend(); i++){
                QJsonObject item;
                item.insert("index",(*i)->getIndex());

                //发送方信息
                item.insert("senderUsername",(*i)->getSender()->getUsername());
                item.insert("senderName",(*i)->getSender()->getName());
                item.insert("senderTime",(*i)->getSendTime().toSecsSinceEpoch());

                //揽收人员
                if((*i)->getCollector() != NULL){
                    item.insert("collectorUsername",(*i)->getCollector()->getUsername());
                    item.insert("collectorName",(*i)->getCollector()->getName());
                }
                else{
                    item.insert("collectorUsername","");
                    item.insert("collectorName","");
                }

                //揽收时间
                item.insert("collectorTime",(*i)->getCollectTime().toSecsSinceEpoch());

                //接受方信息
                item.insert("recverUsername",(*i)->getRecver()->getUsername());
                item.insert("recverName",(*i)->getRecver()->getName());
                item.insert("recverTime",(*i)->getRecvTime().toSecsSinceEpoch());

                //快递的基本信息
                item.insert("address",(*i)->getAddr());
                item.insert("status",(*i)->getStatus());
                item.insert("price",(*i)->getPrice());
                item.insert("remark",(*i)->getRemark());

                message.append(item);
            }
        }
        else{
            //客户不存在
            res.insert("status",300);
        }
    }
    else{   //快递员
        if(Courier::courierList.contains(username)){
            res.insert("status",200);
            for(auto i = Courier::courierList[username]->getMyPackage().cbegin();
                i != Courier::courierList[username]->getMyPackage().cend(); i++){
                QJsonObject item;
                item.insert("index",(*i)->getIndex());

                //发送方信息
                item.insert("senderUsername",(*i)->getSender()->getUsername());
                item.insert("senderName",(*i)->getSender()->getName());
                item.insert("senderTime",(*i)->getSendTime().toSecsSinceEpoch());

                //揽收人员
                if((*i)->getCollector() != NULL){
                    item.insert("collectorUsername",(*i)->getCollector()->getUsername());
                    item.insert("collectorName",(*i)->getCollector()->getName());
                }
                else{
                    item.insert("collectorUsername","");
                    item.insert("collectorName","");
                }

                //揽收时间
                item.insert("collectorTime",(*i)->getCollectTime().toSecsSinceEpoch());

                //接受方信息
                item.insert("recverUsername",(*i)->getRecver()->getUsername());
                item.insert("recverName",(*i)->getRecver()->getName());
                item.insert("recverTime",(*i)->getRecvTime().toSecsSinceEpoch());

                //快递的基本信息
                item.insert("address",(*i)->getAddr());
                item.insert("status",(*i)->getStatus());
                item.insert("price",(*i)->getPrice());
                item.insert("remark",(*i)->getRemark());

                message.append(item);
            }
        }
        else{
            //快递员不存在
            res.insert("status",300);
        }
    }

    res.insert("message",message);
    //转为Document
    QJsonDocument doc2;
    doc2.setObject(res);
    QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
//    qDebug() << abyte;
    con->write(abyte);
}

//处理包裹
void MainWindow::dealWithPackage(QJsonObject info){
    ui->log->append(QString("%1: 处理包裹").arg(QTime::currentTime().toString()));
    //先提取信息
    QString username = info["username"].toString();
    int type = info["type"].toInt();
    QJsonArray needToDeal = info["message"].toArray();
//    qDebug() << username << type;
    QJsonObject res;
    QJsonArray message;
   // res.insert("status",200);

    if(type == 1){  //管理员
        res.insert("status",200);
        for(auto i = needToDeal.constBegin();
            i != needToDeal.constEnd(); i++){
            //提取快递员和包裹信息
            QJsonObject tmp = (*i).toObject();
            QString pkgIndex = tmp["index"].toString();
            QString courier = tmp["username"].toString();

            //分发
            bool result = Administrator::admin.distribute(courier,pkgIndex);

            //回答
            QJsonObject item;
            item.insert("result",result);
            message.append(item);
        }
    }
    else if(type == 2){ //客户
        if(Client::clientList.contains(username)){
            res.insert("status",200);

            //当前客户
            Client *theClient = Client::clientList[username];
            QList<Package *>pkgList;
            bool isSuccess = true;
            for(auto i = needToDeal.constBegin();
                i != needToDeal.constEnd(); i++){   //需要签收的快递依次入队

                if(theClient->getMyPackage().contains((*i).toString())){    //是否存在
                    pkgList.push_back(theClient->getMyPackage()[(*i).toString()]);
                }
                else{
                    isSuccess = false;
                }
            }

            bool result = theClient->recvPackage(pkgList) && isSuccess;

            //回答
            QJsonObject item;
            item.insert("result",result);
            message.append(item);
        }
        else{
            //客户不存在
            res.insert("status",300);
        }
    }
    else{   //快递员
        if(Courier::courierList.contains(username)){

            res.insert("status",200);
            //当前快递员
            Courier *theCourier = Courier::courierList[username];
            QList<Package *>pkgList;
            bool isSuccess = true;
            for(auto i = needToDeal.constBegin();
                i != needToDeal.constEnd(); i++){   //需要揽收的快递依次入队

                if(theCourier->getMyPackage().contains((*i).toString())){    //是否存在
                    pkgList.push_back(theCourier->getMyPackage()[(*i).toString()]);
                }
                else{
                    isSuccess = false;
                }
            }

            bool result = theCourier->collectPackage(pkgList) && isSuccess;

            //回答
            QJsonObject item;
            item.insert("result",result);
            message.append(item);
        }
        else{
            //快递员不存在
            res.insert("status",300);
        }
    }

    res.insert("message",message);
    //转为Document
    QJsonDocument doc2;
    doc2.setObject(res);
    QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
//    qDebug() << abyte;
    con->write(abyte);
}

//充钱充钱
void MainWindow::addMoney(QJsonObject info){

    ui->log->append(QString("%1: 有人充钱").arg(QTime::currentTime().toString()));
    //提取信息
    QString username = info["username"].toString();
    int type = info["type"].toInt();
    int money = info["message"].toArray()[0].toObject()["money"].toInt();

    QJsonObject res;
    QJsonArray message;
    if(Client::clientList.contains(username)){
        res.insert("status",200);
        Client *theClient = Client::clientList[username];
        QJsonObject item;

        //构造回复报文
        bool result = theClient->changeBalance((double)(money));
        item.insert("result",result);
        message.append(item);
        res.insert("message",message);
    }
    else{
        res.insert("status",300);
    }

    //转为Document
    QJsonDocument doc2;
    doc2.setObject(res);
    QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
//    qDebug() << abyte;
    con->write(abyte);
}

//查询快递员
void MainWindow::searchCourier(QJsonObject info){
    ui->log->append(QString("%1: 查询快递员").arg(QTime::currentTime().toString()));
    //查看用户类型和查询对象
    int type = info["type"].toInt();
    QString aim = info["aim"].toString();

    QJsonObject res;
    QJsonArray message;

    if(aim == "ALL"){   //全部人
        //构造message
        res.insert("status",200);
        for(auto i = Courier::courierList.cbegin();i != Courier::courierList.cend();i++){
            QJsonObject item;
            item.insert("username",(*i)->getUsername());
            item.insert("name",(*i)->getName());
            if(type == 1){
                item.insert("password",(*i)->getPassword());
                item.insert("balance",(*i)->getBalance());
            }
            item.insert("phone",(*i)->getPhoneNum());
            message.append(item);
        }
    }
    else if(Courier::courierList.contains(aim)){  //当是某个人
        res.insert("status",200);//找到了

        //构造Json并发送
        Courier *theCourier = Courier::courierList[aim];
        QJsonObject item;
        item.insert("username",theCourier->getUsername());
        item.insert("name",theCourier->getName());
        if(type == 1){
            item.insert("password",theCourier->getPassword());
            item.insert("balance",theCourier->getBalance());
        }
        item.insert("phone",theCourier->getPhoneNum());
        message.append(item);
    }
    else{
        res.insert("status",404);
    }
    res.insert("message",message);

    //转为Document
    QJsonDocument doc2;
    doc2.setObject(res);
    QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    con->write(abyte);
}

void MainWindow::changePassword(QJsonObject info){      //修改密码
    ui->log->append(QString("%1: 修改密码").arg(QTime::currentTime().toString()));
    //先提取信息
    QString username = info["username"].toString();
    int type = info["type"].toInt();
    QString oldPassword = info["oldPassword"].toString();
    QString newPassword = info["newPassword"].toString();
    QJsonObject res;
    QJsonArray message;
   // res.insert("status",200);

    if(type == 1){  //管理员
        res.insert("status",200);
        //修改密码
        bool result = Administrator::admin.changePassword(oldPassword,newPassword);

        //回答
        QJsonObject item;
        item.insert("result",result);
        message.append(item);

    }
    else if(type == 2){ //客户
        if(Client::clientList.contains(username)){
            res.insert("status",200);
            //回答
            bool result = Client::clientList[username]->changePassword(oldPassword,newPassword);

            //回答
            QJsonObject item;
            item.insert("result",result);
            message.append(item);
        }
        else{
            //客户不存在
            res.insert("status",300);
        }
    }
    else{   //快递员
        if(Courier::courierList.contains(username)){

            res.insert("status",200);


            bool result = Courier::courierList[username]->changePassword(oldPassword,newPassword);

            //回答
            QJsonObject item;
            item.insert("result",result);
            message.append(item);
        }
        else{
            //快递员不存在
            res.insert("status",300);
        }
    }

    res.insert("message",message);
    //转为Document
    QJsonDocument doc2;
    doc2.setObject(res);
    QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
//    qDebug() << abyte;
    con->write(abyte);
}

void MainWindow::deleteCourier(QJsonObject info){       //删除快递员
    ui->log->append(QString("%1: 删除快递员").arg(QTime::currentTime().toString()));
    //先提取信息
    int type = info["type"].toInt();
    QString aim = info["aim"].toString();
    QJsonObject res;
    QJsonArray message;

    if(type == 1 && Courier::courierList.contains(aim)){

        res.insert("status",200);
        bool result = Courier::deleteCourier(aim);

        //回答
        QJsonObject item;
        item.insert("result",result);
        message.append(item);
        res.insert("message",message);
    }
    else{
        //快递员不存在
        res.insert("status",300);
    }

    //转为Document
    QJsonDocument doc2;
    doc2.setObject(res);
    QByteArray abyte = doc2.toJson(QJsonDocument::Compact);
//    qDebug() << abyte;
    con->write(abyte);
}

MainWindow::~MainWindow()
{
    delete ui;
}

