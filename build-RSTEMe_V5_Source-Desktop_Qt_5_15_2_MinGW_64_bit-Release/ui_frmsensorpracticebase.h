/********************************************************************************
** Form generated from reading UI file 'frmsensorpracticebase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSENSORPRACTICEBASE_H
#define UI_FRMSENSORPRACTICEBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmSensorPracticeBase
{
public:
    QWidget *centralwidget;
    QFrame *frame_toolTrack;
    QToolButton *toolButton_toolCrosshair;
    QToolButton *toolButton_toolCallout;
    QLabel *label_6;
    QToolButton *toolButton_toolHideSeries;
    QFrame *frame_toolHeader;
    QToolButton *toolButton_openFile;
    QToolButton *toolButton_saveFile;
    QToolButton *toolButton_exportFile;
    QFrame *frame_toolData;
    QToolButton *toolButton_toolTable;
    QLabel *label_9;
    QToolButton *toolButton_toolLogarit;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_7;
    QToolButton *toolButton_toolSingleY;
    QToolButton *toolButton_toolLineDot;
    QToolButton *toolButton_toolMultiY;
    QToolButton *toolButton_toolLine;
    QFrame *frame_toolSetup;
    QComboBox *comboBox_sampleTime;
    QLineEdit *lineEdit_playTime;
    QLabel *label;
    QLabel *label_timePlay;
    QFrame *line;
    QFrame *line_3;
    QLabel *label_3;
    QLabel *label_2;
    QComboBox *comboBox_sampleType;
    QToolButton *toolButton_toolSampleTime;
    QToolButton *toolButton_toolSampleTime_2;
    QToolButton *toolButton_toolSampleTime_3;
    QFrame *frame_toolDevice;
    QToolButton *toolButton_menuSelect;
    QFrame *frame_play;
    QToolButton *toolButton_toolPause;
    QToolButton *toolButton_toolPlay;
    QToolButton *toolButton_toolClear;
    QFrame *line_4;
    QToolButton *toolButton_toolManual;
    QTableWidget *tableWidget_DataTable;
    QGraphicsView *graphicsViewChart;
    QTableWidget *tableWidget_dataEvaluate;

    void setupUi(QMainWindow *FrmSensorPracticeBase)
    {
        if (FrmSensorPracticeBase->objectName().isEmpty())
            FrmSensorPracticeBase->setObjectName(QString::fromUtf8("FrmSensorPracticeBase"));
        FrmSensorPracticeBase->resize(1200, 800);
        FrmSensorPracticeBase->setMinimumSize(QSize(1200, 800));
        FrmSensorPracticeBase->setStyleSheet(QString::fromUtf8("QMainWindow#FrmSensorPracticeBase{\n"
"}"));
        centralwidget = new QWidget(FrmSensorPracticeBase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame_toolTrack = new QFrame(centralwidget);
        frame_toolTrack->setObjectName(QString::fromUtf8("frame_toolTrack"));
        frame_toolTrack->setGeometry(QRect(-1, 39, 51, 631));
        frame_toolTrack->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        frame_toolTrack->setFrameShape(QFrame::NoFrame);
        frame_toolTrack->setFrameShadow(QFrame::Raised);
        toolButton_toolCrosshair = new QToolButton(frame_toolTrack);
        toolButton_toolCrosshair->setObjectName(QString::fromUtf8("toolButton_toolCrosshair"));
        toolButton_toolCrosshair->setGeometry(QRect(5, 30, 40, 40));
        toolButton_toolCrosshair->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
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
        toolButton_toolCallout->setGeometry(QRect(5, 80, 40, 40));
        toolButton_toolCallout->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/chart/iconChartCallout_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icon/chart/iconChartCallout_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolCallout->setIcon(icon1);
        toolButton_toolCallout->setIconSize(QSize(30, 30));
        toolButton_toolCallout->setAutoRaise(true);
        label_6 = new QLabel(frame_toolTrack);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1, 0, 50, 20));
        QFont font;
        font.setBold(true);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 149, 173);"));
        label_6->setFrameShape(QFrame::Panel);
        label_6->setFrameShadow(QFrame::Raised);
        label_6->setAlignment(Qt::AlignCenter);
        toolButton_toolHideSeries = new QToolButton(frame_toolTrack);
        toolButton_toolHideSeries->setObjectName(QString::fromUtf8("toolButton_toolHideSeries"));
        toolButton_toolHideSeries->setGeometry(QRect(5, 130, 40, 40));
        toolButton_toolHideSeries->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/chart/iconSeriesCheck_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/icon/chart/iconSeriesCheck_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolHideSeries->setIcon(icon2);
        toolButton_toolHideSeries->setIconSize(QSize(30, 30));
        toolButton_toolHideSeries->setAutoRaise(true);
        frame_toolHeader = new QFrame(centralwidget);
        frame_toolHeader->setObjectName(QString::fromUtf8("frame_toolHeader"));
        frame_toolHeader->setGeometry(QRect(0, 0, 1201, 41));
        frame_toolHeader->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        frame_toolHeader->setFrameShape(QFrame::NoFrame);
        frame_toolHeader->setFrameShadow(QFrame::Raised);
        toolButton_openFile = new QToolButton(frame_toolHeader);
        toolButton_openFile->setObjectName(QString::fromUtf8("toolButton_openFile"));
        toolButton_openFile->setGeometry(QRect(10, 5, 30, 30));
        toolButton_openFile->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 5px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/chart/iconOpenFile_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/icon/chart/iconOpenFile_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_openFile->setIcon(icon3);
        toolButton_openFile->setIconSize(QSize(25, 25));
        toolButton_openFile->setAutoRaise(true);
        toolButton_saveFile = new QToolButton(frame_toolHeader);
        toolButton_saveFile->setObjectName(QString::fromUtf8("toolButton_saveFile"));
        toolButton_saveFile->setGeometry(QRect(50, 5, 30, 30));
        toolButton_saveFile->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 5px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/chart/iconSaveFile_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/icon/chart/iconSaveFile_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_saveFile->setIcon(icon4);
        toolButton_saveFile->setIconSize(QSize(25, 25));
        toolButton_saveFile->setAutoRaise(true);
        toolButton_exportFile = new QToolButton(frame_toolHeader);
        toolButton_exportFile->setObjectName(QString::fromUtf8("toolButton_exportFile"));
        toolButton_exportFile->setGeometry(QRect(90, 5, 30, 30));
        toolButton_exportFile->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 5px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/chart/iconExportFile_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/icon/chart/iconExportFile_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_exportFile->setIcon(icon5);
        toolButton_exportFile->setIconSize(QSize(25, 25));
        toolButton_exportFile->setAutoRaise(true);
        frame_toolData = new QFrame(centralwidget);
        frame_toolData->setObjectName(QString::fromUtf8("frame_toolData"));
        frame_toolData->setGeometry(QRect(1150, 40, 51, 631));
        frame_toolData->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        frame_toolData->setFrameShape(QFrame::NoFrame);
        frame_toolData->setFrameShadow(QFrame::Raised);
        toolButton_toolTable = new QToolButton(frame_toolData);
        toolButton_toolTable->setObjectName(QString::fromUtf8("toolButton_toolTable"));
        toolButton_toolTable->setGeometry(QRect(5, 30, 40, 40));
        toolButton_toolTable->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/chart/iconChartTable_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/icon/chart/iconChartTable_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/icon/chart/iconChartTable_On.jpg"), QSize(), QIcon::Active, QIcon::On);
        toolButton_toolTable->setIcon(icon6);
        toolButton_toolTable->setIconSize(QSize(30, 30));
        toolButton_toolTable->setAutoRaise(true);
        label_9 = new QLabel(frame_toolData);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 0, 50, 20));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 149, 173);"));
        label_9->setFrameShape(QFrame::Panel);
        label_9->setFrameShadow(QFrame::Raised);
        label_9->setAlignment(Qt::AlignCenter);
        toolButton_toolLogarit = new QToolButton(frame_toolData);
        toolButton_toolLogarit->setObjectName(QString::fromUtf8("toolButton_toolLogarit"));
        toolButton_toolLogarit->setGeometry(QRect(4, 490, 40, 40));
        toolButton_toolLogarit->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/chart/iconChartLogarit_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/icon/chart/iconChartLogarit_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolLogarit->setIcon(icon7);
        toolButton_toolLogarit->setIconSize(QSize(30, 30));
        toolButton_toolLogarit->setAutoRaise(true);
        label_8 = new QLabel(frame_toolData);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 460, 50, 20));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 149, 173);"));
        label_8->setFrameShape(QFrame::Panel);
        label_8->setFrameShadow(QFrame::Raised);
        label_8->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(frame_toolData);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 120, 50, 20));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 149, 173);"));
        label_5->setFrameShape(QFrame::Panel);
        label_5->setFrameShadow(QFrame::Raised);
        label_5->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(frame_toolData);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 290, 50, 20));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 149, 173);"));
        label_7->setFrameShape(QFrame::Panel);
        label_7->setFrameShadow(QFrame::Raised);
        label_7->setAlignment(Qt::AlignCenter);
        toolButton_toolSingleY = new QToolButton(frame_toolData);
        toolButton_toolSingleY->setObjectName(QString::fromUtf8("toolButton_toolSingleY"));
        toolButton_toolSingleY->setGeometry(QRect(4, 370, 40, 40));
        toolButton_toolSingleY->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/chart/iconChartSingleY_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/icon/chart/iconChartSingleY_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolSingleY->setIcon(icon8);
        toolButton_toolSingleY->setIconSize(QSize(30, 30));
        toolButton_toolSingleY->setAutoRaise(true);
        toolButton_toolLineDot = new QToolButton(frame_toolData);
        toolButton_toolLineDot->setObjectName(QString::fromUtf8("toolButton_toolLineDot"));
        toolButton_toolLineDot->setGeometry(QRect(4, 150, 40, 40));
        toolButton_toolLineDot->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/chart/iconChartDot_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/icon/chart/iconChartDot_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolLineDot->setIcon(icon9);
        toolButton_toolLineDot->setIconSize(QSize(30, 30));
        toolButton_toolLineDot->setAutoRaise(true);
        toolButton_toolMultiY = new QToolButton(frame_toolData);
        toolButton_toolMultiY->setObjectName(QString::fromUtf8("toolButton_toolMultiY"));
        toolButton_toolMultiY->setGeometry(QRect(4, 320, 40, 40));
        toolButton_toolMultiY->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/chart/iconChartMultiY_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon10.addFile(QString::fromUtf8(":/icon/chart/iconChartMultiY_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolMultiY->setIcon(icon10);
        toolButton_toolMultiY->setIconSize(QSize(30, 30));
        toolButton_toolMultiY->setAutoRaise(true);
        toolButton_toolLine = new QToolButton(frame_toolData);
        toolButton_toolLine->setObjectName(QString::fromUtf8("toolButton_toolLine"));
        toolButton_toolLine->setGeometry(QRect(4, 200, 40, 40));
        toolButton_toolLine->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icon/chart/iconChartSpline_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QString::fromUtf8(":/icon/chart/iconChartSpline_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolLine->setIcon(icon11);
        toolButton_toolLine->setIconSize(QSize(30, 30));
        toolButton_toolLine->setAutoRaise(true);
        frame_toolSetup = new QFrame(centralwidget);
        frame_toolSetup->setObjectName(QString::fromUtf8("frame_toolSetup"));
        frame_toolSetup->setGeometry(QRect(0, 670, 1201, 41));
        frame_toolSetup->setStyleSheet(QString::fromUtf8("QFrame#frame_toolSetup{\n"
"	background-color: rgb(25, 149, 173);\n"
"    /*background-color: rgb(3, 87, 123);;*/\n"
"}"));
        frame_toolSetup->setFrameShape(QFrame::Panel);
        frame_toolSetup->setFrameShadow(QFrame::Raised);
        comboBox_sampleTime = new QComboBox(frame_toolSetup);
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->addItem(QString());
        comboBox_sampleTime->setObjectName(QString::fromUtf8("comboBox_sampleTime"));
        comboBox_sampleTime->setGeometry(QRect(140, 5, 121, 30));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        comboBox_sampleTime->setFont(font1);
        comboBox_sampleTime->setLayoutDirection(Qt::LeftToRight);
        comboBox_sampleTime->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: rgb(3, 87, 123);\n"
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
"background-color: rgb(0, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        comboBox_sampleTime->setInputMethodHints(Qt::ImhHiddenText);
        comboBox_sampleTime->setEditable(true);
        lineEdit_playTime = new QLineEdit(frame_toolSetup);
        lineEdit_playTime->setObjectName(QString::fromUtf8("lineEdit_playTime"));
        lineEdit_playTime->setGeometry(QRect(1010, 5, 141, 30));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        lineEdit_playTime->setFont(font2);
        lineEdit_playTime->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	color: rgb(3, 87, 123);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 15px;\n"
