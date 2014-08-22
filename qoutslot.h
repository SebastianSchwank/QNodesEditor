#ifndef QOUTSLOT_H
#define QOUTSLOT_H

#include "qnode.h"
#include "qSlot.h"
#include "qinslot.h"

#include "ConnectionStatus.h"
#include "TransferStatus.h"

class qOutSlot : private qSlot
{
public:
    qOutSlot(QString id);

    ConnectionReturnStatus routeTo(qInSlot *destination);
    TransferReturnStatus transfer();

};

#endif // QOUTSLOT_H
