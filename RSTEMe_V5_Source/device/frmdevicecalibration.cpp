#include "frmdevicecalibration.h"
#include "ui_frmdevicecalibration.h"
#include <QtMath>

QT_CHARTS_USE_NAMESPACE

FrmDeviceCalibration::FrmDeviceCalibration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDeviceCalibration)
{
    ui->setupUi(this);
    m_sizeWindow = this->size();
    m_graphicView = ui->graphicsViewChart->size();
    m_frameHeader = ui->frame_Header->size();
    m_frameToolTrack = ui->frame_toolTrack->size();
    m_frameToolControl = ui->frame_toolControl->geometry();

    //combox unit
    QLineEdit *_lde = ui->comboBox_unit->lineEdit();
    _lde->setObjectName("LineEdit");
    QString _style = ("QLineEdit{\
                        color: rgb(2, 87, 122);\
                        background-color: rgb(255, 255 ,255);\
                        border: none;\
                        border-style: outset;\
                        }\
                        QLineEdit:hover{\
                        background-color: rgb(25, 149, 173);\
                        color: rgb(255, 255, 255);\
                        }");
    _lde->setAlignment(Qt::AlignHCenter);
    _lde->setFont(QFont("Segoe UI",10,QFont::Bold));
    _lde->setStyleSheet(_style);
    _lde->setReadOnly(true);
    ui->comboBox_unit->setLineEdit(_lde);
    //status play
    this->setToolControl(m_chartPlay);

    //timer
    m_timePoll = new QTimer();
    QObject::connect(m_timePoll,&QTimer::timeout,this,&FrmDeviceCalibration::on_timerPoll);
}

FrmDeviceCalibration::~FrmDeviceCalibration()
{
    this->removeSensor();
    if(m_frmDeviceTable){
        m_frmDeviceTable->deleteLater();
        m_frmDeviceTable = nullptr;
    }
    delete ui;
}

void FrmDeviceCalibration::setCalibParameter(CalibParameter var)
{
    m_calibParameter = var;
    this->updateCalibParameter(var);
}

void FrmDeviceCalibration::setDevice(EDevice *dev)
{
    if(dev==nullptr)return;
    if(m_edevice==dev)return;
    m_edevice = dev;
    m_esensor = new ESensor(this,dev);
    QObject::connect(m_esensor,&ESensor::newDataDevice,this,&FrmDeviceCalibration::on_newDataDevice);
    m_esensor->start();
    //unit
    m_para = m_esensor->parameter();
    ui->comboBox_unit->clear();
    for(int i=0;i<m_para.unit().count();i++){
        ui->comboBox_unit->addItem(m_para.unit().at(i).name);
    }

    //init
    this->resetParameter();
    this->initChart();
    this->updateChartView();


    //init calib
    this->initCalib();
}

void FrmDeviceCalibration::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void FrmDeviceCalibration::resizeEvent(QResizeEvent *event)
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

