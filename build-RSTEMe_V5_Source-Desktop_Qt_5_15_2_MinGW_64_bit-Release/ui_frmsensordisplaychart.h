/********************************************************************************
** Form generated from reading UI file 'frmsensordisplaychart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSENSORDISPLAYCHART_H
#define UI_FRMSENSORDISPLAYCHART_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmSensorDisplayChart
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsViewChart;
    QFrame *frame_Header;
    QLabel *label;
    QCheckBox *checkBox_antiAliasing;
    QComboBox *comboBox_legend;
    QLabel *label_3;
    QComboBox *comboBox_theme;
    QFrame *line;
    QFrame *line_2;
    QFrame *frame_toolTrack;
    QToolButton *toolButton_toolCrosshair;
    QToolButton *toolButton_toolCallout;
    QFrame *frame_toolControl;
    QToolButton *toolButton_toolPause;
    QToolButton *toolButton_toolClear;
    QFrame *line_4;
    QToolButton *toolButton_toolPlay;

    void setupUi(QMainWindow *FrmSensorDisplayChart)
    {
        if (FrmSensorDisplayChart->objectName().isEmpty())
            FrmSensorDisplayChart->setObjectName(QString::fromUtf8("FrmSensorDisplayChart"));
        FrmSensorDisplayChart->resize(1200, 779);
        FrmSensorDisplayChart->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(FrmSensorDisplayChart);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsViewChart = new QGraphicsView(centralwidget);
        graphicsViewChart->setObjectName(QString::fromUtf8("graphicsViewChart"));
        graphicsViewChart->setGeometry(QRect(51, 40, 1151, 740));
        graphicsViewChart->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphicsViewChart->setFrameShape(QFrame::NoFrame);
        graphicsViewChart->setFrameShadow(QFrame::Raised);
        frame_Header = new QFrame(centralwidget);
        frame_Header->setObjectName(QString::fromUtf8("frame_Header"));
        frame_Header->setGeometry(QRect(0, 0, 1201, 41));
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
        frame_toolTrack = new QFrame(centralwidget);
        frame_toolTrack->setObjectName(QString::fromUtf8("frame_toolTrack"));
        frame_toolTrack->setGeometry(QRect(0, 40, 51, 561));
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
        frame_toolControl->setGeometry(QRect(0, 590, 51, 181));
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
        toolButton_toolClear = new QToolButton(frame_toolControl);
        toolButton_toolClear->setObjectName(QString::fromUtf8("toolButton_toolClear"));
        toolButton_toolClear->setGeometry(QRect(5, 140, 40, 40));
        toolButton_toolClear->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        icon3.addFile(QString::fromUtf8(":/icon/chart/iconChartClear_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/icon/chart/iconChartClear_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolClear->setIcon(icon3);
        toolButton_toolClear->setIconSize(QSize(30, 30));
        toolButton_toolClear->setAutoRaise(true);
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/chart/iconChartPlay_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/icon/chart/iconChartPlay_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_toolPlay->setIcon(icon4);
        toolButton_toolPlay->setIconSize(QSize(30, 30));
        toolButton_toolPlay->setAutoRaise(true);
        FrmSensorDisplayChart->setCentralWidget(centralwidget);
        QWidget::setTabOrder(comboBox_theme, comboBox_legend);
        QWidget::setTabOrder(comboBox_legend, checkBox_antiAliasing);
        QWidget::setTabOrder(checkBox_antiAliasing, toolButton_toolCrosshair);
        QWidget::setTabOrder(toolButton_toolCrosshair, toolButton_toolCallout);
        QWidget::setTabOrder(toolButton_toolCallout, toolButton_toolPlay);
        QWidget::setTabOrder(toolButton_toolPlay, toolButton_toolPause);
        QWidget::setTabOrder(toolButton_toolPause, toolButton_toolClear);
        QWidget::setTabOrder(toolButton_toolClear, graphicsViewChart);

        retranslateUi(FrmSensorDisplayChart);

        QMetaObject::connectSlotsByName(FrmSensorDisplayChart);
    } // setupUi

    void retranslateUi(QMainWindow *FrmSensorDisplayChart)
    {
        FrmSensorDisplayChart->setWindowTitle(QCoreApplication::translate("FrmSensorDisplayChart", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("FrmSensorDisplayChart", "B\341\273\221i c\341\272\243nh \304\221\341\273\223 th\341\273\213", nullptr));
        checkBox_antiAliasing->setText(QCoreApplication::translate("FrmSensorDisplayChart", "Kh\341\273\255 r\304\203ng c\306\260a", nullptr));
        label_3->setText(QCoreApplication::translate("FrmSensorDisplayChart", "\304\220\306\260\341\273\235ng ghi ch\303\272", nullptr));
        toolButton_toolCrosshair->setText(QCoreApplication::translate("FrmSensorDisplayChart", "...", nullptr));
        toolButton_toolCallout->setText(QCoreApplication::translate("FrmSensorDisplayChart", "...", nullptr));
        toolButton_toolPause->setText(QCoreApplication::translate("FrmSensorDisplayChart", "...", nullptr));
        toolButton_toolClear->setText(QCoreApplication::translate("FrmSensorDisplayChart", "...", nullptr));
        toolButton_toolPlay->setText(QCoreApplication::translate("FrmSensorDisplayChart", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmSensorDisplayChart: public Ui_FrmSensorDisplayChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSENSORDISPLAYCHART_H
