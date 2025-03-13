/********************************************************************************
** Form generated from reading UI file 'frmdeviceconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDEVICECONFIG_H
#define UI_FRMDEVICECONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmDeviceConfig
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_cancel;
    QFrame *line;
    QLabel *label_11;
    QSpinBox *spinBox_sampleTime;
    QToolButton *toolButton_setSampleTime;
    QLabel *label_zeroText;
    QToolButton *toolButton_setZero;
    QFrame *frame;
    QLabel *label_Name;
    QFrame *line_2;
    QToolButton *toolButton_clearZero;
    QLabel *label_12;
    QComboBox *comboBox_unit;
    QComboBox *comboBox_resolution;
    QLabel *label_13;
    QFrame *line_3;
    QLineEdit *lineEdit_Zero;
    QLabel *label_Unit;
    QLabel *label_Unit_2;
    QCheckBox *checkBox_tempCompensation;

    void setupUi(QMainWindow *FrmDeviceConfig)
    {
        if (FrmDeviceConfig->objectName().isEmpty())
            FrmDeviceConfig->setObjectName(QString::fromUtf8("FrmDeviceConfig"));
        FrmDeviceConfig->resize(530, 260);
        FrmDeviceConfig->setStyleSheet(QString::fromUtf8("background-color: rgb(240,240, 240);"));
        centralwidget = new QWidget(FrmDeviceConfig);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_cancel = new QPushButton(centralwidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(380, 220, 141, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        pushButton_cancel->setFont(font);
        pushButton_cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 140, 530, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 105, 121, 20));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(50, 150, 200);"));
        spinBox_sampleTime = new QSpinBox(centralwidget);
        spinBox_sampleTime->setObjectName(QString::fromUtf8("spinBox_sampleTime"));
        spinBox_sampleTime->setGeometry(QRect(180, 100, 91, 30));
        spinBox_sampleTime->setFont(font);
        spinBox_sampleTime->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        spinBox_sampleTime->setAlignment(Qt::AlignCenter);
        spinBox_sampleTime->setMinimum(1);
        spinBox_sampleTime->setMaximum(65535);
        spinBox_sampleTime->setValue(100);
        toolButton_setSampleTime = new QToolButton(centralwidget);
        toolButton_setSampleTime->setObjectName(QString::fromUtf8("toolButton_setSampleTime"));
        toolButton_setSampleTime->setGeometry(QRect(330, 100, 131, 30));
        toolButton_setSampleTime->setFont(font);
        toolButton_setSampleTime->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(50, 150, 200);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 6px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(120, 210, 240);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        toolButton_setSampleTime->setIconSize(QSize(50, 50));
        toolButton_setSampleTime->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_setSampleTime->setAutoRaise(true);
        label_zeroText = new QLabel(centralwidget);
        label_zeroText->setObjectName(QString::fromUtf8("label_zeroText"));
        label_zeroText->setGeometry(QRect(20, 55, 161, 20));
        label_zeroText->setFont(font);
        label_zeroText->setStyleSheet(QString::fromUtf8("color: rgb(50, 150, 200);"));
        toolButton_setZero = new QToolButton(centralwidget);
        toolButton_setZero->setObjectName(QString::fromUtf8("toolButton_setZero"));
        toolButton_setZero->setGeometry(QRect(330, 50, 131, 30));
        toolButton_setZero->setFont(font);
        toolButton_setZero->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(50, 150, 200);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 6px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(120, 210, 240);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        toolButton_setZero->setIconSize(QSize(50, 50));
        toolButton_setZero->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_setZero->setAutoRaise(true);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 530, 41));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(2,87, 122);"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        label_Name = new QLabel(frame);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setGeometry(QRect(10, 6, 431, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        font1.setBold(true);
        label_Name->setFont(font1);
        label_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 90, 530, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        toolButton_clearZero = new QToolButton(centralwidget);
        toolButton_clearZero->setObjectName(QString::fromUtf8("toolButton_clearZero"));
        toolButton_clearZero->setGeometry(QRect(470, 50, 51, 30));
        toolButton_clearZero->setFont(font);
        toolButton_clearZero->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(50, 150, 200);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 6px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(120, 210, 240);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        toolButton_clearZero->setIconSize(QSize(50, 50));
        toolButton_clearZero->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_clearZero->setAutoRaise(true);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(280, 156, 81, 21));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(50, 150, 200);"));
        comboBox_unit = new QComboBox(centralwidget);
        comboBox_unit->addItem(QString());
        comboBox_unit->addItem(QString());
        comboBox_unit->setObjectName(QString::fromUtf8("comboBox_unit"));
        comboBox_unit->setGeometry(QRect(90, 150, 181, 32));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        comboBox_unit->setFont(font2);
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
        comboBox_resolution = new QComboBox(centralwidget);
        comboBox_resolution->addItem(QString());
        comboBox_resolution->addItem(QString());
        comboBox_resolution->addItem(QString());
        comboBox_resolution->addItem(QString());
        comboBox_resolution->setObjectName(QString::fromUtf8("comboBox_resolution"));
        comboBox_resolution->setGeometry(QRect(370, 150, 71, 32));
        comboBox_resolution->setFont(font2);
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
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 156, 61, 20));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(50, 150, 200);"));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 190, 530, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        lineEdit_Zero = new QLineEdit(centralwidget);
        lineEdit_Zero->setObjectName(QString::fromUtf8("lineEdit_Zero"));
        lineEdit_Zero->setGeometry(QRect(180, 50, 91, 30));
        lineEdit_Zero->setFont(font);
        lineEdit_Zero->setAlignment(Qt::AlignCenter);
        label_Unit = new QLabel(centralwidget);
        label_Unit->setObjectName(QString::fromUtf8("label_Unit"));
        label_Unit->setGeometry(QRect(276, 57, 49, 16));
        label_Unit->setFont(font);
        label_Unit->setAlignment(Qt::AlignCenter);
        label_Unit_2 = new QLabel(centralwidget);
        label_Unit_2->setObjectName(QString::fromUtf8("label_Unit_2"));
        label_Unit_2->setGeometry(QRect(276, 107, 49, 16));
        label_Unit_2->setFont(font);
        label_Unit_2->setAlignment(Qt::AlignCenter);
        checkBox_tempCompensation = new QCheckBox(centralwidget);
        checkBox_tempCompensation->setObjectName(QString::fromUtf8("checkBox_tempCompensation"));
        checkBox_tempCompensation->setGeometry(QRect(20, 200, 191, 20));
        checkBox_tempCompensation->setFont(font);
        checkBox_tempCompensation->setStyleSheet(QString::fromUtf8("color: rgb(50, 150, 200);"));
        FrmDeviceConfig->setCentralWidget(centralwidget);

        retranslateUi(FrmDeviceConfig);

        QMetaObject::connectSlotsByName(FrmDeviceConfig);
    } // setupUi

    void retranslateUi(QMainWindow *FrmDeviceConfig)
    {
        FrmDeviceConfig->setWindowTitle(QCoreApplication::translate("FrmDeviceConfig", "MainWindow", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("FrmDeviceConfig", "Tho\303\241t", nullptr));
        label_11->setText(QCoreApplication::translate("FrmDeviceConfig", "Th\341\273\235i gian l\341\272\245y m\341\272\253u", nullptr));
        toolButton_setSampleTime->setText(QCoreApplication::translate("FrmDeviceConfig", "C\303\240i \304\221\341\272\267t", nullptr));
        label_zeroText->setText(QCoreApplication::translate("FrmDeviceConfig", "Thi\341\272\277t l\341\272\255p \304\221i\341\273\203m kh\303\264ng t\341\272\241i", nullptr));
        toolButton_setZero->setText(QCoreApplication::translate("FrmDeviceConfig", "Zero", nullptr));
        label_Name->setText(QCoreApplication::translate("FrmDeviceConfig", "C\341\272\243m bi\341\272\277n", nullptr));
        toolButton_clearZero->setText(QCoreApplication::translate("FrmDeviceConfig", "X\303\263a", nullptr));
        label_12->setText(QCoreApplication::translate("FrmDeviceConfig", "\304\220\341\273\231 ph\303\242n gi\341\272\243i", nullptr));
        comboBox_unit->setItemText(0, QCoreApplication::translate("FrmDeviceConfig", "\304\220\341\273\231 \341\272\251m t\306\260\306\241ng \304\221\341\273\221i (%RH)", nullptr));
        comboBox_unit->setItemText(1, QCoreApplication::translate("FrmDeviceConfig", "\304\220\341\273\231 \341\272\251m tuy\341\273\207t \304\221\341\273\221i (g/m3)", nullptr));

        comboBox_resolution->setItemText(0, QCoreApplication::translate("FrmDeviceConfig", "1", nullptr));
        comboBox_resolution->setItemText(1, QCoreApplication::translate("FrmDeviceConfig", "0.1", nullptr));
        comboBox_resolution->setItemText(2, QCoreApplication::translate("FrmDeviceConfig", "0.01", nullptr));
        comboBox_resolution->setItemText(3, QCoreApplication::translate("FrmDeviceConfig", "0.001", nullptr));

        label_13->setText(QCoreApplication::translate("FrmDeviceConfig", "\304\220\306\241n v\341\273\213 \304\221o", nullptr));
        lineEdit_Zero->setText(QCoreApplication::translate("FrmDeviceConfig", "0", nullptr));
        label_Unit->setText(QCoreApplication::translate("FrmDeviceConfig", "...", nullptr));
        label_Unit_2->setText(QCoreApplication::translate("FrmDeviceConfig", "(ms)", nullptr));
        checkBox_tempCompensation->setText(QCoreApplication::translate("FrmDeviceConfig", "B\303\271 nhi\341\273\207t \304\221\341\273\231 cho ph\303\251p \304\221o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmDeviceConfig: public Ui_FrmDeviceConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDEVICECONFIG_H
