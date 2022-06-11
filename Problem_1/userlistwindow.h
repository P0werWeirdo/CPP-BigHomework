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
    ~UserListWindow();

    void showClientInfo();
    void showDetailInfo(QTableWidgetItem *item);

private:
    Ui::UserListWindow *ui;
};

#endif // USERLISTWINDOW_H
