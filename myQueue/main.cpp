#include <iostream>
#include "MyQueue.h"

int main() {
    MyQueue Q;

    Q.push(45);
    Q.push(5);
    Q.push(15);
    Q.push(145);
    std::cout<<Q.size<<std::endl;
    std::cout<<Q.pop()<<std::endl;
    std::cout<<"+++++++++"<<std::endl;

    Q.show();
    std::cout<<Q.size<<std::endl;
//    std::cout<<Q.first->data<<std::endl;
//    std::cout<<Q.last->data<<std::endl;

    return 0;
}
