#include <QtGui>
#include "mtitlewidget.h"

#define TITLE_BORDER_SIZE    1
#define TITLE_WHITE_SIZE     1

MTitleWidget::MTitleWidget(QString &backgroundname, QWidget *parent) :
    QWidget(parent)
{
    pixmap_background_.load(backgroundname);
    setMaximumHeight(pixmap_background_.height()+4);
    setMinimumHeight(pixmap_background_.height()+4);
    draw_bottom_line_ = true;
    is_draw_title_ = false;
}

void MTitleWidget::SetTitleName(QString &titlename)
{
    if(titlename.isEmpty())
    {
        is_draw_title_ = false;
    }
    else
    {
        pixmap_title_.load(titlename);
        is_draw_title_ = true;
    }
}

void MTitleWidget::setDrawBottomLine(bool bdraw)
{
    draw_bottom_line_ = bdraw;
}

void MTitleWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    DrawBackground(painter);

    if(is_draw_title_)
    {
        painter.drawPixmap(TITLE_BORDER_SIZE + TITLE_WHITE_SIZE,TITLE_BORDER_SIZE + TITLE_WHITE_SIZE,pixmap_title_);
    }
}

void MTitleWidget::DrawBackground(QPainter& painter)
{
    int widget_width = size().width();
    int widget_height = size().height();

    for(int i = TITLE_BORDER_SIZE + TITLE_WHITE_SIZE;i < widget_width - TITLE_BORDER_SIZE - TITLE_WHITE_SIZE;i++)
    {
        painter.drawPixmap(i,TITLE_BORDER_SIZE + TITLE_WHITE_SIZE,pixmap_background_);
    }

    painter.setPen(QColor(112,161,220));
    painter.drawLine(0,0,widget_width-1,0);
    painter.drawLine(0,0,0,widget_height-1);
    painter.drawLine(widget_width-1,0,widget_width-1,widget_height-1);
    if(draw_bottom_line_)
    {
        painter.drawLine(0,widget_height-1,widget_width-1,widget_height-1);
    }
    painter.setPen(QColor(255,255,255));
    painter.drawLine(TITLE_WHITE_SIZE,TITLE_WHITE_SIZE,widget_width-TITLE_BORDER_SIZE-1,TITLE_WHITE_SIZE);
    painter.drawLine(TITLE_WHITE_SIZE,TITLE_WHITE_SIZE,TITLE_WHITE_SIZE,widget_height-TITLE_BORDER_SIZE-1);
    painter.drawLine(widget_width-TITLE_BORDER_SIZE-1,TITLE_WHITE_SIZE,widget_width-TITLE_BORDER_SIZE-1,widget_height-TITLE_BORDER_SIZE-1);
    painter.drawLine(TITLE_WHITE_SIZE,widget_height-TITLE_BORDER_SIZE-1,widget_width-TITLE_BORDER_SIZE-1,widget_height-TITLE_BORDER_SIZE-1);
}
