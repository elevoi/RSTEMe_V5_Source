#include "frmsensordisplayclock.h"
#include "ui_frmsensordisplayclock.h"
#include <QPainter>
#include <QPainterPath>
#include <QtMath>
#include <qmath.h>
#include <QDebug>
#include <QBrush>
#include <QLineEdit>

FrmSensorDisplayClock::FrmSensorDisplayClock(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmSensorDisplayClock)
{
    ui->setupUi(this);
    m_mainRect = this->geometry();
    m_graphicSize = ui->graphicsView_backgroundClock->size();

    QLineEdit *_lde = ui->comboBox_unit->lineEdit();
    _lde->setObjectName("LineEdit");
    QString _style = ("QLineEdit{\
                        color: rgb(2, 87, 122);\
                        background-color: rgb(255, 255 ,255);\
                        border: none;\
                        border-style: outset;\
                        border-top-left-radius: 15px;\
                        border-bottom-left-radius: 15px;\
                        }\
                        QLineEdit:hover{\
                        background-color: rgb(25, 149, 173);\
                        color: rgb(255, 255, 255);\
                        }");
    _lde->setAlignment(Qt::AlignHCenter);
    _lde->setFont(QFont("Segoe UI",10,QFont::Bold));
    _lde->setStyleSheet(_style);
    ui->comboBox_unit->setLineEdit(_lde);
    m_sceneClock = new QGraphicsScene(this);
    m_needleClock = new QGraphicsLineItem();
    m_originClock = new QGraphicsEllipseItem();
    ui->graphicsView_backgroundClock->setScene(m_sceneClock);
    this->drawClock();
}

FrmSensorDisplayClock::~FrmSensorDisplayClock()
{
    if(m_esensor){
    QObject::disconnect(m_esensor,&ESensor::newData,this,&FrmSensorDisplayClock::on_newData);
    m_esensor->deleteLater();
    m_esensor = nullptr;
    }
    delete ui;
}

void FrmSensorDisplayClock::setDevice(EDevice *dev)
{
    m_edevice = dev;
    this->setWindowTitle(dev->deviceInfo().name() + "(@" + dev->deviceInfo().serialHex() + ")");
    ui->label_Name->setText(dev->deviceInfo().name());
    m_esensor = new ESensor(this,m_edevice);
    m_esensor->start();
    //init Display
    this->initDisplay();
    QObject::connect(m_esensor,&ESensor::newData,this,&FrmSensorDisplayClock::on_newData);
}

void FrmSensorDisplayClock::initDisplay()
{
    m_para = m_esensor->parameter();
    this->setValue();
    //name
    ui->label_Name->setText(m_esensor->device()->deviceInfo().name());
    QIcon my_icon;
    my_icon.addPixmap(QPixmap(m_esensor->device()->deviceInfo().icon()), QIcon::Normal);
    my_icon.addPixmap(QPixmap(m_esensor->device()->deviceInfo().iconOn()), QIcon::Active);
    ui->toolButton_info->setIcon(my_icon);
    //unit
    ui->comboBox_unit->clear();
    for(int i=0;i<m_para.unit().count();i++){
        ui->comboBox_unit->addItem(m_para.unit().at(i).name);
    }
    //para
   // m_rangeMax = m_para.clock().rangeMax;
    ui->spinBox_rangeMax->setValue(m_para.clock().rangeMax);
    ui->spinBox_rangeMin->setValue(m_para.clock().rangeMin);
   // m_rangeMax = m_para.clock().rangeMin;
}

void FrmSensorDisplayClock::setValue()
{
    m_para = m_esensor->parameter();
    m_value = m_para.value();
    this->drawNeedleClock();
}

void FrmSensorDisplayClock::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
}

void FrmSensorDisplayClock::on_newData(int)
{
    //value
    this->setValue();
}

