#ifndef FRMSENSORDISPLAYCLOCK_H
#define FRMSENSORDISPLAYCLOCK_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QCloseEvent>
#include <QResizeEvent>
#include <QSize>
#include <QRect>
#include "device/edevice.h"
#include "device/def/esensor.h"
#include "device/def/edeviceparameter.h"
#include "device/frmaddsensor.h"
#include "control/frmdeviceconfig.h"

namespace Ui {
class FrmSensorDisplayClock;
}

class FrmSensorDisplayClock : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmSensorDisplayClock(QWidget *parent = nullptr);
    ~FrmSensorDisplayClock();

    void setDevice(EDevice *dev);
    inline EDevice* device(){return m_edevice;}


protected:
  //  virtual void paintEvent(QPaintEvent *event);
    //void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;

private slots:
    void on_newData(int id);

    void on_spinBox_rangeMin_valueChanged(int arg1);

    void on_spinBox_rangeMax_valueChanged(int arg1);

    void on_comboBox_unit_currentIndexChanged(int index);

    void on_toolButton_config_clicked();

    void on_toolButton_info_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::FrmSensorDisplayClock *ui;

    EDevice *m_edevice = nullptr;
    ESensor *m_esensor = nullptr;
    EDeviceParameter m_para;

    FrmAddSensor *m_frmAddSensor = nullptr;
    FrmDeviceConfig *m_frmDeviceConfig = nullptr;

    //draw clock
    qreal m_angleStart=225,m_angleSpan=90;
    QPoint m_origin;
    QRect m_rectClock;
    int m_sizeRect=0;
    //Parameter
    qreal m_rangeMin = 0;
    qreal m_rangeMax = 100;
    qreal m_value = 0;


    QRect m_mainRect = QRect(1,1,1,1);
    QSize m_graphicSize = QSize(1,1);

    QGraphicsScene *m_sceneClock;
    QGraphicsRectItem *m_recItem;
    QGraphicsTextItem *m_textItem;
    QGraphicsLineItem *m_needleClock;
    QGraphicsEllipseItem *m_originClock;
    QList<QGraphicsTextItem*> m_lstTextItem;

    void initDisplay();
    void setValue();

    void drawClock();
    void drawBackground(QGraphicsScene *scene,QRect rect);
    void drawShotLineArc(QGraphicsScene *scene,QPen pen,QPoint origin,qreal degree,qreal radius,qreal percent);
    void drawMeasureText(QString text,QGraphicsScene *scene,QPoint origin,qreal degree, qreal radius);
    void updateMeasureText();
    void drawNeedleClock();
};


#endif // FRMSENSORDISPLAYCLOCK_H
