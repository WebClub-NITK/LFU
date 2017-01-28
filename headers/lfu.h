//
// Created by mohit on 12/1/17.
//

#ifndef EXAMPLE_CACHE_H
#define EXAMPLE_CACHE_H

#include <unordered_map>
#include "FrequencyNode.h"

using namespace std;

class LFU{

private:
    FrequencyNode *root;
    unordered_map<int, FrequencyNode *> itemFrequencyNodeMap;
    unordered_map<int, FrequencyNode *> frequencyFrequencyNodeMap;
public:
    LFU();
    ~LFU();
    void InitialiseRoot();
    void InsertItem(int value);
    void RemoveItem(int value);
    bool Access(int value);

    void NewFrequencyNodeInsert(int value, int frequency);

    void ExistingFrequencyInsert(int value, int frequency) ;

    void InsertInNextFrequency(int value, FrequencyNode *currNode);
};



#endif //EXAMPLE_CACHE_H
