/********************************************************************************
** Form generated from reading UI file 'frmprogram.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPROGRAM_H
#define UI_FRMPROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmProgram
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit_program;
    QPushButton *pushButton_run;
    QMenuBar *menubar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *FrmProgram)
    {
        if (FrmProgram->objectName().isEmpty())
            FrmProgram->setObjectName(QString::fromUtf8("FrmProgram"));
        FrmProgram->resize(1289, 698);
        centralwidget = new QWidget(FrmProgram);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit_program = new QTextEdit(centralwidget);
        textEdit_program->setObjectName(QString::fromUtf8("textEdit_program"));
        textEdit_program->setGeometry(QRect(0, 0, 841, 631));
        pushButton_run = new QPushButton(centralwidget);
        pushButton_run->setObjectName(QString::fromUtf8("pushButton_run"));
        pushButton_run->setGeometry(QRect(850, 10, 91, 31));
        FrmProgram->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FrmProgram);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1289, 22));
        FrmProgram->setMenuBar(menubar);
        dockWidget = new QDockWidget(FrmProgram);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setLayoutDirection(Qt::LeftToRight);
        dockWidget->setFloating(false);
        dockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        FrmProgram->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

        retranslateUi(FrmProgram);

        QMetaObject::connectSlotsByName(FrmProgram);
    } // setupUi

    void retranslateUi(QMainWindow *FrmProgram)
    {
        FrmProgram->setWindowTitle(QCoreApplication::translate("FrmProgram", "MainWindow", nullptr));
        pushButton_run->setText(QCoreApplication::translate("FrmProgram", "Ch\341\272\241y", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("FrmProgram", "Th\303\264ng b\303\241o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmProgram: public Ui_FrmProgram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPROGRAM_H