void FrmDeviceCalibration::on_newDataDevice(EDevice *dev)
{
    if(m_edevice!=dev)return;
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

void FrmDeviceCalibration::on_newDataDeviceReference(EDevice *dev)
{
    if(m_edeviceReference!=dev)return;
    switch(dev->deviceInfo().serial(EDeviceInfo::SERIAL_GROUP)){
        case EDeviceInfo::GroupType::GROUP_SOFTWARE:
            break;
        case EDeviceInfo::GroupType::GROUP_SENSOR:this->newDataSensorReferece(m_esensorReference);
            break;
        case EDeviceInfo::GroupType::GROUP_MODULE:
            break;
        case EDeviceInfo::GroupType::GROUP_SYSTEM:
            break;
    }
}

void FrmDeviceCalibration::on_errorDeviceReference(EDevice::Error)
{
    m_isConnectDeviceParameter = false;
}

void FrmDeviceCalibration::on_replySelectDeviceInfo(EDeviceInfo dev)
{
    m_referenceConnectTimeOut = 0;
    dev.setSelectTool(false);
    m_deviceInfo = dev;
    m_drcConnect = DRC_FindDevice;
    m_timePoll->start(1);
    emit this->replySelectDeviceInfo(dev);
}

void FrmDeviceCalibration::on_timerPoll()
{
this->checkReferenceConnect();
}
void FrmDeviceCalibration::newDataSensor(ESensor *sen)
{
this->updateChart(sen);
}

void FrmDeviceCalibration::resetParameter()
{
    /*bool isFail = true;
    qreal calibValue = 0;
    QList<qreal> calibBuffer;
    qreal referenceValue = 0;
    QList<qreal> referenceBuffer;
    QList<qreal> rawBuffer;
    qreal calX = 0;
    qreal calY = 0;*/

    m_axisX_Max = 0;
    m_axisY_Max = 0;
    m_axisY_Min = 0;
    m_timeTickSingle = 0;
    m_indexScroll = 0;

    //EvaluateParameter
    m_evaluateParameter.calibBuffer.clear();
    m_evaluateParameter.referenceBuffer.clear();
    m_evaluateParameter.rawBuffer.clear();
}

void FrmDeviceCalibration::checkIndexScroll(ESensor *sen)
{
    foreach (auto var, sen->series()) {
        if(m_indexScroll<var->count())m_indexScroll = var->count();
    }
}





void FrmDeviceCalibration::initChart()
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


void FrmDeviceCalibration::updateChartView()
{
    if(!m_chart)return;
    if(!m_lineSeriesValue){
        m_lineSeriesValue = new QLineSeries;
        auto _pen = QPen(QColor(Qt::green),2);
        m_lineSeriesValue->setPen(_pen);
        m_lineSeriesValue->setName("Giá trị đo");
        m_chart->addSeries(m_lineSeriesValue);
        m_lineSeriesValue->attachAxis(m_axisX);
        m_lineSeriesValue->attachAxis(m_axisY);
        //for callout
        m_echartView->updateSeries(m_lineSeriesValue);
    }
    if(!m_lineSeriesReference){
        m_lineSeriesReference = new QLineSeries;
        auto _pen = QPen(QColor(Qt::blue),2);
        m_lineSeriesReference->setPen(_pen);
        m_lineSeriesReference->setName("Đường chuẩn");
        m_chart->addSeries(m_lineSeriesReference);
        m_lineSeriesReference->attachAxis(m_axisX);
        m_lineSeriesReference->attachAxis(m_axisY);
        //for callout
        m_echartView->updateSeries(m_lineSeriesReference);
    }
    m_chart->setTitle(m_edevice->deviceInfo().name());
}

void FrmDeviceCalibration::updateChart(ESensor *sen)
{
    m_para = sen->parameter();
    //calib value
    this->setCalibText(m_para);

    if(m_para.adcs().count()<1)return;
    if(!m_chartPlay){
        ui->lcdNumber_Value->display(m_para.adcs().at(0));
        return;
    }

    for(int i=0;i<m_para.adcs().count();i++){
        m_timeTickSingle += m_para.sampleTime();
    //    if(m_axisX_Max<m_timeTickSingle)m_axisX_Max = m_timeTickSingle;
        auto _point = QPointF(QVariant(m_timeTickSingle).toDouble()/1000,m_para.adcs().at(i));
        //update Calib
        this->updateCalib(_point);

        //set chart
        if(m_axisY){
            if(m_axisY->max()<m_evaluateParameter.calibValue)m_axisY->setMax(m_evaluateParameter.calibValue*1.25);
            if(m_axisY->max()<m_evaluateParameter.referenceValue)m_axisY->setMax(m_evaluateParameter.referenceValue*1.25);
            if(m_axisY->min()>m_evaluateParameter.calibValue)m_axisY->setMin(m_evaluateParameter.calibValue*0.75);
            if(m_axisY->min()>m_evaluateParameter.referenceValue)m_axisY->setMin(m_evaluateParameter.referenceValue*0.75);
            }
        _point.setY(m_evaluateParameter.calibValue);
        m_lineSeriesValue->append(_point);
        _point.setY(m_evaluateParameter.referenceValue);
        m_lineSeriesReference->append(_point);

        if(!m_isConnectDeviceParameter&&(m_calibParameter.methodType == CMT_referenceSample))this->stopCalib();

        if((_point.x()>m_calibParameter.calibTime)||!m_evaluateParameter.isFail){
            this->stopCalib();
            return;
            }
    }
    this->checkIndexScroll(sen);
}



void FrmDeviceCalibration::removeChart(ESensor* sen)
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


void FrmDeviceCalibration::removeSensor()
{
    this->removeChart(m_esensor);
    QObject::disconnect(m_esensor,&ESensor::newDataDevice,this,&FrmDeviceCalibration::on_newDataDevice);
    m_esensor->deleteLater();
    m_esensor=nullptr;
}


uint32_t FrmDeviceCalibration::elapsed(uint32_t now, uint32_t last)
{
    if(now>=last)return (now-last);
    else return (((uint32_t)-last)+now);
}

uint32_t FrmDeviceCalibration::different(uint32_t now, uint32_t last)
{
    if(now>=last)return (now-last);
    else return (last-now);
}



void FrmDeviceCalibration::on_comboBox_theme_currentIndexChanged(int index)
{
    if(index<0)return;
    this->updateTheme(index);
}


///////////////////////////////////////////////////////////////////////////////////////Chart Advanced

void FrmDeviceCalibration::clearChart()
{
if(!m_chart)return;
foreach (auto series, m_esensor->series()) {
        series->clear();
    }
m_echartView->clearTrackLine();
this->resetParameter();
}

void FrmDeviceCalibration::setToolControl(bool play)
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

void FrmDeviceCalibration::updateTrackLine(EChartView::ETrackLine track)
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

void FrmDeviceCalibration::initTheme()
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


void FrmDeviceCalibration::initLegend()
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

void FrmDeviceCalibration::updateTheme(int index)
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


void FrmDeviceCalibration::updateLegend(int index)
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

void FrmDeviceCalibration::updateAntiAliasing(bool checked)
{
    if(m_echartView)m_echartView->setRenderHint(QPainter::Antialiasing, checked);
}

void FrmDeviceCalibration::setMessage(QString text, QMessageBox::Icon icon)
{
    if(m_msg)delete m_msg;
    m_msg = new QMessageBox(this);
    m_msg->setStandardButtons(QMessageBox::Ok);
    m_msg->setText(text);
    m_msg->setWindowTitle(this->windowTitle());
    m_msg->setIcon(icon);
    m_msg->setWindowIcon(this->windowIcon());
    m_msg->show();
}


///////////////////////////////////////////////////////////////////////////////////////////////////Calib
bool FrmDeviceCalibration::getCalibParameter()
{
    qreal val=0;
    bool ok=false;
    m_calibParameter.calibTime = ui->spinBox_calibTime->value();
    //sample
    m_calibParameter.sampleTime = ui->spinBox_sampleTime->value();
    m_calibParameter.sampleNumber = ui->spinBox_sampleNumber->value();
    //calib
    m_calibParameter.calibpoint = (CalibPoint)ui->comboBox_calibPointSelect->currentIndex();

    //accuracy
    m_calibParameter.accuracyType = (CalibAccuracyType)ui->comboBox_accuracySelect->currentIndex();
    if(ui->spinBox_rangeMax->value()<ui->spinBox_rangeMin->value()){
        this->setMessage("Giá trị dải đo không hợp lệ!\n Dải đo phải từ nhỏ đến lớn.",QMessageBox::Warning);
        ui->spinBox_rangeMax->setValue(m_calibParameter.RangeMax);
        ui->spinBox_rangeMin->setValue(m_calibParameter.RangeMin);
        return false;
        }
        else{
            m_calibParameter.RangeMax = ui->spinBox_rangeMax->value();
            m_calibParameter.RangeMin = ui->spinBox_rangeMin->value();
            }
    val = QVariant(ui->lineEdit_accuracy->text()).toDouble(&ok);
    if(ok)m_calibParameter.accuracyValue = val;
        else {
            this->setMessage("Giá trị của độ chính xác không hợp lệ!\n Giá trị cần phải là một số thực.",QMessageBox::Warning);
            ui->lineEdit_accuracy->setText(QString::number(m_calibParameter.accuracyValue));
            return false;
            }

    //method type
    if(ui->radioButton_standardSample->isChecked()){
        m_calibParameter.methodType = CMT_standardSample;
        val = QVariant(ui->lineEdit_standardValue->text()).toDouble(&ok);
        if(ok)m_calibParameter.standardValue = val;
            else {
                this->setMessage("Giá trị chuẩn nhập vào không hợp lệ!\n Giá trị cần phải là một số thực.",QMessageBox::Warning);
                ui->lineEdit_standardValue->setText(QString::number(m_calibParameter.standardValue));
                return false;
                }
        }
        else m_calibParameter.methodType = CMT_referenceSample;
    //evaluate type
    m_calibParameter.evaluateType = (EvaluateMethodType)ui->comboBox_evaluateSelect->currentIndex();
    //Check Parameter
    if(m_calibParameter.calibTime*1000<m_calibParameter.sampleTime*m_calibParameter.sampleNumber){
        ui->spinBox_calibTime->setValue((m_calibParameter.sampleTime*m_calibParameter.sampleNumber)/1000 + 1);
        }

    //update chart
    this->updateChartError();

    return true;
}

void FrmDeviceCalibration::updateCalibParameter(CalibParameter para)
{
ui->spinBox_calibTime->setValue(para.calibTime);
//sample
ui->spinBox_sampleTime->setValue(para.sampleTime);
ui->spinBox_sampleNumber->setValue(para.sampleNumber);
//calib
ui->comboBox_calibPointSelect->setCurrentIndex((int)para.calibpoint);
//accuracy
ui->comboBox_accuracySelect->setCurrentIndex((int)para.accuracyType);
ui->frame_range->setEnabled(false);
switch(para.accuracyType){
case ACC_accordingValue:ui->label_accuracyUnit->setText(ui->label_standartValueUnit->text());
    break;
case ACC_accordingReading:ui->label_accuracyUnit->setText("(%RD)");
    break;
case ACC_accordingFullScale:ui->label_accuracyUnit->setText("(%FS)");
    ui->frame_range->setEnabled(true);
    break;
}
ui->spinBox_rangeMin->setValue(para.RangeMin);
ui->spinBox_rangeMax->setValue(para.RangeMax);
ui->lineEdit_accuracy->setText(QString::number(para.accuracyValue));

if(para.methodType == CMT_standardSample){
    ui->radioButton_standardSample->setChecked(true);
    ui->pushButton_addDeviceRef->setEnabled(false);
    ui->lineEdit_standardValue->setEnabled(true);
    ui->lineEdit_standardValue->setText(QString::number(para.standardValue));
    }
    else{
        ui->radioButton_referenceSample->setChecked(true);
        ui->pushButton_addDeviceRef->setEnabled(true);
        ui->lineEdit_standardValue->setEnabled(false);
        }
switch(ui->comboBox_calibPointSelect->currentIndex()){
    case 0:ui->lineEdit_standardValue->setText(QString::number(m_calibParameter.standardValue01));
        break;
    case 1:ui->lineEdit_standardValue->setText(QString::number(m_calibParameter.standardValue02));
        break;
    case 2:ui->lineEdit_standardValue->setText(QString::number(m_calibParameter.standardValue03));
        break;
    }
//evaluate type
 ui->comboBox_evaluateSelect->setCurrentIndex((int)para.evaluateType);

}

void FrmDeviceCalibration::setCalibText(EDeviceParameter para)
{
    qreal _x,_y;
    //one
    if(para.calibPointOne().x()>=0xFFFFFFFF&&para.calibPointOne().y()>=0xFFFFFFFF){
        ui->label_calibCAL01->setText("...");
    }
    else{
        _x = EDeviceParameter::decryption_toDouble((uint32_t)para.calibPointOne().x(),para.calibResolution().factor);
        _y = EDeviceParameter::decryption_toDouble((uint32_t)para.calibPointOne().y(),para.calibResolution().factor);
        QString _text = "( " + QString::number(_x) + " , " + QString::number(_y) + " )";
        ui->label_calibCAL01->setText(_text);
    }
    //two
    if(para.calibPointTwo().x()>=0xFFFFFFFF&&para.calibPointTwo().y()>=0xFFFFFFFF){
        ui->label_calibCAL02->setText("...");
    }
    else{
        _x = EDeviceParameter::decryption_toDouble((uint32_t)para.calibPointTwo().x(),para.calibResolution().factor);
        _y = EDeviceParameter::decryption_toDouble((uint32_t)para.calibPointTwo().y(),para.calibResolution().factor);
        QString _text = "( " + QString::number(_x) + " , " + QString::number(_y) + " )";
        ui->label_calibCAL02->setText(_text);
    }
    //three
    if(para.calibPointThree().x()>=0xFFFFFFFF&&para.calibPointThree().y()>=0xFFFFFFFF){
        ui->label_calibCAL03->setText("...");
    }
    else{
        _x = EDeviceParameter::decryption_toDouble((uint32_t)para.calibPointThree().x(),para.calibResolution().factor);
        _y = EDeviceParameter::decryption_toDouble((uint32_t)para.calibPointThree().y(),para.calibResolution().factor);
        QString _text = "( " + QString::number(_x) + " , " + QString::number(_y) + " )";
        ui->label_calibCAL03->setText(_text);
    }
}

qreal FrmDeviceCalibration::getAccuracyMax()
{
    qreal _val=0,_del=0;
    //check calib method type
    if(m_calibParameter.methodType == CMT_standardSample)_val = m_calibParameter.standardValue;
        else _val = m_evaluateParameter.referenceValue;
    switch(m_calibParameter.accuracyType){
    case ACC_accordingValue:_del = m_calibParameter.accuracyValue;
        break;
    case ACC_accordingReading:_del = (_val*m_calibParameter.accuracyValue)/100.0;
        break;
    case ACC_accordingFullScale:_del = ((m_calibParameter.RangeMax-m_calibParameter.RangeMin)*m_calibParameter.accuracyValue)/100.0;
        break;
    }
    if(_del<0)_del*=(-1);
    return (_val + _del);
}

qreal FrmDeviceCalibration::getAccuracyMin()
{
    qreal _val=0,_del=0;
    //check calib method type
    if(m_calibParameter.methodType == CMT_standardSample)_val = m_calibParameter.standardValue;
        else _val = m_evaluateParameter.referenceValue;
    switch(m_calibParameter.accuracyType){
    case ACC_accordingValue:_del = m_calibParameter.accuracyValue;
        break;
    case ACC_accordingReading:_del = (_val*m_calibParameter.accuracyValue)/100.0;
        break;
    case ACC_accordingFullScale:_del = ((m_calibParameter.RangeMax-m_calibParameter.RangeMin)*m_calibParameter.accuracyValue)/100.0;
        break;
    }
    if(_del<0)_del*=(-1);
    return (_val - _del);
}
void FrmDeviceCalibration::initLineBarrier()
{
    auto pen = QPen(QColor(Qt::red),1);
    if(!m_lineSeriesHigher){
        m_lineSeriesHigher = new QLineSeries;
        m_lineSeriesHigher->setPen(pen);
        m_lineSeriesHigher->setName("Giới hạn trên");
        }
    if(!m_lineSeriesLower){
        m_lineSeriesLower = new QLineSeries;
        m_lineSeriesLower->setPen(pen);
        m_lineSeriesLower->setName("Giới hạn dưới");
        }
    if(m_chart){
        m_chart->addSeries(m_lineSeriesHigher);
        m_chart->addSeries(m_lineSeriesLower);
    }
    m_lineSeriesHigher->attachAxis(m_axisX);
    m_lineSeriesHigher->attachAxis(m_axisY);

    m_lineSeriesLower->attachAxis(m_axisX);
    m_lineSeriesLower->attachAxis(m_axisY);
}

void FrmDeviceCalibration::updateLineBarrier()
{
    qreal _max = this->getAccuracyMax();
    qreal _min = this->getAccuracyMin();
    m_lineSeriesHigher->clear();
    m_lineSeriesHigher->append(QPointF(0,_max));
    m_lineSeriesHigher->append(QPointF(m_axisX->max(),_max));
    m_lineSeriesLower->clear();
    m_lineSeriesLower->append(QPointF(0,_min));
    m_lineSeriesLower->append(QPointF(m_axisX->max(),_min));
}

void FrmDeviceCalibration::updateChartError()
{
    if(m_chart){
        qreal _standardVal = 0;
        if(m_calibParameter.methodType == CMT_standardSample)_standardVal = m_calibParameter.standardValue;
            else _standardVal = m_evaluateParameter.referenceValue;
        m_axisX->setRange(0,m_calibParameter.calibTime);
        m_axisY->setMax((2*this->getAccuracyMax())-_standardVal);
        m_axisY->setMin((2*this->getAccuracyMin())-_standardVal);
        this->updateLineBarrier();
    }
}

qreal FrmDeviceCalibration::precision(qreal val,int res)
{
return QString::number(val,'f',res).toDouble();
}

void FrmDeviceCalibration::initCalib()
{
    //barrier
    this->initLineBarrier();
    //update parameter
    if(!m_edevice)return;
    auto _calibPara = m_edevice->deviceInfo().calibParameter();
    CalibParameter _para;
    _para.calibTime = _calibPara.calibTime;
    _para.sampleTime = _calibPara.sampleTime;
    _para.sampleNumber = _calibPara.sampleNumber;
    _para.accuracyType = (CalibAccuracyType)_calibPara.accuracyType;
    _para.accuracyValue = _calibPara.accuracyValue;
    _para.RangeMin = _calibPara.RangeMin;
    _para.RangeMax = _calibPara.RangeMax;
    _para.methodType = (CalibMethodType)_calibPara.methodType;
    _para.standardValue01 = _calibPara.standardValue01;
    _para.standardValue02 = _calibPara.standardValue02;
    _para.standardValue03 = _calibPara.standardValue03;
    _para.evaluateType = (EvaluateMethodType)_calibPara.evaluateType;

    this->setCalibParameter(_para);
}

void FrmDeviceCalibration::startCalib()
{
if(!m_esensor)return;
m_sampleTimeLast = m_edevice->deviceInfo().sampleTime();
m_esensor->setSampleTime(m_calibParameter.sampleTime);
m_chartPlay = true;
m_calibParameterDefault = m_calibParameter;
m_evaluateParameterDefault = m_evaluateParameter;
this->resetParameter();
m_lineSeriesReference->clear();
m_lineSeriesValue->clear();
}

void FrmDeviceCalibration::stopCalib()
{
this->setToolControl(false);
ui->groupBox_setupParameter->setEnabled(true);
m_esensor->setSampleTime(m_sampleTimeLast);


//check error
if(!m_isConnectDeviceParameter&&(m_calibParameter.methodType == CMT_referenceSample)){
    QString text = "Lỗi kết nối với thiết bị tham chiếu!";
    this->setMessage(text,QMessageBox::Warning);
    m_calibParameter = m_calibParameterDefault;
    m_evaluateParameter = m_evaluateParameterDefault;
    return;
}
//evaluate
if(m_evaluateParameter.isFail){
    QString text = "Hiệu chuẩn không thành công!!!\n /"
                   "Giá trị đo không đạt được độ lặp lại và độ chính xác theo cài đặt.\n/"
                   "Thiết bị cần phải được đặt trong môi trường ổn định trong quá trình hiệu chuẩn.";
    this->setMessage(text,QMessageBox::Warning);
    }
    else{
        quint32 _x,_y;
        _x = EDeviceParameter::encode_toUInt32(m_evaluateParameter.calX,m_para.calibResolution().factor);
        _y = EDeviceParameter::encode_toUInt32(m_evaluateParameter.calY,m_para.calibResolution().factor);
        m_esensor->setCalib((int)m_calibParameter.calibpoint,_x,_y);
        QString text = "Thiết bị đã được hiệu chuẩn thành công.\n Phương pháp đánh giá \"" + ui->comboBox_evaluateSelect->currentText() + "\".\n"
                + ui->comboBox_calibPointSelect->currentText() +
                " có giá trị là CAL( " + QString::number(m_evaluateParameter.calX,'f',m_para.calibResolution().factor) +
                " , " +QString::number(m_evaluateParameter.calY,'f',m_para.calibResolution().factor) + " ).";
        this->setMessage(text,QMessageBox::Information);
        }
m_calibParameter = m_calibParameterDefault;
m_evaluateParameter = m_evaluateParameterDefault;
}

void FrmDeviceCalibration::updateCalib(QPointF point)
{
//evaluateParameter
if(m_evaluateParameter.rawBuffer.count()>=m_calibParameter.sampleNumber){
    m_evaluateParameter.rawBuffer.pop_front();
    }
m_evaluateParameter.rawBuffer.append(point.y());

//reference
if(m_evaluateParameter.referenceBuffer.count()>=m_calibParameter.sampleNumber){
    m_evaluateParameter.referenceBuffer.pop_front();
    }
switch(m_calibParameter.methodType){
    case CMT_standardSample:m_evaluateParameter.referenceBuffer.append(m_calibParameter.standardValue);
        break;
    case CMT_referenceSample:m_evaluateParameter.referenceBuffer.append(m_calibParameter.referenceValue);
        break;
}
this->evaluate();
}

void FrmDeviceCalibration::evaluate()
{
qreal _ratio=1,_error=0;
qreal _standardSum=0,_valueSum=0,_varianceSum=0;

//calculate mean
foreach (auto var, m_evaluateParameter.referenceBuffer) {
    _standardSum += var;
    }
m_evaluateParameter.calY = _standardSum/QVariant(m_evaluateParameter.referenceBuffer.count()).toDouble();
foreach (auto var, m_evaluateParameter.rawBuffer) {
    _valueSum += var;
    }
m_evaluateParameter.calX = _valueSum/QVariant(m_evaluateParameter.rawBuffer.count()).toDouble();
_ratio = m_evaluateParameter.calY/m_evaluateParameter.calX;

m_evaluateParameter.calibValue = this->precision(_ratio*m_evaluateParameter.rawBuffer.at(m_evaluateParameter.rawBuffer.count()-1),3);
m_evaluateParameter.referenceValue = this->precision(m_evaluateParameter.calY,3);
//calculate standard deviation
if(m_evaluateParameter.calibBuffer.count()>=m_calibParameter.sampleNumber){
    m_evaluateParameter.calibBuffer.pop_front();
    }
m_evaluateParameter.calibBuffer.append(m_evaluateParameter.calibValue);
foreach (auto var, m_evaluateParameter.calibBuffer) {
    _varianceSum += pow((var-m_evaluateParameter.calY),2);
    }
_error = pow((_varianceSum/QVariant(m_evaluateParameter.calibBuffer.count()).toDouble()),0.5);
//display
ui->lcdNumber_Reference->display(m_evaluateParameter.referenceValue);
ui->lcdNumber_Value->display(this->precision(m_evaluateParameter.rawBuffer.at(m_evaluateParameter.rawBuffer.count()-1),3));
ui->lcdNumber_ValueCalib->display(m_evaluateParameter.calibValue);
ui->label_ratio->setText(QString::number(_ratio,'f',6));
ui->label_error->setText(QString::number(_error,'f',6));
ui->label_sampleNum->setText(QString::number(m_evaluateParameter.calibBuffer.count()));

if(m_evaluateParameter.calibBuffer.count()>=m_calibParameter.sampleNumber){
    bool _fail = false;
    ui->label_sampleNum->setStyleSheet("color: rgb(0, 170, 0);");

        if(m_calibParameter.evaluateType == EMT_accuracy){
            foreach (auto var, m_evaluateParameter.calibBuffer) {
                if(var>this->getAccuracyMax()||var<this->getAccuracyMin())_fail = true;
                }
            }
            else{
                //standard deviation
                if(((m_evaluateParameter.calY+_error)>this->getAccuracyMax())||((m_evaluateParameter.calY-_error)<this->getAccuracyMin()))_fail = true;

                }
    if(!_fail)m_evaluateParameter.isFail = false;
    }
    else{
        ui->label_sampleNum->setStyleSheet("color: rgb(255, 0, 0);");
        m_evaluateParameter.isFail = true;
        }
}

void FrmDeviceCalibration::clearCalib(int p)
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Xóa dữ liệu hiệu chuẩn có thể gây ra sai số lớn trong phép đo!\nBạn có muốn tiếp tục?");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
     if (msg.result() == QMessageBox::Yes) {
         if(m_esensor){
             m_esensor->setCalib(p,0xFFFFFFFF,0xFFFFFFFF);
         }
     }
}

