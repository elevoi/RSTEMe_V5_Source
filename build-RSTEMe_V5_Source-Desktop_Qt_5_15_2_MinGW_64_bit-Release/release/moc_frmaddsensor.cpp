/****************************************************************************
** Meta object code from reading C++ file 'frmaddsensor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/device/frmaddsensor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmaddsensor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmAddSensor_t {
    QByteArrayData data[17];
    char stringdata0[400];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmAddSensor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmAddSensor_t qt_meta_stringdata_FrmAddSensor = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FrmAddSensor"
QT_MOC_LITERAL(1, 13, 5), // "setup"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "EDeviceInfo"
QT_MOC_LITERAL(4, 32, 4), // "info"
QT_MOC_LITERAL(5, 37, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(6, 66, 31), // "on_pushButton_addDevice_clicked"
QT_MOC_LITERAL(7, 98, 33), // "on_comboBox_groupDevice_activ..."
QT_MOC_LITERAL(8, 132, 5), // "index"
QT_MOC_LITERAL(9, 138, 32), // "on_comboBox_typeDevice_activated"
QT_MOC_LITERAL(10, 171, 38), // "on_spinBox_versioneDevice_val..."
QT_MOC_LITERAL(11, 210, 4), // "arg1"
QT_MOC_LITERAL(12, 215, 35), // "on_lineEdit_serialNumber_text..."
QT_MOC_LITERAL(13, 251, 43), // "on_comboBox_groupDevice_curre..."
QT_MOC_LITERAL(14, 295, 41), // "on_comboBox_typeDevice_curren..."
QT_MOC_LITERAL(15, 337, 31), // "on_pushButton_writeFile_clicked"
QT_MOC_LITERAL(16, 369, 30) // "on_pushButton_openFile_clicked"

    },
    "FrmAddSensor\0setup\0\0EDeviceInfo\0info\0"
    "on_pushButton_Cancel_clicked\0"
    "on_pushButton_addDevice_clicked\0"
    "on_comboBox_groupDevice_activated\0"
    "index\0on_comboBox_typeDevice_activated\0"
    "on_spinBox_versioneDevice_valueChanged\0"
    "arg1\0on_lineEdit_serialNumber_textEdited\0"
    "on_comboBox_groupDevice_currentIndexChanged\0"
    "on_comboBox_typeDevice_currentTextChanged\0"
    "on_pushButton_writeFile_clicked\0"
    "on_pushButton_openFile_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmAddSensor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      10,    1,   80,    2, 0x08 /* Private */,
      12,    1,   83,    2, 0x08 /* Private */,
      13,    1,   86,    2, 0x08 /* Private */,
      14,    1,   89,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmAddSensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmAddSensor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setup((*reinterpret_cast< EDeviceInfo(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_Cancel_clicked(); break;
        case 2: _t->on_pushButton_addDevice_clicked(); break;
        case 3: _t->on_comboBox_groupDevice_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_typeDevice_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_spinBox_versioneDevice_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_serialNumber_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_comboBox_groupDevice_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_comboBox_typeDevice_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_writeFile_clicked(); break;
        case 10: _t->on_pushButton_openFile_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrmAddSensor::*)(EDeviceInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrmAddSensor::setup)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmAddSensor::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmAddSensor.data,
    qt_meta_data_FrmAddSensor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmAddSensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmAddSensor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmAddSensor.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmAddSensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void FrmAddSensor::setup(EDeviceInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
