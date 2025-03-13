/****************************************************************************
** Meta object code from reading C++ file 'frmaccountsetup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/device/software/frmaccountsetup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmaccountsetup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmAccountSetup_t {
    QByteArrayData data[10];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmAccountSetup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmAccountSetup_t qt_meta_stringdata_FrmAccountSetup = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FrmAccountSetup"
QT_MOC_LITERAL(1, 16, 25), // "on_toolBox_currentChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 5), // "index"
QT_MOC_LITERAL(4, 49, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(5, 78, 45), // "on_pushButton_ChangePassword_..."
QT_MOC_LITERAL(6, 124, 36), // "on_pushButton_ChangePassword_..."
QT_MOC_LITERAL(7, 161, 28), // "on_pushButton_Remove_clicked"
QT_MOC_LITERAL(8, 190, 45), // "on_comboBox_RemoveAccount_cur..."
QT_MOC_LITERAL(9, 236, 35) // "on_pushButton_RemoveDefault_c..."

    },
    "FrmAccountSetup\0on_toolBox_currentChanged\0"
    "\0index\0on_pushButton_Cancel_clicked\0"
    "on_pushButton_ChangePassword_NewCreat_clicked\0"
    "on_pushButton_ChangePassword_clicked\0"
    "on_pushButton_Remove_clicked\0"
    "on_comboBox_RemoveAccount_currentIndexChanged\0"
    "on_pushButton_RemoveDefault_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmAccountSetup[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void FrmAccountSetup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmAccountSetup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_toolBox_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_Cancel_clicked(); break;
        case 2: _t->on_pushButton_ChangePassword_NewCreat_clicked(); break;
        case 3: _t->on_pushButton_ChangePassword_clicked(); break;
        case 4: _t->on_pushButton_Remove_clicked(); break;
        case 5: _t->on_comboBox_RemoveAccount_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_RemoveDefault_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmAccountSetup::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmAccountSetup.data,
    qt_meta_data_FrmAccountSetup,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmAccountSetup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmAccountSetup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmAccountSetup.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmAccountSetup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
