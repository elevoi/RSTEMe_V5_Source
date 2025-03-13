#ifndef ECHARTVIEW_H
#define ECHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
#include <QtGui/QMouseEvent>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QLineSeries>
#include <QWheelEvent>

#include <chart/echartcallout.h>
#include <chart/echartcrosshair.h>

QT_CHARTS_USE_NAMESPACE

class EChartView : public QChartView
{
public:
    EChartView(QChart *chart, QWidget *parent = nullptr);

    struct EMouseEvent{
        QPointF value;
        QPointF position;
    };
    enum ETrackLine{
        ETL_CROSSHAIR,
        ETL_CALLOUT,
        ETL_y_ax
    };

    //
    inline QPointF getWidgetPos(){return m_widgetPos;}
    inline QPointF getPositionMouse(){return m_positionMouse;}
    inline EMouseEvent emouseEvent(){return m_emouseEvent;}
    void setTrackLine(ETrackLine track);
    void setPrecisionXY(int x, int y){m_pre_X=x;m_pre_Y=y;}
    void clearTrackLine();

    //chart
    void updateSeries(QLineSeries *series);
    void removeSeries(QLineSeries *series);
    void updateSeries(QSplineSeries *series);
    void removeSeries(QSplineSeries *series);



public slots:

//![2]
protected:
    bool viewportEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void resizeEvent(QResizeEvent *event);
//![2]

private:

    bool m_isTouching;
    QPointF m_positionMouse={0,0};
    QPointF m_positionMouseLast{0,0};
    QPointF m_widgetPos={0,0};
    int m_seriesIndex=0;
    EMouseEvent m_emouseEvent;
    bool m_rightMousePress = false;
    bool m_mouseMove = false;
    int m_rightMouseCount = 0;

    //bool m_leftMousePress = false;
    //bool m_leftMouseHold = false;
    //int m_leftMouseCount = 0;
    ETrackLine m_etrackLine = ETL_CROSSHAIR;
//For Ecallout
    EChartCallout *m_callout=nullptr;
    QList<EChartCallout *> m_listCallouts;
    EChartCrosshair *m_crosshairs=nullptr;
    int m_pre_X=3,m_pre_Y=3;

    int getMax(int x,int y);

    //Mouse
    void mouseRightPress(QPointF pos);
    void mouseLeftPress(QPointF pos);
    void mouseMiddlePress(QPointF pos);
    void mouseRightRelease(QPointF pos);
    void mouseLeftRelease(QPointF pos);
    void mouseMiddleRelease(QPointF pos);

    //map
    QPointF mapToSeries(QLineSeries *series, QPointF pos);

    //Callout
    void newCallout(QLineSeries *series,QPointF point, bool state);
    void keepCallout();
    void refreshCallout();
    void removeCallout();
    void removeCallout(QLineSeries *series);
    void clearCallout();

    void chartResize();
};

#endif // ECHARTVIEW_H
