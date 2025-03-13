#ifndef EDEVICEPARAMETER_H
#define EDEVICEPARAMETER_H
#include <QVariant>
#include <QPointF>
#include "device/edeviceinfo.h"

class EDeviceParameter
{
public:
    EDeviceParameter();

    /* Exported types ------------------------------------------------------------*/
    enum REG_HOLDING_SENSOR{
        DEVICE_SN1,
        DEVICE_SN2,
        DEVICE_ID,
        DEVICE_PIN,
        //sensor -> value
        SENSOR_RESOLUTION,
        SENSOR_VALUE_HI,
        SENSOR_VALUE_LO,
        SENSOR_TEMP,
        SENSOR_STATUS,				//40019		//8 bit MSB = ErrorCode, 8bit LSB = status sensor
        SENSOR_ADC_HI,				//40023
        SENSOR_ADC_LO,
        SENSOR_ZERO_HI,
        SENSOR_ZERO_LO,
        //sensor -> calib
        SENSOR_CAL01X_HI,		//40007
        SENSOR_CAL01X_LO,
        SENSOR_CAL01Y_HI,
        SENSOR_CAL01Y_LO,
        SENSOR_CAL02X_HI,
        SENSOR_CAL02X_LO,
        SENSOR_CAL02Y_HI,
        SENSOR_CAL02Y_LO,
        SENSOR_CAL03X_HI,
        SENSOR_CAL03X_LO,
        SENSOR_CAL03Y_HI,
        SENSOR_CAL03Y_LO,
        //sensor control
        SENSOR_CTRL,
        //sensor -> buffer
        DATA_TIME_TICK_HI,
        DATA_TIME_TICK_LO,
        DATA_SAMPLE_TIME,
        DATA_SAMPLE_COUNT,
        DATA_BUFFER,

        HOLDING_REG_OFFSET = 40001
    };

    enum BUFFER_TYPE{
        BUF_8_BIT,
        BUF_16_BIT,
        BUF_32_BIT
    };

    struct UnitType{
        QString name="";
        QString symbol = "";
        double factor=1;
        double offset=0;
    };
    struct ResolutionType{
        QString name="";
        double factor=1;
    };
    struct DigitalType{
        int digitCount = 8;
        int digitMode = 1;
    };
    struct ClockType{
        qreal rangeMax = 999999;
        qreal rangeMin = -999999;
    };

    struct DisplayParameter{
        DigitalType digital;
        ClockType   clock;
        QList<UnitType> unit;
        QList<ResolutionType> resolution;
    };



    /* Exported constants --------------------------------------------------------*/

    /* Exported macro ------------------------------------------------------------*/


    /* Exported properties -------------------------------------------------------*/
    //Modbus
    struct RegType{
        quint16 RegStart = 40004;
        quint16 RegNumber = 50;
    };


    struct DataType{
        int serial=0;
        int id = 0;
        QList<qreal> values;
        qreal value=0;
        QList<qreal> adcs;
        qreal adc=0;
        qreal resolution=0;
        qreal zero=0;
        qreal zeroSetup = 0;
        qreal tempCpu=0;
        qreal temp=0;
        bool isZero = false;
        bool isTemp = false;        //whether to use temperature values or not
        bool isTempComp = false;    //whether there is temperature compensation or not
        int   status=0;
        int error=0;
        int   control=0;
        int   sampleTime=1000;
        uint32_t timeTick = 0;
    };
    struct CalibType{
        qreal a1=0;
        qreal b1=0;
        qreal a2=0;
        qreal b2=0;
        int number = 0;
        QList<QPointF> point={QPointF(0,0),QPointF(0,0),QPointF(0,0)};
    };
    //DataType
    inline int serial() const {return m_dataType.serial;}
    inline void setSerial(int var) {m_dataType.serial = var;}
    inline int id() const {return m_dataType.id;}
    inline void setId(int var) {m_dataType.id = var;}

