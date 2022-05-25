/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_3;
    QLineEdit *Username_Line;
    QSpacerItem *horizontalSpacer_9;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *Login_PushButton;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *Quit_PushButton_2;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *btn_Register;
    QLabel *Input_Error;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_4;
    QLineEdit *Password_Line;
    QSpacerItem *horizontalSpacer_14;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *btn_Client;
    QRadioButton *btn_admin;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(439, 289);
        widget = new QWidget(LoginWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 378, 55));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        Username_Line = new QLineEdit(widget);
        Username_Line->setObjectName(QString::fromUtf8("Username_Line"));

        horizontalLayout_4->addWidget(Username_Line);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        widget_3 = new QWidget(LoginWindow);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 190, 378, 55));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Login_PushButton = new QPushButton(widget_3);
        Login_PushButton->setObjectName(QString::fromUtf8("Login_PushButton"));

        horizontalLayout_5->addWidget(Login_PushButton);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        Quit_PushButton_2 = new QPushButton(widget_3);
        Quit_PushButton_2->setObjectName(QString::fromUtf8("Quit_PushButton_2"));

        horizontalLayout_5->addWidget(Quit_PushButton_2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        btn_Register = new QPushButton(widget_3);
        btn_Register->setObjectName(QString::fromUtf8("btn_Register"));

        horizontalLayout_5->addWidget(btn_Register);

        Input_Error = new QLabel(LoginWindow);
        Input_Error->setObjectName(QString::fromUtf8("Input_Error"));
        Input_Error->setEnabled(true);
        Input_Error->setGeometry(QRect(90, 170, 331, 21));
        widget_2 = new QWidget(LoginWindow);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 72, 378, 54));
        horizontalLayout_6 = new QHBoxLayout(widget_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        Password_Line = new QLineEdit(widget_2);
        Password_Line->setObjectName(QString::fromUtf8("Password_Line"));
        Password_Line->setContextMenuPolicy(Qt::DefaultContextMenu);
        Password_Line->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(Password_Line);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);

        widget_4 = new QWidget(LoginWindow);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(60, 120, 259, 41));
        horizontalLayout_7 = new QHBoxLayout(widget_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        btn_Client = new QRadioButton(widget_4);
        btn_Client->setObjectName(QString::fromUtf8("btn_Client"));

        horizontalLayout_7->addWidget(btn_Client);

        btn_admin = new QRadioButton(widget_4);
        btn_admin->setObjectName(QString::fromUtf8("btn_admin"));

        horizontalLayout_7->addWidget(btn_admin);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Dialog", nullptr));
        label_3->setText(QApplication::translate("LoginWindow", "\350\264\246\345\217\267\357\274\232", nullptr));
        Login_PushButton->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        Quit_PushButton_2->setText(QApplication::translate("LoginWindow", "\351\200\200\345\207\272", nullptr));
        btn_Register->setText(QApplication::translate("LoginWindow", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        Input_Error->setText(QApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215\346\210\226\345\257\206\347\240\201\351\224\231\350\257\257\357\274\201", nullptr));
        label_4->setText(QApplication::translate("LoginWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        btn_Client->setText(QApplication::translate("LoginWindow", "\345\256\242\346\210\267", nullptr));
        btn_admin->setText(QApplication::translate("LoginWindow", "\347\256\241\347\220\206\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
