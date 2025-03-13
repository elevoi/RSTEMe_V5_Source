/****************************************************************************
** Meta object code from reading C++ file 'widsensordisplaydigital.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/display/widsensordisplaydigital.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widsensordisplaydigital.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidSensorDisplayDigital_t {
    QByteArrayData data[11];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidSensorDisplayDigital_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidSensorDisplayDigital_t qt_meta_stringdata_WidSensorDisplayDigital = {
    {
QT_MOC_LITERAL(0, 0, 23), // "WidSensorDisplayDigital"
QT_MOC_LITERAL(1, 24, 12), // "removeDevice"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "EDevice*"
QT_MOC_LITERAL(4, 47, 3), // "dev"
QT_MOC_LITERAL(5, 51, 10), // "on_newData"
QT_MOC_LITERAL(6, 62, 2), // "id"
QT_MOC_LITERAL(7, 65, 28), // "on_toolButton_cancel_clicked"
QT_MOC_LITERAL(8, 94, 36), // "on_comboBox_unit_currentIndex..."
QT_MOC_LITERAL(9, 131, 5), // "index"
QT_MOC_LITERAL(10, 137, 42) // "on_comboBox_resolution_curren..."

    },
    "WidSensorDisplayDigital\0removeDevice\0"
    "\0EDevice*\0dev\0on_newData\0id\0"
    "on_toolButton_cancel_clicked\0"
    "on_comboBox_unit_currentIndexChanged\0"
    "index\0on_comboBox_resolution_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidSensorDisplayDigital[] = {

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
       8,    1,   46,    2, 0x08 /* Private */,
      10,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void WidSensorDisplayDigital::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidSensorDisplayDigital *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeDevice((*reinterpret_cast< EDevice*(*)>(_a[1]))); break;
        case 1: _t->on_newData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_toolButton_cancel_clicked(); break;
        case 3: _t->on_comboBox_unit_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_resolution_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidSensorDisplayDigital::*)(EDevice * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidSensorDisplayDigital::removeDevice)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidSensorDisplayDigital::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WidSensorDisplayDigital.data,
    qt_meta_data_WidSensorDisplayDigital,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidSensorDisplayDigital::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidSensorDisplayDigital::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidSensorDisplayDigital.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidSensorDisplayDigital::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void WidSensorDisplayDigital::removeDevice(EDevice * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
