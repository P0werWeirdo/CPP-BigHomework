#include "userinfowindow.h"
#include "ui_userinfowindow.h"

UserInfoWindow::UserInfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInfoWindow)
{
    ui->setupUi(this);
}

UserInfoWindow::~UserInfoWindow()
{
    delete ui;
}
