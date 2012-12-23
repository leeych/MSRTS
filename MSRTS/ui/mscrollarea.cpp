#include <QtGui>
#include "mscrollarea.h"

MScrollArea::MScrollArea(QWidget *parent)
    :QScrollArea(parent)
{

}

void MScrollArea::resizeEvent(QResizeEvent * ev)
{
    emit resizeSignal(ev->size().width(),ev->size().height());
    QScrollArea::resizeEvent(ev);
}


void MScrollArea::pointVisible(int x, int y)
{
    //ensureVisible(x,y,100,100);
}
