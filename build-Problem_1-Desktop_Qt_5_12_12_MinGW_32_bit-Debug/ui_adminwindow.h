/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
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
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *Balance_Line;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_ChangePassword;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_Exit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_SearchPkg;
    QPushButton *btn_SearchUser;

    void setupUi(QWidget *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->resize(946, 476);
        widget_5 = new QWidget(AdminWindow);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(0, 0, 391, 331));
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

        btn_ChangePassword = new QPushButton(widget_6);
        btn_ChangePassword->setObjectName(QString::fromUtf8("btn_ChangePassword"));

        horizontalLayout_5->addWidget(btn_ChangePassword);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btn_Exit = new QPushButton(widget_6);
        btn_Exit->setObjectName(QString::fromUtf8("btn_Exit"));

        horizontalLayout_5->addWidget(btn_Exit);

        horizontalSpacer_3 = new QSpacerItem(41, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_6);

        btn_SearchPkg = new QPushButton(AdminWindow);
        btn_SearchPkg->setObjectName(QString::fromUtf8("btn_SearchPkg"));
        btn_SearchPkg->setGeometry(QRect(440, 140, 131, 31));
        btn_SearchUser = new QPushButton(AdminWindow);
        btn_SearchUser->setObjectName(QString::fromUtf8("btn_SearchUser"));
        btn_SearchUser->setGeometry(QRect(600, 140, 141, 31));

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QWidget *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "Form", nullptr));
        label->setText(QApplication::translate("AdminWindow", "\347\224\250\346\210\267\345\220\215:", nullptr));
        Username_Line->setText(QApplication::translate("AdminWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("AdminWindow", "\345\247\223\345\220\215:", nullptr));
        Name_Line->setText(QApplication::translate("AdminWindow", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("AdminWindow", "\346\211\213\346\234\272\345\217\267:", nullptr));
        PhoneNum_Line->setText(QApplication::translate("AdminWindow", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("AdminWindow", "\344\275\231\351\242\235:", nullptr));
        Balance_Line->setText(QApplication::translate("AdminWindow", "TextLabel", nullptr));
        btn_ChangePassword->setText(QApplication::translate("AdminWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        btn_Exit->setText(QApplication::translate("AdminWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        btn_SearchPkg->setText(QApplication::translate("AdminWindow", "\346\237\245\350\257\242\345\277\253\351\200\222\344\277\241\346\201\257", nullptr));
        btn_SearchUser->setText(QApplication::translate("AdminWindow", "\346\237\245\350\257\242\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
