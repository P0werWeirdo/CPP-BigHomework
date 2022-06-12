#include "administrator.h"
#include<QFile>
#include<QCoreApplication>
#include<QTextStream>
#include<QDebug>
#include"courier.h"
Administrator Administrator::admin;     //在类外初始化
Administrator::Administrator()
{

}

void Administrator::initAdmin(){
    QFile file(QCoreApplication::applicationDirPath() + "/data/admin.txt");          //读入文件
    file.open(QIODevice::ReadOnly| QIODevice::Text);
    //查看文件是否打开，打不开直接退出
    if(file.isOpen()){
        QString data;
        QStringList adminData;
        if(file.size() != 0){
            QTextStream in(&file);
            while(!in.atEnd()){
                data = in.readLine();
                adminData = data.split(' ');                                         //根据' '进行分割
                admin.username = adminData[0];
                admin.password = adminData[1];
                admin.name = adminData[2];
                admin.phoneNum = adminData[3];
                Administrator::admin.balance = adminData[4].toInt();
            }
        }
    }
    else{
        qDebug()<<"admin.txt读入失败";
        exit(-1);
    }
    file.close();
}

bool Administrator::saveAdmin(){
    QFile file(QCoreApplication::applicationDirPath() + "/data/admin.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(file.isOpen()){
        QTextStream in(&file);
        in<<admin.username<<' '<<admin.password<<' '<<admin.name<<' '
          <<admin.phoneNum<<' '<<admin.balance<<endl;
    }
    else{
        return false;
    }
    file.close();
    return true;
}

bool Administrator::distribute(QString courier,QString pkg)const{
    if(Courier::courierList.contains(courier) && Package::packageList.contains(pkg)){
        Courier *thecourier = Courier::courierList[courier];
        QString tmp = pkg;
        Package *pkg = Package::packageList[tmp];
        pkg->setCollector(thecourier);
        thecourier->saveToMyPackage(pkg);
        Package::savePackage();
        return true;
    }
    return false;
}

int Administrator::getType(){
    return 1;
}

bool Administrator::checkAdmin(QString username,QString password)const{
    return (admin.username == username) && (admin.password == password);
}
