/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[407];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 5), // "login"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 14), // "on_stateChange"
QT_MOC_LITERAL(4, 33, 21), // "ETypeDef::StateChange"
QT_MOC_LITERAL(5, 55, 5), // "state"
QT_MOC_LITERAL(6, 61, 8), // "on_error"
QT_MOC_LITERAL(7, 70, 14), // "EDevice::Error"
QT_MOC_LITERAL(8, 85, 5), // "error"
QT_MOC_LITERAL(9, 91, 8), // "EDevice*"
QT_MOC_LITERAL(10, 100, 3), // "dev"
QT_MOC_LITERAL(11, 104, 35), // "on_toolButton_groupSoftware_c..."
QT_MOC_LITERAL(12, 140, 33), // "on_toolButton_groupSensor_cli..."
QT_MOC_LITERAL(13, 174, 33), // "on_toolButton_groupModule_cli..."
QT_MOC_LITERAL(14, 208, 33), // "on_toolButton_groupSystem_cli..."
QT_MOC_LITERAL(15, 242, 30), // "on_pushButton_TypeList_clicked"
QT_MOC_LITERAL(16, 273, 33), // "on_toolButton_groupSearch_cli..."
QT_MOC_LITERAL(17, 307, 37), // "on_toolButton_groupConnection..."
QT_MOC_LITERAL(18, 345, 27), // "on_toolButton_login_clicked"
QT_MOC_LITERAL(19, 373, 33) // "on_toolButton_clearDevice_cli..."

    },
    "MainWindow\0login\0\0on_stateChange\0"
    "ETypeDef::StateChange\0state\0on_error\0"
    "EDevice::Error\0error\0EDevice*\0dev\0"
    "on_toolButton_groupSoftware_clicked\0"
    "on_toolButton_groupSensor_clicked\0"
    "on_toolButton_groupModule_clicked\0"
    "on_toolButton_groupSystem_clicked\0"
    "on_pushButton_TypeList_clicked\0"
    "on_toolButton_groupSearch_clicked\0"
    "on_toolButton_groupConnection_clicked\0"
    "on_toolButton_login_clicked\0"
    "on_toolButton_clearDevice_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   75,    2, 0x08 /* Private */,
       6,    2,   78,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,
      16,    0,   88,    2, 0x08 /* Private */,
      17,    0,   89,    2, 0x08 /* Private */,
      18,    0,   90,    2, 0x08 /* Private */,
      19,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 9,    8,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->login(); break;
        case 1: _t->on_stateChange((*reinterpret_cast< ETypeDef::StateChange(*)>(_a[1]))); break;
        case 2: _t->on_error((*reinterpret_cast< EDevice::Error(*)>(_a[1])),(*reinterpret_cast< EDevice*(*)>(_a[2]))); break;
        case 3: _t->on_toolButton_groupSoftware_clicked(); break;
        case 4: _t->on_toolButton_groupSensor_clicked(); break;
        case 5: _t->on_toolButton_groupModule_clicked(); break;
        case 6: _t->on_toolButton_groupSystem_clicked(); break;
        case 7: _t->on_pushButton_TypeList_clicked(); break;
        case 8: _t->on_toolButton_groupSearch_clicked(); break;
        case 9: _t->on_toolButton_groupConnection_clicked(); break;
        case 10: _t->on_toolButton_login_clicked(); break;
        case 11: _t->on_toolButton_clearDevice_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EDevice* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::login)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::login()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
