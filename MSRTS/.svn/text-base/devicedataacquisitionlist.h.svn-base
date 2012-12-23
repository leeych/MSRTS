#ifndef DEVICEDATAACQUISITIONLIST_H
#define DEVICEDATAACQUISITIONLIST_H

#include <QWidget>
#include <QTableWidget>
#include <QScrollArea>

class DeviceDataAcquisitionList : public QScrollArea
{
    Q_OBJECT
public:
    explicit DeviceDataAcquisitionList(QWidget *parent = 0);
    
    QString& widget_name();

    void CreateTable(int w);
    void UpdateDataAcquisitionList();

    void SetDAHighlight(int id);
protected:
    void resizeEvent(QResizeEvent * e);
signals:
    
public slots:
    void onCustomContextMenuRequested(const QPoint &pos);

    void onAddAction();
    void onCopyAction();
    void onEditAction();
    void onDeleteAction();
private:
    void CreateMenus();
private:
    QString widget_name_;
    QTableWidget* main_table_;

    QMenu* popmenu_;
    QAction* add_action_;
    QAction* copy_action_;
    QAction* edit_action_;
    QAction* delete_action_;

    int table_width_;
};

#endif // DEVICEDATAACQUISITIONLIST_H
