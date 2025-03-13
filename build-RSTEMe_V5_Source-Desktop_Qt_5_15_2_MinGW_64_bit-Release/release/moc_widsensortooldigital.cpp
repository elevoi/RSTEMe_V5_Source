/****************************************************************************
** Meta object code from reading C++ file 'widsensortooldigital.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/display/widsensortooldigital.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widsensortooldigital.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidSensorToolDigital_t {
    QByteArrayData data[17];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidSensorToolDigital_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidSensorToolDigital_t qt_meta_stringdata_WidSensorToolDigital = {
    {
QT_MOC_LITERAL(0, 0, 20), // "WidSensorToolDigital"
QT_MOC_LITERAL(1, 21, 12), // "removeDevice"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "EDevice*"
QT_MOC_LITERAL(4, 44, 3), // "dev"
QT_MOC_LITERAL(5, 48, 11), // "updatePoint"
QT_MOC_LITERAL(6, 60, 24), // "QtCharts::QSplineSeries*"
QT_MOC_LITERAL(7, 85, 6), // "series"
QT_MOC_LITERAL(8, 92, 5), // "value"
QT_MOC_LITERAL(9, 98, 10), // "on_newData"
QT_MOC_LITERAL(10, 109, 2), // "id"
QT_MOC_LITERAL(11, 112, 8), // "on_error"
QT_MOC_LITERAL(12, 121, 14), // "EDevice::Error"
QT_MOC_LITERAL(13, 136, 3), // "err"
QT_MOC_LITERAL(14, 140, 26), // "on_toolButton_info_clicked"
QT_MOC_LITERAL(15, 167, 27), // "on_toolButton_close_clicked"
QT_MOC_LITERAL(16, 195, 27) // "on_toolButton_setup_clicked"

    },
    "WidSensorToolDigital\0removeDevice\0\0"
    "EDevice*\0dev\0updatePoint\0"
    "QtCharts::QSplineSeries*\0series\0value\0"
    "on_newData\0id\0on_error\0EDevice::Error\0"
    "err\0on_toolButton_info_clicked\0"
    "on_toolButton_close_clicked\0"
    "on_toolButton_setup_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidSensorToolDigital[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    2,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   57,    2, 0x08 /* Private */,
      11,    1,   60,    2, 0x08 /* Private */,
      14,    0,   63,    2, 0x08 /* Private */,
      15,    0,   64,    2, 0x08 /* Private */,
      16,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QReal,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidSensorToolDigital::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidSensorToolDigital *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeDevice((*reinterpret_cast< EDevice*(*)>(_a[1]))); break;
        case 1: _t->updatePoint((*reinterpret_cast< QtCharts::QSplineSeries*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 2: _t->on_newData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_error((*reinterpret_cast< EDevice::Error(*)>(_a[1]))); break;
        case 4: _t->on_toolButton_info_clicked(); break;
        case 5: _t->on_toolButton_close_clicked(); break;
        case 6: _t->on_toolButton_setup_clicked(); break;
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
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QtCharts::QSplineSeries* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidSensorToolDigital::*)(EDevice * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidSensorToolDigital::removeDevice)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WidSensorToolDigital::*)(QtCharts::QSplineSeries * , qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidSensorToolDigital::updatePoint)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidSensorToolDigital::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WidSensorToolDigital.data,
    qt_meta_data_WidSensorToolDigital,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidSensorToolDigital::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidSensorToolDigital::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidSensorToolDigital.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidSensorToolDigital::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void WidSensorToolDigital::removeDevice(EDevice * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WidSensorToolDigital::updatePoint(QtCharts::QSplineSeries * _t1, qreal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
