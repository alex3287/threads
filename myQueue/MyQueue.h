//
// Created by Александр Мангазеев on 22.03.2021.
//

#ifndef MYQUEUE_MYQUEUE_H
#define MYQUEUE_MYQUEUE_H


#include <iostream>

class MyQueue {
public:
    int data;
    int size;
    MyQueue *first;
    MyQueue *last;

    MyQueue();
    bool isEmpty() const;
    void push(int tempData);
    int pop();
    void show();

private:
    MyQueue *next;
    MyQueue *prev;
};


#endif //MYQUEUE_MYQUEUE_H
