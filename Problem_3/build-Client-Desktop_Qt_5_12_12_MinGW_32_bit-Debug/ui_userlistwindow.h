/********************************************************************************
** Form generated from reading UI file 'userlistwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLISTWINDOW_H
#define UI_USERLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserListWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *ClientListTb;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_del;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *UserListWindow)
    {
        if (UserListWindow->objectName().isEmpty())
            UserListWindow->setObjectName(QString::fromUtf8("UserListWindow"));
        UserListWindow->resize(544, 557);
        verticalLayout = new QVBoxLayout(UserListWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ClientListTb = new QTableWidget(UserListWindow);
        ClientListTb->setObjectName(QString::fromUtf8("ClientListTb"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(20);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(ClientListTb->sizePolicy().hasHeightForWidth());
        ClientListTb->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(ClientListTb);

        widget = new QWidget(UserListWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(194, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_del = new QPushButton(widget);
        btn_del->setObjectName(QString::fromUtf8("btn_del"));

        horizontalLayout->addWidget(btn_del);

        horizontalSpacer_2 = new QSpacerItem(193, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(UserListWindow);

        QMetaObject::connectSlotsByName(UserListWindow);
    } // setupUi

    void retranslateUi(QDialog *UserListWindow)
    {
        UserListWindow->setWindowTitle(QApplication::translate("UserListWindow", "Dialog", nullptr));
        btn_del->setText(QApplication::translate("UserListWindow", "\345\210\240\351\231\244\346\255\244\344\272\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserListWindow: public Ui_UserListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLISTWINDOW_H
