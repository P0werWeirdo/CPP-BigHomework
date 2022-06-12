#ifndef DISTRIBUTEWINDOW_H
#define DISTRIBUTEWINDOW_H

#include <QDialog>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonArray>
#include<QMap>

namespace Ui {
class DistributeWindow;
}

class DistributeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DistributeWindow(QJsonObject,QWidget *parent = nullptr);
    ~DistributeWindow();

    //初始化
    void sendCourierReq();
    void initCourierList();
    void searchCourier();

    //
    void sendDistributeReq();
    void distributeConfirm();
    void closeEvent(QCloseEvent *);

signals:
    void distributeFinish();    //退出时候发出信号，刷新分配界面

private:
    Ui::DistributeWindow *ui;
    QJsonObject thePkg;
    QMap<QString, QJsonObject> courierList;
};

#endif // DISTRIBUTEWINDOW_H
