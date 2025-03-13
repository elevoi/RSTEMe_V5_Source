/********************************************************************************
** Form generated from reading UI file 'frmsearchdevice.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSEARCHDEVICE_H
#define UI_FRMSEARCHDEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmSearchDevice
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QFrame *line;
    QListWidget *listWidget;
    QPushButton *pushButton_Search;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_addNew;
    QFrame *frame;
    QProgressBar *progressBar_search;
    QLabel *label_search;

    void setupUi(QMainWindow *FrmSearchDevice)
    {
        if (FrmSearchDevice->objectName().isEmpty())
            FrmSearchDevice->setObjectName(QString::fromUtf8("FrmSearchDevice"));
        FrmSearchDevice->resize(500, 525);
        centralwidget = new QWidget(FrmSearchDevice);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 0, 491, 51));
        QFont font;
        font.setPointSize(10);
        font.setItalic(true);
        plainTextEdit->setFont(font);
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setFrameShadow(QFrame::Plain);
        plainTextEdit->setReadOnly(true);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 50, 361, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 51, 361, 451));
        listWidget->setFrameShape(QFrame::Panel);
        listWidget->setFrameShadow(QFrame::Raised);
        pushButton_Search = new QPushButton(centralwidget);
        pushButton_Search->setObjectName(QString::fromUtf8("pushButton_Search"));
        pushButton_Search->setGeometry(QRect(370, 50, 121, 61));
        pushButton_Search->setStyleSheet(QString::fromUtf8(""));
        pushButton_Search->setFlat(false);
        pushButton_Cancel = new QPushButton(centralwidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(370, 470, 121, 31));
        pushButton_Cancel->setStyleSheet(QString::fromUtf8(""));
        pushButton_addNew = new QPushButton(centralwidget);
        pushButton_addNew->setObjectName(QString::fromUtf8("pushButton_addNew"));
        pushButton_addNew->setGeometry(QRect(370, 120, 121, 61));
        pushButton_addNew->setStyleSheet(QString::fromUtf8(""));
        pushButton_addNew->setFlat(false);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 500, 501, 31));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        progressBar_search = new QProgressBar(frame);
        progressBar_search->setObjectName(QString::fromUtf8("progressBar_search"));
        progressBar_search->setGeometry(QRect(0, 20, 501, 5));
        progressBar_search->setValue(24);
        progressBar_search->setTextVisible(false);
        label_search = new QLabel(frame);
        label_search->setObjectName(QString::fromUtf8("label_search"));
        label_search->setGeometry(QRect(10, 1, 351, 16));
        FrmSearchDevice->setCentralWidget(centralwidget);
        QWidget::setTabOrder(pushButton_Search, pushButton_addNew);
        QWidget::setTabOrder(pushButton_addNew, pushButton_Cancel);
        QWidget::setTabOrder(pushButton_Cancel, plainTextEdit);
        QWidget::setTabOrder(plainTextEdit, listWidget);

        retranslateUi(FrmSearchDevice);

        QMetaObject::connectSlotsByName(FrmSearchDevice);
    } // setupUi

    void retranslateUi(QMainWindow *FrmSearchDevice)
    {
        FrmSearchDevice->setWindowTitle(QCoreApplication::translate("FrmSearchDevice", "MainWindow", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("FrmSearchDevice", "T\303\254m ki\341\272\277m t\341\272\245t c\341\272\243 thi\341\272\277t b\341\273\213 c\303\263 trong danh m\341\273\245c \304\221\303\243 l\306\260u tr\341\273\257 t\341\273\253 tr\306\260\341\273\233c. Sau \304\221\303\263 t\303\254m ki\341\272\277m thi\341\272\277t b\341\273\213 m\341\273\233i \304\221\306\260\341\273\243c k\341\272\277t n\341\273\221i.", nullptr));
        pushButton_Search->setText(QCoreApplication::translate("FrmSearchDevice", "T\303\254m", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("FrmSearchDevice", "Tho\303\241t", nullptr));
        pushButton_addNew->setText(QCoreApplication::translate("FrmSearchDevice", "Th\303\252m thi\341\272\277t b\341\273\213 m\341\273\233i", nullptr));
        label_search->setText(QCoreApplication::translate("FrmSearchDevice", "Searching...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmSearchDevice: public Ui_FrmSearchDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSEARCHDEVICE_H
