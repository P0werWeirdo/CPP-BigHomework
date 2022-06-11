/********************************************************************************
** Form generated from reading UI file 'userinfowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOWINDOW_H
#define UI_USERINFOWINDOW_H

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

class Ui_UserInfoWindow
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *Username_Line;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *Name_Line;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLabel *PhoneNum_Line;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Addr;
    QLabel *Addr_Line;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Balance_Line2;
    QLabel *Blance_Line;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QPushButton *btn_Check;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Quit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *UserInfoWindow)
    {
        if (UserInfoWindow->objectName().isEmpty())
            UserInfoWindow->setObjectName(QString::fromUtf8("UserInfoWindow"));
        UserInfoWindow->resize(744, 456);
        verticalLayout = new QVBoxLayout(UserInfoWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget_5 = new QWidget(UserInfoWindow);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_2 = new QVBoxLayout(widget_5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
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


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        Name_Line = new QLabel(widget_2);
        Name_Line->setObjectName(QString::fromUtf8("Name_Line"));
        sizePolicy.setHeightForWidth(Name_Line->sizePolicy().hasHeightForWidth());
        Name_Line->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Name_Line);


        verticalLayout_2->addWidget(widget_2);

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


        verticalLayout_2->addWidget(widget_4);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_Addr = new QLabel(widget_6);
        label_Addr->setObjectName(QString::fromUtf8("label_Addr"));

        horizontalLayout_5->addWidget(label_Addr);

        Addr_Line = new QLabel(widget_6);
        Addr_Line->setObjectName(QString::fromUtf8("Addr_Line"));
        sizePolicy.setHeightForWidth(Addr_Line->sizePolicy().hasHeightForWidth());
        Addr_Line->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(Addr_Line);


        verticalLayout_2->addWidget(widget_6);

        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Balance_Line2 = new QLabel(widget_3);
        Balance_Line2->setObjectName(QString::fromUtf8("Balance_Line2"));

        horizontalLayout_3->addWidget(Balance_Line2);

        Blance_Line = new QLabel(widget_3);
        Blance_Line->setObjectName(QString::fromUtf8("Blance_Line"));
        sizePolicy.setHeightForWidth(Blance_Line->sizePolicy().hasHeightForWidth());
        Blance_Line->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Blance_Line);


        verticalLayout_2->addWidget(widget_3);

        widget_8 = new QWidget(widget_5);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_8->sizePolicy().hasHeightForWidth());
        widget_8->setSizePolicy(sizePolicy1);
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(widget_8);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(label_2);

        btn_Check = new QPushButton(widget_8);
        btn_Check->setObjectName(QString::fromUtf8("btn_Check"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_Check->sizePolicy().hasHeightForWidth());
        btn_Check->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(btn_Check);


        verticalLayout_2->addWidget(widget_8);


        verticalLayout->addWidget(widget_5);

        widget_7 = new QWidget(UserInfoWindow);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy3);
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(294, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        btn_Quit = new QPushButton(widget_7);
        btn_Quit->setObjectName(QString::fromUtf8("btn_Quit"));

        horizontalLayout_6->addWidget(btn_Quit);

        horizontalSpacer_2 = new QSpacerItem(293, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_7);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(UserInfoWindow);

        QMetaObject::connectSlotsByName(UserInfoWindow);
    } // setupUi

    void retranslateUi(QDialog *UserInfoWindow)
    {
        UserInfoWindow->setWindowTitle(QApplication::translate("UserInfoWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("UserInfoWindow", "\347\224\250\346\210\267\345\220\215:", nullptr));
        Username_Line->setText(QApplication::translate("UserInfoWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("UserInfoWindow", "\345\247\223\345\220\215:", nullptr));
        Name_Line->setText(QApplication::translate("UserInfoWindow", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("UserInfoWindow", "\346\211\213\346\234\272\345\217\267:", nullptr));
        PhoneNum_Line->setText(QApplication::translate("UserInfoWindow", "TextLabel", nullptr));
        label_Addr->setText(QApplication::translate("UserInfoWindow", "\345\234\260\345\235\200\357\274\232", nullptr));
        Addr_Line->setText(QApplication::translate("UserInfoWindow", "TextLabel", nullptr));
        Balance_Line2->setText(QApplication::translate("UserInfoWindow", "\344\275\231\351\242\235:", nullptr));
        Blance_Line->setText(QApplication::translate("UserInfoWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("UserInfoWindow", "\345\277\253\351\200\222:", nullptr));
        btn_Check->setText(QApplication::translate("UserInfoWindow", "\347\202\271\346\255\244\346\237\245\350\257\242", nullptr));
        btn_Quit->setText(QApplication::translate("UserInfoWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInfoWindow: public Ui_UserInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOWINDOW_H
