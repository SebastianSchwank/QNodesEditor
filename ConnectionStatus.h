#ifndef CONNECTIONSTATUS_H
#define CONNECTIONSTATUS_H

class ConnectionReturnStatus{

    enum EnumConnectionReturnStatus
    {
          CONNECTION_ESTABLISHED,
          SLOT_IN_USE,
          INVALID_CONNECTION_COMBINATION,
          UNKNOWN_CONNECTION_ERROR
    };
};

#endif // CONNECTIONSTATUS_H
