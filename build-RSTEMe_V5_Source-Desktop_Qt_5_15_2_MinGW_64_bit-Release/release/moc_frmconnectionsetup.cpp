/****************************************************************************
** Meta object code from reading C++ file 'frmconnectionsetup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/comm/frmconnectionsetup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmconnectionsetup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmConnectionSetup_t {
    QByteArrayData data[10];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmConnectionSetup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmConnectionSetup_t qt_meta_stringdata_FrmConnectionSetup = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FrmConnectionSetup"
QT_MOC_LITERAL(1, 19, 11), // "stateChange"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21), // "ETypeDef::StateChange"
QT_MOC_LITERAL(4, 54, 5), // "state"
QT_MOC_LITERAL(5, 60, 17), // "on_connectChanged"
QT_MOC_LITERAL(6, 78, 6), // "status"
QT_MOC_LITERAL(7, 85, 28), // "on_pushButton_Active_clicked"
QT_MOC_LITERAL(8, 114, 36), // "on_pushButton_ConnectComPort_..."
QT_MOC_LITERAL(9, 151, 28) // "on_pushButton_Cancel_clicked"

    },
    "FrmConnectionSetup\0stateChange\0\0"
    "ETypeDef::StateChange\0state\0"
    "on_connectChanged\0status\0"
    "on_pushButton_Active_clicked\0"
    "on_pushButton_ConnectComPort_clicked\0"
    "on_pushButton_Cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmConnectionSetup[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   42,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,
       8,    0,   46,    2, 0x08 /* Private */,
       9,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmConnectionSetup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmConnectionSetup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChange((*reinterpret_cast< ETypeDef::StateChange(*)>(_a[1]))); break;
        case 1: _t->on_connectChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_Active_clicked(); break;
        case 3: _t->on_pushButton_ConnectComPort_clicked(); break;
        case 4: _t->on_pushButton_Cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrmConnectionSetup::*)(ETypeDef::StateChange );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrmConnectionSetup::stateChange)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmConnectionSetup::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmConnectionSetup.data,
    qt_meta_data_FrmConnectionSetup,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmConnectionSetup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmConnectionSetup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmConnectionSetup.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmConnectionSetup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FrmConnectionSetup::stateChange(ETypeDef::StateChange _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
