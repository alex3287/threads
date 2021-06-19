// Реализовать параллельный алгоритм перемножения матриц.
// Сравнить время при различном числе потоков (for)

#include <iostream>
#include <vector>
#include "omp.h"


using namespace std;
vector<vector<int>> matrix_multiplication2(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int sz = A.size();
    vector<vector<int>> C(sz, vector<int>(sz));

    for (int i = 0; i < sz; i++)
        for (int j = 0; j < sz; j++)
            for (int k = 0; k < sz; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

vector<vector<int>> createMatrix(int N, int rn)
{
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
//            srand(time(0)+i+j+rn);
            A[i][j] += rand() % 10;
        }

    return A;
}

void printMatrix(vector<vector<int>> &A)
{
    int N = A.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout<<A[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

int main() {
    using namespace std::chrono;
    srand(time(0));
    int size = 2;
    int rn = 1;
    vector<vector<int>> A = createMatrix(size, rn);
    rn += 1;
    vector<vector<int>> B = createMatrix(size, rn);
    vector<vector<int>> C1 = matrix_multiplication2(A,B);

//    printMatrix(A);
//    printMatrix(B);
//    printMatrix(C1);

//    пробую с потоками
    int N = A.size();
    vector<vector<int>> C2(N, vector<int>(N));

    auto start = high_resolution_clock::now(); // начало времени
#pragma omp parallel for
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C2[i][j] += A[i][k] * B[k][j];
        int num = omp_get_thread_num();
        printf("Параллельная область, поток %d\n", num);
    }
    auto end = high_resolution_clock::now(); // завершение
    auto elepsed = end - start;


//    printMatrix(C2);
    std::cout<<duration_cast<milliseconds>(elepsed).count()<<std::endl;
    return 0;
}
