#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include"client.h"

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientWindow(QDialog *parent = nullptr,Client *c = NULL);
    ~ClientWindow();
    void receiveClient(Client *c);
private:
    Client *theClient;
    Ui::ClientWindow *ui;
};

#endif // CLIENTWINDOW_H
