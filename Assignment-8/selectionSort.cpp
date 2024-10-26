// author: Aryanthepain
#include "sorting.h"

ll find_min_index(int8_t *arr, ll start, ll size)
{
    ll min = start;

    for (ll i = start; i < size; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }

    return min;
}

int8_t *selection_sort(int8_t *arr, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        ll min_index = find_min_index(arr, i, n);
        swap(arr[i], arr[min_index]);
    }

    return arr;
}