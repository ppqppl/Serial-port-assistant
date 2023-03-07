/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *JumpComBtn;
    QPushButton *JumpModbusBtn;
    QPushButton *JumpTCPBtn;
    QPushButton *JumpUDPBtn;
    QPushButton *MySQLBtn;
    QPushButton *ExitBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(718, 635);
        MainWindow->setMinimumSize(QSize(718, 635));
        MainWindow->setMaximumSize(QSize(718, 635));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 60, 331, 111));
        label->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:40px;"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(560, 130, 141, 441));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        JumpComBtn = new QPushButton(layoutWidget);
        JumpComBtn->setObjectName(QString::fromUtf8("JumpComBtn"));
        JumpComBtn->setMinimumSize(QSize(139, 45));
        JumpComBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));

        verticalLayout->addWidget(JumpComBtn);

        JumpModbusBtn = new QPushButton(layoutWidget);
        JumpModbusBtn->setObjectName(QString::fromUtf8("JumpModbusBtn"));
        JumpModbusBtn->setMinimumSize(QSize(139, 45));
        JumpModbusBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));

        verticalLayout->addWidget(JumpModbusBtn);

        JumpTCPBtn = new QPushButton(layoutWidget);
        JumpTCPBtn->setObjectName(QString::fromUtf8("JumpTCPBtn"));
        JumpTCPBtn->setMinimumSize(QSize(139, 45));
        JumpTCPBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));

        verticalLayout->addWidget(JumpTCPBtn);

        JumpUDPBtn = new QPushButton(layoutWidget);
        JumpUDPBtn->setObjectName(QString::fromUtf8("JumpUDPBtn"));
        JumpUDPBtn->setMinimumSize(QSize(139, 45));
        JumpUDPBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));

        verticalLayout->addWidget(JumpUDPBtn);

        MySQLBtn = new QPushButton(layoutWidget);
        MySQLBtn->setObjectName(QString::fromUtf8("MySQLBtn"));
        MySQLBtn->setMinimumSize(QSize(139, 45));
        MySQLBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));

        verticalLayout->addWidget(MySQLBtn);

        ExitBtn = new QPushButton(layoutWidget);
        ExitBtn->setObjectName(QString::fromUtf8("ExitBtn"));
        ExitBtn->setMinimumSize(QSize(139, 45));
        ExitBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));

        verticalLayout->addWidget(ExitBtn);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 718, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:30pt;\">\347\202\271\345\207\273\351\200\211\346\213\251\345\212\237\350\203\275</span></p></body></html>", nullptr));
        JumpComBtn->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\212\251\346\211\213", nullptr));
        JumpModbusBtn->setText(QCoreApplication::translate("MainWindow", "modbus\345\212\251\346\211\213", nullptr));
        JumpTCPBtn->setText(QCoreApplication::translate("MainWindow", "TCP\345\212\251\346\211\213", nullptr));
        JumpUDPBtn->setText(QCoreApplication::translate("MainWindow", "UDP\345\212\251\346\211\213", nullptr));
        MySQLBtn->setText(QCoreApplication::translate("MainWindow", "MySQL\346\265\213\350\257\225", nullptr));
        ExitBtn->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
