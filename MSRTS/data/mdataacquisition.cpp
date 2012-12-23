#include "mdataacquisition.h"

MDataAcquisition::MDataAcquisition()
{
    id_ = UN_INITID_INT;
    name_ = "";
    type_ = UN_INITID_INT;
    sample_rate_ = UN_INITID_INT;
    trigger_mode_ = UN_INITID_INT;
    ip_ = "";
    status_ = UN_INITID_INT;    //0 normal 1 abnormal 2 not work(close)
    channel_count_ = UN_INITID_INT;
   trigger_delay_point_ = UN_INITID_INT;
   every_transfer_point_ = UN_INITID_INT;
   sample_length_ = UN_INITID_INT;
   start_channel_id_ = UN_INITID_INT;
}

int MDataAcquisition::id()
{
    return id_;
}

void MDataAcquisition::SetId(int id)
{
    id_ = id;
}

QString &MDataAcquisition::name()
{
    return name_;
}

void MDataAcquisition::SetName(const QString &name)
{
    name_ = name;
}

int MDataAcquisition::type()
{
    return type_;
}

void MDataAcquisition::SetType(int t)
{
    type_ = t;
}

int MDataAcquisition::channel_count()
{
    return channel_count_;
}

void MDataAcquisition::SetChannelCount(int count)
{
    channel_count_ = count;
}

int MDataAcquisition::sample_rate()
{
    return sample_rate_;
}

void MDataAcquisition::SetSampleRate(int rate)
{
    sample_rate_ = rate;
}

QString &MDataAcquisition::model()
{
    return model_;
}

void MDataAcquisition::SetModel(const QString &m)
{
    model_ = m;
}

int MDataAcquisition::trigger_mode()
{
    return trigger_mode_;
}

void MDataAcquisition::SetTriggerMode(int mode)
{
    trigger_mode_ = mode;
}

int MDataAcquisition::trigger_delay_point()
{
    return trigger_delay_point_;
}

void MDataAcquisition::SetTriggerDelayPoint(int point)
{
    trigger_delay_point_ = point;
}

int MDataAcquisition::every_transfer_point()
{
    return every_transfer_point_;
}

void MDataAcquisition::SetEveryTransferPoint(int point)
{
    every_transfer_point_ = point;
}

int MDataAcquisition::sample_length()
{
    return sample_length_;
}

void MDataAcquisition::SetSampleLength(int len)
{
    sample_length_ = len;
}

int MDataAcquisition::start_channel_id()
{
    return start_channel_id_;
}

void MDataAcquisition::SetStartChannelId(int id)
{
    start_channel_id_ = id;
}

QString &MDataAcquisition::ip()
{
    return ip_;
}

void MDataAcquisition::SetIp(const QString &ip)
{
    ip_ = ip;
}

QList<int> MDataAcquisition::triggerid_list()
{
    return triggerid_list_;
}

void MDataAcquisition::AddTriggerId(int tid)
{
    if(!triggerid_list_.contains(tid))
    {
        triggerid_list_.push_back(tid);
    }
}

void MDataAcquisition::RemoveTriggerId(int tid)
{
    QList<int>::iterator itr = qFind(triggerid_list_.begin(),triggerid_list_.end(),tid);
    if(itr != triggerid_list().end())
    {
        triggerid_list_.erase(itr);
    }
}

int MDataAcquisition::status()
{
    return status_;
}

void MDataAcquisition::SetStatus(int s)
{
    status_ = s;
}
