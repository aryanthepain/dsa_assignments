// author: Aryanthepain
#include "sorting.h"

void insert_in_between(int8_t *sorted_arr, int8_t *arr, int8_t x)
{
    while (x >= sorted_arr[0])
    {
        if (sorted_arr == arr)
        {
            return;
        }
        sorted_arr++;
    }

    int8_t temp = x;

    while (sorted_arr != (arr))
    {
        swap(temp, sorted_arr[0]);
        sorted_arr++;
    }
}

void insertion_sort(int8_t *arr, ll n)
{
    int8_t *sorted_arr = arr;
    arr++; // move to next index

    for (ll i = 1; i < n; i++)
    {
        int8_t curr = arr[0];
        arr++; // move to next index
        insert_in_between(sorted_arr, arr, curr);
    }

    return;
}