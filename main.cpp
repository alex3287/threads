#include <iostream>
#include <thread>

void create_array(int *A, int start, int finish){
    for (int i=start; i<finish; i++){
        A[i] = i*finish;
    }
//    std::cout<<std::this_thread::get_id()<<"   "<<std::endl;
    printf("Параллельная область потока %d -> %d\n", std::this_thread::get_id(), finish);
}

int main() {
    int k=0, n=0;
    std::cout<<"Enter count items in array "<<std::endl;
    std::cin>>n;
    std::cout<<"Enter count threads "<<std::endl;
    std::cin>>k;

    int *A = new int [n];
    if (k>n)
        k=n;
    std::thread *A_thread = new std::thread [k];

    int step = n / k;
    int step2 = n % k; // если n не делится нацело на k
    for (int i=0;i<k-1;i++)
        A_thread[i] = std::thread(create_array, A, i*step, (i+1)*step);

    // последний шаг будет включать + остаток от деления
    A_thread[k-1] = std::thread(create_array, A, (k-1)*step, k*step+step2);

    for (int i=0;i<k;i++)
        A_thread[i].join();

    for (int i=0; i<n; i++)
        std::cout<<A[i]<<" ";

    delete [] A;
    delete [] A_thread;

    return 0;
}
