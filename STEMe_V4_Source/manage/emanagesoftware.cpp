#include "emanagesoftware.h"
#include <QDebug>

EManageSoftware::EManageSoftware(QObject *parent)
    : QObject{parent}
{
}

EManageSoftware::~EManageSoftware()
{
this->close();
}

void EManageSoftware::setSelectDevice(EDeviceInfo devInfo, EDevice *edev)
{
    m_edeviceInfo = devInfo;
    //Group:Sensor 0xABC, A = group of sensor, BC = type of sensor
    switch(devInfo.serial(EDeviceInfo::SERIAL_WINDOW)){
    case 0x000:
        break;
    case 0x001:
        if(m_frmDeviceSetup){
            m_frmDeviceSetup->deleteLater();
            m_frmDeviceSetup = nullptr;
            }
        m_frmDeviceSetup = new FrmDeviceSetup();
        m_frmDeviceSetup->setWindowIcon(QIcon(devInfo.icon()));
        m_frmDeviceSetup->setWindowTitle(devInfo.name());
        QObject::connect(m_frmDeviceSetup,&FrmDeviceSetup::stateChange,this,&EManageSoftware::on_stateChange);
        m_frmDeviceSetup->show();
        break;
    case 0x002:
        if(m_frmAccountSetup){
            m_frmAccountSetup->deleteLater();
            m_frmAccountSetup = nullptr;
            }
        m_frmAccountSetup = new FrmAccountSetup();
        m_frmAccountSetup->setWindowIcon(QIcon(devInfo.icon()));
        m_frmAccountSetup->setWindowTitle(devInfo.name());
        m_frmAccountSetup->show();
        break;
    case 0x003:
        if(m_frmSetupSerial){
            m_frmSetupSerial->deleteLater();
            m_frmSetupSerial = nullptr;
            }
        m_frmSetupSerial = new FrmSetupSerial();
        if(devInfo.typeConnect()==EDeviceInfo::ModbusRTU){
            m_frmSetupSerial->setConnection(m_econnection);
            }
        m_frmSetupSerial->setWindowIcon(QIcon(devInfo.icon()));
        m_frmSetupSerial->setWindowTitle(devInfo.name());
        m_frmSetupSerial->show();
        break;
    case 0x004:
        if(m_frmRepairModbusConnection){
            m_frmRepairModbusConnection->deleteLater();
            m_frmRepairModbusConnection = nullptr;
            }
        m_frmRepairModbusConnection = new FrmRepairModbusConnection();
        if(devInfo.typeConnect()==EDeviceInfo::ModbusRTU){
            m_frmRepairModbusConnection->setConnection(m_econnection);
        }
        m_frmRepairModbusConnection->setWindowIcon(QIcon(devInfo.icon()));
        m_frmRepairModbusConnection->setWindowTitle(devInfo.name());
        m_frmRepairModbusConnection->show();
        break;
    case 0x005:
        if(m_frmSearchDevice){
            m_frmSearchDevice->deleteLater();
            m_frmSearchDevice = nullptr;
            }
        m_frmSearchDevice = new FrmSearchDevice();
        m_frmSearchDevice->setConnection(m_econnection);
        m_frmSearchDevice->setWindowIcon(QIcon(devInfo.icon()));
        QObject::connect(m_frmSearchDevice,&FrmSearchDevice::selectDevice,this,&EManageSoftware::on_replySelectDeviceInfo);
        m_frmSearchDevice->setWindowTitle(devInfo.name());
        m_frmSearchDevice->show();
        m_frmSearchDevice->search();
        break;
    case 0x006:
        if(m_frmConnectionSetup){
            m_frmConnectionSetup->deleteLater();
            m_frmConnectionSetup = nullptr;
            }
        m_frmConnectionSetup = new FrmConnectionSetup();
        m_frmConnectionSetup->setConnection(m_econnection);
        m_frmConnectionSetup->setWindowIcon(QIcon(devInfo.icon()));
        QObject::connect(m_frmConnectionSetup,&FrmConnectionSetup::stateChange,this,&EManageSoftware::on_stateChange);
        m_frmConnectionSetup->setWindowTitle(devInfo.name());
        m_frmConnectionSetup->show();
        break;
    case 0x007:
        if(m_frmAddSensor){
            m_frmAddSensor->deleteLater();
            m_frmAddSensor = nullptr;
            }
        m_frmAddSensor = new FrmAddSensor(nullptr);
        m_frmAddSensor->setWindowIcon(QIcon(devInfo.icon()));
        m_frmAddSensor->setWindowTitle(devInfo.name());
        m_frmAddSensor->show();
        break;
    case 0x008:
        if(m_frmDeviceTable){
            m_frmDeviceTable->deleteLater();
            m_frmDeviceTable = nullptr;
            }
        m_frmDeviceTable = new FrmDeviceTable();
        m_frmDeviceTable->setWindowIcon(QIcon(devInfo.icon()));
        m_frmDeviceTable->setWindowTitle(devInfo.name());
        m_frmDeviceTable->setSelectType(FrmDeviceTable::SLT_MULTIPLE);
        m_frmDeviceTable->show();
        break;
    case 0x009:
        if(edev==nullptr)emit this->replySelectDevice(devInfo,edev);
        else this->getDeviceCalibration(edev);
        break;
    }
}


