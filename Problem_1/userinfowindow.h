#ifndef USERINFOWINDOW_H
#define USERINFOWINDOW_H

#include <QDialog>
#include"client.h"
namespace Ui {
class UserInfoWindow;
}

class UserInfoWindow : public QDialog
{
    Q_OBJECT

public:
    //0代表管理员 1代表用户
    explicit UserInfoWindow(User* theUser,char status,QWidget *parent = nullptr);
    ~UserInfoWindow();
    void showInfo();

private:
    User* theUser;      //当前用户
    char status;        //用户状态

    Ui::UserInfoWindow *ui;
};

#endif // USERINFOWINDOW_H
