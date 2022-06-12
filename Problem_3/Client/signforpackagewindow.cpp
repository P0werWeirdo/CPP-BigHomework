#include "signforpackagewindow.h"
#include "ui_signforpackagewindow.h"
#include<QMessageBox>
#include<QCheckBox>
#include"packageinfowindow.h"
#include"userinfowindow.h"
#include"distributewindow.h"
#include"loginwindow.h"

SignForPackageWindow::SignForPackageWindow(QJsonObject theUser,int type,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignForPackageWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("签收快递");
    this->setWindowModality(Qt::WindowModal);

    /*初始化类内对象*/
    this->theUser = theUser;
    this->type = type;
    /*初始化表格*/
    initTable();

    /*初始化逻辑*/
    initLogic();

    /*向服务器发送初始化请求*/
    sendInitReq();

}

void SignForPackageWindow::sendInitReq()const{
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",8);
    QJsonObject info;
    info.insert("username",theUser["username"].toString());
    info.insert("type",this->type);

    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    LoginWindow::con->write(abyte);
    /*绑定逻辑*/
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&SignForPackageWindow::initRes);
}


void SignForPackageWindow::initRes(){                 //获取包裹信息后处理
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&SignForPackageWindow::initRes);

    //读入并构造Json对象
    QByteArray tmp = LoginWindow::con->readAll();
    qDebug() << tmp;
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();


    if(obj["status"].toInt() != 200){
        QMessageBox::critical(this,"错误","服务器忙");
    }
    else{
        //传入Json对象
        QJsonArray pkg = obj["message"].toArray();
        this->packageList.clear();
        //依次读入快递信息
        for(auto item = pkg.constBegin();item != pkg.constEnd();item++){
            this->packageList.insert((*item).toObject()["index"].toString(),
                    (*item).toObject());
        }
        showAllPkg();
        return;
    }
}

void SignForPackageWindow::initTable(){
    /*初始化表格*/
    if(type == 1){
        ui->PkgListTb->setColumnCount(4);
        ui->PkgListTb->setHorizontalHeaderLabels(QStringList()<<"快递单号"<<"发送方账号"<<"发送方姓名"<<"价格");
    }
    else if(type == 2){
        ui->PkgListTb->setColumnCount(4);
        ui->PkgListTb->setHorizontalHeaderLabels(QStringList()<<"快递单号"<<"发送方账号"<<"发送方姓名"<<"是否签收");
    }
    else{
        ui->PkgListTb->setColumnCount(5);
        ui->PkgListTb->setHorizontalHeaderLabels(QStringList()<<"快递单号"<<"发送方账号"<<"发送方姓名"<<"价格"<<"是否揽收");
    }
    ui->PkgListTb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->PkgListTb->setCornerButtonEnabled(false);
}


void SignForPackageWindow::sendSignReq()const{//签收请求
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",9);
    QJsonObject info;
    info.insert("username",theUser["username"].toString());
    info.insert("type",this->type);


    QJsonArray message;
    int totalRow = ui->PkgListTb->rowCount();
    for(int i = 0;i < totalRow;i++){
        //被选中的入列
        if(ui->PkgListTb->item(i,3)->checkState() == Qt::Checked){
            if(packageList.contains(ui->PkgListTb->item(i,0)->text())){
                message.push_back(ui->PkgListTb->item(i,0)->text());
              }
        }
    }
    info.insert("message",message);


    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    LoginWindow::con->write(abyte);
    /*绑定逻辑*/
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&SignForPackageWindow::signRes);
}

void SignForPackageWindow::sendCollectReq()const{//揽收请求
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",9);
    QJsonObject info;
    info.insert("username",theUser["username"].toString());
    info.insert("type",this->type);


    QJsonArray message;
    int totalRow = ui->PkgListTb->rowCount();
    for(int i = 0;i < totalRow;i++){
        //被选中的入列
        if(ui->PkgListTb->item(i,4)->checkState() == Qt::Checked){
            if(packageList.contains(ui->PkgListTb->item(i,0)->text())){
                message.push_back(ui->PkgListTb->item(i,0)->text());
              }
        }
    }
    info.insert("message",message);


    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    LoginWindow::con->write(abyte);
    /*绑定逻辑*/
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&SignForPackageWindow::collectRes);

}

