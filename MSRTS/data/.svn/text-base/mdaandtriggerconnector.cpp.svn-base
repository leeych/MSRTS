#include "mdaandtriggerconnector.h"

MDAAndTriggerConnector::MDAAndTriggerConnector()
{
}

MDAAndTriggerConnector *MDAAndTriggerConnector::getInstance()
{
    static MDAAndTriggerConnector instance;
    return &instance;
}

void MDAAndTriggerConnector::Connect(MDataAcquisition &da, MTrigger &t)
{
    da.AddTriggerId(t.trigger_id());
    t.SetDataAcquisition(da.id());
}

void MDAAndTriggerConnector::DisConnenct(MDataAcquisition &da, MTrigger &t)
{
    da.RemoveTriggerId(t.trigger_id());
    t.SetDataAcquisition(UN_INITID_INT);
}
