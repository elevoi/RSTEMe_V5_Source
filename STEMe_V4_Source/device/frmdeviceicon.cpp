#include "frmdeviceicon.h"
#include "ui_frmdeviceicon.h"
#include <QListWidget>
#include <QDir>
#include <QDebug>

FrmDeviceIcon::FrmDeviceIcon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDeviceIcon)
{
    ui->setupUi(this);
    m_rectPushOk = ui->pushButton_Select->geometry();
    m_rectPushCancel = ui->pushButton_Cancel->geometry();
    m_sizeMainWindow = this->size();

    m_sizeListWidget = ui->listWidget_Icon->size();


    this->loadIcon();
}

FrmDeviceIcon::~FrmDeviceIcon()
{
    delete ui;
}

void FrmDeviceIcon::on_pushButton_Cancel_clicked()
{
    this->close();
}

void FrmDeviceIcon::resizeEvent(QResizeEvent *)
{
    int del_h = this->size().height() - m_sizeMainWindow.height();
    int del_w = this->size().width() - m_sizeMainWindow.width();
    ui->listWidget_Icon->resize(m_sizeListWidget.width()+del_w,m_sizeListWidget.height()+del_h);

    ui->pushButton_Select->setGeometry(QRect(m_rectPushOk.x()+del_w,m_rectPushOk.y()+del_h,m_rectPushOk.width(),m_rectPushOk.height()));
    ui->pushButton_Cancel->setGeometry(QRect(m_rectPushCancel.x()+del_w,m_rectPushCancel.y()+del_h,m_rectPushCancel.width(),m_rectPushCancel.height()));

    this->loadIcon();
}

void FrmDeviceIcon::loadIcon()
{
    //assume the directory exists and contains some files and you want all jpg and JPG files
    QDir directory(":/sensor/image");
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.JPG" << "*.png" << "*.PNG",QDir::Files);
    ui->listWidget_Icon->setViewMode(QListWidget::IconMode);
    ui->listWidget_Icon->setIconSize(QSize(75,75));
    ui->listWidget_Icon->clear();
    m_iconListPath.clear();

    foreach(QString filename, images) {
    //do whatever you need to do
        QString _path = ":/sensor/image/"+filename;
        m_iconListPath.append(_path);
        ui->listWidget_Icon->addItem(new QListWidgetItem(QIcon(_path),NULL));
    }

}


void FrmDeviceIcon::on_listWidget_Icon_itemClicked(QListWidgetItem *item)
{
    m_iconPath = m_iconListPath.at(ui->listWidget_Icon->row(item));
}


void FrmDeviceIcon::on_listWidget_Icon_itemDoubleClicked(QListWidgetItem *item)
{
    emit setIcon(m_iconListPath.at(ui->listWidget_Icon->row(item)));
    this->close();
}



void FrmDeviceIcon::on_pushButton_Select_clicked()
{
    emit setIcon(m_iconPath);
    this->close();
}

