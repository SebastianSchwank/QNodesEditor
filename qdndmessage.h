#ifndef QDNDMESSAGE_H
#define QDNDMESSAGE_H

#include <QMap>

#include "qnodeconnectortuple.h"
#include "qconnectorblob.h"

class qconnectorblob;

struct qDnDMessage{
    enum type{ Drag, ValidDrop, DndDisconnect };

    QMap<unsigned int,QNodeConnectorTuple>* dataModel;
    qconnectorblob* senderObject = nullptr;
    type mType;
};

#endif // QDNDMESSAGE_H
