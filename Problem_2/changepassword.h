#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>
#include"user.h"
namespace Ui {
class ChangePassword;
}

class ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePassword(User* theUser,QDialog*parent = nullptr);
    ~ChangePassword();
    void checkPassword();

private:
    User* theUser;
    Ui::ChangePassword *ui;
};

#endif // CHANGEPASSWORD_H
