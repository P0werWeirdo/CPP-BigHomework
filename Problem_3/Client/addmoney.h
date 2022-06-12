#ifndef ADDMONEY_H
#define ADDMONEY_H

#include <QDialog>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
namespace Ui {
class AddMoney;
}

class AddMoney : public QDialog
{
    Q_OBJECT

public:
    explicit AddMoney(QJsonObject c,QWidget *parent = nullptr);
    void addReq()const;  //充值操作检测
    void addRes();  //

    ~AddMoney();
signals:
    void addFinish();
private:
    QJsonObject theClient;
    Ui::AddMoney *ui;
};

#endif // ADDMONEY_H
