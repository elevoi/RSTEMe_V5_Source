#include "frmsensorpracticebase.h"
#include "ui_frmsensorpracticebase.h"
#include <QtMath>
#include <QLineEdit>
#include <QFontMetrics>
#include "device/edevicelist.h"
#include <QScrollBar>



FrmSensorPracticeBase::FrmSensorPracticeBase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmSensorPracticeBase)
{
    ui->setupUi(this);
    this->initDisplay();
}

FrmSensorPracticeBase::~FrmSensorPracticeBase()
{
    delete ui;
}
void FrmSensorPracticeBase::initDisplay()
{
    QLineEdit *_lde = ui->comboBox_sampleTime->lineEdit();
    _lde->setObjectName("LineEdit");
    QString _style = ("QLineEdit{\
                        color: rgb(3, 87 ,123);\
                        background-color: rgb(255, 255, 255);\
                        border: none;\
                        border-style: outset;\
                        border-top-left-radius: 5px;\
                        border-bottom-left-radius: 5px;\
                        }\
                        QLineEdit:hover{\
                        background-color: rgb(0, 170, 255);\
                        color: rgb(255, 255, 255);\
                        }");
    _lde->setAlignment(Qt::AlignHCenter);
    _lde->setFont(QFont("Segoe UI",10,QFont::Bold,true));
    _lde->setStyleSheet(_style);
    _lde->setReadOnly(true);

    QLineEdit *_ldeType = ui->comboBox_sampleType->lineEdit();
    _ldeType->setAlignment(Qt::AlignHCenter);
    _ldeType->setFont(QFont("Segoe UI",10,QFont::Bold,true));
    _ldeType->setStyleSheet(_style);
    _ldeType->setReadOnly(true);
    //Parameter
    m_logaritIcon = ui->toolButton_toolLogarit->icon();
    this->updateParameter();
    //chart
    this->initChart();
    //table
    this->initTable();
    //
    this->getSizeWindow();
    this->refreshToolTable();
    m_widowSizeBase.frameToolDeviceFix = ui->frame_toolDevice->size();
    m_widSensorToolDigital = new WidSensorToolDigital();
    m_widowSizeBase.sensorToolDigitalFix = m_widSensorToolDigital->size();


    //timer
    m_timerPoll = new QTimer(this);
    QObject::connect(m_timerPoll,&QTimer::timeout,this,&FrmSensorPracticeBase::on_timerPoll);
    m_timerPoll->start(1);
    }

void FrmSensorPracticeBase::updateParameter()
    {
    m_practiceType = m_practiceParameter.practiceType();
    this->setPlay(m_practiceType.play);
    ui->lineEdit_playTime->setText(QString::number(m_practiceType.timeOut));
    this->setSampleTime(m_practiceType.sampleTime);
    if(m_practiceType.sampleType<ui->comboBox_sampleType->count())ui->comboBox_sampleType->setCurrentIndex(m_practiceType.sampleType);
    this->setLineType((LineType)m_practiceType.lineType);
    this->setAxisType((AxisType)m_practiceType.axisType);
    this->setLogaritType((LogaritType)m_practiceType.logaritType);
}

void FrmSensorPracticeBase::setSampleTime(int time)
{
    int _index=5;
 switch(time){
 case 60000:_index=0;
     break;
 case 30000:_index=1;
     break;
 case 10000:_index=2;
     break;
 case 5000:_index=3;
     break;
 case 2000:_index=4;
     break;
 case 1000:_index=5;
     break;
 case 500:_index=6;
     break;
 case 200:_index=7;
     break;
 case 100:_index=8;
     break;
 case 20:_index=9;
     break;
 case 10:_index=10;
     break;
 case 2:_index=11;
     break;
 }
 ui->comboBox_sampleTime->setCurrentIndex(_index);
}


void FrmSensorPracticeBase::setLineType(LineType var)
{
    m_practiceType.lineType = (int)var;
    if(!ui->toolButton_toolLineDot->isEnabled())ui->toolButton_toolLineDot->setEnabled(true);
    if(!ui->toolButton_toolLine->isEnabled())ui->toolButton_toolLine->setEnabled(true);
    switch(var){
    case LTP_lineDot:
        ui->toolButton_toolLineDot->setEnabled(false);
        break;
    case LTP_line:
        ui->toolButton_toolLine->setEnabled(false);
        break;
    };
}

void FrmSensorPracticeBase::setAxisType(AxisType var)
{
    m_practiceType.axisType = (int)var;
    if(!ui->toolButton_toolMultiY->isEnabled())ui->toolButton_toolMultiY->setEnabled(true);
    if(!ui->toolButton_toolSingleY->isEnabled())ui->toolButton_toolSingleY->setEnabled(true);
    switch(var){
    case ATP_single:
        ui->toolButton_toolSingleY->setEnabled(false);
        break;
    case ATP_multiple:
        ui->toolButton_toolMultiY->setEnabled(false);
        break;
    };
}

void FrmSensorPracticeBase::setLogaritType(LogaritType var)
{
    m_practiceType.logaritType = (int)var;
    QIcon _icon = ui->toolButton_toolLogarit->icon();
    _icon.addPixmap(m_logaritIcon.pixmap(ui->toolButton_toolLogarit->iconSize().width(),QIcon::Disabled,QIcon::On));
    switch(var){
    case LGT_none:
        ui->toolButton_toolLogarit->setIcon(m_logaritIcon);
        break;
    case LGT_logarit:
        ui->toolButton_toolLogarit->setIcon(_icon);
        break;
    };
}

