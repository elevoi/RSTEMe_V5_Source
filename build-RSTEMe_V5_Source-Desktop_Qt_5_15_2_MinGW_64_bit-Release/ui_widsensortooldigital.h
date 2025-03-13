/********************************************************************************
** Form generated from reading UI file 'widsensortooldigital.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDSENSORTOOLDIGITAL_H
#define UI_WIDSENSORTOOLDIGITAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidSensorToolDigital
{
public:
    QFrame *frame;
    QToolButton *toolButton_close;
    QLabel *label_Unit;
    QLCDNumber *lcdNumber_value;
    QLabel *label_Name;
    QToolButton *toolButton_info;
    QToolButton *toolButton_setup;

    void setupUi(QWidget *WidSensorToolDigital)
    {
        if (WidSensorToolDigital->objectName().isEmpty())
            WidSensorToolDigital->setObjectName(QString::fromUtf8("WidSensorToolDigital"));
        WidSensorToolDigital->setWindowModality(Qt::NonModal);
        WidSensorToolDigital->resize(300, 70);
        WidSensorToolDigital->setAutoFillBackground(false);
        WidSensorToolDigital->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(WidSensorToolDigital);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 300, 70));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 10px;\n"
"}\n"
"QFrame#frame:hover{\n"
"background-color: rgb(250, 255, 255);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        toolButton_close = new QToolButton(frame);
        toolButton_close->setObjectName(QString::fromUtf8("toolButton_close"));
        toolButton_close->setGeometry(QRect(270, 0, 31, 70));
        toolButton_close->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_close{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(25, 149, 173);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"}\n"
"QToolButton#toolButton_close:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"background-color: rgb(25, 149, 190);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/chart/iconChartClear_On.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/icon/group/iconClear_On.jpg"), QSize(), QIcon::Disabled, QIcon::Off);
        toolButton_close->setIcon(icon);
        toolButton_close->setIconSize(QSize(20, 20));
        toolButton_close->setAutoRaise(true);
        label_Unit = new QLabel(frame);
        label_Unit->setObjectName(QString::fromUtf8("label_Unit"));
        label_Unit->setGeometry(QRect(190, 39, 31, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        label_Unit->setFont(font);
        label_Unit->setStyleSheet(QString::fromUtf8(""));
        lcdNumber_value = new QLCDNumber(frame);
        lcdNumber_value->setObjectName(QString::fromUtf8("lcdNumber_value"));
        lcdNumber_value->setGeometry(QRect(70, 33, 121, 31));
        lcdNumber_value->setLayoutDirection(Qt::LeftToRight);
        lcdNumber_value->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        lcdNumber_value->setFrameShape(QFrame::NoFrame);
        lcdNumber_value->setFrameShadow(QFrame::Plain);
        lcdNumber_value->setLineWidth(1);
        lcdNumber_value->setSmallDecimalPoint(false);
        lcdNumber_value->setDigitCount(8);
        lcdNumber_value->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_value->setProperty("value", QVariant(13.000000000000000));
        lcdNumber_value->setProperty("intValue", QVariant(13));
        label_Name = new QLabel(frame);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setGeometry(QRect(70, 1, 161, 31));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        label_Name->setFont(font1);
        label_Name->setStyleSheet(QString::fromUtf8("color: rgb(3, 87, 123);"));
        toolButton_info = new QToolButton(frame);
        toolButton_info->setObjectName(QString::fromUtf8("toolButton_info"));
        toolButton_info->setGeometry(QRect(5, 5, 61, 61));
        toolButton_info->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 8px;\n"
"border-radius: 8px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"background-color: rgb(25, 149, 190);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/device/iconDeviceOff_401.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_info->setIcon(icon1);
        toolButton_info->setIconSize(QSize(55, 55));
        toolButton_info->setAutoRaise(true);
        toolButton_setup = new QToolButton(frame);
        toolButton_setup->setObjectName(QString::fromUtf8("toolButton_setup"));
        toolButton_setup->setGeometry(QRect(238, 0, 31, 70));
        toolButton_setup->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_setup{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(25, 149, 173);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"}\n"
"QToolButton#toolButton_setup:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"background-color: rgb(25, 149, 190);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/group/iconSetup_On.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/icon/group/iconSetup_On.jpg"), QSize(), QIcon::Disabled, QIcon::Off);
        toolButton_setup->setIcon(icon2);
        toolButton_setup->setIconSize(QSize(20, 20));
        toolButton_setup->setAutoRaise(true);

        retranslateUi(WidSensorToolDigital);

        QMetaObject::connectSlotsByName(WidSensorToolDigital);
    } // setupUi

    void retranslateUi(QWidget *WidSensorToolDigital)
    {
        WidSensorToolDigital->setWindowTitle(QCoreApplication::translate("WidSensorToolDigital", "Form", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_close->setToolTip(QCoreApplication::translate("WidSensorToolDigital", "X\303\263a thi\341\272\277t b\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_close->setText(QCoreApplication::translate("WidSensorToolDigital", "...", nullptr));
        label_Unit->setText(QCoreApplication::translate("WidSensorToolDigital", "(Unit)", nullptr));
        label_Name->setText(QCoreApplication::translate("WidSensorToolDigital", "C\341\272\243m bi\341\272\277n nhi\341\273\207t \304\221\341\273\231", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_info->setToolTip(QCoreApplication::translate("WidSensorToolDigital", "Th\303\264ng tin thi\341\272\277t b\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_info->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_setup->setToolTip(QCoreApplication::translate("WidSensorToolDigital", "C\303\240i \304\221\341\272\267t thi\341\272\277t b\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_setup->setText(QCoreApplication::translate("WidSensorToolDigital", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidSensorToolDigital: public Ui_WidSensorToolDigital {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDSENSORTOOLDIGITAL_H
