#ifndef TRIGGERALLOCATOR_H
#define TRIGGERALLOCATOR_H

#include "data/mtrigger.h"
#include <QList>

class TriggerAllocator
{
public:
    static TriggerAllocator *getInstance();
    TriggerAllocator();

    bool IsAllocate();
    byte IsComponentLeft();
    int AllocateTriggerToDA();

protected:

private:
    MTrigger *trigger;
    QList<int> triggerIdList;
};

#endif // TRIGGERALLOCATOR_H
