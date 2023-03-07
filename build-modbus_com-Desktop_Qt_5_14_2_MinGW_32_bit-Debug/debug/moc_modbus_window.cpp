/****************************************************************************
** Meta object code from reading C++ file 'modbus_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../modbus_com/modbus_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbus_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Modbus_Window_t {
    QByteArrayData data[16];
    char stringdata0[331];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Modbus_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Modbus_Window_t qt_meta_stringdata_Modbus_Window = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Modbus_Window"
QT_MOC_LITERAL(1, 14, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 26), // "on_actionConnect_triggered"
QT_MOC_LITERAL(4, 66, 29), // "on_actionDisconnect_triggered"
QT_MOC_LITERAL(5, 96, 26), // "on_actionRefresh_triggered"
QT_MOC_LITERAL(6, 123, 25), // "on_actionConfig_triggered"
QT_MOC_LITERAL(7, 149, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(8, 173, 25), // "on_pushButtonRead_clicked"
QT_MOC_LITERAL(9, 199, 26), // "on_pushButtonWrite_clicked"
QT_MOC_LITERAL(10, 226, 25), // "on_pushButtonSend_clicked"
QT_MOC_LITERAL(11, 252, 23), // "on_checkBoxAuto_clicked"
QT_MOC_LITERAL(12, 276, 7), // "checked"
QT_MOC_LITERAL(13, 284, 14), // "ReadSerialData"
QT_MOC_LITERAL(14, 299, 12), // "ChartDisplay"
QT_MOC_LITERAL(15, 312, 18) // "on_BackBtn_clicked"

    },
    "Modbus_Window\0on_actionExit_triggered\0"
    "\0on_actionConnect_triggered\0"
    "on_actionDisconnect_triggered\0"
    "on_actionRefresh_triggered\0"
    "on_actionConfig_triggered\0"
    "on_actionSave_triggered\0"
    "on_pushButtonRead_clicked\0"
    "on_pushButtonWrite_clicked\0"
    "on_pushButtonSend_clicked\0"
    "on_checkBoxAuto_clicked\0checked\0"
    "ReadSerialData\0ChartDisplay\0"
    "on_BackBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Modbus_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    1,   88,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Modbus_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Modbus_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionExit_triggered(); break;
        case 1: _t->on_actionConnect_triggered(); break;
        case 2: _t->on_actionDisconnect_triggered(); break;
        case 3: _t->on_actionRefresh_triggered(); break;
        case 4: _t->on_actionConfig_triggered(); break;
        case 5: _t->on_actionSave_triggered(); break;
        case 6: _t->on_pushButtonRead_clicked(); break;
        case 7: _t->on_pushButtonWrite_clicked(); break;
        case 8: _t->on_pushButtonSend_clicked(); break;
        case 9: _t->on_checkBoxAuto_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->ReadSerialData(); break;
        case 11: _t->ChartDisplay(); break;
        case 12: _t->on_BackBtn_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Modbus_Window::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Modbus_Window.data,
    qt_meta_data_Modbus_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Modbus_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Modbus_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Modbus_Window.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Modbus_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