    inline qreal value() const {return m_dataType.value;}
    inline void setValue(qreal var) {m_dataType.value = var;}
    inline QList<qreal> values() const {return m_dataType.values;}
    inline void setValues(QList<qreal> var){m_dataType.values = var;}
    inline void addValues(qreal var){m_dataType.values.append(var);}
    inline void removeValues(){m_dataType.values.clear();}

    inline bool isZero() const{return m_dataType.isZero;}
    inline void setIsZero(bool var){m_dataType.isZero = var;}
    inline qreal zero() const {return m_dataType.zero;}
    inline void setZero(qreal var) {m_dataType.zero = var;}
    inline qreal zeroSetup() const {return m_dataType.zeroSetup;}
    inline void setZeroSetup(qreal var) {m_dataType.zeroSetup = var;}

    inline qreal adc() const {return m_dataType.adc;}
    inline void setAdc(qreal var) {m_dataType.adc = var;}

    inline QList<qreal> adcs() const {return m_dataType.adcs;}
    inline void setAdcs(QList<qreal> var){m_dataType.adcs = var;}
    inline void addAdcs(qreal var){m_dataType.adcs.append(var);}
    inline void removeAdcs(){m_dataType.adcs.clear();}


    inline qreal tempCpu() const {return m_dataType.tempCpu;}
    inline void setTempCpu(qreal var) {m_dataType.tempCpu = var;}
    inline qreal temp() const {return m_dataType.temp;}
    inline void setTemp(qreal var) {m_dataType.temp = var;}
    inline bool isTemp() const{return m_dataType.isTemp;}
    inline void setIsTemp(bool var){m_dataType.isTemp = var;}
    inline bool isTempComp() const{return m_dataType.isTempComp;}
    inline void setIsTempComp(bool var){m_dataType.isTempComp = var;}
    inline int status() const {return m_dataType.status;}
    inline void setStatus(int var) {m_dataType.status = var;}
    inline int error() const {return m_dataType.error;}
    inline void setError(int var) {m_dataType.error = var;}
    inline qreal control() const {return m_dataType.control;}
    inline void setControl(qreal var) {m_dataType.control = var;}
    inline int sampleTime() const {return m_dataType.sampleTime;}
    inline void setSampleTime(int var) {m_dataType.sampleTime = var;}
    inline int timeTick() const {return m_dataType.timeTick;}
    inline void setTimeTick(int var) {m_dataType.timeTick = var;}

    //Calib
    inline int  calibNumber()const{return m_calibType.number;}
    inline void setCalibNumber(int var){m_calibType.number = var;}
    inline QList<QPointF>  calibPoint()const{return m_calibType.point;}
    inline void setCalibPoint(QList<QPointF> var){m_calibType.point = var;}
    inline QPointF  calibPointOne()const{return m_calibType.point.at(0);}
    inline void setCalibPointOne(QPointF var){m_calibType.point.replace(0,var);}
    inline QPointF  calibPointTwo()const{return m_calibType.point.at(1);}
    inline void setCalibPointTwo(QPointF var){m_calibType.point.replace(1,var);}
    inline QPointF  calibPointThree()const{return m_calibType.point.at(2);}
    inline void setCalibPointThree(QPointF var){m_calibType.point.replace(2,var);}


    inline RegType reg()const {return m_regType;}
    inline void setRegType(RegType var){m_regType = var;}
    inline void setRegType(quint16 start,quint16 num){m_regType.RegStart = start;m_regType.RegNumber = num;}

    inline DataType data()const {return m_dataType;}
    inline void setData(DataType var){m_dataType = var;}

    inline BUFFER_TYPE bufferType()const {return m_bufferType;}
    inline void setBufferType(BUFFER_TYPE var){m_bufferType = var;}


    inline CalibType calib()const {return m_calibType;}
    inline void setCalib(CalibType var){m_calibType = var;}
    //Display
    inline DigitalType digital() const {return m_displayParameter.digital;}
    inline void setDigital(DigitalType var){m_displayParameter.digital = var;}
    inline void setDigital(int count,int mode){m_displayParameter.digital.digitCount = count;m_displayParameter.digital.digitMode = mode;}

