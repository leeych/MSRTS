#include <QtGui>
#include "mtabwidget.h"
#include "mutility.h"

MTabWidget::MTabWidget(QWidget *parent) :
    QTabWidget(parent)
{
    tabBar = new MTabBar;
    setTabBar(tabBar);

    /*set style*/
//    QString cssDir;
//    getCssDir(cssDir);;

    setStyleSheet(QLatin1String(fetchQrc(":/qss/tabwidget.qss")));
    connect(this,SIGNAL(tabCloseRequested(int)),this,SLOT(closeTab(int)));
}

void MTabWidget::setDefaultTabName(QString &strName)
{
    strDefaultTabName = strName;
}

void MTabWidget::changeTab(QString &strTabName)
{
    int tabNount = count();

    if(tabNount == 0)
        return;

    for(int i = 0;i < tabNount;i++)
    {
        if(strTabName == tabText(i))
        {
            setCurrentIndex(i);
        }
    }
}

void MTabWidget::closeTab(int index)
{
    if(tabText(index) != strDefaultTabName)
    {
        removeTab(index);
    }
}

MTabBar::MTabBar(QWidget *parent) :
    QTabBar(parent)
{
    //QSize sz = sizeHint();


}

void MTabBar::paintEvent(QPaintEvent* pe)
{
//    QPainter paint(this);

//    paint.setPen(Qt::red);
//    QPixmap p("E:/WorkSpace/MSWA_release/debug/images/background_image.png");
////    paint.drawPixmap(rect(),p);
//    //paint.fillRect(rect(), Qt::Dense6Pattern);

//    //QTabBar::paintEvent(pe);
//    QSize sz = tabSizeHint(0);
//    paint.drawPixmap(QRect(0,0,sz.width(),sz.height()),p);

    QTabBar::paintEvent(pe);

}

QSize MTabBar::tabSizeHint(int index) const
{

    return QTabBar::tabSizeHint(index);
}
