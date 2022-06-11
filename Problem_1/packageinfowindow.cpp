#include "packageinfowindow.h"
#include "ui_packageinfowindow.h"

PackageInfoWindow::PackageInfoWindow(Package *pkg,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PackageInfoWindow)
{
    /*设置窗口状态*/
    ui->setupUi(this);
    this->setWindowTitle("快递信息窗口");
    this->setWindowModality(Qt::WindowModal);

    /*初始化按钮逻辑*/
    connect(ui->btn_Quit,&QPushButton::clicked,[=](){
        this->close();
        this->deleteLater();
    });

    /*初始化成员*/
    this->pkg = pkg;

    showInfo();
}

//展示信息
void PackageInfoWindow::showInfo(){
    ui->Index_Line->setText(pkg->getIndex());
    //渲染发送者部分
    ui->SenderUsername_Line->setText(pkg->getSender()->getUsername());
    ui->SenderName_Line->setText(pkg->getSender()->getName());
    ui->SenderTime->setText(pkg->getSendTime().toString("yyyy-M-d,hh:mm:ss"));

    //渲染接收者部分
    ui->RecvUsername_Line->setText(pkg->getRecver()->getUsername());
    ui->RecvName_Line->setText(pkg->getRecver()->getName());
    if(pkg->getRecvTime().toSecsSinceEpoch() <= 1){
        ui->RecvTime->setText("-");
    }
    else{
        ui->RecvTime->setText(pkg->getRecvTime().toString("yyyy-M-d,hh:mm:ss"));
    }

    //渲染物品描述部分
    ui->Addr_Line->setText(pkg->getRecver()->getAddress());
    ui->PkgRemark->setText(pkg->getRemark());
    ui->PkgStatus_Line->setText(pkg->getStatusString());
}

PackageInfoWindow::~PackageInfoWindow()
{
    delete ui;
}
