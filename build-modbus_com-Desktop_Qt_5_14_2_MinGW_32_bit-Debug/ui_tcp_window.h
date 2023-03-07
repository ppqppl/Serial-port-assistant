/********************************************************************************
** Form generated from reading UI file 'tcp_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCP_WINDOW_H
#define UI_TCP_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCP_Window
{
public:
    QWidget *centralwidget;
    QPushButton *BackBtn;
    QTextBrowser *MyText;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *IPText;
    QLabel *label_2;
    QLineEdit *PortText;
    QPushButton *GetBtn;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *SleepspinBox;
    QLabel *label_5;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TCP_Window)
    {
        if (TCP_Window->objectName().isEmpty())
            TCP_Window->setObjectName(QString::fromUtf8("TCP_Window"));
        TCP_Window->resize(772, 634);
        centralwidget = new QWidget(TCP_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BackBtn = new QPushButton(centralwidget);
        BackBtn->setObjectName(QString::fromUtf8("BackBtn"));
        BackBtn->setGeometry(QRect(630, 540, 121, 41));
        BackBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));
        MyText = new QTextBrowser(centralwidget);
        MyText->setObjectName(QString::fromUtf8("MyText"));
        MyText->setGeometry(QRect(0, 110, 771, 351));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 10, 291, 41));
        label_3->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 60, 761, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        horizontalLayout->addWidget(label);

        IPText = new QLineEdit(layoutWidget);
        IPText->setObjectName(QString::fromUtf8("IPText"));
        IPText->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));
        IPText->setReadOnly(true);

        horizontalLayout->addWidget(IPText);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        horizontalLayout->addWidget(label_2);

        PortText = new QLineEdit(layoutWidget);
        PortText->setObjectName(QString::fromUtf8("PortText"));
        PortText->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));
        PortText->setReadOnly(true);

        horizontalLayout->addWidget(PortText);

        GetBtn = new QPushButton(layoutWidget);
        GetBtn->setObjectName(QString::fromUtf8("GetBtn"));
        GetBtn->setMinimumSize(QSize(121, 41));
        GetBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));

        horizontalLayout->addWidget(GetBtn);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 480, 771, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        horizontalLayout_2->addWidget(label_4);

        SleepspinBox = new QSpinBox(layoutWidget1);
        SleepspinBox->setObjectName(QString::fromUtf8("SleepspinBox"));
        SleepspinBox->setMinimumSize(QSize(40, 30));
        SleepspinBox->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));
        SleepspinBox->setMinimum(2);
        SleepspinBox->setMaximum(300);
        SleepspinBox->setSingleStep(3);

        horizontalLayout_2->addWidget(SleepspinBox);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        horizontalLayout_2->addWidget(label_5);

        checkBox = new QCheckBox(layoutWidget1);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMinimumSize(QSize(0, 30));
        checkBox->setStyleSheet(QString::fromUtf8("border: 0px solid gray;   /* \350\276\271\346\241\206 */\n"
"border-radius: 4px;   /* \345\234\206\350\247\222 */\n"
"padding: 1px 18px 1px 3px;   /* \345\255\227\344\275\223\345\241\253\350\241\254 */\n"
"color: #000;\n"
"font: normal normal 20px \"\344\273\277\345\256\213\";\n"
"background: transparent;"));

        horizontalLayout_2->addWidget(checkBox);

        TCP_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TCP_Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 772, 23));
        TCP_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(TCP_Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TCP_Window->setStatusBar(statusbar);

        retranslateUi(TCP_Window);

        QMetaObject::connectSlotsByName(TCP_Window);
    } // setupUi

    void retranslateUi(QMainWindow *TCP_Window)
    {
        TCP_Window->setWindowTitle(QCoreApplication::translate("TCP_Window", "MainWindow", nullptr));
        BackBtn->setText(QCoreApplication::translate("TCP_Window", "\350\277\224\345\233\236", nullptr));
        label_3->setText(QCoreApplication::translate("TCP_Window", "TCP Modbus \345\215\217\350\256\256\350\216\267\345\217\226\346\234\215\345\212\241\345\231\250\346\225\260\346\215\256", nullptr));
        label->setText(QCoreApplication::translate("TCP_Window", "IP\357\274\232", nullptr));
        IPText->setText(QCoreApplication::translate("TCP_Window", "123.56.90.74", nullptr));
        label_2->setText(QCoreApplication::translate("TCP_Window", "PORT\357\274\232", nullptr));
        PortText->setText(QCoreApplication::translate("TCP_Window", "8002", nullptr));
        GetBtn->setText(QCoreApplication::translate("TCP_Window", "\350\216\267\345\217\226\346\225\260\346\215\256", nullptr));
        label_4->setText(QCoreApplication::translate("TCP_Window", "\350\216\267\345\217\226\346\225\260\346\215\256\346\227\266\351\227\264\351\227\264\351\232\224\357\274\232 ", nullptr));
        label_5->setText(QCoreApplication::translate("TCP_Window", "\346\230\257\345\220\246\344\277\235\345\255\230\345\210\260\346\225\260\346\215\256\345\272\223\357\274\232 ", nullptr));
        checkBox->setText(QCoreApplication::translate("TCP_Window", "\344\277\235\345\255\230\345\210\260\346\225\260\346\215\256\345\272\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCP_Window: public Ui_TCP_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCP_WINDOW_H
