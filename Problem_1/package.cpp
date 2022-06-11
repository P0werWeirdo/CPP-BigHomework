#include "package.h"
#include"client.h"
#include"administrator.h"
#include<QFile>
#include<QCoreApplication>
#include<QTextStream>
#include<QDebug>
#include<QDateTime>
QMap<QString,Package *> Package::packageList;         //静态成员变量类外初始化
long Package::totalPackage;
Package::Package()
{
    this->sender = NULL;        //空指针
    this->recver = NULL;        //空指针
    this->status = 0;           //包裹状态
}
Package::Package(Client* sender,Client *recver,QString remark){
    this->index = createTotalPackage();
    incTotalPackage();
    this->sender = sender;
    this->recver = recver;
    this->sendTime = QDateTime::currentDateTime();
    this->recvTime = QDateTime::fromSecsSinceEpoch(0);
    this->status = 1;
    this->remark = remark;
    //packageList.insert(this->index,this);
}

void Package::recvpkg(){
    this->status = 2;
    this->recvTime = QDateTime::currentDateTime();
}

bool Package::recvpkgList(QList<Package *> pkgList){
    int len = pkgList.length();
    bool isAllFinish = true;
    for(int i = 0;i < len;i++){
        if(pkgList[i] != NULL){
            pkgList[i]->recvpkg();
        }
        else{
            isAllFinish = false;
        }
    }
    savePackage();
    return isAllFinish;
}

QString Package::getIndex()const{         //获取快递单号
    return this->index;
}
Client* Package::getSender()const{        //获取发送方指针
    return this->sender;
}
Client* Package::getRecver()const{        //获取接收方指针
    return this->recver;
}
QDateTime Package::getSendTime()const{        //获取发送时间
    return this->sendTime;
}
QDateTime Package::getRecvTime()const{        //获取接受时间
    return this->recvTime;
}

QString Package::getRemark()const{        //获取快递备注
    return this->remark;
}

QString Package::getAddr()const{         //获取地址
    if(this->recver == NULL){
        return "";
    }
    return this->recver->getAddress();
}

char Package::getStatus()const{           //获取快递状态
    return this->status;
}

void Package::initPackage(){
    QFile file(QCoreApplication::applicationDirPath() + "/data/package.txt");          //读入文件
    file.open(QIODevice::ReadOnly| QIODevice::Text);
    //查看文件是否打开，打不开直接退出
    if(file.isOpen()){
        QString data;
        QStringList packageData;
        if(file.size() != 0){
            QTextStream in(&file);
            data = in.readLine();
            totalPackage = data.toLong();                                               //先读入totalPackage 方便生成快递号
            while(!in.atEnd()){
                data = in.readLine();
                packageData = data.split(' ');
                Package *pkg = new Package;

                pkg->index = packageData[0];
                //读取sender
                pkg->sender = packageData[1] != "0" ?  Client::clientList[packageData[1]]  : NULL;
                //读取recver
//                if(pkg->sender == NULL){
//                    qDebug() << "空的";
//                }
                pkg->recver = packageData[2] != "0" ?  Client::clientList[packageData[2]]  : NULL;
//                if(pkg->recver == NULL){
//              //      qDebug() << "空的！";
//                }
                //读取时间
                pkg->sendTime = QDateTime::fromSecsSinceEpoch(packageData[3].toLongLong());
                pkg->recvTime = QDateTime::fromSecsSinceEpoch(packageData[4].toLongLong());
                //读取备注
                pkg->remark = packageData[5];
                //读取状态
                pkg->status = packageData[6].toShort();
                packageList.insert(pkg->index,pkg);

                //保存到sender 和 recver的表中
                if(pkg->sender){
                    pkg->sender->saveToMyPackage(pkg);
                }
                if(pkg->recver){
                    pkg->recver->saveToMyPackage(pkg);
                }
            }
        }
    }
    else{
        qDebug()<<"package.txt读入失败";
        exit(-1);
    }
    file.close();
}

bool Package::savePackage(){
    QFile file(QCoreApplication::applicationDirPath() + "/data/package.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(file.isOpen()){
        QTextStream in(&file);
        in << totalPackage << endl;
        for(auto iter = packageList.begin();iter != packageList.end(); iter++){
            //写入快递号
            in << iter.value()->index << ' ';
            //写入发送者和接受者
            QString tmp1 = iter.value()->sender != NULL ? iter.value()->sender->getUsername() : "0";
            in << tmp1 << ' ';
            tmp1 = iter.value()->recver != NULL ? iter.value()->recver->getUsername() : "0";
            in << tmp1 << ' ';
            //写入发送时间和接受时间
            in << iter.value()->getSendTime().toSecsSinceEpoch() << ' ';
            in << iter.value()->getRecvTime().toSecsSinceEpoch() << ' ';
            //写入备注
            in << iter.value()->getRemark() << ' ';
            //写入状态
            in << (short)(iter.value()->getStatus()) << endl;
        }
    }
    else{
        return false;
    }
    file.close();
    return true;
}

/*查询方式集合.方便以后使用*/
Package* Package::searchByIndex(QMap<QString,Package *> &myPackage,QString Index)const{
    if(myPackage.contains(Index)){
        return myPackage[Index];
    }
    return NULL;
}

/*按天查询*/
QList<Package*> Package::searchBySendTime(QMap<QString,Package *> &myPackage,QDateTime time)const{
    QList<Package*> tmp;
//    QDateTime upTime = time.addDays(1);
    for(auto iter = myPackage.begin(); iter != myPackage.end(); iter++){
        if(iter.value()->getSendTime().date() == time.date()){
            tmp.push_back(iter.value());
        }
    }
    return tmp;
}

QList<Package*> Package::searchByRecvTime(QMap<QString,Package *> &myPackage,QDateTime time)const{
    QList<Package*> tmp;
//    QDateTime upTime = time.addDays(1);
    for(auto iter = myPackage.begin(); iter != myPackage.end(); iter++){
        if(iter.value()->getRecvTime().date() == time.date()){
            tmp.push_back(iter.value());
        }
    }
    return tmp;
}

QList<Package*> Package::searchByUsername(QMap<QString,Package *> &myPackage,QString username)const{
    QList<Package*> tmp;
//    QDateTime upTime = time.addDays(1);
    for(auto iter = myPackage.begin(); iter != myPackage.end(); iter++){
        if(iter.value()->sender->getName() == username ||
            iter.value()->recver->getName() == username){
            tmp.push_back(iter.value());
        }
    }
    return tmp;
}

QString Package::getStatusString()const{
    if(this->status == 1){
        return "待签收";
    }
    return "已签收";
}

/*生成快递单号字符串*/
QString Package::createTotalPackage(){
    QString tmp = QString::number(totalPackage);
    QString res;
    int len = tmp.length();
    for(int i = 0;i + len <  8; i++){
        res.push_back('0');
    }
    res.push_back(tmp);
    return res;
}

/*总快递单号+1*/
void Package::incTotalPackage(){
    totalPackage++;
}

QMap<QString,Package *>& Package::getPackageList(){
    return packageList;
}