void SignForPackageWindow::signRes(){              //签收回应
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&SignForPackageWindow::signRes);

    //读入并构造Json对象
    QByteArray tmp = LoginWindow::con->readAll();
    qDebug() << tmp;
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();


    if(obj["status"].toInt() != 200){
        QMessageBox::critical(this,"错误","服务器忙");
    }
    else{
        //传入Json对象
        bool result = obj["message"].toArray()[0].toObject()["result"].toBool();
        if(result){
            QMessageBox::about(this,"签收成功","您已经签收了所选的包裹");
            this->close();
        }
        else{
            QMessageBox::critical(this,"签收失败","部分包裹未能签收");
            sendInitReq();
        }
        return;
    }

}

void SignForPackageWindow::collectRes(){              //揽收回应
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&SignForPackageWindow::collectRes);
    //读入并构造Json对象
    QByteArray tmp = LoginWindow::con->readAll();
//    qDebug() << tmp;
    QJsonDocument doc = QJsonDocument::fromJson(tmp);
    QJsonObject obj = doc.object();


    if(obj["status"].toInt() != 200){
        QMessageBox::critical(this,"错误","服务器忙");
    }
    else{
        //传入Json对象
        bool result = obj["message"].toArray()[0].toObject()["result"].toBool();
        if(result){
            QMessageBox::about(this,"揽收成功","您已经揽收了所选的包裹");
            emit collectFinish();
            this->close();
        }
        else{
            QMessageBox::critical(this,"揽收失败","部分包裹未能揽收");
            sendInitReq();
        }
        return;
    }
}



void SignForPackageWindow::initLogic(){
    /*初始化逻辑*/
    if(type == 1){    //管理员
        ui->btn_Sign->setText("分配包裹");
        connect(ui->btn_Sign,&QPushButton::clicked,this,&SignForPackageWindow::distributePkg);
    }
    else if(type == 2){   //客户
        connect(ui->btn_Sign,&QPushButton::clicked,this,&SignForPackageWindow::sendSignReq);
    }
    else{       //快递员
        ui->btn_Sign->setText("揽收全部");
        connect(ui->btn_Sign,&QPushButton::clicked,this,&SignForPackageWindow::sendCollectReq);
    }
    connect(ui->PkgListTb,&QTableWidget::itemDoubleClicked,this,&SignForPackageWindow::showDetailInfo);
}

//分配包裹
void SignForPackageWindow::distributePkg(){
    int row = ui->PkgListTb->currentRow();
    if(row < 0 || row >= ui->PkgListTb->rowCount()){
        QMessageBox::critical(this,"错误","请先选择一个包裹");
        return;
    }
    if(!this->packageList.contains(ui->PkgListTb->item(row,0)->text())){
        QMessageBox::critical(this,"错误","包裹不存在");
        return;
    }

    QJsonObject pkg = this->packageList[ui->PkgListTb->item(row,0)->text()];

    //展示分配窗口
    DistributeWindow *newWindow = new DistributeWindow(pkg,this);
    connect(newWindow,&DistributeWindow::distributeFinish,[=](){
        sendInitReq();
    });
    newWindow->show();
}

void SignForPackageWindow::showDetailInfo(QTableWidgetItem *item){
    /*展示详细信息*/
    if(item->column() == 0){
        PackageInfoWindow *pkgInfo = new PackageInfoWindow(
                    packageList[item->text()],this);
        pkgInfo->show();

    }
//    else if(item->column() == 1){
//        UserInfoWindow *userInfo = new UserInfoWindow(
//                    Client::clientList[item->text()],1,this);
//        userInfo->show();
//    }
}





