/****************************************************************************
** Meta object code from reading C++ file 'frmrepairmodbusconnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/device/repair/frmrepairmodbusconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmrepairmodbusconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmRepairModbusConnection_t {
    QByteArrayData data[8];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmRepairModbusConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmRepairModbusConnection_t qt_meta_stringdata_FrmRepairModbusConnection = {
    {
QT_MOC_LITERAL(0, 0, 25), // "FrmRepairModbusConnection"
QT_MOC_LITERAL(1, 26, 8), // "on_reply"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 12), // "ERequestUnit"
QT_MOC_LITERAL(4, 49, 7), // "request"
QT_MOC_LITERAL(5, 57, 16), // "on_errorOccurred"
QT_MOC_LITERAL(6, 74, 12), // "on_timerPoll"
QT_MOC_LITERAL(7, 87, 27) // "on_pushButton_Start_clicked"

    },
    "FrmRepairModbusConnection\0on_reply\0\0"
    "ERequestUnit\0request\0on_errorOccurred\0"
    "on_timerPoll\0on_pushButton_Start_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmRepairModbusConnection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,
       6,    0,   40,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmRepairModbusConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmRepairModbusConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_reply((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 1: _t->on_errorOccurred((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 2: _t->on_timerPoll(); break;
        case 3: _t->on_pushButton_Start_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmRepairModbusConnection::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmRepairModbusConnection.data,
    qt_meta_data_FrmRepairModbusConnection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmRepairModbusConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmRepairModbusConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmRepairModbusConnection.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmRepairModbusConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
