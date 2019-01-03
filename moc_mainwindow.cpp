/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[459];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "refreshLCD"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "updatePlot"
QT_MOC_LITERAL(4, 34, 21), // "on_openButton_clicked"
QT_MOC_LITERAL(5, 56, 18), // "on_testbtn_clicked"
QT_MOC_LITERAL(6, 75, 35), // "on_actionAbout_how_to_use_tri..."
QT_MOC_LITERAL(7, 111, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(8, 133, 21), // "on_checkBox_3_clicked"
QT_MOC_LITERAL(9, 155, 21), // "on_checkBox_4_clicked"
QT_MOC_LITERAL(10, 177, 21), // "on_checkBox_5_clicked"
QT_MOC_LITERAL(11, 199, 31), // "on_actionCurve_config_triggered"
QT_MOC_LITERAL(12, 231, 32), // "on_actionSystem_config_triggered"
QT_MOC_LITERAL(13, 264, 31), // "on_actionDisplacement_triggered"
QT_MOC_LITERAL(14, 296, 30), // "on_actionMotor_speed_triggered"
QT_MOC_LITERAL(15, 327, 30), // "on_actionMotor_accel_triggered"
QT_MOC_LITERAL(16, 358, 26), // "on_actionCurrent_triggered"
QT_MOC_LITERAL(17, 385, 30), // "on_actionBus_voltage_triggered"
QT_MOC_LITERAL(18, 416, 23), // "on_openButton_2_clicked"
QT_MOC_LITERAL(19, 440, 18) // "on_SendBtn_clicked"

    },
    "MainWindow\0refreshLCD\0\0updatePlot\0"
    "on_openButton_clicked\0on_testbtn_clicked\0"
    "on_actionAbout_how_to_use_triggered\0"
    "on_checkBox_2_clicked\0on_checkBox_3_clicked\0"
    "on_checkBox_4_clicked\0on_checkBox_5_clicked\0"
    "on_actionCurve_config_triggered\0"
    "on_actionSystem_config_triggered\0"
    "on_actionDisplacement_triggered\0"
    "on_actionMotor_speed_triggered\0"
    "on_actionMotor_accel_triggered\0"
    "on_actionCurrent_triggered\0"
    "on_actionBus_voltage_triggered\0"
    "on_openButton_2_clicked\0on_SendBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshLCD(); break;
        case 1: _t->updatePlot(); break;
        case 2: _t->on_openButton_clicked(); break;
        case 3: _t->on_testbtn_clicked(); break;
        case 4: _t->on_actionAbout_how_to_use_triggered(); break;
        case 5: _t->on_checkBox_2_clicked(); break;
        case 6: _t->on_checkBox_3_clicked(); break;
        case 7: _t->on_checkBox_4_clicked(); break;
        case 8: _t->on_checkBox_5_clicked(); break;
        case 9: _t->on_actionCurve_config_triggered(); break;
        case 10: _t->on_actionSystem_config_triggered(); break;
        case 11: _t->on_actionDisplacement_triggered(); break;
        case 12: _t->on_actionMotor_speed_triggered(); break;
        case 13: _t->on_actionMotor_accel_triggered(); break;
        case 14: _t->on_actionCurrent_triggered(); break;
        case 15: _t->on_actionBus_voltage_triggered(); break;
        case 16: _t->on_openButton_2_clicked(); break;
        case 17: _t->on_SendBtn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
