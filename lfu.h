//
// Created by mohit on 12/1/17.
//

#ifndef EXAMPLE_CACHE_H
#define EXAMPLE_CACHE_H

#include <unordered_map>
using namespace std;

class LFU{

private:
    struct FrequencyNode *root;
    unordered_map<int, struct FrequencyNode *> frequencyMap;
public:
    LFU();
    ~LFU();
    void InitialiseRoot();
    void InsertItem(int value);
    void RemoveItem(int value);
    void Access(int value);

};



#endif //EXAMPLE_CACHE_H
