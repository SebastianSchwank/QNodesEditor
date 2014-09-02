#ifndef QNODEVIEW_H
#define QNODEVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QWheelEvent>

class QNodeView : public QGraphicsView
{
public:
    QNodeView(QWidget* parent = NULL);

protected:

    //Take over the interaction
    virtual void wheelEvent(QWheelEvent* event);
};

#endif // QNODEVIEW_H
