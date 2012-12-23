#include <QtGui>
#include "wavetriggerwidget.h"
#include "mutility.h"
#include "MacroImage.h"

WaveTriggerWidget::WaveTriggerWidget(QWidget *parent) :
    QWidget(parent)
{
    resize(1316,166);
    imagechange_ = 0;
}

void WaveTriggerWidget::reflesh()
{
    imagechange_++;
    if(imagechange_ > 3)
    {
        imagechange_ = 0;
    }
    update();
}

void WaveTriggerWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    DrawTrigger(painter);
    DrawRuntimeWave(painter);
}

void WaveTriggerWidget::DrawTrigger(QPainter &painter)
{
    QString strImageDir;
    getImageDir(strImageDir);

    QPixmap triggerbutton;
    if(imagechange_ == 0)
    {
        triggerbutton.load(strImageDir + WAVETRIGGER_IMAGE_1);
    }
    else if(imagechange_ == 1)
    {
        triggerbutton.load(strImageDir + WAVETRIGGER_IMAGE_2);
    }
    else if(imagechange_ == 2)
    {
        triggerbutton.load(strImageDir + WAVETRIGGER_IMAGE_3);
    }
    else
    {
        triggerbutton.load(strImageDir + WAVETRIGGER_IMAGE_4);
    }

    painter.drawPixmap(0,0,triggerbutton);
}

void WaveTriggerWidget::DrawRuntimeWave(QPainter &painter)
{
    QString strImageDir;
    getImageDir(strImageDir);
    QPixmap wavepixmap(strImageDir + "wavetest.PNG");

    painter.drawPixmap(167,0,wavepixmap);
}
