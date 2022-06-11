#ifndef BOOK_H
#define BOOK_H
#include"package.h"


class Book : public Package
{
public:
    Book();
    Book(Client* sender,Client *recver,QString remark,double number) ;

    double getPrice();
};

#endif // BOOK_H