//揽收包裹
//bool SignForPackageWindow::collectAllPkg()const{
//    QList<Package *> tmp;
//    Courier *theCourier = (Courier *)this->theUser;
//    int totalRow = ui->PkgListTb->rowCount();
//    for(int i = 0;i < totalRow;i++){
//        //被选中的入列
//        if(ui->PkgListTb->item(i,4)->checkState() == Qt::Checked){
//            if(theCourier->getMyPackage().contains(ui->PkgListTb->item(i,0)->text())){
//                tmp.push_back(theCourier->getMyPackage()[ui->PkgListTb->item(i,0)->text()]);
//              }
//        }
//    }

//    return theCourier->collectPackage(tmp);
//}

//展示包裹
void SignForPackageWindow::showAllPkg(){

    QMap<QString,QJsonObject >* map = &packageList;
    if(type == 1){            //管理员
        /*计算总共行数*/
        int totalRow = 0;
        for(auto i = map->cbegin(); i != map->cend(); i++){
                if(i.value()["status"].toInt() == 3 && i.value()["collectorUsername"].toString().length() == 0){
                    totalRow ++;
                }
        }
        ui->PkgListTb->setRowCount(totalRow);
        //是否有分配权限
        if(totalRow == 0){
            ui->btn_Sign->hide();
        }
        else{
            ui->btn_Sign->show();
        }
        //渲染
        int row = 0,col = 0;
        for(auto i = map->cbegin(); i != map->cend(); i++){
            col = 0;
            if(i.value()["status"].toInt() == 3 && i.value()["collectorUsername"].toString().length() == 0){
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()["index"].toString()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()["senderUsername"].toString()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()["senderName"].toString()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(QString::number(i.value()["price"].toDouble())));
                row++;
            }
        }
    }
    else if(type == 2){
        /*计算总共行数*/
        int totalRow = 0;
        for(auto i = map->cbegin(); i != map->cend(); i++){
                if(i.value()["status"].toInt() == 1 &&
                        i.value()["recverUsername"].toString() == theUser["username"].toString()){
                    totalRow ++;
                }
        }
        ui->PkgListTb->setRowCount(totalRow);
        //是否有签收权限
        if(totalRow == 0){
            ui->btn_Sign->hide();
        }
        else{
            ui->btn_Sign->show();
        }

        int row = 0,col = 0;
        for(auto i = map->cbegin(); i != map->cend(); i++){
            col = 0;
            if(i.value()["status"].toInt() == 1 &&
                    i.value()["recverUsername"].toString() == theUser["username"].toString()){
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()["index"].toString()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()["senderUsername"].toString()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()["senderName"].toString()));
                QTableWidgetItem *checkbox = new QTableWidgetItem;
                checkbox->setCheckState(Qt::Unchecked);
                ui->PkgListTb->setItem(row,col++,checkbox);
                row++;
            }
        }
    }
    else{
        /*计算总共行数*/
        int totalRow = 0;
        for(auto i = map->cbegin(); i != map->cend(); i++){
                if(i.value()["status"].toInt() == 3){
                    totalRow ++;
                }
        }
        ui->PkgListTb->setRowCount(totalRow);
        //是否有签收权限
        if(totalRow == 0){
            ui->btn_Sign->hide();
        }
        else{
            ui->btn_Sign->show();
        }

        int row = 0,col = 0;
        for(auto i = map->cbegin(); i != map->cend(); i++){
            col = 0;
            if(i.value()["status"].toInt() == 3){
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()["index"].toString()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()["senderUsername"].toString()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(i.value()["senderName"].toString()));
                ui->PkgListTb->setItem(row,col++,new QTableWidgetItem(QString::number(i.value()["price"].toDouble())));
                QTableWidgetItem *checkbox = new QTableWidgetItem;
                checkbox->setCheckState(Qt::Unchecked);
                ui->PkgListTb->setItem(row,col++,checkbox);
                row++;
            }
        }
    }

}

SignForPackageWindow::~SignForPackageWindow()
{
    delete ui;
}
