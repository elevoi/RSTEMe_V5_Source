/********************************************************************************
** Form generated from reading UI file 'frmsetupserial.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSETUPSERIAL_H
#define UI_FRMSETUPSERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmSetupSerial
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_Info;
    QPushButton *pushButton_writeSerial;
    QLabel *label_3;
    QLabel *label;
    QComboBox *comboBox_groupDevice;
    QLineEdit *lineEdit_id;
    QLabel *label_4;
    QComboBox *comboBox_typeDevice;
    QLabel *label_7;
    QSpinBox *spinBox_versioneDevice;
    QLabel *label_8;
    QFrame *line;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *lineEdit_serialNumber;
    QCheckBox *checkBox_Increase;
    QFrame *line_2;
    QPushButton *pushButton_Cancel;
    QFrame *line_3;

    void setupUi(QMainWindow *FrmSetupSerial)
    {
        if (FrmSetupSerial->objectName().isEmpty())
            FrmSetupSerial->setObjectName(QString::fromUtf8("FrmSetupSerial"));
        FrmSetupSerial->resize(660, 320);
        centralwidget = new QWidget(FrmSetupSerial);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_Info = new QGroupBox(centralwidget);
        groupBox_Info->setObjectName(QString::fromUtf8("groupBox_Info"));
        groupBox_Info->setGeometry(QRect(10, 10, 641, 271));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        groupBox_Info->setFont(font);
        groupBox_Info->setFlat(false);
        pushButton_writeSerial = new QPushButton(groupBox_Info);
        pushButton_writeSerial->setObjectName(QString::fromUtf8("pushButton_writeSerial"));
        pushButton_writeSerial->setEnabled(true);
        pushButton_writeSerial->setGeometry(QRect(380, 220, 241, 41));
        pushButton_writeSerial->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        pushButton_writeSerial->setFont(font1);
        label_3 = new QLabel(groupBox_Info);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(18, 150, 91, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        label_3->setFont(font2);
        label = new QLabel(groupBox_Info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(34, 70, 71, 31));
        label->setFont(font2);
        comboBox_groupDevice = new QComboBox(groupBox_Info);
        comboBox_groupDevice->addItem(QString());
        comboBox_groupDevice->addItem(QString());
        comboBox_groupDevice->addItem(QString());
        comboBox_groupDevice->addItem(QString());
        comboBox_groupDevice->setObjectName(QString::fromUtf8("comboBox_groupDevice"));
        comboBox_groupDevice->setGeometry(QRect(120, 70, 201, 30));
        comboBox_groupDevice->setMinimumSize(QSize(0, 30));
        comboBox_groupDevice->setFont(font2);
        lineEdit_id = new QLineEdit(groupBox_Info);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(120, 150, 151, 30));
        lineEdit_id->setMinimumSize(QSize(100, 30));
        lineEdit_id->setFont(font2);
        lineEdit_id->setMaxLength(4);
        lineEdit_id->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_4 = new QLabel(groupBox_Info);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(46, 110, 61, 31));
        label_4->setFont(font2);
        comboBox_typeDevice = new QComboBox(groupBox_Info);
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->setObjectName(QString::fromUtf8("comboBox_typeDevice"));
        comboBox_typeDevice->setGeometry(QRect(120, 110, 201, 30));
        comboBox_typeDevice->setMinimumSize(QSize(0, 30));
        comboBox_typeDevice->setFont(font2);
        label_7 = new QLabel(groupBox_Info);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(42, 30, 61, 31));
        label_7->setFont(font2);
        spinBox_versioneDevice = new QSpinBox(groupBox_Info);
        spinBox_versioneDevice->setObjectName(QString::fromUtf8("spinBox_versioneDevice"));
        spinBox_versioneDevice->setGeometry(QRect(120, 30, 71, 30));
        spinBox_versioneDevice->setMinimum(1);
        spinBox_versioneDevice->setMaximum(9);
        spinBox_versioneDevice->setValue(5);
        label_8 = new QLabel(groupBox_Info);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(360, 20, 81, 30));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(true);
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(groupBox_Info);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(380, 180, 241, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        plainTextEdit = new QPlainTextEdit(groupBox_Info);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(380, 93, 241, 91));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setItalic(true);
        plainTextEdit->setFont(font4);
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"color: rgb(50, 50,50);"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setReadOnly(true);
        lineEdit_serialNumber = new QLineEdit(groupBox_Info);
        lineEdit_serialNumber->setObjectName(QString::fromUtf8("lineEdit_serialNumber"));
        lineEdit_serialNumber->setGeometry(QRect(380, 50, 241, 41));
        lineEdit_serialNumber->setMinimumSize(QSize(100, 30));
        QFont font5;
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setItalic(true);
        lineEdit_serialNumber->setFont(font5);
        lineEdit_serialNumber->setMaxLength(8);
        lineEdit_serialNumber->setAlignment(Qt::AlignCenter);
        checkBox_Increase = new QCheckBox(groupBox_Info);
        checkBox_Increase->setObjectName(QString::fromUtf8("checkBox_Increase"));
        checkBox_Increase->setGeometry(QRect(380, 194, 281, 20));
        checkBox_Increase->setFont(font2);
        line_2 = new QFrame(groupBox_Info);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(330, 20, 20, 231));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pushButton_Cancel = new QPushButton(centralwidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(550, 286, 100, 30));
        pushButton_Cancel->setFont(font2);
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 280, 660, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        FrmSetupSerial->setCentralWidget(centralwidget);
        QWidget::setTabOrder(spinBox_versioneDevice, comboBox_groupDevice);
        QWidget::setTabOrder(comboBox_groupDevice, comboBox_typeDevice);
        QWidget::setTabOrder(comboBox_typeDevice, lineEdit_id);
        QWidget::setTabOrder(lineEdit_id, lineEdit_serialNumber);
        QWidget::setTabOrder(lineEdit_serialNumber, plainTextEdit);
        QWidget::setTabOrder(plainTextEdit, checkBox_Increase);
        QWidget::setTabOrder(checkBox_Increase, pushButton_writeSerial);
        QWidget::setTabOrder(pushButton_writeSerial, pushButton_Cancel);

        retranslateUi(FrmSetupSerial);

        comboBox_groupDevice->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FrmSetupSerial);
    } // setupUi

    void retranslateUi(QMainWindow *FrmSetupSerial)
    {
        FrmSetupSerial->setWindowTitle(QCoreApplication::translate("FrmSetupSerial", "MainWindow", nullptr));
        groupBox_Info->setTitle(QCoreApplication::translate("FrmSetupSerial", "Th\303\264ng tin chi ti\341\272\277t v\341\273\201 thi\341\272\277t b\341\273\213", nullptr));
        pushButton_writeSerial->setText(QCoreApplication::translate("FrmSetupSerial", "Ghi m\303\243 thi\341\272\277t b\341\273\213", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_writeSerial->setShortcut(QCoreApplication::translate("FrmSetupSerial", "Return, Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        label_3->setText(QCoreApplication::translate("FrmSetupSerial", "M\303\243 \304\221\341\273\213nh danh:", nullptr));
        label->setText(QCoreApplication::translate("FrmSetupSerial", "Ph\303\242n nh\303\263m:", nullptr));
        comboBox_groupDevice->setItemText(0, QCoreApplication::translate("FrmSetupSerial", "Ph\341\272\247n m\341\273\201m", nullptr));
        comboBox_groupDevice->setItemText(1, QCoreApplication::translate("FrmSetupSerial", "C\341\272\243m bi\341\272\277n", nullptr));
        comboBox_groupDevice->setItemText(2, QCoreApplication::translate("FrmSetupSerial", "M\303\264-\304\221un th\341\273\261c h\303\240nh", nullptr));
        comboBox_groupDevice->setItemText(3, QCoreApplication::translate("FrmSetupSerial", "M\303\264 h\303\254nh th\303\255 nghi\341\273\207m", nullptr));

        lineEdit_id->setPlaceholderText(QCoreApplication::translate("FrmSetupSerial", "g\341\273\223m 4 k\303\255 t\341\273\261 [0-9][A-F]...", nullptr));
        label_4->setText(QCoreApplication::translate("FrmSetupSerial", "Ph\303\242n lo\341\272\241i:", nullptr));
        comboBox_typeDevice->setItemText(0, QCoreApplication::translate("FrmSetupSerial", "C\341\272\243m bi\341\272\277n nhi\341\273\207t \304\221\341\273\231", nullptr));
        comboBox_typeDevice->setItemText(1, QCoreApplication::translate("FrmSetupSerial", "C\341\272\243m bi\341\272\277n \304\221\341\273\231 \341\272\251m", nullptr));
        comboBox_typeDevice->setItemText(2, QCoreApplication::translate("FrmSetupSerial", "C\341\272\243m bi\341\272\277n l\341\273\261c", nullptr));
        comboBox_typeDevice->setItemText(3, QCoreApplication::translate("FrmSetupSerial", "C\341\272\243m bi\341\272\277n \303\241p su\341\272\245t", nullptr));
        comboBox_typeDevice->setItemText(4, QCoreApplication::translate("FrmSetupSerial", "C\341\272\243m bi\341\272\277n \303\242m thanh", nullptr));

        label_7->setText(QCoreApplication::translate("FrmSetupSerial", "Phi\303\252n b\341\272\243n:", nullptr));
        label_8->setText(QCoreApplication::translate("FrmSetupSerial", "M\303\243 thi\341\272\277t b\341\273\213 :", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("FrmSetupSerial", "M\303\243 thi\341\272\277t b\341\273\213 c\303\263 d\341\272\241ng: ABCDEFGH\n"
"A          Phi\303\252n b\341\272\243n\n"
"B          Nh\303\263m \341\273\251ng d\341\273\245ng\n"
"CD       Lo\341\272\241i thi\341\272\277t b\341\273\213\n"
"EFGH   M\303\243 \304\221\341\273\213nh danh thi\341\272\277t b\341\273\213", nullptr));
        lineEdit_serialNumber->setText(QString());
        lineEdit_serialNumber->setPlaceholderText(QCoreApplication::translate("FrmSetupSerial", "g\341\273\223m 8 k\303\255 t\341\273\261 [0-9][A-F]...", nullptr));
        checkBox_Increase->setText(QCoreApplication::translate("FrmSetupSerial", "T\304\203ng l\303\252n 1 sau khi ghi", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("FrmSetupSerial", "Tho\303\241t", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Cancel->setShortcut(QCoreApplication::translate("FrmSetupSerial", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class FrmSetupSerial: public Ui_FrmSetupSerial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSETUPSERIAL_H
