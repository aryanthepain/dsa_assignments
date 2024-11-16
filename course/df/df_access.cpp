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

vector<string> DataFrame::getIndex() const
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

// // Sample method implementation
// DataFrame DataFrame::sample(size_t sampleSize) const
// {
//     DataFrame sampledData({}, columnNames); // Initialize with empty data and existing column names

//     // Adjust sample size if it's larger than the DataFrame size
//     if (sampleSize > indexLabels.size())
//     {
//         sampleSize = indexLabels.size();
//     }

//     vector<size_t> indices(indexLabels.size());
//     iota(indices.begin(), indices.end(), 0);                 // Fill indices with 0, 1, ..., n-1
//     std::random_device rd;                                   // Obtain a random number from hardware
//     std::mt19937 generator(rd());                            // Seed the generator
//     std::shuffle(indices.begin(), indices.end(), generator); // Shuffle the indices

//     // Sample the rows based on shuffled indices
//     for (size_t i = 0; i < sampleSize; ++i)
//     {
//         size_t index = indices[i];                             // Get the shuffled index
//         sampledData.indexLabels.push_back(indexLabels[index]); // Copy the index label

//         // Copy each column's data for the sampled row
//         for (size_t col = 0; col < columns.size(); ++col)
//         {
//             visit([&sampledData, col, index](const auto &array)
//                   {
//                       using T = decltype(array);
//                       // Debugging: Print size and index
//                       std::cout << "Column: " << col << ", Index: " << index << std::endl;
//                       std::cout << "Array size: " << get<Array<T>>(array).getData().size() << std::endl;

//                       // Check if the index is within bounds before accessing
//                       if (index < get<Array<T>>(array).getData().size()) {
//                           if constexpr (std::is_same_v<T, Array<double>>) {
//                               // Create a new Array<double> for sampled values
//                               Array<double> sampledColumn; // Create a new Array to hold sampled values
//                               sampledColumn = Array<double>(vector<double>()); // Initialize with an empty vector
//                               sampledColumn.getData().push_back(array[index]); // Add the sampled value
//                               sampledData.columns[col] = sampledColumn; // Store the sampled column
//                           } else if constexpr (std::is_same_v<T, Array<string>>) {
//                               // Create a new Array<string> for sampled values
//                               Array<string> sampledColumn; // Create a new Array to hold sampled values
//                               sampledColumn = Array<string>(vector<string>()); // Initialize with an empty vector
//                               sampledColumn.getData().push_back(array[index]); // Add the sampled value
//                               sampledData.columns[col] = sampledColumn; // Store the sampled column
//                           }
//                       } else {
//                           std::cerr << "Index out of bounds: " << index << " for column " << col << std::endl;
//                       } }, columns[col]);
//         }
//     }
//     return sampledData; // Return the sampled DataFrame
// }

// Copy method implementation
DataFrame DataFrame::copy() const
{
    // Create a new DataFrame with the same column names
    DataFrame copiedData({}, columnNames);
    copiedData.indexLabels = indexLabels; // Copy the index labels

    // Copy each column's data
    for (const auto &column : columns)
    {
        if (std::holds_alternative<Array<double>>(column))
        {
            // If the column is of type Array<double>
            const auto &originalArray = std::get<Array<double>>(column);
            Array<double> copiedArray(originalArray); // Create a copy of the original array

            // Here you can manipulate the copiedArray as needed
            // For example: copiedArray.someManipulationFunction();

            copiedData.columns.push_back(copiedArray); // Use the copied array
        }
        else if (std::holds_alternative<Array<string>>(column))
        {
            // If the column is of type Array<string>
            const auto &originalArray = std::get<Array<string>>(column);
            Array<string> copiedArray(originalArray); // Create a copy of the original array

            // Here you can manipulate the copiedArray as needed
            // For example: copiedArray.someManipulationFunction();

            copiedData.columns.push_back(copiedArray); // Use the copied array
        }
    }

    return copiedData; // Return the new DataFrame with copied data
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