//
// Created by Александр Мангазеев on 22.03.2021.
//

#include "MyStack.h"

MyStack::MyStack() {
    top = nullptr;
}

bool MyStack::empty() {
    if (top == nullptr)
        return true;
    return false;
}

void MyStack::push(DATA newData) {
    MyStack *ptr = new MyStack;
    ptr->d = newData;
    ptr->next = top;
    top = ptr;
}

void MyStack::show() {
    MyStack *ptr = top;
    while (ptr != nullptr){
        std::cout<<ptr->d.name<<" "<<ptr->d.old<<std::endl;
        ptr = ptr->next;
    }
}

DATA MyStack::pop() {
    MyStack *ptr;
    ptr = top->next;
    DATA temp;
    temp.name = top->d.name;
    temp.old = top->d.old;
    delete top;
    top = ptr;
    return temp;
}
