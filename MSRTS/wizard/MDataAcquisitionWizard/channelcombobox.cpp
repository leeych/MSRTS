#include "channelcombobox.h"
#include <cstdlib>
#include <ctime>

ChannelComboBox::ChannelComboBox(QObject *parent) :
    QComboBox((QWidget *)parent)
{
    MRtsDataBase *db = MRtsDataBase::GetInstance();
    triggerIdList = db->TriggerList();
    QList<int>::Iterator iter = triggerIdList.begin();
    while (iter != triggerIdList.end())
    {
        if (db->Trigger(*iter, trigger))
        {
            this->addItem(trigger->trigger_name());
        }
        ++iter;
    }
}

void ChannelComboBox::setDisabled(bool flag)
{
    if (flag)
    {
        this->setCurrentIndex(4);
    }
    this->setEnabled(!flag);
}
