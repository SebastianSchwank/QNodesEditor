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

public slots:
    void handleDndMessage(const qDnDMessage &message);

protected:
    //Take over the interaction
    virtual void wheelEvent(QWheelEvent* event);

    QMap<unsigned int,QNodeConnectorTuple>* dataModel = nullptr;

};

#endif // QNODEVIEW_H
