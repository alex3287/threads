// Реализовать потоко-безопасную очередь, с возможностью добавления
// и изъятия элементов несколькими потоками (формат элемента очереди произвольный)

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>

void addItem(int item);
void delItem();
void showItems();

std::queue<int> A;
std::mutex test_mutex;

int main() {

    srand(time(0));
    int add_threads = rand()%1000;
    int del_threads = rand()%1000;
    std::cout<<"add_threads: "<< add_threads<<std::endl;
    std::cout<<"del_threads: "<< del_threads<<std::endl;

    // add Items
    std::thread *A_thread = new std::thread [add_threads];
    for (int i=0; i < add_threads; i++){
        srand(time(0)+i);
        A_thread[i] = std::thread(addItem, rand() % 100);
    }
    for (int i=0; i < add_threads; i++)
        A_thread[i].join();

    // delete Items
    std::thread *A2_thread = new std::thread [del_threads];
    for (int i=0; i < del_threads; i++){
        srand(time(0)+i);
        A2_thread[i] = std::thread(delItem);
    }
    for (int i=0; i < del_threads; i++)
        A2_thread[i].join();


    std::cout<<"Size Queue: "<<A.size()<<std::endl;
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
//        std::cout<<A.front()<<std::endl;
        A.pop();
    } else {
        std::cout<<"Sorry, Queue is EMPTY"<<std::endl;
    }
}

void showItems(){
    std::lock_guard<std::mutex> guard(test_mutex);
    while (A.empty() == false){
        std::cout<<A.front()<<std::endl;
        A.pop();
    }
}