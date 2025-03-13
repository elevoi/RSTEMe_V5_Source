/****************************************************************************
** Meta object code from reading C++ file 'frmdevicetable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/device/frmdevicetable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmdevicetable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmDeviceTable_t {
    QByteArrayData data[11];
    char stringdata0[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmDeviceTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmDeviceTable_t qt_meta_stringdata_FrmDeviceTable = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FrmDeviceTable"
QT_MOC_LITERAL(1, 15, 21), // "replySelectDeviceInfo"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "EDeviceInfo"
QT_MOC_LITERAL(4, 50, 3), // "dev"
QT_MOC_LITERAL(5, 54, 35), // "on_toolButton_groupSoftware_c..."
QT_MOC_LITERAL(6, 90, 33), // "on_toolButton_groupSensor_cli..."
QT_MOC_LITERAL(7, 124, 33), // "on_toolButton_groupModule_cli..."
QT_MOC_LITERAL(8, 158, 33), // "on_toolButton_groupSystem_cli..."
QT_MOC_LITERAL(9, 192, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(10, 221, 34) // "on_pushButton_selectDevice_cl..."

    },
    "FrmDeviceTable\0replySelectDeviceInfo\0"
    "\0EDeviceInfo\0dev\0on_toolButton_groupSoftware_clicked\0"
    "on_toolButton_groupSensor_clicked\0"
    "on_toolButton_groupModule_clicked\0"
    "on_toolButton_groupSystem_clicked\0"
    "on_pushButton_Cancel_clicked\0"
    "on_pushButton_selectDevice_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmDeviceTable[] = {

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
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmDeviceTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmDeviceTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replySelectDeviceInfo((*reinterpret_cast< EDeviceInfo(*)>(_a[1]))); break;
        case 1: _t->on_toolButton_groupSoftware_clicked(); break;
        case 2: _t->on_toolButton_groupSensor_clicked(); break;
        case 3: _t->on_toolButton_groupModule_clicked(); break;
        case 4: _t->on_toolButton_groupSystem_clicked(); break;
        case 5: _t->on_pushButton_Cancel_clicked(); break;
        case 6: _t->on_pushButton_selectDevice_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrmDeviceTable::*)(EDeviceInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrmDeviceTable::replySelectDeviceInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmDeviceTable::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmDeviceTable.data,
    qt_meta_data_FrmDeviceTable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmDeviceTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmDeviceTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmDeviceTable.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmDeviceTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FrmDeviceTable::replySelectDeviceInfo(EDeviceInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
