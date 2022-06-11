#include "changepassword.h"
#include "ui_changepassword.h"
#include<QMessageBox>

ChangePassword::ChangePassword(User* theUser,QDialog *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    /*窗口基本设置*/
    this->setWindowTitle("修改密码");
    this->setWindowModality(Qt::WindowModal);
    this->setFixedSize(500,300);

    /*初始化内部成员*/
    this->theUser = theUser;

    /*初始化按钮逻辑*/
    connect(ui->btn_Cancel,&QPushButton::clicked,[=](){
        this->hide();
        this->destroy();
    });

    connect(ui->btn_Confirm,&QPushButton::clicked,[=](){
        checkPassword();
    });

}

void ChangePassword::checkPassword(){
    //一些错误处理
    if(ui->oldPassword->text() != theUser->getPassword()){
        QMessageBox::critical(this,"错误","原密码错误");
        return;
    }

    if(ui->newPassword->text() != ui->newPassword2->text()){
        QMessageBox::critical(this,"错误","两次密码输入不一致");
        return;
    }

    if(ui->newPassword->text().length() < 6 || ui->newPassword->text().length() > 20){
        QMessageBox::critical(this,"错误","新密码长度必须为6~20");
        return;
    }

    if(theUser->changePassword(ui->oldPassword->text(),ui->newPassword->text())){
        QMessageBox::about(this,"修改成功","密码已经修改成功!");
        this->hide();
        this->destroy();
    }
    else{
        QMessageBox::about(this,"修改失败","请稍后重试");
    }
}

ChangePassword::~ChangePassword()
{
    delete ui;
}
