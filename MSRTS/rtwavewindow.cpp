#include "rtwavewindow.h"
#include "MacroImage.h"
#include <QTextEdit>
#include "data/mrtsdatabase.h"
RTWaveWindow::RTWaveWindow(QWidget *parent) :
    QWidget(parent)
{
    widget_name_ = STRING_RUNTIME_WAVELIST;

    infodisplaylayout_ = new QVBoxLayout;

    QString strDir;
    getImageDir(strDir);
    QString strTip;
    strTip = strDir + SYSTEM_STATUS_1PX_IMAGE;
    runtime_wavewindow_title_ = new RTWaveWindowTitle(strTip);

    scrollarea_ = new QScrollArea;
    scrollarea_->setWidgetResizable(true);

    infodisplaylayout_->addWidget(runtime_wavewindow_title_);
    infodisplaylayout_->addWidget(scrollarea_);
    infodisplaylayout_->setMargin(0);
    infodisplaylayout_->setSpacing(0);
    setLayout(infodisplaylayout_);
    timerEvent(0);
    startTimer(1000);
}

QString RTWaveWindow::widget_name()
{
    return widget_name_;
}

void RTWaveWindow::timerEvent(QTimerEvent *event)
{
    runtime_wavewindow_title_->refresh();
    for(QList<WaveTriggerWidget*>::iterator itr = wavetriggerwidgetlist_.begin();itr != wavetriggerwidgetlist_.end();itr++)
    {
        (*itr)->reflesh();
    }
}

void RTWaveWindow::ShowWave(int daId)
{
    MRtsDataBase* db = MRtsDataBase::GetInstance();

    MDataAcquisition* da;
    if(!db->DataAcquisition(daId,da))
    {
        return;
    }

    wavetriggerwidgetlist_.clear();

    runtime_wavewindow_title_->setDataAcquisitionName(da->name());
    runtime_wavewindow_title_->setDataAcquisitionSampleRate(da->sample_rate());
    runtime_wavewindow_title_->showTitle(true);

    QVBoxLayout* layout = new QVBoxLayout;
    WaveTriggerWidget* p1 = new WaveTriggerWidget;
    //QTextEdit* p1 = new QTextEdit;
    WaveTriggerWidget* p2 = new WaveTriggerWidget;
    WaveTriggerWidget* p3 = new WaveTriggerWidget;
    WaveTriggerWidget* p4 = new WaveTriggerWidget;
    WaveTriggerWidget* p5 = new WaveTriggerWidget;
    wavetriggerwidgetlist_.push_back(p1);
    wavetriggerwidgetlist_.push_back(p2);
    wavetriggerwidgetlist_.push_back(p3);
    wavetriggerwidgetlist_.push_back(p4);
    wavetriggerwidgetlist_.push_back(p5);
    p3->setMinimumHeight(166);
    p4->setMinimumHeight(166);
    p1->setMinimumHeight(166);
    p2->setMinimumHeight(166);
    p5->setMinimumHeight(166);
    layout->addWidget(p1);
    layout->addWidget(p2);
    layout->addWidget(p3);
    layout->addWidget(p4);
    layout->addWidget(p5);
    layout->setSpacing(5);
    layout->setMargin(0);
    //scrollarea_->setLayout(layout);
    QWidget* widget = new QWidget;
    widget->setMinimumHeight(166*5);
    widget->setLayout(layout);
    scrollarea_->setWidget(widget);
}
