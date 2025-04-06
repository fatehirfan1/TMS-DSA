
#include "CategoryTree.h"
CategoryNode::CategoryNode(string category) {
    this->category = category;
    left = right = nullptr;
}