void FrmDeviceCalibration::checkReferenceConnect()
{
    switch(m_drcConnect){
    case DRC_FindDevice:
        foreach (auto var, EDeviceList::deviceOnlineList()) {
            if(var->deviceInfo()==m_deviceInfo){
                m_edeviceReference = var;
                if(m_esensorReference){
                    QObject::disconnect(m_esensorReference,&ESensor::newDataDevice,this,&FrmDeviceCalibration::on_newDataDeviceReference);
                    QObject::disconnect(m_esensorReference,&ESensor::error,this,&FrmDeviceCalibration::on_errorDeviceReference);
                    m_esensorReference->deleteLater();
                    m_esensorReference = nullptr;
                }
                m_esensorReference = new ESensor(this,m_edeviceReference);
                QObject::connect(m_esensorReference,&ESensor::newDataDevice,this,&FrmDeviceCalibration::on_newDataDeviceReference);
                QObject::connect(m_esensorReference,&ESensor::error,this,&FrmDeviceCalibration::on_errorDeviceReference);
                m_esensorReference->start();
                //unit
                auto _para = m_esensorReference->parameter();
                _para.setCurrentUnit(m_para.currentUnit());
                _para.setCurrentResolution(m_para.resolution().at(0));
                m_esensorReference->setParameter(_para);
                m_drcConnect = DRC_CheckConnect;
            }
        }
        break;
    case DRC_CheckConnect:
        if(m_edeviceReference->isStart() == EDevice::StStarted){
            m_drcConnect = DRC_Poll;
            m_timePoll->stop();
            QMessageBox  msg;
            msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
            msg.setText("Thiết bị tham chiếu đã kết nối.");
            msg.setWindowTitle(this->windowTitle());
            msg.setParent(nullptr);
            msg.setIcon(QMessageBox::Question);
            msg.setWindowIcon(this->windowIcon());
            msg.exec();
        }
        break;
    case DRC_Poll:
        break;
    }

if(m_referenceConnectTimeOut++>1000){
    m_timePoll->stop();
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setText("Lỗi kết nối với thiết bị tham chiếu!");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
}
}

