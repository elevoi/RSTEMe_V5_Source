#include "emanagetool.h"

EManageTool::EManageTool(QObject *parent)
    : QObject{parent}
{

}

EManageTool::~EManageTool()
{
this->close();
}

void EManageTool::setSelectDevice(EDeviceInfo devInfo, EDevice *edev)
{
    m_edeviceInfo = devInfo;
    //Group:Sensor 0xABC, A = group of sensor, BC = type of sensor
    switch(devInfo.serial(EDeviceInfo::SERIAL_WINDOW)){
    //Display
    case 0x400:
        break;
    case 0x401:
        if(edev==nullptr)emit this->replySelectDevice(devInfo,edev);
        else this->getSensorDisplayDigital(edev);
        break;
    case 0x402:
        if(edev==nullptr)emit this->replySelectDevice(devInfo,edev);
        else {
            if(!m_frmSensorDisplayMultiple)m_frmSensorDisplayMultiple = new FrmSensorDisplayMultiple();
            m_frmSensorDisplayMultiple->addDevice(edev);
            m_frmSensorDisplayMultiple->setWindowTitle(m_edeviceInfo.name());
            m_frmSensorDisplayMultiple->setWindowIcon(QIcon(m_edeviceInfo.icon()));
            m_frmSensorDisplayMultiple->setWindowTitle(devInfo.name());
            m_frmSensorDisplayMultiple->show();
            m_frmSensorDisplayMultiple->activateWindow();
            }
        break;
    case 0x403:
        if(edev==nullptr)emit this->replySelectDevice(devInfo,edev);
        else this->getSensorDisplayClock(edev);
        break;
    case 0x404:
        if(edev==nullptr)emit this->replySelectDevice(devInfo,edev);
        else this->getSensorDisplayChart(edev);
        break;
    case 0x405:
        if(edev==nullptr)emit this->replySelectDevice(devInfo,edev);
        else this->getSensorOscillo(edev);
        break;
    //Tool
    case 0x451:
        if(edev==nullptr)emit this->replySelectDevice(devInfo,edev);
        else this->getDeviceConfig(edev);
        break;
    case 0x461:
        if(edev==nullptr)emit this->replySelectDevice(devInfo,edev);
        else {
            if(!m_frmSensorPracticeBase){
                m_frmSensorPracticeBase = new FrmSensorPracticeBase();
                QObject::connect(m_frmSensorPracticeBase,&FrmSensorPracticeBase::replySelectDeviceInfo,this,&EManageTool::on_replySelectDeviceInfo);
            }
            m_frmSensorPracticeBase->addDevice(edev);
            m_frmSensorPracticeBase->setWindowTitle(m_edeviceInfo.name());
            m_frmSensorPracticeBase->setWindowIcon(QIcon(m_edeviceInfo.icon()));
            m_frmSensorPracticeBase->setWindowTitle(devInfo.name());
            m_frmSensorPracticeBase->show();
            m_frmSensorPracticeBase->activateWindow();
            }
        break;
    case 0x462:
        if(edev==nullptr)emit this->replySelectDevice(devInfo,edev);
        else {
            if(!m_frmSensorPracticeSoundWave){
                m_frmSensorPracticeSoundWave = new FrmSensorPracticeSoundWave();
            }
            m_frmSensorPracticeSoundWave->setDevice(edev);
            m_frmSensorPracticeSoundWave->setWindowTitle(m_edeviceInfo.name());
            m_frmSensorPracticeSoundWave->setWindowIcon(QIcon(m_edeviceInfo.icon()));
            m_frmSensorPracticeSoundWave->setWindowTitle(devInfo.name());
            m_frmSensorPracticeSoundWave->show();
            m_frmSensorPracticeSoundWave->activateWindow();
            }
        break;

    //Calib
    case 0x009:
        if(edev==nullptr)emit this->replySelectDevice(devInfo,edev);
        else this->getDeviceCalibration(edev);
        break;
    }
}


void EManageTool::on_replySelectDeviceInfo(EDeviceInfo dev)
{
    emit this->replySelectDeviceInfo(dev);
}

void EManageTool::on_stateChange(ETypeDef::StateChange state)
{
    emit this->stateChange(state);
}


