#ifndef PACKAGEINFOWINDOW_H
#define PACKAGEINFOWINDOW_H

#include <QDialog>
#include<QJsonObject>
namespace Ui {
class PackageInfoWindow;
}

class PackageInfoWindow : public QDialog
{
    Q_OBJECT

public:

    explicit PackageInfoWindow(QJsonObject pkg,QWidget *parent = nullptr);
    void showInfo();
    ~PackageInfoWindow();

    qint64 getLongData(QJsonObject json, QString key);

private:
    QJsonObject pkg;
    Ui::PackageInfoWindow *ui;
};

#endif // PACKAGEINFOWINDOW_H
