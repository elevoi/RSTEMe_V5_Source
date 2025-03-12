#ifndef FRMDEVICESETUP_H
#define FRMDEVICESETUP_H

#include <QMainWindow>
#include <QSize>
#include "device/edeviceinfolist.h"
#include "device/frmaddsensor.h"
#include <etypedef.h>
#include <QStandardItemModel>
#include <QTreeWidgetItem>
#include <QCloseEvent>


namespace Ui {
class FrmDeviceSetup;
}

class FrmDeviceSetup : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmDeviceSetup(QWidget *parent = nullptr);
    ~FrmDeviceSetup();
signals:
    void stateChange(ETypeDef::StateChange state);

private slots:
    void on_setup(EDeviceInfo dev);

    void on_pushButton_addDevice_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_remove_clicked();


    void on_pushButton_save_clicked();

    void on_pushButton_saveList_clicked();

    void on_treeWidgetDevice_collapsed(const QModelIndex &index);

    void on_treeWidgetDevice_expanded(const QModelIndex &index);

    void on_pushButton_openList_clicked();


    void on_treeWidgetDevice_itemSelectionChanged();

    void on_treeWidgetDevice_itemDoubleClicked(QTreeWidgetItem *item, int column);

protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;
private:
    Ui::FrmDeviceSetup *ui;


    EDeviceInfo m_deviceInfo;
    EDeviceInfoList m_edeviceInfoList;
    QStandardItemModel *m_itemModel = nullptr;

    QList<bool> m_treeExpandedStatus;
    //Form
    FrmAddSensor *m_frmAddSensor = nullptr;

    //size of widget
    QSize m_sizeTreeViewDevice = QSize(1,1);
    QSize m_sizeframeDevice = QSize(1,1);
    QSize m_deviceSetup = QSize(1,1);
    QSize m_sizeEditDescription = QSize(1,1);

    QRect m_pointFrameCancel;
    QRect m_pointRemove;
    QRect m_pointSave;
    QRect m_pointSaveList;
    QRect m_pointOpenList;


    void refresh();
    void setTreeView();
    void loadDeviceInfo();
    void showSensor();
};

#endif // FRMDEVICESETUP_H
