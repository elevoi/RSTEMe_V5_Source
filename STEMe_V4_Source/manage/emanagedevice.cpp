#include "emanagedevice.h"
#include "comm/econnection.h"
#include "QMainWindow"


EManageDevice::EManageDevice(QObject *parent)
    : QObject{parent}
{
    m_econnectionInfo.load();
    //Software
    m_emanageSoftware = new EManageSoftware(this);
    QObject::connect(m_emanageSoftware,&EManageSoftware::stateChange,this,&EManageDevice::on_stateChange);
    QObject::connect(m_emanageSoftware,&EManageSoftware::replySelectDeviceInfo,this,&EManageDevice::on_replySelectDeviceInfo);
    QObject::connect(m_emanageSoftware,&EManageSoftware::replySelectDevice,this,&EManageDevice::on_replySelectDevice);
    //Tool
    m_emanageTool = new EManageTool(this);
    QObject::connect(m_emanageTool,&EManageTool::stateChange,this,&EManageDevice::on_stateChange);
    QObject::connect(m_emanageTool,&EManageTool::replySelectDeviceInfo,this,&EManageDevice::on_replySelectDeviceInfo);
    QObject::connect(m_emanageTool,&EManageTool::replySelectDevice,this,&EManageDevice::on_replySelectDevice);

    //Sensor
    m_emanageSensor = new EManageSensor(this);
    QObject::connect(m_emanageSensor,&EManageSensor::replySelectDevice,this,&EManageDevice::on_replySelectDevice);
    m_emanageModule = new EManageModule(this);
    m_emanageSystem  = new EManageSystem(this);

}

EManageDevice::~EManageDevice()
{
this->close();
}

void EManageDevice::connectModbusRTU()
{
EConnection::SerialPort para;
m_econnectionInfo.load();
para.port = m_econnectionInfo.modbusPort();
para.baudRate = m_econnectionInfo.modbusBaud();
this->connectModbus(para);
}

bool EManageDevice::isConnectModbusRTU()
{
if(!m_econnection)return false;
return m_econnection->isConnect();
}


void EManageDevice::connectModbus(EConnection::SerialPort para)
{
    if(!m_econnection){
        m_econnection = new EConnection(para);
        QObject::connect(m_econnection,&EConnection::connectChanged,this,&EManageDevice::on_connectChanged);
    }
    m_econnection->setSerialPort(para);
    m_emanageSoftware->setConnection(m_econnection);
    m_emanageTool->setConnection(m_econnection);
    m_econnection->setConnect(para);
}

/*****************************************************************************************************************************************/







////////////////////////////////////////////////////////////////////////////////////////Close()
///
void EManageDevice::selectDeviceTable(EDeviceInfo devInfo)
{
    if(m_frmDeviceTable){
        m_frmDeviceTable->deleteLater();
        m_frmDeviceTable = nullptr;
        }
    m_frmDeviceTable = new FrmDeviceTable();
    m_frmDeviceTable->setWindowIcon(QIcon(devInfo.icon()));
    m_frmDeviceTable->setWindowTitle(devInfo.name());
    m_frmDeviceTable->setSelectType(FrmDeviceTable::SLT_SINGLE);
    m_frmDeviceTable->setDisableSoftwareType(true);
    QObject::connect(m_frmDeviceTable,&FrmDeviceTable::replySelectDeviceInfo,this,[devInfo,this](EDeviceInfo dev){
        this->on_replySelectDevice(devInfo,this->getListDevice(dev));
    });
    m_frmDeviceTable->show();
    m_frmDeviceTable->activateWindow();
}


EDevice *EManageDevice::getListDevice(EDeviceInfo dev)
{
    foreach (EDevice *var, EDeviceList::deviceOnlineList()) {
        if(var->deviceInfo()==dev)return var;
    }
    if(dev.typeConnect()==EDeviceInfo::ModbusRTU){
        m_edevice = new EDevice(m_econnection);
    }
    EDeviceInfoList::getAddressOnlineInc(&dev,&m_edeviceInfoList);
    m_edevice->setDeviceInfo(dev);
    EDeviceList::appendDeviceOnlineList(m_edevice);
    emit this->stateChange(ETypeDef::StateChange::LIST_ONLINE);
    auto _dev = m_edevice;
    QObject::connect(m_edevice,&EDevice::error,this,[_dev,this](auto error){
        emit this->error(error,_dev);
        this->on_error(error,_dev);
    });
    return m_edevice;
}


