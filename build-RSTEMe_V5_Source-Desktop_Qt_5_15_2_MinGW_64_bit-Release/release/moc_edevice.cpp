/****************************************************************************
** Meta object code from reading C++ file 'edevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/device/edevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EDevice_t {
    QByteArrayData data[16];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EDevice_t qt_meta_stringdata_EDevice = {
    {
QT_MOC_LITERAL(0, 0, 7), // "EDevice"
QT_MOC_LITERAL(1, 8, 6), // "result"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 12), // "ERequestUnit"
QT_MOC_LITERAL(4, 29, 7), // "request"
QT_MOC_LITERAL(5, 37, 5), // "error"
QT_MOC_LITERAL(6, 43, 14), // "EDevice::Error"
QT_MOC_LITERAL(7, 58, 3), // "err"
QT_MOC_LITERAL(8, 62, 14), // "connectChanged"
QT_MOC_LITERAL(9, 77, 6), // "status"
QT_MOC_LITERAL(10, 84, 8), // "finished"
QT_MOC_LITERAL(11, 93, 17), // "on_connectChanged"
QT_MOC_LITERAL(12, 111, 8), // "on_reply"
QT_MOC_LITERAL(13, 120, 16), // "on_errorOccurred"
QT_MOC_LITERAL(14, 137, 16), // "on_modbusRequest"
QT_MOC_LITERAL(15, 154, 12) // "on_timerPoll"

    },
    "EDevice\0result\0\0ERequestUnit\0request\0"
    "error\0EDevice::Error\0err\0connectChanged\0"
    "status\0finished\0on_connectChanged\0"
    "on_reply\0on_errorOccurred\0on_modbusRequest\0"
    "on_timerPoll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EDevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       8,    1,   65,    2, 0x06 /* Public */,
      10,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   69,    2, 0x08 /* Private */,
      12,    1,   72,    2, 0x08 /* Private */,
      13,    1,   75,    2, 0x08 /* Private */,
      14,    1,   78,    2, 0x08 /* Private */,
      15,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void EDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EDevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->result((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 1: _t->error((*reinterpret_cast< EDevice::Error(*)>(_a[1]))); break;
        case 2: _t->connectChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->finished(); break;
        case 4: _t->on_connectChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_reply((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 6: _t->on_errorOccurred((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 7: _t->on_modbusRequest((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 8: _t->on_timerPoll(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EDevice::*)(ERequestUnit );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EDevice::result)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EDevice::*)(EDevice::Error );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EDevice::error)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EDevice::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EDevice::connectChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EDevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EDevice::finished)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EDevice.data,
    qt_meta_data_EDevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EDevice.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void EDevice::result(ERequestUnit _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EDevice::error(EDevice::Error _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EDevice::connectChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EDevice::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
