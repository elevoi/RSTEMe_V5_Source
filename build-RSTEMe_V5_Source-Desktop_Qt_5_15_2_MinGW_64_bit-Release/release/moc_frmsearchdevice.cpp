/****************************************************************************
** Meta object code from reading C++ file 'frmsearchdevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/device/frmsearchdevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmsearchdevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmSearchDevice_t {
    QByteArrayData data[15];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmSearchDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmSearchDevice_t qt_meta_stringdata_FrmSearchDevice = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FrmSearchDevice"
QT_MOC_LITERAL(1, 16, 12), // "selectDevice"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "EDeviceInfo"
QT_MOC_LITERAL(4, 42, 3), // "dev"
QT_MOC_LITERAL(5, 46, 8), // "on_error"
QT_MOC_LITERAL(6, 55, 14), // "EDevice::Error"
QT_MOC_LITERAL(7, 70, 3), // "err"
QT_MOC_LITERAL(8, 74, 8), // "on_reply"
QT_MOC_LITERAL(9, 83, 12), // "ERequestUnit"
QT_MOC_LITERAL(10, 96, 7), // "request"
QT_MOC_LITERAL(11, 104, 12), // "on_timerPoll"
QT_MOC_LITERAL(12, 117, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(13, 146, 28), // "on_pushButton_Search_clicked"
QT_MOC_LITERAL(14, 175, 28) // "on_pushButton_addNew_clicked"

    },
    "FrmSearchDevice\0selectDevice\0\0EDeviceInfo\0"
    "dev\0on_error\0EDevice::Error\0err\0"
    "on_reply\0ERequestUnit\0request\0"
    "on_timerPoll\0on_pushButton_Cancel_clicked\0"
    "on_pushButton_Search_clicked\0"
    "on_pushButton_addNew_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmSearchDevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   52,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,
      11,    0,   58,    2, 0x08 /* Private */,
      12,    0,   59,    2, 0x08 /* Private */,
      13,    0,   60,    2, 0x08 /* Private */,
      14,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmSearchDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmSearchDevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectDevice((*reinterpret_cast< EDeviceInfo(*)>(_a[1]))); break;
        case 1: _t->on_error((*reinterpret_cast< EDevice::Error(*)>(_a[1]))); break;
        case 2: _t->on_reply((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 3: _t->on_timerPoll(); break;
        case 4: _t->on_pushButton_Cancel_clicked(); break;
        case 5: _t->on_pushButton_Search_clicked(); break;
        case 6: _t->on_pushButton_addNew_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrmSearchDevice::*)(EDeviceInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrmSearchDevice::selectDevice)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmSearchDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmSearchDevice.data,
    qt_meta_data_FrmSearchDevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmSearchDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmSearchDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmSearchDevice.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmSearchDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FrmSearchDevice::selectDevice(EDeviceInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
