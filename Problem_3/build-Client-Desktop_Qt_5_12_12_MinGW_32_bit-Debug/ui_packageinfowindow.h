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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PackageInfoWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *Index_Line;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *SenderUsername_Line;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLabel *SenderName_Line;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLabel *SenderTime;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_13;
    QLabel *CollectorUsername_Line;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_12;
    QLabel *CollectorName_Line;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_14;
    QLabel *CollectTime_Line;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *RecvUsername_Line;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QLabel *RecvName_Line;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLabel *RecvTime;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QLabel *Addr_Line;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Balance_Line2;
    QLabel *PkgStatus_Line;
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_15;
    QLabel *Balance_Line2_3;
    QLabel *PkgPrice;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *Balance_Line2_2;
    QLabel *PkgRemark;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Quit;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *PackageInfoWindow)
    {
        if (PackageInfoWindow->objectName().isEmpty())
            PackageInfoWindow->setObjectName(QString::fromUtf8("PackageInfoWindow"));
        PackageInfoWindow->resize(761, 782);
        verticalLayout_2 = new QVBoxLayout(PackageInfoWindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_5 = new QWidget(PackageInfoWindow);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout = new QVBoxLayout(widget_5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(widget_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        Index_Line = new QLabel(widget);
        Index_Line->setObjectName(QString::fromUtf8("Index_Line"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(20);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Index_Line->sizePolicy().hasHeightForWidth());
        Index_Line->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Index_Line);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        SenderUsername_Line = new QLabel(widget_2);
        SenderUsername_Line->setObjectName(QString::fromUtf8("SenderUsername_Line"));
        sizePolicy.setHeightForWidth(SenderUsername_Line->sizePolicy().hasHeightForWidth());
        SenderUsername_Line->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(SenderUsername_Line);


        verticalLayout->addWidget(widget_2);

        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(widget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        SenderName_Line = new QLabel(widget_4);
        SenderName_Line->setObjectName(QString::fromUtf8("SenderName_Line"));
        sizePolicy.setHeightForWidth(SenderName_Line->sizePolicy().hasHeightForWidth());
        SenderName_Line->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(SenderName_Line);


        verticalLayout->addWidget(widget_4);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        SenderTime = new QLabel(widget_6);
        SenderTime->setObjectName(QString::fromUtf8("SenderTime"));
        sizePolicy.setHeightForWidth(SenderTime->sizePolicy().hasHeightForWidth());
        SenderTime->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(SenderTime);


        verticalLayout->addWidget(widget_6);

        widget_13 = new QWidget(widget_5);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        horizontalLayout_12 = new QHBoxLayout(widget_13);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_13 = new QLabel(widget_13);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(label_13);

        CollectorUsername_Line = new QLabel(widget_13);
        CollectorUsername_Line->setObjectName(QString::fromUtf8("CollectorUsername_Line"));
        sizePolicy.setHeightForWidth(CollectorUsername_Line->sizePolicy().hasHeightForWidth());
        CollectorUsername_Line->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(CollectorUsername_Line);


        verticalLayout->addWidget(widget_13);

        widget_12 = new QWidget(widget_5);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_11 = new QHBoxLayout(widget_12);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_12 = new QLabel(widget_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(label_12);

        CollectorName_Line = new QLabel(widget_12);
        CollectorName_Line->setObjectName(QString::fromUtf8("CollectorName_Line"));
        sizePolicy.setHeightForWidth(CollectorName_Line->sizePolicy().hasHeightForWidth());
        CollectorName_Line->setSizePolicy(sizePolicy);

        horizontalLayout_11->addWidget(CollectorName_Line);


        verticalLayout->addWidget(widget_12);

        widget_14 = new QWidget(widget_5);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        horizontalLayout_13 = new QHBoxLayout(widget_14);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_14 = new QLabel(widget_14);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_13->addWidget(label_14);

        CollectTime_Line = new QLabel(widget_14);
        CollectTime_Line->setObjectName(QString::fromUtf8("CollectTime_Line"));
        sizePolicy.setHeightForWidth(CollectTime_Line->sizePolicy().hasHeightForWidth());
        CollectTime_Line->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(CollectTime_Line);


        verticalLayout->addWidget(widget_14);

        widget_7 = new QWidget(widget_5);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(widget_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        RecvUsername_Line = new QLabel(widget_7);
        RecvUsername_Line->setObjectName(QString::fromUtf8("RecvUsername_Line"));
        sizePolicy.setHeightForWidth(RecvUsername_Line->sizePolicy().hasHeightForWidth());
        RecvUsername_Line->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(RecvUsername_Line);


        verticalLayout->addWidget(widget_7);

        widget_9 = new QWidget(widget_5);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_8 = new QHBoxLayout(widget_9);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_10 = new QLabel(widget_9);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_8->addWidget(label_10);

        RecvName_Line = new QLabel(widget_9);
        RecvName_Line->setObjectName(QString::fromUtf8("RecvName_Line"));
        sizePolicy.setHeightForWidth(RecvName_Line->sizePolicy().hasHeightForWidth());
        RecvName_Line->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(RecvName_Line);


        verticalLayout->addWidget(widget_9);

        widget_8 = new QWidget(widget_5);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(widget_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        RecvTime = new QLabel(widget_8);
        RecvTime->setObjectName(QString::fromUtf8("RecvTime"));
        sizePolicy.setHeightForWidth(RecvTime->sizePolicy().hasHeightForWidth());
        RecvTime->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(RecvTime);


        verticalLayout->addWidget(widget_8);

        widget_11 = new QWidget(widget_5);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_10 = new QHBoxLayout(widget_11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_11 = new QLabel(widget_11);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_10->addWidget(label_11);

        Addr_Line = new QLabel(widget_11);
        Addr_Line->setObjectName(QString::fromUtf8("Addr_Line"));
        sizePolicy.setHeightForWidth(Addr_Line->sizePolicy().hasHeightForWidth());
        Addr_Line->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(Addr_Line);


        verticalLayout->addWidget(widget_11);

        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Balance_Line2 = new QLabel(widget_3);
        Balance_Line2->setObjectName(QString::fromUtf8("Balance_Line2"));

        horizontalLayout_3->addWidget(Balance_Line2);

        PkgStatus_Line = new QLabel(widget_3);
        PkgStatus_Line->setObjectName(QString::fromUtf8("PkgStatus_Line"));
        sizePolicy.setHeightForWidth(PkgStatus_Line->sizePolicy().hasHeightForWidth());
        PkgStatus_Line->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(PkgStatus_Line);


        verticalLayout->addWidget(widget_3);

        widget_16 = new QWidget(widget_5);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        horizontalLayout_15 = new QHBoxLayout(widget_16);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        Balance_Line2_3 = new QLabel(widget_16);
        Balance_Line2_3->setObjectName(QString::fromUtf8("Balance_Line2_3"));

        horizontalLayout_15->addWidget(Balance_Line2_3);

        PkgPrice = new QLabel(widget_16);
        PkgPrice->setObjectName(QString::fromUtf8("PkgPrice"));
        sizePolicy.setHeightForWidth(PkgPrice->sizePolicy().hasHeightForWidth());
        PkgPrice->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(PkgPrice);


        verticalLayout->addWidget(widget_16);

        widget_10 = new QWidget(widget_5);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_9 = new QHBoxLayout(widget_10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        Balance_Line2_2 = new QLabel(widget_10);
        Balance_Line2_2->setObjectName(QString::fromUtf8("Balance_Line2_2"));

        horizontalLayout_9->addWidget(Balance_Line2_2);

        PkgRemark = new QLabel(widget_10);
        PkgRemark->setObjectName(QString::fromUtf8("PkgRemark"));
        sizePolicy.setHeightForWidth(PkgRemark->sizePolicy().hasHeightForWidth());
        PkgRemark->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(PkgRemark);


        verticalLayout->addWidget(widget_10);


        verticalLayout_2->addWidget(widget_5);

        widget_15 = new QWidget(PackageInfoWindow);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_15->sizePolicy().hasHeightForWidth());
        widget_15->setSizePolicy(sizePolicy2);
        horizontalLayout_14 = new QHBoxLayout(widget_15);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer = new QSpacerItem(302, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);

        btn_Quit = new QPushButton(widget_15);
        btn_Quit->setObjectName(QString::fromUtf8("btn_Quit"));

        horizontalLayout_14->addWidget(btn_Quit);

        horizontalSpacer_2 = new QSpacerItem(302, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_15);


        retranslateUi(PackageInfoWindow);

        QMetaObject::connectSlotsByName(PackageInfoWindow);
    } // setupUi

    void retranslateUi(QDialog *PackageInfoWindow)
    {
        PackageInfoWindow->setWindowTitle(QApplication::translate("PackageInfoWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("PackageInfoWindow", "\345\277\253\351\200\222\345\215\225\345\217\267:", nullptr));
        Index_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("PackageInfoWindow", "\345\217\221\351\200\201\346\226\271\350\264\246\345\217\267:", nullptr));
        SenderUsername_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("PackageInfoWindow", "\345\217\221\351\200\201\346\226\271\345\247\223\345\220\215", nullptr));
        SenderName_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("PackageInfoWindow", "\345\217\221\351\200\201\346\227\266\351\227\264\357\274\232", nullptr));
        SenderTime->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_13->setText(QApplication::translate("PackageInfoWindow", "\345\277\253\351\200\222\345\221\230\350\264\246\345\217\267:", nullptr));
        CollectorUsername_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_12->setText(QApplication::translate("PackageInfoWindow", "\345\277\253\351\200\222\345\221\230\345\247\223\345\220\215:", nullptr));
        CollectorName_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_14->setText(QApplication::translate("PackageInfoWindow", "\346\217\275\346\224\266\346\227\266\351\227\264:", nullptr));
        CollectTime_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_8->setText(QApplication::translate("PackageInfoWindow", "\346\216\245\345\217\227\350\200\205\350\264\246\345\217\267\357\274\232", nullptr));
        RecvUsername_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_10->setText(QApplication::translate("PackageInfoWindow", "\346\216\245\346\224\266\350\200\205\345\247\223\345\220\215\357\274\232", nullptr));
        RecvName_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_9->setText(QApplication::translate("PackageInfoWindow", "\346\216\245\345\217\227\346\227\266\351\227\264\357\274\232", nullptr));
        RecvTime->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_11->setText(QApplication::translate("PackageInfoWindow", "\346\224\266\350\264\247\345\234\260\347\202\271\357\274\232", nullptr));
        Addr_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        Balance_Line2->setText(QApplication::translate("PackageInfoWindow", "\347\211\251\345\223\201\347\212\266\346\200\201:", nullptr));
        PkgStatus_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        Balance_Line2_3->setText(QApplication::translate("PackageInfoWindow", "\347\211\251\345\223\201\344\273\267\346\240\274:", nullptr));
        PkgPrice->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        Balance_Line2_2->setText(QApplication::translate("PackageInfoWindow", "\347\211\251\345\223\201\346\217\217\350\277\260:", nullptr));
        PkgRemark->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        btn_Quit->setText(QApplication::translate("PackageInfoWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PackageInfoWindow: public Ui_PackageInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKAGEINFOWINDOW_H
