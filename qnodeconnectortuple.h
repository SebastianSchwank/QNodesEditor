#ifndef QNODECONNECTORTUPLE_H
#define QNODECONNECTORTUPLE_H

#include "qconnectorblob.h"
#include "qnodewidget.h"

class qconnectorblob;
class QNodeWidget;

struct QNodeConnectorTuple{
    qconnectorblob* property[2];
    QNodeWidget* owner[2];
};


#endif // QNODECONNECTORTUPLE_H
