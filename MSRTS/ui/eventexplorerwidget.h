#ifndef EVENTEXPLORERWIDEGET_H
#define EVENTEXPLORERWIDEGET_H

#include <QDockWidget>
#include "eventtreewidget.h"

class EventExplorerWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit EventExplorerWidget(const QString &title,QWidget *parent = 0, Qt::WindowFlags flags = 0);
    
signals:
    
public slots:

private:
    EventTreeWidget* eventTreeWidget;
    
};

#endif // EVENTEXPLORERWIDEGET_H
