/****************************************************************************
** Meta object code from reading C++ file 'frmsetupserial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/device/software/frmsetupserial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmsetupserial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmSetupSerial_t {
    QByteArrayData data[17];
    char stringdata0[367];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmSetupSerial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmSetupSerial_t qt_meta_stringdata_FrmSetupSerial = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FrmSetupSerial"
QT_MOC_LITERAL(1, 15, 8), // "on_reply"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "ERequestUnit"
QT_MOC_LITERAL(4, 38, 7), // "request"
QT_MOC_LITERAL(5, 46, 16), // "on_errorOccurred"
QT_MOC_LITERAL(6, 63, 12), // "on_timerPoll"
QT_MOC_LITERAL(7, 76, 38), // "on_spinBox_versioneDevice_val..."
QT_MOC_LITERAL(8, 115, 4), // "arg1"
QT_MOC_LITERAL(9, 120, 33), // "on_comboBox_groupDevice_activ..."
QT_MOC_LITERAL(10, 154, 5), // "index"
QT_MOC_LITERAL(11, 160, 32), // "on_comboBox_typeDevice_activated"
QT_MOC_LITERAL(12, 193, 25), // "on_lineEdit_id_textEdited"
QT_MOC_LITERAL(13, 219, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(14, 248, 43), // "on_comboBox_groupDevice_curre..."
QT_MOC_LITERAL(15, 292, 40), // "on_lineEdit_serialNumber_edit..."
QT_MOC_LITERAL(16, 333, 33) // "on_pushButton_writeSerial_cli..."

    },
    "FrmSetupSerial\0on_reply\0\0ERequestUnit\0"
    "request\0on_errorOccurred\0on_timerPoll\0"
    "on_spinBox_versioneDevice_valueChanged\0"
    "arg1\0on_comboBox_groupDevice_activated\0"
    "index\0on_comboBox_typeDevice_activated\0"
    "on_lineEdit_id_textEdited\0"
    "on_pushButton_Cancel_clicked\0"
    "on_comboBox_groupDevice_currentIndexChanged\0"
    "on_lineEdit_serialNumber_editingFinished\0"
    "on_pushButton_writeSerial_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmSetupSerial[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       5,    1,   72,    2, 0x08 /* Private */,
       6,    0,   75,    2, 0x08 /* Private */,
       7,    1,   76,    2, 0x08 /* Private */,
       9,    1,   79,    2, 0x08 /* Private */,
      11,    1,   82,    2, 0x08 /* Private */,
      12,    1,   85,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    1,   89,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmSetupSerial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmSetupSerial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_reply((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 1: _t->on_errorOccurred((*reinterpret_cast< ERequestUnit(*)>(_a[1]))); break;
        case 2: _t->on_timerPoll(); break;
        case 3: _t->on_spinBox_versioneDevice_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_groupDevice_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_comboBox_typeDevice_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_id_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_Cancel_clicked(); break;
        case 8: _t->on_comboBox_groupDevice_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_lineEdit_serialNumber_editingFinished(); break;
        case 10: _t->on_pushButton_writeSerial_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmSetupSerial::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmSetupSerial.data,
    qt_meta_data_FrmSetupSerial,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmSetupSerial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmSetupSerial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmSetupSerial.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmSetupSerial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
