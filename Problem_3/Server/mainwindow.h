#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include<QTcpServer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initData()const;       //初始化数据
    void initWindow();          //初始化窗口
    void initServer();          //初始化服务器

    void adminLogin(QJsonObject admin);         //管理员登录
    void clientLogin(QJsonObject client);       //客户登录
    void courierLogin(QJsonObject courier);     //快递员登录

    void clientRegister(QJsonObject client);    //用户注册
    void courierRegister(QJsonObject courier);  //快递员注册

    void searchClient(QJsonObject client);      //查询用户
    void searchPackage(QJsonObject user);       //查询包裹
    void searchCourier(QJsonObject info);       //查询快递员

    void sendPackage(QJsonObject package);      //发送包裹
    void dealWithPackage(QJsonObject package);      //处理包裹

    void addMoney(QJsonObject info);            //充钱

    void deleteCourier(QJsonObject info);       //删除快递员

    void changePassword(QJsonObject info);      //修改密码

private:
    QTcpServer *listen;
    QTcpSocket *con;
    bool hasConnect;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