/////////////////////////////////////////////////////////////////////////////////////////Display//////////////////////////////
void EManageTool::activateDevice(EDeviceInfo dev)
{
    //display
    foreach (auto var, m_listSensorDisplayDigital) {
            if(var->device()->deviceInfo().serial()==dev.serial())var->activateWindow();
        }
    foreach (auto var, m_listSensorDisplayClock) {
            if(var->device()->deviceInfo().serial()==dev.serial())var->activateWindow();
        }
    foreach (auto var, m_listSensorDisplayChart) {
            if(var->device()->deviceInfo().serial()==dev.serial())var->activateWindow();
        }
    //control
    foreach (auto var, m_listDeviceConfig) {
            if(var->device()->deviceInfo().serial()==dev.serial())var->activateWindow();
        }

    //calib
    foreach (auto var, m_listDeviceCalibration) {
            if(var->device()->deviceInfo().serial()==dev.serial())var->activateWindow();
        }

    if(m_frmSensorDisplayMultiple)m_frmSensorDisplayMultiple->activateWindow();
}


FrmSensorDisplayDigital *EManageTool::getSensorDisplayDigital(EDevice *dev)
{
    foreach (auto var, m_listSensorDisplayDigital) {
            if(var->device()==dev){
                var->show();
                var->activateWindow();
                return var;
            }
        }
        m_frmSensorDisplayDigital = new FrmSensorDisplayDigital();
        m_frmSensorDisplayDigital->setDevice(dev);
        m_frmSensorDisplayDigital->setWindowIcon(QIcon(m_edeviceInfo.icon()));
        m_frmSensorDisplayDigital->setWindowTitle(m_edeviceInfo.name() + " - @"+dev->deviceInfo().objectName());
        m_listSensorDisplayDigital.append(m_frmSensorDisplayDigital);
        auto del = m_frmSensorDisplayDigital;
        QObject::connect(dev,&EDevice::finished,this,[del,this](){
            foreach (auto *var, m_listSensorDisplayDigital) {
                if(var==del){
                    m_listSensorDisplayDigital.removeOne(var);
                    var->deleteLater();
                    var = nullptr;
                    }
                }
        });
        m_frmSensorDisplayDigital->show();
        m_frmSensorDisplayDigital->activateWindow();
        return m_frmSensorDisplayDigital;
}


FrmSensorDisplayClock *EManageTool::getSensorDisplayClock(EDevice *dev)
{
    foreach (auto var, m_listSensorDisplayClock) {
            if(var->device()==dev){
                var->show();
                var->activateWindow();
                return var;
            }
        }
        m_frmSensorDisplayClock = new FrmSensorDisplayClock();
        m_frmSensorDisplayClock->setDevice(dev);
        m_frmSensorDisplayClock->setWindowIcon(QIcon(m_edeviceInfo.icon()));
        m_frmSensorDisplayClock->setWindowTitle(m_edeviceInfo.name() + " - @"+dev->deviceInfo().objectName());
        m_listSensorDisplayClock.append(m_frmSensorDisplayClock);
        auto del = m_frmSensorDisplayClock;
        QObject::connect(dev,&EDevice::finished,this,[del,this](){
            foreach (auto *var, m_listSensorDisplayClock) {
                if(var==del){
                    m_listSensorDisplayClock.removeOne(var);
                    var->deleteLater();
                    var = nullptr;
                    }
                }
        });
        m_frmSensorDisplayClock->show();
        m_frmSensorDisplayClock->activateWindow();
        return m_frmSensorDisplayClock;
}

FrmSensorDisplayChart *EManageTool::getSensorDisplayChart(EDevice *dev)
{
    foreach (auto var, m_listSensorDisplayChart) {
            if(var->device()==dev){
                var->setDevice(dev);
                var->show();
                var->activateWindow();
                return var;
            }
        }
        m_frmSensorDisplayChart = new FrmSensorDisplayChart();
        m_frmSensorDisplayChart->setDevice(dev);
        m_frmSensorDisplayChart->setWindowIcon(QIcon(m_edeviceInfo.icon()));
        m_frmSensorDisplayChart->setWindowTitle(m_edeviceInfo.name() + " - @"+dev->deviceInfo().objectName());
        m_listSensorDisplayChart.append(m_frmSensorDisplayChart);
        auto del = m_frmSensorDisplayChart;
        QObject::connect(dev,&EDevice::finished,this,[del,this](){
            foreach (auto *var, m_listSensorDisplayChart) {
                if(var==del){
                    m_listSensorDisplayChart.removeOne(var);
                    var->deleteLater();
                    var = nullptr;
                    }
                }
        });
        m_frmSensorDisplayChart->show();
        m_frmSensorDisplayChart->activateWindow();
        return m_frmSensorDisplayChart;
}

