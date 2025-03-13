/****************************************************************************
** Meta object code from reading C++ file 'econnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/comm/econnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'econnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EConnection_t {
    QByteArrayData data[15];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EConnection_t qt_meta_stringdata_EConnection = {
    {
QT_MOC_LITERAL(0, 0, 11), // "EConnection"
QT_MOC_LITERAL(1, 12, 5), // "reply"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "ERequestUnit"
QT_MOC_LITERAL(4, 32, 7), // "request"
QT_MOC_LITERAL(5, 40, 13), // "modbusRequest"
QT_MOC_LITERAL(6, 54, 14), // "connectChanged"
QT_MOC_LITERAL(7, 69, 6), // "status"
QT_MOC_LITERAL(8, 76, 13), // "errorOccurred"
QT_MOC_LITERAL(9, 90, 5), // "error"
QT_MOC_LITERAL(10, 96, 20), // "QModbusDevice::Error"
QT_MOC_LITERAL(11, 117, 12), // "on_timerPoll"
QT_MOC_LITERAL(12, 130, 12), // "on_connected"
QT_MOC_LITERAL(13, 143, 8), // "on_error"
QT_MOC_LITERAL(14, 152, 8) // "on_reply"

    },
    "EConnection\0reply\0\0ERequestUnit\0request\0"
    "modbusRequest\0connectChanged\0status\0"
    "errorOccurred\0error\0QModbusDevice::Error\0"
    "on_timerPoll\0on_connected\0on_error\0"
    "on_reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EConnection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       8,    1,   68,    2, 0x06 /* Public */,
       9,    1,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   74,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x08 /* Private */,
      13,    1,   78,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 10,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 10,    9,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void EConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reply((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 1: _t->modbusRequest((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 2: _t->connectChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->errorOccurred((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 4: _t->error((*reinterpret_cast< QModbusDevice::Error(*)>(_a[1]))); break;
        case 5: _t->on_timerPoll(); break;
        case 6: _t->on_connected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_error((*reinterpret_cast< QModbusDevice::Error(*)>(_a[1]))); break;
        case 8: _t->on_reply((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EConnection::*)(ERequestUnit );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EConnection::reply)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EConnection::*)(ERequestUnit );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EConnection::modbusRequest)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EConnection::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EConnection::connectChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EConnection::*)(ERequestUnit );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EConnection::errorOccurred)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (EConnection::*)(QModbusDevice::Error );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EConnection::error)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EConnection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EConnection.data,
    qt_meta_data_EConnection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EConnection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void EConnection::reply(ERequestUnit _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EConnection::modbusRequest(ERequestUnit _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EConnection::connectChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EConnection::errorOccurred(ERequestUnit _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EConnection::error(QModbusDevice::Error _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
