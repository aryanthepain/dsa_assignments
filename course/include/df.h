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

    // Access methods
    void print() const;                // print the entire DataFrame
    void head(size_t n) const;         // get top n values
    void tail(size_t n) const;         // get bottom n values
    vector<string> getColumns() const; // get column names
    vector<size_t> getIndex() const;   // get row index labels
    // Copy method
    variant<double, string> iloc(size_t row, size_t col) const;                        // Integer-location based indexing
    variant<double, string> loc(const string &rowLabel, const string &colLabel) const; // Label-based indexing
    // Sample method
    void to_csv(const string &filePath) const;                           // Export to CSV
    string getRowName(size_t rowIndex, const string &colLabel) const;    // give row name for an entry in a column
    string getColumnName(size_t colIndex, const string &rowLabel) const; // give column name for an entry in a row
};

#endif // DF_H