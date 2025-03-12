#include "frmsensordisplaychart.h"
#include "ui_frmsensordisplaychart.h"
#include<QDebug>


FrmSensorDisplayChart::FrmSensorDisplayChart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmSensorDisplayChart)
{
    ui->setupUi(this);
    m_sizeWindow = this->size();
    m_graphicView = ui->graphicsViewChart->size();
    m_frameHeader = ui->frame_Header->size();
    m_frameToolTrack = ui->frame_toolTrack->size();
    m_frameToolControl = ui->frame_toolControl->geometry();

    //status play
    this->setToolControl(m_chartPlay);
}

FrmSensorDisplayChart::~FrmSensorDisplayChart()
{
    this->removeSensor();
    delete ui;
}

void FrmSensorDisplayChart::setDevice(EDevice *dev)
{
    if(m_edevice==dev)return;
    m_edevice = dev;
    m_esensor = new ESensor(this,dev);
    QObject::connect(m_esensor,&ESensor::newDataDevice,this,&FrmSensorDisplayChart::on_newDataDevice);
    m_esensor->start();
    this->resetParameter();
    this->initChart();
    this->updateChartView();
}

void FrmSensorDisplayChart::removeDevice(EDevice *dev)
{
    if(dev!=m_edevice)return;
    this->removeSensor();
    m_edevice = nullptr;
}

void FrmSensorDisplayChart::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void FrmSensorDisplayChart::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    // Your code here.
     int del_h = this->size().height() - m_sizeWindow.height();
     int del_w = this->size().width() - m_sizeWindow.width();
     ui->frame_toolControl->setGeometry(m_frameToolControl.x(),m_frameToolControl.y()+del_h,m_frameToolControl.width(),m_frameToolControl.height());
     if(del_h<0)del_h=0;
     if(del_w<0)del_w=0;
     ui->graphicsViewChart->resize(m_graphicView.width()+del_w,m_graphicView.height()+del_h);
     ui->frame_Header->resize(m_frameHeader.width()+del_w,m_frameHeader.height());
     ui->frame_toolTrack->resize(m_frameToolTrack.width(),m_frameToolTrack.height()+del_h);

     if(m_echartView)m_echartView->resize(ui->graphicsViewChart->size());
}

