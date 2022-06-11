/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePassword
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *oldPassword;
    QLabel *label_2;
    QLineEdit *newPassword;
    QLabel *label_3;
    QLineEdit *newPassword2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_Confirm;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Cancel;

    void setupUi(QWidget *ChangePassword)
    {
        if (ChangePassword->objectName().isEmpty())
            ChangePassword->setObjectName(QString::fromUtf8("ChangePassword"));
        ChangePassword->resize(364, 245);
        verticalLayout = new QVBoxLayout(ChangePassword);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(ChangePassword);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        formLayout = new QFormLayout(widget_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        oldPassword = new QLineEdit(widget_2);
        oldPassword->setObjectName(QString::fromUtf8("oldPassword"));
        oldPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(0, QFormLayout::FieldRole, oldPassword);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        newPassword = new QLineEdit(widget_2);
        newPassword->setObjectName(QString::fromUtf8("newPassword"));
        newPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, newPassword);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        newPassword2 = new QLineEdit(widget_2);
        newPassword2->setObjectName(QString::fromUtf8("newPassword2"));
        newPassword2->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(4, QFormLayout::FieldRole, newPassword2);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(ChangePassword);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_Confirm = new QPushButton(widget);
        btn_Confirm->setObjectName(QString::fromUtf8("btn_Confirm"));

        horizontalLayout->addWidget(btn_Confirm);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_Cancel = new QPushButton(widget);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));

        horizontalLayout->addWidget(btn_Cancel);


        verticalLayout->addWidget(widget);


        retranslateUi(ChangePassword);

        QMetaObject::connectSlotsByName(ChangePassword);
    } // setupUi

    void retranslateUi(QWidget *ChangePassword)
    {
        ChangePassword->setWindowTitle(QApplication::translate("ChangePassword", "Form", nullptr));
        label->setText(QApplication::translate("ChangePassword", "\345\216\237\345\257\206\347\240\201:", nullptr));
        label_2->setText(QApplication::translate("ChangePassword", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QApplication::translate("ChangePassword", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        btn_Confirm->setText(QApplication::translate("ChangePassword", "\347\241\256\350\256\244", nullptr));
        btn_Cancel->setText(QApplication::translate("ChangePassword", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePassword: public Ui_ChangePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
