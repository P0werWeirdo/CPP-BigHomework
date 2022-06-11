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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PackageListWindow
{
public:
    QWidget *widget;
    QTableWidget *PkgListTb;
    QPushButton *btn_Default;
    QWidget *widget_4;
    QFormLayout *formLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QDateEdit *date_Date;
    QLineEdit *line_Search;
    QComboBox *box_Status;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QRadioButton *rb_Username;
    QRadioButton *rb_Index;
    QRadioButton *rb_Time;
    QRadioButton *rb_Status;
    QPushButton *btn_Search;

    void setupUi(QDialog *PackageListWindow)
    {
        if (PackageListWindow->objectName().isEmpty())
            PackageListWindow->setObjectName(QString::fromUtf8("PackageListWindow"));
        PackageListWindow->resize(748, 586);
        widget = new QWidget(PackageListWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 726, 564));
        PkgListTb = new QTableWidget(widget);
        PkgListTb->setObjectName(QString::fromUtf8("PkgListTb"));
        PkgListTb->setGeometry(QRect(20, 170, 521, 391));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(60);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(PkgListTb->sizePolicy().hasHeightForWidth());
        PkgListTb->setSizePolicy(sizePolicy);
        btn_Default = new QPushButton(widget);
        btn_Default->setObjectName(QString::fromUtf8("btn_Default"));
        btn_Default->setGeometry(QRect(580, 150, 101, 31));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(20, 0, 491, 161));
        formLayout = new QFormLayout(widget_4);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        date_Date = new QDateEdit(widget_2);
        date_Date->setObjectName(QString::fromUtf8("date_Date"));

        verticalLayout->addWidget(date_Date);

        line_Search = new QLineEdit(widget_2);
        line_Search->setObjectName(QString::fromUtf8("line_Search"));

        verticalLayout->addWidget(line_Search);

        box_Status = new QComboBox(widget_2);
        box_Status->addItem(QString());
        box_Status->addItem(QString());
        box_Status->addItem(QString());
        box_Status->setObjectName(QString::fromUtf8("box_Status"));

        verticalLayout->addWidget(box_Status);


        formLayout->setWidget(0, QFormLayout::LabelRole, widget_2);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        rb_Username = new QRadioButton(widget_3);
        rb_Username->setObjectName(QString::fromUtf8("rb_Username"));

        horizontalLayout_2->addWidget(rb_Username);

        rb_Index = new QRadioButton(widget_3);
        rb_Index->setObjectName(QString::fromUtf8("rb_Index"));

        horizontalLayout_2->addWidget(rb_Index);

        rb_Time = new QRadioButton(widget_3);
        rb_Time->setObjectName(QString::fromUtf8("rb_Time"));

        horizontalLayout_2->addWidget(rb_Time);

        rb_Status = new QRadioButton(widget_3);
        rb_Status->setObjectName(QString::fromUtf8("rb_Status"));

        horizontalLayout_2->addWidget(rb_Status);


        formLayout->setWidget(1, QFormLayout::SpanningRole, widget_3);

        btn_Search = new QPushButton(widget_4);
        btn_Search->setObjectName(QString::fromUtf8("btn_Search"));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_Search);


        retranslateUi(PackageListWindow);

        QMetaObject::connectSlotsByName(PackageListWindow);
    } // setupUi

    void retranslateUi(QDialog *PackageListWindow)
    {
        PackageListWindow->setWindowTitle(QApplication::translate("PackageListWindow", "Dialog", nullptr));
        btn_Default->setText(QApplication::translate("PackageListWindow", "\346\230\276\347\244\272\345\205\250\351\203\250\345\277\253\351\200\222", nullptr));
        box_Status->setItemText(0, QApplication::translate("PackageListWindow", "\345\276\205\347\255\276\346\224\266", nullptr));
        box_Status->setItemText(1, QApplication::translate("PackageListWindow", "\345\267\262\347\255\276\346\224\266", nullptr));
        box_Status->setItemText(2, QApplication::translate("PackageListWindow", "\345\276\205\346\217\275\346\224\266", nullptr));

        label->setText(QApplication::translate("PackageListWindow", "\346\237\245\350\257\242\346\226\271\345\274\217\357\274\232", nullptr));
        rb_Username->setText(QApplication::translate("PackageListWindow", "\350\264\246\345\217\267", nullptr));
        rb_Index->setText(QApplication::translate("PackageListWindow", "\345\277\253\351\200\222\345\215\225\345\217\267", nullptr));
        rb_Time->setText(QApplication::translate("PackageListWindow", "\346\227\266\351\227\264", nullptr));
        rb_Status->setText(QApplication::translate("PackageListWindow", "\345\277\253\351\200\222\347\212\266\346\200\201", nullptr));
        btn_Search->setText(QApplication::translate("PackageListWindow", "\346\237\245\346\211\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PackageListWindow: public Ui_PackageListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKAGELISTWINDOW_H
