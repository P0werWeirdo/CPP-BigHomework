#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QDialog *parent,Client *c) :
    QDialog(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    theClient = c;
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

