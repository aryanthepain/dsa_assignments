// author: Aryanthepain
#include "../include/df.h"

// Filter method implementation
DataFrame DataFrame::filter(size_t col, double threshold, bool ifMinimum) const
{
    // Check if the column index is out of bounds
    this->OutOfBounds(col); // Keep the original bounds checking

    DataFrame filteredData;
    filteredData.columnNames = columnNames; // Copy column names to filteredData

    // Vector to hold the indices of the rows that meet the filter criteria
    vector<size_t> filteredIndices;

    // Determine the type of the column and filter accordingly
    if (holds_alternative<Array<double>>(columns[col]))
    {
        const auto &arrayData = get<Array<double>>(columns[col]);
        for (size_t i = 0; i < arrayData.size(); ++i)
        {
            if ((ifMinimum && arrayData[i] >= threshold) || (!ifMinimum && arrayData[i] <= threshold))
            {
                filteredIndices.push_back(i); // Store the index of the row
            }
        }
    }
    else if (holds_alternative<Array<string>>(columns[col]))
    {
        const auto &arrayData = get<Array<string>>(columns[col]);
        for (size_t i = 0; i < arrayData.size(); ++i)
        {
            // Assuming we want to filter for exact matches
            if ((ifMinimum && arrayData[i] == to_string(threshold)) || (!ifMinimum && arrayData[i] != to_string(threshold)))
            {
                filteredIndices.push_back(i); // Store the index of the row
            }
        }
    }
    else
    {
        throw invalid_argument("Unsupported data type for filtering.");
    }

    // Fill the filteredData with the corresponding rows
    for (size_t j = 0; j < columnNames.size(); j++)
    {
        if (holds_alternative<Array<double>>(columns[j]))
        {
            const auto &arrayData = get<Array<double>>(columns[j]);
            vector<double> filteredVect;
            for (size_t i : filteredIndices)
            {
                filteredVect.push_back(arrayData[i]); // Collect filtered values
            }

            filteredData.columns.push_back(Array<double>(filteredVect)); // Store the filtered column data
        }
        else if (holds_alternative<Array<string>>(columns[j]))
        {
            const auto &arrayData = get<Array<string>>(columns[j]);
            vector<string> filteredVect;
            for (size_t i : filteredIndices)
            {
                filteredVect.push_back(arrayData[i]); // Collect filtered values
            }

            filteredData.columns.push_back(Array<string>(filteredVect)); // Store the filtered column data
        }
    }

    // Set the index labels for the filtered DataFrame
    for (size_t index : filteredIndices)
    {
        filteredData.indexLabels.push_back(indexLabels[index]); // Add corresponding index labels
    }

    return filteredData;
}

// Drop method implementation
void DataFrame::drop(size_t col)
{
    this->OutOfBounds(col);

    columns.erase(columns.begin() + col);
    columnNames.erase(columnNames.begin() + col);
}

