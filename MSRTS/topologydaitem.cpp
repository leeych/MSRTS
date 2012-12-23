#include "topologydaitem.h"
#include "MacroImage.h"
#include "mutility.h"

TopologyDAItem::TopologyDAItem()
{
    QString dir;
    getImageDir(dir);

    SetBitmap(dir + TOPOLOGY_DA_NORMAL_IMGAE,dir + TOPOLOGY_DA_ABNORMAL_IMGAE,dir + TOPOLOGY_DA_NOTWORK_IMGAE);
}

int TopologyDAItem::type()
{
    return 1;
}
