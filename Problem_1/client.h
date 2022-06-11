#ifndef CLIENT_H
#define CLIENT_H
#include"package.h"
#include"user.h"
#include<QString>
class Package;
class Client: public User
{
public:
    Client();           //构造函数
    Client(QString username,QString password,QString name,QString phoneNum,QString address);

    QString getAddress()const;      //返回地址
    bool changeAddress(QString newAddr);           //改变地址
    static void initClientList();
    static bool saveClientList();
    /*对快递进行相关操作*/
    bool sendPackage(Client *recver,QString remarks,double price);    //发送快递
//    void recvPackage(Package *pkg);                     //收到快递



    static QMap<QString,Client *> clientList;      //总客户表
    static int registerNewClient(QString username,QString password,QString name,QString phoneNum,QString address);
private:
    QString address;    //地址
};


#endif // CLIENT_H
