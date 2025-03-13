/********************************************************************************
** Form generated from reading UI file 'frmaccountsetup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMACCOUNTSETUP_H
#define UI_FRMACCOUNTSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmAccountSetup
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_Cancel;
    QToolBox *toolBox;
    QWidget *page;
    QGroupBox *groupBox_AccountInfo;
    QLabel *label_Info_Type;
    QLabel *label_Info_Account;
    QLabel *label;
    QLabel *label_2;
    QWidget *page_4;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_NewRePassword;
    QComboBox *comboBox_NewType;
    QLineEdit *lineEdit_NewPassword;
    QLineEdit *lineEdit_NewAccount;
    QPushButton *pushButton_ChangePassword_NewCreat;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_7;
    QWidget *page_3;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_ChangePassword;
    QLineEdit *lineEdit_ChangeNewPassword;
    QLineEdit *lineEdit_ChangeRePassword;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_ChangePassword;
    QWidget *page_2;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_Remove;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_12;
    QLineEdit *lineEdit_RemoveRePassword;
    QComboBox *comboBox_RemoveAccount;
    QLineEdit *lineEdit_RemovePassword;
    QWidget *page_5;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_RemoveDefault;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *FrmAccountSetup)
    {
        if (FrmAccountSetup->objectName().isEmpty())
            FrmAccountSetup->setObjectName(QString::fromUtf8("FrmAccountSetup"));
        FrmAccountSetup->resize(440, 440);
        FrmAccountSetup->setMinimumSize(QSize(440, 440));
        FrmAccountSetup->setMaximumSize(QSize(440, 440));
        centralwidget = new QWidget(FrmAccountSetup);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_Cancel = new QPushButton(centralwidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(330, 400, 100, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        pushButton_Cancel->setFont(font);
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(10, 10, 421, 381));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        toolBox->setFont(font1);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 421, 221));
        groupBox_AccountInfo = new QGroupBox(page);
        groupBox_AccountInfo->setObjectName(QString::fromUtf8("groupBox_AccountInfo"));
        groupBox_AccountInfo->setGeometry(QRect(0, 0, 421, 231));
        groupBox_AccountInfo->setFont(font1);
        groupBox_AccountInfo->setStyleSheet(QString::fromUtf8(""));
        groupBox_AccountInfo->setFlat(false);
        label_Info_Type = new QLabel(groupBox_AccountInfo);
        label_Info_Type->setObjectName(QString::fromUtf8("label_Info_Type"));
        label_Info_Type->setGeometry(QRect(150, 60, 259, 29));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        label_Info_Type->setFont(font2);
        label_Info_Type->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);"));
        label_Info_Account = new QLabel(groupBox_AccountInfo);
        label_Info_Account->setObjectName(QString::fromUtf8("label_Info_Account"));
        label_Info_Account->setGeometry(QRect(150, 20, 259, 30));
        label_Info_Account->setFont(font2);
        label_Info_Account->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 149, 173);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(groupBox_AccountInfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(47, 61, 91, 29));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        label->setFont(font3);
        label_2 = new QLabel(groupBox_AccountInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(52, 20, 91, 30));
        label_2->setFont(font3);
        toolBox->addItem(page, QString::fromUtf8("Th\303\264ng tin t\303\240i kho\341\272\243n \304\221ang s\341\273\255 d\341\273\245ng"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 421, 221));
        groupBox_3 = new QGroupBox(page_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 421, 231));
        groupBox_3->setFont(font1);
        lineEdit_NewRePassword = new QLineEdit(groupBox_3);
        lineEdit_NewRePassword->setObjectName(QString::fromUtf8("lineEdit_NewRePassword"));
        lineEdit_NewRePassword->setGeometry(QRect(150, 140, 259, 30));
        lineEdit_NewRePassword->setFont(font);
        lineEdit_NewRePassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        comboBox_NewType = new QComboBox(groupBox_3);
        comboBox_NewType->addItem(QString());
        comboBox_NewType->addItem(QString());
        comboBox_NewType->addItem(QString());
        comboBox_NewType->setObjectName(QString::fromUtf8("comboBox_NewType"));
        comboBox_NewType->setGeometry(QRect(150, 60, 259, 30));
        comboBox_NewType->setFont(font);
        comboBox_NewType->setEditable(false);
        lineEdit_NewPassword = new QLineEdit(groupBox_3);
        lineEdit_NewPassword->setObjectName(QString::fromUtf8("lineEdit_NewPassword"));
        lineEdit_NewPassword->setGeometry(QRect(150, 100, 259, 30));
        lineEdit_NewPassword->setFont(font);
        lineEdit_NewPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        lineEdit_NewAccount = new QLineEdit(groupBox_3);
        lineEdit_NewAccount->setObjectName(QString::fromUtf8("lineEdit_NewAccount"));
        lineEdit_NewAccount->setGeometry(QRect(150, 20, 259, 30));
        lineEdit_NewAccount->setFont(font);
        pushButton_ChangePassword_NewCreat = new QPushButton(groupBox_3);
        pushButton_ChangePassword_NewCreat->setObjectName(QString::fromUtf8("pushButton_ChangePassword_NewCreat"));
        pushButton_ChangePassword_NewCreat->setGeometry(QRect(150, 190, 259, 30));
        pushButton_ChangePassword_NewCreat->setFont(font1);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(23, 138, 121, 35));
        label_10->setFont(font);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(75, 98, 71, 34));
        label_9->setFont(font);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(48, 58, 91, 35));
        label_8->setFont(font);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(52, 18, 91, 35));
        label_7->setFont(font);
        toolBox->addItem(page_4, QString::fromUtf8("T\341\272\241o t\303\240i kho\341\272\243n m\341\273\233i"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 421, 221));
        groupBox = new QGroupBox(page_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 421, 231));
        groupBox->setFont(font1);
        lineEdit_ChangePassword = new QLineEdit(groupBox);
        lineEdit_ChangePassword->setObjectName(QString::fromUtf8("lineEdit_ChangePassword"));
        lineEdit_ChangePassword->setGeometry(QRect(150, 20, 259, 30));
        lineEdit_ChangePassword->setFont(font);
        lineEdit_ChangePassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        lineEdit_ChangeNewPassword = new QLineEdit(groupBox);
        lineEdit_ChangeNewPassword->setObjectName(QString::fromUtf8("lineEdit_ChangeNewPassword"));
        lineEdit_ChangeNewPassword->setGeometry(QRect(150, 60, 259, 30));
        lineEdit_ChangeNewPassword->setFont(font);
        lineEdit_ChangeNewPassword->setEchoMode(QLineEdit::Password);
        lineEdit_ChangeRePassword = new QLineEdit(groupBox);
        lineEdit_ChangeRePassword->setObjectName(QString::fromUtf8("lineEdit_ChangeRePassword"));
        lineEdit_ChangeRePassword->setGeometry(QRect(150, 100, 259, 30));
        lineEdit_ChangeRePassword->setFont(font);
        lineEdit_ChangeRePassword->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(57, 19, 81, 33));
        label_3->setFont(font);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(49, 59, 91, 33));
        label_5->setFont(font);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(23, 99, 121, 33));
        label_6->setFont(font);
        pushButton_ChangePassword = new QPushButton(groupBox);
        pushButton_ChangePassword->setObjectName(QString::fromUtf8("pushButton_ChangePassword"));
        pushButton_ChangePassword->setGeometry(QRect(150, 150, 259, 30));
        pushButton_ChangePassword->setFont(font1);
        toolBox->addItem(page_3, QString::fromUtf8("Thay \304\221\341\273\225i m\341\272\255t kh\341\272\251u"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 421, 221));
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 421, 221));
        groupBox_2->setFont(font1);
        pushButton_Remove = new QPushButton(groupBox_2);
        pushButton_Remove->setObjectName(QString::fromUtf8("pushButton_Remove"));
        pushButton_Remove->setGeometry(QRect(150, 150, 261, 30));
        pushButton_Remove->setFont(font1);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(42, 19, 101, 33));
        label_11->setFont(font);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(23, 99, 121, 33));
        label_13->setFont(font);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(75, 59, 71, 33));
        label_12->setFont(font);
        lineEdit_RemoveRePassword = new QLineEdit(groupBox_2);
        lineEdit_RemoveRePassword->setObjectName(QString::fromUtf8("lineEdit_RemoveRePassword"));
        lineEdit_RemoveRePassword->setGeometry(QRect(150, 100, 259, 30));
        lineEdit_RemoveRePassword->setFont(font);
        lineEdit_RemoveRePassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        comboBox_RemoveAccount = new QComboBox(groupBox_2);
        comboBox_RemoveAccount->setObjectName(QString::fromUtf8("comboBox_RemoveAccount"));
        comboBox_RemoveAccount->setGeometry(QRect(150, 20, 259, 30));
        comboBox_RemoveAccount->setFont(font);
        comboBox_RemoveAccount->setEditable(false);
        lineEdit_RemovePassword = new QLineEdit(groupBox_2);
        lineEdit_RemovePassword->setObjectName(QString::fromUtf8("lineEdit_RemovePassword"));
        lineEdit_RemovePassword->setGeometry(QRect(150, 60, 259, 30));
        lineEdit_RemovePassword->setFont(font);
        lineEdit_RemovePassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        toolBox->addItem(page_2, QString::fromUtf8("X\303\263a t\303\240i kho\341\272\243n"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 421, 221));
        groupBox_4 = new QGroupBox(page_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 0, 421, 201));
        groupBox_4->setFont(font1);
        pushButton_RemoveDefault = new QPushButton(groupBox_4);
        pushButton_RemoveDefault->setObjectName(QString::fromUtf8("pushButton_RemoveDefault"));
        pushButton_RemoveDefault->setGeometry(QRect(150, 150, 261, 30));
        pushButton_RemoveDefault->setFont(font1);
        plainTextEdit = new QPlainTextEdit(groupBox_4);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 10, 401, 121));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setItalic(true);
        plainTextEdit->setFont(font4);
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"color: rgb(0, 85, 127);"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setReadOnly(true);
        toolBox->addItem(page_5, QString::fromUtf8("Thi\341\272\277t l\341\272\255p m\341\272\267c \304\221\341\273\213nh"));
        FrmAccountSetup->setCentralWidget(centralwidget);
        QWidget::setTabOrder(lineEdit_NewAccount, comboBox_NewType);
        QWidget::setTabOrder(comboBox_NewType, lineEdit_NewPassword);
        QWidget::setTabOrder(lineEdit_NewPassword, lineEdit_NewRePassword);
        QWidget::setTabOrder(lineEdit_NewRePassword, pushButton_ChangePassword_NewCreat);
        QWidget::setTabOrder(pushButton_ChangePassword_NewCreat, lineEdit_ChangePassword);
        QWidget::setTabOrder(lineEdit_ChangePassword, lineEdit_ChangeNewPassword);
        QWidget::setTabOrder(lineEdit_ChangeNewPassword, lineEdit_ChangeRePassword);
        QWidget::setTabOrder(lineEdit_ChangeRePassword, pushButton_ChangePassword);
        QWidget::setTabOrder(pushButton_ChangePassword, comboBox_RemoveAccount);
        QWidget::setTabOrder(comboBox_RemoveAccount, lineEdit_RemovePassword);
        QWidget::setTabOrder(lineEdit_RemovePassword, lineEdit_RemoveRePassword);
        QWidget::setTabOrder(lineEdit_RemoveRePassword, pushButton_Remove);
        QWidget::setTabOrder(pushButton_Remove, pushButton_Cancel);

        retranslateUi(FrmAccountSetup);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FrmAccountSetup);
    } // setupUi

    void retranslateUi(QMainWindow *FrmAccountSetup)
    {
        FrmAccountSetup->setWindowTitle(QCoreApplication::translate("FrmAccountSetup", "MainWindow", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("FrmAccountSetup", "Tho\303\241t", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Cancel->setShortcut(QCoreApplication::translate("FrmAccountSetup", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_AccountInfo->setTitle(QString());
        label_Info_Type->setText(QString());
        label_Info_Account->setText(QString());
        label->setText(QCoreApplication::translate("FrmAccountSetup", "Ki\341\273\203u t\303\240i kho\341\272\243n:", nullptr));
        label_2->setText(QCoreApplication::translate("FrmAccountSetup", "T\303\252n t\303\240i kho\341\272\243n:", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("FrmAccountSetup", "Th\303\264ng tin t\303\240i kho\341\272\243n \304\221ang s\341\273\255 d\341\273\245ng", nullptr));
        groupBox_3->setTitle(QString());
        lineEdit_NewRePassword->setPlaceholderText(QCoreApplication::translate("FrmAccountSetup", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        comboBox_NewType->setItemText(0, QCoreApplication::translate("FrmAccountSetup", "Student (H\341\273\215c sinh)", nullptr));
        comboBox_NewType->setItemText(1, QCoreApplication::translate("FrmAccountSetup", "Teacher (Gi\303\241o vi\303\252n)", nullptr));
        comboBox_NewType->setItemText(2, QCoreApplication::translate("FrmAccountSetup", "Root (Qu\341\272\243n tr\341\273\213)", nullptr));

        comboBox_NewType->setCurrentText(QCoreApplication::translate("FrmAccountSetup", "Student (H\341\273\215c sinh)", nullptr));
        lineEdit_NewPassword->setPlaceholderText(QCoreApplication::translate("FrmAccountSetup", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        lineEdit_NewAccount->setPlaceholderText(QCoreApplication::translate("FrmAccountSetup", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        pushButton_ChangePassword_NewCreat->setText(QCoreApplication::translate("FrmAccountSetup", "T\341\272\241o t\303\240i kho\341\272\243n", nullptr));
        label_10->setText(QCoreApplication::translate("FrmAccountSetup", "Nh\341\272\255p l\341\272\241i m\341\272\255t kh\341\272\251u:", nullptr));
        label_9->setText(QCoreApplication::translate("FrmAccountSetup", "M\341\272\255t kh\341\272\251u:", nullptr));
        label_8->setText(QCoreApplication::translate("FrmAccountSetup", "Lo\341\272\241i t\303\240i kho\341\272\243n:", nullptr));
        label_7->setText(QCoreApplication::translate("FrmAccountSetup", "T\303\252n t\303\240i kho\341\272\243n:", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("FrmAccountSetup", "T\341\272\241o t\303\240i kho\341\272\243n m\341\273\233i", nullptr));
        groupBox->setTitle(QString());
        lineEdit_ChangePassword->setPlaceholderText(QCoreApplication::translate("FrmAccountSetup", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        lineEdit_ChangeNewPassword->setPlaceholderText(QCoreApplication::translate("FrmAccountSetup", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        lineEdit_ChangeRePassword->setPlaceholderText(QCoreApplication::translate("FrmAccountSetup", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        label_3->setText(QCoreApplication::translate("FrmAccountSetup", "M\341\272\255t kh\341\272\251u c\305\251:", nullptr));
        label_5->setText(QCoreApplication::translate("FrmAccountSetup", "M\341\272\255t kh\341\272\251u m\341\273\233i:", nullptr));
        label_6->setText(QCoreApplication::translate("FrmAccountSetup", "Nh\341\272\255p l\341\272\241i m\341\272\255t kh\341\272\251u:", nullptr));
        pushButton_ChangePassword->setText(QCoreApplication::translate("FrmAccountSetup", "\304\220\341\273\225i m\341\272\255t kh\341\272\251u", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("FrmAccountSetup", "Thay \304\221\341\273\225i m\341\272\255t kh\341\272\251u", nullptr));
        groupBox_2->setTitle(QString());
        pushButton_Remove->setText(QCoreApplication::translate("FrmAccountSetup", "X\303\263a t\303\240i kho\341\272\243n", nullptr));
        label_11->setText(QCoreApplication::translate("FrmAccountSetup", "Ch\341\273\215n t\303\240i kho\341\272\243n:", nullptr));
        label_13->setText(QCoreApplication::translate("FrmAccountSetup", "Nh\341\272\255p l\341\272\241i m\341\272\255t kh\341\272\251u:", nullptr));
        label_12->setText(QCoreApplication::translate("FrmAccountSetup", "M\341\272\255t kh\341\272\251u:", nullptr));
        lineEdit_RemoveRePassword->setPlaceholderText(QCoreApplication::translate("FrmAccountSetup", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        comboBox_RemoveAccount->setCurrentText(QString());
        lineEdit_RemovePassword->setPlaceholderText(QCoreApplication::translate("FrmAccountSetup", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("FrmAccountSetup", "X\303\263a t\303\240i kho\341\272\243n", nullptr));
        groupBox_4->setTitle(QString());
        pushButton_RemoveDefault->setText(QCoreApplication::translate("FrmAccountSetup", "X\303\263a v\341\273\201 m\341\272\267c \304\221\341\273\213nh ban \304\221\341\272\247u", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("FrmAccountSetup", "Ch\341\273\211 c\303\263 t\303\240i kho\341\272\243n v\341\273\233i t\303\252n \"root\" c\303\263 th\341\273\203 x\303\263a \304\221\306\260\341\273\243c d\341\273\257 li\341\273\207u v\341\273\201 m\341\272\267c \304\221\341\273\213nh c\341\273\247a nh\303\240 s\341\272\243n xu\341\272\245t.\n"
"Sau khi th\341\273\261c hi\341\273\207n, to\303\240n b\341\273\231 t\303\240i kho\341\272\243n hi\341\273\207n t\341\272\241i s\341\272\275 \304\221\306\260\341\273\243c x\303\263a kh\341\273\217i c\306\241 s\341\273\237 d\341\273\257 li\341\273\207u v\303\240 c\303\241c t\303\240i kho\341\272\243n m\341\272\267c \304\221\341\273\213nh s\341\272\275 \304\221\306\260\341\273\243c kh\303\264i ph\341\273\245c.\n"
"N\341\272\277u kh\303\264ng nh\341\273\233 m\341\272\255t kh\341\272\251u \"root\" h\303\243y li\303\252n h\341\273\207 v\341\273\233i nh\303\240 s\341\272\243n xu\341\272\245t.", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QCoreApplication::translate("FrmAccountSetup", "Thi\341\272\277t l\341\272\255p m\341\272\267c \304\221\341\273\213nh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmAccountSetup: public Ui_FrmAccountSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMACCOUNTSETUP_H
