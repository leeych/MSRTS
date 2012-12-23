#ifndef EVENTEXPLORER_H
#define EVENTEXPLORER_H

#include <QWidget>
#include "eventtreewidget.h"
#include "mdateedit.h"
#include "mshowinfotitle.h"
class QCalendarWidget;
class QDateEdit;

class EventExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit EventExplorer(QWidget *parent = 0);
    
    void UpdateEventTree();

signals:
    void eventExplorerDisplaySignal(EventInfo& info);
    void eventPropertySignal(EventInfo);
    void sitePropertySignal(int, int);

public slots:
    void onEventDisplaySignal(EventInfo& info);
    void onEventpropertySignal(EventInfo info);
    void onTriggerPropertySignal(int, int);

    void onAcceptSlot();
    void onThrowawaySlot();
    void onBlastSlot();
    void onBriefSlot();
    void onDetailSlot();
    void onPropertySlot();
    void onRecvAndSaveSlot();

private:
    EventTreeWidget* eventTreeWidget;
    QCalendarWidget *calendar;
    //QDateEdit *dateedit;
    MDateEdit* dateEdit;
    MShowInfoTitle * showinfotitle_;
};

#endif // EVENTEXPLORER_H
