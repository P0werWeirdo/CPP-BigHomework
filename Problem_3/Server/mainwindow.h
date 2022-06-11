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

private:
    QTcpServer *listen;
    QTcpSocket *con;
    bool hasConnect;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
