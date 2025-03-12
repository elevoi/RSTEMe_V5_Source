#ifndef FRMPRACTICEBASEINFO_H
#define FRMPRACTICEBASEINFO_H

#include <QMainWindow>
#include "practice/eparameter_practicebase.h"
//#include "file/exportexcel_practicebase.h"

namespace Ui {
class FrmPracticeBaseInfo;
}

class FrmPracticeBaseInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmPracticeBaseInfo(QWidget *parent = nullptr);
    ~FrmPracticeBaseInfo();
    FrmPracticeBaseInfo(EParameter_PracticeBase *para,QWidget *parent = nullptr);

private slots:
    void on_pushButton_clicked();
    void on_checkBox_parameter_toggled(bool checked);

private:
    Ui::FrmPracticeBaseInfo *ui;
    EParameter_PracticeBase::PracticeInfo m_info;
    EParameter_PracticeBase *m_parameterPracticeBase;
    //ExportExcel_practicebase *m_exportExcel=nullptr;

    void init();
    void updateInfo();
    void updateParameter();
    void getInfo();
};

#endif // FRMPRACTICEBASEINFO_H
