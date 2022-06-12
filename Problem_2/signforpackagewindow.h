#ifndef SIGNFORPACKAGEWINDOW_H
#define SIGNFORPACKAGEWINDOW_H

#include <QDialog>
#include"client.h"
#include<QTableWidgetItem>
#include"administrator.h"
#include"courier.h"

namespace Ui {
class SignForPackageWindow;
}

class SignForPackageWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignForPackageWindow(User* c, QWidget *parent = nullptr);
    ~SignForPackageWindow();
    void initTable();               //初始化表格
    void initLogic();               //初始化逻辑

    bool signAllPkg()const;         //签收所有包裹
    bool collectAllPkg()const;      //揽收所有包裹
    void distributePkg();           //分配包裹
    void showAllPkg();              //展示所有包裹
    void showDetailInfo(QTableWidgetItem *item);
signals:
    void collectFinish()const;

private:
    User* theUser;
    Ui::SignForPackageWindow *ui;
};

#endif // SIGNFORPACKAGEWINDOW_H
