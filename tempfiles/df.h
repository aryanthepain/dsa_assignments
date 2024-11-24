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

    // Access methods
    void print() const;                                                                // print the entire DataFrame
    void head(size_t n) const;                                                         // get top n values
    void tail(size_t n) const;                                                         // get bottom n values
    vector<string> getColumns() const;                                                 // get column names
    vector<string> getIndex() const;                                                   // get row index labels
    DataFrame copy() const;                                                            // Copy method
    variant<double, string> iloc(size_t row, size_t col) const;                        // Integer-location based indexing
    variant<double, string> loc(const string &rowLabel, const string &colLabel) const; // Label-based indexing
    DataFrame sample(size_t sampleSize) const;                                         // Sample method
    void to_csv(const string &filePath) const;                                         // Export to CSV
    // search row name for an entry of a column
    // search column name for an entry of a row

    // Describe the dataframe
    void describe() const;                   // describe the entire dataframe
    pair<size_t, size_t> shape() const;      // give the row*column as a pair
    vector<string> unique(size_t col) const; // unique values
    size_t nunique(size_t col) const;        // number of unique values

    // Statistical methods
    double sum(size_t col) const;                              // Sum of a column (for double columns)
    double mean(size_t col) const;                             // Mean of a column (for double columns)
    double median(size_t col) const;                           // Median of a column (for double columns)
    tuple<double, double, double> quartiles(size_t col) const; // Quartiles of a column

    // manipulate dataframe
    DataFrame filter(size_t col, double threshold) const;                                           // Filter method
    void drop(size_t col);                                                                          // Drop a column
    DataFrame merge(const DataFrame &other, const string &onColumn) const;                          // merge df
    DataFrame concat(const DataFrame &other, bool axis = 0) const;                                  // concat df
    void sort_values(size_t col);                                                                   // Sort method
    DataFrame groupby(const string &colLabel) const;                                                // Groupby method
    DataFrame apply(function<variant<double, string>(const variant<double, string> &)> func) const; // Apply method

    // Missing value methods
    vector<bool> is_na(size_t col) const;
    void fillna(const variant<double, string> &value);
    void dropna();

    // Plotting methods
    void plot() const;
    void hist(size_t col) const;
    void boxplot(size_t col) const;
};

#endif // DATAFRAME_H