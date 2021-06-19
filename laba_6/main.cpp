// Реализовать скалярное произведение векторов (Reduction)

#include <iostream>
#include "omp.h"

const int size = 5;

void randomNumbers(int (&A)[size], int rN) {
    for (int i=0; i < size; i++){
        srand(time(0)+i+rN);
        A[i] = rand() % 100;
    }
}

int scolMultVectors(int (&A)[size], int(&B)[size]){
    int result = 0;
    for (int i=0; i<size; i++){
        result += (A[i]*B[i]);
    }
    return result;
}

int main() {

    int A[size];
    int B[size];
    int rN=0;
    randomNumbers(A, rN);
    rN++;
    randomNumbers(B, rN);
    int  result = 0, max = size;

#pragma omp parallel for reduction(+:result)
        for (int j=0; j<max; j++){
            result += (A[j]*B[j]);
        }

    std::cout<<result<<std::endl;
    for (auto item: A)
        std::cout<<item<<" ";
    std::cout<<" "<<std::endl;
    for (auto item: B)
        std::cout<<item<<" ";
//    std::cout<<"\n"<<result<<std::endl;
    std::cout<<"\n"<<scolMultVectors(A, B);
    return 0;

}
