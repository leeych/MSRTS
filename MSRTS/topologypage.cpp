#include <QtGui>
#include "topologypage.h"
#include "MacroImage.h"
#include "data/mrtsdatabase.h"
#include <algorithm>

TopologyPage::TopologyPage(QWidget *parent) :
    QWidget(parent)
{
    item_press_ = NULL;
    width_ = 0;
    height_ = 0;
    item_ = new MTopologyItem;
    item_->SetName(STRING_RUNTIME_CONTROL_SYSTEM);
    item_pos_.setX(30);
    item_pos_.setY(30);
    widget_name_ = STRING_TOPOLOGY;
    setStyleSheet("background-color: rgb(233,246,254);");
}

QString &TopologyPage::widget_name()
{
    return widget_name_;
}

void TopologyPage::UpdateData()
{
    ClearLayer();
    CalculateLayout();
    CalculatePostion();
}

void TopologyPage::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    Draw(painter);
}

void TopologyPage::mousePressEvent(QMouseEvent *e)
{
    item_press_ = NULL;
    item_press_ = CheckClicked(e->pos());

    if(item_press_ != NULL)
    {
        item_press_->SetStatusCurrent();
        update();
    }
}

void TopologyPage::mouseReleaseEvent(QMouseEvent *e)
{
    if(item_press_ != NULL)
    {
        item_press_->RestoreStatus();
        update();
        if(item_press_->type() == 0)
        {
            emit TriggerClicked(item_press_->itemid());
        }

        if(item_press_->type() == 1)
        {
            emit DAClicked(item_press_->itemid());
        }
        item_press_ = NULL;

    }
}

void TopologyPage::CalculateLayout()
{
    MRtsDataBase* db = MRtsDataBase::GetInstance();
    int layertriggercount = 0;
    int layertriggermaxcount = 0;

    QList<int> dalist;
    dalist = db->DataAcquisitionList();
    MDataAcquisition* da;
    DataAcquisitionList tmpdalist;
    for(QList<int>::iterator daitr = dalist.begin();daitr != dalist.end();daitr++)
    {
        if(db->DataAcquisition(*daitr,da))
        {
            QList<int> trlist;
            trlist = da->triggerid_list();

            if(trlist.size() >= TRIGGER_COLUMN_MAX_COUNT)
            {
                layertriggermaxcount = std::max(layertriggermaxcount, trlist.size());
                layertriggermaxcount = std::max(layertriggermaxcount, layertriggercount);

                if(!tmpdalist.isEmpty())
                {
                    layer_.push_back(tmpdalist);
                    tmpdalist.clear();
                }

                tmpdalist.push_back(*daitr);
                layer_.push_back(tmpdalist);
                tmpdalist.clear();
                layertriggercount = 0;
                continue;
            }

            if(trlist.isEmpty())
            {
                tmpdalist.push_back(*daitr);
                layertriggercount++;
                if(layertriggercount >= TRIGGER_COLUMN_MAX_COUNT)
                {
                    layer_.push_back(tmpdalist);
                    tmpdalist.clear();
                    layertriggercount = 0;
                }
                continue;
            }

            layertriggercount += trlist.size();
            if(layertriggercount > TRIGGER_COLUMN_MAX_COUNT)
            {
                layertriggermaxcount = std::max(layertriggermaxcount, trlist.size());
                layertriggermaxcount = std::max(layertriggermaxcount, layertriggercount);

                if(!tmpdalist.isEmpty())
                {
                    layer_.push_back(tmpdalist);
                    tmpdalist.clear();
                }

                tmpdalist.push_back(*daitr);
                layertriggercount = trlist.size();
                continue;
            }
            else if(layertriggercount == TRIGGER_COLUMN_MAX_COUNT)
            {
                layertriggermaxcount = std::max(layertriggermaxcount, layertriggercount);
                tmpdalist.push_back(*daitr);
                layer_.push_back(tmpdalist);
                tmpdalist.clear();
                layertriggercount = 0;
                continue;
            }
            else
            {
                tmpdalist.push_back(*daitr);
                if(tmpdalist.size() >= TRIGGER_COLUMN_MAX_COUNT)
                {
                    layertriggermaxcount = std::max(layertriggermaxcount, tmpdalist.size());
                    layer_.push_back(tmpdalist);
                    tmpdalist.clear();
                    layertriggercount = 0;
                }
                layertriggermaxcount = std::max(layertriggermaxcount, layertriggercount);
            }
        }
    }

    if(!tmpdalist.isEmpty())
    {
        layer_.push_back(tmpdalist);
    }

}

