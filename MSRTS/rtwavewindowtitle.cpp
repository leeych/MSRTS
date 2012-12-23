#include <QtGui>
#include "rtwavewindowtitle.h"
#include "MacroImage.h"

RTWaveWindowTitle::RTWaveWindowTitle(QString &backgroundname, QWidget *parent) :
    MTitleWidget(backgroundname,parent)
{
    bDraw = false;

}

void RTWaveWindowTitle::setDataAcquisitionName(QString &name)
{
    trigger_name_ = name;
}

void RTWaveWindowTitle::setDataAcquisitionSampleRate(int rate)
{
    sample_rate_ = rate;
}

void RTWaveWindowTitle::showTitle(bool bShow)
{
    bDraw = bShow;
    update();
}

void RTWaveWindowTitle::refresh()
{
    strtime_ = QDateTime::currentDateTime().toString("hh:mm:ss");
    strtime_ = STRING_TIME + strtime_;
    update();
}

void RTWaveWindowTitle::paintEvent(QPaintEvent * e)
{
    MTitleWidget::paintEvent(e);

    if(bDraw)
    {
        QPainter painter(this);
        DrawInfo(painter);
    }
}

void RTWaveWindowTitle::DrawInfo(QPainter &painter)
{
    if(!trigger_name_.isEmpty())
    {
        painter.drawText(10,20,trigger_name_);
    }

    if(sample_rate_ > 0)
    {
        QString strRate;
        strRate.sprintf("%d",sample_rate_);
        strRate = STRING_SAMPLE_RATE + strRate;
        painter.drawText(80,20,strRate);
    }

    painter.drawText(width() - 150,20,strtime_);
}
