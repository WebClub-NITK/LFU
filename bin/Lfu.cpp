//
// Created by mohit on 20/2/17.
//

#include "../header/Lfu.h"

Lfu::Lfu() {
    this->head = new FrequencyList(0, NULL, NULL);
    this->CountFrequencyListMap[0] = this->head;
}

Lfu::~Lfu() {
    delete(this->head);
    this->NodeFrequencyListMap.clear();
    this->CountFrequencyListMap.clear();
}

void Lfu::Set(int value) {
    // add the item in the cache.
    // Check if the item is already present. If yes increment the count and put it in the next frequency node.
    struct Node node = CreateNode(value);
    if(NodePresent(node)){
        unordered_map::const_iterator iter1 = this->NodeFrequencyListMap.find(node);
        FrequencyList *frequencyList = iter1->first;
        int freq = frequencyList->GetCount();
        // remove the node from current frequency node.
        frequencyList->DeleteNode(node);

        /**
         * Remove the frequency node if the frequency node is empty.
         * */

        // Increment the frequency
        freq = freq + 1;
        // check if the node is present.
        if(FrequencyNodePresent(freq)){
            FrequencyList *frequencyList1 = this->CountFrequencyListMap.find(freq)->second;
            frequencyList1->AddNode(node);
            this->NodeFrequencyListMap[node] = frequencyList1;
        }else{
            FrequencyList *newFrequencyNode = new FrequencyList(freq);
            newFrequencyNode->SetPrevious(frequencyList);
            newFrequencyNode->SetNext(frequencyList->GetNext());
            newFrequencyNode->AddNode(node);
            this->NodeFrequencyListMap[node] = newFrequencyNode;
        }
    }else{
        // else put it the first node.
        int freq = 1;
        if(FrequencyNodePresent(freq)){
            FrequencyList *frequencyList1 = this->CountFrequencyListMap.find(freq)->second;
            frequencyList1->AddNode(node);
            this->NodeFrequencyListMap[node] = frequencyList1;
        }else{
            FrequencyList *newFrequencyNode = new FrequencyList(freq);
            newFrequencyNode->SetPrevious(this->head);
            newFrequencyNode->SetNext(this->head->GetNext());
            newFrequencyNode->AddNode(node);
            this->NodeFrequencyListMap[node] = newFrequencyNode;
        }
    }

}

void Lfu::Retrieve(int value) {

}

void Lfu::Evict(int value) {
    
}

struct Node Lfu::CreateNode(int value) {
    struct Node newNode;
    newNode.ItemName = value;
    return newNode;
}

bool Lfu::NodePresent(Node node) {
    unordered_map::const_iterator iter1 = this->NodeFrequencyListMap.find(node);
    return !(iter1 == this->NodeFrequencyListMap.end());
}

bool Lfu::FrequencyNodePresent(int count) {
    unordered_map::const_iterator iter1 = this->CountFrequencyListMap.find(count);
    return !(iter1 == this->CountFrequencyListMap.end());
}

