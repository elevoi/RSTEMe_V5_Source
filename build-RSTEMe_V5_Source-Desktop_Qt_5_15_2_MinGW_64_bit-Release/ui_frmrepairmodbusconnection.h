/********************************************************************************
** Form generated from reading UI file 'frmrepairmodbusconnection.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMREPAIRMODBUSCONNECTION_H
#define UI_FRMREPAIRMODBUSCONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmRepairModbusConnection
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label;
    QSpinBox *spinBox_StartRegister;
    QSpinBox *spinBox_TimerScan;
    QSpinBox *spinBox_NumberRegister;
    QComboBox *comboBox_typeRegister;
    QLabel *label_3;
    QPushButton *pushButton_Start;
    QLabel *label_5;
    QSpinBox *spinBox_TimerOut;
    QRadioButton *radioButton_Hex;
    QRadioButton *radioButton_Dec;
    QPlainTextEdit *plainTextEdit_Result;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QLabel *label_Count;
    QLabel *label_8;
    QLabel *label_ErrorScan;
    QSpinBox *spinBox_displayTo;
    QLabel *label_10;
    QSpinBox *spinBox_displayFrom;
    QLabel *label_9;

    void setupUi(QMainWindow *FrmRepairModbusConnection)
    {
        if (FrmRepairModbusConnection->objectName().isEmpty())
            FrmRepairModbusConnection->setObjectName(QString::fromUtf8("FrmRepairModbusConnection"));
        FrmRepairModbusConnection->resize(1000, 800);
        centralwidget = new QWidget(FrmRepairModbusConnection);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 981, 80));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(570, 20, 121, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 20, 91, 16));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 20, 91, 16));
        spinBox_StartRegister = new QSpinBox(groupBox);
        spinBox_StartRegister->setObjectName(QString::fromUtf8("spinBox_StartRegister"));
        spinBox_StartRegister->setGeometry(QRect(180, 40, 91, 22));
        spinBox_StartRegister->setMinimum(0);
        spinBox_StartRegister->setMaximum(65535);
        spinBox_StartRegister->setValue(40001);
        spinBox_TimerScan = new QSpinBox(groupBox);
        spinBox_TimerScan->setObjectName(QString::fromUtf8("spinBox_TimerScan"));
        spinBox_TimerScan->setGeometry(QRect(570, 40, 101, 22));
        spinBox_TimerScan->setMinimum(1);
        spinBox_TimerScan->setMaximum(65535);
        spinBox_TimerScan->setValue(500);
        spinBox_NumberRegister = new QSpinBox(groupBox);
        spinBox_NumberRegister->setObjectName(QString::fromUtf8("spinBox_NumberRegister"));
        spinBox_NumberRegister->setGeometry(QRect(300, 40, 91, 22));
        spinBox_NumberRegister->setMinimum(1);
        spinBox_NumberRegister->setMaximum(120);
        spinBox_NumberRegister->setValue(20);
        comboBox_typeRegister = new QComboBox(groupBox);
        comboBox_typeRegister->addItem(QString());
        comboBox_typeRegister->addItem(QString());
        comboBox_typeRegister->setObjectName(QString::fromUtf8("comboBox_typeRegister"));
        comboBox_typeRegister->setGeometry(QRect(30, 40, 131, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 20, 91, 16));
        pushButton_Start = new QPushButton(groupBox);
        pushButton_Start->setObjectName(QString::fromUtf8("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(840, 32, 131, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        pushButton_Start->setFont(font1);
        pushButton_Start->setStyleSheet(QString::fromUtf8(""));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(410, 20, 101, 16));
        spinBox_TimerOut = new QSpinBox(groupBox);
        spinBox_TimerOut->setObjectName(QString::fromUtf8("spinBox_TimerOut"));
        spinBox_TimerOut->setGeometry(QRect(410, 40, 91, 22));
        spinBox_TimerOut->setMinimum(10);
        spinBox_TimerOut->setMaximum(65535);
        spinBox_TimerOut->setValue(100);
        radioButton_Hex = new QRadioButton(groupBox);
        radioButton_Hex->setObjectName(QString::fromUtf8("radioButton_Hex"));
        radioButton_Hex->setGeometry(QRect(720, 40, 51, 20));
        radioButton_Hex->setChecked(true);
        radioButton_Dec = new QRadioButton(groupBox);
        radioButton_Dec->setObjectName(QString::fromUtf8("radioButton_Dec"));
        radioButton_Dec->setGeometry(QRect(780, 40, 51, 20));
        plainTextEdit_Result = new QPlainTextEdit(centralwidget);
        plainTextEdit_Result->setObjectName(QString::fromUtf8("plainTextEdit_Result"));
        plainTextEdit_Result->setGeometry(QRect(10, 170, 981, 621));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 90, 981, 51));
        groupBox_2->setFont(font1);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 20, 31, 16));
        label_Count = new QLabel(groupBox_2);
        label_Count->setObjectName(QString::fromUtf8("label_Count"));
        label_Count->setGeometry(QRect(70, 20, 111, 16));
        label_Count->setFont(font1);
        label_Count->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 20, 51, 16));
        label_ErrorScan = new QLabel(groupBox_2);
        label_ErrorScan->setObjectName(QString::fromUtf8("label_ErrorScan"));
        label_ErrorScan->setGeometry(QRect(260, 20, 111, 16));
        label_ErrorScan->setFont(font1);
        label_ErrorScan->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        spinBox_displayTo = new QSpinBox(centralwidget);
        spinBox_displayTo->setObjectName(QString::fromUtf8("spinBox_displayTo"));
        spinBox_displayTo->setGeometry(QRect(280, 145, 91, 22));
        spinBox_displayTo->setFont(font);
        spinBox_displayTo->setMinimum(0);
        spinBox_displayTo->setMaximum(120);
        spinBox_displayTo->setValue(100);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(250, 148, 31, 16));
        label_10->setFont(font);
        spinBox_displayFrom = new QSpinBox(centralwidget);
        spinBox_displayFrom->setObjectName(QString::fromUtf8("spinBox_displayFrom"));
        spinBox_displayFrom->setGeometry(QRect(140, 145, 91, 22));
        spinBox_displayFrom->setFont(font);
        spinBox_displayFrom->setMinimum(0);
        spinBox_displayFrom->setMaximum(120);
        spinBox_displayFrom->setValue(0);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 148, 121, 16));
        label_9->setFont(font);
        FrmRepairModbusConnection->setCentralWidget(centralwidget);
        QWidget::setTabOrder(comboBox_typeRegister, spinBox_StartRegister);
        QWidget::setTabOrder(spinBox_StartRegister, spinBox_NumberRegister);
        QWidget::setTabOrder(spinBox_NumberRegister, spinBox_TimerOut);
        QWidget::setTabOrder(spinBox_TimerOut, spinBox_TimerScan);
        QWidget::setTabOrder(spinBox_TimerScan, radioButton_Hex);
        QWidget::setTabOrder(radioButton_Hex, radioButton_Dec);
        QWidget::setTabOrder(radioButton_Dec, pushButton_Start);
        QWidget::setTabOrder(pushButton_Start, plainTextEdit_Result);
        QWidget::setTabOrder(plainTextEdit_Result, spinBox_displayFrom);
        QWidget::setTabOrder(spinBox_displayFrom, spinBox_displayTo);

        retranslateUi(FrmRepairModbusConnection);

        QMetaObject::connectSlotsByName(FrmRepairModbusConnection);
    } // setupUi

    void retranslateUi(QMainWindow *FrmRepairModbusConnection)
    {
        FrmRepairModbusConnection->setWindowTitle(QCoreApplication::translate("FrmRepairModbusConnection", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FrmRepairModbusConnection", "Th\303\264ng tin", nullptr));
        label_4->setText(QCoreApplication::translate("FrmRepairModbusConnection", "Th\341\273\235i gian qu\303\251t (ms)", nullptr));
        label_2->setText(QCoreApplication::translate("FrmRepairModbusConnection", "S\341\273\221 thanh ghi", nullptr));
        label->setText(QCoreApplication::translate("FrmRepairModbusConnection", "\304\220\341\273\213a ch\341\273\211 b\341\272\257t \304\221\341\272\247u", nullptr));
        comboBox_typeRegister->setItemText(0, QCoreApplication::translate("FrmRepairModbusConnection", "Holding Registers", nullptr));
        comboBox_typeRegister->setItemText(1, QCoreApplication::translate("FrmRepairModbusConnection", "Input Registers", nullptr));

        label_3->setText(QCoreApplication::translate("FrmRepairModbusConnection", "Lo\341\272\241i thanh ghi", nullptr));
        pushButton_Start->setText(QCoreApplication::translate("FrmRepairModbusConnection", "B\341\272\257t \304\221\341\272\247u", nullptr));
        label_5->setText(QCoreApplication::translate("FrmRepairModbusConnection", "Th\341\273\235i gian l\341\273\227i (ms)", nullptr));
        radioButton_Hex->setText(QCoreApplication::translate("FrmRepairModbusConnection", "Hex", nullptr));
        radioButton_Dec->setText(QCoreApplication::translate("FrmRepairModbusConnection", "Dec", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FrmRepairModbusConnection", "\304\220\303\241nh gi\303\241", nullptr));
        label_6->setText(QCoreApplication::translate("FrmRepairModbusConnection", "\304\220\341\272\277m:", nullptr));
        label_Count->setText(QCoreApplication::translate("FrmRepairModbusConnection", "0", nullptr));
        label_8->setText(QCoreApplication::translate("FrmRepairModbusConnection", "L\341\273\227i qu\303\251t:", nullptr));
        label_ErrorScan->setText(QCoreApplication::translate("FrmRepairModbusConnection", "0", nullptr));
        label_10->setText(QCoreApplication::translate("FrmRepairModbusConnection", "\304\220\341\272\277n:", nullptr));
        label_9->setText(QCoreApplication::translate("FrmRepairModbusConnection", "Hi\341\273\203n th\341\273\213 thanh ghi t\341\273\253:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmRepairModbusConnection: public Ui_FrmRepairModbusConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMREPAIRMODBUSCONNECTION_H
