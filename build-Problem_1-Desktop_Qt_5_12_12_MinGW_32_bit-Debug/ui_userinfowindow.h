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

QT_BEGIN_NAMESPACE

class Ui_UserInfoWindow
{
public:

    void setupUi(QDialog *UserInfoWindow)
    {
        if (UserInfoWindow->objectName().isEmpty())
            UserInfoWindow->setObjectName(QString::fromUtf8("UserInfoWindow"));
        UserInfoWindow->resize(400, 300);

        retranslateUi(UserInfoWindow);

        QMetaObject::connectSlotsByName(UserInfoWindow);
    } // setupUi

    void retranslateUi(QDialog *UserInfoWindow)
    {
        UserInfoWindow->setWindowTitle(QApplication::translate("UserInfoWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInfoWindow: public Ui_UserInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOWINDOW_H
