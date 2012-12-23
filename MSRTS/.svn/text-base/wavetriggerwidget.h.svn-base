#ifndef WAVETRIGGERWIDGET_H
#define WAVETRIGGERWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

class WaveTriggerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WaveTriggerWidget(QWidget *parent = 0);
    
    void reflesh();
protected:
    void paintEvent(QPaintEvent *);

signals:
    
public slots:
    
private:
    void DrawTrigger(QPainter &painter);
    void DrawRuntimeWave(QPainter &painter);
private:
    int imagechange_;
};

#endif // WAVETRIGGERWIDGET_H
