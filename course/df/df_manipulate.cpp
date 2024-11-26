// author: Aryanthepain
#include "../include/df.h"

// filter based on double
DataFrame DataFrame::filterDouble(size_t col, double threshold, bool ifMinimumLimit) const
{
    try
    {
        // Check if the column index is out of bounds
        this->OutOfBounds(col);

        DataFrame filteredData;
        filteredData.columnNames = columnNames; // Copy column names to filteredData

        // Vector to hold the indices of the rows that meet the filter criteria
        vector<size_t> filteredIndices;

        const auto &arrayData = get<Array<double>>(columns[col]);
        for (size_t i = 0; i < arrayData.size(); ++i)
        {
            if ((ifMinimumLimit && arrayData[i] >= threshold) || (!ifMinimumLimit && arrayData[i] <= threshold))
            {
                filteredIndices.push_back(i); // Store the index of the row
            }
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
            else
            {
                throw invalid_argument("Unsupported data type for filtering.");
            }
        }

        // Set the index labels for the filtered DataFrame
        for (size_t index : filteredIndices)
        {
            filteredData.indexLabels.push_back(indexLabels[index]); // Add corresponding index labels
        }

        return filteredData;
    }
    catch (const out_of_range &oor)
    {
        cerr << "Out of Range error: " << oor.what() << '\n';
    }
    catch (const invalid_argument &ia)
    {
        cerr << "Invalid argument: " << ia.what() << '\n';
    }
    catch (const exception &e)
    {
        cerr << "An error occurred: " << e.what() << '\n';
    }
    return DataFrame();
}

// filter based on string
DataFrame DataFrame::filterString(size_t col, string threshold, bool ifMinimumLimit) const
{
    try
    {
        // Check if the column index is out of bounds
        this->OutOfBounds(col);

        DataFrame filteredData;
        filteredData.columnNames = columnNames; // Copy column names to filteredData

        // Vector to hold the indices of the rows that meet the filter criteria
        vector<size_t> filteredIndices;

        const auto &arrayData = get<Array<string>>(columns[col]);
        for (size_t i = 0; i < arrayData.size(); ++i)
        {
            // we want to filter for exact matches
            if ((ifMinimumLimit && arrayData[i] == threshold) || (!ifMinimumLimit && arrayData[i] != threshold))
            {
                filteredIndices.push_back(i); // Store the index of the row
            }
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
            else
            {
                throw invalid_argument("Unsupported data type for filtering.");
            }
        }

        // Set the index labels for the filtered DataFrame
        for (size_t index : filteredIndices)
        {
            filteredData.indexLabels.push_back(indexLabels[index]); // Add corresponding index labels
        }

        return filteredData;
    }
    catch (const out_of_range &oor)
    {
        cerr << "Out of Range error: " << oor.what() << '\n';
    }
    catch (const invalid_argument &ia)
    {
        cerr << "Invalid argument: " << ia.what() << '\n';
    }
    catch (const exception &e)
    {
        cerr << "An error occurred: " << e.what() << '\n';
    }
    return DataFrame();
}

// Drop column
void DataFrame::drop(size_t col)
{
    this->OutOfBounds(col);

    columns.erase(columns.begin() + col);
    columnNames.erase(columnNames.begin() + col);
}

// Concatenate dataframe, 0 for rows, 1 for columns
DataFrame DataFrame::concat(const DataFrame &other, bool axis) const
{
    if (axis == 0)
    {
        return concatRows(other);
    }
    else if (axis == 1)
    {
        return concatColumns(other);
    }
    else
    {
        throw invalid_argument("Axis must be 0 (rows) or 1 (columns).");
    }
}

DataFrame DataFrame::concatRows(const DataFrame &other) const
{
    DataFrame result;

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

    // Set the index labels for the result DataFrame
    vector<size_t> newIndexLabels;
    for (const auto &label : indexLabels)
    {
        newIndexLabels.push_back(label); // Keep the original index labels
    }
    size_t originalSize = newIndexLabels.size();
    for (const auto &label : other.indexLabels)
    {
        newIndexLabels.push_back(label + originalSize); // Append the other DataFrame's index labels
    }
    result.indexLabels = newIndexLabels;

    return result;
}

DataFrame DataFrame::concatColumns(const DataFrame &other) const
{
    DataFrame result;

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

    return result;
}

// Sort method implementation
void DataFrame::sort_values(size_t col, bool ascending)
{
    this->OutOfBounds(col); // Check for valid column index

    // Create a vector of pairs to hold the values and their original indices
    vector<pair<variant<double, string>, size_t>> indexedValues;

    // Visit the specific column to gather values and their indices
    visit([this, col, &indexedValues](auto &array)
          {
              using T = decltype(array[0]);
              for (size_t i = 0; i < array.size(); ++i) {
                  indexedValues.emplace_back(array[i], i);
              } }, columns[col]);

    // Sort the indexed values based on the specified column values
    if (ascending)
    {
        sort(indexedValues.begin(), indexedValues.end(),
             [](const auto &a, const auto &b)
             { return a.first < b.first; });
    }
    else
    {
        sort(indexedValues.begin(), indexedValues.end(),
             [](const auto &a, const auto &b)
             { return a.first > b.first; });
    }

    // Create a new DataFrame to hold the sorted values
    DataFrame sortedDataFrame;

    // Rearrange columns based on sorted indices
    for (size_t j = 0; j < columns.size(); ++j)
    {
        if (holds_alternative<Array<double>>(columns[j]))
        {
            vector<double> sortedColumn;
            for (const auto &pair : indexedValues)
            {
                sortedColumn.push_back(get<Array<double>>(columns[j])[pair.second]);
            }
            sortedDataFrame.addColumn(columnNames[j], Array<double>(sortedColumn));
        }
        else if (holds_alternative<Array<string>>(columns[j]))
        {
            vector<string> sortedColumn;
            for (const auto &pair : indexedValues)
            {
                sortedColumn.push_back(get<Array<string>>(columns[j])[pair.second]);
            }
            sortedDataFrame.addColumn(columnNames[j], Array<string>(sortedColumn));
        }
    }

    // Update the original DataFrame with the sorted DataFrame
    columns = sortedDataFrame.columns;
    columnNames = sortedDataFrame.columnNames;

    // Update indexLabels to sorted order
    indexLabels.clear();
    for (size_t i = 0; i < indexedValues.size(); ++i)
    {
        indexLabels.push_back(indexedValues[i].second);
    }
}

// Apply method implementation
DataFrame DataFrame::apply(size_t col, function<variant<double, string>(const variant<double, string> &)> func) const
{
    this->OutOfBounds(col);
    DataFrame result = this->copy(); // Create a copy to store results

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

    return result;
}