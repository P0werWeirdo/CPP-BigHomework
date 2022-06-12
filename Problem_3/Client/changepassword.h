#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonDocument>

namespace Ui {
class ChangePassword;
}


class ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePassword(QJsonObject user,int type,QDialog* parent = nullptr);
    ~ChangePassword();
    void checkPassword();
    void recvResponse();

private:
    QJsonObject theUser;
    int type;
    Ui::ChangePassword *ui;
};

#endif // CHANGEPASSWORD_H
