#include "test1.h"
#include "data/mrtsdatabase.h"
#include "data/mdaandtriggerconnector.h"

Test1::Test1()
{
}

Test1 *Test1::getInstance()
{
    static Test1 test1;
    return &test1;
}

void Test1::TestInit()
{
    addDataAcquisition();
    addTrigger();

    MRtsDataBase* db = MRtsDataBase::GetInstance();
    MDAAndTriggerConnector* connector = MDAAndTriggerConnector::getInstance();
    QList<int> daList;
    daList = db->DataAcquisitionList();

    QList<int> trList;
    trList = db->TriggerList();

    MDataAcquisition* d;
    db->DataAcquisition(daList[0],d);

    MTrigger* t;
    db->Trigger(trList[3],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[4],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[5],t);
    connector->Connect(*d,*t);

    db->DataAcquisition(daList[2],d);
    db->Trigger(trList[1],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[6],t);
    connector->Connect(*d,*t);

    db->DataAcquisition(daList[6],d);
    db->Trigger(trList[7],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[8],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[9],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[10],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[11],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[12],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[13],t);
    db->Trigger(trList[19],t);
    connector->Connect(*d,*t);

    db->DataAcquisition(daList[8],d);
    connector->Connect(*d,*t);
    db->Trigger(trList[14],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[15],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[16],t);
    connector->Connect(*d,*t);

    db->DataAcquisition(daList[7],d);
    db->Trigger(trList[17],t);
    connector->Connect(*d,*t);
    db->Trigger(trList[18],t);
    connector->Connect(*d,*t);

}

void Test1::addDataAcquisition()
{
    MRtsDataBase* db = MRtsDataBase::GetInstance();

    MDataAcquisition d;
    d.SetId(0);
    d.SetIp(QString("192.168.1.100"));
    d.SetName(QString("AD0"));
    d.SetSampleRate(6000);
    d.SetStatus(0);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);

    d.SetId(1);
    d.SetIp(QString("192.168.1.101"));
    d.SetName(QString("AD1"));
    d.SetSampleRate(6000);
    d.SetStatus(1);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);

    d.SetId(3);
    d.SetIp(QString("192.168.1.103"));
    d.SetName("AD3");
    d.SetSampleRate(6000);
    d.SetStatus(0);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);

    d.SetId(4);
    d.SetIp(QString("192.168.1.104"));
    d.SetName("AD4");
    d.SetSampleRate(6000);
    d.SetStatus(0);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);

    d.SetId(5);
    d.SetIp(QString("192.168.1.105"));
    d.SetName("AD5_5555");
    d.SetSampleRate(7000);
    d.SetStatus(0);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);

    d.SetId(6);
    d.SetIp(QString("192.168.1.106"));
    d.SetName("AD6###################");
    d.SetSampleRate(7000);
    d.SetStatus(2);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);

    d.SetId(7);
    d.SetIp(QString("192.168.1.107"));
    d.SetName("AD7");
    d.SetSampleRate(7000);
    d.SetStatus(1);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);

    d.SetId(8);
    d.SetIp(QString("192.168.1.108"));
    d.SetName("AD8");
    d.SetSampleRate(7000);
    d.SetStatus(1);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);

    d.SetId(9);
    d.SetIp(QString("192.168.1.109"));
    d.SetName("AD9");
    d.SetSampleRate(3000);
    d.SetStatus(0);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);

    d.SetId(10);
    d.SetIp(QString("192.168.1.110"));
    d.SetName("AD10");
    d.SetSampleRate(3000);
    d.SetStatus(2);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);

    d.SetId(11);
    d.SetIp(QString("192.168.1.111"));
    d.SetName("AD11");
    d.SetSampleRate(3000);
    d.SetStatus(2);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);

    d.SetId(2);
    d.SetIp(QString("192.168.1.102"));
    d.SetModel("sd_68s");
    d.SetName("AD2");
    d.SetSampleRate(6000);
    d.SetChannelCount(6);
    d.SetEveryTransferPoint(10);
    d.SetSampleLength(20);
    d.SetStartChannelId(102);
    d.SetTriggerDelayPoint(200);
    d.SetStatus(2);
    d.SetTriggerMode(1);
    d.SetType(0);
    db->AddDataAcquisition(d);
}

void Test1::addTrigger()
{
    MRtsDataBase* db = MRtsDataBase::GetInstance();
    Point pt;
    pt.wgs_point.latitude = 5000;
    pt.wgs_point.longitude = 4000;
    pt.wgs_point.elevation = 500;
    MTrigger t;
    t.SetTriggerId(100);
    t.SetTriggerName(QString("Trigger100"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerChannel(0x07);
    t.SetTriggerType(0);
    t.SetTriggerSensitivity(7000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(101);
    t.SetTriggerName(QString("Trigger101"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerType(0);
    t.SetTriggerSensitivity(3000);
    t.SetTriggerChannel(0x07);
    t.SetTriggerPoint(pt);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(1);
    db->AddTrigger(t);

    t.SetTriggerId(102);
    t.SetTriggerName(QString("Trigger102"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerType(1);
    t.SetTriggerPoint(pt);
    t.SetTriggerChannel(0x01);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(2);
    db->AddTrigger(t);

    t.SetTriggerId(103);
    t.SetTriggerName(QString("Trigger103"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerChannel(0x07);
    t.SetTriggerType(0);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(104);
    t.SetTriggerName(QString("Trigger104"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(2);
    t.SetTriggerChannel(0x07);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(1);
    db->AddTrigger(t);

    t.SetTriggerId(105);
    t.SetTriggerName(QString("Trigger105"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x07);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(2);
    db->AddTrigger(t);

    t.SetTriggerId(106);
    t.SetTriggerName(QString("Trigger106"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerType(0);
    t.SetTriggerPoint(pt);
    t.SetTriggerChannel(0x07);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(107);
    t.SetTriggerName(QString("Trigger107"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(1);
    db->AddTrigger(t);

    t.SetTriggerId(108);
    t.SetTriggerName(QString("Trigger108###"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(1);
    db->AddTrigger(t);

    t.SetTriggerId(109);
    t.SetTriggerName(QString("Trigger109"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(2);
    db->AddTrigger(t);

    t.SetTriggerId(110);
    t.SetTriggerName(QString("Trigger110"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(111);
    t.SetTriggerName(QString("Trigger111"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(112);
    t.SetTriggerName(QString("Trigger112"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(1);
    db->AddTrigger(t);

    t.SetTriggerId(113);
    t.SetTriggerName(QString("Trigger113"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(114);
    t.SetTriggerName(QString("Trigger114"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(115);
    t.SetTriggerName(QString("Trigger115"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(116);
    t.SetTriggerName(QString("Trigger116"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(117);
    t.SetTriggerName(QString("Trigger117"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(118);
    t.SetTriggerName(QString("Trigger118"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(119);
    t.SetTriggerName(QString("Trigger119"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

    t.SetTriggerId(120);
    t.SetTriggerName(QString("Trigger120"));
    t.SetTriggerModel(QString("Model100"));
    t.SetTriggerPoint(pt);
    t.SetTriggerType(0);
    t.SetTriggerChannel(0x08);
    t.SetTriggerSensitivity(4000);
    t.SetAzimuth(40);
    t.SetDip(50);
//    t.SetDataAcquisition(0);
    t.SetStatus(0);
    db->AddTrigger(t);

}
