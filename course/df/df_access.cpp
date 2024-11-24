#include "../include/df.h"

// Print function
void DataFrame::print() const
{
    // Print column names
    cout << setw(10) << ""; // Space for row labels
    for (const auto &colName : columnNames)
    {
        cout << setw(10) << colName; // Adjust width as needed
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

// Head method implementation
void DataFrame::head(size_t n) const
{
    for (size_t i = 0; i < min(n, indexLabels.size()); ++i)
    {
        cout << indexLabels[i] << ": ";
        for (const auto &column : columns)
        {
            visit([i](const auto &array)
                  {
                      // Ensure we access within bounds
                      if (i < array.size())
                          cout << array[i] << " ";
                      else
                          cout << "N/A "; // Indicate missing data
                  },
                  column);
        }
        cout << endl;
    }
}

// Tail method implementation
void DataFrame::tail(size_t n) const
{
    for (size_t i = max(static_cast<int>(indexLabels.size()) - static_cast<int>(n), 0); i < indexLabels.size(); ++i)
    {
        cout << indexLabels[i] << ": ";
        for (const auto &column : columns)
        {
            visit([i](const auto &array)
                  {
                      // Ensure we access within bounds
                      if (i < array.size())
                          cout << array[i] << " ";
                      else
                          cout << "N/A "; // Indicate missing data
                  },
                  column);
        }
        cout << endl;
    }
}

// Getters for columns and index
vector<string> DataFrame::getColumns() const
{
    return columnNames;
}

vector<size_t> DataFrame::getIndex() const
{
    return indexLabels;
}

// Indexing methods implementation
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
// Export to CSV method implementation
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

size_t DataFrame::searchRowByColumn(const string &colLabel, const variant<double, string> &value) const
{
    // Find the index of the column label
    auto colIt = find(columnNames.begin(), columnNames.end(), colLabel);
    if (colIt == columnNames.end())
    {
        cerr << "Column label not found!" << endl;
        return -1; // Indicate not found
    }
    size_t colIndex = distance(columnNames.begin(), colIt);

    // Search for the value in the specified column
    const auto &columnData = get<0>(columns[colIndex]); // Assuming columns are of type Array<double>
    for (size_t rowIndex = 0; rowIndex < columnData.size(); ++rowIndex)
    {
        if (columnData[rowIndex] == value) // Compare with the value
        {
            return rowIndex; // Return the row index if found
        }
    }

    cerr << "Value not found in column!" << endl;
    return -1; // Indicate not found
}