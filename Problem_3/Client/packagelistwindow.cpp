#include "packagelistwindow.h"
#include "ui_packagelistwindow.h"
#include<QMap>
#include<QTableWidget>
#include<QDebug>
#include<packageinfowindow.h>
#include<userinfowindow.h>
#include"loginwindow.h"
#include<QMessageBox>

//status 0代表管理员 1代表用户
PackageListWindow::PackageListWindow(QJsonObject tu,char status,QWidget *parent) :
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
    ui->rb_UsernameSender->click();
    ui->date_Date->setDate(QDate::currentDate());
    ui->date_Date->hide();
    ui->box_Status->hide();
    /*设置搜索栏只能输入数字和字母*/
    QRegExp regx1("[a-zA-Z0-9]+$");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->line_Search);
    ui->line_Search->setValidator( validator1 );

    /*设置默认显示的快递表*/
    initReq();

    /*初始化表格*/
    ui->PkgListTb->setColumnCount(4);
    ui->PkgListTb->setHorizontalHeaderLabels(QStringList()<<"快递单号"<<"发送方账号"<<"接收方账号"<<"状态");
    ui->PkgListTb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->PkgListTb->setCornerButtonEnabled(false);

    /*初始化按键逻辑*/
    connect(ui->btn_Default,&QPushButton::clicked,[=](){
        showMyPkg();
    });
    connect(ui->btn_Search,&QPushButton::clicked,this,&PackageListWindow::searchAndShow);
    //连接radioButton
    connect(ui->rb_Index,&QRadioButton::clicked,[=](){
        ui->line_Search->show();
        ui->date_Date->hide();
        ui->box_Status->hide();
    });
    connect(ui->rb_UsernameSender,&QRadioButton::clicked,[=](){
        ui->line_Search->show();
        ui->date_Date->hide();
        ui->box_Status->hide();
    });
    connect(ui->rb_UsernameRecver,&QRadioButton::clicked,[=](){
        ui->line_Search->show();
        ui->date_Date->hide();
        ui->box_Status->hide();
    });
    connect(ui->rb_Time,&QRadioButton::clicked,[=](){
        ui->line_Search->hide();
        ui->date_Date->show();
        ui->box_Status->hide();
    });
    connect(ui->rb_Status,&QRadioButton::clicked,[=](){
        ui->line_Search->hide();
        ui->date_Date->hide();
        ui->box_Status->show();
    });


    /*初始化表格逻辑*/
    connect(ui->PkgListTb,&QTableWidget::itemDoubleClicked,this,&PackageListWindow::showDetailInfo);
}

//发送请求
void PackageListWindow::initReq(){
    /*构造Json字符串*/
    QJsonObject obj;
    obj.insert("target",8);
    QJsonObject info;
    info.insert("username",theUser["username"].toString());
    info.insert("type",this->status);

    obj.insert("info",info);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray abyte = doc.toJson(QJsonDocument::Compact);
    qDebug() << abyte;
    LoginWindow::con->write(abyte);
    /*绑定逻辑*/
    connect(LoginWindow::con,&QTcpSocket::readyRead,this,&PackageListWindow::initRes);
}



//收到回应
void PackageListWindow::initRes(){
    disconnect(LoginWindow::con,&QTcpSocket::readyRead,this,&PackageListWindow::initRes);

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
        QJsonArray client = obj["message"].toArray();
        //依次读入快递信息
        this->packageList.clear();
        for(auto item = client.constBegin();item != client.constEnd();item++){
            this->packageList.insert((*item).toObject()["index"].toString(),
                    (*item).toObject());
        }
        showMyPkg();
        return;
    }
}





/*查看详细信息*/
void PackageListWindow::showDetailInfo(QTableWidgetItem *item){

    if(item->column() == 0){
        PackageInfoWindow *pkgInfo = new PackageInfoWindow(
                    this->packageList[item->text()],this);
        pkgInfo->show();

    }
    else if(item->column() == 1 || item->column() == 2){
        UserInfoWindow *userInfo = new UserInfoWindow(item->text(),2,this->status,this);
        userInfo->show();
    }
}

/*展示包裹*/
void PackageListWindow::showList(QList<QJsonObject> pkgList){
    /*无项目直接return*/
    int len = pkgList.length();
    ui->PkgListTb->setRowCount(len);
    if(len == 0){
        return;
    }
    int col;
    /*填充table*/
    for(int i = 0;i < len; i++){
        col = 0;
        //qDebug()<< pkg[i]->getIndex();
        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(pkgList[i]["index"].toString()));
        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(pkgList[i]["senderUsername"].toString()));
        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(pkgList[i]["recverUsername"].toString()));
        int status = pkgList[i]["status"].toInt();
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

        ui->PkgListTb->setItem(i,col++,new QTableWidgetItem(st));
    }
}





/*展示我的包裹*/
void PackageListWindow::showMyPkg(){
    QList<QJsonObject> tmp;
    //转化为QList

    for(auto i = packageList.cbegin();i != packageList.cend();i++){
        tmp.append(i.value());
    }
    showList(tmp);
    return;
}

/*展示搜索结果*/
void PackageListWindow::searchAndShow(){
    QList <QJsonObject> showPkgList;
    if(ui->rb_Index->isChecked()){  //按快递号查找
        if( packageList.contains(ui->line_Search->text()) ){
            showPkgList.push_back(packageList[ui->line_Search->text()]);
        }

    }
    else if(ui->rb_UsernameSender->isChecked()){  //按用户名
        for(auto iter = packageList.constBegin(); iter != packageList.constEnd();iter++){
            if(iter.value()["senderUsername"].toString() == ui->line_Search->text()){
                showPkgList.push_back(iter.value());
            }
        }

    }
    else if(ui->rb_UsernameRecver->isChecked()){
        for(auto iter = packageList.constBegin(); iter != packageList.constEnd();iter++){
            if(iter.value()["recverUsername"].toString() == ui->line_Search->text()){
                showPkgList.push_back(iter.value());
            }
        }
    }
    else if(ui->rb_Time->isChecked()){                                   //按时间
        QDate tmp = ui->date_Date->date();

        for(auto iter = packageList.constBegin(); iter != packageList.constEnd();iter++){

            QDateTime senderTime = QDateTime::fromSecsSinceEpoch(getLongData(iter.value(),"senderTime"));
            QDateTime collectorTime = QDateTime::fromSecsSinceEpoch(getLongData(iter.value(),"collectorTime"));
            QDateTime recverTime = QDateTime::fromSecsSinceEpoch(getLongData(iter.value(),"recverTime"));

            if(senderTime.date() == tmp ||
                    collectorTime.date() == tmp || recverTime.date() == tmp){
                showPkgList.push_back(iter.value());
            }
        }
    }
    else{   //按状态
        char status = ui->box_Status->currentIndex() + 1;
        for(auto iter = packageList.constBegin(); iter != packageList.constEnd();iter++){
            if(iter.value()["status"].toInt() == status){
                showPkgList.push_back(iter.value());
            }
        }

    }
    return showList(showPkgList);
}


qint64 PackageListWindow::getLongData(QJsonObject json, QString key){
    return QString::number(json.value(key).toDouble(), 'f', 0).toLongLong();
}

PackageListWindow::~PackageListWindow()
{
    delete ui;
}
