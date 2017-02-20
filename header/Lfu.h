//
// Created by mohit on 20/2/17.
//

#ifndef LFU_LFU_H
#define LFU_LFU_H

#include "FrequencyList.h"

class Lfu {
private:
    unordered_map<Node, FrequencyList*> NodeFrequencyListMap;
    unordered_map<int, FrequencyList*> CountFrequencyListMap;
    FrequencyList *head;
public:
    Lfu();
    ~Lfu();
    void Set(int value);
    void Retrieve(int value);
    void Evict(int value);
    struct Node CreateNode(int value);
    bool NodePresent(Node node);
    bool FrequencyNodePresent(int count);
};


#endif //LFU_LFU_H
