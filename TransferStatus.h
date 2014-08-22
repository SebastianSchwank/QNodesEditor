#ifndef TRANSFERSTATUS_H
#define TRANSFERSTATUS_H

class TransferReturnStatus{

    enum EnumTransferReturnStatus
    {
          TRANSFER_SUCESSFULL,
          SLOT_IN_USE,
          NO_SLOT_CONNECTED,
          UNKNOWN_TRANFER_ERROR
    };
};

#endif // TRANSFERSTATUS_H
