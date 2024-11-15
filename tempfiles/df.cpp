#include "df.h"

// Constructor implementation
DataFrame::DataFrame(const vector<vector<variant<double, string>>> &inputData,
                     const vector<string> &colNames,
                     const vector<string> &rowLabels)
    : columnNames(colNames), indexLabels(rowLabels)
{
    if (!inputData.empty())
    {
        size_t numCols = inputData[0].size();
        columns.resize(numCols);

        // Initialize each column based on type
        for (size_t col = 0; col < numCols; ++col)
        {
            vector<double> doubleColumn;
            vector<string> stringColumn;

            for (const auto &row : inputData)
            {
                if (holds_alternative<double>(row[col]))
                {
                    doubleColumn.push_back(get<double>(row[col]));
                }
                else if (holds_alternative<string>(row[col]))
                {
                    stringColumn.push_back(get<string>(row[col]));
                }
            }

            // Create appropriate Array based on the column type
            if (!doubleColumn.empty())
            {
                columns[col] = Array<double>(doubleColumn);
            }
            else if (!stringColumn.empty())
            {
                columns[col] = Array<string>(stringColumn);
            }
        }
    }
}

// CSV constructor implementation
DataFrame::DataFrame(const string &csvFilePath)
{
    ifstream file(csvFilePath);
    string line;

    if (file.is_open())
    {
        // Read column names
        if (getline(file, line))
        {
            istringstream ss(line);
            string colName;
            while (getline(ss, colName, ','))
            {
                columnNames.push_back(colName);
            }
        }

        // Read data
        while (getline(file, line))
        {
            istringstream ss(line);
            vector<variant<double, string>> row;
            string value;

            while (getline(ss, value, ','))
            {
                // Attempt to convert to double, otherwise treat as string
                try
                {
                    row.push_back(stod(value));
                }
                catch (...)
                {
                    row.push_back(value);
                }
            }
            inputData.push_back(row);
        }
    }
}

