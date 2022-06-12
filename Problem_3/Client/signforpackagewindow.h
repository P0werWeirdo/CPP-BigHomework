#ifndef SIGNFORPACKAGEWINDOW_H
#define SIGNFORPACKAGEWINDOW_H

#include <QDialog>
#include<QTableWidgetItem>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>

namespace Ui {
class SignForPackageWindow;
}

class SignForPackageWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignForPackageWindow(QJsonObject theUse,int type, QWidget *parent = nullptr);
    ~SignForPackageWindow();
    void initTable();               //初始化表格
    void initLogic();               //初始化逻辑

    //bool collectAllPkg()const;      //揽收所有包裹
    void distributePkg();           //分配包裹

    void showDetailInfo(QTableWidgetItem *item);

    //发送请求
    void sendInitReq()const;             //获取包裹信息
    void sendSignReq()const;             //签收请求
    void sendCollectReq()const;          //揽收请求
//    void sendDistributeReq()const;       //分配请求

    //收到信息后处理
    void initRes();                 //获取包裹信息后处理
    void signRes();                 //签收回应
    void collectRes();              //揽收回应
//    void distributeRes();           //分配回应



    //收到请求后初始化
    void showAllPkg();              //展示所有包裹


signals:
    void collectFinish();

private:
    QJsonObject theUser;
    int type;       //1 管理员 2 客户 3 快递员
    QMap<QString,QJsonObject> packageList;
    Ui::SignForPackageWindow *ui;
};

#endif // SIGNFORPACKAGEWINDOW_H
