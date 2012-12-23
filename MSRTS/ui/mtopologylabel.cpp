#include <QtGui>
#include "mtopologylabel.h"

MTopologyItem::MTopologyItem()
{
    status_ = status_normal;
    xradius_ = 5;
    yradius_ = 5;
    border_width_ = 1;
    innter_border_width_ = 1;

    normal_gradient_.setStart(0,0);
    normal_gradient_.setFinalStop(0,100);
    normal_gradient_.setColorAt(0.0, QColor(115,219,144));
    normal_gradient_.setColorAt(1.0, QColor(76,190,95));

    abnormal_gradient_.setColorAt(0.0, QColor(225,99,100));
    abnormal_gradient_.setColorAt(1.0, QColor(225,53,53));

    notwork_gradient_.setColorAt(0.0, QColor(254,254,254));
    notwork_gradient_.setColorAt(1.0, QColor(206,206,206));

    currentstatus_gradient_.setColorAt(0.0, QColor(255,253,202));
    currentstatus_gradient_.setColorAt(1.0, QColor(255,206,155));

    normal_border_color_.setRgb(62,153,83);
    abnormal_border_color_.setRgb(62,153,83);
    notwork_border_color_.setRgb(62,153,83);
    currentstatus_border_color_.setRgb(62,153,83);

    normal_inner_border_color_.setRgb(132,230,157);
    abnormal_inner_border_color_.setRgb(132,230,157);
    notwork_inner_border_color_.setRgb(132,230,157);
    currentstatus_inner_border_color_.setRgb(132,230,157);

    normal_name_color_.setRgb(255,255,255);
    abnormal_name_color_.setRgb(255,255,255);
    notwork_name_color_.setRgb(102,102,102);
    currentstatus_name_color_.setRgb(205,101,2);

    total_width_ = 0;
    total_height_ = 0;
}


void MTopologyItem::SetBitmap(const QString &normal, const QString &abnormal, const QString &notwork)
{
    normal_icon_.load(normal);
    abnormal_icon_.load(abnormal);
    notwork_icon_.load(notwork);
}

void MTopologyItem::SetName(const QString &n)
{
    name_ = n;

    int width;
    int height;
    width = normal_icon_.width();
    width += border_width_ * 2;
    width += innter_border_width_ * 2;

    width += QApplication::fontMetrics().width(name_);
    width += 30;

    height = border_width_ * 2;
    height += innter_border_width_ * 2;
    height += QApplication::fontMetrics().height();
    height += 20;

    total_width_ = width;
    total_height_ = height;
}

void MTopologyItem::SetStatus(int status)
{
    status_ = status;
}

void MTopologyItem::SetStatusCurrent()
{
    status_backup_ = status_;
    status_ = status_currentstatus;
}

void MTopologyItem::RestoreStatus()
{
    status_ = status_backup_;
}

void MTopologyItem::GetPixmapSize(int &w, int &h)
{
    w = total_width_;
    h = total_height_;
}

int MTopologyItem::width()
{
    return total_width_;
}

int MTopologyItem::height()
{
    return total_height_;
}

void MTopologyItem::Draw(QPixmap *pixmap)
{
    if(pixmap == NULL)
        return;

    QPainter painter(pixmap);
    painter.save();
    //painter.setRenderHint(QPainter::Antialiasing, true);

    painter.fillRect(pixmap->rect(),QBrush(QColor(233,246,254)));
    int ypos;
    ypos = (pixmap->height() - normal_icon_.height())/2;

    QPixmap bitmapicon;
    QColor bordercolor;
    QColor innerbordercolor;
    QLinearGradient textGradient;
    QColor textcolor;

    switch (status_)
    {
    case status_normal:
        bitmapicon = normal_icon_;
        bordercolor = normal_border_color_;
        innerbordercolor = normal_inner_border_color_;
        textGradient = normal_gradient_;
        textcolor = normal_name_color_;
        break;
    case status_abnormal:
        bitmapicon = abnormal_icon_;
        bordercolor = abnormal_border_color_;
        innerbordercolor = abnormal_inner_border_color_;
        textGradient = abnormal_gradient_;
        textcolor = abnormal_name_color_;
        break;
    case status_notwork:
        bitmapicon = notwork_icon_;
        bordercolor = notwork_border_color_;
        innerbordercolor = notwork_inner_border_color_;
        textGradient = notwork_gradient_;
        textcolor = notwork_name_color_;
        break;
    case status_currentstatus:
        if(status_backup_ == status_normal)
        {
            bitmapicon = normal_icon_;
        }
        else if(status_backup_ == status_abnormal)
        {
            bitmapicon = abnormal_icon_;
        }
        else if(status_backup_ == status_notwork)
        {
            bitmapicon = notwork_icon_;
        }

        bordercolor = currentstatus_border_color_;
        innerbordercolor = currentstatus_inner_border_color_;
        textGradient = currentstatus_gradient_;
        textcolor = currentstatus_name_color_;
        break;
    default:
        bitmapicon = normal_icon_;
        bordercolor = normal_border_color_;
        innerbordercolor = normal_inner_border_color_;
        textGradient = normal_gradient_;
        textcolor = normal_name_color_;
        break;
    }

    painter.drawPixmap(0,ypos,bitmapicon);

//    QRect borderrect;
//    borderrect.setTop(0);
//    borderrect.setBottom(pixmap->height() - 1);
//    borderrect.setLeft(bitmapicon.width());
//    borderrect.setRight(pixmap->width() - 1);
//    painter.setBrush(QBrush(bordercolor));
//    painter.drawRoundedRect(borderrect,xradius_,yradius_,Qt::RelativeSize);

//    QRect innerborderrect;
//    innerborderrect.setTop(border_width_);
//    innerborderrect.setBottom(pixmap->height() - 1 - border_width_*2);
//    innerborderrect.setLeft(bitmapicon.width() + border_width_);
//    innerborderrect.setRight(pixmap->width() - 1  - border_width_*2);
//    painter.setBrush(QBrush(QColor(121,222,112)));
//    painter.drawRoundedRect(innerborderrect,xradius_,yradius_,Qt::RelativeSize);

    QRect textrect;
    textrect.setTop(border_width_);
    textrect.setBottom(pixmap->height() - 1 - border_width_*2);
    textrect.setLeft(bitmapicon.width() + border_width_);
    textrect.setRight(pixmap->width() - 1  - border_width_*2);
    QBrush textbrush(textGradient);
    QPen borderpen(bordercolor);
    painter.setPen(borderpen);
    painter.setBrush(textbrush);
    painter.drawRoundedRect(textrect,xradius_,yradius_,Qt::AbsoluteSize);

    QPen textpen(textcolor);
    painter.setPen(textpen);
    painter.drawText(textrect,Qt::AlignCenter,name_ );
    painter.restore();
}

bool MTopologyItem::CheckClicked(const QPoint &pt)
{
    QRect rc(normal_icon_.width(),0,total_width_ - normal_icon_.width(),total_height_);

    if(rc.contains(pt))
    {
        return true;
    }
    return false;
}

int MTopologyItem::itemid()
{
    return itemid_;
}

int MTopologyItem::type()
{
    return -1;
}

void MTopologyItem::SetItemId(int id)
{
    itemid_ = id;
}

