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
using namespace std;

class DataFrame
{
private:
    vector<vector<double>> data; // Assuming numeric data
    vector<string> columns;
    vector<string> index;

public:
    DataFrame(const vector<vector<double>> &inputData,
              const vector<string> &colLabels,
              const vector<string> &rowLabels);

    DataFrame(const string &filename); // Constructor to load from CSV

    void head(size_t n);
    void tail(size_t n);
    pair<size_t, size_t> shape();
    vector<string> getColumns();
    vector<string> getIndex();
    void describe();
    double sum(size_t columnIndex);
    double mean(size_t columnIndex);
    double median(size_t columnIndex);
    void filter(const string &columnName, double threshold);
    void print();
};

#endif // DATAFRAME_H