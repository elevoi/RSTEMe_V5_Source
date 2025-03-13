QT       += core gui serialbus charts serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = STEMe
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++17
CONFIG += static

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    chart/echartcallout.cpp \
    chart/echartcrosshair.cpp \
    chart/echartview.cpp \
    comm/econnection.cpp \
    comm/econnectioninfo.cpp \
    comm/emodbus.cpp \
    comm/erequestunit.cpp \
    comm/frmconnectionsetup.cpp \
    control/frmdeviceconfig.cpp \
    device/def/edef_v5.cpp \
    device/def/edeviceparameter.cpp \
    device/edevice.cpp \
    device/edeviceinfo.cpp \
    device/edeviceinfolist.cpp \
    device/edevicelist.cpp \
    device/frmdevicecalibration.cpp \
    device/frmdevicetable.cpp \
    device/software/frmaccountsetup.cpp \
    display/frmsensordisplaychart.cpp \
    display/frmsensordisplaymultiple.cpp \
    display/frmsensoroscillo.cpp \
    display/widsensordisplaydigital.cpp \
    display/widsensortooldigital.cpp \
    file/efile_basepractice.cpp \
    file/ejsonfile.cpp \
    manage/emanagedevice.cpp \
    device/frmaddsensor.cpp \
    device/frmdeviceicon.cpp \
    device/frmdeviceselection.cpp \
    device/frmdevicesetup.cpp \
    device/frmsearchdevice.cpp \
    device/module/emodule.cpp \
    device/repair/frmrepairmodbusconnection.cpp \
    device/def/esensor.cpp \
    device/software/frmsetupserial.cpp \
    display/frmsensordisplayclock.cpp \
    display/frmsensordisplaydigital.cpp \
    elog.cpp \
    etypedef.cpp \
        main.cpp \
        mainwindow.cpp \
    manage/emanagemodule.cpp \
    manage/emanagesensor.cpp \
    manage/emanagesoftware.cpp \
    manage/emanagesystem.cpp \
    manage/emanagetool.cpp \
    practice/eparameter_practicebase.cpp \
    practice/frmpracticebaseinfo.cpp \
    practice/frmsensorpracticebase.cpp \
    practice/frmsensorpracticesoundwave.cpp \
    program/frmprogram.cpp \
    root/eaccountinfo.cpp \
    root/eaccountlist.cpp \
    root/frmlogin.cpp \
    widget/econtainer.cpp

HEADERS += \
    chart/echartcallout.h \
    chart/echartcrosshair.h \
    chart/echartview.h \
    comm/econnection.h \
    comm/econnectioninfo.h \
    comm/emodbus.h \
    comm/erequestunit.h \
    comm/frmconnectionsetup.h \
    control/frmdeviceconfig.h \
    device/def/edef_v5.h \
    device/def/edeviceparameter.h \
    device/edevice.h \
    device/edeviceinfo.h \
    device/edeviceinfolist.h \
    device/edevicelist.h \
    device/frmdevicecalibration.h \
    device/frmdevicetable.h \
    device/software/frmaccountsetup.h \
    display/frmsensordisplaychart.h \
    display/frmsensordisplaymultiple.h \
    display/frmsensoroscillo.h \
    display/widsensordisplaydigital.h \
    display/widsensortooldigital.h \
    file/efile_basepractice.h \
    file/ejsonfile.h \
    file/exportexcel_practicebase.h \
    manage/emanagedevice.h \
    device/frmaddsensor.h \
    device/frmdeviceicon.h \
    device/frmdeviceselection.h \
    device/frmdevicesetup.h \
    device/frmsearchdevice.h \
    device/module/emodule.h \
    device/repair/frmrepairmodbusconnection.h \
    device/def/esensor.h \
    device/software/frmsetupserial.h \
    display/frmsensordisplayclock.h \
    display/frmsensordisplaydigital.h \
    elog.h \
    etypedef.h \
        mainwindow.h \
    manage/emanagemodule.h \
    manage/emanagesensor.h \
    manage/emanagesoftware.h \
    manage/emanagesystem.h \
    manage/emanagetool.h \
    practice/eparameter_practicebase.h \
    practice/frmpracticebaseinfo.h \
    practice/frmsensorpracticebase.h \
    practice/frmsensorpracticesoundwave.h \
    program/frmprogram.h \
    root/eaccountinfo.h \
    root/eaccountlist.h \
    root/frmlogin.h \
    widget/econtainer.h



FORMS += \
    comm/frmconnectionsetup.ui \
    control/frmdeviceconfig.ui \
    device/frmaddsensor.ui \
    device/frmdevicecalibration.ui \
    device/frmdeviceicon.ui \
    device/frmdeviceselection.ui \
    device/frmdevicesetup.ui \
    device/frmdevicetable.ui \
    device/frmsearchdevice.ui \
    device/repair/frmrepairmodbusconnection.ui \
    device/software/frmaccountsetup.ui \
    device/software/frmsetupserial.ui \
    display/frmsensordisplaychart.ui \
    display/frmsensordisplayclock.ui \
    display/frmsensordisplaydigital.ui \
    display/frmsensordisplaymultiple.ui \
    display/frmsensoroscillo.ui \
    display/widsensordisplaydigital.ui \
    display/widsensortooldigital.ui \
        mainwindow.ui \
    practice/frmpracticebaseinfo.ui \
    practice/frmsensorpracticebase.ui \
    practice/frmsensorpracticesoundwave.ui \
    program/frmprogram.ui \
    root/frmlogin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    chart.qrc \
    device.qrc \
    group.qrc

RC_ICONS = icon/group/Steme_icon.ico
