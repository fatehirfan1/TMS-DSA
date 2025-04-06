

#ifndef DSA_PROJECT_CATEGORYTREE_H
#define DSA_PROJECT_CATEGORYTREE_H

#include <string>
#include <vector>
using namespace std;

#include "Ticket.h"

class CategoryNode {
public:
    string category;
    vector<Ticket*> tickets;
    CategoryNode* left;
    CategoryNode* right;

    CategoryNode(string category);
};


#endif //DSA_PROJECT_CATEGORYTREE_H