void FrmSensorPracticeBase::addDevice(EDevice *dev)
{
    if(!dev)return;
    bool isdev=false;
    m_edevice = dev;
    //if(m_listDevice.isEmpty())
    foreach(auto var,m_listWidSensorToolDigital){
        if(dev == var->device())isdev = true;
    }
    if(!isdev){
        this->getSensorToolDigital(dev);
        QObject::connect(dev,&EDevice::finished,this,[dev,this](){
            this->on_removeDevice(dev);
        });
    }
}

void FrmSensorPracticeBase::on_removeDevice(EDevice *dev)
{
    this->removeSensorToolDigital(dev);
    this->refreshToolDevice();
}

void FrmSensorPracticeBase::on_replySelectDeviceInfo(EDeviceInfo dev)
{
    dev.setSelectTool(false);
    emit this->replySelectDeviceInfo(dev);
    foreach (auto var, EDeviceList::deviceOnlineList()) {
        if(var->deviceInfo()==dev){
            this->addDevice(var);
        }
    }
}

void FrmSensorPracticeBase::on_timerPoll()
{
    switch((SampleType)m_practiceType.sampleType){
    case SPT_auto:this->playAutoPoll();
        break;
    case SPT_manual:playManualPoll();
        break;
    }
}

void FrmSensorPracticeBase::on_updatePoint(QSplineSeries *series, qreal val)
{
    if(!series)return;
    if((SampleType)m_practiceType.sampleType==SPT_auto){
        if(m_practiceProcess != PPS_play)return;
        int i = m_listSeries.indexOf(series);
        if(i<0)return;
        double _time=0;
        _time = QVariant(m_practiceType.sampleTime*series->count()).toDouble()/1000.0;
        //check logarit
        if((LogaritType)m_practiceType.logaritType==LogaritType::LGT_logarit)val = log10(val);
        QPointF p;
        p.setX(_time);
        p.setY(val);
        this->processUpdate(series,p);
    }
}

void FrmSensorPracticeBase::setPlay(bool status)
{
m_practiceType.play = status;
if(status){
    //ui->frame_toolSetup->setEnabled(false);
    ui->comboBox_sampleTime->setEnabled(false);
    ui->comboBox_sampleType->setEnabled(false);
    ui->lineEdit_playTime->setEnabled(false);
    ui->frame_toolDevice->setEnabled(false);
    ui->toolButton_toolPlay->hide();
    switch((SampleType)m_practiceType.sampleType){
        case SPT_auto:
            ui->toolButton_toolPause->show();
            m_practiceType.numberOf++;
            break;
        case SPT_manual:
            ui->toolButton_toolManual->show();
            break;
        }
    }
    else{
        ui->frame_toolDevice->setEnabled(true);
        ui->comboBox_sampleTime->setEnabled(true);
        ui->comboBox_sampleType->setEnabled(true);
        ui->lineEdit_playTime->setEnabled(true);
        //ui->frame_toolSetup->setEnabled(true);
        ui->toolButton_toolManual->hide();
        ui->toolButton_toolPause->hide();
        ui->toolButton_toolPlay->show();
        }
}

void FrmSensorPracticeBase::playAutoPoll()
{
    switch(m_practiceProcess){
    case PPS_idle:
        if(m_practiceType.play)m_practiceProcess = PPS_setup;
        break;
    case PPS_setup:
        if(this->processAutoSetup())m_practiceProcess = PPS_play;
            else m_practiceProcess = PPS_pause;
        break;
    case PPS_play:
        if(!this->processAutoPlay())m_practiceProcess = PPS_pause;
        break;
    case PPS_pause:
        this->processAutoPause();
        m_practiceProcess = PPS_finish;
        break;
    case PPS_finish:
      //  m_timerPoll->stop();
        m_practiceProcess = PPS_idle;
        break;
    }
}

void FrmSensorPracticeBase::playManualPoll()
{
switch(m_practiceProcess){
case PPS_idle:
    if(m_practiceType.play)m_practiceProcess = PPS_setup;
    break;
case PPS_setup:
    m_practiceType.timeManual = 0;
    foreach (auto var, m_listWidSensorToolDigital) {
        this->updateChart(var);
        }
    m_practiceProcess = PPS_play;
    break;
case PPS_play:
    m_practiceType.timeManual+=0.001;
    this->updateClockWise(m_practiceType.timeManual);
    if(!m_practiceType.play)m_practiceProcess = PPS_finish;
    break;
case PPS_pause:
    m_practiceProcess = PPS_finish;
    break;
case PPS_finish:
    m_practiceProcess = PPS_idle;
    break;
}

}

bool FrmSensorPracticeBase::processAutoSetup()
{
    bool _isDev = false;
    m_practiceType.timeCount = 0;
    foreach (auto var, m_listWidSensorToolDigital) {
        if(var->isConnect()){
            _isDev = true;
            var->setSampleTime(m_practiceType.sampleTime);
        }
    }
    if(!_isDev){
        QMessageBox  msg;
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setWindowTitle(this->windowTitle());
        msg.setParent(nullptr);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowIcon(this->windowIcon());
        msg.setText("Có lỗi xảy ra!\n  - Không có thiết bị nào kết nối!");
        msg.exec();
        return false;
    }
    //chart;
    if(!getTimePractice())return false;
    m_axisX->setMax(m_practiceType.timeOut);
    m_axisX->setMin(0);
    foreach (auto var, m_listWidSensorToolDigital) {
        this->updateChart(var);
    }
    //settext
    ui->label_timePlay->setText("Thời gian còn lại");
    ui->lineEdit_playTime->setStyleSheet("QLineEdit{\
                                         color: rgb(170, 0, 0);\
                                         background-color: rgb(255, 255, 255);\
                                         border: none;\
                                         border-style: outset;\
                                         border-width: 0px;\
                                         border-radius: 15px;\
                                         }");
    return true;
}

