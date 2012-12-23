#ifndef MSCROLLAREA_H
#define MSCROLLAREA_H

#include <QScrollArea>


class MScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    MScrollArea(QWidget* parent=0);

signals:
    void resizeSignal(int w, int h);

public slots:
    void pointVisible(int x,int y);

protected:
    void resizeEvent(QResizeEvent *ev);

private:

};

#endif // MSCROLLAREA_H
