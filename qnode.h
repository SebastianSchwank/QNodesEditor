#ifndef QNODE_H
#define QNODE_H

#include <QString>
#include <QVector>

#include "qInSlot.h"
#include "qOutSlot.h"

class QNode
{
public:
    QNode(QString id);
    ~QNode();

    bool addSlot(qSlot newQslot);

private:
    QVector<qInSlot>  QslotsIn;
    QVector<qOutSlot> QslotsOut;

public:
    enum ConnectionReturnStatus
    {
          OK,
          SLOT_IN_USE,
          INVALID_CONNECTION_COMBINATION,
          UNKNOWN_CONNECTION_ERROR
    };

    enum TransferReturnStatus
    {
          OK,
          SLOT_IN_USE,
          NO_SLOT_CONNECTED,
          UNKNOWN_TRANFER_ERROR
    };

};

#endif // QNODE_H
