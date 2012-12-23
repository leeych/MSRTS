#ifndef MTITLEWIDGET_H
#define MTITLEWIDGET_H

#include <QWidget>

class MTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MTitleWidget(QString& backgroundname,QWidget *parent = 0);
    void SetTitleName(QString& titlename);
    
    void setDrawBottomLine(bool bdraw);
protected:
    void paintEvent(QPaintEvent *);
signals:
    
public slots:
    
private:
    void DrawBackground(QPainter &painter);
private:
    QPixmap pixmap_title_;
    QPixmap pixmap_background_;
    bool draw_bottom_line_;
    bool is_draw_title_;
};

#endif // MTITLEWIDGET_H
