#include "distributewindow.h"
#include "ui_distributewindow.h"
#include<QRegExpValidator>
#include<QMessageBox>
#include"administrator.h"

DistributeWindow::DistributeWindow(Package *thePkg,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DistributeWindow)
{
    ui->setupUi(this);
    this->setFixedSize(400,400);           //设置窗口大小
    /*窗口基本设置*/
    this->setWindowTitle("分配包裹");
    this->setWindowModality(Qt::WindowModal);

    ui->nameLabel->setText("不存在");
    ui->phoneLabel->setText("不存在");

    //初始化
    this->thePkg = thePkg;

    /*禁止用户名框输入中文*/
    QRegExp regx1("[a-zA-Z0-9]+$");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->lineUsername);
    ui->lineUsername->setValidator( validator1 );

    connect(ui->lineUsername,&QLineEdit::textChanged,this,&DistributeWindow::searchCourier);
    connect(ui->btn_Confirm,&QPushButton::clicked,this,&DistributeWindow::distributeConfirm);
}

//查找并渲染快递员
void DistributeWindow::searchCourier(){
    if(Courier::courierList.contains(ui->lineUsername->text())){
        Courier *courier = Courier::courierList[ui->lineUsername->text()];
        ui->nameLabel->setText(courier->getName());
        ui->phoneLabel->setText(courier->getPhoneNum());
    }
    else {
        ui->nameLabel->setText("不存在");
        ui->phoneLabel->setText("不存在");
    }
}

//确认揽收
void DistributeWindow::distributeConfirm(){
    if(Administrator::admin.distribute(ui->lineUsername->text(),thePkg->getIndex())){
        QMessageBox::about(this,"","快递："+thePkg->getIndex() + "已经指定了快递员");
        this->close();
    }
    else{
        QMessageBox::critical(this,"错误","快递员不存在");
    }
}

//发出信号
void DistributeWindow::closeEvent(QCloseEvent *e){
    emit distributeFinish();
    e->accept();
}

DistributeWindow::~DistributeWindow()
{
    delete ui;
}
