#ifndef QCONNECTORBLOB_H
#define QCONNECTORBLOB_H

#include <QApplication>
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
#include <QGraphicsLineItem>

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
                            QNodeWidget *myPWidget = 0, long myID = -1 , long connectToID = -1);

    ~qconnectorblob();

public slots:
    void makeDrag();

    void postLoadingConnect();

public:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *event);

    void moveEvent(QMoveEvent *event);

    void repaintMyConnector();
    QGraphicsLineItem mConnector;

    QString getIDTuple();

    bool mtype; //"False" for "In" && "True" for "Out"

    void addConnection(qconnectorblob newBlob);

private:
    QPoint getPositionInGView();

    static QMap<unsigned long,QNodeConnectorTuple> Connections; //DataModel

    static unsigned long smIDcounter;
    long mID;
    long mConnectedToID;

    static bool DnDStartStopFlag;

    static QPoint smDragStartPosition;
    QMimeData mimeData;

    QNodeWidget *mNodeWidget;


};

#endif // QCONNECTORBLOB_H
