/****************************************************************************
** Meta object code from reading C++ file 'esensor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/device/def/esensor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'esensor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ESensor_t {
    QByteArrayData data[14];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ESensor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ESensor_t qt_meta_stringdata_ESensor = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ESensor"
QT_MOC_LITERAL(1, 8, 7), // "newData"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 2), // "id"
QT_MOC_LITERAL(4, 20, 13), // "newDataDevice"
QT_MOC_LITERAL(5, 34, 8), // "EDevice*"
QT_MOC_LITERAL(6, 43, 3), // "dev"
QT_MOC_LITERAL(7, 47, 5), // "error"
QT_MOC_LITERAL(8, 53, 14), // "EDevice::Error"
QT_MOC_LITERAL(9, 68, 3), // "err"
QT_MOC_LITERAL(10, 72, 9), // "on_result"
QT_MOC_LITERAL(11, 82, 12), // "ERequestUnit"
QT_MOC_LITERAL(12, 95, 7), // "request"
QT_MOC_LITERAL(13, 103, 8) // "on_error"

    },
    "ESensor\0newData\0\0id\0newDataDevice\0"
    "EDevice*\0dev\0error\0EDevice::Error\0err\0"
    "on_result\0ERequestUnit\0request\0on_error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ESensor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       7,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   48,    2, 0x08 /* Private */,
      13,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void ESensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ESensor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->newDataDevice((*reinterpret_cast< EDevice*(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< EDevice::Error(*)>(_a[1]))); break;
        case 3: _t->on_result((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 4: _t->on_error((*reinterpret_cast< EDevice::Error(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EDevice* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ESensor::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ESensor::newData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ESensor::*)(EDevice * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ESensor::newDataDevice)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ESensor::*)(EDevice::Error );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ESensor::error)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ESensor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ESensor.data,
    qt_meta_data_ESensor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ESensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ESensor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ESensor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ESensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ESensor::newData(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ESensor::newDataDevice(EDevice * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ESensor::error(EDevice::Error _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
