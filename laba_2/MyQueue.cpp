//
// Created by Александр Мангазеев on 16.03.2021.
//

#include "MyQueue.h"

MyQueue::MyQueue() {
    size = 0;
    first = nullptr;
    last = nullptr;
}

MyQueue::~MyQueue() {
//    for (int i=0; i<size; i++){ fixme
//
//    }
//    for(auto it=item;it;it = it->next)...
}

bool MyQueue::isEmpty() const {
    if (size)
        return false;
    return true;
}

void MyQueue::push(int tempDate) {
    Node *ptr = new Node;
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

 /**   size++;
    if (size == 1){
        first = new Node;
        first->data = tempDate;
        last = first;
    } else {
        Node *tmp = new Node;
        tmp->next = last;
        last->next = tmp; **/
//        last->next = tmp;
//        last = tmp;  TODO тут возник спор

}

void MyQueue::show() {
    Node *ptr = first;
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
//ctrl+shift+d почему не используешь

// TODO опасность
//int MyQueue::pop() {
//    int tmp = first->data;
//    size--;
//
//    return tmp;
//}


