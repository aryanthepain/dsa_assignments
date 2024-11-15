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
    Array<T> sample(size_t sampleSize) const; // Sample from the array
    void sort();                              // Sorts the array in place
    static Array<T> randomRand(size_t size);  // Random Sampling

    // Mathematical Operations
    Array<T> add(const Array<T> &other);
    Array<T> subtract(const Array<T> &other);
    Array<T> multiply(const Array<T> &other);
    Array<T> divide(const Array<T> &other);
    Array<T> power(double exponent);
    double sum();
    double mean();
    double std();
    double var();                                    // Variance
    Array<T> cumsum();                               // Cumulative sum
    Array<T> cumprod();                              // Cumulative product
    Array<T> sin();                                  // Sine
    Array<T> cos();                                  // Cosine
    Array<T> exp();                                  // Exponential
    Array<T> log();                                  // Natural logarithm
    tuple<double, double, double> quartiles() const; // Returns Q1, Q2, Q3 Quartiles
    T max() const;                                   // Maximum value
    T min() const;                                   // Minimum value
    Array<T> slice(size_t start, size_t end);        // Slice the array
    Array<T> unique() const;                         // Unique values
    size_t count(const T &value) const;              // Count occurrences of a value

    // Print function
    void print() const;

    // Return the data
    vector<T> getData() const
    {
        return data;
    }

    // Access methods
    T loc(size_t index) const;  // Access by label (index)
    T iloc(size_t index) const; // Access by integer position
    T at(size_t index) const;   // Fast access by index
    T iat(size_t index) const;  // Fast access by integer position
};

#endif // ARRAY_H