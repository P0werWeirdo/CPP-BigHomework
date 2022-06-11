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
    void registerClient();      //用户注册
    void registerCourier();     //快递员注册
    void closeEvent(QCloseEvent * event);
signals:
    void hasFinish();

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
