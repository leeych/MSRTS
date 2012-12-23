#include "mtrigger.h"

MTrigger::MTrigger()
{
    trigger_id_ = UN_INITID_INT;
    trigger_type_ = UN_INITID_INT;
    trigger_name_ = "";
    trigger_model_ = "";
    trigger_sensitivity_ = UN_INITID_INT;
    //Point   position;
    azimuth_ = UN_INITID_FLOAT;
    dip_ = UN_INITID_FLOAT;
    data_acquisition_id_ = UN_INITID_INT;
}

int MTrigger::trigger_id()
{
    return trigger_id_;
}

void MTrigger::SetTriggerId(int id)
{
    trigger_id_ = id;
}

QString &MTrigger::trigger_name()
{
    return trigger_name_;
}

void MTrigger::SetTriggerName(const QString &name)
{
    trigger_name_ = name;
}

QString &MTrigger::trigger_model()
{
    return trigger_model_;
}

void MTrigger::SetTriggerModel(const QString &model)
{
    trigger_model_ = model;
}

byte MTrigger::trigger_channel()
{
    return trigger_channel_;
}

void MTrigger::SetTriggerChannel(byte c)
{
    trigger_channel_ = c;
}

int MTrigger::trigger_type()
{
    return trigger_type_;
}

void MTrigger::SetTriggerType(int type)
{
    trigger_type_ = type;
}

Point MTrigger::trigger_point()
{
    return trigger_point_;
}

void MTrigger::SetTriggerPoint(const Point &pt)
{
    trigger_point_ = pt;
}

int MTrigger::trigger_sensitivity()
{
    return trigger_sensitivity_;
}

void MTrigger::SetTriggerSensitivity(int s)
{
    trigger_sensitivity_ = s;
}

float MTrigger::azimuth()
{
    return azimuth_;
}

void MTrigger::SetAzimuth(int a)
{
    azimuth_ = a;
}

float MTrigger::dip()
{
    return dip_;
}

void MTrigger::SetDip(int d)
{
    dip_ = d;
}

bool MTrigger::isusing()
{
    return isusing_;
}

void MTrigger::SetIsUing(bool isuse)
{
    isusing_ = isuse;
}

int MTrigger::data_acquisition_id()
{
    return data_acquisition_id_;
}

void MTrigger::SetDataAcquisition(int d)
{
    data_acquisition_id_ = d;
}

int MTrigger::status()
{
    return status_;
}

void MTrigger::SetStatus(int s)
{
    status_ = s;
}
