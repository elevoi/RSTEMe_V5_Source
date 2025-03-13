#include "efile_basepractice.h"

EFile_BasePractice::EFile_BasePractice()
{

}

void EFile_BasePractice::saveFile(EParameter_PracticeBase para)
{
    m_parameter = para;
    this->writeFile();
}

bool EFile_BasePractice::openFile(EParameter_PracticeBase &para)
{
    if(this->readFile()){
        para=m_parameter;
        return true;
    }
    return false;
}

void EFile_BasePractice::writeFile()
{
    EJsonFile _file;
    auto m_practiceInfo = m_parameter.practiceInfo();
    auto m_practiceType = m_parameter.practiceType();
    //info
    _file.setValue("header", m_practiceInfo.header);
    _file.setValue("subject", m_practiceInfo.subject);
    _file.setValue("teacher", m_practiceInfo.teacher);
    _file.setValue("unit", m_practiceInfo.unit);
    _file.setValue("student", m_practiceInfo.student);
    _file.setValue("classroom", m_practiceInfo.classroom);
    _file.setValue("group", m_practiceInfo.group);
    //parameter
    _file.setValue("timeOut", m_practiceType.timeOut);
    _file.setValue("sampleTime", m_practiceType.sampleTime);
    _file.setValue("sampleType", m_practiceType.sampleType);
    _file.setValue("lineType", m_practiceType.lineType);
    _file.setValue("axisType", m_practiceType.axisType);
    _file.setValue("logaritType", m_practiceType.logaritType);
    //device
    QList<QJsonObject> _dev;
    for(int i=0;i<m_practiceType.devices.count();i++){
        EDeviceInfo _info = m_practiceType.devices.at(i);
        _dev.append(_info.getJsonDevice());
    }
    _file.setValue("devices",_file.getJsonArray(_dev));
    //charts
    QJsonArray _jseries;
    for(int i=0;i<m_practiceType.series.count();i++){
        _jseries.append(_file.getJsonObject(m_practiceType.series.at(i)));
    }
    _file.setValue("series",_jseries);

    _file.saveFile(m_practiceInfo.unit,"prc",_file.jsonObject());
}

bool EFile_BasePractice::readFile()
{
    EJsonFile _file;
    QJsonObject obj;
    if(!_file.openFile("prc",obj))return false;
    _file.setJsonObject(obj);
    auto m_practiceInfo = m_parameter.practiceInfo();
    auto m_practiceType = m_parameter.practiceType();
    //info
    m_practiceInfo.header = _file.value("header", "");
    m_practiceInfo.subject = _file.value("subject", "");
    m_practiceInfo.teacher = _file.value("teacher", "");
    m_practiceInfo.unit = _file.value("unit", "");
    m_practiceInfo.student = _file.value("student", "");
    m_practiceInfo.classroom = _file.value("classroom", "");
    m_practiceInfo.group = _file.value("group", "");
    //parameter
    m_practiceType.timeOut = _file.value("timeOut", 10.0);
    m_practiceType.sampleTime = _file.value("sampleTime", 1000);
    m_practiceType.sampleType = _file.value("sampleType", 0);
    m_practiceType.lineType = _file.value("lineType", 0);
    m_practiceType.axisType = _file.value("axisType", 1);
    m_practiceType.logaritType = _file.value("logaritType", 0);

    //device
    QList<QJsonObject> _objList;
    QJsonObject _new;
    QJsonArray _arr;
    QJsonArray _value = _file.value("devices",_arr);
    _objList = _file.fromJsonArray(_value,_new);
    m_practiceType.devices.clear();
    for(int i=0;i<_objList.count();i++){
        if(!_objList.at(i).isEmpty()){
            EDeviceInfo _edev;
            _edev.setJsonDevice(_objList.at(i));
            m_practiceType.devices.append(_edev);
        }
    }
    //charts
    m_parameter.setPracticeInfo(m_practiceInfo);
    m_parameter.setPracticeType(m_practiceType);
    this->updateChart(_file);
    return true;
}


void EFile_BasePractice::updateChart(EJsonFile &file)
{
    QList<QJsonObject> _objList;
    QJsonObject _new;
    auto m_practiceType = m_parameter.practiceType();
    QJsonArray _arr;
    QJsonArray _value = file.value("series",_arr);
    _objList = file.fromJsonArray(_value,_new);
    foreach (auto var, m_practiceType.series) {
        m_practiceType.series.removeOne(var);
        var->deleteLater();
        var=nullptr;
    }
    foreach (auto var, m_practiceType.axis) {
        m_practiceType.axis.removeOne(var);
        var->deleteLater();
        var=nullptr;
    }
    for(int i=0;i<_objList.count();i++){
        if(!_objList.at(i).isEmpty()){
            m_axisY = new QValueAxis;
            m_series = new QSplineSeries;
            if(file.fromJsonObject(_objList.at(i),m_series,m_axisY)){
                m_practiceType.series.append(m_series);
                m_practiceType.axis.append(m_axisY);
            }
            else{
                m_axisY->deleteLater();
                m_axisY=nullptr;
                m_series->deleteLater();
                m_series=nullptr;
            }
        }
    }
    m_parameter.setPracticeType(m_practiceType);
}
