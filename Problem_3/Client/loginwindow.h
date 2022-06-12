#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include<QTcpSocket>
#include<QEventLoop>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QDialog *parent = nullptr);        //构造函数
    bool userLogin();                                  //用户登录
    void userRegister();                               //用户注册
    bool clientRegister(QString username,QString password,QString name,QString phoneNum);                                  //注册用户
    void initConnect();                                 //初始化连接
    void adminLogin();
    void clientLogin();
    void courierLogin();

    static QTcpSocket *con;
    QEventLoop loop;
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
