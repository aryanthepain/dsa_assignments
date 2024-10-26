// author: Aryanthepain
#include "sorting.h"

void bucket_sort(int8_t *arr, ll n)
{
    // the array is assigned values 0 to 127
    vector<int8_t> vectArr[13];

    // divide into buckets
    for (ll i = 0; i < n; i++)
    {
        int index = (arr[i] / 10);
        vectArr[index].push_back(arr[i]);
    }

    // sort each vector
    for (int i = 0; i < 13; i++)
    {
        sort(vectArr[i].begin(), vectArr[i].end());
    }

    // put in original vector
    for (int i = 0; i < 13; i++)
    {
        for (ll j = 0; j < vectArr[i].size(); j++)
        {
            arr[0] = vectArr[i][j];
            arr++;
        }
    }

    return;
}