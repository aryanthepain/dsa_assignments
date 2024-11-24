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

public:
    // Constructors
    DataFrame(const vector<vector<variant<double, string>>> &inputData,
              const vector<string> &colNames);

    DataFrame(const string &csvFilePath);
    void addColumn(const string &name, const ColumnType &data);
    void addIndexLabel(size_t label);

    // Access methods
    void print() const;                // print the entire DataFrame
    void head(size_t n) const;         // get top n values
    void tail(size_t n) const;         // get bottom n values
    vector<string> getColumns() const; // get column names
    vector<size_t> getIndex() const;   // get row index labels
    // Copy method
    variant<double, string> iloc(size_t row, size_t col) const;                 // Integer-location based indexing
    variant<double, string> loc(size_t rowLabel, const string &colLabel) const; // Label-based indexing

    // search row name for an entry of a column
    int searchRowByColumn(const string &colLabel, const variant<double, string> &value) const;
    // search column name for an entry of a row
    int searchColumnByRow(size_t rowIndex, const variant<double, string> &value) const;
    // Sample method
    void to_csv(const string &filePath) const; // Export to CSV
};

#endif // DF_H