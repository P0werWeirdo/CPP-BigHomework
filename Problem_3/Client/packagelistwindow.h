#ifndef PACKAGELISTWINDOW_H
#define PACKAGELISTWINDOW_H

#include <QDialog>

#include<QTableWidgetItem>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>

namespace Ui {
class PackageListWindow;
}

class PackageListWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PackageListWindow(QJsonObject tu,char status,QWidget *parent = nullptr);
    void showList(QList<QJsonObject> pkgList);
    void showMyPkg();
    void searchAndShow();
    void showDetailInfo(QTableWidgetItem *item);
    ~PackageListWindow();

    //发送请求
    void initReq();

    //收到回应
    void initRes();


    qint64 getLongData(QJsonObject json, QString key);
private:
    QJsonObject theUser;
    char status;        //1代表管理员 2代表客户 3代表快递员
    QMap<QString,QJsonObject> packageList;
    Ui::PackageListWindow *ui;
};

#endif // PACKAGELISTWINDOW_H
