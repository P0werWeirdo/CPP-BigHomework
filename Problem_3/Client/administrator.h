#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include"user.h"

class Administrator: public User
{
public:
    Administrator();            //构造函数
    bool checkAdmin(QString username,QString password);     //管理员登录
    bool distribute(QString courier,QString pkg);
    int getType();              //管理员 1 客户 2 快递员 3
    //保存信息
    static void initAdmin();    //初始化管理员
    static bool saveAdmin();
    static Administrator admin;    //唯一管理员
};

#endif // ADMINISTRATOR_H
