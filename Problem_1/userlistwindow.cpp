#include "userlistwindow.h"
#include "ui_userlistwindow.h"

UserListWindow::UserListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserListWindow)
{
    ui->setupUi(this);
}

UserListWindow::~UserListWindow()
{
    delete ui;
}
