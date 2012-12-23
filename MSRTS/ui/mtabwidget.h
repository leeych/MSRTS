#ifndef MTABWIDGET_H
#define MTABWIDGET_H

#include <QTabWidget>
#include <QTabBar>

class MTabBar : public QTabBar
{
    Q_OBJECT

public:
    explicit MTabBar(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);

    virtual QSize tabSizeHint(int index) const;
};

class MTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit MTabWidget(QWidget *parent = 0);
    void setDefaultTabName(QString& strName);
    
    void changeTab(QString& strTabName);
signals:
    
public slots:
    void closeTab(int index);

private:
    MTabBar* tabBar;
    QString strDefaultTabName;
};

#endif // MTABWIDGET_H
