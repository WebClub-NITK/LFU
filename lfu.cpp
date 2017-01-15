//
// Created by mohit on 12/1/17.
//
#include "lfu.h"
#include "FrequencyNode.h"

using namespace std;

LFU::LFU() {
    InitialiseRoot();
}

LFU::~LFU() {
    delete(this);
}

void LFU::InitialiseRoot() {
    // initialise root with new frequency node with frequency zero;
    this->root = new FrequencyNode(0);
}

/**
* Look for the value in the valueFrequencyNode.
*  If it is present
*      Remove from that node, add to the next frequency node.
*          Check if the next frequency node exists
*              yes, insert
*              no, create a new node and insert.
*  Else
*      create a new node.
*      insert in that node.
* */

void LFU::InsertItem(int value) {
    unordered_map<int, FrequencyNode *>::const_iterator iter = this->itemFrequencyNodeMap.find(value);
    // value not present in the cache.
    int frequency = 0;
    if(iter == this->itemFrequencyNodeMap.end()){
        frequency = 1;
        // frequency node not present.
        if(this->frequencyFrequencyNodeMap.find(frequency) == this->frequencyFrequencyNodeMap.end()){
            FrequencyNode *newNode = new FrequencyNode(frequency);
            FrequencyNode *prevFreqNode = this->frequencyFrequencyNodeMap.find(frequency-1)->second;
            newNode->setPrev(prevFreqNode);
            newNode->setnext(prevFreqNode->getNext());
            prevFreqNode->setnext(newNode);
            newNode->AddItem(value);
            // update frequency map and the value map
            this->frequencyFrequencyNodeMap.insert({frequency, newNode});
            this->itemFrequencyNodeMap.insert({value, newNode});
        }
    }
    // item already present in a frequency node.
    else{
        FrequencyNode *currNode = iter->second;
        // remove from this frequency node and keep it in the next frequency node.
        currNode->DeleteItem(value);
        frequency = currNode->getFrequency();
        // have to check for the next frequency.
        frequency = frequency + 1;
        if(this->frequencyFrequencyNodeMap.find(frequency) == this->frequencyFrequencyNodeMap.end()){
            FrequencyNode *newNode = new FrequencyNode(frequency);
            newNode->setnext(currNode->getNext());
            newNode->setPrev(currNode);
            newNode->AddItem(value);
            this->itemFrequencyNodeMap.insert({value, newNode)});
            this->frequencyFrequencyNodeMap.insert({frequency, newNode});
        }else{
            FrequencyNode *nextNode = this->frequencyFrequencyNodeMap.find(frequency)->second;
            nextNode->AddItem(value);
            this->itemFrequencyNodeMap.insert({value, nextNode});
        }

    }
}

void LFU::RemoveItem(int value) {

}

void LFU::Access(int value) {

}

int main(){

    return 0;
}
