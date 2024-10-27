// author: Aryanthepain
#include "sorting.h"

void merge(int8_t *arr, ll l, ll m, ll r)
{
    // finding size of the divided arrays
    ll n1 = m - l + 1;
    ll n2 = r - m;

    // define new arrays
    int8_t *left = new int8_t[n1];
    int8_t *right = new int8_t[n2];

    // copy data into new arrays
    for (ll i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for (ll i = 0; i < n2; i++)
    {
        right[i] = arr[m + 1 + i];
    }

    // merging the two arrays with smaller element added first
    // using one pointer each for each array
    ll i = 0; // for left
    ll j = 0; // for right
    ll k = l; // for main array

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy remaining elements
    while (i < n1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }

    // deallocating the array
    delete[] left;
    delete[] right;

    return;
}

void merge_sort(int8_t *arr, ll r, ll l)
{
    // this is done so that we can just call sort(arr,n)
    r--;
    if (l >= r)
        return;

    ll m = l + (r - l) / 2;

    // the below lines of code are quirky due to the first line of the function
    merge_sort(arr, m + 1, l);
    merge_sort(arr, r + 1, m + 1);
    merge(arr, l, m, r);

    return;
}