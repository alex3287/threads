//
// Created by Александр Мангазеев on 22.03.2021.
//

#ifndef STACK_MYSTACK_H
#define STACK_MYSTACK_H

#include <iostream>
#include <string>

typedef struct {
    std::string name;
    short old;
} DATA;

class MyStack {
public:
    DATA d;
    int size;
    MyStack();
    void push(DATA newData);
    DATA pop();
    bool empty();
    void show();
private:
    MyStack *next;
    MyStack *top;
};



#endif //STACK_MYSTACK_H
