#ifndef EFILE_BASEPRACTICE_H
#define EFILE_BASEPRACTICE_H
#include "practice/eparameter_practicebase.h"
#include "file/ejsonfile.h"

class EFile_BasePractice
{
public:
    EFile_BasePractice();

    void saveFile(EParameter_PracticeBase para);
    bool openFile(EParameter_PracticeBase &para);
private:
    EParameter_PracticeBase m_parameter;

    QtCharts::QSplineSeries* m_series=nullptr;
    QValueAxis* m_axisY=nullptr;
    //parameter file
    void writeFile();
    bool readFile();
    //chart
    void updateChart(EJsonFile &file);
};

#endif // EFILE_BASEPRACTICE_H
