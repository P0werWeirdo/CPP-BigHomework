#ifndef SENDPACKAGEWINDOW_H
#define SENDPACKAGEWINDOW_H

#include <QDialog>
#include<client.h>
namespace Ui {
class SendPackageWindow;
}

class SendPackageWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SendPackageWindow(QWidget *parent = nullptr,Client* theClient = NULL);
    ~SendPackageWindow();
    void initSenderInfo();
    void sendPackage();
    void showRecvInfo();
signals:
    void sendFinish();
private:
    Client* theClient;

    Ui::SendPackageWindow *ui;
};

#endif // SENDPACKAGEWINDOW_H
