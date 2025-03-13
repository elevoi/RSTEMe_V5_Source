/********************************************************************************
** Form generated from reading UI file 'frmpracticebaseinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPRACTICEBASEINFO_H
#define UI_FRMPRACTICEBASEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmPracticeBaseInfo
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_unit;
    QLabel *label;
    QLineEdit *lineEdit_student;
    QLabel *label_2;
    QLineEdit *lineEdit_class;
    QLabel *label_3;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit_description;
    QLabel *label_8;
    QLineEdit *lineEdit_group;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_header;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_subject;
    QLineEdit *lineEdit_teacher;
    QLabel *label_7;
    QGroupBox *groupBox_3;
    QPlainTextEdit *plainTextEdit_parameter;
    QCheckBox *checkBox_parameter;

    void setupUi(QMainWindow *FrmPracticeBaseInfo)
    {
        if (FrmPracticeBaseInfo->objectName().isEmpty())
            FrmPracticeBaseInfo->setObjectName(QString::fromUtf8("FrmPracticeBaseInfo"));
        FrmPracticeBaseInfo->resize(684, 600);
        centralwidget = new QWidget(FrmPracticeBaseInfo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(520, 560, 150, 30));
        QFont font;
        font.setPointSize(10);
        pushButton->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 140, 661, 231));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        groupBox->setFont(font1);
        lineEdit_unit = new QLineEdit(groupBox);
        lineEdit_unit->setObjectName(QString::fromUtf8("lineEdit_unit"));
        lineEdit_unit->setGeometry(QRect(170, 30, 481, 22));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(10);
        font2.setBold(true);
        lineEdit_unit->setFont(font2);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 33, 91, 16));
        label->setFont(font1);
        lineEdit_student = new QLineEdit(groupBox);
        lineEdit_student->setObjectName(QString::fromUtf8("lineEdit_student"));
        lineEdit_student->setGeometry(QRect(170, 60, 241, 22));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(10);
        font3.setBold(false);
        lineEdit_student->setFont(font3);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 63, 91, 16));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        label_2->setFont(font4);
        lineEdit_class = new QLineEdit(groupBox);
        lineEdit_class->setObjectName(QString::fromUtf8("lineEdit_class"));
        lineEdit_class->setGeometry(QRect(170, 90, 241, 22));
        lineEdit_class->setFont(font3);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 93, 91, 16));
        label_3->setFont(font4);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 150, 131, 16));
        label_4->setFont(font4);
        plainTextEdit_description = new QPlainTextEdit(groupBox);
        plainTextEdit_description->setObjectName(QString::fromUtf8("plainTextEdit_description"));
        plainTextEdit_description->setGeometry(QRect(170, 150, 481, 71));
        plainTextEdit_description->setFont(font4);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 123, 91, 16));
        label_8->setFont(font4);
        lineEdit_group = new QLineEdit(groupBox);
        lineEdit_group->setObjectName(QString::fromUtf8("lineEdit_group"));
        lineEdit_group->setGeometry(QRect(170, 120, 241, 22));
        lineEdit_group->setFont(font3);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 661, 121));
        groupBox_2->setFont(font1);
        lineEdit_header = new QLineEdit(groupBox_2);
        lineEdit_header->setObjectName(QString::fromUtf8("lineEdit_header"));
        lineEdit_header->setGeometry(QRect(170, 27, 481, 22));
        lineEdit_header->setFont(font2);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 60, 91, 16));
        label_5->setFont(font4);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 90, 131, 16));
        label_6->setFont(font4);
        lineEdit_subject = new QLineEdit(groupBox_2);
        lineEdit_subject->setObjectName(QString::fromUtf8("lineEdit_subject"));
        lineEdit_subject->setGeometry(QRect(170, 57, 241, 22));
        lineEdit_subject->setFont(font3);
        lineEdit_teacher = new QLineEdit(groupBox_2);
        lineEdit_teacher->setObjectName(QString::fromUtf8("lineEdit_teacher"));
        lineEdit_teacher->setGeometry(QRect(170, 87, 241, 22));
        lineEdit_teacher->setFont(font3);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 30, 91, 16));
        label_7->setFont(font1);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 370, 661, 191));
        groupBox_3->setFont(font1);
        plainTextEdit_parameter = new QPlainTextEdit(groupBox_3);
        plainTextEdit_parameter->setObjectName(QString::fromUtf8("plainTextEdit_parameter"));
        plainTextEdit_parameter->setGeometry(QRect(30, 40, 621, 141));
        plainTextEdit_parameter->setFont(font4);
        checkBox_parameter = new QCheckBox(groupBox_3);
        checkBox_parameter->setObjectName(QString::fromUtf8("checkBox_parameter"));
        checkBox_parameter->setGeometry(QRect(30, 20, 501, 20));
        checkBox_parameter->setFont(font4);
        checkBox_parameter->setChecked(true);
        FrmPracticeBaseInfo->setCentralWidget(centralwidget);
        QWidget::setTabOrder(lineEdit_header, lineEdit_subject);
        QWidget::setTabOrder(lineEdit_subject, lineEdit_teacher);
        QWidget::setTabOrder(lineEdit_teacher, lineEdit_unit);
        QWidget::setTabOrder(lineEdit_unit, lineEdit_student);
        QWidget::setTabOrder(lineEdit_student, lineEdit_class);
        QWidget::setTabOrder(lineEdit_class, lineEdit_group);
        QWidget::setTabOrder(lineEdit_group, plainTextEdit_description);
        QWidget::setTabOrder(plainTextEdit_description, pushButton);

        retranslateUi(FrmPracticeBaseInfo);

        QMetaObject::connectSlotsByName(FrmPracticeBaseInfo);
    } // setupUi

    void retranslateUi(QMainWindow *FrmPracticeBaseInfo)
    {
        FrmPracticeBaseInfo->setWindowTitle(QCoreApplication::translate("FrmPracticeBaseInfo", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "Xu\341\272\245t t\341\273\207p tin", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FrmPracticeBaseInfo", "Th\303\264ng tin th\341\273\261c h\303\240nh", nullptr));
        lineEdit_unit->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "Th\341\273\261c h\303\240nh \304\221o l\306\260\341\273\235ng c\341\272\243m bi\341\272\277n", nullptr));
        lineEdit_unit->setPlaceholderText(QCoreApplication::translate("FrmPracticeBaseInfo", "Th\341\273\261c h\303\240nh \304\221o l\306\260\341\273\235ng c\341\272\243m bi\341\272\277n", nullptr));
        label->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "B\303\240i th\341\273\261c h\303\240nh:", nullptr));
        lineEdit_student->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "Tr\341\272\247n v\304\203n B", nullptr));
        lineEdit_student->setPlaceholderText(QCoreApplication::translate("FrmPracticeBaseInfo", "Tr\341\272\247n v\304\203n B", nullptr));
        label_2->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "H\341\273\215c sinh:", nullptr));
        lineEdit_class->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "6", nullptr));
        lineEdit_class->setPlaceholderText(QCoreApplication::translate("FrmPracticeBaseInfo", "6", nullptr));
        label_3->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "L\341\273\233p:", nullptr));
        label_4->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "Nh\341\272\255n x\303\251t:", nullptr));
        plainTextEdit_description->setPlainText(QCoreApplication::translate("FrmPracticeBaseInfo", "M\303\264 t\341\272\243 chi ti\341\272\277t", nullptr));
        plainTextEdit_description->setPlaceholderText(QCoreApplication::translate("FrmPracticeBaseInfo", "Nh\341\272\255n x\303\251t...", nullptr));
        label_8->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "Nh\303\263m:", nullptr));
        lineEdit_group->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "A1", nullptr));
        lineEdit_group->setPlaceholderText(QCoreApplication::translate("FrmPracticeBaseInfo", "A1", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FrmPracticeBaseInfo", "Th\303\264ng tin b\303\241o c\303\241o", nullptr));
        lineEdit_header->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "B\303\241o c\303\241o th\303\255 nghi\341\273\207m", nullptr));
        lineEdit_header->setPlaceholderText(QCoreApplication::translate("FrmPracticeBaseInfo", "B\303\241o c\303\241o th\303\255 nghi\341\273\207m", nullptr));
        label_5->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "M\303\264n h\341\273\215c:", nullptr));
        label_6->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "Gi\303\241o vi\303\252n h\306\260\341\273\233ng d\341\272\253n:", nullptr));
        lineEdit_subject->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "V\341\272\255t l\303\275", nullptr));
        lineEdit_subject->setPlaceholderText(QCoreApplication::translate("FrmPracticeBaseInfo", "V\341\272\255t l\303\275", nullptr));
        lineEdit_teacher->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "Nguy\341\273\205n v\304\203n A", nullptr));
        lineEdit_teacher->setPlaceholderText(QCoreApplication::translate("FrmPracticeBaseInfo", "Nguy\341\273\205n v\304\203n A", nullptr));
        label_7->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "Ti\303\252u \304\221\341\273\201:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("FrmPracticeBaseInfo", "Th\303\264ng s\341\273\221", nullptr));
        plainTextEdit_parameter->setPlainText(QString());
        plainTextEdit_parameter->setPlaceholderText(QCoreApplication::translate("FrmPracticeBaseInfo", "Th\303\264ng s\341\273\221 th\341\273\261c h\303\240nh...", nullptr));
        checkBox_parameter->setText(QCoreApplication::translate("FrmPracticeBaseInfo", "Xu\341\272\245t c\303\241c th\303\264ng s\341\273\221 th\341\273\261c h\303\240nh theo t\341\273\207p", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmPracticeBaseInfo: public Ui_FrmPracticeBaseInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPRACTICEBASEINFO_H
