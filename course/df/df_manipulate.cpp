// author: Aryanthepain
#include "../include/df.h"

// Filter method implementation
DataFrame DataFrame::filter(size_t col, double threshold, bool ifMinimum) const
{
    this->OutOfBounds(col);

    DataFrame filteredData;
    for (size_t i = 0; i < columnNames.size(); i++)
    {
        filteredData.columnNames = columnNames;
    }

    if (ifMinimum)
    {
        visit([this, &filteredData, threshold](const auto &array)
              {
        using T = decltype(array[0]);
        if constexpr (is_same_v<T, double>) {
            for (size_t i = 0; i < array.size(); ++i) {
                if (array[i] >= threshold) {
                    filteredData.indexLabels.push_back(indexLabels[i]);
                    // Add the corresponding row to filteredData
                }
            }
        } }, columns[col]);
    }
    else
    {
        visit([this, &filteredData, threshold](const auto &array)
              {
        using T = decltype(array[0]);
        if constexpr (is_same_v<T, double>) {
            for (size_t i = 0; i < array.size(); ++i) {
                if (array[i] <= threshold) {
                    filteredData.indexLabels.push_back(indexLabels[i]);
                    // Add the corresponding row to filteredData
                }
            }
        } }, columns[col]);
    }

    auto filteredIndices = filteredData.indexLabels;

    for (size_t j = 0; j < columnNames.size(); j++)
    {
        if (holds_alternative<Array<double>>(columns[j]))
        {
            const auto &arrayData = get<Array<double>>(columns[j]);
            vector<double> filteredVect;
            for (size_t i = 0; i < filteredIndices.size(); i++)
            {
                filteredVect.push_back(arrayData[filteredIndices[i]]);
            }

            filteredData.columns[j] = Array(filteredVect);
        }
        else if (holds_alternative<Array<string>>(columns[j]))
        {
            const auto &arrayData = get<Array<string>>(columns[j]);
            vector<string> filteredVect;
            for (size_t i = 0; i < filteredIndices.size(); i++)
            {
                filteredVect.push_back(arrayData[filteredIndices[i]]);
            }

            filteredData.columns[j] = Array(filteredVect);
        }
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
    // Implementation for merging two DataFrames based on a common column
}

// Concat method implementation
DataFrame DataFrame::concat(const DataFrame &other, bool axis) const
{
    // Implementation for concatenating two DataFrames along a specified axis
}

// Sort method implementation
void DataFrame::sort_values(size_t col, bool ascending)
{
    this->OutOfBounds(col);

    if (ascending)
    {
        visit([this, col](auto &array)
              {
        using T = decltype(array[0]);
        if constexpr (is_same_v<T, double>) {
            // Sort the array and maintain the indexLabels
            vector<size_t> indices(array.size());
            iota(indices.begin(), indices.end(), 0);
            sort(indices.begin(), indices.end(), [&array](size_t a, size_t b) {
                return array[a] < array[b];
            });
            // Rearrange indexLabels based on sorted indices
            vector<size_t> sortedIndexLabels;
            for (size_t index : indices) {
                sortedIndexLabels.push_back(indexLabels[index]);
            }
            indexLabels = sortedIndexLabels;
        } }, columns[col]);
    }
    else
    {
        visit([this, col](auto &array)
              {
        using T = decltype(array[0]);
        if constexpr (is_same_v<T, double>) {
            // Sort the array and maintain the indexLabels
            vector<size_t> indices(array.size());
            iota(indices.begin(), indices.end(), 0);
            sort(indices.begin(), indices.end(), [&array](size_t a, size_t b) {
                return array[a] > array[b];
            });
            // Rearrange indexLabels based on sorted indices
            vector<size_t> sortedIndexLabels;
            for (size_t index : indices) {
                sortedIndexLabels.push_back(indexLabels[index]);
            }
            indexLabels = sortedIndexLabels;
        } }, columns[col]);
    }
}

// Groupby method implementation
DataFrame DataFrame::groupby(const string &colLabel) const
{
    // Implementation for grouping the DataFrame by a specified column
}

// Apply method implementation
DataFrame DataFrame::apply(function<variant<double, string>(const variant<double, string> &)> func) const
{
    // DataFrame result = copy(); // Create a copy to store results
    // for (size_t col = 0; col < columns.size(); ++col)
    // {
    //     visit([this, &result, col, &func](auto &array)
    //           {
    //         for (size_t i = 0; i < array.size(); ++i) {
    //             result.columns[col].getArray()[i] = func(array[i]); // Apply the function to each element
    //         } }, columns[col]);
    // }
    // return result;
}