#include "user.h"
#include"package.h"
User::User(){

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
int User::getBalance()const{       //获取用户余额
    return this->balance;
}
QString User::getPassword()const{  //获取用户密码
    return this->password;
}
QMap<QString,Package *>   User::getMyPackage()const{  //获取用户包裹
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
    return true;
}
bool User::changeBalance(int num){                                    //修改余额
    if(num > 0){
        if(num + this->balance < 0){      //溢出
            return false;
        }
        else{
            this->balance += num;
        }
    }
    else{
        if(this->balance + num < 0){        //余额不足
            return false;
        }else{
            this->balance += num;
        }
    }
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
    return true;
}

//保存快递
bool User::saveToMyPackage(Package *pkg){
    if(pkg!=NULL){
        this->myPackage.insert(pkg->getIndex(),pkg);
        return true;
    }
    return false;
}

//删除快递
bool User::deleteFromMyPackage(Package *pkg){
    return this->myPackage.remove(pkg->getIndex()) == 1;
}
