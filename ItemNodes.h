//
// Created by mohit on 12/1/17.
//

#ifndef LFU_NODE_H
#define LFU_NODE_H


#include <unordered_map>
#include "FrequencyNode.h"

using namespace std;

class ItemNodes {

private:
    int numItems;
    vector<int> items;
    FrequencyNode *parent;
    unordered_map<int, int> ItemIndexMap;
public:
    ItemNodes();
    ~ItemNodes();
    ItemNodes(int value, FrequencyNode *parent);
    ItemNodes(FrequencyNode *parent);
    bool ItemPresent(int value);
    void AddItem(int value);
    void RemoveItem(int value);
    int GetItem();
};


#endif //LFU_NODE_H
