/********************************************************************************
** Form generated from reading UI file 'distributewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISTRIBUTEWINDOW_H
#define UI_DISTRIBUTEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DistributeWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineUsername;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *nameLabel;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *phoneLabel;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Confirm;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DistributeWindow)
    {
        if (DistributeWindow->objectName().isEmpty())
            DistributeWindow->setObjectName(QString::fromUtf8("DistributeWindow"));
        DistributeWindow->resize(365, 259);
        verticalLayout_2 = new QVBoxLayout(DistributeWindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(DistributeWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        lineUsername = new QLineEdit(widget_2);
        lineUsername->setObjectName(QString::fromUtf8("lineUsername"));

        horizontalLayout->addWidget(lineUsername);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_2);

        nameLabel = new QLabel(widget_3);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout_2->addWidget(nameLabel);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_3);

        phoneLabel = new QLabel(widget_4);
        phoneLabel->setObjectName(QString::fromUtf8("phoneLabel"));

        horizontalLayout_3->addWidget(phoneLabel);


        verticalLayout->addWidget(widget_4);


        verticalLayout_2->addWidget(widget);

        widget_5 = new QWidget(DistributeWindow);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(104, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btn_Confirm = new QPushButton(widget_5);
        btn_Confirm->setObjectName(QString::fromUtf8("btn_Confirm"));

        horizontalLayout_4->addWidget(btn_Confirm);

        horizontalSpacer_2 = new QSpacerItem(104, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_5);


        retranslateUi(DistributeWindow);

        QMetaObject::connectSlotsByName(DistributeWindow);
    } // setupUi

    void retranslateUi(QDialog *DistributeWindow)
    {
        DistributeWindow->setWindowTitle(QApplication::translate("DistributeWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("DistributeWindow", "\345\277\253\351\200\222\345\221\230\350\264\246\345\217\267:", nullptr));
        label_2->setText(QApplication::translate("DistributeWindow", "\345\277\253\351\200\222\345\221\230\345\247\223\345\220\215:", nullptr));
        nameLabel->setText(QApplication::translate("DistributeWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("DistributeWindow", "\345\277\253\351\200\222\345\221\230\347\224\265\350\257\235:", nullptr));
        phoneLabel->setText(QApplication::translate("DistributeWindow", "TextLabel", nullptr));
        btn_Confirm->setText(QApplication::translate("DistributeWindow", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DistributeWindow: public Ui_DistributeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISTRIBUTEWINDOW_H
