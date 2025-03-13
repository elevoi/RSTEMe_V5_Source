/****************************************************************************
** Meta object code from reading C++ file 'frmdevicecalibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RSTEMe_V5_Source/device/frmdevicecalibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmdevicecalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmDeviceCalibration_t {
    QByteArrayData data[39];
    char stringdata0[1056];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmDeviceCalibration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmDeviceCalibration_t qt_meta_stringdata_FrmDeviceCalibration = {
    {
QT_MOC_LITERAL(0, 0, 20), // "FrmDeviceCalibration"
QT_MOC_LITERAL(1, 21, 21), // "replySelectDeviceInfo"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 11), // "EDeviceInfo"
QT_MOC_LITERAL(4, 56, 3), // "dev"
QT_MOC_LITERAL(5, 60, 16), // "on_newDataDevice"
QT_MOC_LITERAL(6, 77, 8), // "EDevice*"
QT_MOC_LITERAL(7, 86, 25), // "on_newDataDeviceReference"
QT_MOC_LITERAL(8, 112, 23), // "on_errorDeviceReference"
QT_MOC_LITERAL(9, 136, 14), // "EDevice::Error"
QT_MOC_LITERAL(10, 151, 3), // "err"
QT_MOC_LITERAL(11, 155, 24), // "on_replySelectDeviceInfo"
QT_MOC_LITERAL(12, 180, 12), // "on_timerPoll"
QT_MOC_LITERAL(13, 193, 37), // "on_comboBox_theme_currentInde..."
QT_MOC_LITERAL(14, 231, 5), // "index"
QT_MOC_LITERAL(15, 237, 32), // "on_checkBox_antiAliasing_toggled"
QT_MOC_LITERAL(16, 270, 7), // "checked"
QT_MOC_LITERAL(17, 278, 38), // "on_comboBox_legend_currentInd..."
QT_MOC_LITERAL(18, 317, 35), // "on_toolButton_toolCrosshair_c..."
QT_MOC_LITERAL(19, 353, 33), // "on_toolButton_toolCallout_cli..."
QT_MOC_LITERAL(20, 387, 30), // "on_toolButton_toolPlay_clicked"
QT_MOC_LITERAL(21, 418, 31), // "on_toolButton_toolPause_clicked"
QT_MOC_LITERAL(22, 450, 37), // "on_radioButton_standardSample..."
QT_MOC_LITERAL(23, 488, 33), // "on_spinBox_calibTime_valueCha..."
QT_MOC_LITERAL(24, 522, 4), // "arg1"
QT_MOC_LITERAL(25, 527, 34), // "on_spinBox_sampleTime_valueCh..."
QT_MOC_LITERAL(26, 562, 36), // "on_spinBox_sampleNumber_value..."
QT_MOC_LITERAL(27, 599, 48), // "on_comboBox_calibPointSelect_..."
QT_MOC_LITERAL(28, 648, 41), // "on_lineEdit_standardValue_edi..."
QT_MOC_LITERAL(29, 690, 46), // "on_comboBox_accuracySelect_cu..."
QT_MOC_LITERAL(30, 737, 32), // "on_lineEdit_accuracy_textChanged"
QT_MOC_LITERAL(31, 770, 37), // "on_lineEdit_standardValue_tex..."
QT_MOC_LITERAL(32, 808, 32), // "on_spinBox_rangeMax_valueChanged"
QT_MOC_LITERAL(33, 841, 32), // "on_spinBox_rangeMin_valueChanged"
QT_MOC_LITERAL(34, 874, 36), // "on_comboBox_unit_currentIndex..."
QT_MOC_LITERAL(35, 911, 35), // "on_pushButton_clearCalibOne_c..."
QT_MOC_LITERAL(36, 947, 35), // "on_pushButton_clearCalibTwo_c..."
QT_MOC_LITERAL(37, 983, 37), // "on_pushButton_clearCalibThree..."
QT_MOC_LITERAL(38, 1021, 34) // "on_pushButton_addDeviceRef_cl..."

    },
    "FrmDeviceCalibration\0replySelectDeviceInfo\0"
    "\0EDeviceInfo\0dev\0on_newDataDevice\0"
    "EDevice*\0on_newDataDeviceReference\0"
    "on_errorDeviceReference\0EDevice::Error\0"
    "err\0on_replySelectDeviceInfo\0on_timerPoll\0"
    "on_comboBox_theme_currentIndexChanged\0"
    "index\0on_checkBox_antiAliasing_toggled\0"
    "checked\0on_comboBox_legend_currentIndexChanged\0"
    "on_toolButton_toolCrosshair_clicked\0"
    "on_toolButton_toolCallout_clicked\0"
    "on_toolButton_toolPlay_clicked\0"
    "on_toolButton_toolPause_clicked\0"
    "on_radioButton_standardSample_toggled\0"
    "on_spinBox_calibTime_valueChanged\0"
    "arg1\0on_spinBox_sampleTime_valueChanged\0"
    "on_spinBox_sampleNumber_valueChanged\0"
    "on_comboBox_calibPointSelect_currentIndexChanged\0"
    "on_lineEdit_standardValue_editingFinished\0"
    "on_comboBox_accuracySelect_currentIndexChanged\0"
    "on_lineEdit_accuracy_textChanged\0"
    "on_lineEdit_standardValue_textChanged\0"
    "on_spinBox_rangeMax_valueChanged\0"
    "on_spinBox_rangeMin_valueChanged\0"
    "on_comboBox_unit_currentIndexChanged\0"
    "on_pushButton_clearCalibOne_clicked\0"
    "on_pushButton_clearCalibTwo_clicked\0"
    "on_pushButton_clearCalibThree_clicked\0"
    "on_pushButton_addDeviceRef_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmDeviceCalibration[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  159,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,  162,    2, 0x08 /* Private */,
       7,    1,  165,    2, 0x08 /* Private */,
       8,    1,  168,    2, 0x08 /* Private */,
      11,    1,  171,    2, 0x08 /* Private */,
      12,    0,  174,    2, 0x08 /* Private */,
      13,    1,  175,    2, 0x08 /* Private */,
      15,    1,  178,    2, 0x08 /* Private */,
      17,    1,  181,    2, 0x08 /* Private */,
      18,    0,  184,    2, 0x08 /* Private */,
      19,    0,  185,    2, 0x08 /* Private */,
      20,    0,  186,    2, 0x08 /* Private */,
      21,    0,  187,    2, 0x08 /* Private */,
      22,    1,  188,    2, 0x08 /* Private */,
      23,    1,  191,    2, 0x08 /* Private */,
      25,    1,  194,    2, 0x08 /* Private */,
      26,    1,  197,    2, 0x08 /* Private */,
      27,    1,  200,    2, 0x08 /* Private */,
      28,    0,  203,    2, 0x08 /* Private */,
      29,    1,  204,    2, 0x08 /* Private */,
      30,    1,  207,    2, 0x08 /* Private */,
      31,    1,  210,    2, 0x08 /* Private */,
      32,    1,  213,    2, 0x08 /* Private */,
      33,    1,  216,    2, 0x08 /* Private */,
      34,    1,  219,    2, 0x08 /* Private */,
      35,    0,  222,    2, 0x08 /* Private */,
      36,    0,  223,    2, 0x08 /* Private */,
      37,    0,  224,    2, 0x08 /* Private */,
      38,    0,  225,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmDeviceCalibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmDeviceCalibration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replySelectDeviceInfo((*reinterpret_cast< EDeviceInfo(*)>(_a[1]))); break;
        case 1: _t->on_newDataDevice((*reinterpret_cast< EDevice*(*)>(_a[1]))); break;
        case 2: _t->on_newDataDeviceReference((*reinterpret_cast< EDevice*(*)>(_a[1]))); break;
        case 3: _t->on_errorDeviceReference((*reinterpret_cast< EDevice::Error(*)>(_a[1]))); break;
        case 4: _t->on_replySelectDeviceInfo((*reinterpret_cast< EDeviceInfo(*)>(_a[1]))); break;
        case 5: _t->on_timerPoll(); break;
        case 6: _t->on_comboBox_theme_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_checkBox_antiAliasing_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_comboBox_legend_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_toolButton_toolCrosshair_clicked(); break;
        case 10: _t->on_toolButton_toolCallout_clicked(); break;
        case 11: _t->on_toolButton_toolPlay_clicked(); break;
        case 12: _t->on_toolButton_toolPause_clicked(); break;
        case 13: _t->on_radioButton_standardSample_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_spinBox_calibTime_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_spinBox_sampleTime_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_spinBox_sampleNumber_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_comboBox_calibPointSelect_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_lineEdit_standardValue_editingFinished(); break;
        case 19: _t->on_comboBox_accuracySelect_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_lineEdit_accuracy_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->on_lineEdit_standardValue_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->on_spinBox_rangeMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_spinBox_rangeMin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_comboBox_unit_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_pushButton_clearCalibOne_clicked(); break;
        case 26: _t->on_pushButton_clearCalibTwo_clicked(); break;
        case 27: _t->on_pushButton_clearCalibThree_clicked(); break;
        case 28: _t->on_pushButton_addDeviceRef_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EDevice* >(); break;
            }
            break;
        case 2:
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
            using _t = void (FrmDeviceCalibration::*)(EDeviceInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrmDeviceCalibration::replySelectDeviceInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmDeviceCalibration::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FrmDeviceCalibration.data,
    qt_meta_data_FrmDeviceCalibration,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmDeviceCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmDeviceCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmDeviceCalibration.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FrmDeviceCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void FrmDeviceCalibration::replySelectDeviceInfo(EDeviceInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
