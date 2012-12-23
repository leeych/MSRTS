#ifndef DEVICEMANAGEPAGE_H
#define DEVICEMANAGEPAGE_H

#include <QMainWindow>
#include "ui/mtabwidget.h"
#include "devicetriggerlist.h"
#include "devicedataacquisitionlist.h"

class DeviceManagePage : public QMainWindow
{
    Q_OBJECT
public:
    explicit DeviceManagePage(QWidget *parent = 0);
    QString& widget_name();

    void ChangeTriggerListPage(int id);
    void ChangeDAListPage(int id);

    void UpdateTriggerList();
    void UpdateDataAcquisitionList();
signals:
    
public slots:
    
private:

private:
    QString widget_name_;
    MTabWidget* maintab_;
    DeviceTriggerList* device_trigger_list_;
    DeviceDataAcquisitionList* device_dataacquisition_list_;
    int width_;
};

#endif // DEVICEMANAGEPAGE_H
