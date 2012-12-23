#ifndef MRTSDATABASE_H
#define MRTSDATABASE_H

#include "mtrigger.h"
#include "mdataacquisition.h"
#include <QMap>
#include <QList>
#include <QObject>

typedef QMap<int,MDataAcquisition> DataAcquisitionMap;  //key is data acquisition device id
typedef QMap<int,MTrigger> TriggerMap;  //key is trigger id

class MRtsDataBase //: public QObject
{
//    Q_OBJECT
public:
    MRtsDataBase();
    static MRtsDataBase* GetInstance();

    bool AddTrigger(MTrigger& t);
    bool SetTrigger(MTrigger& t);
    bool Trigger(int id, MTrigger*& t);
    bool DeleteTrigger(int id);

    bool AddDataAcquisition(MDataAcquisition& d);
    bool SetDataAcquisition(MDataAcquisition& d);
    bool DataAcquisition(int id, MDataAcquisition*& d);
    bool DeleteDataAcquisition(int id);

    QList<int> TriggerList();
    QList<int> DataAcquisitionList();

//signals:
//    void AddTriggerFinish();
//    void AddDataAcquisitionFinish();
private:
    TriggerMap trigger_map_;
    DataAcquisitionMap data_acquisition_map_;
};

#endif // MRTSDATABASE_H
