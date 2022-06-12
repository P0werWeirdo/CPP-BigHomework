#ifndef COURIERWINDOW_H
#define COURIERWINDOW_H

#include <QDialog>
#include<QJsonObject>
#include<QJsonArray>

namespace Ui {
class CourierWindow;
}

class CourierWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CourierWindow(QJsonObject courier,QWidget *parent = nullptr);

    void showInfo();        //展示信息

    void freshUserRequest();       //刷新信息
    void freshSuccess();
    ~CourierWindow();
signals:
    void courierExit();

private:
    Ui::CourierWindow *ui;
    QJsonObject theCourier;
};

#endif // COURIERWINDOW_H
