#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//system
#include <QGuiApplication>
#include <QMainWindow>
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

//manage
#include "manage/emanagedevice.h"
#include <etypedef.h>


namespace Ui {

class MainWindow;
}

class EConnection;
//class VButtonSingle;



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    static QString EModbusComPort;
    static int     EModbusBaudRate;

    void close();
protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;
    bool eventFilter(QObject* watched, QEvent* event) override;
signals:
    void login();
private slots:
    void on_stateChange(ETypeDef::StateChange state);
    void on_error(EDevice::Error error,EDevice *dev);

    void on_toolButton_groupSoftware_clicked();

    void on_toolButton_groupSensor_clicked();

    void on_toolButton_groupModule_clicked();

    void on_toolButton_groupSystem_clicked();

    void on_pushButton_TypeList_clicked();

    void on_toolButton_groupSearch_clicked();

    void on_toolButton_groupConnection_clicked();

    void on_toolButton_login_clicked();

    void on_toolButton_clearDevice_clicked();

private:
    Ui::MainWindow *ui;

    bool m_frameWindowFullScreen = false;

    struct SizeWindowDefault{
        QRect window;
        QRect listGroup;
        QRect listType;
        QRect listTool;
        QRect widgetDisplay;
        QRect pushLogin;
        QRect pushClear;
    };


    //main
    EDeviceInfo m_deviceInfo;
    EDeviceInfoList m_edeviceInfoList;
    EManageDevice *m_manageDevice = nullptr;
    SizeWindowDefault   m_sizeWindowDefault;
    void loadSizeWindow();
    void resizeWindow();



    //For ListGroup
    bool m_showDeviceSerial = false;
    int m_buttonGroupClick = -1;
    int m_deltaJumpWidgetDisplay=0;
    QIcon *m_toolButtonIcon = nullptr;
    QList<QString> m_iconListGroup;
    QList<QToolButton*>     m_buttonTypeList;
    QList<QToolButton*>     m_buttonOnlineList;
    QList<EDeviceInfo>     m_edeviceOnlineList;

    void statusConnectModbus(bool isConnect);
    void checkDeviceList(); //if no device, add devicesetup
    void blinkTypeList();
    void hideTypeList();
    void loadTypeList();
    void loadListDeviceOnline();

    void deviceConnectChanged(bool status,EDeviceInfo dev);

};

#endif // MAINWINDOW_H
