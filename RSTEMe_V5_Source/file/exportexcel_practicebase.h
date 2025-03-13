#ifndef EXPORTEXCEL_PRACTICEBASE_H
#define EXPORTEXCEL_PRACTICEBASE_H
#include "library/QtXlsxWriter/src/xlsx/xlsxdocument.h"
#include <QFileDialog>
#include "practice/eparameter_practicebase.h"

using namespace QXlsx;

class ExportExcel_practicebase
{

public:
    ExportExcel_practicebase();

    bool newFile();
    bool newFile(EParameter_PracticeBase para);
    void updateFile();

private:
    EParameter_PracticeBase m_practiceBase;

    void writeInfo(Document *xlsx,int *row);
    void writeInfoCell(Document *xlsx,int *row,QString title,QString data,Format format);
    void writeInfoCell(Document *xlsx,int *row,QString title,QString data,Format format,int rowHeight);
    void writeDataCell(Document *xlsx,int *row);
};

#endif // EXPORTEXCEL_PRACTICEBASE_H
