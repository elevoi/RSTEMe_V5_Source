/********************************************************************************
** Form generated from reading UI file 'frmdevicesetup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDEVICESETUP_H
#define UI_FRMDEVICESETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmDeviceSetup
{
public:
    QWidget *centralwidget;
    QFrame *frameDevice;
    QFrame *lineDevice;
    QLabel *label_nameDevice;
    QTextEdit *textEditDescription;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_groupDevice;
    QLabel *label_typeDevice;
    QLabel *label_versionDevice;
    QLabel *label_5;
    QLabel *label_serialNumber;
    QPushButton *pushButton_remove;
    QPushButton *pushButton_save;
    QFrame *frameCancel;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_addDevice;
    QTreeWidget *treeWidgetDevice;
    QPushButton *pushButton_saveList;
    QPushButton *pushButton_openList;

    void setupUi(QMainWindow *FrmDeviceSetup)
    {
        if (FrmDeviceSetup->objectName().isEmpty())
            FrmDeviceSetup->setObjectName(QString::fromUtf8("FrmDeviceSetup"));
        FrmDeviceSetup->resize(860, 592);
        centralwidget = new QWidget(FrmDeviceSetup);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frameDevice = new QFrame(centralwidget);
        frameDevice->setObjectName(QString::fromUtf8("frameDevice"));
        frameDevice->setGeometry(QRect(300, 0, 571, 551));
        frameDevice->setFrameShape(QFrame::Panel);
        frameDevice->setFrameShadow(QFrame::Raised);
        lineDevice = new QFrame(frameDevice);
        lineDevice->setObjectName(QString::fromUtf8("lineDevice"));
        lineDevice->setGeometry(QRect(0, 30, 2000, 3));
        lineDevice->setFrameShape(QFrame::HLine);
        lineDevice->setFrameShadow(QFrame::Sunken);
        label_nameDevice = new QLabel(frameDevice);
        label_nameDevice->setObjectName(QString::fromUtf8("label_nameDevice"));
        label_nameDevice->setGeometry(QRect(10, 8, 521, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_nameDevice->setFont(font);
        textEditDescription = new QTextEdit(frameDevice);
        textEditDescription->setObjectName(QString::fromUtf8("textEditDescription"));
        textEditDescription->setGeometry(QRect(40, 180, 510, 321));
        textEditDescription->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        textEditDescription->setFrameShape(QFrame::NoFrame);
        textEditDescription->setReadOnly(true);
        label_4 = new QLabel(frameDevice);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(36, 101, 71, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        label_4->setFont(font1);
        label = new QLabel(frameDevice);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(55, 81, 41, 31));
        label->setFont(font1);
        label_7 = new QLabel(frameDevice);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(32, 121, 71, 31));
        label_7->setFont(font1);
        label_3 = new QLabel(frameDevice);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(28, 50, 71, 31));
        label_3->setFont(font1);
        label_groupDevice = new QLabel(frameDevice);
        label_groupDevice->setObjectName(QString::fromUtf8("label_groupDevice"));
        label_groupDevice->setGeometry(QRect(110, 81, 171, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(true);
        label_groupDevice->setFont(font2);
        label_typeDevice = new QLabel(frameDevice);
        label_typeDevice->setObjectName(QString::fromUtf8("label_typeDevice"));
        label_typeDevice->setGeometry(QRect(110, 101, 171, 31));
        label_typeDevice->setFont(font2);
        label_versionDevice = new QLabel(frameDevice);
        label_versionDevice->setObjectName(QString::fromUtf8("label_versionDevice"));
        label_versionDevice->setGeometry(QRect(110, 121, 171, 31));
        label_versionDevice->setFont(font2);
        label_5 = new QLabel(frameDevice);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(14, 150, 81, 31));
        label_5->setFont(font1);
        label_serialNumber = new QLabel(frameDevice);
        label_serialNumber->setObjectName(QString::fromUtf8("label_serialNumber"));
        label_serialNumber->setGeometry(QRect(110, 50, 201, 31));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setItalic(false);
        label_serialNumber->setFont(font3);
        label_serialNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 127);\n"
"color: rgb(255, 255, 255);"));
        label_serialNumber->setAlignment(Qt::AlignCenter);
        pushButton_remove = new QPushButton(frameDevice);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));
        pushButton_remove->setGeometry(QRect(450, 510, 100, 25));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(false);
        pushButton_remove->setFont(font4);
        pushButton_remove->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_save = new QPushButton(frameDevice);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(290, 510, 150, 25));
        pushButton_save->setFont(font4);
        pushButton_save->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        frameCancel = new QFrame(centralwidget);
        frameCancel->setObjectName(QString::fromUtf8("frameCancel"));
        frameCancel->setGeometry(QRect(470, 540, 391, 51));
        frameCancel->setFrameShape(QFrame::StyledPanel);
        frameCancel->setFrameShadow(QFrame::Raised);
        pushButton_Cancel = new QPushButton(frameCancel);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(280, 16, 100, 30));
        pushButton_Cancel->setFont(font1);
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_addDevice = new QPushButton(frameCancel);
        pushButton_addDevice->setObjectName(QString::fromUtf8("pushButton_addDevice"));
        pushButton_addDevice->setGeometry(QRect(70, 16, 200, 31));
        pushButton_addDevice->setFont(font1);
        pushButton_addDevice->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        treeWidgetDevice = new QTreeWidget(centralwidget);
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        treeWidgetDevice->headerItem()->setText(0, QString());
        treeWidgetDevice->headerItem()->setText(1, QString());
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(1, Qt::AlignCenter);
        __qtreewidgetitem->setFont(1, font5);
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        __qtreewidgetitem->setFont(0, font5);
        treeWidgetDevice->setHeaderItem(__qtreewidgetitem);
        treeWidgetDevice->setObjectName(QString::fromUtf8("treeWidgetDevice"));
        treeWidgetDevice->setGeometry(QRect(0, 0, 301, 551));
        treeWidgetDevice->setFrameShape(QFrame::Panel);
        treeWidgetDevice->setFrameShadow(QFrame::Raised);
        pushButton_saveList = new QPushButton(centralwidget);
        pushButton_saveList->setObjectName(QString::fromUtf8("pushButton_saveList"));
        pushButton_saveList->setGeometry(QRect(190, 510, 100, 25));
        pushButton_saveList->setFont(font4);
        pushButton_saveList->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_openList = new QPushButton(centralwidget);
        pushButton_openList->setObjectName(QString::fromUtf8("pushButton_openList"));
        pushButton_openList->setGeometry(QRect(80, 510, 100, 25));
        pushButton_openList->setFont(font4);
        pushButton_openList->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        FrmDeviceSetup->setCentralWidget(centralwidget);
        QWidget::setTabOrder(treeWidgetDevice, pushButton_openList);
        QWidget::setTabOrder(pushButton_openList, pushButton_saveList);
        QWidget::setTabOrder(pushButton_saveList, textEditDescription);
        QWidget::setTabOrder(textEditDescription, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_remove);
        QWidget::setTabOrder(pushButton_remove, pushButton_addDevice);
        QWidget::setTabOrder(pushButton_addDevice, pushButton_Cancel);

        retranslateUi(FrmDeviceSetup);

        QMetaObject::connectSlotsByName(FrmDeviceSetup);
    } // setupUi

    void retranslateUi(QMainWindow *FrmDeviceSetup)
    {
        FrmDeviceSetup->setWindowTitle(QCoreApplication::translate("FrmDeviceSetup", "MainWindow", nullptr));
        label_nameDevice->setText(QCoreApplication::translate("FrmDeviceSetup", "C\341\272\243m bi\341\272\277n nhi\341\273\207t \304\221\341\273\231", nullptr));
        textEditDescription->setHtml(QCoreApplication::translate("FrmDeviceSetup", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        textEditDescription->setPlaceholderText(QCoreApplication::translate("FrmDeviceSetup", "M\303\264 t\341\272\243 chi ti\341\272\277t thi\341\272\277t b\341\273\213...", nullptr));
        label_4->setText(QCoreApplication::translate("FrmDeviceSetup", "Ph\303\242n lo\341\272\241i:", nullptr));
        label->setText(QCoreApplication::translate("FrmDeviceSetup", "Nh\303\263m:", nullptr));
        label_7->setText(QCoreApplication::translate("FrmDeviceSetup", "Phi\303\252n b\341\272\243n:", nullptr));
        label_3->setText(QCoreApplication::translate("FrmDeviceSetup", "M\303\243 thi\341\272\277t b\341\273\213:", nullptr));
        label_groupDevice->setText(QCoreApplication::translate("FrmDeviceSetup", "C\341\272\243m bi\341\272\277n", nullptr));
        label_typeDevice->setText(QCoreApplication::translate("FrmDeviceSetup", "C\341\272\243m bi\341\272\277n nhi\341\273\207t \304\221\341\273\231", nullptr));
        label_versionDevice->setText(QCoreApplication::translate("FrmDeviceSetup", "2", nullptr));
        label_5->setText(QCoreApplication::translate("FrmDeviceSetup", "M\303\264 t\341\272\243 chi ti\341\272\277t:", nullptr));
        label_serialNumber->setText(QCoreApplication::translate("FrmDeviceSetup", "000009AF", nullptr));
        pushButton_remove->setText(QCoreApplication::translate("FrmDeviceSetup", "X\303\263a", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_remove->setShortcut(QCoreApplication::translate("FrmDeviceSetup", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_save->setText(QCoreApplication::translate("FrmDeviceSetup", "L\306\260u t\341\273\207p", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_save->setShortcut(QCoreApplication::translate("FrmDeviceSetup", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_Cancel->setText(QCoreApplication::translate("FrmDeviceSetup", "Tho\303\241t", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Cancel->setShortcut(QCoreApplication::translate("FrmDeviceSetup", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_addDevice->setText(QCoreApplication::translate("FrmDeviceSetup", "Th\303\252m/s\341\273\255a thi\341\272\277t b\341\273\213", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_addDevice->setShortcut(QCoreApplication::translate("FrmDeviceSetup", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_saveList->setText(QCoreApplication::translate("FrmDeviceSetup", "L\306\260u danh s\303\241ch", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_saveList->setShortcut(QCoreApplication::translate("FrmDeviceSetup", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_openList->setText(QCoreApplication::translate("FrmDeviceSetup", "T\341\272\243i danh s\303\241ch", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_openList->setShortcut(QCoreApplication::translate("FrmDeviceSetup", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class FrmDeviceSetup: public Ui_FrmDeviceSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDEVICESETUP_H
