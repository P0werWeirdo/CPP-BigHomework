#include "registerwindow.h"
#include "ui_registerwindow.h"
#include"client.h"
#include<QCloseEvent>
#include<QMessageBox>
#include<QRegExpValidator>
RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("注册界面");

    /*输入错误提示初始化*/
    ui->Input_Error->hide();
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->Input_Error->setPalette(pa);

    /*禁止用户名框输入中文*/
    QRegExp regx1("[a-zA-Z0-9]+$");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->Username_Line);
    ui->Username_Line->setValidator( validator1 );
    /*设置电话框只能输入数字*/
    QRegExp regx2("[0-9]+$");
    QValidator* validator2 = new QRegExpValidator(regx2, ui->PhoneNum_Line);
    ui->PhoneNum_Line->setValidator(validator2);

    /*绑定窗口按钮逻辑*/
    connect(ui->btn_Confirm,&QPushButton::clicked,this,&RegisterWindow::registerClient);
    connect(ui->btn_Cancel,&QPushButton::clicked,[=](){
        this->close();
    });
}

void RegisterWindow::registerClient(){
    int tmp = Client::registerNewClient(ui->Username_Line->text(),ui->Password_Line->text(),
                                ui->Name_Line->text(),ui->PhoneNum_Line->text(),ui->Addr_Line->toPlainText());
    //判断是否成功注册，并给予提示消息
    switch (tmp) {
    case 1:
        ui->Input_Error->setText("用户名长度为4~20");
        break;
    case 2:
        ui->Input_Error->setText("用户名已存在");
        break;
    case 3:
        ui->Input_Error->setText("密码长度为6~20");
        break;
    case 4:
        ui->Input_Error->setText("手机号格式有误");
        break;
    case 5:
        ui->Input_Error->setText("姓名不能为空");
        break;
    case 6:
        ui->Input_Error->setText("地址不能为空");
        break;
    case 7:
        ui->Input_Error->setText("地址过长");
        break;
    default:
        QMessageBox::about(this, "注册成功", "您已完成注册");
        this->close();
        break;
    }
    ui->Input_Error->show();
}

void RegisterWindow::closeEvent(QCloseEvent *event){
    emit hasFinish();
    event->accept();
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}