bool FrmSensorPracticeBase::processAutoPlay()
{
    if(!m_practiceType.play)return false;
    m_practiceType.timeCount += 0.001; //1mSecond
    if(m_practiceType.timeCount>m_practiceType.timeOut)return false;
    this->updateClock(m_practiceType.timeOut - m_practiceType.timeCount);
return true;
}

void FrmSensorPracticeBase::processAutoPause()
{
    this->setPlay(false);
    foreach (auto var, m_listWidSensorToolDigital) {
            var->setSampleTime(var->sampleTimeLast());
    }
    ui->lineEdit_playTime->setText(QString::number(m_practiceType.timeOut));
    ui->label_timePlay->setText("Thời gian thực hành");
    ui->lineEdit_playTime->setStyleSheet("QLineEdit{\
                                         color: rgb(3, 87, 123);\
                                         background-color: rgb(255, 255, 255);\
                                         border: none;\
                                         border-style: outset;\
                                         border-width: 0px;\
                                         border-radius: 15px;\
}");
}

void FrmSensorPracticeBase::processUpdate(QSplineSeries *series, QPointF p)
{
    int i = m_listSeries.indexOf(series);
    if(i<0)return;
    series->append(p);
    foreach (auto var, m_listWidSensorToolDigital) {
        if(var->series()==series){
            if((AxisType)m_practiceType.axisType==AxisType::ATP_multiple)var->resizeAxisY(p.y());
                else this->resizeAxisY(p.y());
            this->updateEvaluate(var,p.y(),i);
        }
    }
    //update table
    m_tableItem = new QTableWidgetItem(QString::number(p.y()));
    m_tableItem->setBackground(series->pen().color());
    m_tableItem->setForeground(QColor(Qt::white));
    this->setTableRow(series->count()-1,i+1,m_tableItem);
    m_tableItem = new QTableWidgetItem(QString::number(p.x()));
    this->setTableRow(series->count()-1,0,m_tableItem);
    //update evaluate
}

void FrmSensorPracticeBase::manualUpdate()
{
    if(m_practiceType.sampleType!=SPT_manual)return;
    foreach (auto var, m_listWidSensorToolDigital) {
        if(var->isConnect()){
            double _time=0;
            auto val = var->value();
            _time = m_practiceType.timeManual;
            if(m_axisX)m_axisX->setMax(_time*1.1);
            //check logarit
            if((LogaritType)m_practiceType.logaritType==LogaritType::LGT_logarit)val = log10(val);
            QPointF p;
            p.setX(_time);
            p.setY(val);
            this->processUpdate(var->series(),p);
        }
    }
}

void FrmSensorPracticeBase::updateClock(qreal val)
{
    int _h,_m,_s,_lo;
    _s = (int)val;
    _h = _s/3600;
    _m = (_s%3600)/60;
    _lo = (val-(qreal)_s)*10;
    _s = _s - (_h*3600) - (_m*60);
    QString str="";
    str += QString("%1").arg(_h, 2, 10, QLatin1Char( '0' ))+":";
    str += QString("%1").arg(_m, 2, 10, QLatin1Char( '0' ))+":";
    str += QString("%1").arg(_s, 2, 10, QLatin1Char( '0' ))+".";
    str += QString("%1").arg(_lo, 1, 10, QLatin1Char( '0' ));
    ui->lineEdit_playTime->setText(str);
}
void FrmSensorPracticeBase::updateClockWise(qreal val)
{
    int _h,_m,_s;
    _s = (int)val;
    _h = _s/3600;
    _m = (_s%3600)/60;
    _s = _s - (_h*3600) - (_m*60);
    QString str="";
    str += QString("%1").arg(_h, 2, 10, QLatin1Char( '0' ))+":";
    str += QString("%1").arg(_m, 2, 10, QLatin1Char( '0' ))+":";
    str += QString("%1").arg(_s, 2, 10, QLatin1Char( '0' ));
    ui->lineEdit_playTime->setText(str);
}

bool FrmSensorPracticeBase::getTimePractice()
{
    bool ok=false;
    double val = QString(ui->lineEdit_playTime->text()).toDouble(&ok);
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());
    msg.setText("Có lỗi xảy ra!\n  - \"Thời gian thực hành\" phải là một số thực không âm.");
    if(!ok||val<0){
        ui->lineEdit_playTime->setText(QString::number(10));
        msg.exec();
        return false;
    }
    m_practiceType.timeOut = val;
    return true;
}


void FrmSensorPracticeBase::refreshToolTable()
{
//tableWidget
if(m_toolTableType.widgetTableBlink){
    m_containerTable->show();
    ui->tableWidget_dataEvaluate->show();
    ui->graphicsViewChart->resize(m_widowSizeBase.dataWidget.x() - ui->graphicsViewChart->geometry().x()-1,ui->graphicsViewChart->size().height());
    }
    else {
    m_containerTable->hide();
    ui->tableWidget_dataEvaluate->hide();
    ui->graphicsViewChart->resize(ui->frame_toolData->geometry().x() - ui->graphicsViewChart->geometry().x(),ui->graphicsViewChart->size().height());
    }
ui->tableWidget_dataEvaluate->setGeometry(m_containerTable->geometry().x(),m_widowSizeBase.dataEvaluate.y(),m_containerTable->geometry().width(),m_widowSizeBase.dataEvaluate.height());
//[m_containerTable->setGeometry(
this->getSizeWindow();
//chart
if(m_echartView)m_echartView->resize(ui->graphicsViewChart->size());
}

