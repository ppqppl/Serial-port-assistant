/********************************************************************************
** Form generated from reading UI file 'com_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COM_WINDOW_H
#define UI_COM_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_COM_Window
{
public:
    QWidget *centralwidget;
    QPushButton *BackBtn;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QComboBox *COMcomboBox;
    QLabel *label;
    QComboBox *BitcomboBox;
    QLabel *label_2;
    QComboBox *DatacomboBox;
    QLabel *label_3;
    QComboBox *StopcomboBox;
    QLabel *label_5;
    QComboBox *CRCcomboBox;
    QLabel *label_4;
    QTextBrowser *ReceiveText;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *OpenCOMBtn;
    QPushButton *RenewCOMBtn;
    QPushButton *ClearBtn;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QCheckBox *StopShowcheckBox;
    QCheckBox *LogShowcheckBox;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QRadioButton *ASCIIradioButton;
    QRadioButton *HEXradioButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *COM_Window)
    {
        if (COM_Window->objectName().isEmpty())
            COM_Window->setObjectName(QString::fromUtf8("COM_Window"));
        COM_Window->resize(967, 738);
        COM_Window->setMinimumSize(QSize(967, 738));
        COM_Window->setMaximumSize(QSize(967, 738));
        centralwidget = new QWidget(COM_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BackBtn = new QPushButton(centralwidget);
        BackBtn->setObjectName(QString::fromUtf8("BackBtn"));
        BackBtn->setGeometry(QRect(840, 640, 121, 41));
        BackBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 450, 181, 241));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        COMcomboBox = new QComboBox(layoutWidget);
        COMcomboBox->setObjectName(QString::fromUtf8("COMcomboBox"));
        COMcomboBox->setMinimumSize(QSize(101, 31));
        COMcomboBox->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        gridLayout->addWidget(COMcomboBox, 0, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        BitcomboBox = new QComboBox(layoutWidget);
        BitcomboBox->addItem(QString());
        BitcomboBox->addItem(QString());
        BitcomboBox->addItem(QString());
        BitcomboBox->addItem(QString());
        BitcomboBox->addItem(QString());
        BitcomboBox->addItem(QString());
        BitcomboBox->addItem(QString());
        BitcomboBox->addItem(QString());
        BitcomboBox->addItem(QString());
        BitcomboBox->addItem(QString());
        BitcomboBox->setObjectName(QString::fromUtf8("BitcomboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BitcomboBox->sizePolicy().hasHeightForWidth());
        BitcomboBox->setSizePolicy(sizePolicy);
        BitcomboBox->setMinimumSize(QSize(101, 31));
        BitcomboBox->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        gridLayout->addWidget(BitcomboBox, 1, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        DatacomboBox = new QComboBox(layoutWidget);
        DatacomboBox->addItem(QString());
        DatacomboBox->addItem(QString());
        DatacomboBox->addItem(QString());
        DatacomboBox->addItem(QString());
        DatacomboBox->setObjectName(QString::fromUtf8("DatacomboBox"));
        DatacomboBox->setMinimumSize(QSize(101, 31));
        DatacomboBox->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        gridLayout->addWidget(DatacomboBox, 2, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        StopcomboBox = new QComboBox(layoutWidget);
        StopcomboBox->addItem(QString());
        StopcomboBox->addItem(QString());
        StopcomboBox->setObjectName(QString::fromUtf8("StopcomboBox"));
        StopcomboBox->setMinimumSize(QSize(101, 31));
        StopcomboBox->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        gridLayout->addWidget(StopcomboBox, 3, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 1, 1, 1);

        CRCcomboBox = new QComboBox(layoutWidget);
        CRCcomboBox->addItem(QString());
        CRCcomboBox->addItem(QString());
        CRCcomboBox->addItem(QString());
        CRCcomboBox->setObjectName(QString::fromUtf8("CRCcomboBox"));
        CRCcomboBox->setMinimumSize(QSize(101, 31));
        CRCcomboBox->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        gridLayout->addWidget(CRCcomboBox, 4, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        ReceiveText = new QTextBrowser(centralwidget);
        ReceiveText->setObjectName(QString::fromUtf8("ReceiveText"));
        ReceiveText->setGeometry(QRect(0, 0, 971, 431));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(281, 482, 379, 170));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        OpenCOMBtn = new QPushButton(widget);
        OpenCOMBtn->setObjectName(QString::fromUtf8("OpenCOMBtn"));
        OpenCOMBtn->setMinimumSize(QSize(121, 41));
        OpenCOMBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));

        horizontalLayout_2->addWidget(OpenCOMBtn);

        RenewCOMBtn = new QPushButton(widget);
        RenewCOMBtn->setObjectName(QString::fromUtf8("RenewCOMBtn"));
        RenewCOMBtn->setMinimumSize(QSize(121, 41));
        RenewCOMBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));

        horizontalLayout_2->addWidget(RenewCOMBtn);

        ClearBtn = new QPushButton(widget);
        ClearBtn->setObjectName(QString::fromUtf8("ClearBtn"));
        ClearBtn->setMinimumSize(QSize(121, 41));
        ClearBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));

        horizontalLayout_2->addWidget(ClearBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        horizontalLayout->addWidget(label_6);

        StopShowcheckBox = new QCheckBox(widget);
        StopShowcheckBox->setObjectName(QString::fromUtf8("StopShowcheckBox"));
        StopShowcheckBox->setStyleSheet(QString::fromUtf8("border: 0px solid gray;   /* \350\276\271\346\241\206 */\n"
