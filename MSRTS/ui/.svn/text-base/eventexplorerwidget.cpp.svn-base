#include "eventexplorerwidget.h"

EventExplorerWidget::EventExplorerWidget(const QString &title,QWidget *parent, Qt::WindowFlags flags) :
    QDockWidget(title,parent,flags)
{
    setAllowedAreas(Qt::LeftDockWidgetArea);

    eventTreeWidget = new EventTreeWidget(this);
    setWidget(eventTreeWidget);
}
