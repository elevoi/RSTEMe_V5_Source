/****************************************************************************
** Meta object code from reading C++ file 'frmsensordisplaydigital.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/display/frmsensordisplaydigital.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmsensordisplaydigital.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmSensorDisplayDigital_t {
    QByteArrayData data[10];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmSensorDisplayDigital_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmSensorDisplayDigital_t qt_meta_stringdata_FrmSensorDisplayDigital = {
    {
QT_MOC_LITERAL(0, 0, 23), // "FrmSensorDisplayDigital"
QT_MOC_LITERAL(1, 24, 10), // "on_newData"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 2), // "id"
QT_MOC_LITERAL(4, 39, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(5, 68, 36), // "on_comboBox_unit_currentIndex..."
QT_MOC_LITERAL(6, 105, 5), // "index"
QT_MOC_LITERAL(7, 111, 42), // "on_comboBox_resolution_curren..."
QT_MOC_LITERAL(8, 154, 26), // "on_toolButton_info_clicked"
QT_MOC_LITERAL(9, 181, 28) // "on_toolButton_config_clicked"

    },
    "FrmSensorDisplayDigital\0on_newData\0\0"
    "id\0on_pushButton_cancel_clicked\0"
    "on_comboBox_unit_currentIndexChanged\0"
    "index\0on_comboBox_resolution_currentIndexChanged\0"
    "on_toolButton_info_clicked\0"
    "on_toolButton_config_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmSensorDisplayDigital[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    1,   48,    2, 0x08 /* Private */,
       7,    1,   51,    2, 0x08 /* Private */,
       8,    0,   54,    2, 0x08 /* Private */,
       9,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmSensorDisplayDigital::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmSensorDisplayDigital *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_newData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_cancel_clicked(); break;
        case 2: _t->on_comboBox_unit_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_comboBox_resolution_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_toolButton_info_clicked(); break;
        case 5: _t->on_toolButton_config_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmSensorDisplayDigital::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmSensorDisplayDigital.data,
    qt_meta_data_FrmSensorDisplayDigital,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmSensorDisplayDigital::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmSensorDisplayDigital::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmSensorDisplayDigital.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmSensorDisplayDigital::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
