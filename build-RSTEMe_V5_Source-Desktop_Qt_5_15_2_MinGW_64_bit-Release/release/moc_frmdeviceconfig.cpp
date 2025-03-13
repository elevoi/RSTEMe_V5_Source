/****************************************************************************
** Meta object code from reading C++ file 'frmdeviceconfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/control/frmdeviceconfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmdeviceconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmDeviceConfig_t {
    QByteArrayData data[14];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmDeviceConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmDeviceConfig_t qt_meta_stringdata_FrmDeviceConfig = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FrmDeviceConfig"
QT_MOC_LITERAL(1, 16, 10), // "on_newData"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "id"
QT_MOC_LITERAL(4, 31, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(5, 60, 29), // "on_toolButton_setZero_clicked"
QT_MOC_LITERAL(6, 90, 35), // "on_toolButton_setSampleTime_c..."
QT_MOC_LITERAL(7, 126, 31), // "on_toolButton_clearZero_clicked"
QT_MOC_LITERAL(8, 158, 36), // "on_comboBox_unit_currentIndex..."
QT_MOC_LITERAL(9, 195, 5), // "index"
QT_MOC_LITERAL(10, 201, 42), // "on_comboBox_resolution_curren..."
QT_MOC_LITERAL(11, 244, 32), // "on_lineEdit_Zero_editingFinished"
QT_MOC_LITERAL(12, 277, 36), // "on_checkBox_tempCompensation_..."
QT_MOC_LITERAL(13, 314, 7) // "checked"

    },
    "FrmDeviceConfig\0on_newData\0\0id\0"
    "on_pushButton_cancel_clicked\0"
    "on_toolButton_setZero_clicked\0"
    "on_toolButton_setSampleTime_clicked\0"
    "on_toolButton_clearZero_clicked\0"
    "on_comboBox_unit_currentIndexChanged\0"
    "index\0on_comboBox_resolution_currentIndexChanged\0"
    "on_lineEdit_Zero_editingFinished\0"
    "on_checkBox_tempCompensation_toggled\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmDeviceConfig[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    0,   62,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
      10,    1,   69,    2, 0x08 /* Private */,
      11,    0,   72,    2, 0x08 /* Private */,
      12,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,

       0        // eod
};

void FrmDeviceConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmDeviceConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_newData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_cancel_clicked(); break;
        case 2: _t->on_toolButton_setZero_clicked(); break;
        case 3: _t->on_toolButton_setSampleTime_clicked(); break;
        case 4: _t->on_toolButton_clearZero_clicked(); break;
        case 5: _t->on_comboBox_unit_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_resolution_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_lineEdit_Zero_editingFinished(); break;
        case 8: _t->on_checkBox_tempCompensation_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmDeviceConfig::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmDeviceConfig.data,
    qt_meta_data_FrmDeviceConfig,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmDeviceConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmDeviceConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmDeviceConfig.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmDeviceConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
