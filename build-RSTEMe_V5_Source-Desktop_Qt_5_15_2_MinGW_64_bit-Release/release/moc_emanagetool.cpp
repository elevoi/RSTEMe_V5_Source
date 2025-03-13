/****************************************************************************
** Meta object code from reading C++ file 'emanagetool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/manage/emanagetool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emanagetool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EManageTool_t {
    QByteArrayData data[13];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EManageTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EManageTool_t qt_meta_stringdata_EManageTool = {
    {
QT_MOC_LITERAL(0, 0, 11), // "EManageTool"
QT_MOC_LITERAL(1, 12, 21), // "replySelectDeviceInfo"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 11), // "EDeviceInfo"
QT_MOC_LITERAL(4, 47, 3), // "dev"
QT_MOC_LITERAL(5, 51, 17), // "replySelectDevice"
QT_MOC_LITERAL(6, 69, 8), // "EDevice*"
QT_MOC_LITERAL(7, 78, 4), // "edev"
QT_MOC_LITERAL(8, 83, 11), // "stateChange"
QT_MOC_LITERAL(9, 95, 21), // "ETypeDef::StateChange"
QT_MOC_LITERAL(10, 117, 5), // "state"
QT_MOC_LITERAL(11, 123, 24), // "on_replySelectDeviceInfo"
QT_MOC_LITERAL(12, 148, 14) // "on_stateChange"

    },
    "EManageTool\0replySelectDeviceInfo\0\0"
    "EDeviceInfo\0dev\0replySelectDevice\0"
    "EDevice*\0edev\0stateChange\0"
    "ETypeDef::StateChange\0state\0"
    "on_replySelectDeviceInfo\0on_stateChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EManageTool[] = {

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
       5,    2,   42,    2, 0x06 /* Public */,
       8,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   50,    2, 0x08 /* Private */,
      12,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void EManageTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EManageTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replySelectDeviceInfo((*reinterpret_cast< EDeviceInfo(*)>(_a[1]))); break;
        case 1: _t->replySelectDevice((*reinterpret_cast< EDeviceInfo(*)>(_a[1])),(*reinterpret_cast< EDevice*(*)>(_a[2]))); break;
        case 2: _t->stateChange((*reinterpret_cast< ETypeDef::StateChange(*)>(_a[1]))); break;
        case 3: _t->on_replySelectDeviceInfo((*reinterpret_cast< EDeviceInfo(*)>(_a[1]))); break;
        case 4: _t->on_stateChange((*reinterpret_cast< ETypeDef::StateChange(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            using _t = void (EManageTool::*)(EDeviceInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EManageTool::replySelectDeviceInfo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EManageTool::*)(EDeviceInfo , EDevice * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EManageTool::replySelectDevice)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EManageTool::*)(ETypeDef::StateChange );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EManageTool::stateChange)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EManageTool::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EManageTool.data,
    qt_meta_data_EManageTool,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EManageTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EManageTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EManageTool.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EManageTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void EManageTool::replySelectDeviceInfo(EDeviceInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EManageTool::replySelectDevice(EDeviceInfo _t1, EDevice * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EManageTool::stateChange(ETypeDef::StateChange _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
