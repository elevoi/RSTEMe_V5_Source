#ifndef FRMPROGRAM_H
#define FRMPROGRAM_H

#include <QMainWindow>
#include <QTextEdit>
//#include <QJSEngine>
#include <QTimer>

namespace Ui {
class FrmProgram;
}

class FrmProgram : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmProgram(QWidget *parent = nullptr);
    ~FrmProgram();

private slots:
    void on_pushButton_run_clicked();

private:
    Ui::FrmProgram *ui;
    //QJSEngine* m_qjsEngine = nullptr;
    QTimer *m_timerPoll = nullptr;

    QTextEdit* m_textEdit_Consolse = nullptr;

    //variables
    int m_timeTick = 0;
    int m_setValue = 0;
};

#endif // FRMPROGRAM_H
