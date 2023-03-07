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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *IPText;
    QLabel *label_2;
    QLineEdit *PortText;
    QPushButton *GetBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TCP_Window)
    {
        if (TCP_Window->objectName().isEmpty())
            TCP_Window->setObjectName(QString::fromUtf8("TCP_Window"));
        TCP_Window->resize(512, 559);
        centralwidget = new QWidget(TCP_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BackBtn = new QPushButton(centralwidget);
        BackBtn->setObjectName(QString::fromUtf8("BackBtn"));
        BackBtn->setGeometry(QRect(380, 460, 121, 41));
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
        MyText->setGeometry(QRect(0, 110, 511, 341));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 10, 291, 41));
        label_3->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 60, 511, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        horizontalLayout->addWidget(label);

        IPText = new QLineEdit(widget);
        IPText->setObjectName(QString::fromUtf8("IPText"));
        IPText->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));
        IPText->setReadOnly(true);

        horizontalLayout->addWidget(IPText);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));

        horizontalLayout->addWidget(label_2);

        PortText = new QLineEdit(widget);
        PortText->setObjectName(QString::fromUtf8("PortText"));
        PortText->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;"));
        PortText->setReadOnly(true);

        horizontalLayout->addWidget(PortText);

        GetBtn = new QPushButton(widget);
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

        TCP_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TCP_Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 512, 23));
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
    } // retranslateUi

};

namespace Ui {
    class TCP_Window: public Ui_TCP_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCP_WINDOW_H
