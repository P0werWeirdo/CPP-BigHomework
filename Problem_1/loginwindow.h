#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QDialog *parent = nullptr);        //构造函数
    bool userLogin();                                  //用户登录
    void initData()const;                                        //初始化所有数据
    bool saveData()const;                                        //保存所有数据
    void userRegister();                               //用户注册
    bool clientRegister(QString username,QString password,QString name,QString phoneNum);                                  //注册用户
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
