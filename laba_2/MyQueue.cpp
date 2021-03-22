//
// Created by Александр Мангазеев on 16.03.2021.
//

#include "queue.h"

Queue::Queue() {
    size = 0;
    first = nullptr;
    last = nullptr;
}

Queue::~Queue() {
//    for (int i=0; i<size; i++){ fixme
//
//    }
//    for(auto it=item;it;it = it->next)...
}

bool Queue::isEmpty() {
    if (size)
        return false;
    return true;
}

void Queue::push(int tempDate) {
    size++;
    if (size == 1){
        first = new node;
        first->data = tempDate;
        last = first;
    } else {
        node *tmp = new node;
        tmp->next = last;
        last->next = tmp;
//        last->next = tmp;
//        last = tmp;  TODO тут возник спор
    }
}
//ctrl+shift+d почему не используешь

// TODO опасность
int Queue::pop() {
    int tmp = first->data;
    size--;

    return tmp;
}


