#include "fragile.h"

Fragile::Fragile(){
    this->setType(1);
}

Fragile::Fragile(Client* sender,Client *recver,QString remark,double number) : Package(sender,recver,remark){
    //将type设为1
    this->setType(1);
    this->setNumber(number);
}

double Fragile::getPrice(){
    //
    return this->getNumber() * 8;
}
