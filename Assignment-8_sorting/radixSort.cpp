// author: Aryanthepain
#include "sorting.h"

void radix_sort(int8_t *arr, ll n)
{
    int radix = 1;
    for (int iteration = 0; iteration < 3; iteration++)
    {
        vector<int8_t> vectArr[10];

        // divide into buckets
        for (ll i = 0; i < n; i++)
        {
            int index = ((arr[i] / radix) % 10);
            vectArr[index].push_back(arr[i]);
        }
        radix *= 10;

        // put in original vector
        ll pos = 0;
        for (int i = 0; i < 10; i++)
        {
            for (ll j = 0; j < vectArr[i].size(); j++)
            {
                arr[pos] = vectArr[i][j];
                pos++;
            }
        }
    }

    return;
}