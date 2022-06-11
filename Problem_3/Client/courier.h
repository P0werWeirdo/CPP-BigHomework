#ifndef COURIER_H
#define COURIER_H
#include "user.h"
#include"package.h"
class Courier : public User
{
public:
    Courier();
    Courier(QString username,QString password,QString name,QString phoneNum);
    int getType();
    bool collectPackage(QList<Package *> pkgList);//批量签收

    static void initCourierList();
    static bool saveCourierList();
    static bool deleteCourier(QString username);    //删除某一个快递员
    //总表
    static QMap<QString,Courier *> courierList;      //总快递员表
    //注册
    static int registerNewCourier(QString username,QString password,QString name,QString phoneNum);

};

#endif // COURIER_H