    inline ClockType clock() const {return m_displayParameter.clock;}
    inline void setClock(ClockType var){m_displayParameter.clock = var;}
    inline void setClock(qreal max,qreal min){m_displayParameter.clock.rangeMax = max;m_displayParameter.clock.rangeMin = min;}

    inline QList<UnitType> unit() const {return m_displayParameter.unit;}
    inline void setUnit(QList<UnitType> var){m_displayParameter.unit = var;}

    inline UnitType currentUnit() const {return m_unit;}
    inline void setCurrentUnit(UnitType var) {m_unit = var;}

    inline qreal division() const {return m_dataType.resolution;}
    inline void setDivision(qreal var){m_dataType.resolution = var;}

    inline QList<ResolutionType> resolution() const {return m_displayParameter.resolution;}
    inline void setResolution(QList<ResolutionType> var){m_displayParameter.resolution = var;}

    inline ResolutionType currentResolution() const {return m_resolution;}
    inline void setCurrentResolution(ResolutionType var){m_resolution = var;}

    inline ResolutionType calibResolution() const {return m_calibResolution;}
    inline void setCalibResolution(ResolutionType var){m_calibResolution = var;}

    //tool
    inline QList<int> toolDisplay(){return m_toolDisplaySensor;}
    inline void setToolDisplay(QList<int> var){m_toolDisplaySensor = var;}

    inline QList<int> toolPractice(){return m_toolPracticeSensor;}
    inline void setToolPractice(QList<int> var){m_toolPracticeSensor = var;}

    inline QList<int> toolControl(){return m_toolControlSensor;}
    inline void setToolControl(QList<int> var){m_toolControlSensor = var;}
    /* Exported functions prototypes ---------------------------------------------*/

    void appendUnit(QString name,QString symbol,double factor,double offset);
    void setCurrentUnit(QString name,QString symbol,double factor,double offset);
    void appendResolution(QString name,double factor=1);

    //Update data
    void updateDataHoldingSensor(quint16 add,quint16 value);
    void finishUpdateDataSensor();

    //Convert float to uint32_t (fixed-point = UInt*pow(10,m))
    static quint8 encode_toUInt8(double f, int m);
    static double decryption_toDouble(quint8 val);
    static double decryption_toDouble(quint8 val,int m);

    static quint16 encode_toUInt16(double f, int m);
    static double decryption_toDouble(quint16 val);
    static double decryption_toDouble(quint16 val,int m);

    static quint32 encode_toUInt32(double f, int m);
    static double decryption_toDouble(quint32 val);
    static double decryption_toDouble(quint32 val,int m);


    //value convert
    static double getConvertValue(double value,UnitType unit,ResolutionType res);

private:
        QList<int> m_toolDisplaySensor = {};
        QList<int> m_toolPracticeSensor = {};
        QList<int> m_toolControlSensor = {};
        DisplayParameter m_displayParameter;
        RegType m_regType;
        DataType m_dataType;
        CalibType m_calibType;
        uint32_t m_timeTickRaw = 0;
        uint32_t m_valueRaw = 0;
        uint32_t m_valueRaw_Count = 0;

        UnitType m_unit = {"","",1,0};
        ResolutionType m_resolution = {"1",0};
        ResolutionType m_calibResolution = {"0.00001",5};

        BUFFER_TYPE m_bufferType = BUFFER_TYPE::BUF_16_BIT;    //0: buffer contain 8-bit, 1: 16-bit, 2: 32-bit

        qreal convertUnit(qreal value);
        qreal getResolution(qreal value);
        void updateBuffer(uint16_t val);
        void setSensorStatus(quint16 val);

        //Calib
        static bool calibSort(QPointF &v1, QPointF &v2);
        void updateCalibFactor();
        double getCalib(double value);
        double calibOnePoint(double value);
        double calibTwoPoint(double value);
        double calibThreePoint(double value);
};

#endif // EDEVICEPARAMETER_H
