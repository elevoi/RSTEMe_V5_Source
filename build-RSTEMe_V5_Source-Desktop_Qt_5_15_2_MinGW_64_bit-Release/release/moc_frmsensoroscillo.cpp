/****************************************************************************
** Meta object code from reading C++ file 'frmsensoroscillo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/display/frmsensoroscillo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmsensoroscillo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmSensorOscillo_t {
    QByteArrayData data[12];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmSensorOscillo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmSensorOscillo_t qt_meta_stringdata_FrmSensorOscillo = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FrmSensorOscillo"
QT_MOC_LITERAL(1, 17, 16), // "on_newDataDevice"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "EDevice*"
QT_MOC_LITERAL(4, 44, 3), // "dev"
QT_MOC_LITERAL(5, 48, 35), // "on_toolButton_toolCrosshair_c..."
QT_MOC_LITERAL(6, 84, 33), // "on_toolButton_toolCallout_cli..."
QT_MOC_LITERAL(7, 118, 30), // "on_toolButton_toolPlay_clicked"
QT_MOC_LITERAL(8, 149, 31), // "on_toolButton_toolPause_clicked"
QT_MOC_LITERAL(9, 181, 31), // "on_toolButton_toolClear_clicked"
QT_MOC_LITERAL(10, 213, 26), // "on_toolButton_plus_clicked"
QT_MOC_LITERAL(11, 240, 27) // "on_toolButton_minus_clicked"

    },
    "FrmSensorOscillo\0on_newDataDevice\0\0"
    "EDevice*\0dev\0on_toolButton_toolCrosshair_clicked\0"
    "on_toolButton_toolCallout_clicked\0"
    "on_toolButton_toolPlay_clicked\0"
    "on_toolButton_toolPause_clicked\0"
    "on_toolButton_toolClear_clicked\0"
    "on_toolButton_plus_clicked\0"
    "on_toolButton_minus_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmSensorOscillo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmSensorOscillo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmSensorOscillo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_newDataDevice((*reinterpret_cast< EDevice*(*)>(_a[1]))); break;
        case 1: _t->on_toolButton_toolCrosshair_clicked(); break;
        case 2: _t->on_toolButton_toolCallout_clicked(); break;
        case 3: _t->on_toolButton_toolPlay_clicked(); break;
        case 4: _t->on_toolButton_toolPause_clicked(); break;
        case 5: _t->on_toolButton_toolClear_clicked(); break;
        case 6: _t->on_toolButton_plus_clicked(); break;
        case 7: _t->on_toolButton_minus_clicked(); break;
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

QT_INIT_METAOBJECT const QMetaObject FrmSensorOscillo::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmSensorOscillo.data,
    qt_meta_data_FrmSensorOscillo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmSensorOscillo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmSensorOscillo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmSensorOscillo.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmSensorOscillo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
