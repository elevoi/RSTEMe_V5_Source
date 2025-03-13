/****************************************************************************
** Meta object code from reading C++ file 'frmdeviceicon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/device/frmdeviceicon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmdeviceicon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmDeviceIcon_t {
    QByteArrayData data[10];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmDeviceIcon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmDeviceIcon_t qt_meta_stringdata_FrmDeviceIcon = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FrmDeviceIcon"
QT_MOC_LITERAL(1, 14, 7), // "setIcon"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "path"
QT_MOC_LITERAL(4, 28, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(5, 57, 30), // "on_listWidget_Icon_itemClicked"
QT_MOC_LITERAL(6, 88, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 105, 4), // "item"
QT_MOC_LITERAL(8, 110, 36), // "on_listWidget_Icon_itemDouble..."
QT_MOC_LITERAL(9, 147, 28) // "on_pushButton_Select_clicked"

    },
    "FrmDeviceIcon\0setIcon\0\0path\0"
    "on_pushButton_Cancel_clicked\0"
    "on_listWidget_Icon_itemClicked\0"
    "QListWidgetItem*\0item\0"
    "on_listWidget_Icon_itemDoubleClicked\0"
    "on_pushButton_Select_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmDeviceIcon[] = {

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
       4,    0,   42,    2, 0x08 /* Private */,
       5,    1,   43,    2, 0x08 /* Private */,
       8,    1,   46,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void FrmDeviceIcon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmDeviceIcon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setIcon((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_Cancel_clicked(); break;
        case 2: _t->on_listWidget_Icon_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_listWidget_Icon_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_Select_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrmDeviceIcon::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrmDeviceIcon::setIcon)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmDeviceIcon::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmDeviceIcon.data,
    qt_meta_data_FrmDeviceIcon,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmDeviceIcon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmDeviceIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmDeviceIcon.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmDeviceIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FrmDeviceIcon::setIcon(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
