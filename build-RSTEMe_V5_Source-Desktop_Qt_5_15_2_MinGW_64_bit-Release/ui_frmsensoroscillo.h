/********************************************************************************
** Form generated from reading UI file 'frmsensoroscillo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSENSOROSCILLO_H
#define UI_FRMSENSOROSCILLO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmSensorOscillo
{
public:
    QWidget *centralwidget;
    QFrame *frame_toolTrack;
    QToolButton *toolButton_toolCrosshair;
    QToolButton *toolButton_toolCallout;
    QLabel *label_6;
    QToolButton *toolButton_toolHideSeries;
    QGraphicsView *graphicsViewChart;
    QFrame *frame_Control;
    QFrame *frame_scope;
    QToolButton *toolButton_plus;
    QToolButton *toolButton_minus;
    QLabel *label_2;
    QLabel *label_scope;
    QFrame *frame_play;
    QToolButton *toolButton_toolPause;
    QToolButton *toolButton_toolPlay;
    QToolButton *toolButton_toolClear;
    QFrame *line_4;
    QFrame *frame_toolSetup;

    void setupUi(QMainWindow *FrmSensorOscillo)
    {
        if (FrmSensorOscillo->objectName().isEmpty())
            FrmSensorOscillo->setObjectName(QString::fromUtf8("FrmSensorOscillo"));
        FrmSensorOscillo->resize(1200, 800);
        centralwidget = new QWidget(FrmSensorOscillo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame_toolTrack = new QFrame(centralwidget);
        frame_toolTrack->setObjectName(QString::fromUtf8("frame_toolTrack"));
        frame_toolTrack->setGeometry(QRect(0, 0, 51, 670));
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
        graphicsViewChart = new QGraphicsView(centralwidget);
        graphicsViewChart->setObjectName(QString::fromUtf8("graphicsViewChart"));
        graphicsViewChart->setGeometry(QRect(50, 0, 1151, 670));
        graphicsViewChart->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphicsViewChart->setFrameShape(QFrame::NoFrame);
        graphicsViewChart->setFrameShadow(QFrame::Raised);
        frame_Control = new QFrame(centralwidget);
        frame_Control->setObjectName(QString::fromUtf8("frame_Control"));
        frame_Control->setGeometry(QRect(0, 669, 1201, 131));
        frame_Control->setFrameShape(QFrame::StyledPanel);
        frame_Control->setFrameShadow(QFrame::Raised);
        frame_scope = new QFrame(frame_Control);
        frame_scope->setObjectName(QString::fromUtf8("frame_scope"));
        frame_scope->setGeometry(QRect(10, 50, 201, 71));
        frame_scope->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color: rgb(250, 255, 255);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 10px;\n"
"}\n"
""));
        frame_scope->setFrameShape(QFrame::Panel);
        frame_scope->setFrameShadow(QFrame::Raised);
        toolButton_plus = new QToolButton(frame_scope);
        toolButton_plus->setObjectName(QString::fromUtf8("toolButton_plus"));
        toolButton_plus->setGeometry(QRect(170, 0, 31, 70));
        toolButton_plus->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_plus{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(25, 149, 173);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"}\n"
"QToolButton#toolButton_plus:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"background-color: rgb(25, 149, 190);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/chart/iconChartPlus_On.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_plus->setIcon(icon3);
        toolButton_plus->setIconSize(QSize(20, 20));
        toolButton_plus->setAutoRaise(true);
        toolButton_minus = new QToolButton(frame_scope);
        toolButton_minus->setObjectName(QString::fromUtf8("toolButton_minus"));
        toolButton_minus->setGeometry(QRect(0, 0, 31, 70));
        toolButton_minus->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_minus{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(25, 149, 173);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-top-left-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}\n"
"QToolButton#toolButton_minus:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"background-color: rgb(25, 149, 190);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/chart/iconChartMinus_On.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_minus->setIcon(icon4);
        toolButton_minus->setIconSize(QSize(20, 20));
        toolButton_minus->setAutoRaise(true);
        label_2 = new QLabel(frame_scope);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 0, 61, 21));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(3, 87, 123);"));
        label_scope = new QLabel(frame_scope);
        label_scope->setObjectName(QString::fromUtf8("label_scope"));
        label_scope->setGeometry(QRect(40, 20, 121, 31));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        label_scope->setFont(font2);
        label_scope->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
""));
        label_scope->setAlignment(Qt::AlignCenter);
        frame_play = new QFrame(frame_Control);
        frame_play->setObjectName(QString::fromUtf8("frame_play"));
        frame_play->setGeometry(QRect(1020, 50, 172, 73));
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/chart/iconChartPause_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/icon/chart/iconChartPause_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolPause->setIcon(icon5);
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/chart/iconChartPlay_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/icon/chart/iconChartPlay_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolPlay->setIcon(icon6);
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/chart/iconChartClear_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/icon/chart/iconChartClear_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolClear->setIcon(icon7);
        toolButton_toolClear->setIconSize(QSize(40, 40));
        toolButton_toolClear->setAutoRaise(true);
        line_4 = new QFrame(frame_play);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(100, 0, 3, 73));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        frame_toolSetup = new QFrame(frame_Control);
        frame_toolSetup->setObjectName(QString::fromUtf8("frame_toolSetup"));
        frame_toolSetup->setGeometry(QRect(0, 0, 1201, 41));
        frame_toolSetup->setStyleSheet(QString::fromUtf8("QFrame#frame_toolSetup{\n"
"	background-color: rgb(25, 149, 173);\n"
"    /*background-color: rgb(3, 87, 123);;*/\n"
"}"));
        frame_toolSetup->setFrameShape(QFrame::Panel);
        frame_toolSetup->setFrameShadow(QFrame::Raised);
        FrmSensorOscillo->setCentralWidget(centralwidget);

        retranslateUi(FrmSensorOscillo);

        QMetaObject::connectSlotsByName(FrmSensorOscillo);
    } // setupUi

    void retranslateUi(QMainWindow *FrmSensorOscillo)
    {
        FrmSensorOscillo->setWindowTitle(QCoreApplication::translate("FrmSensorOscillo", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolCrosshair->setToolTip(QCoreApplication::translate("FrmSensorOscillo", "Con tr\341\273\217 ch\341\273\257 th\341\272\255p", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolCrosshair->setText(QCoreApplication::translate("FrmSensorOscillo", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolCallout->setToolTip(QCoreApplication::translate("FrmSensorOscillo", "B\341\272\257t \304\221i\341\273\203m tr\303\252n \304\221\306\260\341\273\235ng \304\221\341\273\223 th\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolCallout->setText(QCoreApplication::translate("FrmSensorOscillo", "...", nullptr));
        label_6->setText(QCoreApplication::translate("FrmSensorOscillo", "Con tr\341\273\217", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolHideSeries->setToolTip(QCoreApplication::translate("FrmSensorOscillo", "\341\272\250n hi\341\273\207n \304\221\341\273\223 th\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolHideSeries->setText(QCoreApplication::translate("FrmSensorOscillo", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_plus->setToolTip(QCoreApplication::translate("FrmSensorOscillo", "X\303\263a thi\341\272\277t b\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_plus->setText(QCoreApplication::translate("FrmSensorOscillo", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_minus->setToolTip(QCoreApplication::translate("FrmSensorOscillo", "X\303\263a thi\341\272\277t b\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_minus->setText(QCoreApplication::translate("FrmSensorOscillo", "...", nullptr));
        label_2->setText(QCoreApplication::translate("FrmSensorOscillo", "Ph\341\272\241m vi", nullptr));
        label_scope->setText(QCoreApplication::translate("FrmSensorOscillo", "100ms/div", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_toolPause->setToolTip(QCoreApplication::translate("FrmSensorOscillo", "D\341\273\253ng l\341\272\241i (Esc)", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolPause->setText(QCoreApplication::translate("FrmSensorOscillo", "...", nullptr));
#if QT_CONFIG(shortcut)
        toolButton_toolPause->setShortcut(QCoreApplication::translate("FrmSensorOscillo", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        toolButton_toolPlay->setToolTip(QCoreApplication::translate("FrmSensorOscillo", "B\341\272\257t \304\221\341\272\247u (F1)", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolPlay->setText(QCoreApplication::translate("FrmSensorOscillo", "...", nullptr));
#if QT_CONFIG(shortcut)
        toolButton_toolPlay->setShortcut(QCoreApplication::translate("FrmSensorOscillo", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        toolButton_toolClear->setToolTip(QCoreApplication::translate("FrmSensorOscillo", "X\303\263a \304\221\341\273\223 th\341\273\213", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_toolClear->setText(QCoreApplication::translate("FrmSensorOscillo", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmSensorOscillo: public Ui_FrmSensorOscillo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSENSOROSCILLO_H
