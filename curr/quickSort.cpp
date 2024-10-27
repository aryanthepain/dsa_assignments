// author: Aryanthepain
#include "sorting.h"

ll divide(int8_t *arr, ll l, ll r)
{
    ll pivot = arr[r]; // last element as pivot
    ll i = l - 1;      // pointer to smaller element

    for (ll j = l; j < r; j++)
    {
        // arr[j] = current element
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]); // move last element to end of the smaller element array

    return (i + 1);
}

void quick_sort(int8_t *arr, ll r, ll l)
{
    // this is done so that we can just call sort(arr,n)
    r--;
    if (l >= r)
        return;

    ll m = divide(arr, l, r);

    // the below lines of code are quirky due to the first line of the function
    quick_sort(arr, m, l);
    quick_sort(arr, r + 1, m + 1);

    return;
}