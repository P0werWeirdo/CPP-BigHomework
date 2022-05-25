/********************************************************************************
** Form generated from reading UI file 'packageinfowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKAGEINFOWINDOW_H
#define UI_PACKAGEINFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_PackageInfoWindow
{
public:

    void setupUi(QDialog *PackageInfoWindow)
    {
        if (PackageInfoWindow->objectName().isEmpty())
            PackageInfoWindow->setObjectName(QString::fromUtf8("PackageInfoWindow"));
        PackageInfoWindow->resize(400, 300);

        retranslateUi(PackageInfoWindow);

        QMetaObject::connectSlotsByName(PackageInfoWindow);
    } // setupUi

    void retranslateUi(QDialog *PackageInfoWindow)
    {
        PackageInfoWindow->setWindowTitle(QApplication::translate("PackageInfoWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PackageInfoWindow: public Ui_PackageInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKAGEINFOWINDOW_H
