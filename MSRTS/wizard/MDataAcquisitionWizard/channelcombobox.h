#ifndef CHANNELCOMBOBOX_H
#define CHANNELCOMBOBOX_H

#include <QComboBox>
#include "data/mrtsdatabase.h"
#include "data/mtrigger.h"
#include <QList>

class ChannelComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit ChannelComboBox(QObject *parent = 0);
    void setDisabled(bool);
signals:
    
public slots:
    
private:
    QList<int> triggerIdList;
    MTrigger *trigger;
};

#endif // CHANNELCOMBOBOX_H
