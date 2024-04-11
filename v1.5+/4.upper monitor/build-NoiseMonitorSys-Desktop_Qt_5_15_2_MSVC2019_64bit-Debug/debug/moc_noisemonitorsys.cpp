/****************************************************************************
** Meta object code from reading C++ file 'noisemonitorsys.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../NoiseMonitorSys/noisemonitorsys.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'noisemonitorsys.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NoiseMonitorSys_t {
    QByteArrayData data[10];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NoiseMonitorSys_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NoiseMonitorSys_t qt_meta_stringdata_NoiseMonitorSys = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NoiseMonitorSys"
QT_MOC_LITERAL(1, 16, 30), // "on_ChooseDevice_Button_clicked"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 28), // "on_CalHisData_Button_clicked"
QT_MOC_LITERAL(4, 77, 25), // "on_SaveCSV_Button_clicked"
QT_MOC_LITERAL(5, 103, 23), // "on_Start_Button_clicked"
QT_MOC_LITERAL(6, 127, 22), // "on_Stop_Button_clicked"
QT_MOC_LITERAL(7, 150, 25), // "on_Connect_Button_clicked"
QT_MOC_LITERAL(8, 176, 31), // "on_DeviceMonitor_Button_clicked"
QT_MOC_LITERAL(9, 208, 27) // "on_MaxWindow_Button_clicked"

    },
    "NoiseMonitorSys\0on_ChooseDevice_Button_clicked\0"
    "\0on_CalHisData_Button_clicked\0"
    "on_SaveCSV_Button_clicked\0"
    "on_Start_Button_clicked\0on_Stop_Button_clicked\0"
    "on_Connect_Button_clicked\0"
    "on_DeviceMonitor_Button_clicked\0"
    "on_MaxWindow_Button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NoiseMonitorSys[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
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

void NoiseMonitorSys::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NoiseMonitorSys *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ChooseDevice_Button_clicked(); break;
        case 1: _t->on_CalHisData_Button_clicked(); break;
        case 2: _t->on_SaveCSV_Button_clicked(); break;
        case 3: _t->on_Start_Button_clicked(); break;
        case 4: _t->on_Stop_Button_clicked(); break;
        case 5: _t->on_Connect_Button_clicked(); break;
        case 6: _t->on_DeviceMonitor_Button_clicked(); break;
        case 7: _t->on_MaxWindow_Button_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject NoiseMonitorSys::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_NoiseMonitorSys.data,
    qt_meta_data_NoiseMonitorSys,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NoiseMonitorSys::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NoiseMonitorSys::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NoiseMonitorSys.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int NoiseMonitorSys::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
