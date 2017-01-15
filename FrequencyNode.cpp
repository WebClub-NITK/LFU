//
// Created by mohit on 12/1/17.
//

#include "FrequencyNode.h"

FrequencyNode::FrequencyNode() {
    this->frequency = 0;
    this->prev = this->next = nullptr;
    this->itemNodes = new ItemNodes(this);
}

FrequencyNode::~FrequencyNode() {
    delete(this);
}

FrequencyNode::FrequencyNode(int frequency) {
    this->frequency = frequency;
    this->prev = nullptr;
    this->next = nullptr;
    this->itemNodes = new ItemNodes(this);
}

FrequencyNode::FrequencyNode(int frequency, FrequencyNode *prev, FrequencyNode *next) {
    this->frequency = frequency;
    this->prev = prev;
    this->next = next;
    this->itemNodes = new ItemNodes(this);
}

void FrequencyNode::AddItem(int value) {
    this->itemNodes->AddItem(value);
}

int FrequencyNode::AccessItem(int value) {
    return this->itemNodes->GetItem();
}

void FrequencyNode::DeleteItem(int value) {
    this->itemNodes->RemoveItem(value);
    return;
}

bool FrequencyNode::Find(int value) {
    return this->itemNodes->ItemPresent(value);
}

void FrequencyNode::setPrev(FrequencyNode *prev) {
    this->prev = prev;
}

void FrequencyNode::setnext(FrequencyNode *next) {
    this->next = next;
}

FrequencyNode *FrequencyNode::getNext() {
    return this->next;
}

FrequencyNode *FrequencyNode::getPrev() {
    return this->prev;
}

int FrequencyNode::getFrequency() {
    return this->frequency;
}
