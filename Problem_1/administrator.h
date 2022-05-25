#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include"user.h"

class Administrator: public User
{
public:
    Administrator();            //构造函数
    static void initAdmin();    //初始化管理员
    bool checkAdmin(QString username,QString password);     //管理员登录
    static bool saveAdmin();
    static Administrator admin;    //唯一管理员
};

#endif // ADMINISTRATOR_H
