#ifndef NOTATIONCONVERTERDEQUE_H
#define NOTATIONCONVERTERDEQUE_H

#include "NotationConverter.hpp"


NotationConverter::NotationConverter(){
    head = nullptr;
    rear = nullptr;
}
void NotationConverter::clearDeque(){
    while (!empty()){
        removeFront();
    }
}
bool NotationConverter::empty() const{ // is the deque empty?
    if (head == nullptr) return 1;
    else return 0;
}

const Elem& NotationConverter::front() const { // first element
    if (head == nullptr) throw runtime_error("empty");
    return head->ch;
}

const Elem& NotationConverter::back() const { // last element
    if (head == nullptr) throw runtime_error("empty");
    return rear->ch;
}

void NotationConverter::insertFront(string e){ // insert new first element
    nodePtr curr = new node;
    curr->ch = e;
    curr->next = head;
    curr->prev = rear;
    head = curr;
}
void NotationConverter::insertBack(string e){ // insert new last element
    nodePtr curr = new node;
    curr->ch = e;
    curr->prev = rear;
    curr->next = nullptr;
    if (rear != nullptr){
        rear->next = curr;
    }
    else{
        head = curr;
    }
    rear = curr;
}
void NotationConverter::removeFront(){ // remove first element
    if (head == nullptr) throw runtime_error("empty");
    nodePtr temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) rear = nullptr;
}
    
    

void NotationConverter::removeBack(){  // remove last element
    if (rear == nullptr) throw runtime_error("empty");
    nodePtr temp = rear;
    rear = rear->prev;
    delete temp;
    rear->next = nullptr;
    if (rear == nullptr) head = nullptr;
}

#endif /* NOTATIONCONVERTERDEQUE_H */