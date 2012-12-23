#ifndef RTWAVEWINDOW_H
#define RTWAVEWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include "rtwavewindowtitle.h"
#include "wavetriggerwidget.h"

class RTWaveWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RTWaveWindow(QWidget *parent = 0);
    
    QString widget_name();

protected:
    void timerEvent(QTimerEvent * event);

signals:
    
public slots:
    void ShowWave(int daId); //data acquistion id
private:
    QVBoxLayout *infodisplaylayout_;
    QString widget_name_;
    RTWaveWindowTitle* runtime_wavewindow_title_;
    QScrollArea* scrollarea_;
    QList<WaveTriggerWidget*> wavetriggerwidgetlist_;
};

#endif // RTWAVEWINDOW_H
