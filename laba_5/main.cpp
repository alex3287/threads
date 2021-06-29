#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <chrono>

void complete_array(std::vector<double> &A){
    std::default_random_engine rnd(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    for (auto &item:A){
        item = rnd() % 100 + (rnd() % 100 / 100.0);
    }
}

void print(std::vector<double> &A){
    for (auto item:A){
        std::cout<<item<<" ";
    }
    std::cout<<"\n";
}

int partition (double *arr, int low, int high)
{
    double pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(double *arr, int low, int high, int count_thread)
{

    if (count_thread > 1){
        if (low < high)
        {
            int pi = partition(arr, low, high);
            std::thread T1(quickSort, arr, low, pi - 1, count_thread-2);
            std::thread T2(quickSort, arr, pi + 1, high, count_thread-2);
            T1.join();
            T2.join();
        }
    }
    else if (count_thread > 0){
        if (low < high)
        {
            int pi = partition(arr, low, high);
            std::thread T1(quickSort, arr, low, pi - 1, count_thread-1);
            quickSort(arr, pi + 1, high, 0);
            T1.join();

        }
    } else {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(arr, low, high);

            // Separately sort elements before
            // partition and after partition
            quickSort(arr, low, pi - 1, 0);
            quickSort(arr, pi + 1, high, 0);
        }
    }
}

int main() {
    int size = 10;
    std::vector<double> A(size);
    int count_thread = 26;  //fixme enter any thread
    complete_array(A);
    print(A);
    std::cout<<"\n";
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(A.data(),0, A.size()-1, count_thread);
    auto finish = std::chrono::high_resolution_clock::now();
    print(A);
    std::cout<<std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count()<<std::endl;
    return 0;
}
