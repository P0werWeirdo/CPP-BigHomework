#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);     //用户注册调用
    explicit RegisterWindow(int admin,QWidget *parent = nullptr);    //快递员注册调用

    ~RegisterWindow();

    void clientRequest();               //发请求
    void courierRequest();              //发请求

    void clientResHandle();             //处理
    void courierResHandle();            //处理

    void registerClient(int result);      //用户显示结果
    void registerCourier(int result);     //快递员显示结果
    void closeEvent(QCloseEvent * event);
signals:
    void hasFinish();

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
