//
// Created by mohit on 12/1/17.
//

#include "ItemNodes.h"

ItemNodes::ItemNodes() {
    this->numItems = 0;
}

ItemNodes::~ItemNodes() {
    delete(this);
}

ItemNodes::ItemNodes(FrequencyNode *parent) {
    this->numItems = 0;
    this->parent = parent;
}

ItemNodes::ItemNodes(int value, FrequencyNode *parent) {
    this->numItems = 0;
    this->parent = parent;
    AddItem(value);
}

void ItemNodes::AddItem(int value) {
    this->items.push_back(value);
    this->ItemIndexMap.insert({value, this->numItems++});
}

void ItemNodes::RemoveItem(int value) {
    unordered_map<int, int>::const_iterator iter = this->ItemIndexMap.find(value);
    if(iter == this->ItemIndexMap.end()){
        // Case may never Happen.
    }else{
        // get the index of that element.
        int index = iter->second;
        // swap the value with the last value.
        int swappedValue = this->items[numItems - 1];
        swap(this->items[index], this->items[numItems - 1]);
        // update index.
        this->ItemIndexMap.insert({swappedValue, index});
        // pop back the element and update the number of items in the nodelist.
        this->items.pop_back();
        this->numItems--;
    }
}

int ItemNodes::GetItem() {
    if(this->items.empty()){
        return -1;
    }else{
        return this->items[0];
    }
}

bool ItemNodes::ItemPresent(int value) {
    return this->ItemIndexMap.find(value) == this->ItemIndexMap.end();
}

bool ItemNodes::IsEmpty() {
    return this->items.empty();
}