void FrmDeviceCalibration::newDataSensorReferece(ESensor *sen)
{
    double _sum = 0;
    m_isConnectDeviceParameter = true;
    auto _para = sen->parameter();
    if(_para.values().count()<1)return;
    if(m_drcBufferError.count()>100)m_drcBufferError.removeFirst();
    m_drcBufferError.append(_para.value());
    foreach (auto var, m_drcBufferError) {
        _sum += var;
    }
    m_calibParameter.referenceValue = _sum/QVariant(m_drcBufferError.count()).toDouble();
    if(!m_chartPlay){
        m_evaluateParameter.referenceValue = QString::number(m_calibParameter.referenceValue,'f',m_para.currentResolution().factor).toDouble();
        ui->lcdNumber_Reference->display(m_evaluateParameter.referenceValue);
        this->updateChartError();
    }
}



///////////////////////////////////////////////////////////////////////////////////////////////////Form
void FrmDeviceCalibration::on_checkBox_antiAliasing_toggled(bool checked)
{
    this->updateAntiAliasing(checked);
}

void FrmDeviceCalibration::on_comboBox_legend_currentIndexChanged(int index)
{
    if(index<0)return;
    this->updateLegend(index);
}


void FrmDeviceCalibration::on_toolButton_toolCrosshair_clicked()
{
    this->updateTrackLine(EChartView::ETL_CROSSHAIR);
}


