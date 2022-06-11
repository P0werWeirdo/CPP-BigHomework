/********************************************************************************
** Form generated from reading UI file 'sendpackagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDPACKAGEWINDOW_H
#define UI_SENDPACKAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SendPackageWindow
{
public:
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_17;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget_18;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_16;
    QWidget *widget_19;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_13;
    QLabel *Index_label;
    QSpacerItem *horizontalSpacer_18;
    QWidget *widget_20;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_19;
    QWidget *widget_21;
    QHBoxLayout *horizontalLayout;
    QLabel *label_14;
    QLabel *SenderUsername_Label;
    QSpacerItem *horizontalSpacer_20;
    QWidget *widget_22;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_21;
    QLabel *label_15;
    QLabel *SenderName_Label;
    QSpacerItem *horizontalSpacer_22;
    QWidget *widget_29;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_33;
    QLabel *label_20;
    QLabel *SenderPhoneNum_Label;
    QSpacerItem *horizontalSpacer_34;
    QWidget *widget_31;
    QHBoxLayout *horizontalLayout_23;
    QSpacerItem *horizontalSpacer_37;
    QWidget *widget_32;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_22;
    QComboBox *typeOfPkg;
    QSpacerItem *horizontalSpacer_38;
    QWidget *widget_48;
    QHBoxLayout *horizontalLayout_41;
    QSpacerItem *horizontalSpacer_64;
    QWidget *widget_51;
    QHBoxLayout *horizontalLayout_42;
    QLabel *label_35;
    QDoubleSpinBox *numberOfPkg;
    QSpacerItem *horizontalSpacer_65;
    QWidget *widget_24;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer_23;
    QWidget *widget_25;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_16;
    QLineEdit *RecvUserName_Line;
    QSpacerItem *horizontalSpacer_24;
    QWidget *widget_26;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_29;
    QLabel *label_18;
    QLabel *RecvName_Label;
    QSpacerItem *horizontalSpacer_30;
    QWidget *widget_27;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_31;
    QLabel *label_19;
    QLabel *RecvPhoneNum_Label;
    QSpacerItem *horizontalSpacer_32;
    QWidget *widget_23;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_25;
    QLabel *label_17;
    QLabel *RecvAddr_Label;
    QSpacerItem *horizontalSpacer_26;
    QWidget *widget_30;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_35;
    QLabel *label_21;
    QPlainTextEdit *remark_Edit;
    QSpacerItem *horizontalSpacer_36;
    QLabel *Input_Error_2;
    QLabel *Price_Label;
    QWidget *widget_28;
    QHBoxLayout *horizontalLayout_24;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_Confirm_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_Cancel_2;
    QSpacerItem *horizontalSpacer_27;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_28;

    void setupUi(QDialog *SendPackageWindow)
    {
        if (SendPackageWindow->objectName().isEmpty())
            SendPackageWindow->setObjectName(QString::fromUtf8("SendPackageWindow"));
        SendPackageWindow->resize(865, 1126);
        gridLayout_3 = new QGridLayout(SendPackageWindow);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_17 = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_17, 0, 2, 1, 1);

        widget_7 = new QWidget(SendPackageWindow);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_2 = new QVBoxLayout(widget_7);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        widget_3 = new QWidget(widget_7);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_18 = new QWidget(widget_3);
        widget_18->setObjectName(QString::fromUtf8("widget_18"));
        horizontalLayout_15 = new QHBoxLayout(widget_18);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalSpacer_16 = new QSpacerItem(75, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_16);

        widget_19 = new QWidget(widget_18);
        widget_19->setObjectName(QString::fromUtf8("widget_19"));
        horizontalLayout_16 = new QHBoxLayout(widget_19);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_13 = new QLabel(widget_19);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);

        horizontalLayout_16->addWidget(label_13);

        Index_label = new QLabel(widget_19);
        Index_label->setObjectName(QString::fromUtf8("Index_label"));

        horizontalLayout_16->addWidget(Index_label);


        horizontalLayout_15->addWidget(widget_19);

        horizontalSpacer_18 = new QSpacerItem(74, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_18);


        verticalLayout->addWidget(widget_18);

        widget_20 = new QWidget(widget_3);
        widget_20->setObjectName(QString::fromUtf8("widget_20"));
        horizontalLayout_17 = new QHBoxLayout(widget_20);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalSpacer_19 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_19);

        widget_21 = new QWidget(widget_20);
        widget_21->setObjectName(QString::fromUtf8("widget_21"));
        horizontalLayout = new QHBoxLayout(widget_21);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_14 = new QLabel(widget_21);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_14);

        SenderUsername_Label = new QLabel(widget_21);
        SenderUsername_Label->setObjectName(QString::fromUtf8("SenderUsername_Label"));

        horizontalLayout->addWidget(SenderUsername_Label);


        horizontalLayout_17->addWidget(widget_21);

        horizontalSpacer_20 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_20);


        verticalLayout->addWidget(widget_20);

        widget_22 = new QWidget(widget_3);
        widget_22->setObjectName(QString::fromUtf8("widget_22"));
        horizontalLayout_2 = new QHBoxLayout(widget_22);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_21 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_21);

        label_15 = new QLabel(widget_22);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_15);

        SenderName_Label = new QLabel(widget_22);
        SenderName_Label->setObjectName(QString::fromUtf8("SenderName_Label"));

        horizontalLayout_2->addWidget(SenderName_Label);

        horizontalSpacer_22 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_22);


        verticalLayout->addWidget(widget_22);

        widget_29 = new QWidget(widget_3);
        widget_29->setObjectName(QString::fromUtf8("widget_29"));
        horizontalLayout_20 = new QHBoxLayout(widget_29);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalSpacer_33 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_33);

        label_20 = new QLabel(widget_29);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);

        horizontalLayout_20->addWidget(label_20);

        SenderPhoneNum_Label = new QLabel(widget_29);
        SenderPhoneNum_Label->setObjectName(QString::fromUtf8("SenderPhoneNum_Label"));

        horizontalLayout_20->addWidget(SenderPhoneNum_Label);

        horizontalSpacer_34 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_34);


        verticalLayout->addWidget(widget_29);

        widget_31 = new QWidget(widget_3);
        widget_31->setObjectName(QString::fromUtf8("widget_31"));
        horizontalLayout_23 = new QHBoxLayout(widget_31);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalSpacer_37 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_37);

        widget_32 = new QWidget(widget_31);
        widget_32->setObjectName(QString::fromUtf8("widget_32"));
        horizontalLayout_25 = new QHBoxLayout(widget_32);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_22 = new QLabel(widget_32);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_25->addWidget(label_22);

        typeOfPkg = new QComboBox(widget_32);
        typeOfPkg->addItem(QString());
        typeOfPkg->addItem(QString());
        typeOfPkg->addItem(QString());
        typeOfPkg->setObjectName(QString::fromUtf8("typeOfPkg"));

        horizontalLayout_25->addWidget(typeOfPkg);


        horizontalLayout_23->addWidget(widget_32);

        horizontalSpacer_38 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_38);


        verticalLayout->addWidget(widget_31);

        widget_48 = new QWidget(widget_3);
        widget_48->setObjectName(QString::fromUtf8("widget_48"));
        horizontalLayout_41 = new QHBoxLayout(widget_48);
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        horizontalSpacer_64 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_64);

        widget_51 = new QWidget(widget_48);
        widget_51->setObjectName(QString::fromUtf8("widget_51"));
        horizontalLayout_42 = new QHBoxLayout(widget_51);
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        label_35 = new QLabel(widget_51);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_42->addWidget(label_35);

        numberOfPkg = new QDoubleSpinBox(widget_51);
        numberOfPkg->setObjectName(QString::fromUtf8("numberOfPkg"));
        numberOfPkg->setDecimals(0);
        numberOfPkg->setMinimum(1.000000000000000);
        numberOfPkg->setMaximum(99.000000000000000);
        numberOfPkg->setSingleStep(1.000000000000000);

        horizontalLayout_42->addWidget(numberOfPkg);


        horizontalLayout_41->addWidget(widget_51);

        horizontalSpacer_65 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_65);


        verticalLayout->addWidget(widget_48);

        widget_24 = new QWidget(widget_3);
        widget_24->setObjectName(QString::fromUtf8("widget_24"));
        horizontalLayout_21 = new QHBoxLayout(widget_24);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        horizontalSpacer_23 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_23);

        widget_25 = new QWidget(widget_24);
        widget_25->setObjectName(QString::fromUtf8("widget_25"));
        horizontalLayout_22 = new QHBoxLayout(widget_25);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_16 = new QLabel(widget_25);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_22->addWidget(label_16);

        RecvUserName_Line = new QLineEdit(widget_25);
        RecvUserName_Line->setObjectName(QString::fromUtf8("RecvUserName_Line"));

        horizontalLayout_22->addWidget(RecvUserName_Line);


        horizontalLayout_21->addWidget(widget_25);

        horizontalSpacer_24 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_24);


        verticalLayout->addWidget(widget_24);

        widget_26 = new QWidget(widget_3);
        widget_26->setObjectName(QString::fromUtf8("widget_26"));
        horizontalLayout_18 = new QHBoxLayout(widget_26);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalSpacer_29 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_29);

        label_18 = new QLabel(widget_26);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_18->addWidget(label_18);

        RecvName_Label = new QLabel(widget_26);
        RecvName_Label->setObjectName(QString::fromUtf8("RecvName_Label"));

        horizontalLayout_18->addWidget(RecvName_Label);

        horizontalSpacer_30 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_30);


        verticalLayout->addWidget(widget_26);

        widget_27 = new QWidget(widget_3);
        widget_27->setObjectName(QString::fromUtf8("widget_27"));
        horizontalLayout_19 = new QHBoxLayout(widget_27);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalSpacer_31 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_31);

        label_19 = new QLabel(widget_27);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_19->addWidget(label_19);

        RecvPhoneNum_Label = new QLabel(widget_27);
        RecvPhoneNum_Label->setObjectName(QString::fromUtf8("RecvPhoneNum_Label"));

        horizontalLayout_19->addWidget(RecvPhoneNum_Label);

        horizontalSpacer_32 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_32);


        verticalLayout->addWidget(widget_27);

        widget_23 = new QWidget(widget_3);
        widget_23->setObjectName(QString::fromUtf8("widget_23"));
        horizontalLayout_6 = new QHBoxLayout(widget_23);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_25 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_25);

        label_17 = new QLabel(widget_23);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_6->addWidget(label_17);

        RecvAddr_Label = new QLabel(widget_23);
        RecvAddr_Label->setObjectName(QString::fromUtf8("RecvAddr_Label"));

        horizontalLayout_6->addWidget(RecvAddr_Label);

        horizontalSpacer_26 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_26);


        verticalLayout->addWidget(widget_23);

        widget_30 = new QWidget(widget_3);
        widget_30->setObjectName(QString::fromUtf8("widget_30"));
        horizontalLayout_7 = new QHBoxLayout(widget_30);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_35 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_35);

        label_21 = new QLabel(widget_30);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_7->addWidget(label_21);

        remark_Edit = new QPlainTextEdit(widget_30);
        remark_Edit->setObjectName(QString::fromUtf8("remark_Edit"));

        horizontalLayout_7->addWidget(remark_Edit);

        horizontalSpacer_36 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_36);


        verticalLayout->addWidget(widget_30);

        Input_Error_2 = new QLabel(widget_3);
        Input_Error_2->setObjectName(QString::fromUtf8("Input_Error_2"));
        Input_Error_2->setEnabled(true);

        verticalLayout->addWidget(Input_Error_2);

        Price_Label = new QLabel(widget_3);
        Price_Label->setObjectName(QString::fromUtf8("Price_Label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(20);
        sizePolicy1.setHeightForWidth(Price_Label->sizePolicy().hasHeightForWidth());
        Price_Label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(20);
        Price_Label->setFont(font);
        Price_Label->setFrameShape(QFrame::NoFrame);
        Price_Label->setFrameShadow(QFrame::Plain);

        verticalLayout->addWidget(Price_Label);

        widget_28 = new QWidget(widget_3);
        widget_28->setObjectName(QString::fromUtf8("widget_28"));
        horizontalLayout_24 = new QHBoxLayout(widget_28);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalSpacer_4 = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_4);

        btn_Confirm_2 = new QPushButton(widget_28);
        btn_Confirm_2->setObjectName(QString::fromUtf8("btn_Confirm_2"));

        horizontalLayout_24->addWidget(btn_Confirm_2);

        horizontalSpacer_5 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_5);

        btn_Cancel_2 = new QPushButton(widget_28);
        btn_Cancel_2->setObjectName(QString::fromUtf8("btn_Cancel_2"));

        horizontalLayout_24->addWidget(btn_Cancel_2);

        horizontalSpacer_27 = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_27);


        verticalLayout->addWidget(widget_28);


        verticalLayout_2->addWidget(widget_3);

        verticalSpacer_6 = new QSpacerItem(516, 9, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);


        gridLayout_3->addWidget(widget_7, 0, 1, 1, 1);

        horizontalSpacer_28 = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_28, 0, 0, 1, 1);


        retranslateUi(SendPackageWindow);

        QMetaObject::connectSlotsByName(SendPackageWindow);
    } // setupUi

    void retranslateUi(QDialog *SendPackageWindow)
    {
        SendPackageWindow->setWindowTitle(QApplication::translate("SendPackageWindow", "Dialog", nullptr));
        label_13->setText(QApplication::translate("SendPackageWindow", "\345\277\253\351\200\222\345\215\225\345\217\267\357\274\232", nullptr));
        Index_label->setText(QApplication::translate("SendPackageWindow", "TextLabel", nullptr));
        label_14->setText(QApplication::translate("SendPackageWindow", "\345\217\221\351\200\201\346\226\271\350\264\246\345\217\267\357\274\232", nullptr));
        SenderUsername_Label->setText(QApplication::translate("SendPackageWindow", "TextLabel", nullptr));
        label_15->setText(QApplication::translate("SendPackageWindow", "\345\217\221\351\200\201\346\226\271\345\247\223\345\220\215\357\274\232", nullptr));
        SenderName_Label->setText(QApplication::translate("SendPackageWindow", "TextLabel", nullptr));
        label_20->setText(QApplication::translate("SendPackageWindow", "\345\217\221\351\200\201\346\226\271\347\224\265\350\257\235\357\274\232", nullptr));
        SenderPhoneNum_Label->setText(QApplication::translate("SendPackageWindow", "TextLabel", nullptr));
        label_22->setText(QApplication::translate("SendPackageWindow", "\347\211\251\345\223\201\347\261\273\345\236\213\357\274\232", nullptr));
        typeOfPkg->setItemText(0, QApplication::translate("SendPackageWindow", "\346\230\223\347\242\216\345\223\201", nullptr));
        typeOfPkg->setItemText(1, QApplication::translate("SendPackageWindow", "\345\233\276\344\271\246", nullptr));
        typeOfPkg->setItemText(2, QApplication::translate("SendPackageWindow", "\346\231\256\351\200\232\347\211\251\345\223\201", nullptr));

        label_35->setText(QApplication::translate("SendPackageWindow", "\347\211\251\345\223\201\346\225\260\351\207\217\357\274\232", nullptr));
        label_16->setText(QApplication::translate("SendPackageWindow", "\346\216\245\346\224\266\346\226\271\350\264\246\345\217\267\357\274\232", nullptr));
        label_18->setText(QApplication::translate("SendPackageWindow", "\346\216\245\346\224\266\346\226\271\345\247\223\345\220\215\357\274\232", nullptr));
        RecvName_Label->setText(QApplication::translate("SendPackageWindow", "\344\270\215\345\255\230\345\234\250", nullptr));
        label_19->setText(QApplication::translate("SendPackageWindow", "\346\216\245\345\217\227\346\226\271\347\224\265\350\257\235\357\274\232", nullptr));
        RecvPhoneNum_Label->setText(QApplication::translate("SendPackageWindow", "\344\270\215\345\255\230\345\234\250", nullptr));
        label_17->setText(QApplication::translate("SendPackageWindow", "\346\216\245\345\217\227\346\226\271\345\234\260\345\235\200\357\274\232", nullptr));
        RecvAddr_Label->setText(QApplication::translate("SendPackageWindow", "\344\270\215\345\255\230\345\234\250", nullptr));
        label_21->setText(QApplication::translate("SendPackageWindow", "\347\211\251\345\223\201\346\217\217\350\277\260\357\274\232", nullptr));
        Input_Error_2->setText(QApplication::translate("SendPackageWindow", "\345\220\210\350\256\241:", nullptr));
        Price_Label->setText(QString());
        btn_Confirm_2->setText(QApplication::translate("SendPackageWindow", "\347\241\256\350\256\244", nullptr));
        btn_Cancel_2->setText(QApplication::translate("SendPackageWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendPackageWindow: public Ui_SendPackageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDPACKAGEWINDOW_H
