#include <QtGui>
#include "msplitter.h"
#include "mutility.h"
#include <math.h>

MSplitter::MSplitter(Qt::Orientation o, MSplitterExpand e, QWidget* parent) :
    QSplitter(o,parent)
{

    //setCollapsible(1,true);
    setHandleWidth(7);
    //setChildrenCollapsible(true);
//    expandButton = new QPushButton(this);
//    addWidget(expandButton);
    orientation = o;
    expandDirection = e;
    //splitterHandle = new MSplitterHandle(o,this);

    connect(this,SIGNAL(splitterMoved(int,int)),this,SLOT(msplitterMoved(int,int)));
}

void MSplitter::msplitterMoved(int pos, int index)
{
    MSplitterHandle* h = (MSplitterHandle*)handle(index);
    h->splitterMoved(pos);
}

void MSplitter::paintEvent(QPaintEvent *)
{
//    QPainter paint(this);
//    paint.setPen(Qt::red);
//     //paint.drawPixmap(rect(),groundPixmap);
//    paint.drawText(0,0,"dddddddc");
//    paint.setRenderHint(QPainter::Antialiasing);
//    paint.fillRect(rect(), Qt::Dense6Pattern);

//    QPainter painter(this);
//    QRect rect = this->rect();

//    QDockWidget *dw = qobject_cast<QDockWidget*>(parentWidget());
//    Q_ASSERT(dw != 0);

//    if (dw->features() & QDockWidget::DockWidgetVerticalTitleBar) {
//        QSize s = rect.size();
//        s.transpose();
//        rect.setSize(s);

//        painter.translate(rect.left(), rect.top() + rect.width());
//        painter.rotate(-90);
//        painter.translate(-rect.left(), -rect.top());
//    }

//    painter.drawPixmap(rect.topLeft(), leftPm);
//    painter.drawPixmap(rect.topRight() - QPoint(rightPm.width() - 1, 0), rightPm);
//    QBrush brush(centerPm);
//    painter.fillRect(rect.left() + leftPm.width(), rect.top(),
//                        rect.width() - leftPm.width() - rightPm.width(),
    //                        centerPm.height(), centerPm);
}

QSplitterHandle *MSplitter::createHandle()
{
    return (QSplitterHandle*) new MSplitterHandle(orientation, expandDirection, this);
}


MSplitterHandle::MSplitterHandle(Qt::Orientation o, MSplitterExpand e, QSplitter *parent) :
    QSplitterHandle(o,parent)
{
    expandDirection = e;

    QString dir;
    getImageDir(dir);

    leftpPixmap = new QPixmap(dir + "yc_1.png");
    rightpPixmap = new QPixmap(dir + "yc_2.png");

    if(e == MSplitterLeft )
    {
        currentPixmap = leftpPixmap;
    }
    else
    {
        currentPixmap = rightpPixmap;
    }

    oldPos = 0;
    isPressed = false;
    isMoved = false;
    closestLegalPosition(30);
    isExpand = true;
}

void MSplitterHandle::paintEvent(QPaintEvent *)
{
    QPainter paint(this);

    QSize sz = size();

    int posX = sz.width()/2 - 1;
    int posY = sz.height()/2 - 25;
    if(isMoved)
    {
        --posX;
        --posY;
    }

    QPointF point(posX,posY);
    paint.drawPixmap(point,*currentPixmap);
}

void MSplitterHandle::mousePressEvent(QMouseEvent *m)
{
    QSize sz = size();

    if(m->y() >= (sz.height()/2 - 25) && m->y() <= (sz.height()/2 + 25))
    {
        isPressed = true;
    }

    pressPoint.setX(m->x());
    pressPoint.setY(m->y());
    QSplitterHandle::mousePressEvent(m);
}

void MSplitterHandle::mouseMoveEvent(QMouseEvent *m)
{
    QSize sz = size();
    isMoved = (m->y() >= (sz.height()/2 - 25) && m->y() <= (sz.height()/2 + 25));

    QSplitterHandle::mouseMoveEvent(m);
}

void MSplitterHandle::mouseReleaseEvent(QMouseEvent *m)
{
    QSize sz = size();

    if((abs(m->x() - pressPoint.x()) < 1 ) &&
            (abs(m->y() - pressPoint.y()) < 1))
    {
        if(m->y() >= (sz.height()/2 - 25) && m->y() <= (sz.height()/2 + 25) && isPressed)
        {
//            if(currentPixmap == leftpPixmap)
//            {
//                currentPixmap = rightpPixmap;
//                //oldPos = m->x();
//                moveSplitter(0);
//            }
//            else
//            {
//                currentPixmap = leftpPixmap;
//                //moveSplitter(oldPos);
//                //oldPos = 0;
//                moveSplitter(80);
//            }

          QWidget* p = (QWidget*)splitter()->parent();
         if(isExpand)
         {
             //oldPos = m->x();
             QList<int> wl = splitter()->sizes();
             int left = wl[0];
             int right = wl[1];

             if(expandDirection == MSplitterRight)
             {
                 moveSplitter(left + right);
             }
             else
             {
                 moveSplitter(0);
             }

         }
         else
         {
             //moveSplitter(oldPos);
             //oldPos = 0;
             //moveSplitter(300);
//             QList<int> wl = splitter()->sizes();
//             int left = wl[0];
//             int right = wl[1];

             if(expandDirection == MSplitterRight)
             {
                 moveSplitter(p->width()/5*3);
             }
             else
             {
                 moveSplitter(p->width()/6);
             }
         }

            update();
            return;
        }
    }

    isPressed = false;
    QSplitterHandle::mouseReleaseEvent(m);
}

bool MSplitterHandle::event(QEvent *event)
{
    QSize sz = size();
    QPoint pt;
    switch(event->type()) {
    case QEvent::HoverMove:
        pt= ((QHoverEvent*)event)->pos();
        isMoved = (pt.y() >= (sz.height()/2 - 25) && pt.y() <= (sz.height()/2 + 25));

        if(isMoved)
        {
//            Qcurosr *myCursor=new QCursor(QPixmap(":/images/custom.png"),-1,-1);
//            setCursor(*myCursor);
            oleCursor = cursor();
            setCursor(Qt::PointingHandCursor);
        }
        else
        {
            setCursor(Qt::SplitHCursor);
        }
        update();
        break;
    case QEvent::HoverLeave:
        isMoved = false;
        update();
        break;
    default:
        break;
    }
    return QSplitterHandle::event(event);
}

void MSplitterHandle::splitterMoved(int pos)
{
    if(expandDirection == MSplitterLeft)
    {
        if(pos == 0)
        {
            isExpand = false;
            currentPixmap = rightpPixmap;
    //        update();
        }
        else
        {
            currentPixmap = leftpPixmap;
            isExpand = true;
        }
    }
    else
    {
        QList<int> wl = splitter()->sizes();
        int left = wl[0];
        int right = wl[1];

        if(pos == (right + left))
        {
            isExpand = false;
            currentPixmap = leftpPixmap;
        }
        else
        {
            currentPixmap = rightpPixmap;
            isExpand = true;
        }
    }

}
