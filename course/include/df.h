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
    vector<string> indexLabels; // Row index labels

public:
    // Constructors
    DataFrame(const vector<vector<variant<double, string>>> &inputData,
              const vector<string> &colNames);

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
};

#endif // DF_H