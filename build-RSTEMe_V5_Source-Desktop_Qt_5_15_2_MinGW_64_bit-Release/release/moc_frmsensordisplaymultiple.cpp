/****************************************************************************
** Meta object code from reading C++ file 'frmsensordisplaymultiple.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/display/frmsensordisplaymultiple.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmsensordisplaymultiple.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmSensorDisplayMultiple_t {
    QByteArrayData data[8];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmSensorDisplayMultiple_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmSensorDisplayMultiple_t qt_meta_stringdata_FrmSensorDisplayMultiple = {
    {
QT_MOC_LITERAL(0, 0, 24), // "FrmSensorDisplayMultiple"
QT_MOC_LITERAL(1, 25, 15), // "on_removeDevice"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 8), // "EDevice*"
QT_MOC_LITERAL(4, 51, 3), // "dev"
QT_MOC_LITERAL(5, 55, 28), // "on_toolButton_cancel_clicked"
QT_MOC_LITERAL(6, 84, 30), // "on_spinBox_rowMax_valueChanged"
QT_MOC_LITERAL(7, 115, 4) // "arg1"

    },
    "FrmSensorDisplayMultiple\0on_removeDevice\0"
    "\0EDevice*\0dev\0on_toolButton_cancel_clicked\0"
    "on_spinBox_rowMax_valueChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmSensorDisplayMultiple[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       5,    0,   32,    2, 0x08 /* Private */,
       6,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void FrmSensorDisplayMultiple::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmSensorDisplayMultiple *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_removeDevice((*reinterpret_cast< EDevice*(*)>(_a[1]))); break;
        case 1: _t->on_toolButton_cancel_clicked(); break;
        case 2: _t->on_spinBox_rowMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EDevice* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmSensorDisplayMultiple::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmSensorDisplayMultiple.data,
    qt_meta_data_FrmSensorDisplayMultiple,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmSensorDisplayMultiple::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmSensorDisplayMultiple::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmSensorDisplayMultiple.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmSensorDisplayMultiple::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
