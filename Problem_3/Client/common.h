#ifndef COMMON_H
#define COMMON_H
#include"package.h"

class Common : public Package
{
public:
    Common();
    Common(Client* sender,Client *recver,QString remark,double number);

    double getPrice();
};

#endif // COMMON_H
