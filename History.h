
#ifndef DSA_PROJECT_HISTORY_H
#define DSA_PROJECT_HISTORY_H

#include "Ticket.h"

class HistoryNode {
public:
    Ticket* ticket;
    HistoryNode* next;

    HistoryNode(Ticket* ticket);
};


#endif //DSA_PROJECT_HISTORY_H