void FrmSensorPracticeBase::initChart()
{
if(m_chart){m_chart->deleteLater();m_chart = nullptr;}
if(m_echartView){m_echartView->deleteLater();m_echartView = nullptr;}
if(m_axisX){m_axisX->deleteLater();m_axisX=nullptr;}
m_axisX = new QValueAxis();
m_chart = new QChart();
m_echartView = new EChartView(m_chart,ui->graphicsViewChart);
m_echartView->resize(ui->graphicsViewChart->size());
m_echartView->chart()->legend()->setAlignment(Qt::AlignTop);
     this->updateTrackLine(EChartView::ETL_CROSSHAIR);
m_chart->addAxis(m_axisX, Qt::AlignBottom);
}

void FrmSensorPracticeBase::updateChart(WidSensorToolDigital *sen)
{

    auto series = sen->newSeries();
    QString _name = series->name()+" ("+sen->sensor()->parameter().currentUnit().symbol+")";
    series->setName(_name+"-Lần "+QString::number(m_practiceType.numberOf));
    //marker
  //  series.set
    if((LineType)m_practiceType.lineType==LTP_lineDot)series->setPointsVisible(true);
    QObject::connect(series,&QSplineSeries::clicked,this,[this,series](QPointF p){
        this->setSelectTable(series,p);
    });

    if((AxisType)m_practiceType.axisType==AxisType::ATP_multiple){
        if(m_axisY){
            auto _ind = m_chart->axes(Qt::Vertical).indexOf(m_axisY);
            if(_ind>=0)m_chart->removeAxis(m_axisY);
            m_axisY->deleteLater();
            m_axisY=nullptr;
        }
        auto _ind = m_chart->axes(Qt::Vertical).indexOf(sen->axisY());
        if(_ind<0)m_chart->addAxis(sen->axisY(), Qt::AlignLeft);
        m_chart->addSeries(dynamic_cast<QLineSeries*>(series));
        if(m_axisX)series->attachAxis(m_axisX);
        series->attachAxis(sen->axisY());
        auto _brush = sen->axisY()->titleBrush();
        _brush.setColor(series->color());
        sen->axisY()->setTitleBrush(_brush);
        sen->setDisplayColor(series->color());
        sen->axisY()->setTitleFont(m_chart->font());
        if(sen->sensor())sen->axisY()->setTitleText(_name);
        if(m_practiceType.numberOf==1)sen->resetAxisY();
        }
        else{
            if(!m_axisY)m_axisY=new QValueAxis(this);
            m_axisY->setTitleText("Giá trị đo");
            auto _ind = m_chart->axes(Qt::Vertical).indexOf(m_axisY);
            if(_ind<0)m_chart->addAxis(m_axisY, Qt::AlignLeft);
            m_chart->addSeries(dynamic_cast<QLineSeries*>(series));
            if(m_axisX)series->attachAxis(m_axisX);
            series->attachAxis(m_axisY);
            sen->setDisplayColor(series->color());
            m_axisY->setTitleFont(m_chart->font());
            if(m_practiceType.numberOf==1)this->resetAxisY();
        }


    m_echartView->updateSeries(series);
    m_listSeries.append(series);
    //evaluate
    sen->resetEvaluate();
    //table
    this->appendTableColumn(series);
}

void FrmSensorPracticeBase::removeChart(WidSensorToolDigital *sen)
{
    foreach (auto var, m_chart->series()) {
        foreach (auto series, sen->listSeries()) {
            if(var==series){
                m_chart->removeSeries(series);
                m_echartView->removeSeries(series);
                this->removeList(series);
                series->deleteLater();
                series = nullptr;
            }
        }
    }
    foreach (auto axis, m_chart->axes(Qt::Vertical)) {
        if(axis==sen->axisY()){
            m_chart->removeAxis(sen->axisY());
        }
    }
}

void FrmSensorPracticeBase::removeList(QSplineSeries *series)
{
    int i = m_listSeries.indexOf(series);
    if(i<0)return;
    this->removeTableColumn(i+1);
    m_listSeries.removeAt(i);
}

void FrmSensorPracticeBase::updateTrackLine(EChartView::ETrackLine track)
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

void FrmSensorPracticeBase::clearChart()
{
    foreach (auto var, m_listWidSensorToolDigital) {
        this->removeChart(var);
    }
    this->removeTableRow();
    this->setPlay(false);
    m_practiceProcess = PPS_idle;
    ui->lineEdit_playTime->setText(QString::number(m_practiceType.timeOut));
    m_practiceType.numberOf = 0;
}

void FrmSensorPracticeBase::resizeAxisY(qreal val)
{
    if(!m_axisY)return;
    if(m_axisY_Max<val)m_axisY_Max = val;
    if(m_axisY_Min>val)m_axisY_Min = val;
    qreal _min = m_axisY_Min*0.25;
    qreal _max = m_axisY_Max*0.25;
    if(_min<0)_min *= -1;
    if(_max<0)_max *= -1;
    m_axisY->setRange(m_axisY_Min-_min,m_axisY_Max+_max);
}

