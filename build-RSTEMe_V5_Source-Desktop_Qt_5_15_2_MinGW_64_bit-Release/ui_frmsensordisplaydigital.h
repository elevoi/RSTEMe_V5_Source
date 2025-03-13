/********************************************************************************
** Form generated from reading UI file 'frmsensordisplaydigital.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSENSORDISPLAYDIGITAL_H
#define UI_FRMSENSORDISPLAYDIGITAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmSensorDisplayDigital
{
public:
    QWidget *centralwidget;
    QLCDNumber *lcdNumber_Value;
    QLCDNumber *lcdNumber_temperature;
    QCheckBox *checkBox_tempature;
    QLabel *label_UnitSymbol;
    QLabel *label_Name;
    QFrame *line_2;
    QFrame *frame_parameter;
    QLabel *label_12;
    QFrame *line;
    QLabel *label_11;
    QPushButton *pushButton_cancel;
    QComboBox *comboBox_resolution;
    QComboBox *comboBox_unit;
    QToolButton *toolButton_config;
    QFrame *line_3;
    QToolButton *toolButton_info;

    void setupUi(QMainWindow *FrmSensorDisplayDigital)
    {
        if (FrmSensorDisplayDigital->objectName().isEmpty())
            FrmSensorDisplayDigital->setObjectName(QString::fromUtf8("FrmSensorDisplayDigital"));
        FrmSensorDisplayDigital->resize(1000, 420);
        FrmSensorDisplayDigital->setMinimumSize(QSize(1000, 350));
        FrmSensorDisplayDigital->setMaximumSize(QSize(1000, 420));
        FrmSensorDisplayDigital->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color: rgb(2,87, 122);\n"
"}"));
        centralwidget = new QWidget(FrmSensorDisplayDigital);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lcdNumber_Value = new QLCDNumber(centralwidget);
        lcdNumber_Value->setObjectName(QString::fromUtf8("lcdNumber_Value"));
        lcdNumber_Value->setGeometry(QRect(10, 60, 861, 211));
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
        lcdNumber_temperature = new QLCDNumber(centralwidget);
        lcdNumber_temperature->setObjectName(QString::fromUtf8("lcdNumber_temperature"));
        lcdNumber_temperature->setGeometry(QRect(669, 280, 321, 71));
        lcdNumber_temperature->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgb(0, 60, 90);"));
        lcdNumber_temperature->setFrameShape(QFrame::Panel);
        lcdNumber_temperature->setLineWidth(1);
        lcdNumber_temperature->setSmallDecimalPoint(false);
        lcdNumber_temperature->setDigitCount(8);
        lcdNumber_temperature->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_temperature->setProperty("value", QVariant(12345678.000000000000000));
        lcdNumber_temperature->setProperty("intValue", QVariant(12345678));
        checkBox_tempature = new QCheckBox(centralwidget);
        checkBox_tempature->setObjectName(QString::fromUtf8("checkBox_tempature"));
        checkBox_tempature->setGeometry(QRect(420, 295, 241, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        checkBox_tempature->setFont(font);
        checkBox_tempature->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        checkBox_tempature->setIconSize(QSize(16, 16));
        checkBox_tempature->setCheckable(true);
        label_UnitSymbol = new QLabel(centralwidget);
        label_UnitSymbol->setObjectName(QString::fromUtf8("label_UnitSymbol"));
        label_UnitSymbol->setGeometry(QRect(869, 60, 121, 211));
        QFont font1;
        font1.setPointSize(32);
        font1.setBold(true);
        label_UnitSymbol->setFont(font1);
        label_UnitSymbol->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 60, 90);\n"
"color: rgb(0, 255, 255);"));
        label_UnitSymbol->setAlignment(Qt::AlignCenter);
        label_Name = new QLabel(centralwidget);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setGeometry(QRect(50, 0, 901, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(24);
        font2.setBold(true);
        label_Name->setFont(font2);
        label_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 50, 1000, 3));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb(2,87, 122);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        frame_parameter = new QFrame(centralwidget);
        frame_parameter->setObjectName(QString::fromUtf8("frame_parameter"));
        frame_parameter->setGeometry(QRect(0, 350, 1001, 71));
        frame_parameter->setStyleSheet(QString::fromUtf8("QFrame#frame_parameter{\n"
"background-color: rgb(3,87, 123);\n"
"}"));
        frame_parameter->setFrameShape(QFrame::StyledPanel);
        frame_parameter->setFrameShadow(QFrame::Raised);
        label_12 = new QLabel(frame_parameter);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(540, 26, 121, 21));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        label_12->setFont(font3);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line = new QFrame(frame_parameter);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 0, 1000, 3));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(2,87, 122);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_11 = new QLabel(frame_parameter);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(90, 26, 91, 20));
        label_11->setFont(font3);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_cancel = new QPushButton(frame_parameter);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(840, 16, 151, 41));
        pushButton_cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_resolution = new QComboBox(frame_parameter);
        comboBox_resolution->addItem(QString());
        comboBox_resolution->addItem(QString());
        comboBox_resolution->addItem(QString());
        comboBox_resolution->addItem(QString());
        comboBox_resolution->setObjectName(QString::fromUtf8("comboBox_resolution"));
        comboBox_resolution->setGeometry(QRect(670, 16, 141, 41));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setItalic(true);
        comboBox_resolution->setFont(font4);
        comboBox_resolution->setLayoutDirection(Qt::LeftToRight);
        comboBox_resolution->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-left-radius: 20px;\n"
"border-bottom-left-radius: 20px;\n"
"}\n"
"QComboBox::drop-down{\n"
"width: 20;\n"
"}\n"
"QComboBox:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        comboBox_resolution->setEditable(true);
        comboBox_unit = new QComboBox(frame_parameter);
        comboBox_unit->addItem(QString());
        comboBox_unit->addItem(QString());
        comboBox_unit->setObjectName(QString::fromUtf8("comboBox_unit"));
        comboBox_unit->setGeometry(QRect(190, 16, 331, 41));
        comboBox_unit->setFont(font4);
        comboBox_unit->setLayoutDirection(Qt::LeftToRight);
        comboBox_unit->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-left-radius: 20px;\n"
"border-bottom-left-radius: 20px;\n"
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
        toolButton_config = new QToolButton(frame_parameter);
        toolButton_config->setObjectName(QString::fromUtf8("toolButton_config"));
        toolButton_config->setGeometry(QRect(10, 9, 50, 51));
        toolButton_config->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(3, 87, 123);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 8px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/group/iconSetup_On1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/icon/group/iconSetup_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_config->setIcon(icon);
        toolButton_config->setIconSize(QSize(45, 45));
        toolButton_config->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_config->setAutoRaise(true);
        line_3 = new QFrame(frame_parameter);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(70, 10, 3, 50));
        line_3->setFrameShadow(QFrame::Sunken);
        line_3->setFrameShape(QFrame::VLine);
        toolButton_info = new QToolButton(centralwidget);
        toolButton_info->setObjectName(QString::fromUtf8("toolButton_info"));
        toolButton_info->setGeometry(QRect(5, 5, 41, 41));
        toolButton_info->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(250, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 6px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"background-color: rgb(25, 149, 190);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/device/iconDeviceOff_401.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icon/device/iconDeviceOn_401.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_info->setIcon(icon1);
        toolButton_info->setIconSize(QSize(36, 36));
        toolButton_info->setAutoRaise(true);
        FrmSensorDisplayDigital->setCentralWidget(centralwidget);
        QWidget::setTabOrder(checkBox_tempature, comboBox_unit);
        QWidget::setTabOrder(comboBox_unit, comboBox_resolution);
        QWidget::setTabOrder(comboBox_resolution, pushButton_cancel);

        retranslateUi(FrmSensorDisplayDigital);

        QMetaObject::connectSlotsByName(FrmSensorDisplayDigital);
    } // setupUi

    void retranslateUi(QMainWindow *FrmSensorDisplayDigital)
    {
        FrmSensorDisplayDigital->setWindowTitle(QCoreApplication::translate("FrmSensorDisplayDigital", "MainWindow", nullptr));
        checkBox_tempature->setText(QCoreApplication::translate("FrmSensorDisplayDigital", "B\303\271 nhi\341\273\207t \304\221\341\273\231 ph\303\251p \304\221o", nullptr));
        label_UnitSymbol->setText(QCoreApplication::translate("FrmSensorDisplayDigital", "mV", nullptr));
        label_Name->setText(QCoreApplication::translate("FrmSensorDisplayDigital", "C\341\272\243m bi\341\272\277n", nullptr));
        label_12->setText(QCoreApplication::translate("FrmSensorDisplayDigital", "\304\220\341\273\231 ph\303\242n gi\341\272\243i", nullptr));
        label_11->setText(QCoreApplication::translate("FrmSensorDisplayDigital", "\304\220\306\241n v\341\273\213 \304\221o", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("FrmSensorDisplayDigital", "Tho\303\241t", nullptr));
        comboBox_resolution->setItemText(0, QCoreApplication::translate("FrmSensorDisplayDigital", "1", nullptr));
        comboBox_resolution->setItemText(1, QCoreApplication::translate("FrmSensorDisplayDigital", "0.1", nullptr));
        comboBox_resolution->setItemText(2, QCoreApplication::translate("FrmSensorDisplayDigital", "0.01", nullptr));
        comboBox_resolution->setItemText(3, QCoreApplication::translate("FrmSensorDisplayDigital", "0.001", nullptr));

        comboBox_unit->setItemText(0, QCoreApplication::translate("FrmSensorDisplayDigital", "\304\220\341\273\231 \341\272\251m t\306\260\306\241ng \304\221\341\273\221i (%RH)", nullptr));
        comboBox_unit->setItemText(1, QCoreApplication::translate("FrmSensorDisplayDigital", "\304\220\341\273\231 \341\272\251m tuy\341\273\207t \304\221\341\273\221i (g/m3)", nullptr));

#if QT_CONFIG(tooltip)
        toolButton_config->setToolTip(QCoreApplication::translate("FrmSensorDisplayDigital", "Th\303\264ng tin thi\341\272\277t b\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_config->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_info->setToolTip(QCoreApplication::translate("FrmSensorDisplayDigital", "Th\303\264ng tin thi\341\272\277t b\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_info->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FrmSensorDisplayDigital: public Ui_FrmSensorDisplayDigital {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSENSORDISPLAYDIGITAL_H
