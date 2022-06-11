#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QDialog *parent = nullptr);
    ~AdminWindow();
    void showInfo();
    void searchPkg();
    void searchUser();
signals:
    void adminExit();


private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
