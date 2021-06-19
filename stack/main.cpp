#include <iostream>
#include <stack>
#include "MyStack.h"

int main() {
    MyStack S;
    S.push({"Petr", 15});
    S.push({"Bill", 10});
    S.push({"Alex", 35});
    S.pop();
//    DATA temp = S.pop();
//    temp = S.pop();
//    std::cout<<temp.name<<" "<<temp.old<<std::endl;
    S.show();
    return 0;
}
