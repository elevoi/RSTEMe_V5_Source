#include "edef_v5.h"

EDef::EDef(EDeviceInfo dev)
{
m_edeviceInfo = dev;
this->init();
}

EDef::~EDef()
{

}

EDeviceParameter EDef::parameter()
{
    return m_para;
}
/*
EDeviceParameter EDef::parameter(EDeviceInfo dev)
{
    m_edeviceInfo = dev;
    return m_para;
}*/

void EDef::setParameter(EDeviceParameter para)
{
    m_para = para;
}

void EDef::setRequest(ERequestUnit request)
{
    m_requestUnit = request;
    for(quint16 i=0;i<request.data().valueCount();i++){
        switch(request.data().registerType()){
        case QModbusDataUnit::RegisterType::HoldingRegisters:
            m_para.updateDataHoldingSensor((request.data().startAddress()-40001)+i,request.data().value(i));
            break;
        case QModbusDataUnit::RegisterType::Coils:
            break;
        case QModbusDataUnit::RegisterType::DiscreteInputs:
            break;
        case QModbusDataUnit::RegisterType::InputRegisters:
            break;
        case QModbusDataUnit::RegisterType::Invalid:
            break;
        }
    }
    m_para.finishUpdateDataSensor();
}

void EDef::init()
{
    //////////////////////////////////////////////////////////////////default private
    //sensor
    m_para.setDigital(8,1);
    m_para.setClock(100,0);
    //unit
    //resolution
    //isTemp
    m_para.setIsZero(false);
    m_para.setZeroSetup(0);
    m_para.setIsTemp(false);
    m_para.setIsTempComp(false);
    //data buffer type
    m_para.setBufferType(EDeviceParameter::BUF_16_BIT);
    //tool
    m_para.setToolDisplay({0x14010000,0x14020000,0x14030000,0x14040000,0x14050000});
    m_para.setToolPractice({0x14610000});
    m_para.setToolControl({0x14510000,0x10090000});
    /////////////////////////////////////////////////////////////////////private config
    switch(m_edeviceInfo.serial(EDeviceInfo::SERIAL_DEVICE)){
        case 0x01://TEMPRATURE SENSOR
            //sensor
            m_para.setDigital(8,1);
            m_para.setClock(250,-50);
            //unit
            m_para.appendUnit("Độ C - Celsius","C",0.01,0);
            m_para.appendUnit("Độ F - Fahrenheit","F",0.01,273.15);
            m_para.appendUnit("Độ K - Kelvin","K",(9.0/0.5)*0.01,32.0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("0.01",2);
            m_para.appendResolution("0.1",1);
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(0));
            break;
        case 0x02://HUMIDITY SENSOR
            //sensor
            m_para.setDigital(8,1);
            m_para.setClock(100,0);
            //unit
            m_para.appendUnit("Độ ẩm tương đối","%RH",0.01,0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("0.01",2);
            m_para.appendResolution("0.1",1);
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(0));
            //isTemp
            m_para.setIsTemp(true);
            break;
        case 0x03://FORCE SENSOR
            //sensor
            m_para.setDigital(8,1);
            m_para.setClock(5000,0);
            //unit
            m_para.appendUnit("Đo lực (Newton)","N",0.001,0);
            m_para.appendUnit("Đo khối lượng (Gram)","G",0.1,0);
            m_para.appendUnit("Đo khối lượng (Kilogram)","Kg",0.0001,0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("0.001",3);
            m_para.appendResolution("0.01",2);
            m_para.appendResolution("0.1",1);
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(0));
            //isTemp
            m_para.setIsZero(true);
            break;
        case 0x04://PRESSURE SENSOR
            //sensor
            m_para.setDigital(8,1);
            m_para.setClock(250000,0);
            //unit
            m_para.appendUnit("Pascal","Pa",1,0);
            m_para.appendUnit("Kilopascal","kPa",0.001,0);
            m_para.appendUnit("Bar","bar",0.00001,0);
            m_para.appendUnit("psi","psi",0.0001450377,0);
            m_para.appendUnit("ksi","ksi",1.450377377E-7,0);
            m_para.appendUnit("Standard atmosphere","atm",0.0000098692,0);
            m_para.appendUnit("Torr","Torr",0.0075006168,0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("0.001",3);
            m_para.appendResolution("0.01",2);
            m_para.appendResolution("0.1",1);
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(0));
            //isTemp
            m_para.setIsZero(true);
            m_para.setZeroSetup(100000);//air pressure is 100000
            //data buffer type
            m_para.setBufferType(EDeviceParameter::BUF_32_BIT);
            break;
        case 0x05://PRESSURE SENSOR
            //sensor
            m_para.setDigital(6,1);
            m_para.setClock(3300,0);
            //unit
            m_para.appendUnit("Voltage","V",0.001,0);
            m_para.appendUnit("Decibel","dB",0.001,0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("0.001",3);
            m_para.appendResolution("0.01",2);
            m_para.appendResolution("0.1",1);
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(0));
            //tool
            m_para.setToolPractice({0x14610000,0x14620000});
            break;
        case 0x06://pH SENSOR
            //sensor
            m_para.setDigital(8,1);
            m_para.setClock(14,0);
            //unit
            m_para.appendUnit("pH","pH",0.001,0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("0.001",3);
            m_para.appendResolution("0.01",2);
            m_para.appendResolution("0.1",1);
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(0));
            //isTemp
            m_para.setIsZero(true);
            m_para.setZeroSetup(7000);//pH in pure water or distilled water
            m_para.setIsTemp(true);
            break;
        case 0x07://DO SENSOR
            //sensor
            m_para.setDigital(8,1);
            m_para.setClock(20,0);
            //unit
            m_para.appendUnit("mg/L","mg",0.001,0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("0.001",3);
            m_para.appendResolution("0.01",2);
            m_para.appendResolution("0.1",1);
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(0));
            //isTemp
            m_para.setIsZero(true);
            m_para.setZeroSetup(0);
            m_para.setIsTemp(true);
            break;
        case 0x09://DO SENSOR
            //sensor
            m_para.setDigital(8,1);
            m_para.setClock(50,0);
            //unit
            m_para.appendUnit("ppt","ppt",0.001,0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("0.001",3);
            m_para.appendResolution("0.01",2);
            m_para.appendResolution("0.1",1);
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(0));
            //isTemp
            m_para.setIsZero(true);
            m_para.setZeroSetup(0);
            m_para.setIsTemp(true);
            //data buffer type
            m_para.setBufferType(EDeviceParameter::BUF_32_BIT);
            break;
        case 0x12://LIGHT SENSOR
            //sensor
            m_para.setDigital(8,1);
            m_para.setClock(65000,0);
            //unit
            m_para.appendUnit("Độ rọi (Lux)","lx",1,0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(0));
            //isTemp
            m_para.setIsZero(true);
            break;
        case 0x15://Conductivity SENSOR
            //sensor
            m_para.setDigital(8,1);
            m_para.setClock(14,0);
            //unit
            m_para.appendUnit("uS/cm","uS",0.1,0);
            m_para.appendUnit("mS/cm","mS",0.001,0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("0.001",3);
            m_para.appendResolution("0.01",2);
            m_para.appendResolution("0.1",1);
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(3));
            //isTemp
            m_para.setIsZero(true);
            m_para.setIsTemp(true);
            //data buffer type
            m_para.setBufferType(EDeviceParameter::BUF_32_BIT);
            //tool
            break;
        case 0x50://VOLTAGE SENSOR
            //sensor
            m_para.setDigital(8,1);
            m_para.setClock(12000,-12000);
            //unit
            m_para.appendUnit("Volts (V)","V",0.001,0);
            m_para.appendUnit("Millivolts (mV)","mV",1,0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("0.001",3);
            m_para.appendResolution("0.01",2);
            m_para.appendResolution("0.1",1);
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(0));
            //isTemp
            m_para.setIsZero(true);
            break;
        case 0x51://AMPE SENSOR
            //sensor
            m_para.setDigital(8,1);
            m_para.setClock(3000,-3000);
            //unit
            m_para.appendUnit("Ampere (A)","A",0.001,0);
            m_para.appendUnit("Milliampere (mA)","mA",1,0);
            m_para.setCurrentUnit(m_para.unit().at(0));
            //resolution
            m_para.appendResolution("0.001",3);
            m_para.appendResolution("0.01",2);
            m_para.appendResolution("0.1",1);
            m_para.appendResolution("1",0);
            m_para.setCurrentResolution(m_para.resolution().at(0));
            //isTemp
            m_para.setIsZero(true);
            break;
        }
}
