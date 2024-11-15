#ifndef DF_H
#define DF_H

#include <BITS/stdc++.h>
#include "include/array.h"
using namespace std;

class DataFrame
{
private:
    vector<Array> data;     // 1D Array for each column
    vector<string> columns; // Column labels
    vector<string> index;   // Row labels

public:
    // Constructor
    DataFrame(const vector<vector<double>> &inputData, const vector<string> &colLabels, const vector<string> &rowLabels);

    // DataFrame Operations
    DataFrame head(size_t n);
    DataFrame tail(size_t n);
    pair<size_t, size_t> shape();
    vector<string> getColumns();
    vector<string> getIndex();

    // Describe statistics
    map<string, double> describe();

    // Print function
    void print() const;

    // Read CSV function
    static DataFrame read_csv(const string &filename);

    // Additional functions (median, quartiles, is.na, etc.) can be implemented similarly
};

#endif