#include "client.h"
#include<QFile>
#include<QCoreApplication>
#include<QTextStream>
#include<QDebug>
#include"fragile.h"
#include"book.h"
#include"common.h"
#include"administrator.h"

QMap<QString,Client *> Client::clientList;      //总客户表

Client::Client()
{
}
/*含参构造函数*/
Client::Client(QString username,QString password,QString name,QString phoneNum,QString address){
    this->username = username;
    this->password = password;
    this->name = name;
    this->phoneNum = phoneNum;
    this->balance = 0;
    this->address = address;
}

QString Client::getAddress()const{      //返回地址
    return this->address;
}

int Client::getType(){
    return 2;
}

void Client::initClientList(){
    QFile file(QCoreApplication::applicationDirPath() + "/data/client.txt");          //读入文件
    file.open(QIODevice::ReadOnly| QIODevice::Text);
    //查看文件是否打开，打不开直接退出
    if(file.isOpen()){
        QString data;
        QStringList clientData;
        if(file.size() != 0){
           QTextStream in(&file);
           while(!in.atEnd()){
               data = in.readLine();
               clientData = data.split(' ');                                         //根据' '进行分割
               Client* tmp = new Client;
               //读用户名
               tmp->username = clientData[0];
               tmp->password = clientData[1];
               //读入姓名
               tmp->name = clientData[2];
               //读电话 余额 地址
               tmp->phoneNum = clientData[3];
               tmp->balance = clientData[4].toDouble();
               tmp->address = clientData[5];
               clientList.insert(tmp->getUsername(),tmp);                                          //添加到总客户表

            }
        }
    }
    else{
        qDebug()<<"client.txt读入失败";
        exit(-1);
    }
    file.close();
}



bool Client::saveClientList(){
    QFile file(QCoreApplication::applicationDirPath() + "/data/client.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(file.isOpen()){
        QTextStream in(&file);
        for(auto i = clientList.begin();i != clientList.end() ;i++){
            //按顺序写入
            in<<i.value()->username<<' '<<i.value()->password<<' '<<i.value()->name<<' '
              <<i.value()->phoneNum<<' '<<i.value()->balance<<' '<<i.value()->address<<endl;
        }

    }
    else{
        return false;
    }
    file.close();
    return true;
}

bool Client::sendPackage(Client* recver,QString remarks,double number,char type){    //发送快递
    if(remarks.length() == 0 || remarks.length() > 200){
        return false;
    }
    Package* newpkg = NULL;
    switch (type) {
    case 1://易碎品
        newpkg = new Fragile(this,recver,remarks,number);
        break;
    case 2://书籍
        newpkg = new Book(this,recver,remarks,number);
        break;
    case 3://普通快递
        newpkg = new Common(this,recver,remarks,number);
        break;
    default:
        return false;
    }

    if(this->balance < newpkg->getPrice()){
        delete newpkg;
        return false;
    }
    else{
        this->balance -=newpkg->getPrice();
        Administrator::admin.changeBalance(newpkg->getPrice());
    }
    Package::packageList.insert(newpkg->getIndex(),newpkg);
    this->myPackage.insert(newpkg->getIndex(),newpkg);
    Administrator::admin.saveToMyPackage(newpkg);
    recver->myPackage.insert(newpkg->getIndex(),newpkg);
    Administrator::saveAdmin();
    Client::saveClientList();
    Package::savePackage();
    return true;
}

bool Client::recvPackage(QList<Package *> pkgList){ //接受快递
    return Package::recvpkgList(pkgList);
}


bool Client::changeAddress(QString newAddr){           //改变地址
    if(newAddr.length() == 0){
        return false;
    }
    this->address = newAddr;
    //Administrator::saveAdmin();
    Client::saveClientList();
    //Package::savePackage();
    return true;
}

//注册新用户 返回1: 用户名过长或过短 返回2：用户名重复 返回3:密码过长或过短 返回4:手机号不符合格式 返回5:姓名检测 返回6:地址检测
//返回7:地址过长 返回0:注册成功
int Client::registerNewClient(QString username,QString password,QString name,QString phoneNum,QString address){
    //用户名检测
    if(username.length() < 4 || username.length() > 20){
        return 1;
    }
    if(clientList.contains(username)){
        return 2;
    }
    //密码检测
   if(password.length() < 6 || password.length() > 20){
        return 3;
   }
   //姓名检测
   if(name.length() == 0){
       return 5;
   }
   //地址检测
   if(address.length() == 0){
       return 6;
   }
   //手机号检测
   if(phoneNum.length() != 11){
        for(int i = 0;i < 11;i++){
            if(phoneNum[i] < '0' || phoneNum[i] > '9'){
                return 4;
            }
        }
   }

   if(address.length() >= 200){
       return 7;
   }

   Client *newClient = new Client(username,password,name,phoneNum,address);
   clientList.insert(newClient->username,newClient);
   saveClientList();
   return 0;
}

