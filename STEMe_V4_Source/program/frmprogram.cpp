#include "frmprogram.h"
#include "ui_frmprogram.h"
#include <QDebug>


FrmProgram::FrmProgram(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmProgram)
{
    ui->setupUi(this);
    m_textEdit_Consolse = new QTextEdit();
    m_textEdit_Consolse->setReadOnly(true);
    ui->dockWidget->setWidget(m_textEdit_Consolse);
   /* QObject::connect(ui->dockWidget,&QDockWidget::dockLocationChanged,this,[this](){
                         this->m_textEdit_Consolse->resize(ui->dockWidget->size());
                     });*/
    //m_qjsEngine = new QJSEngine(this);
    m_timerPoll = new QTimer(this);
    QObject::connect(m_timerPoll,&QTimer::timeout,this,[this](){
                             this->m_timeTick++;
                         });
    m_timerPoll->start(100);

}

FrmProgram::~FrmProgram()
{
    delete ui;
}

void FrmProgram::on_pushButton_run_clicked()
{

}

