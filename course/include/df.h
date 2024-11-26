// author: Aryanthepain
#ifndef DF_H
#define DF_H

#include <bits/stdc++.h>
#include "Array.h"
using namespace std;

// Define a variant type for the DataFrame columns
using ColumnType = variant<Array<double>, Array<string>>;

class DataFrame
{
private:
    vector<ColumnType> columns; // Each column can be either Array<double> or Array<string>
    vector<string> columnNames; // Column names
    vector<size_t> indexLabels; // Row index labels

    // helper functions
    void describeNumericColumn(size_t index) const;
    void describeStringColumn(size_t index) const;
    bool OutOfBounds(size_t num) const;
    DataFrame concatColumns(const DataFrame &other) const;
    DataFrame concatRows(const DataFrame &other) const;

public:
    // Constructors

    DataFrame();
    DataFrame(const vector<vector<variant<double, string>>> &inputData,
              const vector<string> &colNames);
    DataFrame(const string &csvFilePath);
    void addColumn(const string &name, const ColumnType &data);
    void addColumn(const string &name, const Array<double> &data);
    void addColumn(const string &name, const Array<string> &data);

    // Access methods

    void print() const;                                                         // print the entire DataFrame
    void head(size_t n = 5) const;                                              // get top n values
    void tail(size_t n = 5) const;                                              // get bottom n values
    vector<string> getColumns() const;                                          // get column names
    vector<size_t> getIndex() const;                                            // get row index labels
    DataFrame copy() const;                                                     // Copy method
    variant<double, string> iloc(size_t row, size_t col) const;                 // Integer-location based indexing
    variant<double, string> loc(size_t rowLabel, const string &colLabel) const; // Label-based indexing
    // search row name for an entry of a column
    int searchRowByColumn(const string &colLabel, const variant<double, string> &value) const;
    // search column name for an entry of a row
    int searchColumnByRow(size_t rowIndex, const variant<double, string> &value) const;
    void to_csv(const string &filePath) const; // Export to CSV

    // Describe the dataframe

    void describe() const;               // describe the entire dataframe
    pair<size_t, size_t> shape() const;  // give the row*column as a pair
    ColumnType unique(size_t col) const; // unique values
    size_t nunique(size_t col) const;    // number of unique values

    // Statistical methods

    double sum(size_t col) const;                              // Sum of a column (for double columns)
    double mean(size_t col) const;                             // Mean of a column (for double columns)
    tuple<double, double, double> quartiles(size_t col) const; // Quartiles of a column

    // manipulate dataframe

    DataFrame filterString(size_t col, string threshold, bool ifMinimumLimit = true) const;
    DataFrame filterDouble(size_t col, double threshold, bool ifMinimumLimit = true) const;
    void drop(size_t col);                                         // Drop a column
    DataFrame concat(const DataFrame &other, bool axis = 0) const; // concat df
    void sort_values(size_t col, bool ascending = true);           // Sort method
    DataFrame apply(size_t col, function<variant<double, string>(const variant<double, string> &)> func) const;

    // Plotting methods

    void plot(size_t col) const;
    void hist(size_t col) const;
    void boxplot(size_t col) const;
};

#endif // DF_H