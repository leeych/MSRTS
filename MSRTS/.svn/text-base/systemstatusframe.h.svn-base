#ifndef SYSTEMSTATUSFRAME_H
#define SYSTEMSTATUSFRAME_H

#include <QFrame>
#include <QVBoxLayout>
#include "ui/mtreewidget.h"

class SystemStatusFrame : public QFrame
{
    Q_OBJECT
public:
    explicit SystemStatusFrame(QWidget *parent = 0);
    
    void UpdateDataToTree();

signals:
    void treeWidgetDoubleClicked(int id);
public slots:
    void onTreeWidgetDoubleClicked(int id);
private:
    QTreeWidgetItem* AddTreeTopLevelFolder(const QString& name);
private:
    QVBoxLayout *infodisplaylayout_;
    MTreeWidget* treewidget_;
};

#endif // SYSTEMSTATUSFRAME_H
