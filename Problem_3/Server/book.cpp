#include "book.h"


Book::Book(){
    this->setType(2);
}

Book::Book(Client* sender,Client *recver,QString remark,double number): Package(sender,recver,remark){
    this->setType(2);
    this->setNumber(number);
}

double Book::getPrice(){
    return this->getNumber() * 2;
}