void FrmSensorPracticeBase::resetAxisY()
{
    if(!m_axisY)return;
    m_axisY_Max = -999999;
    m_axisY_Min = 999999;
    m_axisY->setRange(0,1);
}

void FrmSensorPracticeBase::initTable()
{
    ui->tableWidget_DataTable->setColumnWidth(0,100);
    ui->tableWidget_dataEvaluate->setColumnWidth(0,100);
    m_containerTable = new EContainer(this, QPoint(ui->tableWidget_DataTable->geometry().x(),ui->tableWidget_DataTable->geometry().y()), ui->tableWidget_DataTable);
    m_containerTable->setModeEnable(EContainer::RESIZEL);
    m_containerTable->setMoveEnable(false);
    QObject::connect(m_containerTable,&EContainer::newGeometry,this,[this](){
       this->refreshToolTable();
    });
    QObject::connect(ui->tableWidget_DataTable->horizontalScrollBar(),SIGNAL(valueChanged(int)),ui->tableWidget_dataEvaluate->horizontalScrollBar(),SLOT(setValue(int)));
    QObject::connect(ui->tableWidget_dataEvaluate->horizontalScrollBar(),SIGNAL(valueChanged(int)),ui->tableWidget_DataTable->horizontalScrollBar(),SLOT(setValue(int)));
    /*auto _header = ui->tableWidget_DataTable->horizontalHeader();
    _header->setFixedHeight(50);
    ui->tableWidget_DataTable->setHorizontalHeader(_header);*/
}

void FrmSensorPracticeBase::appendTableColumn(QSplineSeries *series)
{
m_tableItem = new QTableWidgetItem(series->name());
m_tableItem->setBackground(series->pen().color());
m_tableItem->setForeground(QColor(Qt::white));
m_tableItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
ui->tableWidget_DataTable->setColumnCount(ui->tableWidget_DataTable->columnCount()+1);
ui->tableWidget_DataTable->setHorizontalHeaderItem(ui->tableWidget_DataTable->columnCount()-1,m_tableItem);
int _w = QFontMetrics(ui->tableWidget_DataTable->horizontalHeader()->fontMetrics()).horizontalAdvance(m_tableItem->text());
ui->tableWidget_DataTable->setColumnWidth(ui->tableWidget_DataTable->columnCount()-1,_w+10);
//data Evaluate
m_tableItem = new QTableWidgetItem(series->name());
m_tableItem->setBackground(series->pen().color());
m_tableItem->setForeground(QColor(Qt::white));
m_tableItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
ui->tableWidget_dataEvaluate->setColumnCount(ui->tableWidget_dataEvaluate->columnCount()+1);
ui->tableWidget_dataEvaluate->setHorizontalHeaderItem(ui->tableWidget_dataEvaluate->columnCount()-1,m_tableItem);
ui->tableWidget_dataEvaluate->setColumnWidth(ui->tableWidget_dataEvaluate->columnCount()-1,_w+10);
}

void FrmSensorPracticeBase::removeTableColumn(int column)
{
    if(column<ui->tableWidget_dataEvaluate->columnCount())ui->tableWidget_dataEvaluate->removeColumn(column);
    if(column<ui->tableWidget_DataTable->columnCount())ui->tableWidget_DataTable->removeColumn(column);
}

void FrmSensorPracticeBase::setTableRow(int row, int column, QTableWidgetItem *item)
{
    if(column>=ui->tableWidget_DataTable->columnCount())return;
    if(row >= ui->tableWidget_DataTable->rowCount())ui->tableWidget_DataTable->setRowCount(row+1);
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->tableWidget_DataTable->setItem(row,column,item);
}

void FrmSensorPracticeBase::setSelectTable(QSplineSeries *series, QPointF p)
{
    int index = 0;
if(series->count()>1){
    for(int i=1;i<series->count();i++){
        if((p.x()>series->at(i-1).x())&&((p.x()<series->at(i).x()))){
                qreal _lo = p.x()-series->at(i-1).x();
                qreal _hi = series->at(i).x()-p.x();
                if(_lo<_hi)index = i-1;
                    else index = i;
            }
        }
    }
//select row on tableWidget
int _column = m_listSeries.indexOf(series);
if(_column<0)return;
auto _item = ui->tableWidget_DataTable->item(index,_column+1);
if(!_item)return;
_item->setSelected(true);
ui->tableWidget_DataTable->setCurrentItem(_item);
}

void FrmSensorPracticeBase::removeTableRow()
{
    ui->tableWidget_DataTable->setRowCount(0);
}

void FrmSensorPracticeBase::updateEvaluate(WidSensorToolDigital *sen, double val,int index)
{
sen->updateEvaluate(val);
auto para = sen->evaluate();
if(index>=ui->tableWidget_dataEvaluate->columnCount()-1)return;

//number of samples
this->setEvaluateTableRow(0,index+1,QString::number(para.sample,'f',0));
//maximum
this->setEvaluateTableRow(1,index+1,QString::number(para.max));
//minimum
this->setEvaluateTableRow(2,index+1,QString::number(para.min));
//average
this->setEvaluateTableRow(3,index+1,QString::number(para.avr,'f',3));
//variance
this->setEvaluateTableRow(4,index+1,QString::number(para.var,'f',5));
//standard deviation
this->setEvaluateTableRow(5,index+1,QString::number(para.std,'f',5));

}

void FrmSensorPracticeBase::setEvaluateTableRow(int row, int column,QString val)
{
auto _it = ui->tableWidget_dataEvaluate->item(row,column);
if(_it){
    _it->setText(val);
    }
     else {
        m_tableItem = new QTableWidgetItem(val);
        m_tableItem->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget_dataEvaluate->setItem(row,column,m_tableItem);
}
}

