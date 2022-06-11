#ifndef USER_H
#define USER_H
#include<QString>
#include<QMap>
#include<QList>
//#include"package.h"           //循环include问题
using namespace std;
class Package;
class User
{
public:
    User();       //构造函数
    virtual ~User();

    QString getUsername()const;  //获取用户账号
    QString getName()const;      //获取用户名字
    QString getPhoneNum()const;  //获取用户电话
    QString getPassword()const;  //获取用户密码
    double getBalance()const;       //获取用户余额
    QMap<QString,Package *>&   getMyPackage();   //获取用户快递信息


    /*修改相关函数，成功返回true，失败返回false*/
    bool changePassword(QString oldPassword,QString newPassword);   //修改密码
    bool changeBalance(double num);                                    //修改余额
    bool changePhoneNum(QString phoneNum);                       //修改电话

    bool saveToMyPackage(Package *pkg);                         //将某一快递保存到User里
    bool deleteFromMyPackage(Package *pkg);                     //将某一快递从我表里删除
    virtual int getType() = 0;

protected:
    QString username;       //账号
    QString password;       //密码
    QString name;           //姓名
    QString phoneNum;       //电话
    double balance;            //余额
    QMap<QString,Package *>   myPackage;    //我的快递

};

#endif // USER_H