void FrmDeviceCalibration::on_toolButton_toolCallout_clicked()
{
    this->updateTrackLine(EChartView::ETL_CALLOUT);
}


void FrmDeviceCalibration::on_toolButton_toolPlay_clicked()
{
    if(!m_isConnectDeviceParameter&&(m_calibParameter.methodType == CMT_referenceSample)){
        QMessageBox  msg;
        msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
        msg.setText("Chưa kết nối với thiết bị tham chiếu!");
        msg.setWindowTitle(this->windowTitle());
        msg.setParent(nullptr);
        msg.setIcon(QMessageBox::Question);
        msg.setWindowIcon(this->windowIcon());
        msg.exec();
        return;
    }
    if(getCalibParameter()){
        ui->groupBox_setupParameter->setEnabled(false);
        this->setToolControl(true);
        this->startCalib();
        }
}


void FrmDeviceCalibration::on_toolButton_toolPause_clicked()
{
    this->setToolControl(false);
    ui->groupBox_setupParameter->setEnabled(true);
}

void FrmDeviceCalibration::on_radioButton_standardSample_toggled(bool)
{
    this->getCalibParameter();
    updateCalibParameter(m_calibParameter);
}


void FrmDeviceCalibration::on_spinBox_calibTime_valueChanged(int)
{
    this->getCalibParameter();
}


