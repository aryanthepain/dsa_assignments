// author: Aryanthepain
#include "sorting.h"

int main()
{
    ll n = 100000;
    int8_t *arr = new int8_t[n];
    // printArr(arr, n);
    cout << "hello" << endl;

    insertion_sort(arr, n);
    // printArr(arr, n);

    delete[] arr;
}