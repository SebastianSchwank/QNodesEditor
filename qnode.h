#ifndef QNODE_H
#define QNODE_H

#include <QString>
#include <QVector>

#include "qslot.h"

class QNode
{
public:
    QNode(QString id);
    ~QNode();

    bool addSlot(qSlot newQslot);

private:
    QVector<qSlot> Qslots;

};

#endif // QNODE_H
