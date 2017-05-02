//
// Created by mohit on 20/2/17.
//

#ifndef LFU_LFU_H
#define LFU_LFU_H

#include "FrequencyList.h"

class Lfu {
private:
    unordered_map<int, FrequencyList*> NodeFrequencyListMap;
    unordered_map<int, FrequencyList*> CountFrequencyListMap;
    FrequencyList *head;
public:
    Lfu();
    ~Lfu();
    void Set(int value);
    void Retrieve(int value);
    void Evict(int value);
    void EvictFromCache();
    struct Node CreateNode(int value);
    bool NodePresent(int node);
    bool FrequencyNodePresent(int count);
    bool IsNodeEmpty(FrequencyList *frequencyList);
    void PrintLfu();
    void NodeAlreadyPresent(int node);
    void NewNodeSet(int node);
};


#endif //LFU_LFU_H
