//
// Created by Александр Мангазеев on 16.03.2021.
//

// first -> f <- s <- t <- f <- last

#ifndef LABA_2_QUEUE_H
#define LABA_2_QUEUE_H

struct node{
    int data;
    node *next;
};

class Queue {
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void push(int tempData);
    int pop();

private:
    int size;
    node *first;
    node *last;
};


#endif //LABA_2_QUEUE_H
