#ifndef TOPOLOGYPAGE_H
#define TOPOLOGYPAGE_H
#include <QScrollArea>
#include "ui/mtopologylabel.h"
#include "topologydaitem.h"
#include "topologytriggeritem.h"
#include <QList>

#define TRIGGER_COLUMN_MAX_COUNT    12

#define LAYER_GAP_WIDTH                 20
#define DA_TRIGGER_GAP_WIDTH        20
#define TRIGGER_GAP_HEIGHT              10
#define DA_GAT_HEIGHT               20

typedef struct tTrItem
{
    QPoint pt;
    MTopologyItem* item;
}TrItem;

typedef struct tDAItem
{
    QPoint pt;
    MTopologyItem* item;
    QList<TrItem> trigger_item_list;
}DAItem;

class TopologyPage : public QWidget
{
    Q_OBJECT
public:
    TopologyPage(QWidget *parent = 0);

    QString& widget_name();

    void UpdateData();

signals:
    void DAClicked(int id);
    void TriggerClicked(int id);
public slots:
    void onParentResizeSignal(int w,int h);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);

private:
    void CalculateLayout();
    void CalculatePostion();
    void Draw(QPainter& painter);
    void DrawBackground(QPainter& painter);
    void DrawItems(QPainter& painter);
    void DrawLines(QPainter& painter);
    void DrawSingleItem(QPainter& painter,MTopologyItem* item, int posx,int posy);

    MTopologyItem* CheckClicked(const QPoint& pt);

    void ClearLayer();
private:

    typedef QList<int> DataAcquisitionList;
    typedef QList<DataAcquisitionList> TopologyLayerList;
    typedef QList<DAItem> TItemList;

    MTopologyItem* item_;
    QPoint item_pos_;

    QString widget_name_;
    TopologyLayerList layer_;
    int width_;
    int height_;

    QSize parent_size_;

    TItemList titem_list_;

    MTopologyItem* item_press_;
};

#endif // TOPOLOGYPAGE_H
