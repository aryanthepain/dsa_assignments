// author: Aryanthepain
#include "sorting.h"

int main()
{
    ll n = 10000;
    int8_t *arr = new int8_t[n];
    printArr(arr, n);
    cout << "hello" << endl;

    bucket_sort(arr, n);
    printArr(arr, n);

    delete[] arr;
}