"border-radius: 4px;   /* \345\234\206\350\247\222 */\n"
"padding: 1px 18px 1px 3px;   /* \345\255\227\344\275\223\345\241\253\350\241\254 */\n"
"color: #000;\n"
"font: normal normal 20px \"\344\273\277\345\256\213\";\n"
"background: transparent;"));

        horizontalLayout->addWidget(StopShowcheckBox);

        LogShowcheckBox = new QCheckBox(widget);
        LogShowcheckBox->setObjectName(QString::fromUtf8("LogShowcheckBox"));
        LogShowcheckBox->setStyleSheet(QString::fromUtf8("border: 0px solid gray;   /* \350\276\271\346\241\206 */\n"
"border-radius: 4px;   /* \345\234\206\350\247\222 */\n"
"padding: 1px 18px 1px 3px;   /* \345\255\227\344\275\223\345\241\253\350\241\254 */\n"
"color: #000;\n"
"font: normal normal 20px \"\344\273\277\345\256\213\";\n"
"background: transparent;"));

        horizontalLayout->addWidget(LogShowcheckBox);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        horizontalLayout_3->addWidget(label_7);

        ASCIIradioButton = new QRadioButton(widget);
        ASCIIradioButton->setObjectName(QString::fromUtf8("ASCIIradioButton"));
        ASCIIradioButton->setStyleSheet(QString::fromUtf8("border: 0px solid gray;   /* \350\276\271\346\241\206 */\n"
"border-radius: 4px;   /* \345\234\206\350\247\222 */\n"
"padding: 1px 18px 1px 3px;   /* \345\255\227\344\275\223\345\241\253\350\241\254 */\n"
"color: #000;\n"
"font: normal normal 20px \"\344\273\277\345\256\213\";\n"
"background: transparent;"));
        ASCIIradioButton->setChecked(true);

        horizontalLayout_3->addWidget(ASCIIradioButton);

        HEXradioButton = new QRadioButton(widget);
        HEXradioButton->setObjectName(QString::fromUtf8("HEXradioButton"));
        HEXradioButton->setStyleSheet(QString::fromUtf8("border: 0px solid gray;   /* \350\276\271\346\241\206 */\n"
"border-radius: 4px;   /* \345\234\206\350\247\222 */\n"
"padding: 1px 18px 1px 3px;   /* \345\255\227\344\275\223\345\241\253\350\241\254 */\n"
"color: #000;\n"
"font: normal normal 20px \"\344\273\277\345\256\213\";\n"
"background: transparent;"));

        horizontalLayout_3->addWidget(HEXradioButton);


        verticalLayout->addLayout(horizontalLayout_3);

        COM_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(COM_Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 967, 23));
        COM_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(COM_Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        COM_Window->setStatusBar(statusbar);

        retranslateUi(COM_Window);

        BitcomboBox->setCurrentIndex(6);
        DatacomboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(COM_Window);
    } // setupUi

    void retranslateUi(QMainWindow *COM_Window)
    {
        COM_Window->setWindowTitle(QCoreApplication::translate("COM_Window", "MainWindow", nullptr));
        BackBtn->setText(QCoreApplication::translate("COM_Window", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("COM_Window", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\344\270\262\345\217\243\345\217\267</span></p></body></html>", nullptr));
        BitcomboBox->setItemText(0, QCoreApplication::translate("COM_Window", "2400", nullptr));
        BitcomboBox->setItemText(1, QCoreApplication::translate("COM_Window", "4800", nullptr));
        BitcomboBox->setItemText(2, QCoreApplication::translate("COM_Window", "9600", nullptr));
        BitcomboBox->setItemText(3, QCoreApplication::translate("COM_Window", "19200", nullptr));
        BitcomboBox->setItemText(4, QCoreApplication::translate("COM_Window", "38400", nullptr));
        BitcomboBox->setItemText(5, QCoreApplication::translate("COM_Window", "57600", nullptr));
        BitcomboBox->setItemText(6, QCoreApplication::translate("COM_Window", "115200", nullptr));
        BitcomboBox->setItemText(7, QCoreApplication::translate("COM_Window", "128000", nullptr));
        BitcomboBox->setItemText(8, QCoreApplication::translate("COM_Window", "230400", nullptr));
        BitcomboBox->setItemText(9, QCoreApplication::translate("COM_Window", "256000", nullptr));

        label_2->setText(QCoreApplication::translate("COM_Window", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\263\242\347\211\271\347\216\207</span></p></body></html>", nullptr));
        DatacomboBox->setItemText(0, QCoreApplication::translate("COM_Window", "5", nullptr));
        DatacomboBox->setItemText(1, QCoreApplication::translate("COM_Window", "6", nullptr));
        DatacomboBox->setItemText(2, QCoreApplication::translate("COM_Window", "7", nullptr));
        DatacomboBox->setItemText(3, QCoreApplication::translate("COM_Window", "8", nullptr));

        label_3->setText(QCoreApplication::translate("COM_Window", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\225\260\346\215\256\344\275\215</span></p></body></html>", nullptr));
        StopcomboBox->setItemText(0, QCoreApplication::translate("COM_Window", "1", nullptr));
        StopcomboBox->setItemText(1, QCoreApplication::translate("COM_Window", "2", nullptr));

        label_5->setText(QCoreApplication::translate("COM_Window", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\201\234\346\255\242\344\275\215</span></p></body></html>", nullptr));
        CRCcomboBox->setItemText(0, QCoreApplication::translate("COM_Window", "\346\227\240", nullptr));
        CRCcomboBox->setItemText(1, QCoreApplication::translate("COM_Window", "\345\245\207", nullptr));
        CRCcomboBox->setItemText(2, QCoreApplication::translate("COM_Window", "\345\201\266", nullptr));

        label_4->setText(QCoreApplication::translate("COM_Window", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\240\241\351\252\214\344\275\215</span></p></body></html>", nullptr));
        OpenCOMBtn->setText(QCoreApplication::translate("COM_Window", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        RenewCOMBtn->setText(QCoreApplication::translate("COM_Window", "\345\210\267\346\226\260\344\270\262\345\217\243", nullptr));
        ClearBtn->setText(QCoreApplication::translate("COM_Window", "\346\270\205\351\231\244\347\252\227\345\217\243", nullptr));
        label_6->setText(QCoreApplication::translate("COM_Window", "\350\276\223\345\207\272\350\256\276\347\275\256\357\274\232", nullptr));
        StopShowcheckBox->setText(QCoreApplication::translate("COM_Window", "\345\201\234\346\255\242\346\230\276\347\244\272", nullptr));
        LogShowcheckBox->setText(QCoreApplication::translate("COM_Window", "\346\227\245\345\277\227\346\250\241\345\274\217", nullptr));
        label_7->setText(QCoreApplication::translate("COM_Window", "\350\276\223\345\207\272\347\274\226\347\240\201\357\274\232", nullptr));
        ASCIIradioButton->setText(QCoreApplication::translate("COM_Window", "ASCII", nullptr));
        HEXradioButton->setText(QCoreApplication::translate("COM_Window", "HEX", nullptr));
    } // retranslateUi

};

namespace Ui {
    class COM_Window: public Ui_COM_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COM_WINDOW_H
