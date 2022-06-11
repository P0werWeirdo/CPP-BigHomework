#include "common.h"

Common::Common(){
    this->setType(3);
}

Common::Common(Client* sender,Client *recver,QString remark,double number) : Package(sender,recver,remark){
    this->setType(3);
    this->setNumber(number);
}

double Common::getPrice(){
    return this->getNumber() * 5;
}
