/********************************************************************************
** Form generated from reading UI file 'frmdeviceselection.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDEVICESELECTION_H
#define UI_FRMDEVICESELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmDeviceSelection
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_Practice;
    QListWidget *listWidget_toolPractice;
    QPushButton *pushButton_cancel;
    QGroupBox *groupBox_Display;
    QListWidget *listWidget_toolDisplay;
    QLabel *label_Name;
    QGroupBox *groupBox_Control;
    QListWidget *listWidget_toolControl;

    void setupUi(QMainWindow *FrmDeviceSelection)
    {
        if (FrmDeviceSelection->objectName().isEmpty())
            FrmDeviceSelection->setObjectName(QString::fromUtf8("FrmDeviceSelection"));
        FrmDeviceSelection->resize(700, 410);
        FrmDeviceSelection->setMinimumSize(QSize(540, 320));
        FrmDeviceSelection->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(FrmDeviceSelection);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_Practice = new QGroupBox(centralwidget);
        groupBox_Practice->setObjectName(QString::fromUtf8("groupBox_Practice"));
        groupBox_Practice->setGeometry(QRect(10, 150, 681, 111));
        QFont font;
        font.setBold(true);
        groupBox_Practice->setFont(font);
        listWidget_toolPractice = new QListWidget(groupBox_Practice);
        listWidget_toolPractice->setObjectName(QString::fromUtf8("listWidget_toolPractice"));
        listWidget_toolPractice->setGeometry(QRect(10, 20, 661, 81));
        listWidget_toolPractice->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        listWidget_toolPractice->setFrameShadow(QFrame::Raised);
        pushButton_cancel = new QPushButton(centralwidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(590, 375, 100, 31));
        pushButton_cancel->setFont(font);
        groupBox_Display = new QGroupBox(centralwidget);
        groupBox_Display->setObjectName(QString::fromUtf8("groupBox_Display"));
        groupBox_Display->setGeometry(QRect(10, 40, 681, 111));
        groupBox_Display->setFont(font);
        listWidget_toolDisplay = new QListWidget(groupBox_Display);
        listWidget_toolDisplay->setObjectName(QString::fromUtf8("listWidget_toolDisplay"));
        listWidget_toolDisplay->setGeometry(QRect(10, 20, 661, 81));
        listWidget_toolDisplay->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
""));
        listWidget_toolDisplay->setFrameShadow(QFrame::Raised);
        label_Name = new QLabel(centralwidget);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setGeometry(QRect(0, 0, 701, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        font1.setBold(true);
        label_Name->setFont(font1);
        label_Name->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255,255);"));
        label_Name->setAlignment(Qt::AlignCenter);
        groupBox_Control = new QGroupBox(centralwidget);
        groupBox_Control->setObjectName(QString::fromUtf8("groupBox_Control"));
        groupBox_Control->setGeometry(QRect(10, 260, 681, 111));
        groupBox_Control->setFont(font);
        listWidget_toolControl = new QListWidget(groupBox_Control);
        listWidget_toolControl->setObjectName(QString::fromUtf8("listWidget_toolControl"));
        listWidget_toolControl->setGeometry(QRect(10, 20, 661, 81));
        listWidget_toolControl->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        listWidget_toolControl->setFrameShadow(QFrame::Raised);
        FrmDeviceSelection->setCentralWidget(centralwidget);
        QWidget::setTabOrder(listWidget_toolDisplay, listWidget_toolPractice);
        QWidget::setTabOrder(listWidget_toolPractice, pushButton_cancel);

        retranslateUi(FrmDeviceSelection);

        QMetaObject::connectSlotsByName(FrmDeviceSelection);
    } // setupUi

    void retranslateUi(QMainWindow *FrmDeviceSelection)
    {
        FrmDeviceSelection->setWindowTitle(QCoreApplication::translate("FrmDeviceSelection", "MainWindow", nullptr));
        groupBox_Practice->setTitle(QCoreApplication::translate("FrmDeviceSelection", "C\303\264ng c\341\273\245 th\341\273\261c h\303\240nh", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("FrmDeviceSelection", "Tho\303\241t", nullptr));
        groupBox_Display->setTitle(QCoreApplication::translate("FrmDeviceSelection", "C\303\264ng c\341\273\245 hi\341\273\203n th\341\273\213 d\341\273\257 li\341\273\207u", nullptr));
        label_Name->setText(QCoreApplication::translate("FrmDeviceSelection", "C\341\272\243m bi\341\272\277n", nullptr));
        groupBox_Control->setTitle(QCoreApplication::translate("FrmDeviceSelection", "C\303\264ng c\341\273\245 \304\221i\341\273\201u khi\341\273\203n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmDeviceSelection: public Ui_FrmDeviceSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDEVICESELECTION_H
