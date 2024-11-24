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
                      cout << setw(10) << arg[i]; // Access the i-th element of the column
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
                  { cout << array[i] << " "; }, column);
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
                  { cout << array[i] << " "; }, column);
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
        cout << "Index out of bounds!" << endl;
        return {}; // Return an empty variant
    }

    // Use visit to retrieve the element at the specified row and column
    return visit([row](const auto &array) -> variant<double, string>
                 {
                     return array[row]; // Return the element at the specified row
                 },
                 columns[col]);
}

variant<double, string> DataFrame::loc(const string &rowLabel, const string &colLabel) const
{
    // Find the index of the row label
    auto it = find(indexLabels.begin(), indexLabels.end(), rowLabel);
    if (it == indexLabels.end())
    {
        cout << "Row label not found!" << endl;
        return {}; // Return an empty variant
    }
    size_t rowIndex = distance(indexLabels.begin(), it);

    // Find the index of the column label
    auto colIt = find(columnNames.begin(), columnNames.end(), colLabel);
    if (colIt == columnNames.end())
    {
        cout << "Column label not found!" << endl;
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
                      { file << array[i]; }, columns[col]);
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