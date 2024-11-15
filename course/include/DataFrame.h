#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <thread>
#include <mutex>
#include <type_traits>
#include <numeric> // For std::accumulate

using namespace std;

template <typename T>
class DataFrame
{
private:
    vector<vector<T>> data; // Generic data type
    vector<string> columns;
    vector<string> index;

public:
    DataFrame(const vector<vector<T>> &inputData,
              const vector<string> &colLabels,
              const vector<string> &rowLabels);

    DataFrame(const string &filename); // Constructor to load from CSV

    void head(size_t n);
    void tail(size_t n);
    pair<size_t, size_t> shape();
    vector<string> getColumns();
    vector<string> getIndex();
    void describe();
    T sum(size_t columnIndex);
    double mean(size_t columnIndex);
    double median(size_t columnIndex);
    void filter(const string &columnName, T threshold);
    void print();
};

#endif // DATAFRAME_H