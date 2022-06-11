#ifndef PACKAGE_H
#define PACKAGE_H
#include<QString>
#include<QDateTime>
#include"client.h"
#include"courier.h"

class Courier;
class Client;
class Package
{
public:
    Package();
    Package(Client* sender,Client *recver,QString remark);
    virtual ~Package();
    /*获取快递信息的有关操作*/
    QString getIndex()const;         //获取快递单号
    Client* getSender()const;        //获取发送方指针
    Courier* getCollector()const;    //获取揽收者指针
    Client* getRecver()const;        //获取接收方指针

    QDateTime getSendTime()const;        //获取发送时间
    QDateTime getCollectTime()const;     //获取揽收时间
    QDateTime getRecvTime()const;        //获取接受时间

    QString getRemark()const;        //获取快递备注
    QString getAddr()const;          //获取快递地址
    char getStatus()const;           //获取快递状态
    QString getStatusString()const;  //获取快递状态字符串

    double getNumber()const;        //获取快递数量
    char getType()const;          //获取快递类型
    void resetCollector();          //重置快递员 删除用
    void setCollector(Courier *);    //设置快递员

    /*一些查询方式*/
    Package* searchByIndex(QMap<QString,Package *> &myPackage,QString Index)const;
    QList<Package*> searchBySendTime(QMap<QString,Package *> &myPackage,QDateTime time)const;
    QList<Package*> searchByRecvTime(QMap<QString,Package *> &myPackage,QDateTime time)const;
    QList<Package*> searchByUsername(QMap<QString,Package *> &myPackage,QString username)const;

    /*改变快递状态的有关操作*/
   // void sendpkg(Package *pkg);              //发送某一快递
    void collectpkg(Courier *);                          //揽收某一快递
    void recvpkg();                             //签收某一快递
    /*改变快递状态*/
    void setType(char type);                    //设置为某一类型
    void setNumber(double number);              //设置快递数量

    /*获取快递金额的操作*/
    virtual double getPrice() = 0;

    /*信息永久保存的有关操作*/
    static void initPackage();  //初始化包裹信息
    static bool savePackage();  //保存包裹信息
    static QString createTotalPackage();
    static void incTotalPackage();
    static QMap<QString,Package *>& getPackageList();
    static QMap<QString,Package *> packageList;     //快递表
    static bool collectpkgList(QList<Package *>pkgList,Courier *theCourier);            //批量揽收
    static bool recvpkgList(QList<Package *>pkgList);              //批量签收

private:
    QString index;              //此快递单号
    Client *sender;             //发送方
    Courier *collector;         //揽收员
    Client *recver;             //接收方
    QDateTime sendTime;             //发送时间
    QDateTime collectTime;          //揽收时间
    QDateTime recvTime;             //接受时间
    QString remark;             //备注
    char status;                //状态    1 代表 待签收  2 代表 已签收 3 代表待揽收
    double number;              //数量
    static long totalPackage;   //分配单号
    char type;                  //类型
};

#endif // PACKAGE_H
