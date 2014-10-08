#ifndef QCONNECTORBLOB_H
#define QCONNECTORBLOB_H

#include <QWidget>
#include <QT>
#include <QGraphicsScene>
#include <QRadioButton>

#include <QDrag>
#include <QMimeData>

#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QMimeType>
#include <QMap>

#include "qnodewidget.h"
#include "qnodeconnectortuple.h"
#include "qdndmessage.h"
#include "qnodeview.h"

#include <QDebug>

class QNodeWidget;

namespace Ui {
class qconnectorblob;
}

class qconnectorblob : public QRadioButton
{
    Q_OBJECT

public:
    explicit qconnectorblob(QWidget *parent = 0, bool type = false,
                            QNodeWidget *myPWidget = 0);
    ~qconnectorblob();

public slots:
    void makeDrag();

public:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *event);

private:
    static QMap<unsigned int,QNodeConnectorTuple> Connections; //DataModel

    static unsigned int smIDcounter;
    unsigned int mID;

    static bool DnDStartStopFlag;

    static QPoint smDragStartPosition;
    QMimeData mimeData;

    bool mtype; //"False" for "In" && "True" for "Out"
    QNodeWidget *mNodeWidget;

};

#endif // QCONNECTORBLOB_H
