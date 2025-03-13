/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QListWidget *listWidget_online;
    QListWidget *listWidget_Type;
    QListWidget *listWidget_Group;
    QToolButton *toolButton_groupSoftware;
    QToolButton *toolButton_groupSensor;
    QToolButton *toolButton_groupSystem;
    QToolButton *toolButton_groupModule;
    QPushButton *pushButton_TypeList;
    QFrame *line;
    QFrame *line_2;
    QFrame *frame_Display;
    QToolButton *toolButton_groupSearch;
    QToolButton *toolButton_groupConnection;
    QToolButton *toolButton_login;
    QToolButton *toolButton_clearDevice;
    QFrame *line_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1280, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/group/steme_icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setIconSize(QSize(24, 24));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listWidget_online = new QListWidget(centralWidget);
        listWidget_online->setObjectName(QString::fromUtf8("listWidget_online"));
        listWidget_online->setGeometry(QRect(120, 5, 1071, 50));
        listWidget_online->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        listWidget_online->setFrameShape(QFrame::NoFrame);
        listWidget_Type = new QListWidget(centralWidget);
        listWidget_Type->setObjectName(QString::fromUtf8("listWidget_Type"));
        listWidget_Type->setGeometry(QRect(120, 88, 251, 713));
        listWidget_Type->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 255, 255);\n"