void FrmDeviceCalibration::on_spinBox_sampleTime_valueChanged(int)
{
    this->getCalibParameter();
}


void FrmDeviceCalibration::on_spinBox_sampleNumber_valueChanged(int)
{
    this->getCalibParameter();
}


void FrmDeviceCalibration::on_comboBox_calibPointSelect_currentIndexChanged(int index)
{
    this->getCalibParameter();
    if(index>=0){
        switch(index){
        case 0:ui->lineEdit_standardValue->setText(QString::number(m_calibParameter.standardValue01));
            break;
        case 1:ui->lineEdit_standardValue->setText(QString::number(m_calibParameter.standardValue02));
            break;
        case 2:ui->lineEdit_standardValue->setText(QString::number(m_calibParameter.standardValue03));
            break;
        }
    }
}

void FrmDeviceCalibration::on_lineEdit_standardValue_editingFinished()
{
    this->getCalibParameter();
}


void FrmDeviceCalibration::on_comboBox_accuracySelect_currentIndexChanged(int)
{
    this->getCalibParameter();
    updateCalibParameter(m_calibParameter);
}


void FrmDeviceCalibration::on_lineEdit_accuracy_textChanged(const QString &)
{
    this->getCalibParameter();
}


void FrmDeviceCalibration::on_lineEdit_standardValue_textChanged(const QString &str)
{
    if(str!="-")this->getCalibParameter();
}


