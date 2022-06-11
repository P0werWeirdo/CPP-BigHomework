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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PackageInfoWindow
{
public:
    QPushButton *btn_Quit;
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
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *Balance_Line2_2;
    QLabel *PkgRemark;

    void setupUi(QDialog *PackageInfoWindow)
    {
        if (PackageInfoWindow->objectName().isEmpty())
            PackageInfoWindow->setObjectName(QString::fromUtf8("PackageInfoWindow"));
        PackageInfoWindow->resize(880, 579);
        btn_Quit = new QPushButton(PackageInfoWindow);
        btn_Quit->setObjectName(QString::fromUtf8("btn_Quit"));
        btn_Quit->setGeometry(QRect(720, 540, 93, 28));
        widget_5 = new QWidget(PackageInfoWindow);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(10, 10, 751, 521));
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


        retranslateUi(PackageInfoWindow);

        QMetaObject::connectSlotsByName(PackageInfoWindow);
    } // setupUi

    void retranslateUi(QDialog *PackageInfoWindow)
    {
        PackageInfoWindow->setWindowTitle(QApplication::translate("PackageInfoWindow", "Dialog", nullptr));
        btn_Quit->setText(QApplication::translate("PackageInfoWindow", "\351\200\200\345\207\272", nullptr));
        label->setText(QApplication::translate("PackageInfoWindow", "\345\277\253\351\200\222\345\215\225\345\217\267:", nullptr));
        Index_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("PackageInfoWindow", "\345\217\221\351\200\201\346\226\271\350\264\246\345\217\267:", nullptr));
        SenderUsername_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("PackageInfoWindow", "\345\217\221\351\200\201\346\226\271\345\247\223\345\220\215", nullptr));
        SenderName_Line->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("PackageInfoWindow", "\345\217\221\351\200\201\346\227\266\351\227\264\357\274\232", nullptr));
        SenderTime->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
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
        Balance_Line2_2->setText(QApplication::translate("PackageInfoWindow", "\347\211\251\345\223\201\346\217\217\350\277\260:", nullptr));
        PkgRemark->setText(QApplication::translate("PackageInfoWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PackageInfoWindow: public Ui_PackageInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKAGEINFOWINDOW_H
