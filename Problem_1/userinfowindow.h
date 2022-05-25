#ifndef USERINFOWINDOW_H
#define USERINFOWINDOW_H

#include <QDialog>

namespace Ui {
class UserInfoWindow;
}

class UserInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfoWindow(QWidget *parent = nullptr);
    ~UserInfoWindow();

private:
    Ui::UserInfoWindow *ui;
};

#endif // USERINFOWINDOW_H
