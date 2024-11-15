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

class DataFrame
{
private:
    std::vector<std::vector<double>> data; // Assuming numeric data
    std::vector<std::string> columns;
    std::vector<std::string> index;

public:
    DataFrame(const std::vector<std::vector<double>> &inputData,
              const std::vector<std::string> &colLabels,
              const std::vector<std::string> &rowLabels);

    DataFrame(const std::string &filename); // Constructor to load from CSV

    void head(size_t n);
    void tail(size_t n);
    std::pair<size_t, size_t> shape();
    std::vector<std::string> getColumns();
    std::vector<std::string> getIndex();
    void describe();
    double sum(size_t columnIndex);
    double mean(size_t columnIndex);
    double median(size_t columnIndex);
    void filter(const std::string &columnName, double threshold);
    void print();
};

#endif // DATAFRAME_H