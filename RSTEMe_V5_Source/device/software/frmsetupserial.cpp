#include "frmsetupserial.h"
#include "ui_frmsetupserial.h"

FrmSetupSerial::FrmSetupSerial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmSetupSerial)
{
    ui->setupUi(this);
    this->init();
}

void FrmSetupSerial::init()
{
    this->setWindowIcon(QIcon(":/icon/software/iconSoftware03_off"));
    //load combobox
    ui->comboBox_groupDevice->clear();
    for(int i=0;i<m_edeviceInfoList.groups().count();i++){
        ui->comboBox_groupDevice->addItem(m_edeviceInfoList.groups().at(i).name);
    }
    ui->comboBox_typeDevice->clear();
    QList<ETypeDef::TypeDevice> _list = m_edeviceInfoList.type(m_edeviceInfoList.groups().at(ui->comboBox_groupDevice->currentIndex()).id);
    for(int i=0;i<_list.count();i++){
        ui->comboBox_typeDevice->addItem(_list.at(i).name);
        }
    if(m_timerPoll)m_timerPoll->deleteLater();
    m_timerPoll = new QTimer(this);
    QObject::connect(m_timerPoll,&QTimer::timeout,this,&FrmSetupSerial::on_timerPoll);
}

bool FrmSetupSerial::checkTimerOut()
{
    if(m_timerOut++>1000){
        m_timerPoll->stop();
        QMessageBox  msg;
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setText("Lỗi kết nối!\n - Không có phản hồi từ thiết bị.");
        msg.setWindowTitle(this->windowTitle());
        msg.setWindowIcon(this->windowIcon());
        msg.setParent(nullptr);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowIcon(this->windowIcon());
        msg.exec();
        ui->pushButton_writeSerial->setEnabled(true);
        return true;
    }
    return false;
}

bool FrmSetupSerial::checkData()
{
    if(!m_errorRequest&&!m_newData)return false;
    m_timerPoll->stop();
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setWindowIcon(this->windowIcon());
    msg.setParent(nullptr);
    msg.setWindowIcon(this->windowIcon());
    if(m_errorRequest){
        msg.setIcon(QMessageBox::Warning);
        if(m_newData){
            if(m_request.errorString().contains("Request timeout")){
                msg.setText("Lỗi kết nối với thiết bị!"
                            "\nChỉ cài đặt được mã thiết bị khi:"
                            "\n - Thiết bị vừa mới được cắm vào."
                            "\n - Chỉ có 1 thiết bị duy nhất trên hệ thống");
                }
                else{//Modbus Exception Response.
                    msg.setText("Lỗi ghi mã thiết bị!\n - Kiểm tra lại \"Phân loại\" và \"Phiên bản\" của thiết bị. ");
                    }
            }
            else{
                msg.setText("Lỗi kết nối với thiết bị!\n - Kiểm tra lại cổng kết nối.");
                }

    }
    else{
        if(m_request.error()==QModbusDevice::NoError){
            msg.setText("Ghi mã thiết bị thành công.");
            msg.setIcon(QMessageBox::Information);
            }
            else msg.setText("Lỗi kết nối với thiết bị!");
        }
    msg.exec();
    if(ui->checkBox_Increase->isChecked()){
        m_serialNumber++;
        ui->lineEdit_serialNumber->setText(QString("%1").arg(m_serialNumber, 8, 16, QLatin1Char( '0' )));
        }
    ui->pushButton_writeSerial->setEnabled(true);
    m_statusWriteSerial = false;
    return true;
}
FrmSetupSerial::~FrmSetupSerial()
{
    delete ui;
}

void FrmSetupSerial::setConnection(EConnection *connect)
{
    m_connection = connect;
    QObject::connect(m_connection,&EConnection::reply,this,&FrmSetupSerial::on_reply);
    QObject::connect(m_connection,&EConnection::errorOccurred,this,&FrmSetupSerial::on_errorOccurred);
}


void FrmSetupSerial::on_reply(ERequestUnit request)
{
    if(!m_statusWriteSerial)return;
    if(request.slaveAddress() != 127)return;
    if(request.id()!=m_requestId)return;
    m_request = request;
    m_newData = true;
    m_statusWriteSerial = false;
    //ELog::log(request);
}

void FrmSetupSerial::on_errorOccurred(ERequestUnit request)
{
    if(request.id()!=m_requestId)return;
    m_errorRequest = true;
}

void FrmSetupSerial::on_timerPoll()
{
    this->poll();
}

void FrmSetupSerial::updateSerialNumber()
{
    bool ok;
    QString str="";
    str += QString("%1").arg(ui->spinBox_versioneDevice->value(), 1, 16, QLatin1Char( '0' ));
    int _groupId = m_edeviceInfoList.groups().at(ui->comboBox_groupDevice->currentIndex()).id;
    str += QString("%1").arg(_groupId, 1, 16, QLatin1Char( '0' ));
    str += QString("%1").arg(m_edeviceInfoList.type(_groupId).at(ui->comboBox_typeDevice->currentIndex()).id, 2, 16, QLatin1Char( '0' ));
    uint val = QString(ui->lineEdit_id->text()).toUInt(&ok,16);
    if(!ok)ui->lineEdit_id->setText("0000");
    str += QString("%1").arg(val, 4, 16, QLatin1Char( '0' ));
    ui->lineEdit_serialNumber->setText(str.toUpper());
}

