/********************************************************************************
** Form generated from reading UI file 'modbus_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODBUS_WINDOW_H
#define UI_MODBUS_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_Modbus_Window
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionExit;
    QAction *actionConfig;
    QAction *actionSave;
    QAction *actionRefresh;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *comboBoxParity;
    QComboBox *comboBoxStop;
    QComboBox *comboBoxBaud;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBoxData;
    QLabel *label_3;
    QComboBox *comboBoxPort;
    QLabel *label_2;
    QGroupBox *groupBox_6;
    QChartView *graphicsView;
    QGroupBox *groupBox_5;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QComboBox *comboBoxDataType;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QSpinBox *spinBoxStation;
    QSpinBox *spinBoxStartRead;
    QSpinBox *spinBoxNumberRead;
    QCheckBox *checkBoxAuto;
    QSpinBox *spinBoxInterval;
    QLabel *label_8;
    QPushButton *pushButtonRead;
    QSpinBox *spinBoxStartWrite;
    QLabel *label_11;
    QLabel *label_12;
    QSpinBox *spinBoxNumberWrite;
    QPushButton *pushButtonWrite;
    QLineEdit *lineEditWriteValue;
    QLabel *label_15;
    QComboBox *comboBoxFormat;
    QLabel *label_13;
    QCheckBox *MySQLcheckBox;
    QCheckBox *HEXCheckBox;
    QGroupBox *groupBox_3;
    QLabel *label_14;
    QLineEdit *lineEditSend;
    QPushButton *pushButtonSend;
    QPushButton *BackBtn;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *Modbus_Window)
    {
        if (Modbus_Window->objectName().isEmpty())
            Modbus_Window->setObjectName(QString::fromUtf8("Modbus_Window"));
        Modbus_Window->resize(999, 850);
        actionConnect = new QAction(Modbus_Window);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../ModbusMaster-master/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon);
        actionDisconnect = new QAction(Modbus_Window);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../ModbusMaster-master/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon1);
        actionExit = new QAction(Modbus_Window);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../ModbusMaster-master/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionConfig = new QAction(Modbus_Window);
        actionConfig->setObjectName(QString::fromUtf8("actionConfig"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../ModbusMaster-master/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfig->setIcon(icon3);
        actionSave = new QAction(Modbus_Window);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../ModbusMaster-master/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        actionRefresh = new QAction(Modbus_Window);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../ModbusMaster-master/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon5);
        centralwidget = new QWidget(Modbus_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 221, 220));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 50, 30));
        comboBoxParity = new QComboBox(groupBox);
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->setObjectName(QString::fromUtf8("comboBoxParity"));
        comboBoxParity->setGeometry(QRect(70, 140, 100, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxParity->sizePolicy().hasHeightForWidth());
        comboBoxParity->setSizePolicy(sizePolicy1);
        comboBoxParity->setMinimumSize(QSize(0, 20));
        comboBoxStop = new QComboBox(groupBox);
        comboBoxStop->addItem(QString());
        comboBoxStop->addItem(QString());
        comboBoxStop->addItem(QString());
        comboBoxStop->setObjectName(QString::fromUtf8("comboBoxStop"));
        comboBoxStop->setGeometry(QRect(70, 180, 100, 30));
        sizePolicy1.setHeightForWidth(comboBoxStop->sizePolicy().hasHeightForWidth());
        comboBoxStop->setSizePolicy(sizePolicy1);
        comboBoxBaud = new QComboBox(groupBox);
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->setObjectName(QString::fromUtf8("comboBoxBaud"));
        comboBoxBaud->setGeometry(QRect(70, 60, 100, 30));
        sizePolicy1.setHeightForWidth(comboBoxBaud->sizePolicy().hasHeightForWidth());
        comboBoxBaud->setSizePolicy(sizePolicy1);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 50, 30));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 180, 50, 30));
        comboBoxData = new QComboBox(groupBox);
        comboBoxData->addItem(QString());
        comboBoxData->addItem(QString());
        comboBoxData->addItem(QString());
        comboBoxData->addItem(QString());
        comboBoxData->addItem(QString());
        comboBoxData->setObjectName(QString::fromUtf8("comboBoxData"));
        comboBoxData->setGeometry(QRect(70, 100, 100, 30));
        sizePolicy1.setHeightForWidth(comboBoxData->sizePolicy().hasHeightForWidth());
        comboBoxData->setSizePolicy(sizePolicy1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 50, 30));
        comboBoxPort = new QComboBox(groupBox);
        comboBoxPort->setObjectName(QString::fromUtf8("comboBoxPort"));
        comboBoxPort->setGeometry(QRect(70, 20, 100, 30));
        sizePolicy1.setHeightForWidth(comboBoxPort->sizePolicy().hasHeightForWidth());
        comboBoxPort->setSizePolicy(sizePolicy1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 50, 30));
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(239, 10, 751, 400));
        graphicsView = new QChartView(groupBox_6);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 770, 371));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(239, 420, 751, 231));
        textBrowser = new QTextBrowser(groupBox_5);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 20, 770, 200));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 240, 221, 481));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 22, 60, 30));
        comboBoxDataType = new QComboBox(groupBox_2);
        comboBoxDataType->addItem(QString());
        comboBoxDataType->addItem(QString());
        comboBoxDataType->addItem(QString());
        comboBoxDataType->addItem(QString());
        comboBoxDataType->setObjectName(QString::fromUtf8("comboBoxDataType"));
        comboBoxDataType->setGeometry(QRect(70, 60, 141, 30));
        sizePolicy1.setHeightForWidth(comboBoxDataType->sizePolicy().hasHeightForWidth());
        comboBoxDataType->setSizePolicy(sizePolicy1);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 180, 60, 30));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 140, 60, 30));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 60, 60, 30));
        spinBoxStation = new QSpinBox(groupBox_2);
        spinBoxStation->setObjectName(QString::fromUtf8("spinBoxStation"));
        spinBoxStation->setGeometry(QRect(70, 20, 101, 30));
        spinBoxStation->setAlignment(Qt::AlignCenter);
        spinBoxStation->setMinimum(1);
        spinBoxStation->setMaximum(254);
        spinBoxStartRead = new QSpinBox(groupBox_2);
        spinBoxStartRead->setObjectName(QString::fromUtf8("spinBoxStartRead"));
        spinBoxStartRead->setGeometry(QRect(70, 140, 100, 30));
        spinBoxStartRead->setAlignment(Qt::AlignCenter);
        spinBoxStartRead->setMaximum(65535);
        spinBoxNumberRead = new QSpinBox(groupBox_2);
        spinBoxNumberRead->setObjectName(QString::fromUtf8("spinBoxNumberRead"));
        spinBoxNumberRead->setGeometry(QRect(70, 180, 100, 30));
        spinBoxNumberRead->setAlignment(Qt::AlignCenter);
        spinBoxNumberRead->setMinimum(1);
        spinBoxNumberRead->setMaximum(125);
        spinBoxNumberRead->setValue(4);
        checkBoxAuto = new QCheckBox(groupBox_2);
        checkBoxAuto->setObjectName(QString::fromUtf8("checkBoxAuto"));
        checkBoxAuto->setGeometry(QRect(10, 250, 100, 30));
        spinBoxInterval = new QSpinBox(groupBox_2);
        spinBoxInterval->setObjectName(QString::fromUtf8("spinBoxInterval"));
        spinBoxInterval->setGeometry(QRect(70, 220, 100, 30));
        spinBoxInterval->setAlignment(Qt::AlignCenter);
        spinBoxInterval->setMinimum(1);
        spinBoxInterval->setMaximum(3600000);
        spinBoxInterval->setValue(1000);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 220, 60, 30));
        pushButtonRead = new QPushButton(groupBox_2);
        pushButtonRead->setObjectName(QString::fromUtf8("pushButtonRead"));
        pushButtonRead->setGeometry(QRect(10, 280, 100, 30));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../ModbusMaster-master/images/books.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRead->setIcon(icon6);
        spinBoxStartWrite = new QSpinBox(groupBox_2);
        spinBoxStartWrite->setObjectName(QString::fromUtf8("spinBoxStartWrite"));
        spinBoxStartWrite->setGeometry(QRect(70, 320, 100, 30));
        spinBoxStartWrite->setAlignment(Qt::AlignCenter);
        spinBoxStartWrite->setMaximum(65535);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 320, 60, 30));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 360, 60, 30));
        spinBoxNumberWrite = new QSpinBox(groupBox_2);
        spinBoxNumberWrite->setObjectName(QString::fromUtf8("spinBoxNumberWrite"));
        spinBoxNumberWrite->setGeometry(QRect(70, 360, 100, 30));
        spinBoxNumberWrite->setAlignment(Qt::AlignCenter);
        spinBoxNumberWrite->setMinimum(1);
        spinBoxNumberWrite->setMaximum(125);
        pushButtonWrite = new QPushButton(groupBox_2);
        pushButtonWrite->setObjectName(QString::fromUtf8("pushButtonWrite"));
        pushButtonWrite->setGeometry(QRect(60, 440, 100, 30));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../ModbusMaster-master/images/Write.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonWrite->setIcon(icon7);
        lineEditWriteValue = new QLineEdit(groupBox_2);
        lineEditWriteValue->setObjectName(QString::fromUtf8("lineEditWriteValue"));
        lineEditWriteValue->setGeometry(QRect(70, 400, 100, 30));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 400, 60, 30));
        comboBoxFormat = new QComboBox(groupBox_2);
        comboBoxFormat->setObjectName(QString::fromUtf8("comboBoxFormat"));
        comboBoxFormat->setGeometry(QRect(70, 100, 100, 30));
        sizePolicy1.setHeightForWidth(comboBoxFormat->sizePolicy().hasHeightForWidth());
        comboBoxFormat->setSizePolicy(sizePolicy1);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 100, 60, 30));
        MySQLcheckBox = new QCheckBox(groupBox_2);
        MySQLcheckBox->setObjectName(QString::fromUtf8("MySQLcheckBox"));
        MySQLcheckBox->setGeometry(QRect(90, 250, 110, 30));
        HEXCheckBox = new QCheckBox(groupBox_2);
        HEXCheckBox->setObjectName(QString::fromUtf8("HEXCheckBox"));
        HEXCheckBox->setGeometry(QRect(120, 280, 91, 30));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(239, 660, 751, 60));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 20, 54, 30));
        lineEditSend = new QLineEdit(groupBox_3);
        lineEditSend->setObjectName(QString::fromUtf8("lineEditSend"));
        lineEditSend->setGeometry(QRect(70, 20, 561, 30));
        pushButtonSend = new QPushButton(groupBox_3);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(640, 20, 100, 30));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../ModbusMaster-master/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSend->setIcon(icon8);
        BackBtn = new QPushButton(centralwidget);
        BackBtn->setObjectName(QString::fromUtf8("BackBtn"));
        BackBtn->setGeometry(QRect(860, 720, 121, 41));
        BackBtn->setStyleSheet(QString::fromUtf8("font-family:'\344\273\277\345\256\213';\n"
"font-size:20px;\n"
"color: #2f3640;\n"
"background-color: #eea2a4;\n"
"border-color: #eea2a4;\n"
"border-radius: 20px;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"padding: 5px;"));
        Modbus_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Modbus_Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 999, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        Modbus_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Modbus_Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Modbus_Window->setStatusBar(statusbar);
        mainToolBar = new QToolBar(Modbus_Window);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        Modbus_Window->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionConnect);
        menu->addAction(actionDisconnect);
        menu->addAction(actionRefresh);
        menu->addSeparator();
        menu->addAction(actionExit);
        menu_2->addAction(actionConfig);
        menu_2->addAction(actionSave);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionRefresh);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionConfig);

        retranslateUi(Modbus_Window);

        comboBoxBaud->setCurrentIndex(8);
        comboBoxData->setCurrentIndex(3);
        comboBoxDataType->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Modbus_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Modbus_Window)
    {
        Modbus_Window->setWindowTitle(QCoreApplication::translate("Modbus_Window", "MainWindow", nullptr));
        actionConnect->setText(QCoreApplication::translate("Modbus_Window", "\350\277\236\346\216\245", nullptr));
#if QT_CONFIG(tooltip)
        actionConnect->setToolTip(QCoreApplication::translate("Modbus_Window", "\350\277\236\346\216\245\344\273\216\347\253\231", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDisconnect->setText(QCoreApplication::translate("Modbus_Window", "\346\226\255\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actionDisconnect->setToolTip(QCoreApplication::translate("Modbus_Window", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        actionExit->setText(QCoreApplication::translate("Modbus_Window", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("Modbus_Window", "\351\200\200\345\207\272\350\275\257\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actionConfig->setText(QCoreApplication::translate("Modbus_Window", "\351\205\215\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        actionConfig->setToolTip(QCoreApplication::translate("Modbus_Window", "\351\205\215\347\275\256\345\217\202\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave->setText(QCoreApplication::translate("Modbus_Window", "\345\255\230\346\241\243", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("Modbus_Window", "\346\212\245\346\226\207\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRefresh->setText(QCoreApplication::translate("Modbus_Window", "\345\210\267\346\226\260", nullptr));
#if QT_CONFIG(tooltip)
        actionRefresh->setToolTip(QCoreApplication::translate("Modbus_Window", "\345\210\267\346\226\260\344\270\262\345\217\243\345\210\227\350\241\250", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox->setTitle(QCoreApplication::translate("Modbus_Window", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("Modbus_Window", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        comboBoxParity->setItemText(0, QCoreApplication::translate("Modbus_Window", "\346\227\240\346\240\241\351\252\214", nullptr));
        comboBoxParity->setItemText(1, QCoreApplication::translate("Modbus_Window", "\345\245\207\346\240\241\351\252\214", nullptr));
        comboBoxParity->setItemText(2, QCoreApplication::translate("Modbus_Window", "\345\201\266\346\240\241\351\252\214", nullptr));

        comboBoxStop->setItemText(0, QCoreApplication::translate("Modbus_Window", "1\344\275\215", nullptr));
        comboBoxStop->setItemText(1, QCoreApplication::translate("Modbus_Window", "1.5\344\275\215", nullptr));
        comboBoxStop->setItemText(2, QCoreApplication::translate("Modbus_Window", "2\344\275\215", nullptr));

        comboBoxBaud->setItemText(0, QCoreApplication::translate("Modbus_Window", "4800", nullptr));
        comboBoxBaud->setItemText(1, QCoreApplication::translate("Modbus_Window", "9600", nullptr));
        comboBoxBaud->setItemText(2, QCoreApplication::translate("Modbus_Window", "14400", nullptr));
        comboBoxBaud->setItemText(3, QCoreApplication::translate("Modbus_Window", "19200", nullptr));
        comboBoxBaud->setItemText(4, QCoreApplication::translate("Modbus_Window", "28800", nullptr));
        comboBoxBaud->setItemText(5, QCoreApplication::translate("Modbus_Window", "38400", nullptr));
        comboBoxBaud->setItemText(6, QCoreApplication::translate("Modbus_Window", "56000", nullptr));
        comboBoxBaud->setItemText(7, QCoreApplication::translate("Modbus_Window", "57600", nullptr));
        comboBoxBaud->setItemText(8, QCoreApplication::translate("Modbus_Window", "115200", nullptr));
        comboBoxBaud->setItemText(9, QCoreApplication::translate("Modbus_Window", "128000", nullptr));
        comboBoxBaud->setItemText(10, QCoreApplication::translate("Modbus_Window", "230400", nullptr));
        comboBoxBaud->setItemText(11, QCoreApplication::translate("Modbus_Window", "256000", nullptr));

        label_4->setText(QCoreApplication::translate("Modbus_Window", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Modbus_Window", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        comboBoxData->setItemText(0, QCoreApplication::translate("Modbus_Window", "5", nullptr));
        comboBoxData->setItemText(1, QCoreApplication::translate("Modbus_Window", "6", nullptr));
        comboBoxData->setItemText(2, QCoreApplication::translate("Modbus_Window", "7", nullptr));
        comboBoxData->setItemText(3, QCoreApplication::translate("Modbus_Window", "8", nullptr));
        comboBoxData->setItemText(4, QCoreApplication::translate("Modbus_Window", "9", nullptr));

        label_3->setText(QCoreApplication::translate("Modbus_Window", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Modbus_Window", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Modbus_Window", "\345\212\250\346\200\201\346\233\262\347\272\277", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Modbus_Window", "\346\224\266\345\217\221\346\230\276\347\244\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Modbus_Window", "\344\272\244\344\272\222\351\205\215\347\275\256", nullptr));
        label_6->setText(QCoreApplication::translate("Modbus_Window", "\344\273\216\347\253\231\345\234\260\345\235\200\357\274\232", nullptr));
        comboBoxDataType->setItemText(0, QCoreApplication::translate("Modbus_Window", "0 Coils", nullptr));
        comboBoxDataType->setItemText(1, QCoreApplication::translate("Modbus_Window", "1 Input Status", nullptr));
        comboBoxDataType->setItemText(2, QCoreApplication::translate("Modbus_Window", "2 Input Registers", nullptr));
        comboBoxDataType->setItemText(3, QCoreApplication::translate("Modbus_Window", "3 Holding Registers", nullptr));

        label_7->setText(QCoreApplication::translate("Modbus_Window", "\350\257\273\345\217\226\346\225\260\351\207\217\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("Modbus_Window", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("Modbus_Window", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        checkBoxAuto->setText(QCoreApplication::translate("Modbus_Window", "\350\207\252\345\212\250\350\257\273\345\217\226", nullptr));
        label_8->setText(QCoreApplication::translate("Modbus_Window", "\351\227\264\351\232\224\345\221\250\346\234\237\357\274\232", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("Modbus_Window", "  \350\257\273\345\217\226", nullptr));
        label_11->setText(QCoreApplication::translate("Modbus_Window", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("Modbus_Window", "\345\206\231\345\205\245\346\225\260\351\207\217\357\274\232", nullptr));
        pushButtonWrite->setText(QCoreApplication::translate("Modbus_Window", "  \345\206\231\345\205\245", nullptr));
        label_15->setText(QCoreApplication::translate("Modbus_Window", "\345\206\231\345\205\245\346\225\260\345\200\274\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("Modbus_Window", "\346\212\245\346\226\207\346\240\274\345\274\217\357\274\232", nullptr));
        MySQLcheckBox->setText(QCoreApplication::translate("Modbus_Window", "\344\277\235\345\255\230\345\210\260\346\225\260\346\215\256\345\272\223", nullptr));
        HEXCheckBox->setText(QCoreApplication::translate("Modbus_Window", "\350\276\223\345\207\27216\350\277\233\345\210\266", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Modbus_Window", "\346\223\215\344\275\234\345\214\272\345\237\237", nullptr));
        label_14->setText(QCoreApplication::translate("Modbus_Window", "\345\217\221\351\200\201\345\221\275\344\273\244\357\274\232", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("Modbus_Window", "  \345\217\221\351\200\201", nullptr));
        BackBtn->setText(QCoreApplication::translate("Modbus_Window", "\350\277\224\345\233\236", nullptr));
        menu->setTitle(QCoreApplication::translate("Modbus_Window", "\350\256\276\345\244\207", nullptr));
        menu_2->setTitle(QCoreApplication::translate("Modbus_Window", "\345\267\245\345\205\267", nullptr));
        mainToolBar->setWindowTitle(QCoreApplication::translate("Modbus_Window", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modbus_Window: public Ui_Modbus_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUS_WINDOW_H
