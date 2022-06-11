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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInfoWindow
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
    QLabel *Name_Line;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLabel *PhoneNum_Line;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLabel *Addr_Line;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Balance_Line2;
    QLabel *Blance_Line;
    QPushButton *btn_Quit;

    void setupUi(QDialog *UserInfoWindow)
    {
        if (UserInfoWindow->objectName().isEmpty())
            UserInfoWindow->setObjectName(QString::fromUtf8("UserInfoWindow"));
        UserInfoWindow->resize(744, 456);
        widget_5 = new QWidget(UserInfoWindow);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(10, 20, 701, 371));
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

        Name_Line = new QLabel(widget_2);
        Name_Line->setObjectName(QString::fromUtf8("Name_Line"));
        sizePolicy.setHeightForWidth(Name_Line->sizePolicy().hasHeightForWidth());
        Name_Line->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Name_Line);


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

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        Addr_Line = new QLabel(widget_6);
        Addr_Line->setObjectName(QString::fromUtf8("Addr_Line"));
        sizePolicy.setHeightForWidth(Addr_Line->sizePolicy().hasHeightForWidth());
        Addr_Line->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(Addr_Line);


        verticalLayout->addWidget(widget_6);

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


        verticalLayout->addWidget(widget_3);

        btn_Quit = new QPushButton(UserInfoWindow);
        btn_Quit->setObjectName(QString::fromUtf8("btn_Quit"));
        btn_Quit->setGeometry(QRect(190, 410, 93, 28));

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
        label_6->setText(QApplication::translate("UserInfoWindow", "\345\234\260\345\235\200\357\274\232", nullptr));
        Addr_Line->setText(QApplication::translate("UserInfoWindow", "TextLabel", nullptr));
        Balance_Line2->setText(QApplication::translate("UserInfoWindow", "\344\275\231\351\242\235:", nullptr));
        Blance_Line->setText(QApplication::translate("UserInfoWindow", "TextLabel", nullptr));
        btn_Quit->setText(QApplication::translate("UserInfoWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInfoWindow: public Ui_UserInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOWINDOW_H
