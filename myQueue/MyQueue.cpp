//
// Created by Александр Мангазеев on 22.03.2021.
//

#include "MyQueue.h"

MyQueue::MyQueue() {
    size = 0;
    first = nullptr;
    last = nullptr;
}

bool MyQueue::isEmpty() const {
    if (size)
        return false;
    return true;
}

void MyQueue::push(int tempDate) {
    MyQueue *ptr = new MyQueue;
    ptr->data = tempDate;
    ptr->prev = last;
    ptr->next = nullptr;
    if (last != nullptr){
        last->next = ptr;
    }
    last = ptr;
    if (ptr->prev == nullptr){
        first = ptr;
    }
    size++;
}

void MyQueue::show() {
    MyQueue *ptr = first;
    while (ptr != nullptr) {
        std::cout<<ptr->data<<std::endl;
        ptr = ptr->next;
    }
    if (last->next != nullptr)
        std::cout<<"Ok"<<std::endl;
}

int MyQueue::pop() {
    int temp = first->data;
    first = first->next;
    size--;
    delete first;
    return temp;
}