#ifndef MDATAACQUISITIONDEVICE_H
#define MDATAACQUISITIONDEVICE_H

#include <QString>
#include <QList>
#include "mutility.h"

class MDataAcquisition
{
public:
    MDataAcquisition();

    int id();
    void SetId(int id);

    QString& name();
    void SetName(const QString& name);

    int type();
    void SetType(int t);

    int channel_count();
    void SetChannelCount(int count);

    int sample_rate();
    void SetSampleRate(int rate);

    QString& model();
    void SetModel(const QString& m);

    int  trigger_mode();
    void SetTriggerMode(int mode);

    int trigger_delay_point();
    void SetTriggerDelayPoint(int point);

    int every_transfer_point();
    void SetEveryTransferPoint(int point);

    int sample_length();
    void SetSampleLength(int len);

    int start_channel_id();
    void SetStartChannelId(int id);

    QString& ip();
    void SetIp(const QString& ip);

    QList<int> triggerid_list();
    void AddTriggerId(int tid);
    void RemoveTriggerId(int tid);

    int status();
    void SetStatus(int s);

private:
    int id_;
    QString name_;
    int type_;
    int channel_count_;
    int sample_rate_;
    QString model_;
    int trigger_mode_;
    int trigger_delay_point_;
    int every_transfer_point_;
    int sample_length_;
    int start_channel_id_;
    BTime time_;
    QString ip_;
    QList<int> triggerid_list_;  //trigger id
    int status_;    //0 normal 1 abnormal 2 not work(close)
};

#endif // MDATAACQUISITIONDEVICE_H
