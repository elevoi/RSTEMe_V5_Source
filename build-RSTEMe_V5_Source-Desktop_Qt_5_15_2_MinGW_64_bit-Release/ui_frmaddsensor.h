/********************************************************************************
** Form generated from reading UI file 'frmaddsensor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMADDSENSOR_H
#define UI_FRMADDSENSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmAddSensor
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_Info;
    QTabWidget *tabWidget_Genaral;
    QWidget *tab;
    QPushButton *pushButton_writeFile;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *lineEdit_nameDevice;
    QSpinBox *spinBox_versioneDevice;
    QLabel *label_7;
    QLabel *label_5;
    QComboBox *comboBox_typeDevice;
    QLabel *label_2;
    QPushButton *pushButton_openFile;
    QPlainTextEdit *plainTextEdit;
    QComboBox *comboBox_groupDevice;
    QLineEdit *lineEdit_serialNumber;
    QPushButton *pushButton_iconDevice;
    QLabel *label_serialNumber;
    QLabel *label_18;
    QComboBox *comboBox_accountType;
    QWidget *tab_2;
    QTabWidget *tabWidget_Parameter;
    QWidget *tab_3;
    QSpinBox *spinBox_sampleTime;
    QLabel *label_6;
    QLabel *label_13;
    QGroupBox *groupBox_2;
    QSpinBox *spinBox_rangeMin;
    QSpinBox *spinBox_rangeMax;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *tab_5;
    QGroupBox *groupBox_4;
    QLabel *label_19;
    QSpinBox *spinBox_calibTime;
    QLabel *label_20;
    QLabel *label_21;
    QSpinBox *spinBox_calibSampleTime;
    QSpinBox *spinBox_sampleNumber;
    QLabel *label_22;
    QLabel *label_23;
    QComboBox *comboBox_accuracySelect;
    QLabel *label_24;
    QLineEdit *lineEdit_accuracy;
    QFrame *frame_2;
    QRadioButton *radioButton_standardSample;
    QRadioButton *radioButton_referenceSample;
    QLabel *label_25;
    QLineEdit *lineEdit_standardValue_01;
    QComboBox *comboBox_evaluateSelect;
    QLabel *label_26;
    QLabel *label_27;
    QLineEdit *lineEdit_standardValue_02;
    QLineEdit *lineEdit_standardValue_03;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QFrame *line;
    QFrame *line_3;
    QFrame *line_4;
    QWidget *tab_4;
    QGroupBox *groupBox;
    QSpinBox *spinBox_requestTimeOut;
    QSpinBox *spinBox_requestRetries;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_10;
    QSpinBox *spinBox_addressDefault;
    QSpinBox *spinBox_requestPriority;
    QLabel *label_9;
    QGroupBox *groupBox_3;
    QLabel *label_16;
    QSpinBox *spinBox_regStart;
    QLabel *label_17;
    QSpinBox *spinBox_regNumber;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_addDevice;
    QGroupBox *groupBox_description;
    QTextEdit *textEdit_descriptionDevice;

    void setupUi(QMainWindow *FrmAddSensor)
    {
        if (FrmAddSensor->objectName().isEmpty())
            FrmAddSensor->setObjectName(QString::fromUtf8("FrmAddSensor"));
        FrmAddSensor->resize(850, 658);
        FrmAddSensor->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color: rgb(240, 240, 240);\n"
"}"));
        centralwidget = new QWidget(FrmAddSensor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_Info = new QGroupBox(centralwidget);
        groupBox_Info->setObjectName(QString::fromUtf8("groupBox_Info"));
        groupBox_Info->setGeometry(QRect(10, 10, 361, 611));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        groupBox_Info->setFont(font);
        groupBox_Info->setFlat(false);
        tabWidget_Genaral = new QTabWidget(groupBox_Info);
        tabWidget_Genaral->setObjectName(QString::fromUtf8("tabWidget_Genaral"));
        tabWidget_Genaral->setGeometry(QRect(10, 20, 341, 581));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        tabWidget_Genaral->setFont(font1);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton_writeFile = new QPushButton(tab);
        pushButton_writeFile->setObjectName(QString::fromUtf8("pushButton_writeFile"));
        pushButton_writeFile->setEnabled(true);
        pushButton_writeFile->setGeometry(QRect(220, 520, 100, 25));
        pushButton_writeFile->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(true);
        pushButton_writeFile->setFont(font2);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(19, 50, 81, 31));
        label_3->setFont(font1);
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 10, 171, 31));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(true);
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 170, 127);"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(33, 100, 71, 31));
        label->setFont(font1);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(45, 140, 61, 31));
        label_4->setFont(font1);
        lineEdit_nameDevice = new QLineEdit(tab);
        lineEdit_nameDevice->setObjectName(QString::fromUtf8("lineEdit_nameDevice"));
        lineEdit_nameDevice->setGeometry(QRect(120, 180, 201, 30));
        lineEdit_nameDevice->setMinimumSize(QSize(0, 30));
        lineEdit_nameDevice->setFont(font1);
        lineEdit_nameDevice->setMaxLength(30);
        lineEdit_nameDevice->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        spinBox_versioneDevice = new QSpinBox(tab);
        spinBox_versioneDevice->setObjectName(QString::fromUtf8("spinBox_versioneDevice"));
        spinBox_versioneDevice->setGeometry(QRect(120, 220, 71, 30));
        spinBox_versioneDevice->setMinimum(1);
        spinBox_versioneDevice->setMaximum(9);
        spinBox_versioneDevice->setValue(5);
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(41, 220, 61, 31));
        label_7->setFont(font1);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(35, 320, 81, 32));
        label_5->setFont(font1);
        comboBox_typeDevice = new QComboBox(tab);
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->setObjectName(QString::fromUtf8("comboBox_typeDevice"));
        comboBox_typeDevice->setGeometry(QRect(120, 140, 201, 30));
        comboBox_typeDevice->setMinimumSize(QSize(0, 30));
        comboBox_typeDevice->setFont(font1);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(32, 180, 71, 32));
        label_2->setFont(font1);
        pushButton_openFile = new QPushButton(tab);
        pushButton_openFile->setObjectName(QString::fromUtf8("pushButton_openFile"));
        pushButton_openFile->setEnabled(true);
        pushButton_openFile->setGeometry(QRect(259, 50, 61, 31));
        pushButton_openFile->setMinimumSize(QSize(0, 30));
        pushButton_openFile->setFont(font2);
        plainTextEdit = new QPlainTextEdit(tab);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(19, 417, 301, 91));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setItalic(true);
        plainTextEdit->setFont(font4);
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"color: rgb(0, 85, 127);"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setReadOnly(true);
        comboBox_groupDevice = new QComboBox(tab);
        comboBox_groupDevice->addItem(QString());
        comboBox_groupDevice->addItem(QString());
        comboBox_groupDevice->addItem(QString());
        comboBox_groupDevice->addItem(QString());
        comboBox_groupDevice->setObjectName(QString::fromUtf8("comboBox_groupDevice"));
        comboBox_groupDevice->setGeometry(QRect(120, 100, 201, 30));
        comboBox_groupDevice->setMinimumSize(QSize(0, 30));
        comboBox_groupDevice->setFont(font1);
        lineEdit_serialNumber = new QLineEdit(tab);
        lineEdit_serialNumber->setObjectName(QString::fromUtf8("lineEdit_serialNumber"));
        lineEdit_serialNumber->setGeometry(QRect(119, 50, 131, 30));
        lineEdit_serialNumber->setMinimumSize(QSize(100, 30));
        lineEdit_serialNumber->setFont(font1);
        lineEdit_serialNumber->setMaxLength(4);
        lineEdit_serialNumber->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        pushButton_iconDevice = new QPushButton(tab);
        pushButton_iconDevice->setObjectName(QString::fromUtf8("pushButton_iconDevice"));
        pushButton_iconDevice->setGeometry(QRect(120, 300, 100, 100));
        pushButton_iconDevice->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_iconDevice->setIconSize(QSize(100, 100));
        label_serialNumber = new QLabel(tab);
        label_serialNumber->setObjectName(QString::fromUtf8("label_serialNumber"));
        label_serialNumber->setGeometry(QRect(178, 10, 141, 31));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setItalic(false);
        label_serialNumber->setFont(font5);
        label_serialNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 127);\n"
"color: rgb(255, 255, 255);"));
        label_18 = new QLabel(tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(11, 258, 91, 35));
        label_18->setFont(font1);
        comboBox_accountType = new QComboBox(tab);
        comboBox_accountType->addItem(QString());
        comboBox_accountType->addItem(QString());
        comboBox_accountType->addItem(QString());
        comboBox_accountType->setObjectName(QString::fromUtf8("comboBox_accountType"));
        comboBox_accountType->setGeometry(QRect(120, 260, 201, 30));
        comboBox_accountType->setFont(font1);
        comboBox_accountType->setEditable(false);
        tabWidget_Genaral->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget_Parameter = new QTabWidget(tab_2);
        tabWidget_Parameter->setObjectName(QString::fromUtf8("tabWidget_Parameter"));
        tabWidget_Parameter->setGeometry(QRect(-1, 0, 341, 556));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        spinBox_sampleTime = new QSpinBox(tab_3);
        spinBox_sampleTime->setObjectName(QString::fromUtf8("spinBox_sampleTime"));
        spinBox_sampleTime->setGeometry(QRect(160, 13, 131, 30));
        spinBox_sampleTime->setMinimum(50);
        spinBox_sampleTime->setMaximum(65535);
        spinBox_sampleTime->setSingleStep(1);
        spinBox_sampleTime->setValue(1000);
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 20, 111, 16));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(300, 20, 31, 16));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 50, 311, 61));
        spinBox_rangeMin = new QSpinBox(groupBox_2);
        spinBox_rangeMin->setObjectName(QString::fromUtf8("spinBox_rangeMin"));
        spinBox_rangeMin->setGeometry(QRect(50, 20, 91, 30));
        spinBox_rangeMin->setMinimum(-999999);
        spinBox_rangeMin->setMaximum(999999);
        spinBox_rangeMin->setSingleStep(1);
        spinBox_rangeMin->setValue(0);
        spinBox_rangeMax = new QSpinBox(groupBox_2);
        spinBox_rangeMax->setObjectName(QString::fromUtf8("spinBox_rangeMax"));
        spinBox_rangeMax->setGeometry(QRect(190, 20, 91, 30));
        spinBox_rangeMax->setMinimum(-999999);
        spinBox_rangeMax->setMaximum(999999);
        spinBox_rangeMax->setSingleStep(1);
        spinBox_rangeMax->setValue(100);
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(25, 27, 21, 16));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(155, 27, 31, 16));
        tabWidget_Parameter->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        groupBox_4 = new QGroupBox(tab_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 311, 511));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setItalic(false);
        groupBox_4->setFont(font6);
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 25, 131, 20));
        QFont font7;
        font7.setPointSize(10);
        font7.setBold(false);
        font7.setItalic(false);
        label_19->setFont(font7);
        spinBox_calibTime = new QSpinBox(groupBox_4);
        spinBox_calibTime->setObjectName(QString::fromUtf8("spinBox_calibTime"));
        spinBox_calibTime->setGeometry(QRect(150, 20, 101, 31));
        spinBox_calibTime->setFont(font6);
        spinBox_calibTime->setMinimum(1);
        spinBox_calibTime->setMaximum(65000);
        spinBox_calibTime->setValue(10);
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(260, 25, 41, 20));
        label_20->setFont(font7);
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 66, 111, 20));
        label_21->setFont(font7);
        spinBox_calibSampleTime = new QSpinBox(groupBox_4);
        spinBox_calibSampleTime->setObjectName(QString::fromUtf8("spinBox_calibSampleTime"));
        spinBox_calibSampleTime->setGeometry(QRect(150, 60, 101, 31));
        spinBox_calibSampleTime->setFont(font6);
        spinBox_calibSampleTime->setMinimum(50);
        spinBox_calibSampleTime->setMaximum(65000);
        spinBox_sampleNumber = new QSpinBox(groupBox_4);
        spinBox_sampleNumber->setObjectName(QString::fromUtf8("spinBox_sampleNumber"));
        spinBox_sampleNumber->setGeometry(QRect(150, 100, 101, 31));
        spinBox_sampleNumber->setFont(font6);
        spinBox_sampleNumber->setMinimum(1);
        spinBox_sampleNumber->setMaximum(65000);
        spinBox_sampleNumber->setValue(10);
        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(20, 106, 111, 20));
        label_22->setFont(font7);
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(260, 66, 31, 20));
        label_23->setFont(font7);
        comboBox_accuracySelect = new QComboBox(groupBox_4);
        comboBox_accuracySelect->addItem(QString());
        comboBox_accuracySelect->addItem(QString());
        comboBox_accuracySelect->addItem(QString());
        comboBox_accuracySelect->setObjectName(QString::fromUtf8("comboBox_accuracySelect"));
        comboBox_accuracySelect->setGeometry(QRect(20, 170, 211, 31));
        comboBox_accuracySelect->setFont(font2);
        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 150, 91, 16));
        label_24->setFont(font3);
        lineEdit_accuracy = new QLineEdit(groupBox_4);
        lineEdit_accuracy->setObjectName(QString::fromUtf8("lineEdit_accuracy"));
        lineEdit_accuracy->setGeometry(QRect(240, 170, 61, 31));
        frame_2 = new QFrame(groupBox_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(30, 230, 241, 41));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        radioButton_standardSample = new QRadioButton(frame_2);
        radioButton_standardSample->setObjectName(QString::fromUtf8("radioButton_standardSample"));
        radioButton_standardSample->setGeometry(QRect(10, 0, 241, 20));
        radioButton_standardSample->setFont(font7);
        radioButton_standardSample->setChecked(true);
        radioButton_referenceSample = new QRadioButton(frame_2);
        radioButton_referenceSample->setObjectName(QString::fromUtf8("radioButton_referenceSample"));
        radioButton_referenceSample->setGeometry(QRect(10, 20, 201, 20));
        radioButton_referenceSample->setFont(font7);
        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 440, 161, 16));
        label_25->setFont(font3);
        lineEdit_standardValue_01 = new QLineEdit(groupBox_4);
        lineEdit_standardValue_01->setObjectName(QString::fromUtf8("lineEdit_standardValue_01"));
        lineEdit_standardValue_01->setGeometry(QRect(150, 310, 81, 30));
        comboBox_evaluateSelect = new QComboBox(groupBox_4);
        comboBox_evaluateSelect->addItem(QString());
        comboBox_evaluateSelect->addItem(QString());
        comboBox_evaluateSelect->setObjectName(QString::fromUtf8("comboBox_evaluateSelect"));
        comboBox_evaluateSelect->setGeometry(QRect(20, 460, 281, 31));
        comboBox_evaluateSelect->setFont(font2);
        label_26 = new QLabel(groupBox_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(20, 315, 121, 20));
        label_26->setFont(font7);
        label_27 = new QLabel(groupBox_4);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 355, 121, 20));
        label_27->setFont(font7);
        lineEdit_standardValue_02 = new QLineEdit(groupBox_4);
        lineEdit_standardValue_02->setObjectName(QString::fromUtf8("lineEdit_standardValue_02"));
        lineEdit_standardValue_02->setGeometry(QRect(150, 350, 81, 30));
        lineEdit_standardValue_03 = new QLineEdit(groupBox_4);
        lineEdit_standardValue_03->setObjectName(QString::fromUtf8("lineEdit_standardValue_03"));
        lineEdit_standardValue_03->setGeometry(QRect(150, 390, 81, 30));
        label_28 = new QLabel(groupBox_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(20, 395, 121, 20));
        label_28->setFont(font7);
        label_29 = new QLabel(groupBox_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(10, 210, 171, 16));
        label_29->setFont(font3);
        label_30 = new QLabel(groupBox_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 290, 161, 16));
        label_30->setFont(font3);
        line = new QFrame(groupBox_4);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 140, 290, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(groupBox_4);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 280, 290, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(groupBox_4);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(10, 430, 290, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        tabWidget_Parameter->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 311, 321));
        spinBox_requestTimeOut = new QSpinBox(groupBox);
        spinBox_requestTimeOut->setObjectName(QString::fromUtf8("spinBox_requestTimeOut"));
        spinBox_requestTimeOut->setGeometry(QRect(140, 140, 111, 30));
        spinBox_requestTimeOut->setMinimum(1);
        spinBox_requestTimeOut->setMaximum(65000);
        spinBox_requestTimeOut->setValue(50);
        spinBox_requestRetries = new QSpinBox(groupBox);
        spinBox_requestRetries->setObjectName(QString::fromUtf8("spinBox_requestRetries"));
        spinBox_requestRetries->setGeometry(QRect(140, 100, 111, 30));
        spinBox_requestRetries->setMinimum(0);
        spinBox_requestRetries->setMaximum(5);
        spinBox_requestRetries->setValue(0);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(52, 140, 81, 31));
        label_12->setFont(font1);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(80, 100, 61, 31));
        label_11->setFont(font1);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 60, 101, 31));
        label_10->setFont(font1);
        spinBox_addressDefault = new QSpinBox(groupBox);
        spinBox_addressDefault->setObjectName(QString::fromUtf8("spinBox_addressDefault"));
        spinBox_addressDefault->setGeometry(QRect(140, 20, 111, 30));
        spinBox_addressDefault->setMinimum(100);
        spinBox_addressDefault->setMaximum(246);
        spinBox_addressDefault->setValue(127);
        spinBox_requestPriority = new QSpinBox(groupBox);
        spinBox_requestPriority->setObjectName(QString::fromUtf8("spinBox_requestPriority"));
        spinBox_requestPriority->setGeometry(QRect(140, 60, 111, 30));
        spinBox_requestPriority->setMinimum(0);
        spinBox_requestPriority->setMaximum(5);
        spinBox_requestPriority->setValue(3);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 20, 101, 31));
        label_9->setFont(font1);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 190, 291, 111));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(58, 75, 71, 20));
        spinBox_regStart = new QSpinBox(groupBox_3);
        spinBox_regStart->setObjectName(QString::fromUtf8("spinBox_regStart"));
        spinBox_regStart->setGeometry(QRect(130, 30, 111, 30));
        spinBox_regStart->setMinimum(1);
        spinBox_regStart->setMaximum(65535);
        spinBox_regStart->setSingleStep(1);
        spinBox_regStart->setValue(40004);
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(91, 37, 31, 16));
        spinBox_regNumber = new QSpinBox(groupBox_3);
        spinBox_regNumber->setObjectName(QString::fromUtf8("spinBox_regNumber"));
        spinBox_regNumber->setGeometry(QRect(130, 70, 111, 30));
        spinBox_regNumber->setMinimum(0);
        spinBox_regNumber->setMaximum(125);
        spinBox_regNumber->setSingleStep(1);
        spinBox_regNumber->setValue(100);
        tabWidget_Parameter->addTab(tab_4, QString());
        tabWidget_Genaral->addTab(tab_2, QString());
        pushButton_Cancel = new QPushButton(centralwidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(740, 623, 100, 30));
        pushButton_Cancel->setFont(font1);
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_addDevice = new QPushButton(centralwidget);
        pushButton_addDevice->setObjectName(QString::fromUtf8("pushButton_addDevice"));
        pushButton_addDevice->setGeometry(QRect(530, 623, 200, 31));
        pushButton_addDevice->setFont(font1);
        pushButton_addDevice->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        groupBox_description = new QGroupBox(centralwidget);
        groupBox_description->setObjectName(QString::fromUtf8("groupBox_description"));
        groupBox_description->setGeometry(QRect(370, 10, 471, 611));
        groupBox_description->setFont(font);
        groupBox_description->setFlat(false);
        textEdit_descriptionDevice = new QTextEdit(groupBox_description);
        textEdit_descriptionDevice->setObjectName(QString::fromUtf8("textEdit_descriptionDevice"));
        textEdit_descriptionDevice->setGeometry(QRect(10, 20, 451, 581));
        textEdit_descriptionDevice->setFont(font1);
        textEdit_descriptionDevice->setMouseTracking(true);
        textEdit_descriptionDevice->setReadOnly(false);
        FrmAddSensor->setCentralWidget(centralwidget);
        QWidget::setTabOrder(tabWidget_Genaral, lineEdit_serialNumber);
        QWidget::setTabOrder(lineEdit_serialNumber, pushButton_openFile);
        QWidget::setTabOrder(pushButton_openFile, comboBox_groupDevice);
        QWidget::setTabOrder(comboBox_groupDevice, comboBox_typeDevice);
        QWidget::setTabOrder(comboBox_typeDevice, lineEdit_nameDevice);
        QWidget::setTabOrder(lineEdit_nameDevice, spinBox_versioneDevice);
        QWidget::setTabOrder(spinBox_versioneDevice, comboBox_accountType);
        QWidget::setTabOrder(comboBox_accountType, pushButton_iconDevice);
        QWidget::setTabOrder(pushButton_iconDevice, plainTextEdit);
        QWidget::setTabOrder(plainTextEdit, pushButton_writeFile);
        QWidget::setTabOrder(pushButton_writeFile, textEdit_descriptionDevice);
        QWidget::setTabOrder(textEdit_descriptionDevice, pushButton_addDevice);
        QWidget::setTabOrder(pushButton_addDevice, pushButton_Cancel);
        QWidget::setTabOrder(pushButton_Cancel, tabWidget_Parameter);
        QWidget::setTabOrder(tabWidget_Parameter, spinBox_sampleTime);
        QWidget::setTabOrder(spinBox_sampleTime, spinBox_rangeMin);
        QWidget::setTabOrder(spinBox_rangeMin, spinBox_rangeMax);
        QWidget::setTabOrder(spinBox_rangeMax, spinBox_requestTimeOut);
        QWidget::setTabOrder(spinBox_requestTimeOut, spinBox_requestRetries);
        QWidget::setTabOrder(spinBox_requestRetries, spinBox_addressDefault);
        QWidget::setTabOrder(spinBox_addressDefault, spinBox_requestPriority);
        QWidget::setTabOrder(spinBox_requestPriority, spinBox_regStart);
        QWidget::setTabOrder(spinBox_regStart, spinBox_regNumber);

        retranslateUi(FrmAddSensor);

        tabWidget_Genaral->setCurrentIndex(0);
        comboBox_groupDevice->setCurrentIndex(1);
        tabWidget_Parameter->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FrmAddSensor);
    } // setupUi

    void retranslateUi(QMainWindow *FrmAddSensor)
    {
        FrmAddSensor->setWindowTitle(QCoreApplication::translate("FrmAddSensor", "MainWindow", nullptr));
        groupBox_Info->setTitle(QCoreApplication::translate("FrmAddSensor", "Th\303\264ng tin chi ti\341\272\277t v\341\273\201 thi\341\272\277t b\341\273\213", nullptr));
        pushButton_writeFile->setText(QCoreApplication::translate("FrmAddSensor", "L\306\260u t\341\273\207p", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_writeFile->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        label_3->setText(QCoreApplication::translate("FrmAddSensor", "M\303\243 \304\221\341\273\213nh danh:", nullptr));
        label_8->setText(QCoreApplication::translate("FrmAddSensor", "                M\303\243 thi\341\272\277t b\341\273\213:", nullptr));
        label->setText(QCoreApplication::translate("FrmAddSensor", "Ph\303\242n nh\303\263m:", nullptr));
        label_4->setText(QCoreApplication::translate("FrmAddSensor", "Ph\303\242n lo\341\272\241i:", nullptr));
        lineEdit_nameDevice->setText(QString());
        lineEdit_nameDevice->setPlaceholderText(QCoreApplication::translate("FrmAddSensor", "t\303\252n g\341\273\243i nh\341\273\233...", nullptr));
        label_7->setText(QCoreApplication::translate("FrmAddSensor", "Phi\303\252n b\341\272\243n:", nullptr));
        label_5->setText(QCoreApplication::translate("FrmAddSensor", "Bi\341\273\203u t\306\260\341\273\243ng:", nullptr));
        comboBox_typeDevice->setItemText(0, QCoreApplication::translate("FrmAddSensor", "C\341\272\243m bi\341\272\277n nhi\341\273\207t \304\221\341\273\231", nullptr));
        comboBox_typeDevice->setItemText(1, QCoreApplication::translate("FrmAddSensor", "C\341\272\243m bi\341\272\277n \304\221\341\273\231 \341\272\251m", nullptr));
        comboBox_typeDevice->setItemText(2, QCoreApplication::translate("FrmAddSensor", "C\341\272\243m bi\341\272\277n l\341\273\261c", nullptr));
        comboBox_typeDevice->setItemText(3, QCoreApplication::translate("FrmAddSensor", "C\341\272\243m bi\341\272\277n \303\241p su\341\272\245t", nullptr));
        comboBox_typeDevice->setItemText(4, QCoreApplication::translate("FrmAddSensor", "C\341\272\243m bi\341\272\277n \303\242m thanh", nullptr));

        label_2->setText(QCoreApplication::translate("FrmAddSensor", "T\303\252n thi\341\272\277t b\341\273\213:", nullptr));
        pushButton_openFile->setText(QCoreApplication::translate("FrmAddSensor", "T\341\272\243i t\341\273\207p", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_openFile->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        plainTextEdit->setPlainText(QCoreApplication::translate("FrmAddSensor", "M\303\243 thi\341\272\277t b\341\273\213 c\303\263 d\341\272\241ng: ABCDEFGH\n"
"A          Phi\303\252n b\341\272\243n\n"
"B          Nh\303\263m \341\273\251ng d\341\273\245ng\n"
"CD       Lo\341\272\241i thi\341\272\277t b\341\273\213\n"
"EFGH   M\303\243 \304\221\341\273\213nh danh thi\341\272\277t b\341\273\213", nullptr));
        comboBox_groupDevice->setItemText(0, QCoreApplication::translate("FrmAddSensor", "Ph\341\272\247n m\341\273\201m", nullptr));
        comboBox_groupDevice->setItemText(1, QCoreApplication::translate("FrmAddSensor", "C\341\272\243m bi\341\272\277n", nullptr));
        comboBox_groupDevice->setItemText(2, QCoreApplication::translate("FrmAddSensor", "M\303\264-\304\221un th\341\273\261c h\303\240nh", nullptr));
        comboBox_groupDevice->setItemText(3, QCoreApplication::translate("FrmAddSensor", "M\303\264 h\303\254nh th\303\255 nghi\341\273\207m", nullptr));

        lineEdit_serialNumber->setPlaceholderText(QCoreApplication::translate("FrmAddSensor", "g\341\273\223m 4 k\303\255 t\341\273\261 [0-9][A-F]...", nullptr));
        pushButton_iconDevice->setText(QString());
        label_serialNumber->setText(QCoreApplication::translate("FrmAddSensor", "000009AF", nullptr));
        label_18->setText(QCoreApplication::translate("FrmAddSensor", "Quy\341\273\201n truy c\341\272\255p:", nullptr));
        comboBox_accountType->setItemText(0, QCoreApplication::translate("FrmAddSensor", "Student (H\341\273\215c sinh)", nullptr));
        comboBox_accountType->setItemText(1, QCoreApplication::translate("FrmAddSensor", "Teacher (Gi\303\241o vi\303\252n)", nullptr));
        comboBox_accountType->setItemText(2, QCoreApplication::translate("FrmAddSensor", "Root (Qu\341\272\243n tr\341\273\213)", nullptr));

        comboBox_accountType->setCurrentText(QCoreApplication::translate("FrmAddSensor", "Student (H\341\273\215c sinh)", nullptr));
        tabWidget_Genaral->setTabText(tabWidget_Genaral->indexOf(tab), QCoreApplication::translate("FrmAddSensor", "           Chung           ", nullptr));
        label_6->setText(QCoreApplication::translate("FrmAddSensor", "Th\341\273\235i gian l\341\272\245y m\341\272\253u:", nullptr));
        label_13->setText(QCoreApplication::translate("FrmAddSensor", "(ms)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FrmAddSensor", "D\341\272\243i \304\221o", nullptr));
        label_14->setText(QCoreApplication::translate("FrmAddSensor", "T\341\273\253", nullptr));
        label_15->setText(QCoreApplication::translate("FrmAddSensor", "\304\220\341\272\277n", nullptr));
        tabWidget_Parameter->setTabText(tabWidget_Parameter->indexOf(tab_3), QCoreApplication::translate("FrmAddSensor", "Th\303\264ng s\341\273\221 ho\341\272\241t \304\221\341\273\231ng", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("FrmAddSensor", "Hi\341\273\207u chu\341\272\251n", nullptr));
        label_19->setText(QCoreApplication::translate("FrmAddSensor", "Th\341\273\235i gian hi\341\273\207u chu\341\272\251n", nullptr));
        label_20->setText(QCoreApplication::translate("FrmAddSensor", "(gi\303\242y)", nullptr));
        label_21->setText(QCoreApplication::translate("FrmAddSensor", "Th\341\273\235i gian l\341\272\245y m\341\272\253u", nullptr));
        label_22->setText(QCoreApplication::translate("FrmAddSensor", "S\341\273\221 l\306\260\341\273\243ng m\341\272\253u \304\221o", nullptr));
        label_23->setText(QCoreApplication::translate("FrmAddSensor", "(ms)", nullptr));
        comboBox_accuracySelect->setItemText(0, QCoreApplication::translate("FrmAddSensor", "Theo gi\303\241 tr\341\273\213 \304\221o", nullptr));
        comboBox_accuracySelect->setItemText(1, QCoreApplication::translate("FrmAddSensor", "Theo ph\341\272\247n tr\304\203m (%RD - reading)", nullptr));
        comboBox_accuracySelect->setItemText(2, QCoreApplication::translate("FrmAddSensor", "Theo to\303\240n thang \304\221o (%FS - fullscale)", nullptr));

        label_24->setText(QCoreApplication::translate("FrmAddSensor", "\304\220\341\273\231 ch\303\255nh x\303\241c", nullptr));
        lineEdit_accuracy->setText(QCoreApplication::translate("FrmAddSensor", "1", nullptr));
        radioButton_standardSample->setText(QCoreApplication::translate("FrmAddSensor", "Hi\341\273\207u chu\341\272\251n theo m\341\272\253u (ngu\341\273\223n) chu\341\272\251n", nullptr));
        radioButton_referenceSample->setText(QCoreApplication::translate("FrmAddSensor", "Hi\341\273\207u chu\341\272\251n theo tham chi\341\272\277u", nullptr));
        label_25->setText(QCoreApplication::translate("FrmAddSensor", "Ph\306\260\306\241ng ph\303\241p \304\221\303\241nh gi\303\241", nullptr));
        lineEdit_standardValue_01->setText(QCoreApplication::translate("FrmAddSensor", "0", nullptr));
        comboBox_evaluateSelect->setItemText(0, QCoreApplication::translate("FrmAddSensor", "Theo \304\221\341\273\231 ch\303\255nh x\303\241c", nullptr));
        comboBox_evaluateSelect->setItemText(1, QCoreApplication::translate("FrmAddSensor", "Theo \304\221\341\273\231 l\341\273\207ch chu\341\272\251n", nullptr));

        label_26->setText(QCoreApplication::translate("FrmAddSensor", "Gi\303\241 tr\341\273\213 chu\341\272\251n CAL-01:", nullptr));
        label_27->setText(QCoreApplication::translate("FrmAddSensor", "Gi\303\241 tr\341\273\213 chu\341\272\251n CAL-02:", nullptr));
        lineEdit_standardValue_02->setText(QCoreApplication::translate("FrmAddSensor", "0", nullptr));
        lineEdit_standardValue_03->setText(QCoreApplication::translate("FrmAddSensor", "0", nullptr));
        label_28->setText(QCoreApplication::translate("FrmAddSensor", "Gi\303\241 tr\341\273\213 chu\341\272\251n  CAL-03:", nullptr));
        label_29->setText(QCoreApplication::translate("FrmAddSensor", "Ph\306\260\306\241ng ph\303\241p hi\341\273\207u chu\341\272\251n", nullptr));
        label_30->setText(QCoreApplication::translate("FrmAddSensor", "\304\220i\341\273\203m chu\341\272\251n", nullptr));
        tabWidget_Parameter->setTabText(tabWidget_Parameter->indexOf(tab_5), QCoreApplication::translate("FrmAddSensor", "Hi\341\273\207u chu\341\272\251n", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FrmAddSensor", "ModbusRTU", nullptr));
        label_12->setText(QCoreApplication::translate("FrmAddSensor", "Th\341\273\235i gian \304\221\341\273\243i:", nullptr));
        label_11->setText(QCoreApplication::translate("FrmAddSensor", "L\341\272\267p l\341\273\207nh:", nullptr));
        label_10->setText(QCoreApplication::translate("FrmAddSensor", "M\341\273\251c \304\221\341\273\231 \306\260u ti\303\252n:", nullptr));
        label_9->setText(QCoreApplication::translate("FrmAddSensor", "\304\220\341\273\213a ch\341\273\211 m\341\272\267c \304\221\341\273\213nh:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("FrmAddSensor", "Truy v\341\272\245n v\303\271ng d\341\273\257 li\341\273\207u", nullptr));
        label_16->setText(QCoreApplication::translate("FrmAddSensor", "K\303\255ch th\306\260\341\273\233c:", nullptr));
        label_17->setText(QCoreApplication::translate("FrmAddSensor", "V\341\273\213 tr\303\255:", nullptr));
        tabWidget_Parameter->setTabText(tabWidget_Parameter->indexOf(tab_4), QCoreApplication::translate("FrmAddSensor", "    K\341\272\277t n\341\273\221i    ", nullptr));
        tabWidget_Genaral->setTabText(tabWidget_Genaral->indexOf(tab_2), QCoreApplication::translate("FrmAddSensor", "          N\303\242ng cao          ", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("FrmAddSensor", "Tho\303\241t", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Cancel->setShortcut(QCoreApplication::translate("FrmAddSensor", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_addDevice->setText(QCoreApplication::translate("FrmAddSensor", "Th\303\252m/S\341\273\255a thi\341\272\277t b\341\273\213", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_addDevice->setShortcut(QCoreApplication::translate("FrmAddSensor", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_description->setTitle(QCoreApplication::translate("FrmAddSensor", "M\303\264 t\341\272\243 chi ti\341\272\277t", nullptr));
        textEdit_descriptionDevice->setPlaceholderText(QCoreApplication::translate("FrmAddSensor", "m\303\264 t\341\272\243 chi ti\341\272\277t c\303\241c tham s\341\273\221 ho\341\272\241t \304\221\341\273\231ng c\341\273\247a thi\341\272\277t b\341\273\213...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmAddSensor: public Ui_FrmAddSensor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMADDSENSOR_H
