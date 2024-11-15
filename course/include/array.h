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

    // Array Manipulation
    static Array<T> concatenate(const Array<T> &a, const Array<T> &b);
    static vector<Array<T>> split(const Array<T> &a, size_t num);

    // Mathematical Operations
    Array<T> add(const Array<T> &other);
    Array<T> subtract(const Array<T> &other);
    Array<T> multiply(const Array<T> &other);
    Array<T> divide(const Array<T> &other);
    Array<T> power(double exponent);
    double sum();
    double mean();
    double std();
    double var();       // Variance
    Array<T> cumsum();  // Cumulative sum
    Array<T> cumprod(); // Cumulative product
    Array<T> sin();     // Sine
    Array<T> cos();     // Cosine
    Array<T> exp();     // Exponential
    Array<T> log();     // Natural logarithm

    // Random Sampling
    static Array<T> randomRand(size_t size);

    // Print function
    void print() const;

    // Return the data
    vector<T> getData() const
    {
        return data;
    }
};

#endif // ARRAY_H