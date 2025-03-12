#include "frmsensorpracticesoundwave.h"
#include "ui_frmsensorpracticesoundwave.h"

FrmSensorPracticeSoundWave::FrmSensorPracticeSoundWave(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmSensorPracticeSoundWave)
{
    ui->setupUi(this);
    m_formResize.window = this->size();
    m_formResize.graphicView = ui->graphicsViewChart->size();
    m_formResize.frameToolTrack = ui->frame_toolTrack->size();
    m_formResize.frameToolSetup = ui->frame_toolSetup->size();
    m_formResize.frameControl = ui->frame_Control->geometry();
    m_formResize.framePlay = ui->frame_play->geometry();

    //status play
    this->setToolControl(m_chartPara.play);
}

FrmSensorPracticeSoundWave::~FrmSensorPracticeSoundWave()
{
    this->removeSensor();
    delete ui;
}

void FrmSensorPracticeSoundWave::setDevice(EDevice *dev)
{
    if(m_edevice==dev)return;
        m_edevice = dev;
        m_esensor = new ESensor(this,dev);
        QObject::connect(m_esensor,&ESensor::newDataDevice,this,&FrmSensorPracticeSoundWave::on_newDataDevice);
        m_esensor->start();
        this->chartInit();
        this->chartViewUpdate();
    //
    QString  _str = " ( @" + m_edevice->deviceInfo().name() + ")";
    this->setWindowTitle(_str);
}

void FrmSensorPracticeSoundWave::removeDevice(EDevice *dev)
{
    if(dev!=m_edevice)return;
    this->removeSensor();
    m_edevice = nullptr;
}

void FrmSensorPracticeSoundWave::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void FrmSensorPracticeSoundWave::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    // Your code here.
    int del_h = this->size().height() - m_formResize.window.height();
    int del_w = this->size().width() - m_formResize.window.width();
    if(del_h<0)del_h=0;
    if(del_w<0)del_w=0;
    ui->graphicsViewChart->resize(m_formResize.graphicView.width()+del_w,m_formResize.graphicView.height()+del_h);
    ui->frame_toolTrack->resize(m_formResize.frameToolTrack.width(),m_formResize.frameToolTrack.height()+del_h);

    ui->frame_toolSetup->resize(m_formResize.frameToolSetup.width()+del_w,m_formResize.frameToolSetup.height());

    ui->frame_play->setGeometry(m_formResize.framePlay.x()+del_w,m_formResize.framePlay.y(),m_formResize.framePlay.width(),m_formResize.framePlay.height());
    ui->frame_Control->setGeometry(m_formResize.frameControl.x(),m_formResize.frameControl.y()+del_h,m_formResize.frameControl.width()+del_w,m_formResize.frameControl.height());

    if(m_chartPara.chartView)m_chartPara.chartView->resize(ui->graphicsViewChart->size());
}

void FrmSensorPracticeSoundWave::on_newDataDevice(EDevice *dev)
{
    if(m_edevice!=dev)return;
        if(!m_chartPara.play)return;
        switch(dev->deviceInfo().serial(EDeviceInfo::SERIAL_GROUP)){
            case EDeviceInfo::GroupType::GROUP_SOFTWARE:
                break;
            case EDeviceInfo::GroupType::GROUP_SENSOR:this->newDataSensor(m_esensor);
                break;
            case EDeviceInfo::GroupType::GROUP_MODULE:
                break;
            case EDeviceInfo::GroupType::GROUP_SYSTEM:
                break;
            }
}

void FrmSensorPracticeSoundWave::removeSensor()
{
    this->chartRemove(m_esensor);
    QObject::disconnect(m_esensor,&ESensor::newDataDevice,this,&FrmSensorPracticeSoundWave::on_newDataDevice);
    m_esensor->deleteLater();
    m_esensor=nullptr;
}

void FrmSensorPracticeSoundWave::newDataSensor(ESensor *sen)
{
this->chartUpdate(sen);
}

void FrmSensorPracticeSoundWave::setToolControl(bool play)
{
    m_chartPara.play = play;
    if(play){
        ui->toolButton_toolPlay->setHidden(true);
        ui->toolButton_toolPause->setHidden(false);
        }
        else{
            ui->toolButton_toolPlay->setHidden(false);
            ui->toolButton_toolPause->setHidden(true);
    }
    if(m_chartPara.chart)m_chartPara.chart->setAnimationDuration(1);
}

