QT       += core gui serialport serialbus charts sql network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    com_window.cpp \
    linkmysql.cpp \
    main.cpp \
    mainwindow.cpp \
    modbus_window.cpp \
    mythread.cpp \
    tcp_window.cpp \
    udp_window.cpp

HEADERS += \
    com_window.h \
    linkmysql.h \
    main.h \
    mainwindow.h \
    modbus_window.h \
    mythread.h \
    tcp_window. \
    tcp_window.h \
    udp_window.h

FORMS += \
    com_window.ui \
    linkmysql.ui \
    mainwindow.ui \
    modbus_window.ui \
    tcp_window.ui \
    udp_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -lwsock32 -Ldll -lws2_32 -lwsock32 -lmswsock

RESOURCES += \
    Img.qrc

RC_ICONS = logo.ico # 设置应用图标