"}"));
        lineEdit_playTime->setMaxLength(10);
        lineEdit_playTime->setAlignment(Qt::AlignCenter);
        label = new QLabel(frame_toolSetup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(38, 9, 101, 20));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_timePlay = new QLabel(frame_toolSetup);
        label_timePlay->setObjectName(QString::fromUtf8("label_timePlay"));
        label_timePlay->setGeometry(QRect(880, 10, 121, 20));
        label_timePlay->setFont(font);
        label_timePlay->setLayoutDirection(Qt::RightToLeft);
        label_timePlay->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_timePlay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line = new QFrame(frame_toolSetup);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(850, 0, 3, 41));
        line->setStyleSheet(QString::fromUtf8(""));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(frame_toolSetup);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(270, 0, 3, 41));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(frame_toolSetup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1160, 11, 31, 16));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(frame_toolSetup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 9, 71, 20));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        comboBox_sampleType = new QComboBox(frame_toolSetup);
        comboBox_sampleType->addItem(QString());
        comboBox_sampleType->addItem(QString());
        comboBox_sampleType->setObjectName(QString::fromUtf8("comboBox_sampleType"));
        comboBox_sampleType->setGeometry(QRect(390, 5, 201, 30));
        comboBox_sampleType->setFont(font1);
        comboBox_sampleType->setLayoutDirection(Qt::LeftToRight);
        comboBox_sampleType->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: rgb(3, 87, 123);\n"
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
"background-color: rgb(0, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        comboBox_sampleType->setInputMethodHints(Qt::ImhHiddenText);
        comboBox_sampleType->setEditable(true);
        toolButton_toolSampleTime = new QToolButton(frame_toolSetup);
        toolButton_toolSampleTime->setObjectName(QString::fromUtf8("toolButton_toolSampleTime"));
        toolButton_toolSampleTime->setGeometry(QRect(4, 5, 30, 30));
        toolButton_toolSampleTime->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 5px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icon/chart/iconChartClock_On.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_toolSampleTime->setIcon(icon12);
        toolButton_toolSampleTime->setIconSize(QSize(30, 30));
        toolButton_toolSampleTime->setAutoRaise(true);
        toolButton_toolSampleTime_2 = new QToolButton(frame_toolSetup);
        toolButton_toolSampleTime_2->setObjectName(QString::fromUtf8("toolButton_toolSampleTime_2"));
        toolButton_toolSampleTime_2->setGeometry(QRect(278, 5, 30, 30));
        toolButton_toolSampleTime_2->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 5px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icon/chart/iconChartManual_On.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_toolSampleTime_2->setIcon(icon13);
        toolButton_toolSampleTime_2->setIconSize(QSize(30, 30));
        toolButton_toolSampleTime_2->setAutoRaise(true);
        toolButton_toolSampleTime_3 = new QToolButton(frame_toolSetup);
        toolButton_toolSampleTime_3->setObjectName(QString::fromUtf8("toolButton_toolSampleTime_3"));
        toolButton_toolSampleTime_3->setGeometry(QRect(860, 5, 30, 30));
        toolButton_toolSampleTime_3->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(210, 210, 210);\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 5px;\n"
