#include "eparameter_practicebase.h"
#include "file/ejsonfile.h"
#include <QString>

EParameter_PracticeBase::EParameter_PracticeBase()
{
    this->readInfoFile();
}

void EParameter_PracticeBase::saveInfo()
{
    this->writeInfoFile();
}


void EParameter_PracticeBase::writeInfoFile()
{
    EJsonFile _file;
    //info
    _file.setValue("header", m_practiceInfo.header);
    _file.setValue("subject", m_practiceInfo.subject);
    _file.setValue("teacher", m_practiceInfo.teacher);
    _file.setValue("unit", m_practiceInfo.unit);
    _file.setValue("student", m_practiceInfo.student);
    _file.setValue("classroom", m_practiceInfo.classroom);
    _file.setValue("group", m_practiceInfo.group);

    _file.write("ELEVOI", "STEMe","EInfoPracticeBase");
}


void EParameter_PracticeBase::readInfoFile()
{
    EJsonFile _file;
    if(!_file.read("ELEVOI", "STEMe","EInfoPracticeBase"))return;
    //info
    m_practiceInfo.header = _file.value("header", "");
    m_practiceInfo.subject = _file.value("subject", "");
    m_practiceInfo.teacher = _file.value("teacher", "");
    m_practiceInfo.unit = _file.value("unit", "");
    m_practiceInfo.student = _file.value("student", "");
    m_practiceInfo.classroom = _file.value("classroom", "");
    m_practiceInfo.group = _file.value("group", "");
}

