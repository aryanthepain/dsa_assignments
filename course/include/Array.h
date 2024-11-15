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

    Array<T> elementWiseOperation(const Array<T> &other, function<T(T, T)> op);
    Array<T> elementWiseOperation(function<T(T)> op);

public:
    // Constructors
    Array(const vector<T> &data) : data(data) {}
    static Array<T> zeros(size_t size);
    static Array<T> ones(size_t size);
    static Array<T> arange(double start, double end, double step);
    static Array<T> linspace(double start, double end, size_t num);

    // Access methods
    T loc(size_t index) const; // Access by index

    // Array Manipulation
    static Array<T> concatenate(const Array<T> &a, const Array<T> &b); // concatenate two arrays
    static vector<Array<T>> split(const Array<T> &a, size_t num);      // split into multiple arrays
    static Array<T> randomRand(size_t size);                           // Random Sampling
    void sort();                                                       // Sorts the array in place
    Array<T> sample(size_t sampleSize) const;                          // Sample from the array

    // Print function
    void print() const;

    // Return the data
    vector<T> getData() const;
};

#endif // ARRAY_H