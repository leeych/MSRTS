#ifndef PROPERTYWIDGET_H
#define PROPERTYWIDGET_H
#include <QFrame>
#include <QVBoxLayout>
#include "statusinfowidget.h"

class PropertyFrame : public QFrame
{
    Q_OBJECT
public:
    PropertyFrame();

signals:

public slots:

private:

private:
    QVBoxLayout *infodisplaylayout_;
    StatusInfoWidget* statusInfoWidget_;
};

#endif // PROPERTYWIDGET_H
