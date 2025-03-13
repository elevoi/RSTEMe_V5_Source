#include "echartcrosshair.h"
#include <QtCharts/QChart>
#include <QtGui/QPainter>
#include <QtGui/QCursor>
#include <QtGui/QTextDocument>
#include <QDebug>

QT_CHARTS_USE_NAMESPACE
EChartCrosshair::EChartCrosshair(QChart *chart):
    m_xLine(new QGraphicsLineItem(chart)),
    m_yLine(new QGraphicsLineItem(chart)),
    m_xText(new QGraphicsTextItem(chart)),
    m_yText(new QGraphicsTextItem(chart)),
    m_chart(chart)
{
    m_xLine->setPen(QPen(QColor(0, 255, 255), 1,Qt::DashLine));
    m_yLine->setPen(QPen(QColor(0, 255, 255), 1,Qt::DashLine));
    m_xText->setZValue(9);
    m_yText->setZValue(9);
    auto font = m_xText->font();
    font.setPointSize(9);
    font.setBold(true);
    m_xText->setFont(font);
    m_yText->setFont(font);
    m_xText->document()->setDocumentMargin(0);
    m_yText->document()->setDocumentMargin(0);
    m_xText->setDefaultTextColor(QColor(0, 255, 255));
    m_yText->setDefaultTextColor(QColor(0, 255, 255));

}


void EChartCrosshair::updatePosition(QPointF position)
{
    this->updatePosition(position,0,0);
}

void EChartCrosshair::updatePosition(QPointF position, int x, int y)
{
    foreach (auto var, m_listYText) {
        m_listYText.removeOne(var);
        var->deleteLater();
        var = nullptr;
    }
    if(m_yText){m_yText->deleteLater();m_yText = nullptr;}
    QLineF xLine(position.x(), m_chart->plotArea().top(),
                 position.x(), m_chart->plotArea().bottom());
    QLineF yLine(m_chart->plotArea().left(), position.y(),
                 m_chart->plotArea().right(), position.y());
    m_xLine->setLine(xLine);
    m_yLine->setLine(yLine);
    QString xText = QString(" %1 ").arg(QString::number(m_chart->mapToValue(position).x(),'f',x));
    m_xText->setHtml(QString("<div style='background-color: #000000;'>") + xText + "</div>");
    m_xText->setPos(position.x() - m_xText->boundingRect().width() / 2.0, m_chart->plotArea().bottom());

    qreal pText = 0;
    for(int i=0;i<m_chart->axes(Qt::Vertical).count();i++){
        auto p = this->mapToSeries(dynamic_cast<QValueAxis*>(m_chart->axes(Qt::Vertical).at(i)),position);
        QString yText = QString(" %1 ").arg(QString::number(p.y(),'f',y));

        m_yText = new QGraphicsTextItem(m_chart);
        m_listYText.append(m_yText);
        m_yText->setZValue(9);
        auto font = m_xText->font();
        font.setPointSize(9);
        font.setBold(true);
        m_yText->setFont(font);
        m_yText->document()->setDocumentMargin(0);
        m_yText->setDefaultTextColor(QColor(0, 255, 255));
        m_yText->setHtml(QString("<div style='background-color: #000000;'>") + yText + "</div>");
        m_yText->setPos(m_chart->plotArea().left() - pText - m_yText->boundingRect().width(), position.y() - m_yText->boundingRect().height() / 2.0);
        pText += (m_chart->plotArea().left()-30)/m_chart->axes(Qt::Vertical).count();
    }

   /* foreach (auto var, m_chart->series()) {
        auto seri = dynamic_cast<QLineSeries*>(var);
        seri->pen().data_ptr();
    }*/

    if (!m_chart->plotArea().contains(position))
    {
        m_xLine->hide();
        m_xText->hide();
        m_yLine->hide();
        foreach (auto var, m_listYText) var->hide();
    }
    else
    {
        m_xLine->show();
        m_xText->show();
        m_yLine->show();
        foreach (auto var, m_listYText) var->show();
    }
}
/*
    QLineF xLine(position.x(), m_chart->plotArea().top(),
                 position.x(), m_chart->plotArea().bottom());
    QLineF yLine(m_chart->plotArea().left(), position.y(),
                 m_chart->plotArea().right(), position.y());
    m_xLine->setLine(xLine);
    m_yLine->setLine(yLine);
    QString xText = QString(" %1 ").arg(QString::number(m_chart->mapToValue(position).x(),'f',x)),
            yText = QString(" %1 ").arg(QString::number(m_chart->mapToValue(position).y(),'f',y));
    m_xText->setHtml(QString("<div style='background-color: #000000;'>") + xText + "</div>");
    m_yText->setHtml(QString("<div style='background-color: #000000;'>") + yText + "</div>");
    m_xText->setPos(position.x() - m_xText->boundingRect().width() / 2.0, m_chart->plotArea().bottom());
    m_yText->setPos(m_chart->plotArea().left()-m_yText->boundingRect().width(), position.y() - m_yText->boundingRect().height() / 2.0);

    if (!m_chart->plotArea().contains(position))
    {
        m_xLine->hide();
        m_xText->hide();
        m_yLine->hide();
        m_yText->hide();
    }
    else
    {
        m_xLine->show();
        m_xText->show();
        m_yLine->show();
        m_yText->show();
    }
 */
void EChartCrosshair::hide()
{
    m_xLine->hide();
    m_xText->hide();
    m_yLine->hide();
    m_yText->hide();
}

QPointF EChartCrosshair::mapToSeries(QValueAxis *axis, QPointF pos)
{
    QPointF _p(0,0);
    pos = m_chart->mapToValue(pos);
    QPointF _top = m_chart->mapToValue(QPointF(0,m_chart->plotArea().top()));
    QPointF _bot = m_chart->mapToValue(QPointF(0,m_chart->plotArea().bottom()));
    qreal _a = (axis->max()-axis->min())/(_top.y()-_bot.y());
    qreal _b = axis->max() - _top.y()*_a;
    _p.setX(pos.x());
    _p.setY(_a*pos.y()+_b);
    return _p;
}

