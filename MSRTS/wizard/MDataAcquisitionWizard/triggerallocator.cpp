#include "triggerallocator.h"
#include "data/mrtsdatabase.h"
#include <iostream>

TriggerAllocator::TriggerAllocator()
{
    triggerIdList = MRtsDataBase::GetInstance()->TriggerList();
}

TriggerAllocator *TriggerAllocator::getInstance()
{
    static TriggerAllocator allocator;
    return &allocator;
}

bool TriggerAllocator::IsAllocate()
{
    return true;
}

int TriggerAllocator::AllocateTriggerToDA()
{
    return 0;
}

byte TriggerAllocator::IsComponentLeft()
{
    return 0;
}