void FrmSensorPracticeSoundWave::setSpeaker()
{
if(!m_esensor)return;
/*
typedef enum{
    CTRL_NONE = 0x00U,
    CTRL_FIFO_CLEAR = 0x01U,
    CTRL_SPEAKER	= 0xF1U
}EDeviceControl_TypeDef;
 */
quint16 command = 0xF1;
quint16 time = (uint8_t)m_oscilloPara.timeLength;//milliSecond
command |= (time<<8);
m_esensor->setControl(command);
}

void FrmSensorPracticeSoundWave::chartInit()
{
    if(m_chartPara.chart){m_chartPara.chart->deleteLater();m_chartPara.chart = nullptr;}
    if(m_chartPara.axisX){m_chartPara.axisX->deleteLater();m_chartPara.axisX = nullptr;}
    if(m_chartPara.axisY){m_chartPara.axisY->deleteLater();m_chartPara.axisY = nullptr;}
     m_chartPara.chart = new QChart();
     m_chartPara.chart->setAnimationDuration(1);
     //axis
     m_chartPara.axisX = new QValueAxis;
     m_chartPara.axisX->setRange(m_chartPara.axisX_Min,m_chartPara.axisX_Max);
     m_chartPara.axisX->setTickCount(m_chartPara.axisX_Tick);
     auto _penX = m_chartPara.axisX->gridLinePen();
     _penX.setStyle(Qt::DotLine);
     m_chartPara.axisX->setGridLinePen(_penX);
     m_chartPara.axisX->setLabelFormat("%.2f");
     m_chartPara.axisX->setTitleText("Giây (s)");


     m_chartPara.axisY = new QValueAxis;
     m_chartPara.axisY->setRange(m_chartPara.axisY_Min,m_chartPara.axisY_Max);
     m_chartPara.axisY->setTickCount(m_chartPara.axisY_Tick);
     auto _penY = m_chartPara.axisX->gridLinePen();
     _penY.setStyle(Qt::DotLine);
     m_chartPara.axisY->setGridLinePen(_penY);
     m_chartPara.axisY->setLabelFormat("%.3f");

     m_chartPara.chart->addAxis(m_chartPara.axisX, Qt::AlignBottom);
     m_chartPara.chart->addAxis(m_chartPara.axisY, Qt::AlignLeft);


    // m_chartPara.chart->setAnimationDuration(0);
    // m_chartPara.chart->setAnimationOptions(QChart::GridAxisAnimations);
     //axit
     if(m_chartPara.chartView){
         m_chartPara.chartView->deleteLater();
         m_chartPara.chartView = nullptr;
     }
     m_chartPara.chartView = new EChartView(m_chartPara.chart,ui->graphicsViewChart);
     m_chartPara.chartView->resize(ui->graphicsViewChart->size());
     this->chartSetTrackLine(EChartView::ETL_CROSSHAIR);

     //oscillo
     this->setScope(m_oscilloPara.scope);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////CHART/////////////
void FrmSensorPracticeSoundWave::chartViewUpdate()
{
    if(!m_esensor)return;
    foreach(auto series,m_esensor->series()){
        m_chartPara.chart->addSeries(series);
        foreach(auto axis,series->attachedAxes()){
            series->detachAxis(axis);
            }
        series->attachAxis(m_chartPara.axisX);
        series->attachAxis(m_chartPara.axisY);
        m_chartPara.axisY->setTitleText(m_esensor->parameter().currentUnit().symbol);
        //for callout
        m_chartPara.chartView->updateSeries(series);
    }
    m_chartPara.chart->setTitle(m_edevice->deviceInfo().name());
    m_chartPara.chartView->resize(ui->graphicsViewChart->size());
}

void FrmSensorPracticeSoundWave::chartUpdate(ESensor *sen)
{
    m_para = sen->parameter();
    if(m_para.values().count()<1)return;

    foreach (auto var, m_para.values()) {
        if(m_chartPara.axisY_Max<var)m_chartPara.axisY_Max = var;
        if(m_chartPara.axisY_Min>var)m_chartPara.axisY_Min = var;
        }
    //sen->appendSeries(m_chartPara.timeCount);//convert ms to s
    sen->replaceSeries(m_chartPara.interval,m_chartPara.timeIndex,m_chartPara.axisX_Max);
    if(m_chartPara.axisY)m_chartPara.axisY->setRange(m_chartPara.axisY_Min*1.1,m_chartPara.axisY_Max*1.1);
}

void FrmSensorPracticeSoundWave::chartRemove(ESensor *sen)
{
    if(!m_chartPara.chart)return;
        foreach (auto var, sen->series()) {
            foreach (auto series, m_chartPara.chart->series()) {
                if(var==series){
                    m_chartPara.chart->removeSeries(var);
                    m_chartPara.chartView->removeSeries(var);
                }
            }
        }
}

void FrmSensorPracticeSoundWave::chartClear()
{
    if(!m_esensor)return;
    this->setToolControl(false);
    foreach (auto series, m_esensor->series()) {
            series->clear();
        }
    //this->chartRemove(m_esensor);
    //this->chartInit();
   // this->chartViewUpdate();
    //reset para
    m_chartPara.timeIndex = 0;
    //m_indexScroll = 0;
}

void FrmSensorPracticeSoundWave::chartSetTrackLine(EChartView::ETrackLine track)
{
    if(!m_chartPara.chartView)return;
        //resetbutton
        if(!ui->toolButton_toolCrosshair->isEnabled())ui->toolButton_toolCrosshair->setEnabled(true);
        if(!ui->toolButton_toolCallout->isEnabled())ui->toolButton_toolCallout->setEnabled(true);
        switch(track){
        case EChartView::ETrackLine::ETL_CROSSHAIR:ui->toolButton_toolCrosshair->setEnabled(false);
            break;
        case EChartView::ETrackLine::ETL_CALLOUT:ui->toolButton_toolCallout->setEnabled(false);
            break;
        case EChartView::ETrackLine::ETL_y_ax:
            break;
        }
        m_chartPara.chartView->setTrackLine(track);
}

///////////////////////////////////////////////////////////////////////////////////////////////////Scope
void FrmSensorPracticeSoundWave::setScope(int var)
{
    if(var<m_oscilloPara.scopeText.count())ui->label_scope->setText(m_oscilloPara.scopeText.at(var));
    if(var<m_oscilloPara.scopeMax.count()){
        m_chartPara.axisX_Max = m_oscilloPara.scopeMax.at(var)*QVariant(m_chartPara.axisX_Tick-1).toDouble();
        if(m_chartPara.axisX)m_chartPara.axisX->setMax(m_chartPara.axisX_Max);
    }
}

void FrmSensorPracticeSoundWave::setTimeLength(int time)
{
ui->label_timeLength->setText(QString::number(time)+" (ms)");
}



///////////////////////////////////////////////////////////////////////////////////////////////////Event button

void FrmSensorPracticeSoundWave::on_toolButton_toolCrosshair_clicked()
{
    this->chartSetTrackLine(EChartView::ETL_CROSSHAIR);
}


void FrmSensorPracticeSoundWave::on_toolButton_toolCallout_clicked()
{
    this->chartSetTrackLine(EChartView::ETL_CALLOUT);
}


void FrmSensorPracticeSoundWave::on_toolButton_toolPlay_clicked()
{
    this->setToolControl(true);
}


void FrmSensorPracticeSoundWave::on_toolButton_toolPause_clicked()
{
    this->setToolControl(false);
}


void FrmSensorPracticeSoundWave::on_toolButton_toolClear_clicked()
{
    this->chartClear();
}

void FrmSensorPracticeSoundWave::on_toolButton_plus_clicked()
{
    if(++m_oscilloPara.scope>=m_oscilloPara.scopeText.count())m_oscilloPara.scope = m_oscilloPara.scopeText.count()-1;
    this->setScope(m_oscilloPara.scope);
}


void FrmSensorPracticeSoundWave::on_toolButton_minus_clicked()
{
    if(m_oscilloPara.scope--<1)m_oscilloPara.scope = 0;
    this->setScope(m_oscilloPara.scope);
}

void FrmSensorPracticeSoundWave::on_toolButton_setSpeaker_clicked()
{
    this->setSpeaker();
}


void FrmSensorPracticeSoundWave::on_toolButton_timePlus_clicked()
{
    if(++m_oscilloPara.timeLength>=250)m_oscilloPara.timeLength = 250;
    this->setTimeLength(m_oscilloPara.timeLength);
}


void FrmSensorPracticeSoundWave::on_toolButton_timeMinus_clicked()
{
    if(m_oscilloPara.timeLength--<2)m_oscilloPara.timeLength = 1;
    this->setTimeLength(m_oscilloPara.timeLength);
}

