#include "courier.h"
#include<QCoreApplication>
#include<QTextStream>
#include<QDebug>
#include"administrator.h"

QMap<QString,Courier *> Courier::courierList;      //总快递员表
Courier::Courier()
{
    this->balance = 0;
}

Courier::Courier(QString username,QString password,QString name,QString phoneNum){
    this->username = username;
    this->password = password;
    this->name = name;
    this->phoneNum = phoneNum;
    this->balance = 0;
}

int Courier::getType(){
    return 3;
}

//注册新快递员 返回1: 快递员名过长或过短 返回2：用户名重复 返回3:密码过长或过短 返回4:手机号不符合格式 返回5:姓名检测
//返回0:注册成功
int Courier::registerNewCourier(QString username,QString password,QString name,QString phoneNum){
    //用户名检测
    if(username.length() < 4 || username.length() > 20){
        return 1;
    }
    if(courierList.contains(username)){
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
   //手机号检测
   qDebug()<<phoneNum.length();
   if(phoneNum.length() != 11){
        for(int i = 0;i < 11;i++){
            if(phoneNum[i] < '0' || phoneNum[i] > '9'){
                return 4;
            }
        }
   }

   Courier *newCourier = new Courier(username,password,name,phoneNum);
   courierList.insert(newCourier->username,newCourier);
   saveCourierList();
   return 0;
}

void Courier::initCourierList(){
    QFile file(QCoreApplication::applicationDirPath() + "/data/courier.txt");          //读入文件
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
               Courier* tmp = new Courier;
               //读用户名
               tmp->username = clientData[0];
               tmp->password = clientData[1];
               //读入姓名
               tmp->name = clientData[2];
               //读电话 余额 地址
               tmp->phoneNum = clientData[3];
               tmp->balance = clientData[4].toDouble();
               courierList.insert(tmp->getUsername(),tmp);                                          //添加到总客户表
            }
        }
    }
    else{
        qDebug()<<"courier.txt读入失败";
        exit(-1);
    }
    file.close();
}

bool Courier::deleteCourier(QString username){    //删除某一个快递员
    if(!courierList.contains(username)){    //如果没有这个快递员，则删除失败
        return false;
    }
    Courier *tmp = courierList[username];   //有这个快递员

    for(auto item = tmp->myPackage.cbegin();item != tmp->myPackage.cend(); item++){
        (*item)->resetCollector();              //将快递员清空，防止段错误
    }
    courierList.remove(username);
    delete tmp;
    saveCourierList();
    Package::savePackage();
    return true;
}

bool Courier::collectPackage(QList<Package *> pkgList){
    qDebug()<<"已经在揽收了";
    qDebug() << pkgList.length();
    return Package::collectpkgList(pkgList,this);
}

bool Courier::saveCourierList(){
    QFile file(QCoreApplication::applicationDirPath() + "/data/courier.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(file.isOpen()){
        QTextStream in(&file);
        for(auto i = courierList.begin();i != courierList.end() ;i++){
            //按顺序写入
            in<<i.value()->username<<' '<<i.value()->password<<' '<<i.value()->name<<' '
              <<i.value()->phoneNum<<' '<<i.value()->balance<<endl;
        }

    }
    else{
        qDebug()<<"courier.txt写入失败";
        return false;
    }
    file.close();
    return true;
}
