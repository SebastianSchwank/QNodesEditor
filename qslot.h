#ifndef QSLOT_H
#define QSLOT_H

#include <QString>
#include <QVector>

class qSlot
{
public:
    qSlot(QString id);

    QString getId();

    void connectTo(qSlot* destinationSlot);
    qSlot getConnectedSlot();

    bool isLocked();

protected:

    void Lock();
    void Unlock();

    QString getExchangeStr();

    void setExchangeStr(QString exchangeStr);

private:
    //The Slot we are Connected to
    qSlot* connectedSlot = 0;
    //The Id of the this slot
    QString id;
    //In case of thread-usage we store the exchangeVariables in the Slot,too.
    QString exchangeStr;
    //In case of thread-usage we can lock the Slot here
    bool currentlyInUse = false;

};

#endif // QSLOT_H