void EManageSoftware::on_replySelectDeviceInfo(EDeviceInfo dev)
{
    emit this->replySelectDeviceInfo(dev);
}

void EManageSoftware::on_stateChange(ETypeDef::StateChange state)
{
    emit this->stateChange(state);
}


/////////////////////////////////////////////////////////////////////////////////////////Display//////////////////////////////

FrmDeviceCalibration *EManageSoftware::getDeviceCalibration(EDevice *dev)
{
    foreach (FrmDeviceCalibration *var, m_listDeviceCalibration) {
            if(var->device()==dev){
                var->show();
                var->activateWindow();
                return var;
            }
        }
        m_frmDeviceCalibration = new FrmDeviceCalibration();
        m_frmDeviceCalibration->setDevice(dev);
        m_frmDeviceCalibration->setWindowIcon(QIcon(m_edeviceInfo.icon()));
        m_frmDeviceCalibration->setWindowTitle(m_edeviceInfo.name() + " - @"+dev->deviceInfo().objectName());
        m_listDeviceCalibration.append(m_frmDeviceCalibration);
        QObject::connect(m_frmDeviceCalibration,&FrmDeviceCalibration::replySelectDeviceInfo,this,&EManageSoftware::on_replySelectDeviceInfo);
        auto del = m_frmDeviceCalibration;

        QObject::connect(dev,&EDevice::finished,this,[del,this](){
            foreach (auto *var, m_listDeviceCalibration) {
                if(var==del){
                    m_listDeviceCalibration.removeOne(var);
                    var->deleteLater();
                    var = nullptr;
                    }
                }
        });
        m_frmDeviceCalibration->show();
        m_frmDeviceCalibration->activateWindow();
        return m_frmDeviceCalibration;
}


void EManageSoftware::close()
{
    if(m_frmDeviceSetup){m_frmDeviceSetup->deleteLater();m_frmDeviceSetup = nullptr;}
    if(m_frmSetupSerial){m_frmSetupSerial->deleteLater();m_frmSetupSerial = nullptr;}
    if(m_frmSearchDevice){m_frmSearchDevice->deleteLater();m_frmSearchDevice = nullptr;}
    if(m_frmConnectionSetup){m_frmConnectionSetup->deleteLater();m_frmConnectionSetup = nullptr;}
    if(m_frmRepairModbusConnection){m_frmRepairModbusConnection->deleteLater();m_frmRepairModbusConnection = nullptr;}
    if(m_frmAddSensor){m_frmAddSensor->deleteLater();m_frmAddSensor = nullptr;}
    if(m_frmDeviceTable){m_frmDeviceTable->deleteLater();m_frmDeviceTable = nullptr;}

    //calib
    foreach (auto var, m_listDeviceCalibration) {
        m_listDeviceCalibration.removeOne(var);
        var->deleteLater();
        var = nullptr;
    }
}



