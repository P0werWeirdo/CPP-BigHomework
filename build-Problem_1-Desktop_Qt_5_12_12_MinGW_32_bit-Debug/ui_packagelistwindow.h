/********************************************************************************
** Form generated from reading UI file 'packagelistwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKAGELISTWINDOW_H
#define UI_PACKAGELISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PackageListWindow
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QTableWidget *PkgListTb;
    QPushButton *pushButton_3;

    void setupUi(QDialog *PackageListWindow)
    {
        if (PackageListWindow->objectName().isEmpty())
            PackageListWindow->setObjectName(QString::fromUtf8("PackageListWindow"));
        PackageListWindow->resize(644, 479);
        gridLayout_2 = new QGridLayout(PackageListWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(PackageListWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        PkgListTb = new QTableWidget(widget);
        PkgListTb->setObjectName(QString::fromUtf8("PkgListTb"));
        PkgListTb->setGeometry(QRect(11, 11, 511, 431));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(60);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(PkgListTb->sizePolicy().hasHeightForWidth());
        PkgListTb->setSizePolicy(sizePolicy);
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 230, 93, 28));

        gridLayout_2->addWidget(widget, 0, 0, 2, 1);


        retranslateUi(PackageListWindow);

        QMetaObject::connectSlotsByName(PackageListWindow);
    } // setupUi

    void retranslateUi(QDialog *PackageListWindow)
    {
        PackageListWindow->setWindowTitle(QApplication::translate("PackageListWindow", "Dialog", nullptr));
        pushButton_3->setText(QApplication::translate("PackageListWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PackageListWindow: public Ui_PackageListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKAGELISTWINDOW_H
