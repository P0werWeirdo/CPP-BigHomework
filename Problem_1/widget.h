#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);      //登录界面构造函数
    ~Widget();                              //登录界面析构函数

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