void FrmSensorPracticeBase::fileGetParameter()
{
    foreach (auto var, m_practiceType.series) {
        m_practiceType.series.removeOne(var);
        var->deleteLater();
        var=nullptr;
    }
    for(int i=0;i<m_chart->series().count();i++){
        m_practiceType.series.append(dynamic_cast<QSplineSeries*>(m_chart->series().at(i)));
    }
    m_practiceType.devices.clear();
    foreach (auto var, m_listWidSensorToolDigital) {
        m_practiceType.devices.append(var->device()->deviceInfo());
    }
    m_practiceParameter.setPracticeType(m_practiceType);
}

void FrmSensorPracticeBase::fileSetParameter()
{
this->updateParameter();
//update devices
    foreach (auto var, m_listWidSensorToolDigital) {
        m_listWidSensorToolDigital.removeOne(var);
        var->deleteLater();
        var=nullptr;
    }
    for(int i=0;i<m_practiceType.devices.count();i++){
        this->on_replySelectDeviceInfo(m_practiceType.devices.at(i));
    }
//chart
this->fileInitChart();
}

void FrmSensorPracticeBase::fileSave()
{
    this->fileGetParameter();
    m_fileBasePractice.saveFile(m_practiceParameter);
}

void FrmSensorPracticeBase::fileOpen()
{
    EFile_BasePractice _file;
    EParameter_PracticeBase _para;
    if(_file.openFile(_para)){
        m_practiceParameter = _para;
        this->fileSetParameter();
    }
}

void FrmSensorPracticeBase::fileExportExcel()
{
    this->fileGetParameter();
    if(m_frmPracticeBaseInfo){
        m_frmPracticeBaseInfo->deleteLater();
        m_frmPracticeBaseInfo = nullptr;
    }
    m_frmPracticeBaseInfo = new FrmPracticeBaseInfo(&m_practiceParameter,this);
    m_frmPracticeBaseInfo->show();
}

void FrmSensorPracticeBase::fileExportReport()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());
    msg.setText("Tính năng chưa sử dụng!");
    msg.exec();
}

void FrmSensorPracticeBase::fileInitChart()
{
    int _num = m_practiceType.series.count()/m_listWidSensorToolDigital.count();
    if(_num<1)return;
    m_practiceType.numberOf=0;
    if(m_axisX)m_axisX->setRange(0,m_practiceType.timeOut);
    for(int i=0;i<_num;i++){
        m_practiceType.numberOf++;
        this->fileUpdateChart(i);
    }
}

void FrmSensorPracticeBase::fileUpdateChart(int num)
{
    for(int i=0;i<m_listWidSensorToolDigital.count();i++){
        this->updateChart(m_listWidSensorToolDigital.at(i));
        //update
        int _index = (num*m_listWidSensorToolDigital.count())+i;
        if(_index>=m_practiceType.series.count())return;
        for(int j=0;j<m_practiceType.series.at(_index)->count();j++){
            this->processUpdate(m_listWidSensorToolDigital.at(i)->series(),m_practiceType.series.at(_index)->points().at(j));
        }
    }
}

void FrmSensorPracticeBase::on_toolButton_toolPlay_clicked()
{
    if(m_listWidSensorToolDigital.empty()){
        QMessageBox  msg;
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setWindowTitle(this->windowTitle());
        msg.setParent(nullptr);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowIcon(this->windowIcon());
        msg.setText("Có lỗi xảy ra!\n  - Không có thiết bị nào trong danh sách thực hành.");
        msg.exec();
        return;
    }
    this->setPlay(true);
}


void FrmSensorPracticeBase::on_toolButton_toolPause_clicked()
{
    this->setPlay(false);
}

void FrmSensorPracticeBase::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    // Your code here.
    int del_h = this->size().height() - m_widowSizeBase.window.height();
    int del_w = this->size().width() - m_widowSizeBase.window.width();
    this->updateSizeWindow(del_w,del_h);
    this->refreshToolDevice();
}

void FrmSensorPracticeBase::removeSensorToolDigital(EDevice *dev)
{
    foreach (auto *var, m_listWidSensorToolDigital) {
            if(var->device()==dev){
                this->removeChart(var);
                m_listWidSensorToolDigital.removeOne(var);
                var->deleteLater();
                var = nullptr;
            }
        }
    if(m_listWidSensorToolDigital.isEmpty())this->removeTableRow();
}

WidSensorToolDigital *FrmSensorPracticeBase::getSensorToolDigital(EDevice *dev)
{
    foreach (auto *var, m_listWidSensorToolDigital) {
            if(var->device()==dev){
                var->show();
                var->activateWindow();
                return var;
            }
        }
        m_widSensorToolDigital = new WidSensorToolDigital(ui->frame_toolDevice);
        m_widSensorToolDigital->setDevice(dev);
        QObject::connect(m_widSensorToolDigital,&WidSensorToolDigital::removeDevice,this,&FrmSensorPracticeBase::on_removeDevice);
        QObject::connect(m_widSensorToolDigital,&WidSensorToolDigital::updatePoint,this,&FrmSensorPracticeBase::on_updatePoint);
        m_listWidSensorToolDigital.append(m_widSensorToolDigital);
        m_widSensorToolDigital->setAutoFillBackground(false);
        m_widSensorToolDigital->show();
        this->refreshToolDevice();
        return m_widSensorToolDigital;
}

