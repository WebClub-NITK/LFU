//
// Created by mohit on 20/2/17.
//

#ifndef LFU_FREQUENCYLIST_H
#define LFU_FREQUENCYLIST_H

#include "unordered_map"
#include "Constants.h"

using namespace std;
struct Node {
    int ItemName;
};

class FrequencyList {
private:
    int count;
    unordered_map<Node, int> nodelist;
    FrequencyList *left;
    FrequencyList *right;
public:
    FrequencyList();
    FrequencyList(int count);
    FrequencyList(int count, FrequencyList *left, FrequencyList *right);
    ~FrequencyList();
    void AddNode(Node node);
    void LookUpNode(Node node);
    void DeleteNode(Node node);
    bool NodePresent(Node node);
    int GetCount();
    void SetPrevious(FrequencyList *left);
    void SetNext(FrequencyList *right);
    FrequencyList *GetPrevious();
    FrequencyList *GetNext();
};


#endif //LFU_FREQUENCYLIST_H
