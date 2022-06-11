#ifndef COURIERWINDOW_H
#define COURIERWINDOW_H

#include <QDialog>
#include"courier.h"

namespace Ui {
class CourierWindow;
}

class CourierWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CourierWindow(Courier *,QWidget *parent = nullptr);

    void showInfo();        //展示信息
    ~CourierWindow();
signals:
    void courierExit();

private:
    Ui::CourierWindow *ui;
    Courier *theCourier;
};

#endif // COURIERWINDOW_H
