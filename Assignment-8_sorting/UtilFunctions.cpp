// author: Aryanthepain
#include "sorting.h"

void printArr(int8_t *arr, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cout << +arr[i] << " ";
    }
    cout << endl;

    return;
}

void assignArray(int8_t *arr, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        arr[i] = rand() % (MAXIMUM + 1);
    }
}

void copy_array(int8_t *src, int8_t *dest, ll n)
{
    for (ll i = 0; i < n; ++i)
    {
        dest[i] = src[i];
    }
}