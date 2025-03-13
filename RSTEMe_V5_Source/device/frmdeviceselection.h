#ifndef FRMDEVICESELECTION_H
#define FRMDEVICESELECTION_H

#include <QMainWindow>
#include <QVariant>
#include <QToolButton>
#include <device/edevice.h>
#include <device/edeviceinfolist.h>
#include <QCloseEvent>

namespace Ui {
class FrmDeviceSelection;
}

class FrmDeviceSelection : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmDeviceSelection(QWidget *parent = nullptr);
    ~FrmDeviceSelection();

    void setDevice(EDeviceInfo dev);
signals:
    void selectDevice(EDeviceInfo dev);
protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;
private slots:
    void on_pushButton_cancel_clicked();

private:
    Ui::FrmDeviceSelection *ui;
    QSize m_sizeWindow=QSize(1,1);
    QSize m_sizeGroupDisplay=QSize(1,1);
    QSize m_sizeListDisplay=QSize(1,1);
    QRect m_sizeListControl=QRect(1,1,1,1);
    QRect m_rectGroupControl = QRect(1,1,1,1);
    QRect m_rectPushCancel = QRect(1,1,1,1);

    EDeviceInfo m_deviceInfo;
    EDeviceInfoList m_deviceInfoList;

    QList<QToolButton*> m_buttonListToolDisplay;
    QList<QToolButton*> m_buttonListToolPractice;
    QList<QToolButton*> m_buttonListToolControl;

    void init();
    void loadToolDisplay();
    void loadToolPractice();
    void loadToolControl();
    void showDevice(EDeviceInfo dev);
};

#endif // FRMDEVICESELECTION_H
