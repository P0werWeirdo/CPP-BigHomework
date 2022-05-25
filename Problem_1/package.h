#ifndef PACKAGE_H
#define PACKAGE_H
#include<QString>
#include<QDateTime>
#include"client.h"

class Client;
class Package
{
public:
    Package();
    /*获取快递信息的有关操作*/
    QString getIndex()const;         //获取快递单号
    Client* getSender()const;        //获取发送方指针
    Client* getRecver()const;        //获取接收方指针
    QDateTime getSendTime()const;        //获取发送时间
    QDateTime getRecvTime()const;        //获取接受时间
    QString getRemark()const;        //获取快递备注
    QString getAddr()const;          //获取快递地址
    char getStatus()const;           //获取快递状态
    QString getStatusString()const;  //获取快递状态字符串

    /*一些查询方式*/
    Package* searchByIndex(QMap<QString,Package *> &myPackage,QString Index);
    QList<Package*> searchBySendTime(QMap<QString,Package *> &myPackage,QDateTime time);
    QList<Package*> searchByRecvTime(QMap<QString,Package *> &myPackage,QDateTime time);
    QList<Package*> searchByUsername(QMap<QString,Package *> &myPackage,QString username);

    /*改变快递状态的有关操作*/
    void sendpkg(Package *pkg);              //发送某一快递
    void recvpkg(Package *pkg);              //签收某一快递

    /*信息永久保存的有关操作*/
    static void initPackage();  //初始化包裹信息
    static bool savePackage();  //保存包裹信息
    static QMap<QString,Package *>& getPackageList();
    static QMap<QString,Package *> packageList;     //快递表

private:
    QString index;              //此快递单号
    Client *sender;             //发送方
    Client *recver;             //接收方
    QDateTime sendTime;             //发送时间
    QDateTime recvTime;             //接受时间
    QString remark;             //备注
    char status;                //状态    1 代表 待签收 2 代表 已签收

    static long totalPackage;   //分配单号
};

#endif // PACKAGE_H
