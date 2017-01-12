//
// Created by mohit on 12/1/17.
//

#ifndef LFU_FREQUENCYNODE_H
#define LFU_FREQUENCYNODE_H

#include <vector>
#include "ItemNodes.h"
using namespace std;

class FrequencyNode {

private:
    int frequency;
    FrequencyNode *prev;
    FrequencyNode *next;
    ItemNodes *itemNodes;
public:
    FrequencyNode();
    ~FrequencyNode();
    FrequencyNode(int frequency);
    FrequencyNode(int frequency, FrequencyNode *prev, FrequencyNode *next);
    void AddItem(int value);
    void DeleteItem(int value);
    int AccessItem(int value);
    bool Find(int value);
};


#endif //LFU_FREQUENCYNODE_H
