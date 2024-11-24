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

    // Helper functions
    Array<T> elementWiseOperation(const Array<T> &other, std::function<T(T, T)> op) const;
    Array<T> elementWiseOperation(std::function<T(T)> op) const;

public:
    // Constructors
    Array() : data() {} // Initializes an empty vector
    Array(const vector<T> &data) : data(data) {}
    static Array<T> zeros(size_t size);
    static Array<T> ones(size_t size);
    static Array<T> arange(double start, double end, double step);
    static Array<T> linspace(double start, double end, size_t num);

    // Access methods
    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    void print() const;        // Print function
    vector<T> getData() const; // Return the data
    size_t search(const T &value) const;
    size_t size() const; // Return the size of the array

    // Array Manipulation
    static Array<T> concatenate(const Array<T> &a, const Array<T> &b); // concatenate two arrays
    static vector<Array<T>> split(const Array<T> &a, size_t num);      // split into multiple arrays
    static Array<T> randomRand(size_t size);                           // Random Sampling
    void sort();                                                       // Sorts the array in place
    Array<T> sample(size_t sampleSize) const;                          // Sample from the array
    Array<T> slice(size_t start, size_t end);                          // Slice the array
    Array<T> unique() const;                                           // Unique values
    size_t count(const T &value) const;                                // Count occurrences of a value

    // Mathematical Operations for double
    Array<double> add(const Array<double> &other) const;
    Array<double> subtract(const Array<double> &other) const;
    Array<double> multiply(const Array<double> &other) const;
    Array<double> divide(const Array<double> &other) const;
    Array<double> power(double exponent) const;
    double sum() const;
    double mean() const;
    double std() const;
    double var() const;                                   // Variance
    Array<double> cumsum() const;                         // Cumulative sum
    Array<double> cumprod() const;                        // Cumulative product
    Array<double> sin() const;                            // Sine
    Array<double> cos() const;                            // Cosine
    Array<double> exp() const;                            // Exponential
    Array<double> log() const;                            // Natural logarithm
    std::tuple<double, double, double> quartiles() const; // Returns Q1, Q2, Q3 Quartiles
    double max() const;                                   // Maximum value
    double min() const;                                   // Minimum value
};

#endif // ARRAY_H