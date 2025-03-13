/********************************************************************************
** Form generated from reading UI file 'frmdeviceicon.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDEVICEICON_H
#define UI_FRMDEVICEICON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmDeviceIcon
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget_Icon;
    QPushButton *pushButton_Select;
    QPushButton *pushButton_Cancel;

    void setupUi(QMainWindow *FrmDeviceIcon)
    {
        if (FrmDeviceIcon->objectName().isEmpty())
            FrmDeviceIcon->setObjectName(QString::fromUtf8("FrmDeviceIcon"));
        FrmDeviceIcon->resize(588, 450);
        centralwidget = new QWidget(FrmDeviceIcon);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget_Icon = new QListWidget(centralwidget);
        listWidget_Icon->setObjectName(QString::fromUtf8("listWidget_Icon"));
        listWidget_Icon->setGeometry(QRect(-1, 10, 591, 403));
        listWidget_Icon->setFrameShape(QFrame::Box);
        pushButton_Select = new QPushButton(centralwidget);
        pushButton_Select->setObjectName(QString::fromUtf8("pushButton_Select"));
        pushButton_Select->setGeometry(QRect(270, 416, 200, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        pushButton_Select->setFont(font);
        pushButton_Cancel = new QPushButton(centralwidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(480, 416, 100, 30));
        pushButton_Cancel->setFont(font);
        FrmDeviceIcon->setCentralWidget(centralwidget);

        retranslateUi(FrmDeviceIcon);

        QMetaObject::connectSlotsByName(FrmDeviceIcon);
    } // setupUi

    void retranslateUi(QMainWindow *FrmDeviceIcon)
    {
        FrmDeviceIcon->setWindowTitle(QCoreApplication::translate("FrmDeviceIcon", "MainWindow", nullptr));
        pushButton_Select->setText(QCoreApplication::translate("FrmDeviceIcon", "Ch\341\273\215n", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Select->setShortcut(QCoreApplication::translate("FrmDeviceIcon", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_Cancel->setText(QCoreApplication::translate("FrmDeviceIcon", "Tho\303\241t", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Cancel->setShortcut(QCoreApplication::translate("FrmDeviceIcon", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class FrmDeviceIcon: public Ui_FrmDeviceIcon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDEVICEICON_H