void TopologyPage::CalculatePostion()
{
    MRtsDataBase* db = MRtsDataBase::GetInstance();
    MDataAcquisition* da;
    MTrigger* tr;

    int layerposx = item_pos_.x() + item_->width() + DA_TRIGGER_GAP_WIDTH;
    int layerposy =  item_pos_.y() + item_->height() + TRIGGER_GAP_HEIGHT;
    int layerwidth = 0;
    int layerMaxheight = 0;
    for(QList<DataAcquisitionList>::iterator dalistitr = layer_.begin();dalistitr != layer_.end();dalistitr++)
    {
        layerposx += layerwidth;
        layerposy =  item_pos_.y() + item_->height() + TRIGGER_GAP_HEIGHT;
        int damaxwidth = 0;
        int trmaxwidth = 0;
        for(QList<int>::iterator daIditr = (*dalistitr).begin(); daIditr != (*dalistitr).end(); daIditr++)
        {
            if(db->DataAcquisition(*daIditr,da))
            {
                DAItem daItem;
                QList<int> trlist;
                trlist = da->triggerid_list();
                daItem.item = new TopologyDAItem;
                daItem.item->SetName(da->name());
                daItem.item->SetStatus(da->status());
                daItem.item->SetItemId(da->id());
                damaxwidth = std::max(daItem.item->width(),damaxwidth);
                int trlist_height = 0;

                //add trigger list of da to trItemlist
                int trgap = 0;
                for(QList<int>::iterator tritr = trlist.begin();tritr != trlist.end();tritr++)
                {
                    if(db->Trigger(*tritr,tr))
                    {
                        TrItem trItem;
                        trItem.item = new TopologyTriggerItem;
                        trItem.item->SetName(tr->trigger_name());
                        trItem.item->SetStatus(tr->status());
                        trItem.item->SetItemId(tr->trigger_id());
                        trmaxwidth = std::max( trItem.item->width(),trmaxwidth);
                        daItem.trigger_item_list.push_back(trItem);
                         trlist_height += trItem.item->height();
                         trgap++;
                    }
                }

                if(trgap > 0)
                {
                    trlist_height += (trgap-1) * TRIGGER_GAP_HEIGHT;
                }

                //calculate data acquisition position
                if(daItem.item->height() > trlist_height)
                {
                    daItem.pt.setX(layerposx);
                    daItem.pt.setY(layerposy);
                }
                else
                {
                    int posh = (trlist_height-daItem.item->height())/2 + layerposy;
                    daItem.pt.setX(layerposx);
                    daItem.pt.setY(posh);
                }

                //calculate trigger list position
               int trposx = layerposx + daItem.item->width() + DA_TRIGGER_GAP_WIDTH;
               int trposy = layerposy;

               for(QList<TrItem>::iterator trItemitr = daItem.trigger_item_list.begin();trItemitr != daItem.trigger_item_list.end();trItemitr++)
               {
                   (*trItemitr).pt.setX(trposx);
                   (*trItemitr).pt.setY(trposy);
                   trposy += (*trItemitr).item->height() +  TRIGGER_GAP_HEIGHT;
               }

               layerposy += std::max(daItem.item->height(),trlist_height) + DA_GAT_HEIGHT;

               titem_list_.push_back(daItem);
            }
        }

        layerwidth = damaxwidth + DA_TRIGGER_GAP_WIDTH + trmaxwidth + LAYER_GAP_WIDTH;
        layerMaxheight = std::max(layerposy,layerMaxheight);
    }

    width_ = layerposx + layerwidth;
    height_ = layerMaxheight;

    width_ = std::max(width_, parent_size_.width());

    resize(width_,height_);
}

void TopologyPage::Draw(QPainter &painter)
{
    DrawBackground(painter);
    DrawItems(painter);
    DrawLines(painter);
}

void TopologyPage::DrawBackground(QPainter &painter)
{
    painter.fillRect(0,0,width(),height(),QColor(233,246,254));
}

