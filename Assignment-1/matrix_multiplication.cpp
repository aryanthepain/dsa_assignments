// author:Aryanthepain
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print_array(int x, int y, int *arr)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << *(arr + i * y + j) << " ";
        }
        cout << "" << endl;
    }
    return;
}

int main()
{
    int max = 20; // maximum value the random values can take
    cout << "To multiply two randomnly generated matrices(we will be taking max number to be " << max << " for not having too high numbers)" << endl;

    int m = rand() % max + 1;
    int n = rand() % max + 1;
    int p = rand() % max + 1;

    // defining arrays
    int first[m][n];
    int second[n][p];
    int product[m][p];

    // generate first matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            first[i][j] = rand() % max;
        }
    }

    // generate second matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            second[i][j] = rand() % max;
        }
    }

    // generate product
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            int temp = 0;
            for (int k = 0; k < n; k++)
            {
                temp += first[i][k] * second[k][j];
            }
            product[i][j] = temp;
        }
    }

    // printing matrices
    cout << "\nFirst matrix:(" << m << "*" << n << ")"
         << endl;
    print_array(m, n, (int *)first);
    cout << "\nSecond matrix:(" << n << "*" << p << ")"
         << endl;
    print_array(n, p, (int *)second);
    cout << "\nProduct matrix:(" << m << "*" << p << ")" << endl;
    print_array(m, p, (int *)product);

    return 0;
}