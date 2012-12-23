#include "topologytriggeritem.h"
#include "MacroImage.h"
#include "mutility.h"

TopologyTriggerItem::TopologyTriggerItem()
{
    QString dir;
    getImageDir(dir);

    SetBitmap(dir + TOPOLOGY_TRIGGER_NORMAL_IMGAE,dir + TOPOLOGY_TRIGGER_ABNORMAL_IMGAE,dir + TOPOLOGY_TRIGGER_NOTWORK_IMGAE);
}

int TopologyTriggerItem::type()
{
    return 0;
}