void TopologyPage::DrawItems(QPainter &painter)
{
    DrawSingleItem(painter,item_,item_pos_.x(),item_pos_.y());

    for(TItemList::iterator titr = titem_list_.begin(); titr != titem_list_.end(); titr++)
    {
        DrawSingleItem(painter,(*titr).item,(*titr).pt.x(),(*titr).pt.y());
        for(QList<TrItem>::iterator itr = (*titr).trigger_item_list.begin();itr != (*titr).trigger_item_list.end();itr++)
        {
            DrawSingleItem(painter,(*itr).item,(*itr).pt.x(),(*itr).pt.y());
        }
    }
}

void TopologyPage::DrawLines(QPainter &painter)
{
    painter.save();
    QPen pen(QColor(102,102,102));
    painter.setPen(pen);

    int itemposx = item_pos_.x() + item_->width();
    int itemposy =  item_pos_.y() + item_->height()/2;
    painter.drawLine(itemposx,itemposy,width(),itemposy);

    int daposx = 0;
    int daposy = 0;
    int trposx = 0;
    int trposy = 0;
    for(TItemList::iterator titr = titem_list_.begin(); titr != titem_list_.end(); titr++)
    {
        daposx = (*titr).pt.x() + (*titr).item->width();
        daposy = (*titr).pt.y() + (*titr).item->height()/2;

        painter.drawLine((*titr).pt.x() - 10 ,itemposy,(*titr).pt.x() - 10,daposy);
        painter.drawLine((*titr).pt.x() - 10 ,daposy,(*titr).pt.x(),daposy);

        for(QList<TrItem>::iterator itr = (*titr).trigger_item_list.begin();itr != (*titr).trigger_item_list.end();itr++)
        {
            trposx = (*itr).pt.x();
            trposy = (*itr).pt.y() + (*itr).item->height()/2;

            if(trposx == daposx)
            {
                painter.drawLine(daposx,daposy,trposx,trposy);
            }
            else
            {
                int joinposx = daposx + std::abs((trposx - daposx)/2);
                painter.drawLine(daposx,daposy,joinposx,daposy);
                painter.drawLine(joinposx,daposy,joinposx,trposy);
                painter.drawLine(joinposx,trposy,trposx,trposy);
            }
        }
    }

    painter.restore();
}

void TopologyPage::DrawSingleItem(QPainter &painter, MTopologyItem *item, int posx, int posy)
{
    if(item == NULL)
    {
        return;
    }

    int w,h;
    item->GetPixmapSize(w,h);
    QPixmap pixmap(w,h);
    item->Draw(&pixmap);
    painter.drawPixmap(posx,posy,pixmap);
}

MTopologyItem *TopologyPage::CheckClicked(const QPoint &pt)
{
//    DrawSingleItem(painter,item_,item_pos_.x(),item_pos_.y());

    QRect rc;
    QPoint offsetpt;
    for(TItemList::iterator titr = titem_list_.begin(); titr != titem_list_.end(); titr++)
    {
        rc.setRect((*titr).pt.x(),(*titr).pt.y(),(*titr).item->width(),(*titr).item->height());
        if(rc.contains(pt))
        {
            offsetpt.setX(pt.x() - (*titr).pt.x());
            offsetpt.setY(pt.y() - (*titr).pt.y());
            if((*titr).item->CheckClicked(offsetpt))
            {
                return (*titr).item;
            }
        }
        for(QList<TrItem>::iterator itr = (*titr).trigger_item_list.begin();itr != (*titr).trigger_item_list.end();itr++)
        {
            rc.setRect((*itr).pt.x(),(*itr).pt.y(),(*itr).item->width(),(*itr).item->height());
            if(rc.contains(pt))
            {
                offsetpt.setX(pt.x() - (*itr).pt.x());
                offsetpt.setY(pt.y() - (*itr).pt.y());
                if((*itr).item->CheckClicked(offsetpt))
                {
                    return (*itr).item;
                }
            }
        }
    }

    return NULL;
}

void TopologyPage::ClearLayer()
{
    layer_.clear();

    for(TItemList::iterator titr = titem_list_.begin(); titr != titem_list_.end(); titr++)
    {
        if((*titr).item != NULL)
        {
            delete (*titr).item;
            (*titr).item = NULL;
        }

        for(QList<TrItem>::iterator itr = (*titr).trigger_item_list.begin();itr != (*titr).trigger_item_list.end();itr++)
        {
            if((*itr).item != NULL)
            {
                delete (*itr).item;
                (*itr).item = NULL;
            }
        }
    }

    titem_list_.clear();
}

void TopologyPage::onParentResizeSignal(int w, int h)
{
    parent_size_.setWidth(w);
    parent_size_.setHeight(h);
}
