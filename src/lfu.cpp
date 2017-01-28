//
// Created by mohit on 12/1/17.
//
#include "../headers/lfu.h"

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
            NewFrequencyNodeInsert(value, frequency);
        }else{
            // frequency node already present.
            ExistingFrequencyInsert(value, frequency);
        }
    }
    // item already present in a frequency node.
    else{
        FrequencyNode *currNode = iter->second;
        // remove from this frequency node and keep it in the next frequency node.
        InsertInNextFrequency(value, currNode);

    }
}

void LFU::InsertInNextFrequency(int value, FrequencyNode *currNode) {
    currNode->DeleteItem(value);
    int frequency = currNode->getFrequency();
    // if the frequency node is empty. Remove it.
    if(currNode->IsEmpty()){
            // remove the currnode.
            currNode->getNext()->setPrev(currNode->getPrev());
            currNode->getPrev()->setnext(currNode->getNext());
            free(currNode);
        }
    // have to check for the next frequency.
    frequency = frequency + 1;
    if(this->frequencyFrequencyNodeMap.find(frequency) == this->frequencyFrequencyNodeMap.end()){
            FrequencyNode *newNode = new FrequencyNode(frequency);
            newNode->setnext(currNode->getNext());
            newNode->setPrev(currNode);
            newNode->AddItem(value);
            this->itemFrequencyNodeMap.insert({value, newNode});
            this->frequencyFrequencyNodeMap.insert({frequency, newNode});
        }else{
            FrequencyNode *nextNode = this->frequencyFrequencyNodeMap.find(frequency)->second;
            nextNode->AddItem(value);
            this->itemFrequencyNodeMap.insert({value, nextNode});
        }
}

void LFU::ExistingFrequencyInsert(int value, int frequency) {
    FrequencyNode *currFreqNode = this->frequencyFrequencyNodeMap.find(frequency)->second;
    currFreqNode->AddItem(value);
    this->itemFrequencyNodeMap.insert({value, currFreqNode});
}

void LFU::NewFrequencyNodeInsert(int value, int frequency) {
    FrequencyNode *newNode = new FrequencyNode(frequency);
    FrequencyNode *prevFreqNode = this->frequencyFrequencyNodeMap.find(frequency - 1)->second;
    newNode->setPrev(prevFreqNode);
    newNode->setnext(prevFreqNode->getNext());
    prevFreqNode->setnext(newNode);
    newNode->AddItem(value);
    // update frequency map and the value map
    this->frequencyFrequencyNodeMap.insert({frequency, newNode});
    this->itemFrequencyNodeMap.insert({value, newNode});
}

/**
 * Remove item.
 * check in the map if the value is present in the cache or not.
 *  - If yes, Remove it from the pointer.
 *  - else, continue;
 * */

void LFU::RemoveItem(int value) {
    unordered_map<int, FrequencyNode *>::const_iterator iter = this->itemFrequencyNodeMap.find(value);
    if(iter != this->itemFrequencyNodeMap.end()){
        FrequencyNode *currNode = iter->second;
        // delete value.
        currNode->DeleteItem(value);
        // check if curr node is empty. If so remove the frequency node.
        if(currNode->IsEmpty()){
            currNode->getNext()->setPrev(currNode->getPrev());
            currNode->getPrev()->setnext(currNode->getNext());
            free(currNode);
        }
        // remove from value_frequency-node map.
        this->itemFrequencyNodeMap.erase(value);
    }
}

/**
 * Access Item.
 * Get item, increment the frequency.
 * If not present insert the item in the cache.
 *
 * */
bool LFU::Access(int value) {
    unordered_map<int, FrequencyNode *>::const_iterator iter = this->itemFrequencyNodeMap.find(value);
    int frequency;
    if(iter == this->itemFrequencyNodeMap.end()){
        // value not present. Insert with frequency 1.
        frequency = 1;
        if(this->frequencyFrequencyNodeMap.find(frequency) == this->frequencyFrequencyNodeMap.end()){
            // create a new frequency new.
            NewFrequencyNodeInsert(value, frequency);
        }else{
            ExistingFrequencyInsert(value, frequency);
        }
        return false;
    }else{
        FrequencyNode *currNode = iter->second;
        InsertInNextFrequency(value, currNode);
        return true;
    }
}

int main(){

    return 0;
}
