//
// Created by Александр Мангазеев on 16.03.2021.
//

// first -> f <- s <- t <- f <- last

#ifndef LABA_2_MYQUEUE_H
#define LABA_2_MYQUEUE_H

#include <iostream>

struct Node{
    int data;
    Node *next;
    Node *prev;
};

class MyQueue {
public:
    int size;
    Node *first;
    Node *last;

    MyQueue();
    ~MyQueue();
    bool isEmpty() const;
    void push(int tempData);
    int pop();
    void show();

private:
    Node *next;
    Node *prev;
};


#endif //LABA_2_MYQUEUE_H
