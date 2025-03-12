#include "echartview.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QValueAxis>

EChartView::EChartView(QChart *chart, QWidget *parent):QChartView(chart,parent),m_isTouching(false)
{
        setRubberBand(QChartView::RectangleRubberBand);
        //setRubberBand(QChartView::NoRubberBand);
        setDragMode(QGraphicsView::NoDrag);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        this->setMouseTracking(true);
        this->setTrackLine(m_etrackLine);
}


void EChartView::updateSeries(QLineSeries *series)
{
if(!this->chart())return;
QObject::connect(series,&QLineSeries::hovered,this,[this,series](const QPointF &point, bool state){
    this->newCallout(series,point,state);
});

}

void EChartView::removeSeries(QLineSeries *series)
{
if(!this->chart())return;
QObject::disconnect(series,&QLineSeries::hovered,this,nullptr);
if(m_etrackLine==ETrackLine::ETL_CALLOUT)this->removeCallout(series);
}

void EChartView::updateSeries(QSplineSeries *series)
{
    this->updateSeries((QLineSeries*)series);
}

void EChartView::removeSeries(QSplineSeries *series)
{
this->removeSeries((QLineSeries*)series);
}


void EChartView::setTrackLine(EChartView::ETrackLine track)
{
    if(!this->chart())return;
    this->clearTrackLine();
    m_etrackLine = track;
    if(!m_crosshairs)m_crosshairs = new EChartCrosshair(this->chart());
}

void EChartView::clearTrackLine()
{
    //if(m_crosshairs)m_crosshairs->hide();
    this->clearCallout();
}

void EChartView::keepCallout()
{
    if(!m_callout)return;
        if(m_callout->isVisible()){
            m_listCallouts.append(m_callout);
            m_callout = new EChartCallout(chart());
            m_callout->hide();
            }
}

void EChartView::refreshCallout()
{
    foreach (auto var, m_listCallouts) {
        var->updateGeometry();
    }
}

void EChartView::removeCallout()
{
    if(m_listCallouts.count()>0){
        auto _call = m_listCallouts.last();
        m_listCallouts.removeOne(_call);
        delete _call;
    }
}

void EChartView::removeCallout(QLineSeries *series)
{
    foreach (auto var, m_listCallouts) {
        if(var->series()==series){
            m_listCallouts.removeOne(var);
            delete var;
        }
    }
    this->refreshCallout();
}

void EChartView::clearCallout()
{
    foreach (auto var, m_listCallouts) {
        m_listCallouts.removeOne(var);
        delete var;
    }
}

void EChartView::newCallout(QLineSeries *series,QPointF point, bool state)
{
    if(m_etrackLine!=ETrackLine::ETL_CALLOUT)return;
    if(!m_callout)m_callout = new EChartCallout(chart());
    if (state) {
        m_callout->setText(QString("X: %1 \nY: %2 ").arg(QString::number(point.x()),QString::number(point.y())));
        m_callout->setAnchor(point);
        m_callout->setZValue(11);
        m_callout->updateGeometry();
        m_callout->setSeries(series);
        m_callout->show();
    } else m_callout->hide();

}

bool EChartView::viewportEvent(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin) {
        // By default touch events are converted to mouse events. So
        // after this event we will get a mouse event also but we want
        // to handle touch events as gestures only. So we need this safeguard
        // to block mouse events that are actually generated from touch.
        m_isTouching = true;

        // Turn off animations when handling gestures they
        // will only slow us down.
        chart()->setAnimationOptions(QChart::NoAnimation);
    }
    return QChartView::viewportEvent(event);
}

void EChartView::mousePressEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;
    if(event->button()==Qt::MouseButton::MiddleButton){
        mouseMiddlePress(event->localPos());
    }else if(event->button()==Qt::MouseButton::LeftButton){
        mouseLeftPress(event->localPos());
        QChartView::mousePressEvent(event);
    }else if(event->button()==Qt::MouseButton::RightButton){
        mouseRightPress(event->localPos());
    }
  //  switch(event->mou
}