"background-color: rgb(245, 245,245);\n"
"background-color: rgb(250, 255, 255);"));
        listWidget_Type->setFrameShape(QFrame::NoFrame);
        listWidget_Type->setFrameShadow(QFrame::Sunken);
        listWidget_Group = new QListWidget(centralWidget);
        listWidget_Group->setObjectName(QString::fromUtf8("listWidget_Group"));
        listWidget_Group->setGeometry(QRect(10, 60, 111, 741));
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
        toolButton_groupSoftware = new QToolButton(centralWidget);
        toolButton_groupSoftware->setObjectName(QString::fromUtf8("toolButton_groupSoftware"));
        toolButton_groupSoftware->setGeometry(QRect(10, 170, 100, 75));
        QFont font;
        font.setPointSize(7);
        font.setBold(true);
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/group/iconSoftwareGroup_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icon/group/iconSoftwareGroup_on.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_groupSoftware->setIcon(icon1);
        toolButton_groupSoftware->setIconSize(QSize(50, 50));
        toolButton_groupSoftware->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_groupSoftware->setAutoRaise(true);
        toolButton_groupSensor = new QToolButton(centralWidget);
        toolButton_groupSensor->setObjectName(QString::fromUtf8("toolButton_groupSensor"));
        toolButton_groupSensor->setGeometry(QRect(10, 270, 100, 75));
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/group/iconSensorGroup_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/icon/group/iconSensorGroup_on.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_groupSensor->setIcon(icon2);
        toolButton_groupSensor->setIconSize(QSize(50, 50));
        toolButton_groupSensor->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_groupSensor->setAutoRaise(true);
        toolButton_groupSystem = new QToolButton(centralWidget);
        toolButton_groupSystem->setObjectName(QString::fromUtf8("toolButton_groupSystem"));
        toolButton_groupSystem->setGeometry(QRect(10, 470, 100, 75));
        toolButton_groupSystem->setFont(font);
        toolButton_groupSystem->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_groupSystem{\n"
"color: rgb(3, 87, 123);\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/group/iconSystemGroup_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/icon/group/iconSystemGroup_on.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_groupSystem->setIcon(icon3);
        toolButton_groupSystem->setIconSize(QSize(50, 50));
        toolButton_groupSystem->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_groupSystem->setAutoRaise(true);
        toolButton_groupModule = new QToolButton(centralWidget);
        toolButton_groupModule->setObjectName(QString::fromUtf8("toolButton_groupModule"));
        toolButton_groupModule->setGeometry(QRect(10, 370, 100, 75));
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/group/iconModuleGroup_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/icon/group/iconModuleGroup_on.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_groupModule->setIcon(icon4);
        toolButton_groupModule->setIconSize(QSize(50, 50));
        toolButton_groupModule->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_groupModule->setAutoRaise(true);
        pushButton_TypeList = new QPushButton(centralWidget);
        pushButton_TypeList->setObjectName(QString::fromUtf8("pushButton_TypeList"));
        pushButton_TypeList->setGeometry(QRect(120, 60, 251, 28));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        pushButton_TypeList->setFont(font1);
        pushButton_TypeList->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_TypeList{\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 149, 173);\n"
"border: none;\n"
"border-width: 0px;\n"
"}\n"
"QPushButton#pushButton_TypeList:hover{\n"
"	background-color: rgb(31, 188, 216);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        pushButton_TypeList->setFlat(true);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(9, 60, 101, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(120, 10, 3, 41));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        frame_Display = new QFrame(centralWidget);
        frame_Display->setObjectName(QString::fromUtf8("frame_Display"));
        frame_Display->setGeometry(QRect(380, 60, 901, 741));
        frame_Display->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_Display->setFrameShape(QFrame::StyledPanel);
        frame_Display->setFrameShadow(QFrame::Raised);
        toolButton_groupSearch = new QToolButton(centralWidget);
        toolButton_groupSearch->setObjectName(QString::fromUtf8("toolButton_groupSearch"));
        toolButton_groupSearch->setGeometry(QRect(10, 70, 100, 75));
        toolButton_groupSearch->setFont(font);
        toolButton_groupSearch->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_groupSearch{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 15px;\n"
"}\n"
"QToolButton#toolButton_groupSearch:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/group/iconSearchGroup_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/icon/group/iconSearchGroup_on.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_groupSearch->setIcon(icon5);
        toolButton_groupSearch->setIconSize(QSize(50, 50));
        toolButton_groupSearch->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_groupSearch->setAutoRaise(true);
        toolButton_groupConnection = new QToolButton(centralWidget);
        toolButton_groupConnection->setObjectName(QString::fromUtf8("toolButton_groupConnection"));
        toolButton_groupConnection->setGeometry(QRect(15, 10, 91, 40));
        toolButton_groupConnection->setFont(font);
        toolButton_groupConnection->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_groupConnection{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 30 ,40);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 20px;\n"
"}\n"
"QToolButton#toolButton_groupConnection:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/group/iconSoftwareConnect_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/icon/group/iconSoftwareConnect_Active.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_groupConnection->setIcon(icon6);
        toolButton_groupConnection->setIconSize(QSize(100, 35));
        toolButton_groupConnection->setPopupMode(QToolButton::DelayedPopup);
        toolButton_groupConnection->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_groupConnection->setAutoRaise(true);
        toolButton_login = new QToolButton(centralWidget);
        toolButton_login->setObjectName(QString::fromUtf8("toolButton_login"));
        toolButton_login->setGeometry(QRect(10, 710, 100, 75));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(true);
        toolButton_login->setFont(font2);
        toolButton_login->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_login{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 15px;\n"
"}\n"
"QToolButton#toolButton_login:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/group/iconLogin_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/icon/group/iconLogin_on.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_login->setIcon(icon7);
        toolButton_login->setIconSize(QSize(75, 50));
        toolButton_login->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_login->setAutoRaise(true);
        toolButton_clearDevice = new QToolButton(centralWidget);
        toolButton_clearDevice->setObjectName(QString::fromUtf8("toolButton_clearDevice"));
        toolButton_clearDevice->setGeometry(QRect(1195, 5, 81, 51));
        toolButton_clearDevice->setFont(font);
        toolButton_clearDevice->setStyleSheet(QString::fromUtf8("QToolButton#toolButton_clearDevice{\n"
"color: rgb(2, 87, 122);\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"border-style: outset;\n"
"border-width: 0px;\n"
"border-radius: 15px;\n"
"}\n"
"QToolButton#toolButton_clearDevice:hover{\n"
"background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/group/iconClear_Off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/icon/group/iconClear_On.jpg"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_clearDevice->setIcon(icon8);
        toolButton_clearDevice->setIconSize(QSize(30, 30));
        toolButton_clearDevice->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_clearDevice->setAutoRaise(true);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 560, 101, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(toolButton_groupConnection, listWidget_Type);
        QWidget::setTabOrder(listWidget_Type, listWidget_Group);
        QWidget::setTabOrder(listWidget_Group, toolButton_groupSearch);
        QWidget::setTabOrder(toolButton_groupSearch, toolButton_groupSoftware);
        QWidget::setTabOrder(toolButton_groupSoftware, toolButton_groupSensor);
        QWidget::setTabOrder(toolButton_groupSensor, toolButton_groupModule);
        QWidget::setTabOrder(toolButton_groupModule, toolButton_groupSystem);
        QWidget::setTabOrder(toolButton_groupSystem, toolButton_login);
        QWidget::setTabOrder(toolButton_login, listWidget_online);
        QWidget::setTabOrder(listWidget_online, pushButton_TypeList);
        QWidget::setTabOrder(pushButton_TypeList, toolButton_clearDevice);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "STEMe - Khoa h\341\273\215c v\303\240 gi\303\241o d\341\273\245c", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        toolButton_groupSoftware->setText(QCoreApplication::translate("MainWindow", "Ph\341\272\247n m\341\273\201m", nullptr));
        toolButton_groupSensor->setText(QCoreApplication::translate("MainWindow", "C\341\272\243m bi\341\272\277n", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_groupSystem->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        toolButton_groupSystem->setText(QCoreApplication::translate("MainWindow", "M\303\264 h\303\254nh th\303\255 nghi\341\273\207m", nullptr));
        toolButton_groupModule->setText(QCoreApplication::translate("MainWindow", "M\303\264 \304\221un th\341\273\261c h\303\240nh", nullptr));
        pushButton_TypeList->setText(QCoreApplication::translate("MainWindow", "Hi\341\273\203n th\341\273\213 m\303\243 thi\341\272\277t b\341\273\213", nullptr));
        toolButton_groupSearch->setText(QCoreApplication::translate("MainWindow", "T\303\254m thi\341\272\277t b\341\273\213", nullptr));
        toolButton_groupConnection->setText(QCoreApplication::translate("MainWindow", "K\341\272\277t n\341\273\221i", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_login->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        toolButton_login->setText(QCoreApplication::translate("MainWindow", "\304\220\304\203ng nh\341\272\255p", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_clearDevice->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        toolButton_clearDevice->setText(QCoreApplication::translate("MainWindow", "X\303\263a thi\341\272\277t b\341\273\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
