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
              const vector<string> &colNames,
              const vector<string> &rowLabels);

    DataFrame(const string &csvFilePath);

    // Method to print the DataFrame
    void print() const;
};

#endif // DF_H