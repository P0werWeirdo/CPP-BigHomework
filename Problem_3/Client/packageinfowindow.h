#ifndef PACKAGEINFOWINDOW_H
#define PACKAGEINFOWINDOW_H

#include <QDialog>
#include"package.h"
namespace Ui {
class PackageInfoWindow;
}

class PackageInfoWindow : public QDialog
{
    Q_OBJECT

public:

    explicit PackageInfoWindow(Package *pkg,QWidget *parent = nullptr);
    void showInfo();
    ~PackageInfoWindow();

private:
    Package* pkg;
    Ui::PackageInfoWindow *ui;
};

#endif // PACKAGEINFOWINDOW_H
