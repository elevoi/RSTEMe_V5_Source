/********************************************************************************
** Form generated from reading UI file 'frmdevicecalibration.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDEVICECALIBRATION_H
#define UI_FRMDEVICECALIBRATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmDeviceCalibration
{
public:
    QWidget *centralwidget;
    QFrame *frame_toolTrack;
    QToolButton *toolButton_toolCrosshair;
    QToolButton *toolButton_toolCallout;
    QFrame *frame_toolControl;
    QToolButton *toolButton_toolPause;
    QFrame *line_4;
    QToolButton *toolButton_toolPlay;
    QFrame *frame_Header;
    QLabel *label;
    QCheckBox *checkBox_antiAliasing;
    QComboBox *comboBox_legend;
    QLabel *label_3;
    QComboBox *comboBox_theme;
    QFrame *line;
    QFrame *line_2;
    QGraphicsView *graphicsViewChart;
    QGroupBox *groupBox_setupParameter;
    QSpinBox *spinBox_sampleTime;
    QLabel *label_2;
    QSpinBox *spinBox_sampleNumber;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QFrame *frame;
    QLineEdit *lineEdit_accuracy;
    QComboBox *comboBox_accuracySelect;
    QLabel *label_15;
    QLabel *label_accuracyUnit;
    QFrame *line_6;
    QLabel *label_12;
    QFrame *frame_2;
    QRadioButton *radioButton_standardSample;
    QRadioButton *radioButton_referenceSample;
    QFrame *line_7;
    QComboBox *comboBox_calibPointSelect;
    QLabel *label_13;
    QFrame *frame_range;
    QSpinBox *spinBox_rangeMax;
    QLabel *label_10;
    QSpinBox *spinBox_rangeMin;
    QLabel *label_11;
    QPushButton *pushButton_addDeviceRef;
    QLineEdit *lineEdit_standardValue;
    QLabel *label_14;
    QLabel *label_standartValueUnit;
    QLabel *label_22;
    QComboBox *comboBox_evaluateSelect;
    QLabel *label_7;
    QLabel *label_5;
    QSpinBox *spinBox_calibTime;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_calibCAL02;
    QLabel *label_calibCAL01;
    QLabel *label_calibCAL03;
    QLabel *label_25;
    QPushButton *pushButton_clearCalibOne;
    QPushButton *pushButton_clearCalibTwo;
    QPushButton *pushButton_clearCalibThree;
    QFrame *line_3;
    QGroupBox *groupBox_setupParameter_2;
    QLCDNumber *lcdNumber_Value;
    QLabel *label_16;
    QFrame *line_8;
    QLabel *label_17;
    QLabel *label_ratio;
    QLabel *label_error;
    QLCDNumber *lcdNumber_ValueCalib;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_sampleNum;
    QLabel *label_21;
    QLabel *label_20;
    QComboBox *comboBox_unit;
    QLCDNumber *lcdNumber_Reference;
    QLabel *label_26;

    void setupUi(QMainWindow *FrmDeviceCalibration)
    {
        if (FrmDeviceCalibration->objectName().isEmpty())
            FrmDeviceCalibration->setObjectName(QString::fromUtf8("FrmDeviceCalibration"));
        FrmDeviceCalibration->resize(1200, 800);
        FrmDeviceCalibration->setMinimumSize(QSize(1200, 800));
        FrmDeviceCalibration->setMaximumSize(QSize(1200, 800));
        centralwidget = new QWidget(FrmDeviceCalibration);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame_toolTrack = new QFrame(centralwidget);
        frame_toolTrack->setObjectName(QString::fromUtf8("frame_toolTrack"));
        frame_toolTrack->setGeometry(QRect(-1, 40, 51, 381));
        frame_toolTrack->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        frame_toolTrack->setFrameShape(QFrame::NoFrame);
        frame_toolTrack->setFrameShadow(QFrame::Raised);
        toolButton_toolCrosshair = new QToolButton(frame_toolTrack);
        toolButton_toolCrosshair->setObjectName(QString::fromUtf8("toolButton_toolCrosshair"));
        toolButton_toolCrosshair->setGeometry(QRect(5, 10, 40, 40));
        toolButton_toolCrosshair->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/chart/iconChartCrosshair_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/icon/chart/iconChartCrosshair_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolCrosshair->setIcon(icon);
        toolButton_toolCrosshair->setIconSize(QSize(30, 30));
        toolButton_toolCrosshair->setAutoRaise(true);
        toolButton_toolCallout = new QToolButton(frame_toolTrack);
        toolButton_toolCallout->setObjectName(QString::fromUtf8("toolButton_toolCallout"));
        toolButton_toolCallout->setGeometry(QRect(5, 60, 40, 40));
        toolButton_toolCallout->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/chart/iconChartCallout_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icon/chart/iconChartCallout_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolCallout->setIcon(icon1);
        toolButton_toolCallout->setIconSize(QSize(30, 30));
        toolButton_toolCallout->setAutoRaise(true);
        frame_toolControl = new QFrame(centralwidget);
        frame_toolControl->setObjectName(QString::fromUtf8("frame_toolControl"));
        frame_toolControl->setGeometry(QRect(-1, 420, 51, 111));
        frame_toolControl->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        frame_toolControl->setFrameShape(QFrame::StyledPanel);
        frame_toolControl->setFrameShadow(QFrame::Raised);
        toolButton_toolPause = new QToolButton(frame_toolControl);
        toolButton_toolPause->setObjectName(QString::fromUtf8("toolButton_toolPause"));
        toolButton_toolPause->setGeometry(QRect(5, 60, 40, 40));
        toolButton_toolPause->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/chart/iconChartPause_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/icon/chart/iconChartPause_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolPause->setIcon(icon2);
        toolButton_toolPause->setIconSize(QSize(30, 30));
        toolButton_toolPause->setAutoRaise(true);
        line_4 = new QFrame(frame_toolControl);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(5, -7, 41, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        toolButton_toolPlay = new QToolButton(frame_toolControl);
        toolButton_toolPlay->setObjectName(QString::fromUtf8("toolButton_toolPlay"));
        toolButton_toolPlay->setGeometry(QRect(5, 10, 40, 40));
        toolButton_toolPlay->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/chart/iconChartPlay_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/icon/chart/iconChartPlay_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolPlay->setIcon(icon3);
        toolButton_toolPlay->setIconSize(QSize(30, 30));
        toolButton_toolPlay->setAutoRaise(true);
        frame_Header = new QFrame(centralwidget);
        frame_Header->setObjectName(QString::fromUtf8("frame_Header"));
        frame_Header->setGeometry(QRect(-1, 0, 1201, 41));
        frame_Header->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        frame_Header->setFrameShape(QFrame::NoFrame);
        frame_Header->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_Header);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(510, 10, 101, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(9, 87, 147);"));
        checkBox_antiAliasing = new QCheckBox(frame_Header);
        checkBox_antiAliasing->setObjectName(QString::fromUtf8("checkBox_antiAliasing"));
        checkBox_antiAliasing->setGeometry(QRect(1020, 12, 101, 17));
        QFont font1;
        font1.setBold(true);
        checkBox_antiAliasing->setFont(font1);
        checkBox_antiAliasing->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(9, 87, 147);"));
        checkBox_antiAliasing->setChecked(true);
        comboBox_legend = new QComboBox(frame_Header);
        comboBox_legend->setObjectName(QString::fromUtf8("comboBox_legend"));
        comboBox_legend->setGeometry(QRect(860, 8, 141, 25));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        comboBox_legend->setFont(font2);
        comboBox_legend->setLayoutDirection(Qt::LeftToRight);
        comboBox_legend->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-left-radius: 12px;\n"
"border-bottom-left-radius: 12px;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"width: 20;\n"
"}\n"
"QComboBox:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        comboBox_legend->setEditable(true);
        label_3 = new QLabel(frame_Header);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(760, 10, 101, 20));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(9, 87, 147);"));
        comboBox_theme = new QComboBox(frame_Header);
        comboBox_theme->setObjectName(QString::fromUtf8("comboBox_theme"));
        comboBox_theme->setGeometry(QRect(610, 8, 141, 25));
        comboBox_theme->setFont(font2);
        comboBox_theme->setLayoutDirection(Qt::LeftToRight);
        comboBox_theme->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-left-radius: 12px;\n"
"border-bottom-left-radius: 12px;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"width: 20;\n"
"}\n"
"QComboBox:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        comboBox_theme->setEditable(true);
        line = new QFrame(frame_Header);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(490, 6, 3, 30));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(frame_Header);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(50, 6, 3, 30));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        graphicsViewChart = new QGraphicsView(centralwidget);
        graphicsViewChart->setObjectName(QString::fromUtf8("graphicsViewChart"));
        graphicsViewChart->setGeometry(QRect(50, 40, 1151, 491));
        graphicsViewChart->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphicsViewChart->setFrameShape(QFrame::NoFrame);
        graphicsViewChart->setFrameShadow(QFrame::Raised);
        groupBox_setupParameter = new QGroupBox(centralwidget);
        groupBox_setupParameter->setObjectName(QString::fromUtf8("groupBox_setupParameter"));
        groupBox_setupParameter->setGeometry(QRect(10, 550, 831, 251));
        groupBox_setupParameter->setFont(font);
        spinBox_sampleTime = new QSpinBox(groupBox_setupParameter);
        spinBox_sampleTime->setObjectName(QString::fromUtf8("spinBox_sampleTime"));
        spinBox_sampleTime->setGeometry(QRect(430, 40, 101, 31));
        spinBox_sampleTime->setFont(font);
        spinBox_sampleTime->setMinimum(100);
        spinBox_sampleTime->setMaximum(65000);
        label_2 = new QLabel(groupBox_setupParameter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 45, 111, 20));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        label_2->setFont(font3);
        spinBox_sampleNumber = new QSpinBox(groupBox_setupParameter);
        spinBox_sampleNumber->setObjectName(QString::fromUtf8("spinBox_sampleNumber"));
        spinBox_sampleNumber->setGeometry(QRect(430, 75, 101, 31));
        spinBox_sampleNumber->setFont(font);
        spinBox_sampleNumber->setMinimum(10);
        spinBox_sampleNumber->setMaximum(65000);
        spinBox_sampleNumber->setValue(10);
        label_4 = new QLabel(groupBox_setupParameter);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 81, 111, 20));
        label_4->setFont(font3);
        label_6 = new QLabel(groupBox_setupParameter);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(540, 46, 31, 20));
        label_6->setFont(font3);
        label_8 = new QLabel(groupBox_setupParameter);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(300, 20, 81, 16));
        label_8->setFont(font2);
        label_9 = new QLabel(groupBox_setupParameter);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(300, 110, 91, 16));
        label_9->setFont(font2);
        frame = new QFrame(groupBox_setupParameter);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(300, 130, 261, 71));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit_accuracy = new QLineEdit(frame);
        lineEdit_accuracy->setObjectName(QString::fromUtf8("lineEdit_accuracy"));
        lineEdit_accuracy->setGeometry(QRect(110, 40, 81, 31));
        comboBox_accuracySelect = new QComboBox(frame);
        comboBox_accuracySelect->addItem(QString());
        comboBox_accuracySelect->addItem(QString());
        comboBox_accuracySelect->addItem(QString());
        comboBox_accuracySelect->setObjectName(QString::fromUtf8("comboBox_accuracySelect"));
        comboBox_accuracySelect->setGeometry(QRect(0, 0, 261, 31));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setItalic(true);
        comboBox_accuracySelect->setFont(font4);
        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 45, 81, 20));
        label_15->setFont(font3);
        label_accuracyUnit = new QLabel(frame);
        label_accuracyUnit->setObjectName(QString::fromUtf8("label_accuracyUnit"));
        label_accuracyUnit->setGeometry(QRect(200, 45, 61, 20));
        label_accuracyUnit->setFont(font3);
        line_6 = new QFrame(groupBox_setupParameter);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(280, 20, 20, 221));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(groupBox_setupParameter);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(580, 20, 171, 16));
        label_12->setFont(font2);
        frame_2 = new QFrame(groupBox_setupParameter);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(580, 40, 241, 41));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        radioButton_standardSample = new QRadioButton(frame_2);
        radioButton_standardSample->setObjectName(QString::fromUtf8("radioButton_standardSample"));
        radioButton_standardSample->setGeometry(QRect(10, 0, 241, 20));
        radioButton_standardSample->setFont(font3);
        radioButton_standardSample->setChecked(true);
        radioButton_referenceSample = new QRadioButton(frame_2);
        radioButton_referenceSample->setObjectName(QString::fromUtf8("radioButton_referenceSample"));
        radioButton_referenceSample->setGeometry(QRect(10, 20, 201, 20));
        radioButton_referenceSample->setFont(font3);
        line_7 = new QFrame(groupBox_setupParameter);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(560, 20, 20, 221));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        comboBox_calibPointSelect = new QComboBox(groupBox_setupParameter);
        comboBox_calibPointSelect->addItem(QString());
        comboBox_calibPointSelect->addItem(QString());
        comboBox_calibPointSelect->addItem(QString());
        comboBox_calibPointSelect->setObjectName(QString::fromUtf8("comboBox_calibPointSelect"));
        comboBox_calibPointSelect->setGeometry(QRect(10, 90, 271, 31));
        comboBox_calibPointSelect->setFont(font4);
        label_13 = new QLabel(groupBox_setupParameter);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 70, 161, 16));
        label_13->setFont(font2);
        frame_range = new QFrame(groupBox_setupParameter);
        frame_range->setObjectName(QString::fromUtf8("frame_range"));
        frame_range->setEnabled(false);
        frame_range->setGeometry(QRect(300, 200, 261, 51));
        frame_range->setFrameShape(QFrame::StyledPanel);
        frame_range->setFrameShadow(QFrame::Raised);
        spinBox_rangeMax = new QSpinBox(frame_range);
        spinBox_rangeMax->setObjectName(QString::fromUtf8("spinBox_rangeMax"));
        spinBox_rangeMax->setGeometry(QRect(190, 10, 71, 31));
        spinBox_rangeMax->setFont(font);
        spinBox_rangeMax->setMinimum(-99999999);
        spinBox_rangeMax->setMaximum(99999999);
        spinBox_rangeMax->setValue(1);
        label_10 = new QLabel(frame_range);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 19, 61, 20));
        label_10->setFont(font3);
        spinBox_rangeMin = new QSpinBox(frame_range);
        spinBox_rangeMin->setObjectName(QString::fromUtf8("spinBox_rangeMin"));
        spinBox_rangeMin->setGeometry(QRect(80, 10, 71, 31));
        spinBox_rangeMin->setFont(font);
        spinBox_rangeMin->setMinimum(-99999999);
        spinBox_rangeMin->setMaximum(99999999);
        spinBox_rangeMin->setValue(0);
        label_11 = new QLabel(frame_range);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(158, 16, 31, 20));
        label_11->setFont(font3);
        pushButton_addDeviceRef = new QPushButton(groupBox_setupParameter);
        pushButton_addDeviceRef->setObjectName(QString::fromUtf8("pushButton_addDeviceRef"));
        pushButton_addDeviceRef->setEnabled(false);
        pushButton_addDeviceRef->setGeometry(QRect(630, 80, 191, 31));
        lineEdit_standardValue = new QLineEdit(groupBox_setupParameter);
        lineEdit_standardValue->setObjectName(QString::fromUtf8("lineEdit_standardValue"));
        lineEdit_standardValue->setGeometry(QRect(670, 115, 81, 31));
        label_14 = new QLabel(groupBox_setupParameter);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(590, 120, 81, 20));
        label_14->setFont(font3);
        label_standartValueUnit = new QLabel(groupBox_setupParameter);
        label_standartValueUnit->setObjectName(QString::fromUtf8("label_standartValueUnit"));
        label_standartValueUnit->setGeometry(QRect(760, 120, 61, 20));
        label_standartValueUnit->setFont(font3);
        label_22 = new QLabel(groupBox_setupParameter);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(580, 160, 171, 16));
        label_22->setFont(font2);
        comboBox_evaluateSelect = new QComboBox(groupBox_setupParameter);
        comboBox_evaluateSelect->addItem(QString());
        comboBox_evaluateSelect->addItem(QString());
        comboBox_evaluateSelect->setObjectName(QString::fromUtf8("comboBox_evaluateSelect"));
        comboBox_evaluateSelect->setGeometry(QRect(590, 180, 231, 31));
        comboBox_evaluateSelect->setFont(font4);
        label_7 = new QLabel(groupBox_setupParameter);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(250, 31, 41, 20));
        label_7->setFont(font3);
        label_5 = new QLabel(groupBox_setupParameter);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 30, 141, 20));
        label_5->setFont(font2);
        spinBox_calibTime = new QSpinBox(groupBox_setupParameter);
        spinBox_calibTime->setObjectName(QString::fromUtf8("spinBox_calibTime"));
        spinBox_calibTime->setGeometry(QRect(150, 26, 91, 31));
        spinBox_calibTime->setFont(font);
        spinBox_calibTime->setMinimum(1);
        spinBox_calibTime->setMaximum(65000);
        spinBox_calibTime->setValue(10);
        label_23 = new QLabel(groupBox_setupParameter);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(20, 200, 61, 20));
        label_23->setFont(font2);
        label_24 = new QLabel(groupBox_setupParameter);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 139, 61, 20));
        label_24->setFont(font2);
        label_calibCAL02 = new QLabel(groupBox_setupParameter);
        label_calibCAL02->setObjectName(QString::fromUtf8("label_calibCAL02"));
        label_calibCAL02->setGeometry(QRect(90, 170, 111, 20));
        label_calibCAL02->setFont(font);
        label_calibCAL02->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        label_calibCAL01 = new QLabel(groupBox_setupParameter);
        label_calibCAL01->setObjectName(QString::fromUtf8("label_calibCAL01"));
        label_calibCAL01->setGeometry(QRect(90, 139, 111, 20));
        label_calibCAL01->setFont(font);
        label_calibCAL01->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        label_calibCAL03 = new QLabel(groupBox_setupParameter);
        label_calibCAL03->setObjectName(QString::fromUtf8("label_calibCAL03"));
        label_calibCAL03->setGeometry(QRect(90, 200, 111, 20));
        label_calibCAL03->setFont(font);
        label_calibCAL03->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        label_25 = new QLabel(groupBox_setupParameter);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(20, 170, 61, 20));
        label_25->setFont(font2);
        pushButton_clearCalibOne = new QPushButton(groupBox_setupParameter);
        pushButton_clearCalibOne->setObjectName(QString::fromUtf8("pushButton_clearCalibOne"));
        pushButton_clearCalibOne->setGeometry(QRect(210, 137, 71, 24));
        pushButton_clearCalibOne->setFont(font3);
        pushButton_clearCalibTwo = new QPushButton(groupBox_setupParameter);
        pushButton_clearCalibTwo->setObjectName(QString::fromUtf8("pushButton_clearCalibTwo"));
        pushButton_clearCalibTwo->setGeometry(QRect(210, 168, 71, 24));
        pushButton_clearCalibTwo->setFont(font3);
        pushButton_clearCalibThree = new QPushButton(groupBox_setupParameter);
        pushButton_clearCalibThree->setObjectName(QString::fromUtf8("pushButton_clearCalibThree"));
        pushButton_clearCalibThree->setGeometry(QRect(210, 198, 71, 24));
        pushButton_clearCalibThree->setFont(font3);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 540, 2000, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        groupBox_setupParameter_2 = new QGroupBox(centralwidget);
        groupBox_setupParameter_2->setObjectName(QString::fromUtf8("groupBox_setupParameter_2"));
        groupBox_setupParameter_2->setGeometry(QRect(850, 550, 341, 251));
        groupBox_setupParameter_2->setFont(font);
        lcdNumber_Value = new QLCDNumber(groupBox_setupParameter_2);
        lcdNumber_Value->setObjectName(QString::fromUtf8("lcdNumber_Value"));
        lcdNumber_Value->setGeometry(QRect(20, 140, 151, 31));
        lcdNumber_Value->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(255, 0,0);"));
        lcdNumber_Value->setFrameShape(QFrame::WinPanel);
        lcdNumber_Value->setLineWidth(1);
        lcdNumber_Value->setSmallDecimalPoint(false);
        lcdNumber_Value->setDigitCount(8);
        lcdNumber_Value->setMode(QLCDNumber::Dec);
        lcdNumber_Value->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Value->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_Value->setProperty("intValue", QVariant(0));
        label_16 = new QLabel(groupBox_setupParameter_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 201, 71, 20));
        label_16->setFont(font3);
        line_8 = new QFrame(groupBox_setupParameter_2);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(20, 100, 311, 16));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        label_17 = new QLabel(groupBox_setupParameter_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 222, 91, 20));
        label_17->setFont(font3);
        label_ratio = new QLabel(groupBox_setupParameter_2);
        label_ratio->setObjectName(QString::fromUtf8("label_ratio"));
        label_ratio->setGeometry(QRect(120, 200, 141, 20));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        label_ratio->setFont(font5);
        label_error = new QLabel(groupBox_setupParameter_2);
        label_error->setObjectName(QString::fromUtf8("label_error"));
        label_error->setGeometry(QRect(120, 220, 141, 20));
        label_error->setFont(font5);
        lcdNumber_ValueCalib = new QLCDNumber(groupBox_setupParameter_2);
        lcdNumber_ValueCalib->setObjectName(QString::fromUtf8("lcdNumber_ValueCalib"));
        lcdNumber_ValueCalib->setGeometry(QRect(180, 140, 151, 31));
        lcdNumber_ValueCalib->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 85, 255);"));
        lcdNumber_ValueCalib->setFrameShape(QFrame::WinPanel);
        lcdNumber_ValueCalib->setLineWidth(1);
        lcdNumber_ValueCalib->setSmallDecimalPoint(false);
        lcdNumber_ValueCalib->setDigitCount(8);
        lcdNumber_ValueCalib->setMode(QLCDNumber::Dec);
        lcdNumber_ValueCalib->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_ValueCalib->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_ValueCalib->setProperty("intValue", QVariant(0));
        label_18 = new QLabel(groupBox_setupParameter_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 120, 61, 16));
        label_18->setFont(font4);
        label_19 = new QLabel(groupBox_setupParameter_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(180, 120, 91, 16));
        label_19->setFont(font4);
        label_sampleNum = new QLabel(groupBox_setupParameter_2);
        label_sampleNum->setObjectName(QString::fromUtf8("label_sampleNum"));
        label_sampleNum->setGeometry(QRect(120, 179, 141, 20));
        label_sampleNum->setFont(font5);
        label_sampleNum->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_21 = new QLabel(groupBox_setupParameter_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 180, 71, 20));
        label_21->setFont(font3);
        label_20 = new QLabel(groupBox_setupParameter_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 70, 61, 16));
        label_20->setFont(font4);
        comboBox_unit = new QComboBox(groupBox_setupParameter_2);
        comboBox_unit->addItem(QString());
        comboBox_unit->addItem(QString());
        comboBox_unit->setObjectName(QString::fromUtf8("comboBox_unit"));
        comboBox_unit->setGeometry(QRect(100, 61, 221, 32));
        comboBox_unit->setFont(font2);
        comboBox_unit->setLayoutDirection(Qt::LeftToRight);
        comboBox_unit->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
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
        lcdNumber_Reference = new QLCDNumber(groupBox_setupParameter_2);
        lcdNumber_Reference->setObjectName(QString::fromUtf8("lcdNumber_Reference"));
        lcdNumber_Reference->setGeometry(QRect(170, 20, 151, 31));
        lcdNumber_Reference->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 170, 0);"));
        lcdNumber_Reference->setFrameShape(QFrame::WinPanel);
        lcdNumber_Reference->setLineWidth(1);
        lcdNumber_Reference->setSmallDecimalPoint(false);
        lcdNumber_Reference->setDigitCount(8);
        lcdNumber_Reference->setMode(QLCDNumber::Dec);
        lcdNumber_Reference->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Reference->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_Reference->setProperty("intValue", QVariant(0));
        label_26 = new QLabel(groupBox_setupParameter_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(20, 26, 151, 20));
        label_26->setFont(font4);
        FrmDeviceCalibration->setCentralWidget(centralwidget);
        QWidget::setTabOrder(comboBox_theme, comboBox_legend);
        QWidget::setTabOrder(comboBox_legend, checkBox_antiAliasing);
        QWidget::setTabOrder(checkBox_antiAliasing, toolButton_toolCrosshair);
        QWidget::setTabOrder(toolButton_toolCrosshair, toolButton_toolCallout);
        QWidget::setTabOrder(toolButton_toolCallout, toolButton_toolPlay);
        QWidget::setTabOrder(toolButton_toolPlay, toolButton_toolPause);
        QWidget::setTabOrder(toolButton_toolPause, graphicsViewChart);
        QWidget::setTabOrder(graphicsViewChart, spinBox_calibTime);
        QWidget::setTabOrder(spinBox_calibTime, comboBox_calibPointSelect);
        QWidget::setTabOrder(comboBox_calibPointSelect, pushButton_clearCalibOne);
        QWidget::setTabOrder(pushButton_clearCalibOne, pushButton_clearCalibTwo);
        QWidget::setTabOrder(pushButton_clearCalibTwo, pushButton_clearCalibThree);
        QWidget::setTabOrder(pushButton_clearCalibThree, spinBox_sampleTime);
        QWidget::setTabOrder(spinBox_sampleTime, spinBox_sampleNumber);
        QWidget::setTabOrder(spinBox_sampleNumber, comboBox_accuracySelect);
        QWidget::setTabOrder(comboBox_accuracySelect, lineEdit_accuracy);
        QWidget::setTabOrder(lineEdit_accuracy, spinBox_rangeMin);
        QWidget::setTabOrder(spinBox_rangeMin, spinBox_rangeMax);
        QWidget::setTabOrder(spinBox_rangeMax, radioButton_standardSample);
        QWidget::setTabOrder(radioButton_standardSample, radioButton_referenceSample);
        QWidget::setTabOrder(radioButton_referenceSample, pushButton_addDeviceRef);
        QWidget::setTabOrder(pushButton_addDeviceRef, lineEdit_standardValue);
        QWidget::setTabOrder(lineEdit_standardValue, comboBox_evaluateSelect);
        QWidget::setTabOrder(comboBox_evaluateSelect, comboBox_unit);

        retranslateUi(FrmDeviceCalibration);

        QMetaObject::connectSlotsByName(FrmDeviceCalibration);
    } // setupUi

    void retranslateUi(QMainWindow *FrmDeviceCalibration)
    {
        FrmDeviceCalibration->setWindowTitle(QCoreApplication::translate("FrmDeviceCalibration", "MainWindow", nullptr));
        toolButton_toolCrosshair->setText(QCoreApplication::translate("FrmDeviceCalibration", "...", nullptr));
        toolButton_toolCallout->setText(QCoreApplication::translate("FrmDeviceCalibration", "...", nullptr));
        toolButton_toolPause->setText(QCoreApplication::translate("FrmDeviceCalibration", "...", nullptr));
        toolButton_toolPlay->setText(QCoreApplication::translate("FrmDeviceCalibration", "...", nullptr));
        label->setText(QCoreApplication::translate("FrmDeviceCalibration", "B\341\273\221i c\341\272\243nh \304\221\341\273\223 th\341\273\213", nullptr));
        checkBox_antiAliasing->setText(QCoreApplication::translate("FrmDeviceCalibration", "Kh\341\273\255 r\304\203ng c\306\260a", nullptr));
        label_3->setText(QCoreApplication::translate("FrmDeviceCalibration", "\304\220\306\260\341\273\235ng ghi ch\303\272", nullptr));
        groupBox_setupParameter->setTitle(QCoreApplication::translate("FrmDeviceCalibration", "C\303\240i \304\221\341\272\267t tham s\341\273\221 hi\341\273\207u chu\341\272\251n", nullptr));
        label_2->setText(QCoreApplication::translate("FrmDeviceCalibration", "Th\341\273\235i gian l\341\272\245y m\341\272\253u:", nullptr));
        label_4->setText(QCoreApplication::translate("FrmDeviceCalibration", "S\341\273\221 l\306\260\341\273\243ng m\341\272\253u \304\221o:", nullptr));
        label_6->setText(QCoreApplication::translate("FrmDeviceCalibration", "(ms)", nullptr));
        label_8->setText(QCoreApplication::translate("FrmDeviceCalibration", "L\341\272\245y m\341\272\253u \304\221o", nullptr));
        label_9->setText(QCoreApplication::translate("FrmDeviceCalibration", "\304\220\341\273\231 ch\303\255nh x\303\241c", nullptr));
        lineEdit_accuracy->setText(QCoreApplication::translate("FrmDeviceCalibration", "1", nullptr));
        comboBox_accuracySelect->setItemText(0, QCoreApplication::translate("FrmDeviceCalibration", "Theo gi\303\241 tr\341\273\213 \304\221o", nullptr));
        comboBox_accuracySelect->setItemText(1, QCoreApplication::translate("FrmDeviceCalibration", "Theo ph\341\272\247n tr\304\203m (%RD - reading)", nullptr));
        comboBox_accuracySelect->setItemText(2, QCoreApplication::translate("FrmDeviceCalibration", "Theo to\303\240n thang \304\221o (%FS - fullscale)", nullptr));

        label_15->setText(QCoreApplication::translate("FrmDeviceCalibration", "\304\220\341\273\231 ch\303\255nh x\303\241c:", nullptr));
        label_accuracyUnit->setText(QCoreApplication::translate("FrmDeviceCalibration", "(unit)", nullptr));
        label_12->setText(QCoreApplication::translate("FrmDeviceCalibration", "Ph\306\260\306\241ng ph\303\241p hi\341\273\207u chu\341\272\251n", nullptr));
        radioButton_standardSample->setText(QCoreApplication::translate("FrmDeviceCalibration", "Hi\341\273\207u chu\341\272\251n theo m\341\272\253u (ngu\341\273\223n) chu\341\272\251n", nullptr));
        radioButton_referenceSample->setText(QCoreApplication::translate("FrmDeviceCalibration", "Hi\341\273\207u chu\341\272\251n theo tham chi\341\272\277u", nullptr));
        comboBox_calibPointSelect->setItemText(0, QCoreApplication::translate("FrmDeviceCalibration", "Hi\341\273\207u chu\341\272\251n \304\221i\341\273\203m \304\221\341\272\247u ti\303\252n (CAL01)", nullptr));
        comboBox_calibPointSelect->setItemText(1, QCoreApplication::translate("FrmDeviceCalibration", "Hi\341\273\207u chu\341\272\251n \304\221i\341\273\203m th\341\273\251 hai (CAL02)", nullptr));
        comboBox_calibPointSelect->setItemText(2, QCoreApplication::translate("FrmDeviceCalibration", "Hi\341\273\207u xu\341\272\251n \304\221i\341\273\203m th\341\273\251 ba (CAL03)", nullptr));

        label_13->setText(QCoreApplication::translate("FrmDeviceCalibration", "\304\220i\341\273\203m hi\341\273\207u chu\341\272\251n", nullptr));
        label_10->setText(QCoreApplication::translate("FrmDeviceCalibration", "D\341\272\243i \304\221o t\341\273\253", nullptr));
        label_11->setText(QCoreApplication::translate("FrmDeviceCalibration", "\304\221\341\272\277n", nullptr));
        pushButton_addDeviceRef->setText(QCoreApplication::translate("FrmDeviceCalibration", "Th\303\252m thi\341\272\277t b\341\273\213 tham chi\341\272\277u", nullptr));
        lineEdit_standardValue->setText(QCoreApplication::translate("FrmDeviceCalibration", "1", nullptr));
        label_14->setText(QCoreApplication::translate("FrmDeviceCalibration", "Gi\303\241 tr\341\273\213 chu\341\272\251n:", nullptr));
        label_standartValueUnit->setText(QCoreApplication::translate("FrmDeviceCalibration", "(unit)", nullptr));
        label_22->setText(QCoreApplication::translate("FrmDeviceCalibration", "Ph\306\260\306\241ng ph\303\241p \304\221\303\241nh gi\303\241", nullptr));
        comboBox_evaluateSelect->setItemText(0, QCoreApplication::translate("FrmDeviceCalibration", "Theo \304\221\341\273\231 ch\303\255nh x\303\241c", nullptr));
        comboBox_evaluateSelect->setItemText(1, QCoreApplication::translate("FrmDeviceCalibration", "Theo \304\221\341\273\231 l\341\273\207ch chu\341\272\251n", nullptr));

        label_7->setText(QCoreApplication::translate("FrmDeviceCalibration", "(gi\303\242y)", nullptr));
        label_5->setText(QCoreApplication::translate("FrmDeviceCalibration", "Th\341\273\235i gian hi\341\273\207u chu\341\272\251n", nullptr));
        label_23->setText(QCoreApplication::translate("FrmDeviceCalibration", "CAL - 03:", nullptr));
        label_24->setText(QCoreApplication::translate("FrmDeviceCalibration", "CAL - 01:", nullptr));
        label_calibCAL02->setText(QCoreApplication::translate("FrmDeviceCalibration", "0", nullptr));
        label_calibCAL01->setText(QCoreApplication::translate("FrmDeviceCalibration", "0", nullptr));
        label_calibCAL03->setText(QCoreApplication::translate("FrmDeviceCalibration", "0", nullptr));
        label_25->setText(QCoreApplication::translate("FrmDeviceCalibration", "CAL - 02:", nullptr));
        pushButton_clearCalibOne->setText(QCoreApplication::translate("FrmDeviceCalibration", "X\303\263a", nullptr));
        pushButton_clearCalibTwo->setText(QCoreApplication::translate("FrmDeviceCalibration", "X\303\263a", nullptr));
        pushButton_clearCalibThree->setText(QCoreApplication::translate("FrmDeviceCalibration", "X\303\263a", nullptr));
        groupBox_setupParameter_2->setTitle(QCoreApplication::translate("FrmDeviceCalibration", "Tham s\341\273\221 \304\221\303\241nh gi\303\241", nullptr));
        label_16->setText(QCoreApplication::translate("FrmDeviceCalibration", "Sai s\341\273\221 t\341\273\267 l\341\273\207:", nullptr));
        label_17->setText(QCoreApplication::translate("FrmDeviceCalibration", "\304\220\341\273\231 l\341\273\207ch chu\341\272\251n:", nullptr));
        label_ratio->setText(QCoreApplication::translate("FrmDeviceCalibration", "0", nullptr));
        label_error->setText(QCoreApplication::translate("FrmDeviceCalibration", "0", nullptr));
        label_18->setText(QCoreApplication::translate("FrmDeviceCalibration", "M\341\272\253u \304\221o", nullptr));
        label_19->setText(QCoreApplication::translate("FrmDeviceCalibration", "\304\220\303\243 hi\341\273\207u chu\341\272\251n", nullptr));
        label_sampleNum->setText(QCoreApplication::translate("FrmDeviceCalibration", "0", nullptr));
        label_21->setText(QCoreApplication::translate("FrmDeviceCalibration", "S\341\273\221 m\341\272\253u \304\221o:", nullptr));
        label_20->setText(QCoreApplication::translate("FrmDeviceCalibration", "\304\220\306\241n v\341\273\213 \304\221o:", nullptr));
        comboBox_unit->setItemText(0, QCoreApplication::translate("FrmDeviceCalibration", "\304\220\341\273\231 \341\272\251m t\306\260\306\241ng \304\221\341\273\221i (%RH)", nullptr));
        comboBox_unit->setItemText(1, QCoreApplication::translate("FrmDeviceCalibration", "\304\220\341\273\231 \341\272\251m tuy\341\273\207t \304\221\341\273\221i (g/m3)", nullptr));

        label_26->setText(QCoreApplication::translate("FrmDeviceCalibration", "Gi\303\241 tr\341\273\213 tham chi\341\272\277u chu\341\272\251n:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmDeviceCalibration: public Ui_FrmDeviceCalibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDEVICECALIBRATION_H
