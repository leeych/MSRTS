#ifndef EVENTTREEWIDGET_H
#define EVENTTREEWIDGET_H

#include <QTreeWidget>

#define TOP_LEVEL       1
#define SECOND_LEVEL    2
#define THIRD_LEVEL     3

class MTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit MTreeWidget(QWidget *parent = 0);
    ~MTreeWidget();

    QTreeWidgetItem * addWidgetItem(QTreeWidgetItem *node,
                                   const QIcon &icon,
                                   const QString &name,
                                   const QColor &color,
                                   int itemLevel,
                                   int itemProperty = -1);

    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *e);

signals:
    void itemDoubleClickedSignal(int id);
public slots:
    void onItemDoubleClickedSlot(QTreeWidgetItem *item, int column);
    void onItemClicked(QTreeWidgetItem *item, int column);

private:
    void mousePressEvent(QMouseEvent *event);

private:

};

#endif // EVENTTREEWIDGET_H
