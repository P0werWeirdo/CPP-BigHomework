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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserListWindow
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tb;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *UserListWindow)
    {
        if (UserListWindow->objectName().isEmpty())
            UserListWindow->setObjectName(QString::fromUtf8("UserListWindow"));
        UserListWindow->resize(542, 366);
        gridLayout = new QGridLayout(UserListWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(61, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        widget = new QWidget(UserListWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tb = new QTableWidget(widget);
        tb->setObjectName(QString::fromUtf8("tb"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(20);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(tb->sizePolicy().hasHeightForWidth());
        tb->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(tb);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addWidget(widget, 1, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(61, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(UserListWindow);

        QMetaObject::connectSlotsByName(UserListWindow);
    } // setupUi

    void retranslateUi(QDialog *UserListWindow)
    {
        UserListWindow->setWindowTitle(QApplication::translate("UserListWindow", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("UserListWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserListWindow: public Ui_UserListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLISTWINDOW_H
