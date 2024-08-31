// author: Aryanthepain
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    cout << "To find the third largest number in an array" << endl;
    cout << "============================================" << endl;
    cout << "Enter the size of the array" << endl;

    int n;
    cin >> n;
    if (n < 3)
    {
        cout << "Array needs to be larger than 2" << endl;
        return 0;
    }

    int arr[n];

    cout << "Enter the elements of array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int first = arr[0];
    int second = arr[0];
    int third = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] >= second)
        {
            third = second;
            second = arr[i];
        }
        else if (arr[i] >= third)
        {
            third = arr[i];
        }
    }

    cout << "Third Largest number- " << third << endl;

    return 0;
}