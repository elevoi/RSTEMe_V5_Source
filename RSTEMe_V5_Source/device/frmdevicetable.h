#ifndef FRMDEVICETABLE_H
#define FRMDEVICETABLE_H

#include <QMainWindow>
//system
#include <QCloseEvent>
#include <QVector>
#include <QList>
#include <QHBoxLayout>
#include <QColor>
#include <QMetaType>
#include <QModbusDataUnit>
#include <QScreen>
#include <QListWidgetItem>
#include <QToolButton>
#include <QFrame>
//User
#include "device/edeviceinfolist.h"
namespace Ui {
class FrmDeviceTable;
}

class FrmDeviceTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmDeviceTable(QWidget *parent = nullptr);
    ~FrmDeviceTable();

    enum SelectType{
        SLT_SINGLE,
        SLT_MULTIPLE
    };


    inline SelectType selectType() const {return m_selectType;}
    void setSelectType(SelectType var);

    void setDisableSoftwareType(bool st);
    void setEnable(EDeviceInfo::GroupType type);
    void setEnable(EDeviceInfo dev);
protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;

signals:
    void replySelectDeviceInfo(EDeviceInfo dev);

private slots:
    void on_toolButton_groupSoftware_clicked();

    void on_toolButton_groupSensor_clicked();

    void on_toolButton_groupModule_clicked();

    void on_toolButton_groupSystem_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_selectDevice_clicked();

private:
    Ui::FrmDeviceTable *ui;

    struct SizeWindowDefault{
        QRect window;
        QRect listGroup;
        QRect listType;
        QRect listTool;
        QRect widgetDisplay;
        QRect pushSelect;
        QRect pushCancel;
    };


    int m_buttonGroupClick = -1;
    QList<QToolButton*>     m_buttonTypeList;
    QGridLayout *m_gridLayout = nullptr;
    SelectType  m_selectType = SLT_SINGLE;
    QList<EDeviceInfo>  m_deviceSelectList;
    //main
    EDeviceInfo m_deviceInfo;
    EDeviceInfoList m_edeviceInfoList;
    SizeWindowDefault   m_sizeWindowDefault;
    void loadSizeWindow();
    void resizeWindow();

    void loadTypeList();
    void selectDevice();
    void selectDeviceList();
};

#endif // FRMDEVICETABLE_H
