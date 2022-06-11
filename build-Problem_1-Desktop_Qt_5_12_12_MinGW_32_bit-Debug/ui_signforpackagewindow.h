/********************************************************************************
** Form generated from reading UI file 'signforpackagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNFORPACKAGEWINDOW_H
#define UI_SIGNFORPACKAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SignForPackageWindow
{
public:
    QTableWidget *PkgListTb;
    QPushButton *btn_Sign;

    void setupUi(QDialog *SignForPackageWindow)
    {
        if (SignForPackageWindow->objectName().isEmpty())
            SignForPackageWindow->setObjectName(QString::fromUtf8("SignForPackageWindow"));
        SignForPackageWindow->resize(801, 573);
        PkgListTb = new QTableWidget(SignForPackageWindow);
        PkgListTb->setObjectName(QString::fromUtf8("PkgListTb"));
        PkgListTb->setGeometry(QRect(10, 30, 591, 511));
        btn_Sign = new QPushButton(SignForPackageWindow);
        btn_Sign->setObjectName(QString::fromUtf8("btn_Sign"));
        btn_Sign->setGeometry(QRect(640, 160, 93, 28));

        retranslateUi(SignForPackageWindow);

        QMetaObject::connectSlotsByName(SignForPackageWindow);
    } // setupUi

    void retranslateUi(QDialog *SignForPackageWindow)
    {
        SignForPackageWindow->setWindowTitle(QApplication::translate("SignForPackageWindow", "Dialog", nullptr));
        btn_Sign->setText(QApplication::translate("SignForPackageWindow", "\345\205\250\351\203\250\347\255\276\346\224\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignForPackageWindow: public Ui_SignForPackageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNFORPACKAGEWINDOW_H
