// author: Aryanthepain
#ifndef ARRAY_H
#define ARRAY_H
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Array
{
private:
    vector<T> data;

public:
    // Constructors
    Array(const vector<T> &data) : data(data) {}
    static Array<T> zeros(size_t size);
    static Array<T> ones(size_t size);
    static Array<T> arange(double start, double end, double step);
    static Array<T> linspace(double start, double end, size_t num);

    // Print function
    void print() const;
};

// print functions
template <typename T>
void Array<T>::print() const
{
    for (const T &val : data)
    {
        cout << val << " ";
    }
    cout << endl;
}

#endif // ARRAY_H