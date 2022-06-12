#ifndef USERINFOWINDOW_H
#define USERINFOWINDOW_H

#include <QDialog>
#include<QJsonObject>

namespace Ui {
class UserInfoWindow;
}

class UserInfoWindow : public QDialog
{
    Q_OBJECT

public:
    //1代表管理员 2代表用户 3代表快递员 status 表示谁看   type 表示被看人的身份
    explicit UserInfoWindow(QString username,char status,int type,QWidget *parent = nullptr);
    explicit UserInfoWindow(QJsonObject user,char status,int type,QWidget *parent = nullptr);
    ~UserInfoWindow();
    void showInfo();

    //发送查询请求
    void sendSearchReq(QString username)const;
    void initUser();


private:
    QJsonObject theUser;      //当前用户
    char status;        //用户状态

    Ui::UserInfoWindow *ui;
};

#endif // USERINFOWINDOW_H