// Method to print the DataFrame
void DataFrame::print() const
{
    cout << setw(10) << ""; // Space for row labels
    for (const auto &colName : columnNames)
    {
        cout << setw(10) << colName; // Adjust width as needed
    }
    cout << endl;

    for (size_t i = 0; i < indexLabels.size(); ++i)
    {
        cout << setw(10) << indexLabels[i]; // Print row label
        for (const auto &column : columns)
        {
            visit([i](const auto &array)
                  { cout << setw(10) << array[i]; }, column);
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

// Shape method implementation
pair<size_t, size_t> DataFrame::shape() const
{
    return {indexLabels.size(), columns.size()};
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

// Describe method implementation
void DataFrame::describe() const
{
    for (size_t i = 0; i < columns.size(); ++i)
    {
        visit([this, i](const auto &array)
              {
            cout << "Column: " << columnNames[i] << endl;
            cout << "Count: " << array.size() << endl;
            cout << "Mean: " << mean(i) << endl;
            cout << "Median: " << median(i) << endl;
            auto [q1, q2, q3] = quartiles(i);
            cout << "Quartiles: " << q1 << ", " << q2 << ", " << q3 << endl; }, columns[i]);
    }
}

// Statistical methods implementations
double DataFrame::sum(size_t col) const
{
    // Implementation for sum
}

double DataFrame::mean(size_t col) const
{
    // Implementation for mean
}

double DataFrame::median(size_t col) const
{
    if (col >= columns.size())
    {
        cout << "Column index out of bounds!" << endl;
        return 0.0;
    }
    return visit([](const auto &array)
                 {
        using T = decltype(array[0]);
        if constexpr (is_same_v<T, double>) {
            return array.median(); // Assuming Array has a median method
        } else {
            cerr << "Median operation is not valid for non-numeric columns." << endl;
            return 0.0;
        } }, columns[col]);
}

tuple<double, double, double> DataFrame::quartiles(size_t col) const
{
    if (col >= columns.size())
    {
        cout << "Column index out of bounds!" << endl;
        return {0.0, 0.0, 0.0};
    }
    return visit([](const auto &array)
                 {
        using T = decltype(array[0]);
        if constexpr (is_same_v<T, double>) {
            return array.quartiles(); // Assuming Array has a quartiles method
        } else {
            cerr << "Quartiles operation is not valid for non-numeric columns." << endl;
            return make_tuple(0.0, 0.0, 0.0);
        } }, columns[col]);
}

// Filter method implementation
DataFrame DataFrame::filter(size_t col, double threshold) const
{
    if (col >= columns.size())
    {
        cout << "Column index out of bounds!" << endl;
        return DataFrame({}, {}, {});
    }
    DataFrame filteredData({}, columnNames, indexLabels);
    visit([this, &filteredData, threshold](const auto &array)
          {
        using T = decltype(array[0]);
        if constexpr (is_same_v<T, double>) {
            for (size_t i = 0; i < array.size(); ++i) {
                if (array[i] > threshold) {
                    filteredData.indexLabels.push_back(indexLabels[i]);
                    // Add the corresponding row to filteredData
                }
            }
        } }, columns[col]);
    return filteredData;
}

// Copy method implementation
DataFrame DataFrame::copy() const
{
    return DataFrame(inputData, columnNames, indexLabels);
}

// Missing value methods implementation
vector<bool> DataFrame::is_na(size_t col) const
{
    vector<bool> missingValues;
    if (col >= columns.size())
    {
        cout << "Column index out of bounds!" << endl;
        return missingValues;
    }
    visit([&missingValues](const auto &array)
          {
        for (const auto& value : array) {
            missingValues.push_back(value == variant<double, string>{}); // Adjust based on how missing values are represented
        } }, columns[col]);
    return missingValues;
}

void DataFrame::fillna(const variant<double, string> &value)
{
    for (size_t col = 0; col < columns.size(); ++col)
    {
        visit([this, &value](auto &array)
              {
            for (auto& elem : array) {
                if (elem == std ::variant<double, string>{}) { // Adjust based on how missing values are represented
                    elem = value;
                }
            } }, columns[col]);
    }
}

void DataFrame::dropna()
{
    // Implementation to remove rows or columns with missing values
}

// Drop method implementation
void DataFrame::drop(size_t col)
{
    if (col >= columns.size())
    {
        cout << "Column index out of bounds!" << endl;
        return;
    }
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

// Indexing methods implementation
variant<double, string> DataFrame::iloc(size_t row, size_t col) const
{
    if (row >= indexLabels.size() || col >= columns.size())
    {
        cout << "Index out of bounds!" << endl;
        return {};
    }
    return visit([row](const auto &array)
                 {
                     return array[row]; // Return the element at the specified row and column
                 },
                 columns[col]);
}

variant<double, string> DataFrame::loc(const string &rowLabel, const string &colLabel) const
{
    auto it = find(indexLabels.begin(), indexLabels.end(), rowLabel);
    if (it == indexLabels.end())
    {
        cout << "Row label not found!" << endl;
        return {};
    }
    size_t rowIndex = distance(indexLabels.begin(), it);
    auto colIt = find(columnNames.begin(), columnNames.end(), colLabel);
    if (colIt == columnNames.end())
    {
        cout << "Column label not found!" << endl;
        return {};
    }
    size_t colIndex = distance(columnNames.begin(), colIt);
    return iloc(rowIndex, colIndex);
}

// Sort method implementation
void DataFrame::sort_values(size_t col)
{
    if (col >= columns.size())
    {
        cout << "Column index out of bounds!" << endl;
        return;
    }
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
            vector<string> sortedIndexLabels;
            for (size_t index : indices) {
                sortedIndexLabels.push_back(indexLabels[index]);
            }
            indexLabels = sortedIndexLabels;
        } }, columns[col]);
}

// Groupby method implementation
DataFrame DataFrame::groupby(const string &colLabel) const
{
    // Implementation for grouping the DataFrame by a specified column
}

// Apply method implementation
DataFrame DataFrame::apply(function<variant<double, string>(const variant<double, string> &)> func) const
{
    DataFrame result = copy(); // Create a copy to store results
    for (size_t col = 0; col < columns.size(); ++col)
    {
        visit([this, &result, col, &func](auto &array)
              {
            for (size_t i = 0; i < array.size(); ++i) {
                result.columns[col].getArray()[i] = func(array[i]); // Apply the function to each element
            } }, columns[col]);
    }
    return result;
}

// Unique method implementation
vector<string> DataFrame::unique(size_t col) const
{
    vector<string> uniqueValues;
    if (col >= columns.size())
    {
        cout << "Column index out of bounds!" << endl;
        return uniqueValues;
    }
    visit([&uniqueValues](const auto &array)
          {
        set<string> uniqueSet;
        for (const auto& value : array) {
            uniqueSet.insert(value);
        }
 uniqueValues.assign(uniqueSet.begin(), uniqueSet.end()); }, columns[col]);
    return uniqueValues;
}

// Nunique method implementation
size_t DataFrame::nunique(size_t col) const
{
    return unique(col).size();
}

// Sample method implementation
DataFrame DataFrame::sample(size_t sampleSize) const
{
    DataFrame sampledData({}, columnNames, {});
    vector<size_t> indices(indexLabels.size());
    iota(indices.begin(), indices.end(), 0);
    random_shuffle(indices.begin(), indices.end());
    for (size_t i = 0; i < min(sampleSize, indices.size()); ++i)
    {
        sampledData.indexLabels.push_back(indexLabels[indices[i]]);
        // Add the corresponding row to sampledData
    }
    return sampledData;
}

// Export to CSV method implementation
void DataFrame::to_csv(const string &filePath) const
{
    ofstream file(filePath);
    if (file.is_open())
    {
        // Write column names
        for (const auto &colName : columnNames)
        {
            file << colName << ",";
        }
        file << "\n";

        // Write data
        for (size_t i = 0; i < indexLabels.size(); ++i)
        {
            file << indexLabels[i] << ",";
            for (const auto &column : columns)
            {
                visit([i](const auto &array)
                      { file << array[i] << ","; }, column);
            }
            file << "\n";
        }
    }
}

// Plotting methods (placeholders)
void DataFrame::plot() const
{
    // Implementation for basic plotting
}

void DataFrame::hist(size_t col) const
{
    // Implementation for generating a histogram
}

void DataFrame::boxplot(size_t col) const
{
    // Implementation for creating a box plot
}