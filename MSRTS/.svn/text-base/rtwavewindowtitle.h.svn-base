#ifndef RTWAVEWINDOWTITLE_H
#define RTWAVEWINDOWTITLE_H

#include <QWidget>
#include "mutility.h"
#include "ui/mtitlewidget.h"

class RTWaveWindowTitle : public MTitleWidget
{
    Q_OBJECT
public:
    explicit RTWaveWindowTitle(QString& backgroundname,QWidget *parent = 0);
    
    void setDataAcquisitionName(QString& name);
    void setDataAcquisitionSampleRate(int rate);
    void showTitle(bool bShow);

    void refresh();
protected:
    void paintEvent(QPaintEvent * e);

signals:
    
public slots:
    
private:
    void DrawInfo(QPainter& painter);
private:
    QString trigger_name_;
    int sample_rate_;
    QString strtime_;
    QPixmap pixmap_background_;
    bool bDraw;
};

#endif // RTWAVEWINDOWTITLE_H
