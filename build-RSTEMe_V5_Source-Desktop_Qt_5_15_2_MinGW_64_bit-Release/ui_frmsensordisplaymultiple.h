/********************************************************************************
** Form generated from reading UI file 'frmsensordisplaymultiple.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSENSORDISPLAYMULTIPLE_H
#define UI_FRMSENSORDISPLAYMULTIPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmSensorDisplayMultiple
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QFrame *frame_status;
    QLabel *label;
    QSpinBox *spinBox_rowMax;
    QToolButton *toolButton_cancel;

    void setupUi(QMainWindow *FrmSensorDisplayMultiple)
    {
        if (FrmSensorDisplayMultiple->objectName().isEmpty())
            FrmSensorDisplayMultiple->setObjectName(QString::fromUtf8("FrmSensorDisplayMultiple"));
        FrmSensorDisplayMultiple->resize(510, 242);
        FrmSensorDisplayMultiple->setStyleSheet(QString::fromUtf8("background-color: rgb(2,87, 122);\n"
"background-color: rgb(64, 65, 66);"));
        centralwidget = new QWidget(FrmSensorDisplayMultiple);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(1, 1, 508, 211));
        frame_status = new QFrame(centralwidget);
        frame_status->setObjectName(QString::fromUtf8("frame_status"));
        frame_status->setGeometry(QRect(0, 212, 351, 30));
        frame_status->setFrameShape(QFrame::StyledPanel);
        frame_status->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_status);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(7, 6, 111, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        spinBox_rowMax = new QSpinBox(frame_status);
        spinBox_rowMax->setObjectName(QString::fromUtf8("spinBox_rowMax"));
        spinBox_rowMax->setGeometry(QRect(117, 4, 81, 22));
        spinBox_rowMax->setStyleSheet(QString::fromUtf8("color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);"));
        spinBox_rowMax->setMinimum(1);
        spinBox_rowMax->setValue(3);
        toolButton_cancel = new QToolButton(centralwidget);
        toolButton_cancel->setObjectName(QString::fromUtf8("toolButton_cancel"));
        toolButton_cancel->setGeometry(QRect(388, 215, 120, 25));
        toolButton_cancel->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 15px;\n"
"}\n"
"QToolButton:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        toolButton_cancel->setAutoRaise(false);
        FrmSensorDisplayMultiple->setCentralWidget(centralwidget);

        retranslateUi(FrmSensorDisplayMultiple);

        QMetaObject::connectSlotsByName(FrmSensorDisplayMultiple);
    } // setupUi

    void retranslateUi(QMainWindow *FrmSensorDisplayMultiple)
    {
        FrmSensorDisplayMultiple->setWindowTitle(QCoreApplication::translate("FrmSensorDisplayMultiple", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("FrmSensorDisplayMultiple", "S\341\273\221 h\303\240ng t\341\273\221i \304\221a:", nullptr));
        toolButton_cancel->setText(QCoreApplication::translate("FrmSensorDisplayMultiple", "Tho\303\241t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmSensorDisplayMultiple: public Ui_FrmSensorDisplayMultiple {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSENSORDISPLAYMULTIPLE_H
