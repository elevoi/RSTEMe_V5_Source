#include "ejsonfile.h"

EJsonFile::EJsonFile()
{

}

void EJsonFile::setValue(QString key, QJsonValue var)
{
    m_jsonObject.insert(key,var);
}

QString EJsonFile::value(QString key, QString valueDefault)
{
return this->getJsonValue(m_jsonObject.value(key),QJsonValue(valueDefault)).toString();
}
int EJsonFile::value(QString key, int valueDefault)
{
return this->getJsonValue(m_jsonObject.value(key),QJsonValue(valueDefault)).toInt();
}
double EJsonFile::value(QString key, double valueDefault)
{
    return this->getJsonValue(m_jsonObject.value(key),QJsonValue(valueDefault)).toDouble();
}

QJsonArray EJsonFile::value(QString key, QJsonArray valueDefault)
{
return this->getJsonValue(m_jsonObject.value(key),QJsonValue(valueDefault)).toArray();
}

QJsonArray EJsonFile::getJsonArray(QList<int> list)
{
    QJsonArray array;
    for(int i=0;i<list.count();i++){
        array.append(QJsonValue(list.at(i)));
    }
    return array;
}
QJsonArray EJsonFile::getJsonArray(QList<double> list)
{
    QJsonArray array;
    for(int i=0;i<list.count();i++){
        array.append(QJsonValue(list.at(i)));
    }
    return array;
}

QJsonArray EJsonFile::getJsonArray(QList<QJsonObject> list)
{
    QJsonArray array;
    for(int i=0;i<list.count();i++){
        array.append(QJsonValue(list.at(i)));
    }
    return array;
}

QList<int> EJsonFile::fromJsonArray(QJsonArray array, int valueDefault)
{
    QList<int> _list;
    for(int i=0;i<array.count();i++){
        if(array.at(i).isUndefined())_list.append(valueDefault);
          else _list.append(array.at(i).toInt());
    }
    return _list;
}

QList<double> EJsonFile::fromJsonArray(QJsonArray array, double valueDefault)
{
    QList<double> _list;
    for(int i=0;i<array.count();i++){
        if(array.at(i).isUndefined())_list.append(valueDefault);
          else _list.append(array.at(i).toDouble());
    }
    return _list;
}

QList<QJsonObject> EJsonFile::fromJsonArray(QJsonArray array, QJsonObject valueDefault)
{
    QList<QJsonObject> _list;
    for(int i=0;i<array.count();i++){
        if(array.at(i).isUndefined())_list.append(valueDefault);
          else _list.append(array.at(i).toObject());
    }
    return _list;
}



QJsonValue EJsonFile::getJsonValue(QJsonValue value, QJsonValue init)
{
    if(value==QJsonValue::Undefined)return init;
    else return value;
}

void EJsonFile::clear()
{
    m_jsonObject = QJsonObject();
}

QJsonObject EJsonFile::getJsonObject(QtCharts::QSplineSeries *series)
{
QJsonObject _jsonObj;
QJsonArray _points;
if(!series)return _jsonObj;
_jsonObj.insert("name",series->name());
//series
for(int i=0;i<series->count();i++){
    QJsonObject _obj;
    _obj.insert("time",series->at(i).x());
    _obj.insert("value",series->at(i).y());
    _points.append(_obj);
}
_jsonObj.insert("series",_points);
//axis y
QtCharts::QValueAxis* _axis=nullptr;
foreach (auto var, series->attachedAxes()) {
    if(var->alignment()==Qt::AlignLeft){
        _axis = dynamic_cast<QtCharts::QValueAxis*>(var);
    }
}
if(_axis){
    _jsonObj.insert("axisMin",_axis->min());
    _jsonObj.insert("axisMax",_axis->max());
    }
return _jsonObj;
}

bool EJsonFile::fromJsonObject(QJsonObject obj, QSplineSeries *series,QValueAxis *axis)
{
if(!series)return false;
series->setName(obj.value("name").toString(""));
QJsonArray _points = obj.value("series").toArray();
//series
for(int i=0;i<_points.count();i++){
    QJsonObject _obj = _points.at(i).toObject();
    auto _p = QPointF(_obj.value("time").toDouble(0),_obj.value("value").toDouble(0));
    series->append(_p);
}
if(!axis)return false;
axis->setRange(obj.value("axisMin").toDouble(0),obj.value("axisMax").toDouble(1));
return true;
}


void EJsonFile::write(const QString &organization, const QString &application, const QString &key)
{
    QSettings settings(organization,application);
    settings.beginGroup(key);
    settings.setValue(key,m_jsonObject);
    settings.endGroup();
}

bool EJsonFile::read(const QString &organization, const QString &application, const QString &key)
{
    QSettings settings(organization,application);
    settings.beginGroup(key);
    m_jsonObject = settings.value(key).toJsonObject();
    settings.endGroup();
    return !m_jsonObject.isEmpty();
}

bool EJsonFile::saveFile(QString fileName,QString extension,QJsonObject obj)
{
    //Show dialog file, get path of file
    QString _ext = "STEMe files (*."+extension+")";
    QString m_fileName = QFileDialog::getSaveFileName(nullptr,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/practice/"+fileName,_ext);
    if(m_fileName.isEmpty())return false;
    //Open file
    if(!m_fileName.contains(extension,Qt::CaseSensitive))m_fileName += extension;
    QFile fileDev(m_fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(nullptr,QObject::tr("Không thể lưu tệp tin!"),fileDev.errorString());
        return false;
    }
    //Save jsonDocument to file
    QJsonDocument *doc = new QJsonDocument(obj);
    fileDev.write(doc->toJson().toBase64());
    fileDev.close();
    return true;
}

bool EJsonFile::openFile(QString extension,QJsonObject &obj)
{
    //Show dialog file, get path of file
    QString _ext = "STEMe files (*."+extension+")";
    QString m_fileName = QFileDialog::getOpenFileName(nullptr,QObject::tr("Open File"),QCoreApplication::applicationDirPath()+"/practice",_ext);
    if(m_fileName.isEmpty())return false;

    //Open file
    QFile fileDev(m_fileName);
    if(!fileDev.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(nullptr,QObject::tr("Không thể mở tệp tin!"),fileDev.errorString());
        return false;
    }
    //get jsonDocument from file
    QJsonParseError jsonParseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(QByteArray::fromBase64(fileDev.readAll()),&jsonParseError);
    fileDev.close();
    if(jsonParseError.error != QJsonParseError::NoError)return false;
    //get All device from JsonDocument
    obj = jsonDoc.object();
    return true;
}
