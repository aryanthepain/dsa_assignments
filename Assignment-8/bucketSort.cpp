// author: Aryanthepain
#include "sorting.h"

void bucket_sort(int8_t *arr, ll n)
{
    // int8_t can hold values from -128 to 127
    vector<int8_t> vectArr[25];

    // divide into buckets
    for (ll i = 0; i < n; i++)
    {
        int index = (arr[i] / 10) + 12;
        vectArr[index].push_back(arr[i]);
    }

    // sort each vector
    for (int i = 0; i < 25; i++)
    {
        sort(vectArr[i].begin(), vectArr[i].end());
    }

    // put in original vector
    for (int i = 0; i < 25; i++)
    {
        for (ll j = 0; j < vectArr[i].size(); j++)
        {
            arr[0] = vectArr[i][j];
            arr++;
        }
    }

    return;
}