void FrmSensorDisplayClock::drawClock()
{
    if(!m_sceneClock){
        m_sceneClock = new QGraphicsScene(this);
        ui->graphicsView_backgroundClock->setScene(m_sceneClock);
    }
    m_rectClock = QRect(20,20,ui->graphicsView_backgroundClock->geometry().width()-40,ui->graphicsView_backgroundClock->geometry().height()-40);
    this->drawBackground(m_sceneClock,m_rectClock);
    this->drawNeedleClock();
}

void FrmSensorDisplayClock::drawBackground(QGraphicsScene *scene,QRect rect)
{
    int _lineWith = 3;
    int _tickNumber=40;
QPen _pen(Qt::black);
QPen _penOrigin(Qt::black);
_pen.setWidth(_lineWith);
_penOrigin.setWidth(rect.width()*0.04);
m_origin.setX(rect.x()+(rect.width()/2));
m_origin.setY(rect.y()+rect.height());
if(rect.width()>rect.height())m_sizeRect = rect.height();
    else m_sizeRect = rect.width();

for(int i=0;i<=_tickNumber;i++){
    qreal _angle = i*(m_angleSpan/_tickNumber)+m_angleStart;
    this->drawShotLineArc(scene,QPen(Qt::black,1,Qt::SolidLine,Qt::FlatCap),m_origin,_angle,m_sizeRect*0.7,0.05);
    if(i%2==0)this->drawShotLineArc(scene,QPen(Qt::black,2,Qt::SolidLine,Qt::FlatCap),m_origin,_angle,m_sizeRect*0.7,0.07);
    if(i%10==0){
        this->drawShotLineArc(scene,QPen(Qt::black,4,Qt::SolidLine,Qt::FlatCap),m_origin,_angle,m_sizeRect*0.7,0.1);
        int value = (int)(((_angle-m_angleStart)*(m_rangeMax-m_rangeMin)/m_angleSpan)+m_rangeMin);
        this->drawMeasureText(QString::number(value),scene,m_origin,_angle,m_sizeRect*0.85);
    }
}
m_needleClock = m_sceneClock->addLine(0,0,0,0,_pen);
m_originClock = m_sceneClock->addEllipse(QRect(m_origin.x()-(m_sizeRect*0.02),m_origin.y()-(m_sizeRect*0.02),m_sizeRect*0.04,m_sizeRect*0.04),QPen(Qt::black,15));
    //draw origin

}

void FrmSensorDisplayClock::drawShotLineArc(QGraphicsScene *scene,QPen pen,QPoint origin,qreal degree, qreal radius,qreal percent)
{
    qreal _x1=0,_y1=0,_x2=0,_y2=0;
    qreal rad =  (degree*M_PI)/180;
    _x1 = (int)(radius*cos(rad))+origin.x();
    _y1 = (int)(radius*sin(rad))+origin.y();
    _x2 = (int)(radius*(1+percent)*cos(rad))+origin.x();  //length shorter 10%
    _y2 = (int)(radius*(1+percent)*sin(rad))+origin.y();
    scene->addLine(_x1,_y1,_x2,_y2,pen);
}

void FrmSensorDisplayClock::drawMeasureText(QString text,QGraphicsScene *scene,QPoint origin,qreal degree, qreal radius)
{
qreal _x,_y;
qreal rad;
m_textItem = scene->addText(text,QFont("Segoe UI",0.04*radius,QFont::Bold));
//m_textItem->setPos(_x-(m_textItem->boundingRect().width()/2.5),_y-(m_textItem->boundingRect().width()/2.5));//2.83 = 2*sqrt(2)
qreal _del = degree-m_textItem->toPlainText().size()*1.2;
m_textItem->setRotation(degree+90);
rad =  (_del*M_PI)/180;
_x = (int)(radius*cos(rad))+origin.x();
_y = (int)(radius*sin(rad))+origin.y();
m_textItem->setPos(_x,_y);//2.83 = 2*sqrt(2)
m_lstTextItem.append(m_textItem);
}

