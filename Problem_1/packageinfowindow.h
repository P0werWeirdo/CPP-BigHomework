#ifndef PACKAGEINFOWINDOW_H
#define PACKAGEINFOWINDOW_H

#include <QDialog>

namespace Ui {
class PackageInfoWindow;
}

class PackageInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PackageInfoWindow(QWidget *parent = nullptr);
    ~PackageInfoWindow();

private:
    Ui::PackageInfoWindow *ui;
};

#endif // PACKAGEINFOWINDOW_H