// Merge method implementation
DataFrame DataFrame::merge(const DataFrame &other, const string &onColumn) const
{
    // Find the index of the column to merge on in both DataFrames
    auto it1 = find(columnNames.begin(), columnNames.end(), onColumn);
    auto it2 = find(other.columnNames.begin(), other.columnNames.end(), onColumn);

    if (it1 == columnNames.end() || it2 == other.columnNames.end())
    {
        throw invalid_argument("Column '" + onColumn + "' does not exist in both DataFrames.");
    }

    size_t colIndex1 = distance(columnNames.begin(), it1);
    size_t colIndex2 = distance(other.columnNames.begin(), it2);

    // Create a new DataFrame to hold the merged data
    DataFrame mergedData;
    mergedData.columnNames = columnNames; // Start with the column names of the first DataFrame

    // Add columns from the other DataFrame, excluding the merge column
    for (size_t j = 0; j < other.columnNames.size(); ++j)
    {
        if (j != colIndex2)
        { // Skip the column we are merging on
            mergedData.columnNames.push_back(other.columnNames[j]);
        }
    }

    // Create a map to store the index of each value in the merging column of the other DataFrame
    unordered_map<variant<double, string>, vector<size_t>> indexMap;
    for (size_t i = 0; i < other.indexLabels.size(); ++i)
    {
        auto key = other.iloc(i, colIndex2); // Get the value in the merge column
        indexMap[key].push_back(i);          // Map the key to its index in the other DataFrame
    }

    // Temporary vectors to hold merged data for each column
    vector<Array<double>> mergedColumnsDouble(columns.size());
    vector<Array<string>> mergedColumnsString(columns.size());

    // Iterate over the rows of the current DataFrame
    for (size_t i = 0; i < indexLabels.size(); ++i)
    {
        auto key = iloc(i, colIndex1); // Get the value in the merge column

        // Check if this key exists in the indexMap
        if (indexMap.find(key) != indexMap.end())
        {
            // For each matching index in the other DataFrame, create a new row in the merged DataFrame
            for (size_t j : indexMap[key])
            {
                // Add the current row from this DataFrame
                for (size_t k = 0; k < columns.size(); ++k)
                {
                    if (holds_alternative<Array<double>>(columns[k]))
                    {
                        const auto &arrayData = get<Array<double>>(columns[k]);
                        mergedColumnsDouble[k].getData().push_back(arrayData[i]); // Collect double values
                    }
                    else if (holds_alternative<Array<string>>(columns[k]))
                    {
                        const auto &arrayData = get<Array<string>>(columns[k]);
                        mergedColumnsString[k].getData().push_back(arrayData[i]); // Collect string values
                    }
                }

                // Add the corresponding row from the other DataFrame, excluding the merge column
                for (size_t k = 0; k < other.columns.size(); ++k)
                {
                    if (k != colIndex2)
                    { // Skip the merge column
                        if (holds_alternative<Array<double>>(other.columns[k]))
                        {
                            const auto &arrayData = get<Array<double>>(other.columns[k]);
                            mergedColumnsDouble[k].getData().push_back(arrayData[j]); // Collect double values
                        }
                        else if (holds_alternative<Array<string>>(other.columns[k]))
                        {
                            const auto &arrayData = get<Array<string>>(other.columns[k]);
                            mergedColumnsString[k].getData().push_back(arrayData[j]); // Collect string values
                        }
                    }
                }
            }
        }
    }

    // Construct the merged columns from the temporary vectors
    for (size_t k = 0; k < columns.size(); ++k)
    {
        if (holds_alternative<Array<double>>(columns[k]))
        {
            mergedData.columns.push_back(Array<double>(mergedColumnsDouble[k].getData()));
        }
        else if (holds_alternative<Array<string>>(columns[k]))
        {
            mergedData.columns.push_back(Array<string>(mergedColumnsString[k].getData()));
        }
    }

    return mergedData;
}

