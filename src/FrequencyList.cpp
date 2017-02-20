//
// Created by mohit on 20/2/17.
//

#include "../header/FrequencyList.h"


// Constructors
FrequencyList::FrequencyList() {

}

FrequencyList::FrequencyList(int count) {
    this->count = count;
}

FrequencyList::FrequencyList(int count, FrequencyList *left, FrequencyList *right) {
    this->count = count;
    this->left = left;
    this->right = right;
}

// Destructors
FrequencyList::~FrequencyList() {
    delete(this->right);
    delete(this->left);
    this->nodelist.clear();
}


// Support functions
void FrequencyList::AddNode(Node node) {
    // Check if the element is already present.
    if(NodePresent(node)){
        // remove from this node and enter in the next one.
    }else{
        this->nodelist.insert(node, 1);
    }
}

void FrequencyList::DeleteNode(Node node) {
    if(NodePresent(node)){
        // node present.
        this->nodelist.erase(node);
    }else{
        // Node not present.
    }
}

void FrequencyList::LookUpNode(Node node) {
    // Node present in the node list.
    if(NodePresent(node)){
        // increase the count and remove from this node.
    } else{
        // node not present.
    }
}

bool FrequencyList::NodePresent(Node node) {
    unordered_map::const_iterator iter= this->nodelist.find(node);
    if(iter == this->nodelist.end()){
        return false;
    }
    return true;
}

int FrequencyList::GetCount() {
    return this->count;
}

void FrequencyList::SetNext(FrequencyList *right) {
    this->right = right;
}

void FrequencyList::SetPrevious(FrequencyList *left) {
    this->left = left;
}

FrequencyList* FrequencyList::GetNext() {
    return this->right;
}

FrequencyList* FrequencyList::GetPrevious() {
    return this->left;
}