/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QWidget *widget_5;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *Username_Line;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *NameLine;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLabel *PhoneNum_Line;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *Balance_Line;
    QPushButton *btn_addMoney;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnChangePassword;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_Exit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_SendPkg;
    QPushButton *btn_Check;
    QPushButton *btn_Recv;

    void setupUi(QDialog *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QString::fromUtf8("ClientWindow"));
        ClientWindow->resize(944, 482);
        widget_5 = new QWidget(ClientWindow);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(50, 20, 411, 361));
        verticalLayout = new QVBoxLayout(widget_5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(widget_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        Username_Line = new QLabel(widget);
        Username_Line->setObjectName(QString::fromUtf8("Username_Line"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(20);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Username_Line->sizePolicy().hasHeightForWidth());
        Username_Line->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Username_Line);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        NameLine = new QLabel(widget_2);
        NameLine->setObjectName(QString::fromUtf8("NameLine"));
        sizePolicy.setHeightForWidth(NameLine->sizePolicy().hasHeightForWidth());
        NameLine->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(NameLine);


        verticalLayout->addWidget(widget_2);

        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(widget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        PhoneNum_Line = new QLabel(widget_4);
        PhoneNum_Line->setObjectName(QString::fromUtf8("PhoneNum_Line"));
        sizePolicy.setHeightForWidth(PhoneNum_Line->sizePolicy().hasHeightForWidth());
        PhoneNum_Line->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(PhoneNum_Line);


        verticalLayout->addWidget(widget_4);

        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        Balance_Line = new QLabel(widget_3);
        Balance_Line->setObjectName(QString::fromUtf8("Balance_Line"));
        sizePolicy.setHeightForWidth(Balance_Line->sizePolicy().hasHeightForWidth());
        Balance_Line->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Balance_Line);

        btn_addMoney = new QPushButton(widget_3);
        btn_addMoney->setObjectName(QString::fromUtf8("btn_addMoney"));

        horizontalLayout_3->addWidget(btn_addMoney);


        verticalLayout->addWidget(widget_3);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(41, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btnChangePassword = new QPushButton(widget_6);
        btnChangePassword->setObjectName(QString::fromUtf8("btnChangePassword"));

        horizontalLayout_5->addWidget(btnChangePassword);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btn_Exit = new QPushButton(widget_6);
        btn_Exit->setObjectName(QString::fromUtf8("btn_Exit"));

        horizontalLayout_5->addWidget(btn_Exit);

        horizontalSpacer_3 = new QSpacerItem(41, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_6);

        btn_SendPkg = new QPushButton(ClientWindow);
        btn_SendPkg->setObjectName(QString::fromUtf8("btn_SendPkg"));
        btn_SendPkg->setGeometry(QRect(630, 110, 161, 31));
        btn_Check = new QPushButton(ClientWindow);
        btn_Check->setObjectName(QString::fromUtf8("btn_Check"));
        btn_Check->setGeometry(QRect(630, 160, 161, 31));
        btn_Recv = new QPushButton(ClientWindow);
        btn_Recv->setObjectName(QString::fromUtf8("btn_Recv"));
        btn_Recv->setGeometry(QRect(630, 210, 161, 28));

        retranslateUi(ClientWindow);

        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QDialog *ClientWindow)
    {
        ClientWindow->setWindowTitle(QApplication::translate("ClientWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("ClientWindow", "\347\224\250\346\210\267\345\220\215:", nullptr));
        Username_Line->setText(QApplication::translate("ClientWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("ClientWindow", "\345\247\223\345\220\215:", nullptr));
        NameLine->setText(QApplication::translate("ClientWindow", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("ClientWindow", "\346\211\213\346\234\272\345\217\267:", nullptr));
        PhoneNum_Line->setText(QApplication::translate("ClientWindow", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("ClientWindow", "\344\275\231\351\242\235:", nullptr));
        Balance_Line->setText(QApplication::translate("ClientWindow", "TextLabel", nullptr));
        btn_addMoney->setText(QApplication::translate("ClientWindow", "\345\205\205\345\200\274", nullptr));
        btnChangePassword->setText(QApplication::translate("ClientWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        btn_Exit->setText(QApplication::translate("ClientWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        btn_SendPkg->setText(QApplication::translate("ClientWindow", "\345\217\221\351\200\201\346\226\260\347\232\204\345\277\253\351\200\222", nullptr));
        btn_Check->setText(QApplication::translate("ClientWindow", "\346\237\245\347\234\213\350\207\252\345\267\261\347\232\204\345\277\253\351\200\222", nullptr));
        btn_Recv->setText(QApplication::translate("ClientWindow", "\347\255\276\346\224\266\350\207\252\345\267\261\347\232\204\345\277\253\351\200\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
