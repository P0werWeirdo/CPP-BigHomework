#ifndef USERLISTWINDOW_H
#define USERLISTWINDOW_H

#include <QDialog>

namespace Ui {
class UserListWindow;
}

class UserListWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserListWindow(QWidget *parent = nullptr);
    ~UserListWindow();

private:
    Ui::UserListWindow *ui;
};

#endif // USERLISTWINDOW_H
