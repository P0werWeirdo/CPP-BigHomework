#ifndef DISTRIBUTEWINDOW_H
#define DISTRIBUTEWINDOW_H

#include <QDialog>
#include"package.h"
#include"courier.h"

namespace Ui {
class DistributeWindow;
}

class DistributeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DistributeWindow(Package *,QWidget *parent = nullptr);
    ~DistributeWindow();

    void searchCourier();
    void distributeConfirm();
    void closeEvent(QCloseEvent *);

signals:
    void distributeFinish();    //退出时候发出信号，刷新分配界面

private:
    Ui::DistributeWindow *ui;
    Package* thePkg;
};

#endif // DISTRIBUTEWINDOW_H
