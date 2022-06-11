#include "addmoney.h"
#include "ui_addmoney.h"
#include<QMessageBox>
AddMoney::AddMoney(Client *c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMoney)
{
    ui->setupUi(this);
    this->setWindowTitle("充值窗口");
    this->setWindowModality(Qt::WindowModal);
    /*初始化提示*/
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->Tips_Label->setPalette(pa);
    /*初始化内部成员*/
    theClient = c;
    /*初始化按钮逻辑*/
    connect(ui->btn_Confirm,&QPushButton::clicked,[=](){
        addConfirm();
    });
}
void AddMoney::addConfirm(){
    if(theClient->changeBalance((double)(ui->MoneyNum->value()))){
        QMessageBox::about(this,"充值成功","您已经成功充值");
        emit addFinish();
        this->close();
        this->deleteLater();
    }
    else{
        QMessageBox::critical(this,"充值失败","请重新尝试");
    }
}
AddMoney::~AddMoney()
{
    delete ui;
}
