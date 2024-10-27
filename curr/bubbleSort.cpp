// author: Aryanthepain
#include "sorting.h"

void bubble_sort(int8_t *arr, ll n)
{
    bool sorted = false;

    while (!sorted)
    {
        sorted = true;

        for (ll i = 0; i < n; i++)
        {
            if (arr[i] > arr[i + 1])

                sorted = false;
            swap(arr[i], arr[i + 1]);
        }
    }

    return;
}
