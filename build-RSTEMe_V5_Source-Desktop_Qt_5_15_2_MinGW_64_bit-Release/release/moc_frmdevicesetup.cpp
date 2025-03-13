/****************************************************************************
** Meta object code from reading C++ file 'frmdevicesetup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/device/frmdevicesetup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmdevicesetup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmDeviceSetup_t {
    QByteArrayData data[23];
    char stringdata0[445];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmDeviceSetup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmDeviceSetup_t qt_meta_stringdata_FrmDeviceSetup = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FrmDeviceSetup"
QT_MOC_LITERAL(1, 15, 11), // "stateChange"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 21), // "ETypeDef::StateChange"
QT_MOC_LITERAL(4, 50, 5), // "state"
QT_MOC_LITERAL(5, 56, 8), // "on_setup"
QT_MOC_LITERAL(6, 65, 11), // "EDeviceInfo"
QT_MOC_LITERAL(7, 77, 3), // "dev"
QT_MOC_LITERAL(8, 81, 31), // "on_pushButton_addDevice_clicked"
QT_MOC_LITERAL(9, 113, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(10, 142, 28), // "on_pushButton_remove_clicked"
QT_MOC_LITERAL(11, 171, 26), // "on_pushButton_save_clicked"
QT_MOC_LITERAL(12, 198, 30), // "on_pushButton_saveList_clicked"
QT_MOC_LITERAL(13, 229, 29), // "on_treeWidgetDevice_collapsed"
QT_MOC_LITERAL(14, 259, 11), // "QModelIndex"
QT_MOC_LITERAL(15, 271, 5), // "index"
QT_MOC_LITERAL(16, 277, 28), // "on_treeWidgetDevice_expanded"
QT_MOC_LITERAL(17, 306, 30), // "on_pushButton_openList_clicked"
QT_MOC_LITERAL(18, 337, 40), // "on_treeWidgetDevice_itemSelec..."
QT_MOC_LITERAL(19, 378, 37), // "on_treeWidgetDevice_itemDoubl..."
QT_MOC_LITERAL(20, 416, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(21, 433, 4), // "item"
QT_MOC_LITERAL(22, 438, 6) // "column"

    },
    "FrmDeviceSetup\0stateChange\0\0"
    "ETypeDef::StateChange\0state\0on_setup\0"
    "EDeviceInfo\0dev\0on_pushButton_addDevice_clicked\0"
    "on_pushButton_Cancel_clicked\0"
    "on_pushButton_remove_clicked\0"
    "on_pushButton_save_clicked\0"
    "on_pushButton_saveList_clicked\0"
    "on_treeWidgetDevice_collapsed\0QModelIndex\0"
    "index\0on_treeWidgetDevice_expanded\0"
    "on_pushButton_openList_clicked\0"
    "on_treeWidgetDevice_itemSelectionChanged\0"
    "on_treeWidgetDevice_itemDoubleClicked\0"
    "QTreeWidgetItem*\0item\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmDeviceSetup[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   77,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x08 /* Private */,
      16,    1,   88,    2, 0x08 /* Private */,
      17,    0,   91,    2, 0x08 /* Private */,
      18,    0,   92,    2, 0x08 /* Private */,
      19,    2,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20, QMetaType::Int,   21,   22,

       0        // eod
};

void FrmDeviceSetup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmDeviceSetup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChange((*reinterpret_cast< ETypeDef::StateChange(*)>(_a[1]))); break;
        case 1: _t->on_setup((*reinterpret_cast< EDeviceInfo(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_addDevice_clicked(); break;
        case 3: _t->on_pushButton_Cancel_clicked(); break;
        case 4: _t->on_pushButton_remove_clicked(); break;
        case 5: _t->on_pushButton_save_clicked(); break;
        case 6: _t->on_pushButton_saveList_clicked(); break;
        case 7: _t->on_treeWidgetDevice_collapsed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_treeWidgetDevice_expanded((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_openList_clicked(); break;
        case 10: _t->on_treeWidgetDevice_itemSelectionChanged(); break;
        case 11: _t->on_treeWidgetDevice_itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrmDeviceSetup::*)(ETypeDef::StateChange );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrmDeviceSetup::stateChange)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmDeviceSetup::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmDeviceSetup.data,
    qt_meta_data_FrmDeviceSetup,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmDeviceSetup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmDeviceSetup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmDeviceSetup.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmDeviceSetup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void FrmDeviceSetup::stateChange(ETypeDef::StateChange _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
