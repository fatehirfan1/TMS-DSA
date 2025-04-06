
#include "TicketManager.h"
#include <iostream>
using namespace std;

TicketManager::TicketManager() {
    ticketId = 1;
    historyHead = nullptr;
    categoryRoot = nullptr;
}

CategoryNode* TicketManager::insertCategory(CategoryNode* root, string category, Ticket* ticket) {
    if (!root) {
        CategoryNode* newNode = new CategoryNode(category);
        newNode->tickets.push_back(ticket);
        return newNode;
    }

    if (category < root->category)
        root->left = insertCategory(root->left, category, ticket);
    else if (category > root->category)
        root->right = insertCategory(root->right, category, ticket);
    else
        root->tickets.push_back(ticket);

    return root;
}

void TicketManager::displayCategoryTickets(CategoryNode* root, string category) {
    if (!root) return;
    if (category < root->category)
        displayCategoryTickets(root->left, category);
    else if (category > root->category)
        displayCategoryTickets(root->right, category);
    else {
        for (auto t : root->tickets) {
            displayTicket(t);
        }
    }
}

void TicketManager::displayTicket(Ticket* t) {
    cout << "ID: " << t->id << "\nTitle: " << t->title
         << "\nCategory: " << t->category
         << "\nDescription: " << t->description << "\n---" << endl;
}

void TicketManager::createTicket(string title, string category, string description) {
    Ticket* t = new Ticket(ticketId, title, category, description);
    openTickets.push(t);
    ticketMap[ticketId] = t;
    categoryRoot = insertCategory(categoryRoot, category, t);

    HistoryNode* node = new HistoryNode(t);
    node->next = historyHead;
    historyHead = node;

    cout << "Ticket created. ID: " << ticketId << endl;
    ticketId++;
}

void TicketManager::viewOpenTickets() {
    if (openTickets.empty()) {
        cout << "No open tickets.\n";
        return;
    }

    queue<Ticket*> temp = openTickets;
    while (!temp.empty()) {
        displayTicket(temp.front());
        temp.pop();
    }
}

void TicketManager::resolveTicket() {
    if (openTickets.empty()) {
        cout << "No tickets to resolve.\n";
        return;
    }

    Ticket* t = openTickets.front();
    openTickets.pop();
    resolvedTickets.push(t);
    cout << "Resolved Ticket ID: " << t->id << endl;
}

void TicketManager::viewResolvedTickets() {
    if (resolvedTickets.empty()) {
        cout << "No resolved tickets.\n";
        return;
    }

    stack<Ticket*> temp = resolvedTickets;
    while (!temp.empty()) {
        displayTicket(temp.top());
        temp.pop();
    }
}

void TicketManager::searchTicket(int id) {
    if (ticketMap.find(id) != ticketMap.end()) {
        displayTicket(ticketMap[id]);
    } else {
        cout << "Ticket not found.\n";
    }
}

void TicketManager::viewTicketsByCategory(string category) {
    cout << "Tickets in Category: " << category << endl;
    displayCategoryTickets(categoryRoot, category);
}

void TicketManager::viewHistory() {
    HistoryNode* temp = historyHead;
    while (temp) {
        displayTicket(temp->ticket);
        temp = temp->next;
    }
}