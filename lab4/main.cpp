#include <iostream>
#include <ctime>
#include <chrono>
#include "Algorithms.cpp"

using namespace std;

void randInsert(int arr[], long n) {
    srand(time(nullptr));
    for (long i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

int main() {
    const int COUNT = 100000;
    cout << "Time for " << COUNT << ":" << endl;
    int a[COUNT];

    long long sum = 0;

    for(int i = 0; i < 10; i++){
        randInsert(a, COUNT);
        auto begin = std::chrono::steady_clock::now();
        //insertionSort(a, COUNT);
        quickSort(a, 0, COUNT - 1);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        cout << elapsed_ms.count() << " ";
        sum+=elapsed_ms.count();
    }

    cout << "Average time: " << sum / 10;
    return 0;
}
