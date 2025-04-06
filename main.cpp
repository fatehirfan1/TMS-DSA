#include <iostream>
#include "TicketManager.h"
using namespace std;

int main() {
    TicketManager manager;
    int choice;

    do {
        cout << "\nTicket Manager Menu:\n";
        cout << "1. Create Ticket\n2. View Open Tickets\n3. Resolve Ticket\n4. View Resolved Tickets\n";
        cout << "5. Search Ticket by ID\n6. View Tickets by Category\n7. View Ticket History\n";
        cout << "0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        string title, desc, category;
        int id;

        switch (choice) {
            case 1:
                cout << "Title: ";
                getline(cin, title);
                cout << "Category: ";
                getline(cin, category);
                cout << "Description: ";
                getline(cin, desc);
                manager.createTicket(title, category, desc);
                break;
            case 2:
                manager.viewOpenTickets();
                break;
            case 3:
                manager.resolveTicket();
                break;
            case 4:
                manager.viewResolvedTickets();
                break;
            case 5:
                cout << "Enter Ticket ID: ";
                cin >> id;
                manager.searchTicket(id);
                break;
            case 6:
                cout << "Enter Category: ";
                getline(cin, category);
                manager.viewTicketsByCategory(category);
                break;
            case 7:
                manager.viewHistory();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}