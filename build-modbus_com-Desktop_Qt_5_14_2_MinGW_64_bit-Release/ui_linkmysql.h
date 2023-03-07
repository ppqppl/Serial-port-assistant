/********************************************************************************
** Form generated from reading UI file 'linkmysql.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINKMYSQL_H
#define UI_LINKMYSQL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinkMySQL
{
public:
    QWidget *centralwidget;
    QPushButton *TestBtn;
    QPushButton *BackBtn;
    QPushButton *LinkBtn;
    QTextBrowser *MyText;
    QPushButton *FindAllBtn;
    QPushButton *InsertBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LinkMySQL)
    {
        if (LinkMySQL->objectName().isEmpty())
            LinkMySQL->setObjectName(QString::fromUtf8("LinkMySQL"));
        LinkMySQL->resize(734, 427);
        centralwidget = new QWidget(LinkMySQL);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TestBtn = new QPushButton(centralwidget);
        TestBtn->setObjectName(QString::fromUtf8("TestBtn"));
        TestBtn->setGeometry(QRect(470, 20, 100, 30));
        BackBtn = new QPushButton(centralwidget);
        BackBtn->setObjectName(QString::fromUtf8("BackBtn"));
        BackBtn->setGeometry(QRect(600, 330, 121, 41));
        BackBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));
        LinkBtn = new QPushButton(centralwidget);
        LinkBtn->setObjectName(QString::fromUtf8("LinkBtn"));
        LinkBtn->setGeometry(QRect(590, 20, 100, 30));
        MyText = new QTextBrowser(centralwidget);
        MyText->setObjectName(QString::fromUtf8("MyText"));
        MyText->setGeometry(QRect(0, 0, 431, 381));
        FindAllBtn = new QPushButton(centralwidget);
        FindAllBtn->setObjectName(QString::fromUtf8("FindAllBtn"));
        FindAllBtn->setGeometry(QRect(470, 80, 100, 30));
        InsertBtn = new QPushButton(centralwidget);
        InsertBtn->setObjectName(QString::fromUtf8("InsertBtn"));
        InsertBtn->setGeometry(QRect(590, 80, 100, 30));
        LinkMySQL->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LinkMySQL);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 734, 23));
        LinkMySQL->setMenuBar(menubar);
        statusbar = new QStatusBar(LinkMySQL);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LinkMySQL->setStatusBar(statusbar);

        retranslateUi(LinkMySQL);

        QMetaObject::connectSlotsByName(LinkMySQL);
    } // setupUi

    void retranslateUi(QMainWindow *LinkMySQL)
    {
        LinkMySQL->setWindowTitle(QCoreApplication::translate("LinkMySQL", "MainWindow", nullptr));
        TestBtn->setText(QCoreApplication::translate("LinkMySQL", "\346\265\213\350\257\225", nullptr));
        BackBtn->setText(QCoreApplication::translate("LinkMySQL", "\350\277\224\345\233\236", nullptr));
        LinkBtn->setText(QCoreApplication::translate("LinkMySQL", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", nullptr));
        FindAllBtn->setText(QCoreApplication::translate("LinkMySQL", "\346\237\245\346\211\276\346\211\200\346\234\211\346\225\260\346\215\256", nullptr));
        InsertBtn->setText(QCoreApplication::translate("LinkMySQL", "\346\217\222\345\205\245\344\270\200\346\235\241\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LinkMySQL: public Ui_LinkMySQL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINKMYSQL_H