void FrmSensorPracticeBase::refreshToolDevice()
{
    int m_gridColumnMax = ui->frame_toolDevice->size().width()/m_widowSizeBase.sensorToolDigitalFix.width();
    if(m_listWidSensorToolDigital.count()<1)return;
    this->getSizeWindow();
    int _newH = (((m_listWidSensorToolDigital.count()-1)/m_gridColumnMax)+1)*m_widowSizeBase.frameToolDeviceFix.height();
    int _reH = _newH-ui->frame_toolDevice->size().height();
    this->updateSizeWindow(0,_reH*(-1));
    ui->frame_toolDevice->resize(ui->frame_toolDevice->size().width(),ui->frame_toolDevice->size().height()+_reH);
  //  this->getSizeWindow();
    int _row=0,_colum=0;
    for(int i=0;i<m_listWidSensorToolDigital.count();i++){
        int _x,_y,_space=5;
        _x = _colum*(10+m_widowSizeBase.sensorToolDigitalFix.width())+10;
        _y = _row*(_space+m_widowSizeBase.sensorToolDigitalFix.height())+_space;
        m_listWidSensorToolDigital.at(i)->setGeometry(QRect(_x,_y,m_widowSizeBase.sensorToolDigitalFix.width(),m_widowSizeBase.sensorToolDigitalFix.height()));
        if(++_colum>=m_gridColumnMax){
            _colum=0;
            _row++;
            }
    }
}


void FrmSensorPracticeBase::getSizeWindow()
{
    m_widowSizeBase.window = this->size();
    m_widowSizeBase.graphicView = ui->graphicsViewChart->size();
    m_widowSizeBase.frameToolHeader = ui->frame_toolHeader->size();
    m_widowSizeBase.frameToolTrack = ui->frame_toolTrack->size();
    m_widowSizeBase.frameToolSetup = ui->frame_toolSetup->geometry();
    m_widowSizeBase.frameToolDevice = ui->frame_toolDevice->geometry();
    m_widowSizeBase.frameToolData = ui->frame_toolData->geometry();
    m_widowSizeBase.framePlay = ui->frame_play->geometry();
    m_widowSizeBase.toolButtonMenu = ui->toolButton_menuSelect->geometry();
    m_widowSizeBase.dataWidget = m_containerTable->geometry();
    m_widowSizeBase.dataEvaluate = ui->tableWidget_dataEvaluate->geometry();
}


void FrmSensorPracticeBase::updateSizeWindow(int del_w, int del_h)
{
    ui->graphicsViewChart->resize(m_widowSizeBase.graphicView.width()+del_w,m_widowSizeBase.graphicView.height()+del_h);
    ui->frame_toolHeader->resize(m_widowSizeBase.frameToolHeader.width()+del_w,m_widowSizeBase.frameToolHeader.height());
    ui->frame_toolTrack->resize(m_widowSizeBase.frameToolTrack.width(),m_widowSizeBase.frameToolTrack.height());
    ui->frame_toolSetup->setGeometry(m_widowSizeBase.frameToolSetup.x(),m_widowSizeBase.frameToolSetup.y()+del_h,m_widowSizeBase.frameToolSetup.width()+del_w,m_widowSizeBase.frameToolSetup.height());
    ui->frame_toolDevice->setGeometry(m_widowSizeBase.frameToolDevice.x(),m_widowSizeBase.frameToolDevice.y()+del_h,m_widowSizeBase.frameToolDevice.width()+del_w,m_widowSizeBase.frameToolDevice.height());
    ui->frame_toolData->setGeometry(m_widowSizeBase.frameToolData.x()+del_w,m_widowSizeBase.frameToolData.y(),m_widowSizeBase.frameToolData.width(),m_widowSizeBase.frameToolData.height()+del_h);
    ui->frame_play->setGeometry(m_widowSizeBase.framePlay.x()+del_w,m_widowSizeBase.framePlay.y()+del_h,m_widowSizeBase.framePlay.width(),m_widowSizeBase.framePlay.height());
    ui->toolButton_menuSelect->setGeometry(m_widowSizeBase.toolButtonMenu.x(),m_widowSizeBase.toolButtonMenu.y()+del_h,m_widowSizeBase.toolButtonMenu.width(),m_widowSizeBase.toolButtonMenu.height());

    m_containerTable->setGeometry(m_widowSizeBase.dataWidget.x()+del_w,m_widowSizeBase.dataWidget.y(),m_widowSizeBase.dataWidget.width(),m_widowSizeBase.dataWidget.height()+del_h);
    ui->tableWidget_dataEvaluate->setGeometry(m_widowSizeBase.dataEvaluate.x()+del_w,m_widowSizeBase.dataEvaluate.y()+del_h,m_widowSizeBase.dataEvaluate.width(),m_widowSizeBase.dataEvaluate.height());
    //chart
    if(m_echartView)m_echartView->resize(ui->graphicsViewChart->size());

}

void FrmSensorPracticeBase::setSampleType(int type)
{
m_practiceType.sampleType = type;
this->clearChart();
}


void FrmSensorPracticeBase::on_toolButton_menuSelect_clicked()
{
    if(!m_frmDeviceTable){
        m_frmDeviceTable = new FrmDeviceTable(this);
        QObject::connect(m_frmDeviceTable,&FrmDeviceTable::replySelectDeviceInfo,this,&FrmSensorPracticeBase::on_replySelectDeviceInfo);
    }
    m_frmDeviceTable->setEnable(EDeviceInfo::GroupType::GROUP_SENSOR);
    m_frmDeviceTable->show();
    m_frmDeviceTable->activateWindow();
}


