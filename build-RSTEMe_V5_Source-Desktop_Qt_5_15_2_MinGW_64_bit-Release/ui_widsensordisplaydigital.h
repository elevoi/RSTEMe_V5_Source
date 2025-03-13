/********************************************************************************
** Form generated from reading UI file 'widsensordisplaydigital.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDSENSORDISPLAYDIGITAL_H
#define UI_WIDSENSORDISPLAYDIGITAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidSensorDisplayDigital
{
public:
    QFrame *frame;
    QFrame *line_2;
    QToolButton *toolButton_cancel;
    QLCDNumber *lcdNumber_Value;
    QLabel *label_Name;
    QLabel *label_UnitSymbol;
    QLCDNumber *lcdNumber_temperature;
    QCheckBox *checkBox_tempature;
    QFrame *frame_parameter;
    QFrame *line;
    QComboBox *comboBox_unit;
    QLabel *label_11;
    QComboBox *comboBox_resolution;
    QLabel *label_12;

    void setupUi(QWidget *WidSensorDisplayDigital)
    {
        if (WidSensorDisplayDigital->objectName().isEmpty())
            WidSensorDisplayDigital->setObjectName(QString::fromUtf8("WidSensorDisplayDigital"));
        WidSensorDisplayDigital->setWindowModality(Qt::WindowModal);
        WidSensorDisplayDigital->resize(504, 266);
        WidSensorDisplayDigital->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: rgb(2,87, 122);\n"
"}"));
        frame = new QFrame(WidSensorDisplayDigital);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 501, 260));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{\n"
"background-color: rgb(2,87, 122);\n"
"border: none;\n"
"border-color: rgb(0, 255, 255);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 15px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 24, 480, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        toolButton_cancel = new QToolButton(frame);
        toolButton_cancel->setObjectName(QString::fromUtf8("toolButton_cancel"));
        toolButton_cancel->setGeometry(QRect(444, 4, 51, 25));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        toolButton_cancel->setFont(font);
        toolButton_cancel->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(255, 255, 255);\n"
"background-color: transparent;\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 5px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        lcdNumber_Value = new QLCDNumber(frame);
        lcdNumber_Value->setObjectName(QString::fromUtf8("lcdNumber_Value"));
        lcdNumber_Value->setGeometry(QRect(9, 41, 481, 91));
        lcdNumber_Value->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 60, 90);\n"
"color: rgb(0, 255, 255);"));
        lcdNumber_Value->setFrameShape(QFrame::WinPanel);
        lcdNumber_Value->setLineWidth(1);
        lcdNumber_Value->setSmallDecimalPoint(false);
        lcdNumber_Value->setDigitCount(8);
        lcdNumber_Value->setMode(QLCDNumber::Dec);
        lcdNumber_Value->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Value->setProperty("value", QVariant(12345678.000000000000000));
        lcdNumber_Value->setProperty("intValue", QVariant(12345678));
        label_Name = new QLabel(frame);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setGeometry(QRect(9, 3, 431, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        font1.setBold(true);
        label_Name->setFont(font1);
        label_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_UnitSymbol = new QLabel(frame);
        label_UnitSymbol->setObjectName(QString::fromUtf8("label_UnitSymbol"));
        label_UnitSymbol->setGeometry(QRect(420, 100, 70, 26));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        label_UnitSymbol->setFont(font2);
        label_UnitSymbol->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        label_UnitSymbol->setAlignment(Qt::AlignCenter);
        lcdNumber_temperature = new QLCDNumber(frame);
        lcdNumber_temperature->setObjectName(QString::fromUtf8("lcdNumber_temperature"));
        lcdNumber_temperature->setGeometry(QRect(369, 140, 121, 41));
        lcdNumber_temperature->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgb(0, 60, 90);"));
        lcdNumber_temperature->setFrameShape(QFrame::Panel);
        lcdNumber_temperature->setLineWidth(1);
        lcdNumber_temperature->setSmallDecimalPoint(false);
        lcdNumber_temperature->setDigitCount(8);
        lcdNumber_temperature->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_temperature->setProperty("value", QVariant(12345678.000000000000000));
        lcdNumber_temperature->setProperty("intValue", QVariant(12345678));
        checkBox_tempature = new QCheckBox(frame);
        checkBox_tempature->setObjectName(QString::fromUtf8("checkBox_tempature"));
        checkBox_tempature->setGeometry(QRect(208, 150, 151, 21));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        checkBox_tempature->setFont(font3);
        checkBox_tempature->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        checkBox_tempature->setIconSize(QSize(16, 16));
        frame_parameter = new QFrame(frame);
        frame_parameter->setObjectName(QString::fromUtf8("frame_parameter"));
        frame_parameter->setGeometry(QRect(10, 190, 481, 61));
        frame_parameter->setStyleSheet(QString::fromUtf8("background-color: rgb(2,87, 122);"));
        frame_parameter->setFrameShape(QFrame::StyledPanel);
        frame_parameter->setFrameShadow(QFrame::Raised);
        line = new QFrame(frame_parameter);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 0, 500, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        comboBox_unit = new QComboBox(frame_parameter);
        comboBox_unit->addItem(QString());
        comboBox_unit->addItem(QString());
        comboBox_unit->setObjectName(QString::fromUtf8("comboBox_unit"));
        comboBox_unit->setGeometry(QRect(50, 30, 300, 32));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setItalic(true);
        comboBox_unit->setFont(font4);
        comboBox_unit->setLayoutDirection(Qt::LeftToRight);
        comboBox_unit->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"width: 20;\n"
"}\n"
"QComboBox:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        comboBox_unit->setEditable(true);
        label_11 = new QLabel(frame_parameter);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(50, 6, 71, 20));
        label_11->setFont(font3);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        comboBox_resolution = new QComboBox(frame_parameter);
        comboBox_resolution->addItem(QString());
        comboBox_resolution->addItem(QString());
        comboBox_resolution->addItem(QString());
        comboBox_resolution->addItem(QString());
        comboBox_resolution->setObjectName(QString::fromUtf8("comboBox_resolution"));
        comboBox_resolution->setGeometry(QRect(360, 30, 110, 32));
        comboBox_resolution->setFont(font4);
        comboBox_resolution->setLayoutDirection(Qt::LeftToRight);
        comboBox_resolution->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"}\n"
"QComboBox::drop-down{\n"
"width: 20;\n"
"}\n"
"QComboBox:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        comboBox_resolution->setEditable(true);
        label_12 = new QLabel(frame_parameter);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(360, 6, 91, 21));
        label_12->setFont(font3);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        retranslateUi(WidSensorDisplayDigital);

        QMetaObject::connectSlotsByName(WidSensorDisplayDigital);
    } // setupUi

    void retranslateUi(QWidget *WidSensorDisplayDigital)
    {
        WidSensorDisplayDigital->setWindowTitle(QCoreApplication::translate("WidSensorDisplayDigital", "Form", nullptr));
        toolButton_cancel->setText(QCoreApplication::translate("WidSensorDisplayDigital", "X", nullptr));
        label_Name->setText(QCoreApplication::translate("WidSensorDisplayDigital", "C\341\272\243m bi\341\272\277n", nullptr));
        label_UnitSymbol->setText(QCoreApplication::translate("WidSensorDisplayDigital", "mV", nullptr));
        checkBox_tempature->setText(QCoreApplication::translate("WidSensorDisplayDigital", "B\303\271 nhi\341\273\207t \304\221\341\273\231 ph\303\251p \304\221o", nullptr));
        comboBox_unit->setItemText(0, QCoreApplication::translate("WidSensorDisplayDigital", "\304\220\341\273\231 \341\272\251m t\306\260\306\241ng \304\221\341\273\221i (%RH)", nullptr));
        comboBox_unit->setItemText(1, QCoreApplication::translate("WidSensorDisplayDigital", "\304\220\341\273\231 \341\272\251m tuy\341\273\207t \304\221\341\273\221i (g/m3)", nullptr));

        label_11->setText(QCoreApplication::translate("WidSensorDisplayDigital", "\304\220\306\241n v\341\273\213 \304\221o", nullptr));
        comboBox_resolution->setItemText(0, QCoreApplication::translate("WidSensorDisplayDigital", "1", nullptr));
        comboBox_resolution->setItemText(1, QCoreApplication::translate("WidSensorDisplayDigital", "0.1", nullptr));
        comboBox_resolution->setItemText(2, QCoreApplication::translate("WidSensorDisplayDigital", "0.01", nullptr));
        comboBox_resolution->setItemText(3, QCoreApplication::translate("WidSensorDisplayDigital", "0.001", nullptr));

        label_12->setText(QCoreApplication::translate("WidSensorDisplayDigital", "\304\220\341\273\231 ph\303\242n gi\341\272\243i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidSensorDisplayDigital: public Ui_WidSensorDisplayDigital {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDSENSORDISPLAYDIGITAL_H
