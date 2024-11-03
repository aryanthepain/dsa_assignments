// author:Aryanthepain
#include <bits/stdc++.h>
#define MAX 20
#define random_number rand() % MAX
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
        cout << endl;
    }
    return;
}

int main()
{
    cout << "To multiply two randomnly generated matrices(we will be taking max number to be " << MAX << " for not having too high numbers)" << endl;

    int m = random_number + 1;
    int n = random_number + 1;
    int p = random_number + 1;

    // defining arrays
    int a_matrix[m][n];
    int b_matrix[n][p];
    int product[m][p];

    // generate first matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a_matrix[i][j] = random_number;
        }
    }

    // generate second matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            b_matrix[i][j] = random_number;
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
                temp += a_matrix[i][k] * b_matrix[k][j];
            }
            product[i][j] = temp;
        }
    }

    // printing matrices
    cout << "\nFirst matrix:(" << m << "*" << n << ")"
         << endl;
    print_array(m, n, (int *)a_matrix);
    cout << "\nSecond matrix:(" << n << "*" << p << ")"
         << endl;
    print_array(n, p, (int *)b_matrix);
    cout << "\nProduct matrix:(" << m << "*" << p << ")" << endl;
    print_array(m, p, (int *)product);

    return 0;
}