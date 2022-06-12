#include "packageinfowindow.h"
#include "ui_packageinfowindow.h"
#include<QDateTime>

PackageInfoWindow::PackageInfoWindow(QJsonObject pkg,QWidget *parent) :
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
    ui->Index_Line->setText(pkg["index"].toString());
    //渲染发送者部分
    ui->SenderUsername_Line->setText(pkg["senderUsername"].toString());
    ui->SenderName_Line->setText(pkg["senderName"].toString());
    qint64 time = getLongData(pkg,"senderTime");
    ui->SenderTime->setText(QDateTime::fromSecsSinceEpoch(time).toString("yyyy-M-d,hh:mm:ss"));

    //渲染快递员部分
    if(pkg["collectorUsername"].toString() == ""){
        ui->CollectorUsername_Line->setText("-");
        ui->CollectorName_Line->setText("-");
    }
    else{
        ui->CollectorUsername_Line->setText(pkg["collectorUsername"].toString());
        ui->CollectorName_Line->setText(pkg["collectorName"].toString());
    }

    time = getLongData(pkg,"collectorTime");
    if(time <= 1){
        ui->CollectTime_Line->setText("-");
    }
    else{
        ui->CollectTime_Line->setText(QDateTime::fromSecsSinceEpoch(time).toString("yyyy-M-d,hh:mm:ss"));
    }


    //渲染接收者部分
    ui->RecvUsername_Line->setText(pkg["recverUsername"].toString());
    ui->RecvName_Line->setText(pkg["recverName"].toString());

    time = getLongData(pkg,"recverTime");
    if(time <= 1){
        ui->RecvTime->setText("-");
    }
    else{
        ui->RecvTime->setText(QDateTime::fromSecsSinceEpoch(time).toString("yyyy-M-d,hh:mm:ss"));
    }

    //渲染物品描述部分
    ui->Addr_Line->setText(pkg["address"].toString());
    ui->PkgRemark->setText(pkg["remark"].toString());
    ui->PkgPrice->setText(QString::number(pkg["price"].toDouble()));

    int status = pkg["status"].toInt();
    QString st;

    if(status == 1){
        st = "待签收";
    }
    else if(status == 3){
        st = "待揽收";
    }
    else{
        st = "已签收";
    }

    ui->PkgStatus_Line->setText(st);
}

qint64 PackageInfoWindow::getLongData(QJsonObject json, QString key)
{
    return QString::number(json.value(key).toDouble(), 'f', 0).toLongLong();
}

PackageInfoWindow::~PackageInfoWindow()
{
    delete ui;
}
