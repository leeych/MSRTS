#ifndef MTRIGGER_H
#define MTRIGGER_H

#include <QString>
#include <QMap>
#include "mutility.h"

#define TRIGGER_TYPE_VELOCITY             0
#define TRIGGER_TYPE_DISPLACEMENT    1
#define TRIGGER_TYPE_ACCELERATION     2

#define TRIGGER_CHANNEL_COMPONENT_X  0
#define TRIGGER_CHANNEL_COMPONENT_Y  1
#define TRIGGER_CHANNEL_COMPONENT_Z  2
#define TRIGGER_CHANNEL_COMPONENT_P  3

class MTrigger
{
public:
    MTrigger();

    int trigger_id();
    void SetTriggerId(int id);

    QString& trigger_name();
    void SetTriggerName(const QString& name);

    QString& trigger_model();
    void SetTriggerModel(const QString& model);

    /* bit 3   2   1   0
     *       P   X   Y   Z
     **/
    byte trigger_channel();
    void SetTriggerChannel(byte c);

    int trigger_type();
    void SetTriggerType(int type);

    Point trigger_point();
    void SetTriggerPoint(const Point& pt);

    int trigger_sensitivity();
    void SetTriggerSensitivity(int s);

    float azimuth();
    void SetAzimuth(int a);

    float dip();
    void SetDip(int d);

    bool isusing();
    void SetIsUing(bool isuse);

    int data_acquisition_id();
    void SetDataAcquisition(int d);

    int status();
    void SetStatus(int s);
private:
    int trigger_id_;
    QString trigger_name_;
    QString trigger_model_;

    /* bit 3   2   1   0
     *       P   X   Y   Z

    byte trigger_channel_;
    **/
    byte trigger_channel_;
    int trigger_type_;  // 0 velocity 1 displacement 2 acceleration
    int trigger_sensitivity_;
    Point   trigger_point_;
    float azimuth_;
    float dip_;
    bool isusing_;
    int data_acquisition_id_; //UN_INITID_INT means invalid
    int status_;    //0 normal 1 abnormal 2 not work(close)
};

#endif // MTRIGGER_H
