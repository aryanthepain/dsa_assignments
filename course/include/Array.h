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

    // Access methods
    T loc(size_t index) const; // Access by index

    // Print function
    void print() const;

    // Return the data
    vector<T> getData() const;
};

#endif // ARRAY_H