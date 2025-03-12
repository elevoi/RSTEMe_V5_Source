#ifndef ECHARTCALLOUT_H
#define ECHARTCALLOUT_H

#include <QtCharts/QChartGlobal>
#include <QtWidgets/QGraphicsItem>
#include <QtGui/QFont>
#include <QtCharts/QLineSeries>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class EChartCallout : public QGraphicsItem
{
public:
    EChartCallout(QChart *parent);

    void setText(const QString &text);
    void setAnchor(QPointF point);

    inline QLineSeries *series(){return m_series;}
    inline void setSeries(QLineSeries *var){m_series = var;}
    void updateGeometry();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    QString m_text;
    QRectF m_textRect;
    QRectF m_rect;
    QPointF m_anchor;
    QFont m_font;
    QChart *m_chart;
    QLineSeries *m_series = nullptr;
};

#endif // ECHARTCALLOUT_H
