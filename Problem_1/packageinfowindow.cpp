#include "packageinfowindow.h"
#include "ui_packageinfowindow.h"

PackageInfoWindow::PackageInfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PackageInfoWindow)
{
    ui->setupUi(this);
}

PackageInfoWindow::~PackageInfoWindow()
{
    delete ui;
}
