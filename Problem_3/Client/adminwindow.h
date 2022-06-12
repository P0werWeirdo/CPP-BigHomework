#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include<QJsonObject>
namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QJsonObject admin,QDialog *parent = nullptr);
    ~AdminWindow();
    void showInfo();
    void searchPkg();
    void searchUser();
signals:
    void adminExit();


private:
    QJsonObject admin;
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