void EChartView::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;
    m_widgetPos = event->localPos();
    auto const scenePos = mapToScene(QPoint(static_cast<int>(m_widgetPos.x()), static_cast<int>(m_widgetPos.y())));
    auto const chartItemPos = chart()->mapFromScene(scenePos);
    m_positionMouse = chart()->mapToValue(chartItemPos);
    //trackLine

    if(m_crosshairs){
            m_crosshairs->updatePosition(event->pos(),m_pre_X,m_pre_Y);
        }
    if((m_etrackLine==ETrackLine::ETL_CALLOUT)&&m_callout){
        m_callout->setText(QString("X: %1 \nY: %2 ").arg(QString::number(m_positionMouse.x(),'f',3),QString::number(m_positionMouse.y(),'f',3)));
        m_callout->setAnchor(m_positionMouse);
        m_callout->updateGeometry();
        }
    if(m_rightMousePress){
        if(m_rightMouseCount++>5){
            chart()->scroll(m_positionMouseLast.x()-m_widgetPos.x(),m_widgetPos.y()-m_positionMouseLast.y());
            m_positionMouseLast = m_widgetPos;
            m_rightMouseCount = 0;
            }
        if(m_positionMouseLast.x()!=m_widgetPos.x()&&m_widgetPos.y()!=m_positionMouseLast.y())m_mouseMove=true;
    }
    QChartView::mouseMoveEvent(event);
}

void EChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_isTouching)
        m_isTouching = false;

    // Because we disabled animations when touch event was detected
    // we must put them back on.
    chart()->setAnimationOptions(QChart::SeriesAnimations);
    if(event->button()==Qt::MouseButton::MiddleButton){
        mouseMiddleRelease(event->localPos());
    }else if(event->button()==Qt::MouseButton::LeftButton){
        mouseLeftRelease(event->localPos());
        QChartView::mouseReleaseEvent(event);
    }else if(event->button()==Qt::MouseButton::RightButton){
        mouseRightRelease(event->localPos());
    }

}


//![1]
void EChartView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        chart()->zoomIn();
        break;
    case Qt::Key_Minus:
        chart()->zoomOut();
        break;
    case Qt::Key_Enter:
        chart()->zoomReset();
        break;
//![1]
    case Qt::Key_Left:
        chart()->scroll(-10, 0);
        break;
    case Qt::Key_Right:
        chart()->scroll(10, 0);
        break;
    case Qt::Key_Up:
        chart()->scroll(0, 10);
        break;
    case Qt::Key_Down:
        chart()->scroll(0, -10);
        break;
    default:
       // QGraphicsView::keyPressEvent(event);
        QChartView::keyPressEvent(event);
        break;
    }
    this->chartResize();
}

void EChartView::wheelEvent(QWheelEvent *event)
{
        QPoint angle = event->angleDelta();
        if(angle.y()>0)chart()->zoomIn();
            else chart()->zoomOut();
        this->chartResize();
        event->accept();
}

void EChartView::resizeEvent(QResizeEvent *event)
{
    this->chartResize();
    QChartView::resizeEvent(event);
}

int EChartView::getMax(int x, int y)
{
if(x>y)return x;
return y;
}


void EChartView::chartResize()
{
    if(m_etrackLine==ETrackLine::ETL_CALLOUT)this->refreshCallout();
}

//==========================================================================Mouse
void EChartView::mouseRightPress(QPointF pos)
{
    m_rightMousePress = true;
    m_positionMouseLast = pos;//hold mouse
}

void EChartView::mouseLeftPress(QPointF)
{

}

void EChartView::mouseMiddlePress(QPointF)
{

}

void EChartView::mouseRightRelease(QPointF)
{
    m_rightMousePress = false;
    if((m_etrackLine==ETrackLine::ETL_CALLOUT)&&(!m_mouseMove))this->removeCallout();
    m_mouseMove=false;
}

void EChartView::mouseLeftRelease(QPointF)
{
if(m_etrackLine==ETrackLine::ETL_CALLOUT)this->keepCallout();
m_mouseMove=false;
}

void EChartView::mouseMiddleRelease(QPointF)
{
chart()->zoomReset();
if(m_etrackLine==ETrackLine::ETL_CALLOUT)this->clearCallout();
m_mouseMove=false;
}

QPointF EChartView::mapToSeries(QLineSeries *series, QPointF pos)
{
    QPointF _p(0,0);
    pos = chart()->mapToValue(pos);
    foreach (auto var, series->attachedAxes()) {
       if(var->orientation()==Qt::Vertical){
           QValueAxis *_axisY = dynamic_cast<QValueAxis*>(var);
           QPointF _top = chart()->mapToValue(QPointF(0,chart()->plotArea().top()));
           QPointF _bot = chart()->mapToValue(QPointF(0,chart()->plotArea().bottom()));
           qreal _a = (_axisY->max()-_axisY->min())/(_top.y()-_bot.y());
           qreal _b = _axisY->max() - _top.y()*_a;
           _p.setX(pos.x());
           _p.setY(_a*pos.y()+_b);
       }
    }
    return _p;
}

