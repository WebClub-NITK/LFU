//
// Created by mohit on 20/2/17.
//

#include <iostream>
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
void FrequencyList::AddNode(int node) {
    this->nodelist[node] = 1;
}

void FrequencyList::DeleteNode(int node) {
    if(NodePresent(node)){
        // node present.
        this->nodelist.erase(node);
    }else{
        // Node not present.
    }
}

void FrequencyList::LookUpNode(int node) {
    // Node present in the node list.
    if(NodePresent(node)){
        // increase the count and remove from this node.
    } else{
        // node not present.
    }
}

void FrequencyList::PrintNodeList() {
    unordered_map<int, int>::const_iterator iter = this->nodelist.begin();
    while(iter!=this->nodelist.end()){
        cout<<iter->first<<" ";
        iter++;
    }
    cout<<endl;
}

void FrequencyList::SetCount(int val) {
    this->count = val;
}

unordered_map<int, int> FrequencyList::GetNodeList() {
    return this->nodelist;
}

bool FrequencyList::NodePresent(int node) {
    unordered_map<int, int>::const_iterator iter= this->nodelist.find(node);
    return !(iter == this->nodelist.end());
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

bool FrequencyList::IsEmpty() {
    return this->nodelist.empty();
}