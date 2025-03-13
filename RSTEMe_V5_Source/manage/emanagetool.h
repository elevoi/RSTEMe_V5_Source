#ifndef EMANAGETOOL_H
#define EMANAGETOOL_H

#include <QObject>
#include <device/edevice.h>
#include <device/edeviceinfo.h>
#include <comm/econnection.h>
//calib
#include "device/frmdevicecalibration.h"

//display
#include "display/frmsensordisplaydigital.h"
#include <display/frmsensordisplayclock.h>
#include <display/frmsensordisplaychart.h>
#include <display/frmsensordisplaymultiple.h>
#include <display/frmsensoroscillo.h>
//practice
#include <practice/frmsensorpracticebase.h>
#include <practice/frmsensorpracticesoundwave.h>
//control
#include <control/frmdeviceconfig.h>


class EManageTool : public QObject
{
    Q_OBJECT
public:
    explicit EManageTool(QObject *parent = nullptr);
    ~EManageTool();
    //select device
    void setSelectDevice(EDeviceInfo devInfo,EDevice *edev);

    void activateDevice(EDeviceInfo dev);

    inline void setConnection(EConnection *var){m_econnection = var;}
signals:
    void replySelectDeviceInfo(EDeviceInfo dev);
    void replySelectDevice(EDeviceInfo dev,EDevice *edev);
    void stateChange(ETypeDef::StateChange state);

private slots:
    void on_replySelectDeviceInfo(EDeviceInfo dev);
    void on_stateChange(ETypeDef::StateChange state);

private:
    EConnection *m_econnection = nullptr;
    EDeviceInfo m_edeviceInfo;
    //digital
    FrmSensorDisplayDigital *m_frmSensorDisplayDigital = nullptr;
    QList<FrmSensorDisplayDigital*> m_listSensorDisplayDigital;
    FrmSensorDisplayDigital* getSensorDisplayDigital(EDevice *dev);

    //digitalMultiple
    FrmSensorDisplayMultiple *m_frmSensorDisplayMultiple = nullptr;

    //clock
    FrmSensorDisplayClock *m_frmSensorDisplayClock = nullptr;
    QList<FrmSensorDisplayClock*> m_listSensorDisplayClock ;
    FrmSensorDisplayClock* getSensorDisplayClock(EDevice *dev);

    //chart
    FrmSensorDisplayChart *m_frmSensorDisplayChart = nullptr;
    QList<FrmSensorDisplayChart*> m_listSensorDisplayChart;
    FrmSensorDisplayChart* getSensorDisplayChart(EDevice *dev);

    //oscillo
    FrmSensorOscillo *m_frmSensorOscillo = nullptr;
    QList<FrmSensorOscillo*> m_listSensorOscillo;
    FrmSensorOscillo* getSensorOscillo(EDevice *dev);

    //practice
    FrmSensorPracticeBase *m_frmSensorPracticeBase = nullptr;//base practice
    FrmSensorPracticeSoundWave *m_frmSensorPracticeSoundWave = nullptr;//practice sound waves
    //Control->config
    FrmDeviceConfig *m_frmDeviceConfig = nullptr;
    QList<FrmDeviceConfig*> m_listDeviceConfig;
    FrmDeviceConfig* getDeviceConfig(EDevice *dev);




    //calib
    FrmDeviceCalibration *m_frmDeviceCalibration = nullptr;
    QList<FrmDeviceCalibration*> m_listDeviceCalibration ;
    FrmDeviceCalibration* getDeviceCalibration(EDevice *dev);


    void close();

};

#endif // EMANAGETOOL_H
