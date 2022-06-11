/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_16;
    QWidget *widget_7;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *Username_Line;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *Password_Line;
    QSpacerItem *horizontalSpacer_9;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_10;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLineEdit *Name_Line;
    QSpacerItem *horizontalSpacer_11;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_12;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_11;
    QLineEdit *PhoneNum_Line;
    QSpacerItem *horizontalSpacer_13;
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_14;
    QWidget *widget_17;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Addr;
    QTextEdit *Addr_Line;
    QSpacerItem *horizontalSpacer_15;
    QLabel *Input_Error;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Confirm;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_Cancel;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_17;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QString::fromUtf8("RegisterWindow"));
        RegisterWindow->setWindowModality(Qt::WindowModal);
        RegisterWindow->resize(630, 585);
        horizontalLayout = new QHBoxLayout(RegisterWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_16 = new QSpacerItem(47, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_16);

        widget_7 = new QWidget(RegisterWindow);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        gridLayout = new QGridLayout(widget_7);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 1);

        widget_2 = new QWidget(widget_7);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_8 = new QWidget(widget_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_8 = new QHBoxLayout(widget_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_6 = new QSpacerItem(75, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_7 = new QHBoxLayout(widget_9);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(widget_9);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        Username_Line = new QLineEdit(widget_9);
        Username_Line->setObjectName(QString::fromUtf8("Username_Line"));
        Username_Line->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_7->addWidget(Username_Line);


        horizontalLayout_8->addWidget(widget_9);

        horizontalSpacer_7 = new QSpacerItem(74, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);


        verticalLayout->addWidget(widget_8);

        widget_10 = new QWidget(widget_2);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_9 = new QHBoxLayout(widget_10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_8 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        widget_11 = new QWidget(widget_10);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_10 = new QHBoxLayout(widget_11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(widget_11);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        Password_Line = new QLineEdit(widget_11);
        Password_Line->setObjectName(QString::fromUtf8("Password_Line"));
        Password_Line->setEchoMode(QLineEdit::Password);

        horizontalLayout_10->addWidget(Password_Line);


        horizontalLayout_9->addWidget(widget_11);

        horizontalSpacer_9 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout->addWidget(widget_10);

        widget_12 = new QWidget(widget_2);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_11 = new QHBoxLayout(widget_12);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_10 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_10);

        widget_13 = new QWidget(widget_12);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        horizontalLayout_12 = new QHBoxLayout(widget_13);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_10 = new QLabel(widget_13);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_12->addWidget(label_10);

        Name_Line = new QLineEdit(widget_13);
        Name_Line->setObjectName(QString::fromUtf8("Name_Line"));

        horizontalLayout_12->addWidget(Name_Line);


        horizontalLayout_11->addWidget(widget_13);

        horizontalSpacer_11 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);


        verticalLayout->addWidget(widget_12);

        widget_14 = new QWidget(widget_2);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        horizontalLayout_13 = new QHBoxLayout(widget_14);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_12 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_12);

        widget_15 = new QWidget(widget_14);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        horizontalLayout_14 = new QHBoxLayout(widget_15);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_11 = new QLabel(widget_15);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_14->addWidget(label_11);

        PhoneNum_Line = new QLineEdit(widget_15);
        PhoneNum_Line->setObjectName(QString::fromUtf8("PhoneNum_Line"));

        horizontalLayout_14->addWidget(PhoneNum_Line);


        horizontalLayout_13->addWidget(widget_15);

        horizontalSpacer_13 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_13);


        verticalLayout->addWidget(widget_14);

        widget_16 = new QWidget(widget_2);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        horizontalLayout_4 = new QHBoxLayout(widget_16);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_14 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_14);

        widget_17 = new QWidget(widget_16);
        widget_17->setObjectName(QString::fromUtf8("widget_17"));
        horizontalLayout_3 = new QHBoxLayout(widget_17);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_Addr = new QLabel(widget_17);
        label_Addr->setObjectName(QString::fromUtf8("label_Addr"));

        horizontalLayout_3->addWidget(label_Addr);

        Addr_Line = new QTextEdit(widget_17);
        Addr_Line->setObjectName(QString::fromUtf8("Addr_Line"));

        horizontalLayout_3->addWidget(Addr_Line);


        horizontalLayout_4->addWidget(widget_17);

        horizontalSpacer_15 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_15);


        verticalLayout->addWidget(widget_16);

        Input_Error = new QLabel(widget_2);
        Input_Error->setObjectName(QString::fromUtf8("Input_Error"));
        Input_Error->setEnabled(true);

        verticalLayout->addWidget(Input_Error);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btn_Confirm = new QPushButton(widget_6);
        btn_Confirm->setObjectName(QString::fromUtf8("btn_Confirm"));

        horizontalLayout_5->addWidget(btn_Confirm);

        horizontalSpacer_2 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btn_Cancel = new QPushButton(widget_6);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));

        horizontalLayout_5->addWidget(btn_Cancel);

        horizontalSpacer_3 = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_6);


        gridLayout->addWidget(widget_2, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 5, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 2, 0, 1, 1);


        horizontalLayout->addWidget(widget_7);

        horizontalSpacer_17 = new QSpacerItem(46, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_17);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QApplication::translate("RegisterWindow", "Dialog", nullptr));
        label_8->setText(QApplication::translate("RegisterWindow", "\350\264\246  \345\217\267\357\274\232", nullptr));
        label_9->setText(QApplication::translate("RegisterWindow", "\345\257\206  \347\240\201\357\274\232", nullptr));
        label_10->setText(QApplication::translate("RegisterWindow", "\345\247\223  \345\220\215\357\274\232", nullptr));
        label_11->setText(QApplication::translate("RegisterWindow", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label_Addr->setText(QApplication::translate("RegisterWindow", "\345\234\260 \345\235\200\357\274\232", nullptr));
        Input_Error->setText(QApplication::translate("RegisterWindow", "\347\224\250\346\210\267\345\220\215\346\210\226\345\257\206\347\240\201\351\224\231\350\257\257\357\274\201", nullptr));
        btn_Confirm->setText(QApplication::translate("RegisterWindow", "\347\241\256\350\256\244", nullptr));
        btn_Cancel->setText(QApplication::translate("RegisterWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
