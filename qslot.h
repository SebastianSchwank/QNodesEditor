#ifndef QSLOT_H
#define QSLOT_H

#include <QString>
#include <QVector>

class qSlot
{
public:
    qSlot(QString id);

    bool connectTo(qSlot* destinationSlot);

protected:

    float   getExchangeVal();
    QString getExchangeStr();

    void setExchangeVal(float   exchangeVal);
    void setExchangeStr(QString exchangeStr);

    bool currentlyInUse = False;

private:
    qSlot* connectedSlot;

    float   exchangeVal;
    QString exchangeStr;

};

#endif // QSLOT_H
