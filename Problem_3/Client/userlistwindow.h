#ifndef USERLISTWINDOW_H
#define USERLISTWINDOW_H

#include <QDialog>
#include<QTableWidgetItem>
#include<QMap>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonDocument>

namespace Ui {
class UserListWindow;
}

class UserListWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserListWindow(QWidget *parent = nullptr);
    explicit UserListWindow(int admin,QWidget *parent = nullptr);
    ~UserListWindow();

    void showInfo();//展示用户信息
    void showDetailInfo(QTableWidgetItem *item);

    //发送查询客户和快递员的请求
    void sendClientReq()const;
    void sendCourierReq()const;

    //对请求进行处理
    void initClientList();
    void initCourierList();

    //发送删除快递员的请求
    void sendDeleteCourier()const;
    void recvDeleteResult();

private:
    Ui::UserListWindow *ui;
    QMap<QString,QJsonObject> userList;
    int admin;
};

#endif // USERLISTWINDOW_H