"}\n"
"QToolButton:hover{\n"
"border-width: 0px;\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icon/chart/iconPracticeTime_On.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_toolSampleTime_3->setIcon(icon14);
        toolButton_toolSampleTime_3->setIconSize(QSize(30, 30));
        toolButton_toolSampleTime_3->setAutoRaise(true);
        frame_toolDevice = new QFrame(centralwidget);
        frame_toolDevice->setObjectName(QString::fromUtf8("frame_toolDevice"));
        frame_toolDevice->setGeometry(QRect(80, 715, 931, 81));
        frame_toolDevice->setStyleSheet(QString::fromUtf8("QFrame#frame_toolDevice{\n"
"}"));
        frame_toolDevice->setFrameShape(QFrame::StyledPanel);
        frame_toolDevice->setFrameShadow(QFrame::Raised);
        toolButton_menuSelect = new QToolButton(centralwidget);
        toolButton_menuSelect->setObjectName(QString::fromUtf8("toolButton_menuSelect"));
        toolButton_menuSelect->setGeometry(QRect(10, 720, 71, 71));
        toolButton_menuSelect->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(250, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 10px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icon/group/iconMenu_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon15.addFile(QString::fromUtf8(":/icon/group/iconMenu_on.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_menuSelect->setIcon(icon15);
        toolButton_menuSelect->setIconSize(QSize(60, 60));
        toolButton_menuSelect->setAutoRaise(true);
        frame_play = new QFrame(centralwidget);
        frame_play->setObjectName(QString::fromUtf8("frame_play"));
        frame_play->setGeometry(QRect(1020, 719, 172, 73));
        frame_play->setStyleSheet(QString::fromUtf8(""));
        frame_play->setFrameShape(QFrame::Panel);
        frame_play->setFrameShadow(QFrame::Raised);
        toolButton_toolPause = new QToolButton(frame_play);
        toolButton_toolPause->setObjectName(QString::fromUtf8("toolButton_toolPause"));
        toolButton_toolPause->setGeometry(QRect(1, 1, 100, 71));
        toolButton_toolPause->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icon/chart/iconChartPause_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon16.addFile(QString::fromUtf8(":/icon/chart/iconChartPause_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolPause->setIcon(icon16);
        toolButton_toolPause->setIconSize(QSize(80, 80));
        toolButton_toolPause->setAutoRaise(true);
        toolButton_toolPlay = new QToolButton(frame_play);
        toolButton_toolPlay->setObjectName(QString::fromUtf8("toolButton_toolPlay"));
        toolButton_toolPlay->setGeometry(QRect(1, 1, 100, 71));
        toolButton_toolPlay->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icon/chart/iconChartPlay_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon17.addFile(QString::fromUtf8(":/icon/chart/iconChartPlay_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolPlay->setIcon(icon17);
        toolButton_toolPlay->setIconSize(QSize(80, 80));
        toolButton_toolPlay->setAutoRaise(true);
        toolButton_toolClear = new QToolButton(frame_play);
        toolButton_toolClear->setObjectName(QString::fromUtf8("toolButton_toolClear"));
        toolButton_toolClear->setGeometry(QRect(100, 1, 71, 71));
        toolButton_toolClear->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icon/chart/iconChartClear_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon18.addFile(QString::fromUtf8(":/icon/chart/iconChartClear_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolClear->setIcon(icon18);
        toolButton_toolClear->setIconSize(QSize(40, 40));
        toolButton_toolClear->setAutoRaise(true);
        line_4 = new QFrame(frame_play);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(100, 0, 3, 73));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        toolButton_toolManual = new QToolButton(frame_play);
        toolButton_toolManual->setObjectName(QString::fromUtf8("toolButton_toolManual"));
        toolButton_toolManual->setGeometry(QRect(1, 1, 100, 71));
        toolButton_toolManual->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icon/chart/iconChartManual_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon19.addFile(QString::fromUtf8(":/icon/chart/iconChartManual_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolManual->setIcon(icon19);
        toolButton_toolManual->setIconSize(QSize(50, 50));
        toolButton_toolManual->setAutoRaise(true);
        toolButton_toolManual->raise();
        toolButton_toolPause->raise();
        toolButton_toolPlay->raise();
        toolButton_toolClear->raise();
        line_4->raise();
        tableWidget_DataTable = new QTableWidget(centralwidget);
        if (tableWidget_DataTable->columnCount() < 1)
            tableWidget_DataTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_DataTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget_DataTable->setObjectName(QString::fromUtf8("tableWidget_DataTable"));
        tableWidget_DataTable->setGeometry(QRect(859, 40, 291, 492));
        tableWidget_DataTable->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidget_DataTable->setMouseTracking(true);
        tableWidget_DataTable->setAcceptDrops(false);
        tableWidget_DataTable->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"	alternate-background-color: rgb(255, 255, 222);\n"
"	background-color: rgb(250, 255, 255);\n"
"}\n"
"QTableWidget::item:selected{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(64, 65, 66);\n"
"}\n"
"QHeaderView{\n"
"background-color: rgb(30, 40, 65);\n"
"background-color: rgb(25, 149, 173);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QHeaderView::section{\n"
" background-color: rgb(30, 40, 65);\n"
"   background-color: rgb(25, 149, 173);\n"
"   color: rgb(255, 255, 255);\n"
"}"));
        tableWidget_DataTable->setFrameShape(QFrame::Box);
        tableWidget_DataTable->setFrameShadow(QFrame::Raised);
        tableWidget_DataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_DataTable->setDragEnabled(true);
        tableWidget_DataTable->setDragDropOverwriteMode(true);
        tableWidget_DataTable->setDefaultDropAction(Qt::IgnoreAction);
        tableWidget_DataTable->setAlternatingRowColors(true);
        tableWidget_DataTable->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_DataTable->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableWidget_DataTable->verticalHeader()->setVisible(false);
        graphicsViewChart = new QGraphicsView(centralwidget);
        graphicsViewChart->setObjectName(QString::fromUtf8("graphicsViewChart"));
        graphicsViewChart->setGeometry(QRect(50, 40, 809, 630));
        graphicsViewChart->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphicsViewChart->setFrameShape(QFrame::NoFrame);
        graphicsViewChart->setFrameShadow(QFrame::Raised);
        tableWidget_dataEvaluate = new QTableWidget(centralwidget);
        if (tableWidget_dataEvaluate->columnCount() < 1)
            tableWidget_dataEvaluate->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_dataEvaluate->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        if (tableWidget_dataEvaluate->rowCount() < 6)
            tableWidget_dataEvaluate->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_dataEvaluate->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_dataEvaluate->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_dataEvaluate->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_dataEvaluate->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_dataEvaluate->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_dataEvaluate->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem8->setFont(font3);
        __qtablewidgetitem8->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget_dataEvaluate->setItem(0, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem9->setFont(font3);
        __qtablewidgetitem9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget_dataEvaluate->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem10->setFont(font3);
        __qtablewidgetitem10->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget_dataEvaluate->setItem(2, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem11->setFont(font3);
        __qtablewidgetitem11->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget_dataEvaluate->setItem(3, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem12->setFont(font3);
        __qtablewidgetitem12->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget_dataEvaluate->setItem(4, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font3);
        __qtablewidgetitem13->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget_dataEvaluate->setItem(5, 0, __qtablewidgetitem13);
        tableWidget_dataEvaluate->setObjectName(QString::fromUtf8("tableWidget_dataEvaluate"));
        tableWidget_dataEvaluate->setGeometry(QRect(859, 530, 291, 141));
        tableWidget_dataEvaluate->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidget_dataEvaluate->setMouseTracking(true);
        tableWidget_dataEvaluate->setAcceptDrops(false);
        tableWidget_dataEvaluate->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"	alternate-background-color: rgb(255, 255, 222);\n"
"	background-color: rgb(250, 255, 255);\n"
"}\n"
"QTableWidget::item:selected{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(64, 65, 66);\n"
"}\n"
"QHeaderView{\n"
"background-color: rgb(30, 40, 65);\n"
"background-color: rgb(25, 149, 173);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QHeaderView::section{\n"
" background-color: rgb(30, 40, 65);\n"
"   background-color: rgb(25, 149, 173);\n"
"   color: rgb(255, 255, 255);\n"
"}"));
        tableWidget_dataEvaluate->setFrameShape(QFrame::Box);
        tableWidget_dataEvaluate->setFrameShadow(QFrame::Raised);
        tableWidget_dataEvaluate->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_dataEvaluate->setDragEnabled(true);
        tableWidget_dataEvaluate->setDragDropOverwriteMode(true);
        tableWidget_dataEvaluate->setDefaultDropAction(Qt::IgnoreAction);
        tableWidget_dataEvaluate->setAlternatingRowColors(true);
        tableWidget_dataEvaluate->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_dataEvaluate->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableWidget_dataEvaluate->horizontalHeader()->setVisible(false);
        tableWidget_dataEvaluate->verticalHeader()->setVisible(false);
        tableWidget_dataEvaluate->verticalHeader()->setMinimumSectionSize(20);
        tableWidget_dataEvaluate->verticalHeader()->setDefaultSectionSize(20);
        FrmSensorPracticeBase->setCentralWidget(centralwidget);
        tableWidget_dataEvaluate->raise();
        frame_toolTrack->raise();
        frame_toolHeader->raise();
        frame_toolData->raise();
        frame_toolSetup->raise();
        frame_toolDevice->raise();
        toolButton_menuSelect->raise();
        frame_play->raise();
        tableWidget_DataTable->raise();
        graphicsViewChart->raise();

        retranslateUi(FrmSensorPracticeBase);

        QMetaObject::connectSlotsByName(FrmSensorPracticeBase);
    } // setupUi

    void retranslateUi(QMainWindow *FrmSensorPracticeBase)
    {
        FrmSensorPracticeBase->setWindowTitle(QCoreApplication::translate("FrmSensorPracticeBase", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolCrosshair->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "Con tr\341\273\217 ch\341\273\257 th\341\272\255p", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolCrosshair->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolCallout->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "B\341\272\257t \304\221i\341\273\203m tr\303\252n \304\221\306\260\341\273\235ng \304\221\341\273\223 th\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolCallout->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
        label_6->setText(QCoreApplication::translate("FrmSensorPracticeBase", "Con tr\341\273\217", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolHideSeries->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "\341\272\250n hi\341\273\207n \304\221\341\273\223 th\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolHideSeries->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_openFile->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "M\341\273\237 b\303\240i th\341\273\261c h\303\240nh", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_openFile->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_saveFile->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "L\306\260u b\303\240i th\341\273\261c h\303\240nh", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_saveFile->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_exportFile->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "Xu\341\272\245t d\341\273\257 li\341\273\207u", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_exportFile->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolTable->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "D\341\273\257 li\341\273\207u d\341\272\241ng b\341\272\243ng", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolTable->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
        label_9->setText(QCoreApplication::translate("FrmSensorPracticeBase", "B\341\272\243ng", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolLogarit->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "D\341\273\257 li\341\273\207u d\341\272\241ng logarit", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolLogarit->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
        label_8->setText(QCoreApplication::translate("FrmSensorPracticeBase", "D\341\273\257 li\341\273\207u", nullptr));
        label_5->setText(QCoreApplication::translate("FrmSensorPracticeBase", "\304\220\341\273\223 th\341\273\213", nullptr));
        label_7->setText(QCoreApplication::translate("FrmSensorPracticeBase", "So s\303\241nh", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolSingleY->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "So s\303\241nh c\303\271ng tr\341\273\245c tung", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolSingleY->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolLineDot->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "\304\220\341\273\223 th\341\273\213 \304\221i\341\273\203m", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolLineDot->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolMultiY->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "So s\303\241nh kh\303\241c tr\341\273\245c tung", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolMultiY->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolLine->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "\304\220\341\273\223 th\341\273\213 tr\306\241n", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolLine->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
        comboBox_sampleTime->setItemText(0, QCoreApplication::translate("FrmSensorPracticeBase", "60 gi\303\242y/m\341\272\253u", nullptr));
        comboBox_sampleTime->setItemText(1, QCoreApplication::translate("FrmSensorPracticeBase", "30 gi\303\242y/m\341\272\253u", nullptr));
        comboBox_sampleTime->setItemText(2, QCoreApplication::translate("FrmSensorPracticeBase", "10 gi\303\242y/m\341\272\253u", nullptr));
        comboBox_sampleTime->setItemText(3, QCoreApplication::translate("FrmSensorPracticeBase", "5 gi\303\242y/m\341\272\253u", nullptr));
        comboBox_sampleTime->setItemText(4, QCoreApplication::translate("FrmSensorPracticeBase", "2 gi\303\242y/m\341\272\253u", nullptr));
        comboBox_sampleTime->setItemText(5, QCoreApplication::translate("FrmSensorPracticeBase", "1 m\341\272\253u/gi\303\242y", nullptr));
        comboBox_sampleTime->setItemText(6, QCoreApplication::translate("FrmSensorPracticeBase", "2 m\341\272\253u/gi\303\242y", nullptr));
        comboBox_sampleTime->setItemText(7, QCoreApplication::translate("FrmSensorPracticeBase", "5 m\341\272\253u/gi\303\242y", nullptr));
        comboBox_sampleTime->setItemText(8, QCoreApplication::translate("FrmSensorPracticeBase", "10 m\341\272\253u/gi\303\242y", nullptr));
        comboBox_sampleTime->setItemText(9, QCoreApplication::translate("FrmSensorPracticeBase", "50 m\341\272\253u/gi\303\242y", nullptr));
        comboBox_sampleTime->setItemText(10, QCoreApplication::translate("FrmSensorPracticeBase", "100 m\341\272\253u/gi\303\242y", nullptr));
        comboBox_sampleTime->setItemText(11, QCoreApplication::translate("FrmSensorPracticeBase", "500 m\341\272\253u/gi\303\242y", nullptr));

#if QT_CONFIG(tooltip)
        comboBox_sampleTime->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "C\303\240i \304\221\341\272\267t th\341\273\235i gian l\341\272\245y m\341\272\253u", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        lineEdit_playTime->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "C\303\240i \304\221\341\272\267t th\341\273\235i gian th\341\273\261c h\303\240nh", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_playTime->setText(QCoreApplication::translate("FrmSensorPracticeBase", "10", nullptr));
        label->setText(QCoreApplication::translate("FrmSensorPracticeBase", "Th\341\273\235i gian l\341\272\245y m\341\272\253u", nullptr));
        label_timePlay->setText(QCoreApplication::translate("FrmSensorPracticeBase", "Th\341\273\235i gian th\341\273\261c h\303\240nh", nullptr));
        label_3->setText(QCoreApplication::translate("FrmSensorPracticeBase", "gi\303\242y", nullptr));
        label_2->setText(QCoreApplication::translate("FrmSensorPracticeBase", "Ki\341\273\203u l\341\272\245y m\341\272\253u", nullptr));
        comboBox_sampleType->setItemText(0, QCoreApplication::translate("FrmSensorPracticeBase", "L\341\272\245y m\341\272\253u t\341\273\261 \304\221\341\273\231ng (F1 - ESC)", nullptr));
        comboBox_sampleType->setItemText(1, QCoreApplication::translate("FrmSensorPracticeBase", "L\341\272\245y m\341\272\253u b\341\272\261ng tay (F2)", nullptr));

#if QT_CONFIG(tooltip)
        comboBox_sampleType->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "Ki\341\273\203u l\341\272\245y m\341\272\253u", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        toolButton_toolSampleTime->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "\304\220\341\273\223 th\341\273\213 \304\221\306\260\341\273\235ng cong", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolSampleTime->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolSampleTime_2->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "\304\220\341\273\223 th\341\273\213 \304\221\306\260\341\273\235ng cong", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolSampleTime_2->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolSampleTime_3->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "\304\220\341\273\223 th\341\273\213 \304\221\306\260\341\273\235ng cong", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolSampleTime_3->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_menuSelect->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "Th\303\252m thi\341\272\277t b\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_menuSelect->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolPause->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "D\341\273\253ng l\341\272\241i (Esc)", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolPause->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(shortcut)
        toolButton_toolPause->setShortcut(QCoreApplication::translate("FrmSensorPracticeBase", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        toolButton_toolPlay->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "B\341\272\257t \304\221\341\272\247u (F1)", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolPlay->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(shortcut)
        toolButton_toolPlay->setShortcut(QCoreApplication::translate("FrmSensorPracticeBase", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        toolButton_toolClear->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "X\303\263a \304\221\341\273\223 th\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolClear->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolManual->setToolTip(QCoreApplication::translate("FrmSensorPracticeBase", "L\341\272\245y m\341\272\253u (F2)", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolManual->setText(QCoreApplication::translate("FrmSensorPracticeBase", "...", nullptr));
#if QT_CONFIG(shortcut)
        toolButton_toolManual->setShortcut(QCoreApplication::translate("FrmSensorPracticeBase", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        QTableWidgetItem *___qtablewidgetitem = tableWidget_DataTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("FrmSensorPracticeBase", "Th\341\273\235i gian (s)", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_dataEvaluate->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("FrmSensorPracticeBase", "Th\303\264ng s\341\273\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_dataEvaluate->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("FrmSensorPracticeBase", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_dataEvaluate->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("FrmSensorPracticeBase", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_dataEvaluate->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("FrmSensorPracticeBase", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_dataEvaluate->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("FrmSensorPracticeBase", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_dataEvaluate->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("FrmSensorPracticeBase", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_dataEvaluate->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("FrmSensorPracticeBase", "6", nullptr));

        const bool __sortingEnabled = tableWidget_dataEvaluate->isSortingEnabled();
        tableWidget_dataEvaluate->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_dataEvaluate->item(0, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("FrmSensorPracticeBase", "S\341\273\221 m\341\272\253u", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_dataEvaluate->item(1, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("FrmSensorPracticeBase", "Max", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_dataEvaluate->item(2, 0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("FrmSensorPracticeBase", "Min", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_dataEvaluate->item(3, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("FrmSensorPracticeBase", "Trung b\303\254nh", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_dataEvaluate->item(4, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("FrmSensorPracticeBase", "Ph\306\260\306\241ng sai", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_dataEvaluate->item(5, 0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("FrmSensorPracticeBase", "\304\220\341\273\231 l\341\273\207ch chu\341\272\251n", nullptr));
        tableWidget_dataEvaluate->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class FrmSensorPracticeBase: public Ui_FrmSensorPracticeBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSENSORPRACTICEBASE_H
