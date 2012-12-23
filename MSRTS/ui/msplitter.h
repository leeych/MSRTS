#ifndef MSWASPLITTER_H
#define MSWASPLITTER_H

#include <QSplitter>
#include <QPushButton>

typedef enum tagMSplitterExpand
{
    MSplitterLeft,
    MSplitterRight
}MSplitterExpand;

class MSplitterHandle : QSplitterHandle
{
public:
    MSplitterHandle(Qt::Orientation o,MSplitterExpand e, QSplitter *parent);

    bool event(QEvent *event);
    void splitterMoved(int pos);
public slots:


protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
private:
    QPixmap* leftpPixmap;
    QPixmap* rightpPixmap;
    QPixmap* currentPixmap;
    int oldPos;
    bool isPressed;
    bool isMoved;
    QPoint pressPoint;
    QPoint releasePoint;
    bool isExpand;
    QCursor oleCursor;
    MSplitterExpand expandDirection;
};



class MSplitter : public QSplitter
{
    Q_OBJECT
public:
    explicit MSplitter(Qt::Orientation, MSplitterExpand e, QWidget* parent = 0);
    
signals:

public slots:
    void msplitterMoved(int pos, int index);

protected:
   void paintEvent(QPaintEvent *);
    virtual QSplitterHandle *createHandle();
private:

    QPushButton* expandButton;
    MSplitterHandle* splitterHandle;
    Qt::Orientation orientation;
    MSplitterExpand expandDirection;
};

#endif // MSWASPLITTER_H
