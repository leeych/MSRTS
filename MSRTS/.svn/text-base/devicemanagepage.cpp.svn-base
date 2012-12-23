#include <QtGui>
#include "devicemanagepage.h"
#include "MacroImage.h"

DeviceManagePage::DeviceManagePage(QWidget *parent) :
    QMainWindow(parent)
{
    setStyleSheet("background-color: rgb(233,246,254);font:12px;");
    widget_name_ = STRING_DEVICE_MANAGER;

    device_trigger_list_ = new DeviceTriggerList(this);
    device_dataacquisition_list_ = new DeviceDataAcquisitionList(this);
    maintab_ = new MTabWidget(this);
    maintab_->addTab(device_trigger_list_,device_trigger_list_->widget_name());
    device_trigger_list_->CreateTable(width_);
    device_trigger_list_->UpdateTriggerList();
    maintab_->addTab(device_dataacquisition_list_,device_dataacquisition_list_->widget_name());
    device_dataacquisition_list_->CreateTable(width_);
    device_dataacquisition_list_->UpdateDataAcquisitionList();
    setCentralWidget(maintab_);
}

QString &DeviceManagePage::widget_name()
{
    return  widget_name_;
}

void DeviceManagePage::ChangeTriggerListPage(int id)
{
    if(device_trigger_list_ != NULL)
    {
        maintab_->addTab(device_trigger_list_,device_trigger_list_->widget_name());
        maintab_->changeTab(device_trigger_list_->widget_name());
        device_trigger_list_->UpdateTriggerList();
        device_trigger_list_->SetTriggerHighlight(id);
    }
}

void DeviceManagePage::ChangeDAListPage(int id)
{
    if(device_trigger_list_ != NULL)
    {
        maintab_->addTab(device_dataacquisition_list_,device_dataacquisition_list_->widget_name());
        maintab_->changeTab(device_dataacquisition_list_->widget_name());
        device_dataacquisition_list_->UpdateDataAcquisitionList();
        device_dataacquisition_list_->SetDAHighlight(id);
    }
}

void DeviceManagePage::UpdateTriggerList()
{
    device_trigger_list_->UpdateTriggerList();
}

void DeviceManagePage::UpdateDataAcquisitionList()
{
    device_dataacquisition_list_->UpdateDataAcquisitionList();
}
