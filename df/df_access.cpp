// author: Aryanthepain
#include "../include/df.h"

// Print function
void DataFrame::print() const
{
    // Print column names
    cout << setw(10) << ""; // Space for row labels
    for (const auto &colName : columnNames)
    {
        cout << setw(10) << colName;
    }
    cout << endl;

    // Print data rows
    for (size_t i = 0; i < indexLabels.size(); ++i)
    {
        cout << setw(10) << indexLabels[i]; // Print row label
        for (size_t col = 0; col < columns.size(); ++col)
        {
            // Use visit to handle the variant type
            visit([i](auto &&arg)
                  {
                      // Ensure we access within bounds
                      if (i < arg.size())
                          cout << setw(10) << arg[i]; // Access the i-th element of the column
                      else
                          cout << setw(10) << "N/A"; // Indicate missing data
                  },
                  columns[col]);
        }
        cout << endl; // New line after each row
    }
}

void DataFrame::head(size_t n) const
{
    cout << setw(10) << ""; // Space for row labels
    for (const auto &colName : columnNames)
    {
        cout << setw(10) << colName;
    }
    cout << endl;

    for (size_t i = 0; i < min(n, indexLabels.size()); ++i)
    {
        cout << setw(10) << indexLabels[i]; // Print row label
        for (size_t col = 0; col < columns.size(); ++col)
        {
            // Use visit to handle the variant type
            visit([i](auto &&arg)
                  {
                      // Ensure we access within bounds
                      if (i < arg.size())
                          cout << setw(10) << arg[i]; // Access the i-th element of the column
                      else
                          cout << setw(10) << "N/A"; // Indicate missing data
                  },
                  columns[col]);
        }
        cout << endl; // New line after each row
    }
}

void DataFrame::tail(size_t n) const
{
    cout << setw(10) << ""; // Space for row labels
    for (const auto &colName : columnNames)
    {
        cout << setw(10) << colName;
    }
    cout << endl;

    for (size_t i = max(static_cast<int>(indexLabels.size()) - static_cast<int>(n), 0); i < indexLabels.size(); ++i)
    {
        cout << setw(10) << indexLabels[i]; // Print row label
        for (size_t col = 0; col < columns.size(); ++col)
        {
            // Use visit to handle the variant type
            visit([i](auto &&arg)
                  {
                      // Ensure we access within bounds
                      if (i < arg.size())
                          cout << setw(10) << arg[i]; // Access the i-th element of the column
                      else
                          cout << setw(10) << "N/A"; // Indicate missing data
                  },
                  columns[col]);
        }
        cout << endl; // New line after each row
    }
}

// get column names
vector<string> DataFrame::getColumns() const
{
    return columnNames;
}

// get index values
vector<size_t> DataFrame::getIndex() const
{
    return indexLabels;
}

// Find element with integer values
variant<double, string> DataFrame::iloc(size_t row, size_t col) const
{
    // Check for out-of-bounds indices
    if (row >= indexLabels.size() || col >= columns.size())
    {
        cerr << "Index out of bounds!" << endl;
        return {}; // Return an empty variant
    }

    // Use visit to retrieve the element at the specified row and column
    return visit([row](const auto &array) -> variant<double, string>
                 {
                     // Ensure we access within bounds
                     if (row < array.size())
                         return array[row]; // Return the element at the specified row
                     else
                         return {}; // Return an empty variant if out of bounds
                 },
                 columns[col]);
}

// find element with string values
variant<double, string> DataFrame::loc(size_t rowIndex, const string &colLabel) const
{
    // Check if the row index is within bounds
    if (rowIndex >= indexLabels.size())
    {
        cerr << "Row index out of bounds!" << endl;
        return {}; // Return an empty variant
    }

    // Find the index of the column label
    auto colIt = find(columnNames.begin(), columnNames.end(), colLabel);
    if (colIt == columnNames.end())
    {
        cerr << "Column label not found!" << endl;
        return {}; // Return an empty variant
    }
    size_t colIndex = distance(columnNames.begin(), colIt);

    // Use iloc to retrieve the value at the specified row and column
    return iloc(rowIndex, colIndex);
}

// Export to CSV
void DataFrame::to_csv(const string &filePath) const
{
    ofstream file(filePath);
    if (file.is_open())
    {
        // Write column names
        for (size_t i = 0; i < columnNames.size(); ++i)
        {
            file << columnNames[i];
            if (i < columnNames.size() - 1)
                file << ","; // Avoid trailing comma
        }
        file << "\n";

        // Write data
        for (size_t i = 0; i < indexLabels.size(); ++i)
        {
            file << indexLabels[i] << ","; // Write index label
            for (size_t col = 0; col < columns.size(); ++col)
            {
                visit([&file, i](const auto &array)
                      {
                          // Ensure we access within bounds
                          if (i < array.size())
                              file << array[i];
                          else
                              file << "N/A"; // Indicate missing data
                      },
                      columns[col]);
                if (col < columns.size() - 1)
                    file << ","; // Avoid trailing comma
            }
            file << "\n";
        }
    }
    else
    {
        cerr << "Unable to open file for writing." << endl;
    }
}

// return index value by a column and element
int DataFrame::searchRowByColumn(const string &colLabel, const variant<double, string> &value) const
{
    auto colIt = find(columnNames.begin(), columnNames.end(), colLabel);
    if (colIt == columnNames.end())
    {
        cerr << "Column label not found!" << endl;
        return -1; // Column not found
    }

    size_t colIndex = distance(columnNames.begin(), colIt);
    const ColumnType &columnData = columns[colIndex];

    return std::visit([&](const auto &array) -> int
                      {
                          for (size_t i = 0; i < array.size(); ++i)
                          {
                              if (value == (variant<double, string>)array[i])
                              {
                                  return static_cast<int>(i); // Return found index as int
                              }
                          }
                          return (int)(-1); // Value not found
                      },
                      columnData);
}

// return column name by index value and element
int DataFrame::searchColumnByRow(size_t rowIndex, const variant<double, string> &value) const
{
    if (rowIndex >= indexLabels.size())
    {
        cerr << "Row index out of bounds!" << endl;
        return -1; // Row index out of bounds
    }

    for (size_t colIndex = 0; colIndex < columns.size(); ++colIndex)
    {
        const ColumnType &columnData = columns[colIndex];

        int result = std::visit([&](const auto &array) -> int
                                {
                                    if (rowIndex < array.size())
                                    {
                                        if (value == (variant<double, string>)array[rowIndex])
                                        {
                                            return static_cast<int>(colIndex); // Return found column index as int
                                        }
                                    }
                                    return (int)(-1); // Value not found
                                },
                                columnData);

        if (result != -1)
        {
            return result; // Return found column index
        }
    }

    cerr << "Value not found in row!" << endl;
    return -1; // Value not found
}

// return a copy of the dataframe
DataFrame DataFrame::copy() const
{
    DataFrame df;

    for (size_t i = 0; i < columns.size(); i++)
    {
        if (holds_alternative<Array<double>>(columns[i]))
        {
            const auto &arrayData = get<Array<double>>(columns[i]);
            df.addColumn(columnNames[i], arrayData);
        }
        else if (holds_alternative<Array<string>>(columns[i]))
        {
            const auto &arrayData = get<Array<string>>(columns[i]);
            df.addColumn(columnNames[i], arrayData);
        }
    }

    return df;
}