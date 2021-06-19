// Реализовать потоко-безопасную очередь, с возможностью добавления
// и изъятия элементов несколькими потоками (формат элемента очереди произвольный)

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include "MyQueue.h"

void addItem(int item);
void delItem();
void showItems();

std::queue<int> A;
std::mutex test_mutex;
//MyQueue Q2;

int main() {
//    тесты моей очереди
//    MyQueue Q;
//
//    Q.push(415);
//    Q.push(57);
//    Q.push(15);
//    Q.push(1);
//    Q.push(11);
//    std::cout<<Q.size<<std::endl;
//    std::cout<<Q.pop()<<std::endl;
//    std::cout<<"+++++++++"<<std::endl;
//
//    Q.show();
//    std::cout<<Q.size<<std::endl;
//    std::cout<<Q.first->data<<std::endl;
//    std::cout<<Q.last->data<<std::endl;

//    ПРОГРАММА С ПОТОКАМИ

    srand(time(0));
    int add_threads = rand()%100;
    int del_threads = rand()%100;
    std::cout<<"add_threads: "<< add_threads<<std::endl;
    std::cout<<"del_threads: "<< del_threads<<std::endl;

    // add Items
    std::thread *A_thread = new std::thread [add_threads];
    for (int i=0; i < add_threads; i++){
        srand(time(0)+i);
        A_thread[i] = std::thread(addItem, rand() % 100);
    }


    // delete Items
    std::thread *A2_thread = new std::thread [del_threads];
    for (int i=0; i < del_threads; i++){
        srand(time(0)+i);
        A2_thread[i] = std::thread(delItem);
    }



    for (int i=0; i < add_threads; i++)
        A_thread[i].join();

    for (int i=0; i < del_threads; i++)
        A2_thread[i].join();

    std::cout<<"Size MyQueue: "<<A.size()<<std::endl;


    showItems();

    return 0;
}


void addItem(int item) {
    std::lock_guard<std::mutex> guard(test_mutex);
    A.push(item);
}

void delItem(){
    std::lock_guard<std::mutex> guard(test_mutex);
    if (A.empty() == false) {
        A.pop();
    } else {
        std::cout<<"Sorry, MyQueue is EMPTY"<<std::endl;
    }

}

void showItems(){
    std::lock_guard<std::mutex> guard(test_mutex);
    while (A.empty() == false){
        std::cout<<A.front()<<std::endl;
        A.pop();
    }

}