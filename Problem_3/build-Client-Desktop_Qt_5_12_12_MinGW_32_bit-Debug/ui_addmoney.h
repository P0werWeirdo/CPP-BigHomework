/********************************************************************************
** Form generated from reading UI file 'addmoney.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMONEY_H
#define UI_ADDMONEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddMoney
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpinBox *MoneyNum;
    QPushButton *btn_Confirm;
    QLabel *Tips_Label;

    void setupUi(QDialog *AddMoney)
    {
        if (AddMoney->objectName().isEmpty())
            AddMoney->setObjectName(QString::fromUtf8("AddMoney"));
        AddMoney->resize(366, 167);
        verticalLayout = new QVBoxLayout(AddMoney);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(AddMoney);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        MoneyNum = new QSpinBox(widget);
        MoneyNum->setObjectName(QString::fromUtf8("MoneyNum"));
        MoneyNum->setMinimum(1);
        MoneyNum->setMaximum(50000);

        horizontalLayout->addWidget(MoneyNum);

        btn_Confirm = new QPushButton(widget);
        btn_Confirm->setObjectName(QString::fromUtf8("btn_Confirm"));

        horizontalLayout->addWidget(btn_Confirm);


        verticalLayout->addWidget(widget);

        Tips_Label = new QLabel(AddMoney);
        Tips_Label->setObjectName(QString::fromUtf8("Tips_Label"));
        Tips_Label->setEnabled(true);

        verticalLayout->addWidget(Tips_Label);


        retranslateUi(AddMoney);

        QMetaObject::connectSlotsByName(AddMoney);
    } // setupUi

    void retranslateUi(QDialog *AddMoney)
    {
        AddMoney->setWindowTitle(QApplication::translate("AddMoney", "Dialog", nullptr));
        btn_Confirm->setText(QApplication::translate("AddMoney", "\347\241\256\350\256\244", nullptr));
        Tips_Label->setText(QApplication::translate("AddMoney", "\350\257\267\350\276\223\345\205\2451-50000\350\214\203\345\233\264\345\206\205\347\232\204\346\225\264\346\225\260\345\200\274\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddMoney: public Ui_AddMoney {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMONEY_H
