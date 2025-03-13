#include "frmpracticebaseinfo.h"
#include "ui_frmpracticebaseinfo.h"
#include <QDebug>
#include <QDateTime>

FrmPracticeBaseInfo::FrmPracticeBaseInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmPracticeBaseInfo)
{
    this->init();
}

FrmPracticeBaseInfo::~FrmPracticeBaseInfo()
{
    delete ui;
}

FrmPracticeBaseInfo::FrmPracticeBaseInfo(EParameter_PracticeBase *para, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::FrmPracticeBaseInfo),m_parameterPracticeBase(para)
{
    this->init();
}

void FrmPracticeBaseInfo::on_pushButton_clicked()
{
    this->getInfo();
    m_parameterPracticeBase->saveInfo();
    //m_exportExcel->newFile(*m_parameterPracticeBase);
    this->close();
}

void FrmPracticeBaseInfo::init()
{
    ui->setupUi(this);
    this->updateInfo();
    this->updateParameter();
    //qDebug()<<"Note:not updating info report";
   // m_exportExcel = new ExportExcel_practicebase();
}

void FrmPracticeBaseInfo::updateInfo()
{
m_info = m_parameterPracticeBase->practiceInfo();
ui->lineEdit_header->setText(m_info.header);
ui->lineEdit_subject->setText(m_info.subject);
ui->lineEdit_teacher->setText(m_info.teacher);

ui->lineEdit_unit->setText(m_info.unit);
ui->lineEdit_student->setText(m_info.student);
ui->lineEdit_class->setText(m_info.classroom);
ui->lineEdit_group->setText(m_info.group);
ui->plainTextEdit_description->setPlainText(m_info.description);
}

void FrmPracticeBaseInfo::updateParameter()
{
    QString _str="";
    auto _para = m_parameterPracticeBase->practiceType();
    m_info = m_parameterPracticeBase->practiceInfo();
    if(_para.sampleType==0)//sample auto
    {
     _str += "Kiểu lấy mẫu: Lấy mẫu tự động\n";
     _str += "Thời gian thực hành: "+QString::number(_para.timeOut)+" (giây)\n";
    }
    else{
        _str += "Kiểu lấy mẫu: Lấy mẫu bằng tay\n";
        _str += "Thời gian thực hành: "+QString::number(_para.timeManual)+" (giây)\n";
        }
    _str += "Thời gian lấy mẫu: " + QString::number(QVariant(_para.sampleTime).toDouble()/1000)+" (giây)\n";
    if(_para.axisType==0)_str += "Kiểu so sánh: so sánh khác trục tọa độ\n";
        else _str += "Kiểu so sánh: so sánh cùng trục tọa độ\n";
    if(_para.logaritType==0)_str += "Đơn vị đo: theo đơn vị đo\n";
        else _str += "Đơn vị đo: logarit\n";

    if(ui->checkBox_parameter->isChecked())m_info.parameter = _str;
        else m_info.parameter = "";
    ui->plainTextEdit_parameter->setPlainText(m_info.parameter);
}

void FrmPracticeBaseInfo::getInfo()
{
m_info.header = ui->lineEdit_header->text();
m_info.subject = ui->lineEdit_subject->text();
m_info.teacher = ui->lineEdit_teacher->text();

m_info.unit = ui->lineEdit_unit->text();
m_info.student = ui->lineEdit_student->text();
m_info.classroom = ui->lineEdit_class->text();
m_info.group = ui->lineEdit_group->text();
m_info.description=ui->plainTextEdit_description->toPlainText();
m_info.date = QDateTime::currentDateTime().toString("dd/MM/yy-hh:mm:ss");
m_parameterPracticeBase->setPracticeInfo(m_info);
}

void FrmPracticeBaseInfo::on_checkBox_parameter_toggled(bool)
{
    this->updateParameter();
}

