#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <bits/stdc++.h>
#include "include/Array.h"
using namespace std;

// Define a variant type for the DataFrame columns
using ColumnType = variant<Array<double>, Array<string>>;

class DataFrame
{
private:
    vector<ColumnType> columns; // Each column can be either Array<double> or Array<string>
    vector<string> columnNames; // Column names
    vector<string> indexLabels; // Row index labels

public:
    // Constructors
    DataFrame(const vector<vector<variant<double, string>>> &inputData,
              const vector<string> &colNames,
              const vector<string> &rowLabels);

    DataFrame(const string &csvFilePath);

    // Method to print the DataFrame
    void print() const;

    // Head and Tail methods
    void head(size_t n) const;
    void tail(size_t n) const;

    // Shape method
    pair<size_t, size_t> shape() const;

    // Getters for columns and index
    vector<string> getColumns() const;
    vector<string> getIndex() const;

    // Describe method
    void describe() const;

    // Statistical methods
    double sum(size_t col) const;                              // Sum of a column (for double columns)
    double mean(size_t col) const;                             // Mean of a column (for double columns)
    double median(size_t col) const;                           // Median of a column (for double columns)
    tuple<double, double, double> quartiles(size_t col) const; // Quartiles of a column

    // Filter method
    DataFrame filter(size_t col, double threshold) const;

    // Copy method
    DataFrame copy() const;

    // Missing value methods
    vector<bool> is_na(size_t col) const;
    void fillna(const variant<double, string> &value);
    void dropna();

    // Drop method
    void drop(size_t col); // Drop a column

    // Merge and Concat methods
    DataFrame merge(const DataFrame &other, const string &onColumn) const;
    DataFrame concat(const DataFrame &other, bool axis = 0) const;

    // Indexing methods
    variant<double, string> iloc(size_t row, size_t col) const;                        // Integer-location based indexing
    variant<double, string> loc(const string &rowLabel, const string &colLabel) const; // Label-based indexing

    // Sort method
    void sort_values(size_t col);

    // Groupby method
    DataFrame groupby(const string &colLabel) const;

    // Apply method
    DataFrame apply(function<variant<double, string>(const variant<double, string> &)> func) const;

    // Unique and nunique methods
    vector<string> unique(size_t col) const;
    size_t nunique(size_t col) const;

    // Sample method
    DataFrame sample(size_t sampleSize) const;

    // Export to CSV
    void to_csv(const string &filePath) const;

    // Plotting methods (placeholders)
    void plot() const;
    void hist(size_t col) const;
    void boxplot(size_t col) const;
};

#endif // DATAFRAME_H