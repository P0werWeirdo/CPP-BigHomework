#include "packagelistwindow.h"
#include "ui_packagelistwindow.h"
#include"package.h"
#include"user.h"
#include<QMap>
#include<QTableWidget>
#include<QDebug>
//status 0代表管理员 1代表用户
PackageListWindow::PackageListWindow(QWidget *parent,User* tu,char status) :
    QDialog(parent),
    ui(new Ui::PackageListWindow)
{
    ui->setupUi(this);
    /*初始化页面成员*/
    this->theUser = tu;
    this->status = status;
    /*设置页面信息*/
    this->setWindowModality(Qt::WindowModal);
    this->setWindowTitle("快递信息");
    /*初始化表格*/
    ui->PkgListTb->setColumnCount(4);
    ui->PkgListTb->setHorizontalHeaderLabels(QStringList()<<"快递单号"<<"发送方账号"<<"接收方账号"<<"状态");
    ui->PkgListTb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->PkgListTb->setCornerButtonEnabled(false);
    /*初始化快递表*/
    showMyPkg();
}

void PackageListWindow::showList(QList<Package*> pkg){
    /*无项目直接return*/
    int len = pkg.length();
    if(len == 0){
        return;
    }
    ui->PkgListTb->setRowCount(len);
    int col;
    /*填充table*/
    for(int i = 0;i < len; i++){
        col = 0;
        qDebug()<< pkg[i]->getIndex();
        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(pkg[i]->getIndex()));
        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(pkg[i]->getSender()->getUsername()));
        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(pkg[i]->getRecver()->getUsername()));
        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(pkg[i]->getStatusString()));
    }
}
void PackageListWindow::showMyPkg(){
    QList<Package *> tmp;
    //转化为QList
    if(status == 1){
//        for(auto iter = theUser->getMyPackage().begin();iter != theUser->getMyPackage().end(); iter++){
//            tmp.push_back(iter.value());
//        }
        QMap<QString,Package *>::const_iterator i = theUser->getMyPackage().constBegin();
        while(i != theUser->getMyPackage().constEnd()){
            tmp.push_back(i.value());
            i++;
        }
    }
    else{
//        qDebug() << Package::getPackageList().size();

//        for(auto iter = Package::getPackageList().begin(); iter != Package::getPackageList().end(); iter++){
//            tmp.push_back(iter.value());
//        }
        for(auto iter = Package::packageList.constBegin(); iter != Package::packageList.constEnd();iter++){
            tmp.push_back(iter.value());
        }
    }
    showList(tmp);
    return;
}

PackageListWindow::~PackageListWindow()
{
    delete ui;
}