bool FrmSetupSerial::loadDeviceInfo()
{
    bool ok;
    int _serial=QString(ui->lineEdit_serialNumber->text()).toUInt(&ok,16);
    if(!ok){
        QMessageBox  msg;
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setText("Mã thiết bị không đúng! Mã bao gồm 8 kí tự [0-9] và [A-F].");
        msg.setWindowTitle(this->windowTitle());
        msg.setWindowIcon(this->windowIcon());
        msg.setParent(nullptr);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowIcon(this->windowIcon());
        msg.exec();
        return false;
    }
    m_serialNumber = _serial;
    return true;
}

void FrmSetupSerial::poll()
{
switch(m_setupSnPoll){
    case SSP_Idle:
        break;
    case SSP_Write:
        this->writeSerialNumber();
        m_setupSnPoll = SSP_Wait;
        break;
    case SSP_Wait:
        if(!this->checkData()){
            if(this->checkTimerOut())m_setupSnPoll = SSP_Idle;
        }
        else m_setupSnPoll = SSP_Idle;
        break;
    }
}

void FrmSetupSerial::writeSerialNumber()
{
    QVector<quint16> val;
    auto _request = ERequestUnit::getRequestWrite();
    auto _data = _request.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(EDeviceParameter::HOLDING_REG_OFFSET);
    _data.setValueCount(3);
    val.append((m_serialNumber>>16)&0xFFFF);
    val.append(m_serialNumber&0xFFFF);
    val.append(0x8888);
    _data.setValues(val);
    _request.setData(_data);

    _request.setSlaveAddress(127);
    _request.setPriority(1);
    _request.setRetries(1);
    _request.setTimeout(30);

    m_errorRequest = false;
    m_newData = false;
    m_timerOut = 0;
    m_requestId = m_connection->sendRequestId(_request);
    m_timerPoll->start(1);
    m_statusWriteSerial = true;
}

void FrmSetupSerial::on_spinBox_versioneDevice_valueChanged(int)
{
    this->updateSerialNumber();
}


void FrmSetupSerial::on_comboBox_groupDevice_activated(int index)
{
    ui->comboBox_typeDevice->clear();
     QList<ETypeDef::TypeDevice> _list = m_edeviceInfoList.type(m_edeviceInfoList.groups().at(index).id);
    for(int i=0;i<_list.count();i++){
        ui->comboBox_typeDevice->addItem(_list.at(i).name);
        }
    this->updateSerialNumber();
}


void FrmSetupSerial::on_comboBox_typeDevice_activated(int)
{
    this->updateSerialNumber();
}


void FrmSetupSerial::on_lineEdit_id_textEdited(const QString &arg1)
{
    bool ok;
    QString(arg1).toUInt(&ok,16);
    if(!ok){
        QMessageBox  msg;
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setText("Mã định danh không đúng!\n - Mã định danh thiết bị là duy nhất\n - Mã bao gồm 4 kí tự [0-9] và [A-F].");
        msg.setWindowTitle(this->windowTitle());
        msg.setWindowIcon(this->windowIcon());
        msg.setParent(nullptr);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowIcon(this->windowIcon());
        msg.exec();
        ui->lineEdit_serialNumber->setText("09AF");
    }
    this->updateSerialNumber();
}


void FrmSetupSerial::on_pushButton_Cancel_clicked()
{
    this->close();
}


void FrmSetupSerial::on_comboBox_groupDevice_currentIndexChanged(int)
{

}


void FrmSetupSerial::on_lineEdit_serialNumber_editingFinished()
{
    if(this->loadDeviceInfo()){
        //load device info
        EDeviceInfo m_deviceInfo;
        m_deviceInfo.setSerial(m_serialNumber);
        ui->lineEdit_id->setText(QString("%1").arg(m_deviceInfo.serial(EDeviceInfo::SERIAL_ID), 4, 16, QLatin1Char( '0' )));

        ui->comboBox_groupDevice->setCurrentIndex(m_edeviceInfoList.group(m_deviceInfo.serial(EDeviceInfo::SERIAL_GROUP)));
        ui->comboBox_typeDevice->setCurrentIndex(m_edeviceInfoList.type(m_deviceInfo.serial(EDeviceInfo::SERIAL_DEVICE),m_edeviceInfoList.type(m_deviceInfo.serial(EDeviceInfo::SERIAL_GROUP))));
        ui->spinBox_versioneDevice->setValue(m_deviceInfo.serial(EDeviceInfo::SERIAL_VERSION));
        ui->pushButton_writeSerial->setEnabled(true);
    }
}




void FrmSetupSerial::on_pushButton_writeSerial_clicked()
{
    if(!m_connection){
        QMessageBox  msg;
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setText("Lỗi cổng giao tiếp!");
        msg.setWindowTitle(this->windowTitle());
        msg.setWindowIcon(this->windowIcon());
        msg.setParent(nullptr);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowIcon(this->windowIcon());
        msg.exec();
        return;
    }
    if(!loadDeviceInfo())return;
    ui->pushButton_writeSerial->setEnabled(false);
    m_timerPoll->start(1);
    m_setupSnPoll = SSP_Write;
}

void FrmSetupSerial::closeEvent(QCloseEvent *event)
{
    if(m_connection){
        QObject::disconnect(m_connection,&EConnection::reply,this,&FrmSetupSerial::on_reply);
        QObject::disconnect(m_connection,&EConnection::errorOccurred,this,&FrmSetupSerial::on_errorOccurred);
    }
    if(m_timerPoll){
        m_timerPoll->deleteLater();
        m_timerPoll=nullptr;
    }
    event->accept();
}

