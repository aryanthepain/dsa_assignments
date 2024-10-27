#include "sorting.h"
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

// Function to measure sorting times and output to CSV
void measureAndCompareSorts(ll sizes[], int numSizes)
{
    ofstream file("sort_times.csv");
    file << "Size,Insertion,Bubble,Selection,Quick,Merge,Radix,Bucket,STL\n";
    file.flush();

    for (int i = 0; i < numSizes; ++i)
    {
        ll n = sizes[i];
        int8_t *arr = new int8_t[n];
        int8_t *copy = new int8_t[n];

        file << n << ",";
        file.flush();
        // Measure Insertion Sort
        assignArray(arr, n);
        // printArr(arr, n);
        memcpy(copy, arr, n * sizeof(int8_t)); // Ensure a fresh copy
        auto start = high_resolution_clock::now();
        insertion_sort(copy, n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        file << duration << ",";
        file.flush();

        // Measure Bubble Sort
        assignArray(arr, n);
        // printArr(arr, n);
        memcpy(copy, arr, n * sizeof(int8_t));
        start = high_resolution_clock::now();
        bubble_sort(copy, n);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start).count();
        file << duration << ",";
        file.flush();

        // Measure Selection Sort
        assignArray(arr, n);
        // printArr(arr, n);
        memcpy(copy, arr, n * sizeof(int8_t));
        start = high_resolution_clock::now();
        selection_sort(copy, n);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start).count();
        file << duration << ",";
        file.flush();

        // Measure Quick Sort
        assignArray(arr, n);
        // printArr(arr, n);
        memcpy(copy, arr, n * sizeof(int8_t));
        start = high_resolution_clock::now();
        quick_sort(copy, n);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start).count();
        file << duration << ",";
        file.flush();

        // Measure Merge Sort
        assignArray(arr, n);
        // printArr(arr, n);
        memcpy(copy, arr, n * sizeof(int8_t));
        start = high_resolution_clock::now();
        merge_sort(copy, n);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start).count();
        file << duration << ",";
        file.flush();

        // Measure Radix Sort
        assignArray(arr, n);
        // printArr(arr, n);
        memcpy(copy, arr, n * sizeof(int8_t));
        start = high_resolution_clock::now();
        radix_sort(copy, n);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start).count();
        file << duration << ",";
        file.flush();

        // Measure Bucket Sort
        assignArray(arr, n);
        // printArr(arr, n);
        memcpy(copy, arr, n * sizeof(int8_t));
        start = high_resolution_clock::now();
        bucket_sort(copy, n);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start).count();
        file << duration << ",";
        file.flush();

        // Measure STL Sort
        assignArray(arr, n);
        // printArr(arr, n);
        memcpy(copy, arr, n * sizeof(int8_t));
        start = high_resolution_clock::now();
        sort(copy, copy + n);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start).count();
        file << duration << "\n";
        file.flush();

        // Clean up
        delete[] arr;
        delete[] copy;
    }

    file.close();
}

int main()
{
    cout << "hello" << endl;
    // ll sizes[] = {10, 100, 1000, 10000, 100000};
    ll sizes[] = {10, 1000, 1000000, 1000000000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    measureAndCompareSorts(sizes, numSizes);
    return 0;
}