// Concat method implementation
DataFrame DataFrame::concat(const DataFrame &other, bool axis) const
{
    DataFrame result;

    if (axis == 0)
    { // Concatenate along rows
        // Ensure both DataFrames have the same column names
        if (columnNames != other.columnNames)
        {
            throw invalid_argument("Column names must match for row-wise concatenation.");
        }

        // Set the column names for the result DataFrame
        result.columnNames = columnNames;

        // Temporary vectors to hold concatenated data
        vector<vector<double>> tempDouble(columns.size());
        vector<vector<string>> tempString(columns.size());

        // Concatenate rows from the current DataFrame
        for (size_t i = 0; i < indexLabels.size(); ++i)
        {
            for (size_t j = 0; j < columns.size(); ++j)
            {
                if (holds_alternative<Array<double>>(columns[j]))
                {
                    const auto &arrayData = get<Array<double>>(columns[j]);
                    tempDouble[j].push_back(arrayData[i]); // Collect double values
                }
                else if (holds_alternative<Array<string>>(columns[j]))
                {
                    const auto &arrayData = get<Array<string>>(columns[j]);
                    tempString[j].push_back(arrayData[i]); // Collect string values
                }
            }
        }

        // Add collected data to the result DataFrame
        for (size_t j = 0; j < columns.size(); ++j)
        {
            if (holds_alternative<Array<double>>(columns[j]))
            {
                result.columns.push_back(Array<double>(tempDouble[j])); // Create Array from temp vector
            }
            else if (holds_alternative<Array<string>>(columns[j]))
            {
                result.columns.push_back(Array<string>(tempString[j])); // Create Array from temp vector
            }
        }

        // Concatenate rows from the other DataFrame
        for (size_t i = 0; i < other.indexLabels.size(); ++i)
        {
            for (size_t j = 0; j < other.columns.size(); ++j)
            {
                if (holds_alternative<Array<double>>(other.columns[j]))
                {
                    const auto &arrayData = get<Array<double>>(other.columns[j]);
                    tempDouble[j].push_back(arrayData[i]); // Collect double values
                }
                else if (holds_alternative<Array<string>>(other.columns[j]))
                {
                    const auto &arrayData = get<Array<string>>(other.columns[j]);
                    tempString[j].push_back(arrayData[i]); // Collect string values
                }
            }
        }

        // Add collected data from the other DataFrame to the result DataFrame
        for (size_t j = 0; j < other.columns.size(); ++j)
        {
            if (holds_alternative<Array<double>>(other.columns[j]))
            {
                result.columns.push_back(Array<double>(tempDouble[j])); // Create Array from temp vector
            }
            else if (holds_alternative<Array<string>>(other.columns[j]))
            {
                result.columns.push_back(Array<string>(tempString[j])); // Create Array from temp vector
            }
        }

        // Set the index labels for the result DataFrame
        result.indexLabels = indexLabels; // Keep the original index labels
        for (const auto &label : other.indexLabels)
        {
            result.indexLabels.push_back(label); // Append the other DataFrame's index labels
        }
    }
    else if (axis == 1)
    { // Concatenate along columns
        // Ensure both DataFrames have the same number of rows
        if (indexLabels.size() != other.indexLabels.size())
        {
            throw invalid_argument("Number of rows must match for column-wise concatenation.");
        }

        // Set the initial column names for the result DataFrame
        result.columnNames = columnNames;

        // Add columns from the current DataFrame
        for (const auto &col : columns)
        {
            result.columns.push_back(col); // Directly copy the column
        }

        // Add columns from the other DataFrame
        for (size_t j = 0; j < other.columns.size(); ++j)
        {
            result.columnNames.push_back(other.columnNames[j]);
            result.columns.push_back(other.columns[j]); // Directly copy the column
        }

        // Set the index labels for the concatenated DataFrame
        result.indexLabels = indexLabels; // Keep the original index labels
    }
    else
    {
        throw invalid_argument("Axis must be 0 (rows) or 1 (columns).");
    }

    return result;
}

// Sort method implementation
void DataFrame::sort_values(size_t col, bool ascending)
{
    this->OutOfBounds(col); // Check for valid column index

    visit([this, col, ascending](auto &array)
          {
        using T = decltype(array[0]);
        if constexpr (is_same_v<T, double> || is_same_v<T, string>) {
            // Sort the array and maintain the indexLabels
            vector<size_t> indices(array.size());
            iota(indices.begin(), indices.end(), 0); // Fill indices with 0, 1, ..., n-1
            
            // Perform sorting based on the specified order
            if (ascending) {
                sort(indices.begin(), indices.end(), [&array](size_t a, size_t b) {
                    return array[a] < array[b]; // Ascending order
                });
            } else {
                sort(indices.begin(), indices.end(), [&array](size_t a, size_t b) {
                    return array[a] > array[b]; // Descending order
                });
            }

            // Rearrange indexLabels based on sorted indices
            vector<size_t> sortedIndexLabels;
            for (size_t index : indices) {
                sortedIndexLabels.push_back(indexLabels[index]);
            }
            indexLabels = sortedIndexLabels; // Update indexLabels to sorted order
        } 
        else {
            throw invalid_argument("Unsupported data type for sorting.");
        } }, columns[col]); // Visit the specific column
}

// Apply method implementation
DataFrame DataFrame::apply(function<variant<double, string>(const variant<double, string> &)> func) const
{
    DataFrame result = this->copy(); // Create a copy to store results

    for (size_t col = 0; col < columns.size(); ++col)
    {
        vector<double> tempDouble;
        vector<string> tempString;

        visit([this, &tempDouble, &tempString, &func](auto &array)
              {
            using T = decltype(array[0]);

            // Iterate over each element in the array
            for (size_t i = 0; i < array.size(); ++i) {
                // Apply the function to each element and store the result
                auto result = func(array[i]);

                if (holds_alternative<double>(result)) {
                    tempDouble.push_back(get<double>(result));
                } else if (holds_alternative<string>(result)) {
                    tempString.push_back(get<string>(result));
                }
            } }, columns[col]);

        if (!tempDouble.empty())
        {
            result.columns[col] = Array<double>(tempDouble);
        }
        else if (!tempString.empty())
        {
            result.columns[col] = Array<string>(tempString);
        }
    }

    return result;
}