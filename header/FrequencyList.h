//
// Created by mohit on 20/2/17.
//

#ifndef LFU_FREQUENCYLIST_H
#define LFU_FREQUENCYLIST_H

#include <unordered_map>
#include "Constants.h"

using namespace std;


class FrequencyList {
private:
    int count;
    unordered_map<int, int> nodelist;
    FrequencyList *left;
    FrequencyList *right;
public:
    FrequencyList();
    FrequencyList(int count);
    FrequencyList(int count, FrequencyList *left, FrequencyList *right);
    ~FrequencyList();
    void AddNode(int node);
    void LookUpNode(int node);
    void DeleteNode(int node);
    bool NodePresent(int node);
    void PrintNodeList();
    int GetCount();
    void SetPrevious(FrequencyList *left);
    void SetNext(FrequencyList *right);
    FrequencyList *GetPrevious();
    FrequencyList *GetNext();
    bool IsEmpty();
};


#endif //LFU_FREQUENCYLIST_H
