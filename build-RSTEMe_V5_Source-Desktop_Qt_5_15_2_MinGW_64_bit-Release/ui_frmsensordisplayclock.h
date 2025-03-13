/********************************************************************************
** Form generated from reading UI file 'frmsensordisplayclock.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSENSORDISPLAYCLOCK_H
#define UI_FRMSENSORDISPLAYCLOCK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmSensorDisplayClock
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView_backgroundClock;
    QGroupBox *groupBox;
    QSpinBox *spinBox_rangeMin;
    QSpinBox *spinBox_rangeMax;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_unit;
    QLabel *label_Name;
    QToolButton *toolButton_info;
    QToolButton *toolButton_config;
    QPushButton *pushButton_cancel;

    void setupUi(QMainWindow *FrmSensorDisplayClock)
    {
        if (FrmSensorDisplayClock->objectName().isEmpty())
            FrmSensorDisplayClock->setObjectName(QString::fromUtf8("FrmSensorDisplayClock"));
        FrmSensorDisplayClock->resize(740, 600);
        FrmSensorDisplayClock->setMinimumSize(QSize(740, 600));
        FrmSensorDisplayClock->setMaximumSize(QSize(740, 600));
        FrmSensorDisplayClock->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color: rgb(2,87, 122);\n"
"}"));
        centralwidget = new QWidget(FrmSensorDisplayClock);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView_backgroundClock = new QGraphicsView(centralwidget);
        graphicsView_backgroundClock->setObjectName(QString::fromUtf8("graphicsView_backgroundClock"));
        graphicsView_backgroundClock->setGeometry(QRect(10, 50, 721, 461));
        graphicsView_backgroundClock->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphicsView_backgroundClock->setFrameShape(QFrame::WinPanel);
        graphicsView_backgroundClock->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(360, 520, 281, 71));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        spinBox_rangeMin = new QSpinBox(groupBox);
        spinBox_rangeMin->setObjectName(QString::fromUtf8("spinBox_rangeMin"));
        spinBox_rangeMin->setGeometry(QRect(40, 30, 101, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        spinBox_rangeMin->setFont(font1);
        spinBox_rangeMin->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"}\n"
"QSpinBox:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        spinBox_rangeMin->setAlignment(Qt::AlignCenter);
        spinBox_rangeMin->setMinimum(-999999);
        spinBox_rangeMin->setMaximum(999999);
        spinBox_rangeMin->setValue(0);
        spinBox_rangeMax = new QSpinBox(groupBox);
        spinBox_rangeMax->setObjectName(QString::fromUtf8("spinBox_rangeMax"));
        spinBox_rangeMax->setGeometry(QRect(180, 30, 91, 31));
        spinBox_rangeMax->setFont(font1);
        spinBox_rangeMax->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"}\n"
"QSpinBox:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        spinBox_rangeMax->setAlignment(Qt::AlignCenter);
        spinBox_rangeMax->setMinimum(-999999);
        spinBox_rangeMax->setMaximum(999999);
        spinBox_rangeMax->setValue(100);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 21, 16));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        label_2->setFont(font2);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(149, 40, 31, 16));
        label_3->setFont(font2);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(80, 520, 271, 71));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        comboBox_unit = new QComboBox(groupBox_2);
        comboBox_unit->addItem(QString());
        comboBox_unit->addItem(QString());
        comboBox_unit->setObjectName(QString::fromUtf8("comboBox_unit"));
        comboBox_unit->setGeometry(QRect(10, 30, 251, 32));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(true);
        comboBox_unit->setFont(font3);
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
"QComboBox::drop-down{\n"
"width: 20;\n"
"}\n"
"QComboBox:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        comboBox_unit->setEditable(true);
        label_Name = new QLabel(centralwidget);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setGeometry(QRect(60, 0, 671, 50));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(24);
        font4.setBold(true);
        label_Name->setFont(font4);
        label_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        toolButton_info = new QToolButton(centralwidget);
        toolButton_info->setObjectName(QString::fromUtf8("toolButton_info"));
        toolButton_info->setGeometry(QRect(10, 5, 41, 41));
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/device/iconDeviceOff_401.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/icon/device/iconDeviceOn_401.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_info->setIcon(icon);
        toolButton_info->setIconSize(QSize(36, 36));
        toolButton_info->setAutoRaise(true);
        toolButton_config = new QToolButton(centralwidget);
        toolButton_config->setObjectName(QString::fromUtf8("toolButton_config"));
        toolButton_config->setGeometry(QRect(10, 530, 61, 61));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/group/iconSetup_On1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icon/group/iconSetup_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_config->setIcon(icon1);
        toolButton_config->setIconSize(QSize(55, 55));
        toolButton_config->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_config->setAutoRaise(true);
        pushButton_cancel = new QPushButton(centralwidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(650, 527, 81, 63));
        pushButton_cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        FrmSensorDisplayClock->setCentralWidget(centralwidget);
        QWidget::setTabOrder(graphicsView_backgroundClock, comboBox_unit);
        QWidget::setTabOrder(comboBox_unit, spinBox_rangeMin);
        QWidget::setTabOrder(spinBox_rangeMin, spinBox_rangeMax);

        retranslateUi(FrmSensorDisplayClock);

        QMetaObject::connectSlotsByName(FrmSensorDisplayClock);
    } // setupUi

    void retranslateUi(QMainWindow *FrmSensorDisplayClock)
    {
        FrmSensorDisplayClock->setWindowTitle(QCoreApplication::translate("FrmSensorDisplayClock", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FrmSensorDisplayClock", "D\341\272\243i \304\221o", nullptr));
        label_2->setText(QCoreApplication::translate("FrmSensorDisplayClock", "T\341\273\253", nullptr));
        label_3->setText(QCoreApplication::translate("FrmSensorDisplayClock", "\304\220\341\272\277n", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FrmSensorDisplayClock", "\304\220\306\241n v\341\273\213 \304\221o", nullptr));
        comboBox_unit->setItemText(0, QCoreApplication::translate("FrmSensorDisplayClock", "\304\220\341\273\231 \341\272\251m t\306\260\306\241ng \304\221\341\273\221i (%RH)", nullptr));
        comboBox_unit->setItemText(1, QCoreApplication::translate("FrmSensorDisplayClock", "\304\220\341\273\231 \341\272\251m tuy\341\273\207t \304\221\341\273\221i (g/m3)", nullptr));

        label_Name->setText(QCoreApplication::translate("FrmSensorDisplayClock", "C\341\272\243m bi\341\272\277n", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_info->setToolTip(QCoreApplication::translate("FrmSensorDisplayClock", "Th\303\264ng tin thi\341\272\277t b\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_info->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_config->setToolTip(QCoreApplication::translate("FrmSensorDisplayClock", "Th\303\264ng tin thi\341\272\277t b\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_config->setText(QString());
        pushButton_cancel->setText(QCoreApplication::translate("FrmSensorDisplayClock", "Tho\303\241t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmSensorDisplayClock: public Ui_FrmSensorDisplayClock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSENSORDISPLAYCLOCK_H
