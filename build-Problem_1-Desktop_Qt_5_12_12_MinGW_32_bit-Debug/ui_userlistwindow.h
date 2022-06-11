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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_UserListWindow
{
public:
    QTableWidget *ClientListTb;

    void setupUi(QDialog *UserListWindow)
    {
        if (UserListWindow->objectName().isEmpty())
            UserListWindow->setObjectName(QString::fromUtf8("UserListWindow"));
        UserListWindow->resize(542, 366);
        ClientListTb = new QTableWidget(UserListWindow);
        ClientListTb->setObjectName(QString::fromUtf8("ClientListTb"));
        ClientListTb->setGeometry(QRect(11, 11, 521, 341));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(20);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(ClientListTb->sizePolicy().hasHeightForWidth());
        ClientListTb->setSizePolicy(sizePolicy);

        retranslateUi(UserListWindow);

        QMetaObject::connectSlotsByName(UserListWindow);
    } // setupUi

    void retranslateUi(QDialog *UserListWindow)
    {
        UserListWindow->setWindowTitle(QApplication::translate("UserListWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserListWindow: public Ui_UserListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLISTWINDOW_H