FrmSensorOscillo *EManageTool::getSensorOscillo(EDevice *dev)
{
    foreach (auto var, m_listSensorOscillo) {
            if(var->device()==dev){
                var->setDevice(dev);
                var->show();
                var->activateWindow();
                return var;
            }
        }
        m_frmSensorOscillo = new FrmSensorOscillo();
        m_frmSensorOscillo->setDevice(dev);
        m_frmSensorOscillo->setWindowIcon(QIcon(m_edeviceInfo.icon()));
        m_frmSensorOscillo->setWindowTitle(m_edeviceInfo.name() + " - @"+dev->deviceInfo().objectName());
        m_listSensorOscillo.append(m_frmSensorOscillo);
        auto del = m_frmSensorOscillo;
        QObject::connect(dev,&EDevice::finished,this,[del,this](){
            foreach (auto *var, m_listSensorOscillo) {
                if(var==del){
                    m_listSensorOscillo.removeOne(var);
                    var->deleteLater();
                    var = nullptr;
                    }
                }
        });
        m_frmSensorOscillo->show();
        m_frmSensorOscillo->activateWindow();
        return m_frmSensorOscillo;
}


FrmDeviceConfig *EManageTool::getDeviceConfig(EDevice *dev)
{
    foreach (auto var, m_listDeviceConfig) {
            if(var->device()==dev){
                var->show();
                var->activateWindow();
                return var;
            }
        }
        m_frmDeviceConfig = new FrmDeviceConfig();
        m_frmDeviceConfig->setDevice(dev);
        m_frmDeviceConfig->setWindowIcon(QIcon(m_edeviceInfo.icon()));
        m_frmDeviceConfig->setWindowTitle(m_edeviceInfo.name() + " - @"+dev->deviceInfo().objectName());
        m_listDeviceConfig.append(m_frmDeviceConfig);
        auto del = m_frmDeviceConfig;
        QObject::connect(dev,&EDevice::finished,this,[del,this](){
            foreach (auto *var, m_listDeviceConfig) {
                if(var==del){
                    m_listDeviceConfig.removeOne(var);
                    var->deleteLater();
                    var = nullptr;
                    }
                }
        });
        m_frmDeviceConfig->show();
        m_frmDeviceConfig->activateWindow();
        return m_frmDeviceConfig;
}


FrmDeviceCalibration *EManageTool::getDeviceCalibration(EDevice *dev)
{
    foreach (auto var, m_listDeviceCalibration) {
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
        QObject::connect(m_frmDeviceCalibration,&FrmDeviceCalibration::replySelectDeviceInfo,this,&EManageTool::on_replySelectDeviceInfo);
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


void EManageTool::close()
{
    //digital
    foreach (auto var, m_listSensorDisplayDigital) {
        m_listSensorDisplayDigital.removeOne(var);
        var->deleteLater();
        var = nullptr;
    }

    //clock
    foreach (auto var, m_listSensorDisplayClock) {
        m_listSensorDisplayClock.removeOne(var);
        var->deleteLater();
        var = nullptr;
    }

    //multiDisplay
    if(m_frmSensorDisplayMultiple){m_frmSensorDisplayMultiple->deleteLater();m_frmSensorDisplayMultiple = nullptr;}

    //chart
    foreach (auto var, m_listSensorDisplayChart) {
        m_listSensorDisplayChart.removeOne(var);
        var->deleteLater();
        var = nullptr;
    }

    //oscillo
    foreach (auto var, m_listSensorOscillo) {
        m_listSensorOscillo.removeOne(var);
        var->deleteLater();
        var = nullptr;
    }

    //control->config
    foreach (auto var, m_listDeviceConfig) {
        m_listDeviceConfig.removeOne(var);
        var->deleteLater();
        var = nullptr;
    }


    //calib
    foreach (auto var, m_listDeviceCalibration) {
        m_listDeviceCalibration.removeOne(var);
        var->deleteLater();
        var = nullptr;
    }

    //practice base
    if(m_frmSensorPracticeBase){m_frmSensorPracticeBase->deleteLater();m_frmSensorPracticeBase = nullptr;}
    if(m_frmSensorPracticeSoundWave){m_frmSensorPracticeSoundWave->deleteLater();m_frmSensorPracticeSoundWave = nullptr;}
}
