#ifndef SENDPACKAGEWINDOW_H
#define SENDPACKAGEWINDOW_H

#include <QDialog>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>
#include<QMap>

namespace Ui {
class SendPackageWindow;
}

class SendPackageWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SendPackageWindow(QJsonObject client,QWidget *parent = nullptr);
    ~SendPackageWindow();
    void initSenderInfo();
    void sendPackage();
    void showRecvInfo();
    void showPrice(int);       //展示价格
    void sendInitRequest();       //发送初始化的请求
    void initTotalUser();         //初始化
    void showResult();




signals:
    void sendFinish();
private:
    QJsonObject theClient;
    QMap<QString,QList<QString>> totalUser;

    Ui::SendPackageWindow *ui;
};

#endif // SENDPACKAGEWINDOW_H
