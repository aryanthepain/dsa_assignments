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

public:
    // Constructors
    DataFrame();
    DataFrame(const vector<vector<variant<double, string>>> &inputData,
              const vector<string> &colNames);

    DataFrame(const string &csvFilePath);
    // void addIndexLabel(size_t label);
    void addColumn(const string &name, const ColumnType &data);
    void addColumn(const string &name, const Array<double> &data);
    void addColumn(const string &name, const Array<string> &data);

    // Access methods
    void print() const;                                                         // print the entire DataFrame
    void head(size_t n) const;                                                  // get top n values
    void tail(size_t n) const;                                                  // get bottom n values
    vector<string> getColumns() const;                                          // get column names
    vector<size_t> getIndex() const;                                            // get row index labels
    DataFrame copy() const;                                                     // Copy method
    variant<double, string> iloc(size_t row, size_t col) const;                 // Integer-location based indexing
    variant<double, string> loc(size_t rowLabel, const string &colLabel) const; // Label-based indexing
    // search row name for an entry of a column
    int searchRowByColumn(const string &colLabel, const variant<double, string> &value) const;
    // search column name for an entry of a row
    int searchColumnByRow(size_t rowIndex, const variant<double, string> &value) const;
    // Sample method
    void to_csv(const string &filePath) const; // Export to CSV

    // Describe the dataframe
    void describe() const;              // describe the entire dataframe
    pair<size_t, size_t> shape() const; // give the row*column as a pair
    // unique values
    Array<double> unique(size_t col) const;
    Array<string> uniqueString(size_t col) const;
    size_t nunique(size_t col) const; // number of unique values

    // Statistical methods
    double sum(size_t col) const;                              // Sum of a column (for double columns)
    double mean(size_t col) const;                             // Mean of a column (for double columns)
    tuple<double, double, double> quartiles(size_t col) const; // Quartiles of a column

    // manipulate dataframe
    DataFrame filter(size_t col, double threshold) const;                                           // Filter method
    void drop(size_t col);                                                                          // Drop a column
    DataFrame merge(const DataFrame &other, const string &onColumn) const;                          // merge df
    DataFrame concat(const DataFrame &other, bool axis = 0) const;                                  // concat df
    void sort_values(size_t col);                                                                   // Sort method
    DataFrame groupby(const string &colLabel) const;                                                // Groupby method
    DataFrame apply(function<variant<double, string>(const variant<double, string> &)> func) const; // Apply method
};

#endif // DF_H