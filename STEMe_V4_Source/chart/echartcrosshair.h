#ifndef ECHARTCROSSHAIR_H
#define ECHARTCROSSHAIR_H
#include <QtCharts/QChartGlobal>
#include <QtWidgets/QGraphicsItem>
#include <QtCharts/QLineSeries>
#include <QValueAxis>


QT_CHARTS_BEGIN_NAMESPACE
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class EChartCrosshair
{
public:
    EChartCrosshair(QChart *chart);
    void updatePosition(QPointF position);
    void updatePosition(QPointF position,int x,int y);
    void hide();

private:
    QGraphicsLineItem *m_xLine, *m_yLine;
    QGraphicsTextItem *m_xText, *m_yText;
    QList<QGraphicsTextItem*> m_listYText;
    QChart *m_chart;
    QPointF mapToSeries(QValueAxis *axis, QPointF pos);
};

#endif // ECHARTCROSSHAIR_H
