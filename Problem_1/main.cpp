#include "widget.h"
#include"loginwindow.h"
#include <QApplication>
#include "administrator.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}
