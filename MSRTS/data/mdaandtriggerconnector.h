#ifndef MDAANDTRIGGERCONNECTOR_H
#define MDAANDTRIGGERCONNECTOR_H

#include "mdataacquisition.h"
#include "mtrigger.h"

class MDAAndTriggerConnector
{
public:
    MDAAndTriggerConnector();
    static MDAAndTriggerConnector* getInstance();

    void Connect(MDataAcquisition& da, MTrigger& t);
    void DisConnenct(MDataAcquisition& da, MTrigger& t);
};

#endif // MDAANDTRIGGERCONNECTOR_H
