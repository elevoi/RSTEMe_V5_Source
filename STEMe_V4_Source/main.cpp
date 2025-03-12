#include "mainwindow.h"

#include <QApplication>
#include "root/frmlogin.h"
#include "practice/frmsensorpracticebase.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FrmLogin login;

    //auto _font = QGuiApplication::font();
    //_font.setFamily("Times New Roman");
    //QGuiApplication::setFont(_font);

    //MainWindow w;
    //w.show();
    login.show();
    //FrmSensorPracticeBase _practice;
    //_practice.show();
    return a.exec();
}
