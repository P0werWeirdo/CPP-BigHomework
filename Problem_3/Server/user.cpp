#include "user.h"
#include"package.h"
#include"administrator.h"
User::User(){

}

User::~User(){

}

QString User::getUsername()const{//获取用户账号
    return this->username;
}

QString User::getName()const{      //获取用户名字
    return this->name;
}

QString User::getPhoneNum()const{  //获取用户电话
    return this->phoneNum;
}
double User::getBalance()const{       //获取用户余额
    return this->balance;
}
QString User::getPassword()const{  //获取用户密码
    return this->password;
}
QMap<QString,Package *>&   User::getMyPackage(){  //获取用户包裹
    return this->myPackage;
}
/*修改相关函数，成功返回true，失败返回false*/
bool User::changePassword(QString oldPassword,QString newPassword)   //修改密码
{
    if(this->password != oldPassword) {        //判断是否与旧密码相等
        return false;
    }
    if(newPassword.length() < 6 || newPassword.length() > 20){
        return false;
    }
    this->password = newPassword;
    Client::saveClientList();
    Courier::saveCourierList();
    Administrator::saveAdmin();
    return true;
}
bool User::changeBalance(double num){                                    //修改余额
    if(num > 0){
            this->balance += num;
    }
    else{
        if(this->balance + num < 0){        //余额不足
            return false;
        }else{
            this->balance += num;
        }
    }    
    Client::saveClientList();
    Administrator::saveAdmin();
    return true;
}

bool User::changePhoneNum(QString phoneNum){                          //修改电话
    int len = phoneNum.length();

    if(len != 11){
        return false;
    }

    for(int i = 0;i < len;i++){         //检验是否是数字
        if(phoneNum[i] < '0' || phoneNum[i] > '9'){
            return false;
        }
    }
    this->phoneNum = phoneNum;
    Client::saveClientList();
    Administrator::saveAdmin();
    return true;
}

//保存快递
bool User::saveToMyPackage(Package *pkg){
    if(pkg!=NULL){
        this->myPackage.insert(pkg->getIndex(),pkg);
        return true;
    }
    Package::savePackage();
    return false;
}

//删除快递
bool User::deleteFromMyPackage(Package *pkg){
    Package::savePackage();
    return this->myPackage.remove(pkg->getIndex()) == 1;
}