void EManageDevice::removeDevice(EDevice *dev)
{
    EDeviceList::removeDeviceOnlineList(dev);
    dev->deleteLater();
    dev = nullptr;
}

void EManageDevice::removeDeviceAll()
{
    foreach (EDevice *var, EDeviceList::deviceOnlineList()) {
        this->removeDevice(var);
    }
}


void EManageDevice::selectDeviceInfo(EDeviceInfo dev)
{
    EDevice *_edev;
    m_emanageTool->activateDevice(dev);
    switch(dev.serial(EDeviceInfo::SERIAL_GROUP)){
        case EDeviceInfo::GroupType::GROUP_SOFTWARE:
            m_emanageSoftware->setSelectDevice(dev,m_edevice);
            break;
        case EDeviceInfo::GroupType::GROUP_SENSOR:
            _edev = this->getListDevice(dev);
            if(dev.selectTool())m_emanageSensor->selectDevice(_edev);
            break;
        case EDeviceInfo::GroupType::GROUP_MODULE:
            _edev = this->getListDevice(dev);
            if(dev.selectTool())m_emanageModule->setSelectDevice(_edev);
            break;
        case EDeviceInfo::GroupType::GROUP_SYSTEM:
            _edev = this->getListDevice(dev);
            if(dev.selectTool())m_emanageSystem->setSelectDevice(_edev);
            break;
        case EDeviceInfo::GroupType::GROUP_TOOL:
            m_emanageTool->setSelectDevice(dev,m_edevice);
            break;
    }
}

void EManageDevice::selectDevice(EDeviceInfo dev, EDevice *edev)
{
    if(edev==nullptr){
        this->selectDeviceTable(dev);
        return;
        }
    switch(dev.serial(EDeviceInfo::SERIAL_GROUP)){
        case EDeviceInfo::GroupType::GROUP_SOFTWARE:
            m_emanageSoftware->setSelectDevice(dev,edev);
            break;
        case EDeviceInfo::GroupType::GROUP_SENSOR:
            break;
        case EDeviceInfo::GroupType::GROUP_MODULE:
            break;
        case EDeviceInfo::GroupType::GROUP_SYSTEM:
            break;
        case EDeviceInfo::GroupType::GROUP_TOOL:
            m_emanageTool->setSelectDevice(dev,edev);
            break;
    }
}


//Slot
void EManageDevice::on_stateChange(ETypeDef::StateChange state)
{
    emit this->stateChange(state);
}

void EManageDevice::on_replySelectDeviceInfo(EDeviceInfo dev)
{
    this->selectDeviceInfo(dev);
}

void EManageDevice::on_replySelectDevice(EDeviceInfo dev, EDevice *edev)
{
    this->selectDevice(dev,edev);
}

void EManageDevice::on_error(EDevice::Error error,EDevice *dev)
{
    switch(error){
        case EDevice::Error::NoError:
          //  qDebug()<<"NoError";
            break;
        case EDevice::Error::ErrorSetAddress:
            qDebug()<<"@"<<dev->deviceInfo().serialHex()<<" >> Error set Address!";
            break;
        case EDevice::Error::ErrorSerialNumber:
            qDebug()<<"Error check SerialNumber!";
            break;
        case EDevice::Error::ErrorRequestData:
            qDebug()<<"@"<<dev->deviceInfo().serialHex()<<" >> Error request data, check connect!";
            break;
        case EDevice::Error::ErrorStart:
            qDebug()<<"@"<<dev->deviceInfo().serialHex()<<" >> Error connect to device!";
            break;
    }
}


void EManageDevice::close()
{
    //manage
    if(m_emanageSoftware){m_emanageSoftware->deleteLater();m_emanageSoftware=nullptr;}
    if(m_emanageTool){m_emanageTool->deleteLater();m_emanageTool=nullptr;}
    if(m_emanageSensor){m_emanageSensor->deleteLater();m_emanageSensor=nullptr;}
    if(m_emanageModule){m_emanageModule->deleteLater();m_emanageModule=nullptr;}
    if(m_emanageSystem){m_emanageSystem->deleteLater();m_emanageSystem=nullptr;}

    foreach (EDevice *var, EDeviceList::deviceOnlineList()) {
        this->removeDevice(var);
    }
    if(m_econnection){
        m_econnection->deleteLater();
        m_econnection = nullptr;
        }
}

void EManageDevice::on_connectChanged(bool)
{
emit this->stateChange(ETypeDef::CONNECTION);
}

