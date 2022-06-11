#ifndef ADDMONEY_H
#define ADDMONEY_H

#include <QDialog>
#include"client.h"
namespace Ui {
class AddMoney;
}

class AddMoney : public QDialog
{
    Q_OBJECT

public:
    explicit AddMoney(Client *c,QWidget *parent = nullptr);
    void addConfirm();  //充值操作检测
    ~AddMoney();
signals:
    void addFinish();
private:
    Client* theClient;
    Ui::AddMoney *ui;
};

#endif // ADDMONEY_H
