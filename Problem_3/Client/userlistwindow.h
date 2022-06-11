#ifndef USERLISTWINDOW_H
#define USERLISTWINDOW_H

#include <QDialog>
#include<QTableWidgetItem>
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

    void showClientInfo();//展示用户信息
    void showCourierInfo(); //展示快递员信息
    void showDetailInfo(QTableWidgetItem *item);

private:
    Ui::UserListWindow *ui;
    int admin;
};

#endif // USERLISTWINDOW_H
