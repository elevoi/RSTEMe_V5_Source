/********************************************************************************
** Form generated from reading UI file 'frmconnectionsetup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCONNECTIONSETUP_H
#define UI_FRMCONNECTIONSETUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmConnectionSetup
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QComboBox *comboBox_ComPort;
    QLabel *label;
    QPushButton *pushButton_Active;
    QWidget *tab_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QSpinBox *spinBox;
    QPushButton *pushButton_ConnectComPort;
    QPushButton *pushButton_Cancel;

    void setupUi(QMainWindow *FrmConnectionSetup)
    {
        if (FrmConnectionSetup->objectName().isEmpty())
            FrmConnectionSetup->setObjectName(QString::fromUtf8("FrmConnectionSetup"));
        FrmConnectionSetup->resize(427, 202);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/group/iconSoftwareGroup_off.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FrmConnectionSetup->setWindowIcon(icon);
        centralwidget = new QWidget(FrmConnectionSetup);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-1, 0, 431, 164));
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        comboBox_ComPort = new QComboBox(tab);
        comboBox_ComPort->setObjectName(QString::fromUtf8("comboBox_ComPort"));
        comboBox_ComPort->setGeometry(QRect(90, 9, 321, 30));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 14, 61, 20));
        pushButton_Active = new QPushButton(tab);
        pushButton_Active->setObjectName(QString::fromUtf8("pushButton_Active"));
        pushButton_Active->setGeometry(QRect(290, 50, 121, 30));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 10, 61, 20));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 9, 161, 22));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 10, 41, 20));
        spinBox = new QSpinBox(tab_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(310, 10, 71, 22));
        spinBox->setMaximum(65535);
        spinBox->setSingleStep(1);
        spinBox->setValue(21);
        tabWidget->addTab(tab_2, QString());
        pushButton_ConnectComPort = new QPushButton(centralwidget);
        pushButton_ConnectComPort->setObjectName(QString::fromUtf8("pushButton_ConnectComPort"));
        pushButton_ConnectComPort->setGeometry(QRect(110, 167, 200, 31));
        pushButton_Cancel = new QPushButton(centralwidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(320, 167, 100, 31));
        FrmConnectionSetup->setCentralWidget(centralwidget);
        QWidget::setTabOrder(tabWidget, comboBox_ComPort);
        QWidget::setTabOrder(comboBox_ComPort, pushButton_Active);
        QWidget::setTabOrder(pushButton_Active, pushButton_ConnectComPort);
        QWidget::setTabOrder(pushButton_ConnectComPort, pushButton_Cancel);
        QWidget::setTabOrder(pushButton_Cancel, lineEdit);
        QWidget::setTabOrder(lineEdit, spinBox);

        retranslateUi(FrmConnectionSetup);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FrmConnectionSetup);
    } // setupUi

    void retranslateUi(QMainWindow *FrmConnectionSetup)
    {
        FrmConnectionSetup->setWindowTitle(QCoreApplication::translate("FrmConnectionSetup", "Giao ti\341\272\277p", nullptr));
        label->setText(QCoreApplication::translate("FrmConnectionSetup", "T\303\252n c\341\273\225ng:", nullptr));
        pushButton_Active->setText(QCoreApplication::translate("FrmConnectionSetup", "T\341\272\243i l\341\272\241i", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FrmConnectionSetup", "          C\341\273\225ng n\341\273\221i ti\341\272\277p          ", nullptr));
        label_2->setText(QCoreApplication::translate("FrmConnectionSetup", "\304\220\341\273\213a ch\341\273\211 IP:", nullptr));
        lineEdit->setText(QCoreApplication::translate("FrmConnectionSetup", "127.0.0.1", nullptr));
        label_3->setText(QCoreApplication::translate("FrmConnectionSetup", "C\341\273\225ng:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FrmConnectionSetup", "       Giao ti\341\272\277p m\341\272\241ng       ", nullptr));
        pushButton_ConnectComPort->setText(QCoreApplication::translate("FrmConnectionSetup", "K\341\272\277t n\341\273\221i", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("FrmConnectionSetup", "Tho\303\241t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmConnectionSetup: public Ui_FrmConnectionSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCONNECTIONSETUP_H
