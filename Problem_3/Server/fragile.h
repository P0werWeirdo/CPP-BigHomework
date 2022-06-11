#ifndef FRAGILE_H
#define FRAGILE_H
#include"package.h"

class Fragile : public Package
{
public:
    Fragile();
    Fragile(Client* sender,Client *recver,QString remark,double number);

    /*重写获取快递金额的函数*/
    double getPrice();
};

#endif // FRAGILE_H
