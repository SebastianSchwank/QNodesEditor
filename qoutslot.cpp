#include "qoutslot.h"

qOutSlot::qOutSlot(QString id) : qSlot(id)
{
}

QNode::ConnectionReturnStatus qOutSlot::routeTo(qInSlot *destination){
    //Connect to the destination-slot
    this->connectTo(destination);

    //Everythings all right the Node's Slots have been connected
    return QNode::OK;
}

QNode::TransferReturnStatus qOutSlot::transfer(){

    if(this->connectedSlot == 0){
        return QNode::NO_SLOT_CONNECTED;
    }else{
        if(this->connectedSlot->currentlyInUse == true){
            return QNode::SLOT_IN_USE;
        }else{
            this->connectedSlot->setExchangeStr(this->getExchangeStr());
            //Everythings all right the Value & the String have been transfered
            return QNode::OK;
        }
    }

    //THIS MAY NEVER BE REACHED
    return QNode::UNKNOWN_TRANFER_ERROR;
}
