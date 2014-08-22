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

};

#endif // QNODE_H
