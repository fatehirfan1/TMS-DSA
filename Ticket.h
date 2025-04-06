

#ifndef DSA_PROJECT_TICKET_H
#define DSA_PROJECT_TICKET_H

#include <string>
using namespace std;

class Ticket {
public:
    int id;
    string title;
    string category;
    string description;

    Ticket(int id, string title, string category, string description);
};

#endif //DSA_PROJECT_TICKET_H
