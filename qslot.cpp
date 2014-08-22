#include "qslot.h"

qSlot::qSlot(QString id){
    this->id = id;
}

bool qSlot::isLocked(){
    return currentlyInUse;
}

void qSlot::connectTo(qSlot* destinationSlot){
    connectedSlot = destinationSlot;
}

qSlot qSlot::getConnectedSlot(){
    if(this->getConnectedSlot() != nullptr) return *(this->connectedSlot);
    else return nullptr;
}

QString qSlot::getExchangeStr(){
    return exchangeStr;
}

void qSlot::setExchangeStr(QString exchangeStr){
    this->exchangeStr = exchangeStr;
}

void qSlot::Lock(){
    currentlyInUse = true;
}

void qSlot::Unlock(){
    currentlyInUse = false;
}
