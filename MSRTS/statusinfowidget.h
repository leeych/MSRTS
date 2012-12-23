#ifndef STATUSINFOWIDGET_H
#define STATUSINFOWIDGET_H

#include <QWidget>
#include "data/mrtsdatabase.h"

#define STATUSINFO_WIDTH    204
#define STATUSINFO_HEIGHT   400

class StatusInfoWidget : public QWidget
{
    Q_OBJECT
public:
    StatusInfoWidget();

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:

private:
    void TriggerInfoDisplay(int triggerId);
    void DrawInfo(QPainter& painter);

private:
    MTrigger trigger_;
};

#endif // STATUSINFOWIDGET_H
