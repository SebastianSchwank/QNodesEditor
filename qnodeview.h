#ifndef QNODEVIEW_H
#define QNODEVIEW_H

#include "qconnectorblob.h"
#include "qdndmessage.h"

#include <QGraphicsView>
#include <QMouseEvent>
#include <QWheelEvent>

#include <QDrag>

class QNodeView : public QGraphicsView
{
    Q_OBJECT

public:
    QNodeView(QWidget* parent = NULL);

protected:
    //Take over the interaction
    virtual void wheelEvent(QWheelEvent* event);

};

#endif // QNODEVIEW_H
