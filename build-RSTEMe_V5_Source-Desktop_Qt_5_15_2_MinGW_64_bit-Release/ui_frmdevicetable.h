/********************************************************************************
** Form generated from reading UI file 'frmdevicetable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDEVICETABLE_H
#define UI_FRMDEVICETABLE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmDeviceTable
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget_Group;
    QToolButton *toolButton_groupSensor;
    QToolButton *toolButton_groupModule;
    QToolButton *toolButton_groupSystem;
    QToolButton *toolButton_groupSoftware;
    QListWidget *listWidget_Type;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_selectDevice;

    void setupUi(QMainWindow *FrmDeviceTable)
    {
        if (FrmDeviceTable->objectName().isEmpty())
            FrmDeviceTable->setObjectName(QString::fromUtf8("FrmDeviceTable"));
        FrmDeviceTable->resize(1000, 600);
        centralwidget = new QWidget(FrmDeviceTable);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget_Group = new QListWidget(centralwidget);
        listWidget_Group->setObjectName(QString::fromUtf8("listWidget_Group"));
        listWidget_Group->setGeometry(QRect(10, 0, 111, 561));
        listWidget_Group->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        listWidget_Group->setFrameShape(QFrame::NoFrame);
        listWidget_Group->setFrameShadow(QFrame::Sunken);
        listWidget_Group->setAlternatingRowColors(false);
        listWidget_Group->setTextElideMode(Qt::ElideMiddle);
        listWidget_Group->setMovement(QListView::Static);
        listWidget_Group->setViewMode(QListView::IconMode);
        listWidget_Group->setModelColumn(0);
        listWidget_Group->setUniformItemSizes(true);
        listWidget_Group->setSelectionRectVisible(false);
        toolButton_groupSensor = new QToolButton(centralwidget);
        toolButton_groupSensor->setObjectName(QString::fromUtf8("toolButton_groupSensor"));
        toolButton_groupSensor->setGeometry(QRect(15, 120, 100, 75));
        QFont font;
        font.setPointSize(7);
        font.setBold(true);
        toolButton_groupSensor->setFont(font);
        toolButton_groupSensor->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_groupSensor{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 15px;\n"
"}\n"
"QToolButton#toolButton_groupSensor:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/group/iconSensorGroup_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/icon/group/iconSensorGroup_on.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_groupSensor->setIcon(icon);
        toolButton_groupSensor->setIconSize(QSize(75, 50));
        toolButton_groupSensor->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_groupSensor->setAutoRaise(true);
        toolButton_groupModule = new QToolButton(centralwidget);
        toolButton_groupModule->setObjectName(QString::fromUtf8("toolButton_groupModule"));
        toolButton_groupModule->setGeometry(QRect(15, 220, 100, 75));
        toolButton_groupModule->setFont(font);
        toolButton_groupModule->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_groupModule{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 15px;\n"
"}\n"
"QToolButton#toolButton_groupModule:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/group/iconModuleGroup_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icon/group/iconModuleGroup_on.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_groupModule->setIcon(icon1);
        toolButton_groupModule->setIconSize(QSize(75, 50));
        toolButton_groupModule->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_groupModule->setAutoRaise(true);
        toolButton_groupSystem = new QToolButton(centralwidget);
        toolButton_groupSystem->setObjectName(QString::fromUtf8("toolButton_groupSystem"));
        toolButton_groupSystem->setGeometry(QRect(15, 320, 100, 75));
        toolButton_groupSystem->setFont(font);
        toolButton_groupSystem->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_groupSystem{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 15px;\n"
"}\n"
"QToolButton#toolButton_groupSystem:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/group/iconSystemGroup_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/icon/group/iconSystemGroup_on.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_groupSystem->setIcon(icon2);
        toolButton_groupSystem->setIconSize(QSize(75, 50));
        toolButton_groupSystem->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_groupSystem->setAutoRaise(true);
        toolButton_groupSoftware = new QToolButton(centralwidget);
        toolButton_groupSoftware->setObjectName(QString::fromUtf8("toolButton_groupSoftware"));
        toolButton_groupSoftware->setGeometry(QRect(15, 20, 100, 75));
        toolButton_groupSoftware->setFont(font);
        toolButton_groupSoftware->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_groupSoftware{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 15px;\n"
"}\n"
"QToolButton#toolButton_groupSoftware:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/group/iconSoftwareGroup_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/icon/group/iconSoftwareGroup_on.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_groupSoftware->setIcon(icon3);
        toolButton_groupSoftware->setIconSize(QSize(75, 50));
        toolButton_groupSoftware->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_groupSoftware->setAutoRaise(true);
        listWidget_Type = new QListWidget(centralwidget);
        listWidget_Type->setObjectName(QString::fromUtf8("listWidget_Type"));
        listWidget_Type->setGeometry(QRect(130, 0, 871, 561));
        listWidget_Type->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 255, 255);"));
        listWidget_Type->setFrameShape(QFrame::NoFrame);
        listWidget_Type->setFrameShadow(QFrame::Sunken);
        pushButton_Cancel = new QPushButton(centralwidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(890, 565, 100, 30));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        pushButton_Cancel->setFont(font1);
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_selectDevice = new QPushButton(centralwidget);
        pushButton_selectDevice->setObjectName(QString::fromUtf8("pushButton_selectDevice"));
        pushButton_selectDevice->setGeometry(QRect(680, 565, 200, 31));
        pushButton_selectDevice->setFont(font1);
        pushButton_selectDevice->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        FrmDeviceTable->setCentralWidget(centralwidget);
        QWidget::setTabOrder(toolButton_groupSoftware, toolButton_groupSensor);
        QWidget::setTabOrder(toolButton_groupSensor, toolButton_groupModule);
        QWidget::setTabOrder(toolButton_groupModule, toolButton_groupSystem);
        QWidget::setTabOrder(toolButton_groupSystem, pushButton_selectDevice);
        QWidget::setTabOrder(pushButton_selectDevice, pushButton_Cancel);
        QWidget::setTabOrder(pushButton_Cancel, listWidget_Type);
        QWidget::setTabOrder(listWidget_Type, listWidget_Group);

        retranslateUi(FrmDeviceTable);

        QMetaObject::connectSlotsByName(FrmDeviceTable);
    } // setupUi

    void retranslateUi(QMainWindow *FrmDeviceTable)
    {
        FrmDeviceTable->setWindowTitle(QCoreApplication::translate("FrmDeviceTable", "MainWindow", nullptr));
        toolButton_groupSensor->setText(QCoreApplication::translate("FrmDeviceTable", "C\341\272\243m bi\341\272\277n", nullptr));
        toolButton_groupModule->setText(QCoreApplication::translate("FrmDeviceTable", "M\303\264 \304\221un th\341\273\261c h\303\240nh", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_groupSystem->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        toolButton_groupSystem->setText(QCoreApplication::translate("FrmDeviceTable", "M\303\264 h\303\254nh th\303\255 nghi\341\273\207m", nullptr));
        toolButton_groupSoftware->setText(QCoreApplication::translate("FrmDeviceTable", "Ph\341\272\247n m\341\273\201m", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("FrmDeviceTable", "Tho\303\241t", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Cancel->setShortcut(QCoreApplication::translate("FrmDeviceTable", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_selectDevice->setText(QCoreApplication::translate("FrmDeviceTable", "Ch\341\273\215n thi\341\272\277t b\341\273\213", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_selectDevice->setShortcut(QCoreApplication::translate("FrmDeviceTable", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class FrmDeviceTable: public Ui_FrmDeviceTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDEVICETABLE_H
