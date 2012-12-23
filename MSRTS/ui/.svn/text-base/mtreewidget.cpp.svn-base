#include <QtGui>
#include "mtreewidget.h"

MTreeWidget::MTreeWidget(QWidget *parent) :
    QTreeWidget(parent)
{
    setStyleSheet("background-color: rgb(233,246,254);font:12px;border: 1px solid #759cb9;");

    setHeaderHidden(true);

    connect(this,SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)),this,SLOT(onItemDoubleClickedSlot(QTreeWidgetItem*,int)));
    connect(this, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(onItemClicked(QTreeWidgetItem*,int)));
}


MTreeWidget::~MTreeWidget()
{
}

QSize MTreeWidget::sizeHint() const
{
    return QSize(100, 500);
}

void MTreeWidget::paintEvent(QPaintEvent *e)
{
    QTreeWidget::paintEvent(e);
}

void MTreeWidget::onItemDoubleClickedSlot(QTreeWidgetItem *item, int column)
{
    int level = item->text(1).toInt();

    if(level == SECOND_LEVEL )
    {
        int id = item->text(2).toInt();
        emit itemDoubleClickedSignal(id);
        return;
    }

//    if(level == LEVEL_EVENT)
//    {
//        MDataBase * database = MDataBase::getInstance();
//        MEvent ev = database->event(item->text(2).toInt());

//        if ( false == ev.hasDetail() )
//        {

//            int ret;

//            ret = SendRequest::SendGettEventAssociationRequest(item->text(2).toInt());

//            if ( -2 == ret)
//            {
//                QMessageBox::warning(this, tr("Connect Error"), tr("Could not connect server"));
//            }
//        }

//        EventInfo evInfo;
//        ev.eventInfo(evInfo);
//        if(evInfo.id != -1)
//        {
//            addEventTriggerByEvent(item,ev);
//            emit eventDisplaySignal(evInfo);
//        }
//    }
}

QTreeWidgetItem* MTreeWidget::addWidgetItem(QTreeWidgetItem *node,
                                               const QIcon &icon,
                                               const QString &name,
                                               const QColor &color,
                                               int itemLevel,
                                               int itemProperty)
{
    if(itemLevel == TOP_LEVEL)
    {
        int ncount = topLevelItemCount();
        if(ncount > 0)
        {
            for(int i = 0;i < ncount;i++)
            {
                QTreeWidgetItem* item = topLevelItem(i);
                if(item->text(0) == name)
                {
                    return item;
                }
            }
        }

        node = new QTreeWidgetItem(this);
        node->setText(0, name);
        node->setIcon(0, icon);
        node->setTextColor(0,color);
        return node;
    }

    if(node != NULL)
    {
        int count = node->childCount();

        for(int i = 0;i < count;i++)
        {
            if(node->child(i)->text(0) == name)
            {
                //find node ,return it
                return node->child(i);
            }
        }
    }

    QTreeWidgetItem *newItem = new QTreeWidgetItem(node);
    if(newItem == NULL)
    {
        return NULL;
    }

    QString strLevel;
    strLevel.sprintf("%d",itemLevel);
    QString strItemProperty;
    strItemProperty.sprintf("%d",itemProperty);
    newItem->setText(0, name);
    newItem->setIcon(0, icon);
    newItem->setTextColor(0,color);
    newItem->setText(1, strLevel);
    newItem->setText(2,strItemProperty);

    return newItem;
}

void MTreeWidget::mousePressEvent(QMouseEvent *event)
{
    QTreeView::mousePressEvent(event);

    if(event->buttons() == Qt::RightButton)
    {
    }
}

void MTreeWidget::onItemClicked(QTreeWidgetItem *item, int column)
{
    int level = item->text(1).toInt();

}
