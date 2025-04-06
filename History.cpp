
#include "History.h"
HistoryNode::HistoryNode(Ticket* ticket) {
    this->ticket = ticket;
    this->next = nullptr;
}