void FrmDeviceCalibration::on_spinBox_rangeMax_valueChanged(int)
{
    this->getCalibParameter();
}


void FrmDeviceCalibration::on_spinBox_rangeMin_valueChanged(int)
{
    this->getCalibParameter();
}


void FrmDeviceCalibration::on_comboBox_unit_currentIndexChanged(int index)
{
    if(index<0)return;
    m_para = m_esensor->parameter();
    m_para.setCurrentUnit(m_para.unit().at(index));
    m_para.setCurrentResolution(m_para.resolution().at(0));
    m_esensor->setParameter(m_para);
    ui->label_standartValueUnit->setText("("+m_para.unit().at(index).symbol+")");
    if(m_esensorReference){
        auto _para = m_esensorReference->parameter();
        _para.setCurrentUnit(m_para.currentUnit());
        _para.setCurrentResolution(m_para.resolution().at(0));
        m_esensorReference->setParameter(_para);
    }
}


void FrmDeviceCalibration::on_pushButton_clearCalibOne_clicked()
{
    this->clearCalib(0);
}


void FrmDeviceCalibration::on_pushButton_clearCalibTwo_clicked()
{
    this->clearCalib(1);
}


void FrmDeviceCalibration::on_pushButton_clearCalibThree_clicked()
{
    this->clearCalib(2);
}


void FrmDeviceCalibration::on_pushButton_addDeviceRef_clicked()
{
    if(!m_frmDeviceTable){
        m_frmDeviceTable = new FrmDeviceTable(this);
        QObject::connect(m_frmDeviceTable,&FrmDeviceTable::replySelectDeviceInfo,this,&FrmDeviceCalibration::on_replySelectDeviceInfo);
    }
    m_frmDeviceTable->setDisableSoftwareType(true);
    m_frmDeviceTable->show();
    m_frmDeviceTable->activateWindow();
}

