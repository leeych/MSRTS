#ifndef MTOPOLOGYLABEL_H
#define MTOPOLOGYLABEL_H

#include <QWidget>

class MTopologyItem
{
    //Q_OBJECT
public:
    explicit MTopologyItem();

    enum Status {
        status_normal,
        status_abnormal,
        status_notwork,
        status_currentstatus
    };
    
    void SetBitmap(const QString& normal, const QString& abnormal, const QString& notwork);

    void SetName(const QString& n);
    void SetStatus(int status);
    void SetStatusCurrent();
    void RestoreStatus();
    void GetPixmapSize(int& w,int& h);
    int width();
    int height();

    void Draw(QPixmap* pixmap);

    bool CheckClicked(const QPoint& pt);
    int itemid();
    void SetItemId(int id);

    virtual int type();
signals:
    
public slots:

private:
    QPixmap normal_icon_;
    QPixmap abnormal_icon_;
    QPixmap notwork_icon_;

    QString name_;
    int status_;
    int status_backup_;

    QColor normal_name_color_;
    QColor abnormal_name_color_;
    QColor notwork_name_color_;
    QColor currentstatus_name_color_;

    QLinearGradient normal_gradient_;
    QLinearGradient abnormal_gradient_;
    QLinearGradient notwork_gradient_;
    QLinearGradient currentstatus_gradient_;

    QColor normal_inner_border_color_;
    QColor abnormal_inner_border_color_;
    QColor notwork_inner_border_color_;
    QColor currentstatus_inner_border_color_;

    QColor normal_border_color_;
    QColor abnormal_border_color_;
    QColor notwork_border_color_;
    QColor currentstatus_border_color_;

    int xradius_;
    int yradius_;
    int border_width_;
    int innter_border_width_;

    int total_width_;
    int total_height_;

    QString status_normal_;
    QString status_abnormal_;
    QString status_notwork_;
    QString status_current_;

    int itemid_;
};

#endif // MTOPOLOGYLABEL_H