void FrmSensorPracticeBase::on_toolButton_toolTable_clicked()
{
m_toolTableType.widgetTableBlink = !m_toolTableType.widgetTableBlink;
this->refreshToolTable();
}




void FrmSensorPracticeBase::on_comboBox_sampleTime_currentIndexChanged(int index)
{
switch(index){
    case 0:m_practiceType.sampleTime = 60000;//50 second/sample
        break;
    case 1:m_practiceType.sampleTime = 30000;//20 second/sample
        break;
    case 2:m_practiceType.sampleTime = 10000;//10 second/sample
        break;
    case 3:m_practiceType.sampleTime = 5000;//5 second/sample
        break;
    case 4:m_practiceType.sampleTime = 2000;//2 second/sample
        break;
    case 5:m_practiceType.sampleTime = 1000;//1 second/sample
        break;
    case 6:m_practiceType.sampleTime = 500;//0.5 second/sample
        break;
    case 7:m_practiceType.sampleTime = 200;//0.2 second/sample
        break;
    case 8:m_practiceType.sampleTime = 100;//0.1 second/sample
        break;
    case 9:m_practiceType.sampleTime = 20;//0.05 second/sample
        break;
    case 10:m_practiceType.sampleTime = 10;//0.02 second/sample
        break;
    case 11:m_practiceType.sampleTime = 2;//0.01 second/sample
        break;
    case 12://Tuy chon
        break;
    }
}


void FrmSensorPracticeBase::on_lineEdit_playTime_editingFinished()
{
getTimePractice();
}


void FrmSensorPracticeBase::on_toolButton_toolClear_clicked()
{
    this->clearChart();
}


void FrmSensorPracticeBase::on_toolButton_toolCallout_clicked()
{
    this->updateTrackLine(EChartView::ETL_CALLOUT);
}


void FrmSensorPracticeBase::on_toolButton_toolCrosshair_clicked()
{
    this->updateTrackLine(EChartView::ETL_CROSSHAIR);
}


void FrmSensorPracticeBase::on_tableWidget_DataTable_cellClicked(int, int column)
{
 if(column==0){
     ui->tableWidget_DataTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
 }
 else{
     ui->tableWidget_DataTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
 }
 auto _item = ui->tableWidget_DataTable->currentItem();
 ui->tableWidget_DataTable->setCurrentItem(_item);
}


void FrmSensorPracticeBase::on_comboBox_sampleType_currentIndexChanged(int index)
{
this->setSampleType(index);
}


void FrmSensorPracticeBase::on_toolButton_toolManual_clicked()
{
    this->manualUpdate();
}

void FrmSensorPracticeBase::on_toolButton_toolLineDot_clicked()
{
    this->setLineType(LineType::LTP_lineDot);
}


void FrmSensorPracticeBase::on_toolButton_toolLine_clicked()
{
    this->setLineType(LineType::LTP_line);
}


void FrmSensorPracticeBase::on_tableWidget_dataEvaluate_cellClicked(int, int column)
{
    if(column==0){
        ui->tableWidget_dataEvaluate->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
    }
    else{
        ui->tableWidget_dataEvaluate->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
    }
    auto _item = ui->tableWidget_dataEvaluate->currentItem();
    ui->tableWidget_dataEvaluate->setCurrentItem(_item);
}


void FrmSensorPracticeBase::on_toolButton_toolMultiY_clicked()
{
    this->setAxisType(AxisType::ATP_multiple);
}


void FrmSensorPracticeBase::on_toolButton_toolSingleY_clicked()
{
    this->setAxisType(AxisType::ATP_single);
}


void FrmSensorPracticeBase::on_toolButton_toolLogarit_clicked()
{
    if((LogaritType)m_practiceType.logaritType==LogaritType::LGT_none)setLogaritType(LogaritType::LGT_logarit);
        else   setLogaritType(LogaritType::LGT_none);
}


void FrmSensorPracticeBase::on_toolButton_exportFile_clicked()
{
    QMenu *m_menuExportFile = new QMenu(this);
    auto _actExcel = m_menuExportFile->addAction(QString("Xuất tệp excel"));
    QObject::connect(_actExcel,&QAction::triggered,this,[this](){
            this->fileExportExcel();
        });
    auto _actReport = m_menuExportFile->addAction(QString("Xuất tệp báo cáo"));
    QObject::connect(_actReport,&QAction::triggered,this,[this](){
            this->fileExportReport();
        });
    m_menuExportFile->popup(ui->toolButton_exportFile->mapToGlobal(QPoint(0,ui->toolButton_exportFile->height())));
}


void FrmSensorPracticeBase::on_toolButton_saveFile_clicked()
{
    this->fileSave();
}


void FrmSensorPracticeBase::on_toolButton_openFile_clicked()
{
    this->fileOpen();
}


void FrmSensorPracticeBase::on_toolButton_toolHideSeries_clicked()
{
    QMenu *m_menuHideSeries = new QMenu(this);
    foreach (auto var, m_listSeries) {
        auto _action = new QAction(var->name(), this);
        _action->setCheckable(true);
        _action->setChecked(var->isVisible());
        QObject::connect(_action,&QAction::triggered,this,[_action,var](){
                if(_action->isChecked())var->show();
                else var->hide();
            });
        m_menuHideSeries->addAction(_action);
    }
    m_menuHideSeries->popup(ui->toolButton_toolHideSeries->mapToGlobal(QPoint(ui->toolButton_toolHideSeries->width(),0)));
}

