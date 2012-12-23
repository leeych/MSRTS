#include "mrtsdatabase.h"

MRtsDataBase::MRtsDataBase()
{
}

MRtsDataBase *MRtsDataBase::GetInstance()
{
    static MRtsDataBase mrtsdatabase;
    return &mrtsdatabase;
}

bool MRtsDataBase::AddTrigger(MTrigger &t)
{
    int triggerid = t.trigger_id();
    if(triggerid == UN_INITID_INT)
    {
        return false;
    }

    if(trigger_map_.contains(triggerid))
    {
        trigger_map_[triggerid] = t;
    }
    else
    {
        trigger_map_.insert(triggerid,t);
    }

//    emit AddTriggerFinish();
    return true;
}

bool MRtsDataBase::AddDataAcquisition(MDataAcquisition &d)
{
    int id = d.id();
    if(id == UN_INITID_INT)
    {
        return false;
    }

    if(data_acquisition_map_.contains(id))
    {
        data_acquisition_map_[id] = d;
    }
    else
    {
        data_acquisition_map_.insert(id,d);
    }

//    emit AddDataAcquisitionFinish();
    return true;
}

bool MRtsDataBase::SetTrigger(MTrigger &t)
{
    int triggerid = t.trigger_id();
    if(triggerid == UN_INITID_INT)
    {
        return false;
    }

    if(trigger_map_.contains(triggerid))
    {
        trigger_map_[triggerid] = t;
    }
    else
    {
        trigger_map_.insert(triggerid,t);
    }
    return true;
}

bool MRtsDataBase::Trigger(int id, MTrigger* &t)
{
    if(id == UN_INITID_INT)
    {
        return false;
    }

    if(!trigger_map_.contains(id))
    {
        return false;
    }

    t = &trigger_map_[id];
    return true;
}

bool MRtsDataBase::DeleteTrigger(int id)
{
    if(id == UN_INITID_INT)
    {
        return false;
    }

    if(!trigger_map_.contains(id))
    {
        return true;
    }

    trigger_map_.remove(id);
    return true;
}

bool MRtsDataBase::SetDataAcquisition(MDataAcquisition &d)
{
    int id = d.id();
    if(id == UN_INITID_INT)
    {
        return false;
    }

    if(data_acquisition_map_.contains(id))
    {
        data_acquisition_map_[id] = d;
    }
    else
    {
        data_acquisition_map_.insert(id,d);
    }
    return true;
}

bool MRtsDataBase::DataAcquisition(int id, MDataAcquisition *&d)
{
    if(id == UN_INITID_INT)
    {
        return false;
    }

    if(!data_acquisition_map_.contains(id))
    {
        return false;
    }

    d = &data_acquisition_map_[id];
    return true;
}

bool MRtsDataBase::DeleteDataAcquisition(int id)
{
    if(id == UN_INITID_INT)
    {
        return false;
    }

    if(!data_acquisition_map_.contains(id))
    {
        return true;
    }

    data_acquisition_map_.remove(id);
    return true;
}

QList<int> MRtsDataBase::TriggerList()
{
    QList<int> res;
    res.reserve(trigger_map_.size());
    TriggerMap::const_iterator i = trigger_map_.begin();
    while (i != trigger_map_.end()) {
        res.append(i.key());
        ++i;
    }
    return res;
}

QList<int> MRtsDataBase::DataAcquisitionList()
{
    QList<int> res;
    res.reserve(data_acquisition_map_.size());
    DataAcquisitionMap::const_iterator i = data_acquisition_map_.begin();
    while (i != data_acquisition_map_.end()) {
        res.append(i.key());
        ++i;
    }
    return res;
}