void FrmSensorDisplayChart::on_newDataDevice(EDevice *dev)
{
    if(m_edevice!=dev)return;
    if(!m_chartPlay)return;
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
void FrmSensorDisplayChart::newDataSensor(ESensor *sen)
{
this->updateChart(sen);
}

void FrmSensorDisplayChart::resetParameter()
{
    m_axisX_Max = 0;
    m_axisY_Max = 0;
    m_axisY_Min = 0;
    m_timeTickSingle = 0;
    m_indexScroll = 0;
}

void FrmSensorDisplayChart::checkIndexScroll(ESensor *sen)
{
    foreach (auto var, sen->series()) {
        if(m_indexScroll<var->count())m_indexScroll = var->count();
    }
}





void FrmSensorDisplayChart::initChart()
{
    QString _str = "";
    if(m_chart){m_chart->deleteLater();m_chart = nullptr;}
    if(m_axisX){m_axisX->deleteLater();m_axisX = nullptr;}
    if(m_axisY){m_axisY->deleteLater();m_axisY = nullptr;}
     m_chart = new QChart();
     //axis
     m_axisX = new QValueAxis;
     m_axisY = new QValueAxis;
     m_chart->addAxis(m_axisX, Qt::AlignBottom);
     m_chart->addAxis(m_axisY, Qt::AlignLeft);
     //axit
     if(m_echartView){
         m_echartView->deleteLater();
         m_echartView = nullptr;
     }
     m_echartView = new EChartView(m_chart,ui->graphicsViewChart);
     m_echartView->resize(ui->graphicsViewChart->size());
     this->updateTrackLine(EChartView::ETL_CROSSHAIR);
   //m_chart->legend()->hide();
     _str += " (";
     if(m_edevice)_str += " @" + m_edevice->deviceInfo().name();
     _str += ")";
     this->setWindowTitle(_str);


     //Init advanced
     this->initTheme();
     this->initLegend();
}



void FrmSensorDisplayChart::updateChartView()
{
    if(!m_esensor)return;
    foreach(auto series,m_esensor->series()){
        m_chart->addSeries(series);
        foreach(auto axis,series->attachedAxes()){
            series->detachAxis(axis);
            }
        series->attachAxis(m_axisX);
        series->attachAxis(m_axisY);
        //for callout
        m_echartView->updateSeries(series);
    }
    m_chart->setTitle(m_edevice->deviceInfo().name());
}


void FrmSensorDisplayChart::updateChart(ESensor *sen)
{
    m_para = sen->parameter();
    if(m_para.values().count()<1)return;

    foreach (auto var, m_para.values()) {
        if(m_axisY_Max<var)m_axisY_Max = var;
        if(m_axisY_Min>var)m_axisY_Min = var;
        }

    m_timeTickSingle += m_para.values().count()*m_para.sampleTime();
    if(m_axisX_Max<m_timeTickSingle)m_axisX_Max = m_timeTickSingle;
    sen->appendSeries(QVariant(m_timeTickSingle).toDouble()/1000);
    if(m_axisX)m_axisX->setMax((m_axisX_Max/1000)*1.02);
    if(m_axisY)m_axisY->setRange(m_axisY_Min*1.25,m_axisY_Max*1.25);
    //Check scroll
    this->checkIndexScroll(sen);
}


void FrmSensorDisplayChart::removeChart(ESensor* sen)
{
    if(!m_chart)return;
    foreach (auto var, sen->series()) {
        foreach (auto series, m_chart->series()) {
            if(var==series){
                m_chart->removeSeries(var);
                m_echartView->removeSeries(var);
            }
        }
    }
}


void FrmSensorDisplayChart::removeSensor()
{
    this->removeChart(m_esensor);
    QObject::disconnect(m_esensor,&ESensor::newDataDevice,this,&FrmSensorDisplayChart::on_newDataDevice);
    m_esensor->deleteLater();
    m_esensor=nullptr;
}


uint32_t FrmSensorDisplayChart::elapsed(uint32_t now, uint32_t last)
{
    if(now>=last)return (now-last);
    else return (((uint32_t)-last)+now);
}

uint32_t FrmSensorDisplayChart::different(uint32_t now, uint32_t last)
{
    if(now>=last)return (now-last);
    else return (last-now);
}



void FrmSensorDisplayChart::on_comboBox_theme_currentIndexChanged(int index)
{
    if(index<0)return;
    this->updateTheme(index);
}


///////////////////////////////////////////////////////////////////////////////////////Chart Advanced

void FrmSensorDisplayChart::clearChart()
{
if(!m_chart)return;
foreach (auto series, m_esensor->series()) {
        series->clear();
    }
m_echartView->clearTrackLine();
this->resetParameter();
}

void FrmSensorDisplayChart::setToolControl(bool play)
{
m_chartPlay = play;
if(play){
    ui->toolButton_toolPlay->setEnabled(false);
    ui->toolButton_toolPause->setEnabled(true);
    }
    else{
        ui->toolButton_toolPlay->setEnabled(true);
        ui->toolButton_toolPause->setEnabled(false);
        }
}

void FrmSensorDisplayChart::updateTrackLine(EChartView::ETrackLine track)
{
    if(!m_echartView)return;
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
    m_echartView->setTrackLine(track);
}

void FrmSensorDisplayChart::initTheme()
{
    QLineEdit *_lde = ui->comboBox_theme->lineEdit();
    _lde->setObjectName("LineEdit");
    QString _style = ("QLineEdit{\
                        color: rgb(2, 87, 122);\
                        background-color: rgb(255, 255 ,255);\
                        border: none;\
                        border-style: outset;\
                        border-top-left-radius: 12px;\
                        border-bottom-left-radius: 12px;\
                        }\
                        QLineEdit:hover{\
                        background-color: rgb(25, 149, 173);\
                        color: rgb(255, 255, 255);\
                        }");
    _lde->setAlignment(Qt::AlignHCenter);
    _lde->setFont(QFont("Segoe UI",10,QFont::Bold));
    _lde->setStyleSheet(_style);
    _lde->setReadOnly(true);
    ui->comboBox_theme->setLineEdit(_lde);

    // add items to theme combobox

    ui->comboBox_theme->addItem("None", QChart::ChartThemeQt);
    ui->comboBox_theme->addItem("Blue Cerulean", QChart::ChartThemeBlueCerulean);
    ui->comboBox_theme->addItem("Dark", QChart::ChartThemeDark);
    ui->comboBox_theme->addItem("Brown Sand", QChart::ChartThemeBrownSand);
    ui->comboBox_theme->addItem("Blue NCS", QChart::ChartThemeBlueNcs);
    ui->comboBox_theme->addItem("Blue Icy", QChart::ChartThemeBlueIcy);

}


void FrmSensorDisplayChart::initLegend()
{
    QLineEdit *_lde = ui->comboBox_legend->lineEdit();
    _lde->setObjectName("LineEdit");
    QString _style = ("QLineEdit{\
                        color: rgb(2, 87, 122);\
                        background-color: rgb(255, 255 ,255);\
                        border: none;\
                        border-style: outset;\
                        border-top-left-radius: 12px;\
                        border-bottom-left-radius: 12px;\
                        }\
                        QLineEdit:hover{\
                        background-color: rgb(25, 149, 173);\
                        color: rgb(255, 255, 255);\
                        }");
    _lde->setAlignment(Qt::AlignHCenter);
    _lde->setFont(QFont("Segoe UI",10,QFont::Bold));
    _lde->setStyleSheet(_style);
    _lde->setReadOnly(true);
    ui->comboBox_legend->setLineEdit(_lde);

    //
    ui->comboBox_legend->addItem("No Legend ", 0);
    ui->comboBox_legend->addItem("Legend Top", Qt::AlignTop);
    ui->comboBox_legend->addItem("Legend Bottom", Qt::AlignBottom);
    ui->comboBox_legend->addItem("Legend Left", Qt::AlignLeft);
    ui->comboBox_legend->addItem("Legend Right", Qt::AlignRight);
}

void FrmSensorDisplayChart::updateTheme(int index)
{
    QChart::ChartTheme theme = static_cast<QChart::ChartTheme>(
                ui->comboBox_theme->itemData(index).toInt());
    //![6]
    /*const auto charts = m_chart;
    if (!m_chart.isEmpty() && m_chart.at(0)->chart()->theme() != theme) {
        for (QChartView *chartView : charts) {
            //![7]
            chartView->chart()->setTheme(theme);
            //![7]
        }*/
        if(m_echartView){
        m_echartView->chart()->setTheme(theme);

        // Set palette colors based on selected theme
        //![8]
        QPalette pal = window()->palette();
        if (theme == QChart::ChartThemeDark) {
            pal.setColor(QPalette::Window, QRgb(0x121218));
            pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
        } else if (theme == QChart::ChartThemeBlueCerulean) {
            pal.setColor(QPalette::Window, QRgb(0x40434a));
            pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
        } else if (theme == QChart::ChartThemeBrownSand) {
            pal.setColor(QPalette::Window, QRgb(0x9e8965));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        } else if (theme == QChart::ChartThemeBlueNcs) {
            pal.setColor(QPalette::Window, QRgb(0x018bba));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        } else if (theme == QChart::ChartThemeBlueIcy) {
            pal.setColor(QPalette::Window, QRgb(0xcee7f0));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        } else {
            pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        }
        window()->setPalette(pal);
        }
}


void FrmSensorDisplayChart::updateLegend(int index)
{
    Qt::Alignment alignment(ui->comboBox_legend->itemData(index).toInt());
    if(!m_echartView)return;
    if (!alignment) {
            m_echartView->chart()->legend()->hide();
    } else {
            m_echartView->chart()->legend()->setAlignment(alignment);
            m_echartView->chart()->legend()->show();
    }
}

void FrmSensorDisplayChart::updateAntiAliasing(bool checked)
{
    if(m_echartView)m_echartView->setRenderHint(QPainter::Antialiasing, checked);
}


void FrmSensorDisplayChart::on_checkBox_antiAliasing_toggled(bool checked)
{
    this->updateAntiAliasing(checked);
}

void FrmSensorDisplayChart::on_comboBox_legend_currentIndexChanged(int index)
{
    if(index<0)return;
    this->updateLegend(index);
}


void FrmSensorDisplayChart::on_toolButton_toolCrosshair_clicked()
{
    this->updateTrackLine(EChartView::ETL_CROSSHAIR);
}


void FrmSensorDisplayChart::on_toolButton_toolCallout_clicked()
{
    this->updateTrackLine(EChartView::ETL_CALLOUT);
}


void FrmSensorDisplayChart::on_toolButton_toolPlay_clicked()
{
    this->setToolControl(true);
}


void FrmSensorDisplayChart::on_toolButton_toolPause_clicked()
{
    this->setToolControl(false);
}


void FrmSensorDisplayChart::on_toolButton_toolClear_clicked()
{
    this->clearChart();
}