void FrmSensorDisplayClock::updateMeasureText()
{
    if(!m_sceneClock)return;
    int _tickNumber=40;
    foreach (QGraphicsTextItem *var, m_lstTextItem) {
        m_lstTextItem.removeOne(var);
        delete var;
    }
    for(int i=0;i<=_tickNumber;i++){
        qreal _angle = i*(m_angleSpan/_tickNumber)+m_angleStart;
        if(i%10==0){
            int value = (int)(((_angle-m_angleStart)*(m_rangeMax-m_rangeMin)/m_angleSpan)+m_rangeMin);
            this->drawMeasureText(QString::number(value),m_sceneClock,m_origin,_angle,m_sizeRect*0.85);
        }
    }
    this->drawNeedleClock();
}

void FrmSensorDisplayClock::drawNeedleClock()
{
    if(!m_sceneClock)return;
    qreal _x1=0,_y1=0,_x2=0,_y2=0;
    qreal rad;
    qreal valNeedle = 0;
    qreal radius = m_sizeRect*0.8;
    QPen pen(Qt::red);
    pen.setWidth(2);
    //cal value
    if(m_value<m_rangeMin)m_value = m_rangeMin;
    if(m_value>m_rangeMax)m_value = m_rangeMax;
    //valNeedle = (m_value*m_angleSpan)/(m_rangeMax-m_rangeMin)+m_angleStart;
    valNeedle = (m_angleSpan*(m_value-m_rangeMin))/(m_rangeMax-m_rangeMin)+m_angleStart;
    rad =  (valNeedle*M_PI)/180;
    _x1 = (int)(radius*cos(rad))+m_origin.x();
    _y1 = (int)(radius*sin(rad))+m_origin.y();
    _x2 = -(int)(radius*0.1*cos(rad))+m_origin.x();  //length shorter 10%
    _y2 = -(int)(radius*0.1*sin(rad))+m_origin.y();
    m_sceneClock->removeItem(m_needleClock);
    m_needleClock = m_sceneClock->addLine(_x1,_y1,_x2,_y2,pen);
    m_sceneClock->removeItem(m_originClock);
    m_originClock = m_sceneClock->addEllipse(QRect(m_origin.x()-(m_sizeRect*0.02),m_origin.y()-(m_sizeRect*0.02),m_sizeRect*0.04,m_sizeRect*0.04),QPen(Qt::red,15));
}


void FrmSensorDisplayClock::on_spinBox_rangeMin_valueChanged(int arg1)
{
    m_rangeMin = arg1;
    this->updateMeasureText();
}


void FrmSensorDisplayClock::on_spinBox_rangeMax_valueChanged(int arg1)
{
    m_rangeMax = arg1;
    this->updateMeasureText();
}

void FrmSensorDisplayClock::on_comboBox_unit_currentIndexChanged(int index)
{
    if(index<0)return;
    m_para = m_esensor->parameter();
    m_value = m_para.value();
    m_para.setCurrentUnit(m_para.unit().at(index));
    m_esensor->setParameter(m_para);
}


void FrmSensorDisplayClock::on_toolButton_config_clicked()
{
    if(!m_esensor)return;
    if(!m_frmDeviceConfig){
        m_frmDeviceConfig = new FrmDeviceConfig(this);
        m_frmDeviceConfig->setSensor(m_esensor);
        m_frmDeviceConfig->setWindowIcon(QIcon(m_esensor->device()->deviceInfo().icon()));
    }
    m_frmDeviceConfig->show();
    m_frmDeviceConfig->activateWindow();
}


void FrmSensorDisplayClock::on_toolButton_info_clicked()
{
    if(!m_edevice)return;
    if(!m_frmAddSensor)m_frmAddSensor = new FrmAddSensor(this,m_edevice->deviceInfo());
    m_frmAddSensor->setAutoFillBackground(false);
    m_frmAddSensor->setWindowTitle("Thêm thiết bị");
    m_frmAddSensor->show();
}


void FrmSensorDisplayClock::on_pushButton_cancel_clicked()
{
    this->close();
}

