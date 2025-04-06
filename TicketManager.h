

#ifndef DSA_PROJECT_TICKETMANAGER_H
#define DSA_PROJECT_TICKETMANAGER_H

#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include "Ticket.h"
#include "History.h"
#include "CategoryTree.h"

class TicketManager {
private:
    queue<Ticket*> openTickets;
    stack<Ticket*> resolvedTickets;
    unordered_map<int, Ticket*> ticketMap;
    HistoryNode* historyHead;
    CategoryNode* categoryRoot;
    int ticketId;

    CategoryNode* insertCategory(CategoryNode* root, string category, Ticket* ticket);
    void displayCategoryTickets(CategoryNode* root, string category);
    void displayTicket(Ticket* t);

public:
    TicketManager();

    void createTicket(string title, string category, string description);
    void viewOpenTickets();
    void resolveTicket();
    void viewResolvedTickets();
    void searchTicket(int id);
    void viewTicketsByCategory(string category);
    void viewHistory();
};

#endif //DSA_PROJECT_TICKETMANAGER_H
