// author: Aryanthepain
#ifndef ARRAY_H
#define ARRAY_H
#include <bits/stdc++.h>
using namespace std;

class Array
{
private:
    vector<double> data;

    Array elementWiseOperation(const Array &other, function<double(double, double)> op);
    Array elementWiseOperation(function<double(double)> op);

public:
    // Constructors
    Array(const vector<double> &data) : data(data) {}
    static Array zeros(size_t size);
    static Array ones(size_t size);
    static Array arange(double start, double end, double step);
    static Array linspace(double start, double end, size_t num);

    // Array Manipulation
    static Array concatenate(const Array &a, const Array &b);
    static vector<Array> split(const Array &a, size_t num);

    // Mathematical Operations
    Array add(const Array &other);
    Array subtract(const Array &other);
    Array multiply(const Array &other);
    Array divide(const Array &other);
    Array power(double exponent);
    double sum();
    double mean();
    double std();

    // Random Sampling
    static Array randomRand(size_t size);

    // Print function
    void print() const;

    // return the data
    vector<double> getData() const
    {
        return data;
    }
};

#endif