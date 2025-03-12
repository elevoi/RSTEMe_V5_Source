#ifndef FRMDEVICEICON_H
#define FRMDEVICEICON_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class FrmDeviceIcon;
}

class FrmDeviceIcon : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmDeviceIcon(QWidget *parent = nullptr);
    ~FrmDeviceIcon();

signals:
    void setIcon(QString path);

private slots:
    void on_pushButton_Cancel_clicked();

    void on_listWidget_Icon_itemClicked(QListWidgetItem *item);

    void on_listWidget_Icon_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_Select_clicked();

private:
    Ui::FrmDeviceIcon *ui;
    //resize
    QRect m_rectPushOk;
    QRect m_rectPushCancel;
    QSize m_sizeMainWindow;
    QSize m_sizeListWidget;

    //variant
    QList<QString> m_iconListPath;
    QString m_iconPath="";

    void resizeEvent(QResizeEvent*);

    void loadIcon();
};

#endif // FRMDEVICEICON_H
