#include <QtGui>
#include "eventexplorer.h"
#include "innerdata/msavedata.h"

EventExplorer::EventExplorer(QWidget *parent) :
    QWidget(parent)
{
    showinfotitle_ = new MShowInfoTitle;
    showinfotitle_->title_name()->setText(tr("Event Manager"));

    eventTreeWidget = new EventTreeWidget;
    dateEdit = new MDateEdit;
    QVBoxLayout* vlayout = new QVBoxLayout;
    vlayout->addWidget(showinfotitle_);
    vlayout->addWidget(dateEdit);
    vlayout->addWidget(eventTreeWidget);
    vlayout->setMargin(0);
    vlayout->setSpacing(0);
    setLayout(vlayout);

    MSaveData* saveData = MSaveData::getInstance();
    connect(eventTreeWidget, SIGNAL(eventDisplaySignal(EventInfo&)),saveData,SLOT(onEventExplorerDisplaySignal(EventInfo&)));
    connect(eventTreeWidget, SIGNAL(eventDisplaySignal(EventInfo&)),this,SLOT(onEventDisplaySignal(EventInfo &)));
    connect(eventTreeWidget, SIGNAL(eventPropertySignal(EventInfo)), this, SLOT(onEventpropertySignal(EventInfo)));
    connect(eventTreeWidget, SIGNAL(sitePropertySignal(int, int)), this, SLOT(onTriggerPropertySignal(int, int)));
    connect(dateEdit->dateedit_, SIGNAL(dateChanged(QDate)), eventTreeWidget, SLOT(SelectTreeDate(QDate)));
}

void EventExplorer::UpdateEventTree()
{
    eventTreeWidget->UpdataEventTree();
}

void EventExplorer::onAcceptSlot()
{
    eventTreeWidget->onAcceptSlot();
}

void EventExplorer::onThrowawaySlot()
{
    eventTreeWidget->onThrowawaySlot();
}

void EventExplorer::onBlastSlot()
{
    eventTreeWidget->onBlastSlot();
}

void EventExplorer::onBriefSlot()
{
    eventTreeWidget->onBriefSlot();
}

void EventExplorer::onDetailSlot()
{
    eventTreeWidget->onDetailSlot();
}

void EventExplorer::onPropertySlot()
{
    eventTreeWidget->onPropertySlot();
}

void EventExplorer::onRecvAndSaveSlot()
{
    eventTreeWidget->onRecvAndSaveSlot();
}

void EventExplorer::onEventDisplaySignal(EventInfo &info)
{
    emit eventExplorerDisplaySignal(info);
}

void EventExplorer::onEventpropertySignal(EventInfo info)
{
    emit eventPropertySignal(info);
}

void EventExplorer::onTriggerPropertySignal(int eventId, int stationId)
{
    emit sitePropertySignal(eventId, stationId);

}
