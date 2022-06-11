#ifndef PACKAGELISTWINDOW_H
#define PACKAGELISTWINDOW_H

#include <QDialog>
#include<user.h>
#include<QTableWidgetItem>
namespace Ui {
class PackageListWindow;
}

class PackageListWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PackageListWindow(QWidget *parent = nullptr,User* tu = NULL,char status = '0');
    void showList(QList<Package*> pkg);
    void showMyPkg();
    void searchAndShow();
    void showDetailInfo(QTableWidgetItem *item);
    ~PackageListWindow();

private:
    User *theUser;
    char status;        //0代表管理员 1代表用户
    QMap<QString,Package *> theMap;
    Ui::PackageListWindow *ui;
};

#endif // PACKAGELISTWINDOW_H
