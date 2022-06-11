/********************************************************************************
** Form generated from reading UI file 'courierwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURIERWINDOW_H
#define UI_COURIERWINDOW_H

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

class Ui_CourierWindow
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
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnChangePassword;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_Exit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_Collect;
    QPushButton *btn_Check;

    void setupUi(QDialog *CourierWindow)
    {
        if (CourierWindow->objectName().isEmpty())
            CourierWindow->setObjectName(QString::fromUtf8("CourierWindow"));
        CourierWindow->resize(729, 447);
        widget_5 = new QWidget(CourierWindow);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(20, 40, 411, 361));
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

        btn_Collect = new QPushButton(CourierWindow);
        btn_Collect->setObjectName(QString::fromUtf8("btn_Collect"));
        btn_Collect->setGeometry(QRect(510, 200, 161, 28));
        btn_Check = new QPushButton(CourierWindow);
        btn_Check->setObjectName(QString::fromUtf8("btn_Check"));
        btn_Check->setGeometry(QRect(510, 150, 161, 31));

        retranslateUi(CourierWindow);

        QMetaObject::connectSlotsByName(CourierWindow);
    } // setupUi

    void retranslateUi(QDialog *CourierWindow)
    {
        CourierWindow->setWindowTitle(QApplication::translate("CourierWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("CourierWindow", "\347\224\250\346\210\267\345\220\215:", nullptr));
        Username_Line->setText(QApplication::translate("CourierWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("CourierWindow", "\345\247\223\345\220\215:", nullptr));
        NameLine->setText(QApplication::translate("CourierWindow", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("CourierWindow", "\346\211\213\346\234\272\345\217\267:", nullptr));
        PhoneNum_Line->setText(QApplication::translate("CourierWindow", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("CourierWindow", "\344\275\231\351\242\235:", nullptr));
        Balance_Line->setText(QApplication::translate("CourierWindow", "TextLabel", nullptr));
        btnChangePassword->setText(QApplication::translate("CourierWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        btn_Exit->setText(QApplication::translate("CourierWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        btn_Collect->setText(QApplication::translate("CourierWindow", "\346\217\275\346\224\266\345\277\253\351\200\222", nullptr));
        btn_Check->setText(QApplication::translate("CourierWindow", "\346\237\245\347\234\213\350\207\252\345\267\261\347\232\204\345\277\253\351\200\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourierWindow: public Ui_CourierWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURIERWINDOW_H
