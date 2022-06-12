#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include<QJsonObject>

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientWindow(QJsonObject c,QDialog *parent = nullptr);
    ~ClientWindow();
    void showInfo();        //展示信息
    void freshUserRequest()const;       //刷新信息
    void freshSuccess();
signals:
    void clientExit();

private:
    QJsonObject theClient;
    Ui::ClientWindow *ui;
};

#endif // CLIENTWINDOW_H
