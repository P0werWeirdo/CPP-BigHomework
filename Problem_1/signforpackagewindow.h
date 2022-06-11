#ifndef SIGNFORPACKAGEWINDOW_H
#define SIGNFORPACKAGEWINDOW_H

#include <QDialog>
#include"client.h"
#include<QTableWidgetItem>

namespace Ui {
class SignForPackageWindow;
}

class SignForPackageWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignForPackageWindow(Client* c, QWidget *parent = nullptr);
    ~SignForPackageWindow();
    bool signAllPkg()const;
    void showAllPkg();
    void showDetailInfo(QTableWidgetItem *item);

private:
    Client* theClient;
    Ui::SignForPackageWindow *ui;
};

#endif // SIGNFORPACKAGEWINDOW_H
