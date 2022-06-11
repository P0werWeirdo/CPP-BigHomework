#include "loginwindow.h"
#include "ui_loginwindow.h"
#include<QFile>
#include<QDebug>
#include"package.h"
#include"client.h"
#include"administrator.h"
#include"adminwindow.h"
#include"registerwindow.h"
#include"clientwindow.h"
#include<QRegExpValidator>
LoginWindow::LoginWindow(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("登录界面");       //设置窗口标题
    this->setFixedSize(400,250);           //设置窗口大小
    /*设置默认响应*/
    ui->Login_PushButton->setFocus();
    ui->Login_PushButton->setDefault(true);

    /*禁止用户名框输入中文*/
    QRegExp regx1("[a-zA-Z0-9]+$");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->Username_Line);
    ui->Username_Line->setValidator( validator1 );
    /*密码输入错误提示*/
    ui->Input_Error->hide();
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->Input_Error->setPalette(pa);

    /*设置默认选项*/
    ui->btn_Client->click();
    /*绑定信号*/
    connect(ui->Login_PushButton,&QPushButton::clicked,this,&LoginWindow::userLogin);
    connect(ui->Quit_PushButton_2,&QPushButton::clicked,this,[=](){
        this->close();
    });
    connect(ui->btn_Register,&QPushButton::clicked,this,&LoginWindow::userRegister);
    /*初始化用户和包裹数据*/
    initData();


//    qDebug()<< Client::clientList.value("1234");
//    qDebug()<< Client::clientList.size();
}

//初始化数据
void LoginWindow::initData()const{
    Administrator::initAdmin();
//    qDebug()<< Administrator::admin.getName();
    Client::initClientList();
    Package::initPackage();
}
//保存数据
bool LoginWindow::saveData()const{
    return Administrator::saveAdmin() && Client::saveClientList() && Package::savePackage();
}

bool LoginWindow::userLogin(){

    if(ui->btn_Client->isChecked()){        //根据radio按钮判断是否选中
//        qDebug()<<"客户选中";
        //用户不存在 或者 密码错误
          if(Client::clientList.contains(ui->Username_Line->text()) == false ||
             Client::clientList[ui->Username_Line->text()]->getPassword() != ui->Password_Line->text()){
            ui->Input_Error->setText("用户不存在或密码错误");
            ui->Input_Error->show();
          }
          else{
             ClientWindow *cw = new ClientWindow(this,Client::clientList[ui->Username_Line->text()]); //挂到对象树上
             connect(cw,&ClientWindow::clientExit,[=](){
                 ui->Password_Line->setText("");
                 ui->Input_Error->hide();
                 this->show();
             });
             cw->show();
             this->hide();
             return true;
          }
    }
    else{
//        qDebug()<<"管理员选中";
        if(Administrator::admin.getUsername() !=  ui->Username_Line->text()||
           Administrator::admin.getPassword() !=  ui->Password_Line->text()){
          ui->Input_Error->setText("用户不存在或密码错误");
          ui->Input_Error->show();
        }
        else{
           AdminWindow *aw = new AdminWindow(this);  //挂到对象树上
           connect(aw,&AdminWindow::adminExit,[=](){
               ui->Password_Line->setText("");
               this->show();
           });
           aw->setModal(true);
           this->hide();
           aw->show();
           return true;
        }
    }
    return false;
}

void LoginWindow::userRegister(){      //用户注册函数
     RegisterWindow *rw = new RegisterWindow(this);
     connect(rw,&RegisterWindow::hasFinish,[=](){
         this->show();
     });
     rw->show();
     this->hide();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
