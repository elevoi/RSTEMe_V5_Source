/****************************************************************************
** Meta object code from reading C++ file 'emanagedevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/manage/emanagedevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emanagedevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EManageDevice_t {
    QByteArrayData data[18];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EManageDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EManageDevice_t qt_meta_stringdata_EManageDevice = {
    {
QT_MOC_LITERAL(0, 0, 13), // "EManageDevice"
QT_MOC_LITERAL(1, 14, 11), // "stateChange"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 21), // "ETypeDef::StateChange"
QT_MOC_LITERAL(4, 49, 5), // "state"
QT_MOC_LITERAL(5, 55, 14), // "connectChanged"
QT_MOC_LITERAL(6, 70, 6), // "status"
QT_MOC_LITERAL(7, 77, 11), // "EDeviceInfo"
QT_MOC_LITERAL(8, 89, 3), // "dev"
QT_MOC_LITERAL(9, 93, 5), // "error"
QT_MOC_LITERAL(10, 99, 14), // "EDevice::Error"
QT_MOC_LITERAL(11, 114, 8), // "EDevice*"
QT_MOC_LITERAL(12, 123, 17), // "on_connectChanged"
QT_MOC_LITERAL(13, 141, 14), // "on_stateChange"
QT_MOC_LITERAL(14, 156, 24), // "on_replySelectDeviceInfo"
QT_MOC_LITERAL(15, 181, 20), // "on_replySelectDevice"
QT_MOC_LITERAL(16, 202, 4), // "edev"
QT_MOC_LITERAL(17, 207, 8) // "on_error"

    },
    "EManageDevice\0stateChange\0\0"
    "ETypeDef::StateChange\0state\0connectChanged\0"
    "status\0EDeviceInfo\0dev\0error\0"
    "EDevice::Error\0EDevice*\0on_connectChanged\0"
    "on_stateChange\0on_replySelectDeviceInfo\0"
    "on_replySelectDevice\0edev\0on_error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EManageDevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    2,   57,    2, 0x06 /* Public */,
       9,    2,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   67,    2, 0x08 /* Private */,
      13,    1,   70,    2, 0x08 /* Private */,
      14,    1,   73,    2, 0x08 /* Private */,
      15,    2,   76,    2, 0x08 /* Private */,
      17,    2,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 11,    9,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 11,    8,   16,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 11,    9,    8,

       0        // eod
};

void EManageDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EManageDevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChange((*reinterpret_cast< ETypeDef::StateChange(*)>(_a[1]))); break;
        case 1: _t->connectChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< EDeviceInfo(*)>(_a[2]))); break;
        case 2: _t->error((*reinterpret_cast< EDevice::Error(*)>(_a[1])),(*reinterpret_cast< EDevice*(*)>(_a[2]))); break;
        case 3: _t->on_connectChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_stateChange((*reinterpret_cast< ETypeDef::StateChange(*)>(_a[1]))); break;
        case 5: _t->on_replySelectDeviceInfo((*reinterpret_cast< EDeviceInfo(*)>(_a[1]))); break;
        case 6: _t->on_replySelectDevice((*reinterpret_cast< EDeviceInfo(*)>(_a[1])),(*reinterpret_cast< EDevice*(*)>(_a[2]))); break;
        case 7: _t->on_error((*reinterpret_cast< EDevice::Error(*)>(_a[1])),(*reinterpret_cast< EDevice*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EDevice* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EDevice* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EDevice* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EManageDevice::*)(ETypeDef::StateChange );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EManageDevice::stateChange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EManageDevice::*)(bool , EDeviceInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EManageDevice::connectChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EManageDevice::*)(EDevice::Error , EDevice * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EManageDevice::error)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EManageDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EManageDevice.data,
    qt_meta_data_EManageDevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EManageDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EManageDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EManageDevice.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EManageDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void EManageDevice::stateChange(ETypeDef::StateChange _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EManageDevice::connectChanged(bool _t1, EDeviceInfo _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EManageDevice::error(EDevice::Error _t1, EDevice * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
