#include "df.h"

// Constructor implementation
DataFrame::DataFrame(const std::vector<std::vector<std::variant<double, std::string>>> &inputData,
                     const std::vector<std::string> &colNames,
                     const std::vector<std::string> &rowLabels)
    : columnNames(colNames), indexLabels(rowLabels)
{
    if (!inputData.empty())
    {
        size_t numCols = inputData[0].size();
        columns.resize(numCols);

        // Initialize each column based on type
        for (size_t col = 0; col < numCols; ++col)
        {
            std::vector<double> doubleColumn;
            std::vector<std::string> stringColumn;

            for (const auto &row : inputData)
            {
                if (std::holds_alternative<double>(row[col]))
                {
                    doubleColumn.push_back(std::get<double>(row[col]));
                }
                else if (std::holds_alternative<std::string>(row[col]))
                {
                    stringColumn.push_back(std::get<std::string>(row[col]));
                }
            }

            // Create appropriate Array based on the column type
            if (!doubleColumn.empty())
            {
                columns[col] = Array<double>(doubleColumn);
            }
            else if (!stringColumn.empty())
            {
                columns[col] = Array<std::string>(stringColumn);
            }
        }
    }
}

// CSV constructor implementation
DataFrame::DataFrame(const std::string &csvFilePath)
{
    std::ifstream file(csvFilePath);
    std::string line;

    if (file.is_open())
    {
        // Read column names
        if (std::getline(file, line))
        {
            std::istringstream ss(line);
            std::string colName;
            while (std::getline(ss, colName, ','))
            {
                columnNames.push_back(colName);
            }
        }

        // Read data
        while (std::getline(file, line))
        {
            std::istringstream ss(line);
            std::vector<std::variant<double, std::string>> row;
            std::string value;

            while (std::getline(ss, value, ','))
            {
                // Attempt to convert to double, otherwise treat as string
                try
                {
                    row.push_back(std::stod(value));
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
    std::cout << std::setw(10) << ""; // Space for row labels
    for (const auto &colName : columnNames)
    {
        std::cout << std::setw(10) << colName; // Adjust width as needed
    }
    std::cout << std::endl;

    for (size_t i = 0; i < indexLabels.size(); ++i)
    {
        std::cout << std::setw(10) << indexLabels[i]; // Print row label
        for (const auto &column : columns)
        {
            std::visit([i](const auto &array)
                       { std::cout << std::setw(10) << array[i]; }, column);
        }
        std::cout << std::endl; // New line after each row
    }
}

// Head method implementation
void DataFrame::head(size_t n) const
{
    for (size_t i = 0; i < std::min(n, indexLabels.size()); ++i)
    {
        std::cout << indexLabels[i] << ": ";
        for (const auto &column : columns)
        {
            std::visit([i](const auto &array)
                       { std::cout << array[i] << " "; }, column);
        }
        std::cout << std::endl;
    }
}

// Tail method implementation
void DataFrame::tail(size_t n) const
{
    for (size_t i = std::max(static_cast<int>(indexLabels.size()) - static_cast<int>(n), 0); i < indexLabels.size(); ++i)
    {
        std::cout << indexLabels[i] << ": ";
        for (const auto &column : columns)
        {
            std::visit([i](const auto &array)
                       { std::cout << array[i] << " "; }, column);
        }
        std::cout << std::endl;
    }
}

// Shape method implementation
std::pair<size_t, size_t> DataFrame::shape() const
{
    return {indexLabels.size(), columns.size()};
}

// Getters for columns and index
std::vector<std::string> DataFrame::getColumns() const
{
    return columnNames;
}

std::vector<std::string> DataFrame::getIndex() const
{
    return indexLabels;
}

// Describe method implementation
void DataFrame::describe() const
{
    for (size_t i = 0; i < columns.size(); ++i)
    {
        std::visit([this, i](const auto &array)
                   {
            std::cout << "Column: " << columnNames[i] << std::endl;
            std::cout << "Count: " << array.size() << std::endl;
            std::cout << "Mean: " << mean(i) << std::endl;
            std::cout << "Median: " << median(i) << std::endl;
            auto [q1, q2, q3] = quartiles(i);
            std::cout << "Quartiles: " << q1 << ", " << q2 << ", " << q3 << std::endl; }, columns[i]);
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
        std::cout << "Column index out of bounds!" << std::endl;
        return 0.0;
    }
    return std::visit([](const auto &array)
                      {
        using T = decltype(array[0]);
        if constexpr (std::is_same_v<T, double>) {
            return array.median(); // Assuming Array has a median method
        } else {
            std::cerr << "Median operation is not valid for non-numeric columns." << std::endl;
            return 0.0;
        } }, columns[col]);
}

std::tuple<double, double, double> DataFrame::quartiles(size_t col) const
{
    if (col >= columns.size())
    {
        std::cout << "Column index out of bounds!" << std::endl;
        return {0.0, 0.0, 0.0};
    }
    return std::visit([](const auto &array)
                      {
        using T = decltype(array[0]);
        if constexpr (std::is_same_v<T, double>) {
            return array.quartiles(); // Assuming Array has a quartiles method
        } else {
            std::cerr << "Quartiles operation is not valid for non-numeric columns." << std::endl;
            return std::make_tuple(0.0, 0.0, 0.0);
        } }, columns[col]);
}

// Filter method implementation
DataFrame DataFrame::filter(size_t col, double threshold) const
{
    if (col >= columns.size())
    {
        std::cout << "Column index out of bounds!" << std::endl;
        return DataFrame({}, {}, {});
    }
    DataFrame filteredData({}, columnNames, indexLabels);
    std::visit([this, &filteredData, threshold](const auto &array)
               {
        using T = decltype(array[0]);
        if constexpr (std::is_same_v<T, double>) {
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
std::vector<bool> DataFrame::is_na(size_t col) const
{
    std::vector<bool> missingValues;
    if (col >= columns.size())
    {
        std::cout << "Column index out of bounds!" << std::endl;
        return missingValues;
    }
    std::visit([&missingValues](const auto &array)
               {
        for (const auto& value : array) {
            missingValues.push_back(value == std::variant<double, std::string>{}); // Adjust based on how missing values are represented
        } }, columns[col]);
    return missingValues;
}

void DataFrame::fillna(const std::variant<double, std::string> &value)
{
    for (size_t col = 0; col < columns.size(); ++col)
    {
        std::visit([this, &value](auto &array)
                   {
            for (auto& elem : array) {
                if (elem == std ::variant<double, std::string>{}) { // Adjust based on how missing values are represented
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
        std::cout << "Column index out of bounds!" << std::endl;
        return;
    }
    columns.erase(columns.begin() + col);
    columnNames.erase(columnNames.begin() + col);
}

// Merge method implementation
DataFrame DataFrame::merge(const DataFrame &other, const std::string &onColumn) const
{
    // Implementation for merging two DataFrames based on a common column
}

// Concat method implementation
DataFrame DataFrame::concat(const DataFrame &other, bool axis) const
{
    // Implementation for concatenating two DataFrames along a specified axis
}

// Indexing methods implementation
std::variant<double, std::string> DataFrame::iloc(size_t row, size_t col) const
{
    if (row >= indexLabels.size() || col >= columns.size())
    {
        std::cout << "Index out of bounds!" << std::endl;
        return {};
    }
    return std::visit([row](const auto &array)
                      {
                          return array[row]; // Return the element at the specified row and column
                      },
                      columns[col]);
}

std::variant<double, std::string> DataFrame::loc(const std::string &rowLabel, const std::string &colLabel) const
{
    auto it = std::find(indexLabels.begin(), indexLabels.end(), rowLabel);
    if (it == indexLabels.end())
    {
        std::cout << "Row label not found!" << std::endl;
        return {};
    }
    size_t rowIndex = std::distance(indexLabels.begin(), it);
    auto colIt = std::find(columnNames.begin(), columnNames.end(), colLabel);
    if (colIt == columnNames.end())
    {
        std::cout << "Column label not found!" << std::endl;
        return {};
    }
    size_t colIndex = std::distance(columnNames.begin(), colIt);
    return iloc(rowIndex, colIndex);
}

// Sort method implementation
void DataFrame::sort_values(size_t col)
{
    if (col >= columns.size())
    {
        std::cout << "Column index out of bounds!" << std::endl;
        return;
    }
    std::visit([this, col](auto &array)
               {
        using T = decltype(array[0]);
        if constexpr (std::is_same_v<T, double>) {
            // Sort the array and maintain the indexLabels
            std::vector<size_t> indices(array.size());
            std::iota(indices.begin(), indices.end(), 0);
            std::sort(indices.begin(), indices.end(), [&array](size_t a, size_t b) {
                return array[a] < array[b];
            });
            // Rearrange indexLabels based on sorted indices
            std::vector<std::string> sortedIndexLabels;
            for (size_t index : indices) {
                sortedIndexLabels.push_back(indexLabels[index]);
            }
            indexLabels = sortedIndexLabels;
        } }, columns[col]);
}

// Groupby method implementation
DataFrame DataFrame::groupby(const std::string &colLabel) const
{
    // Implementation for grouping the DataFrame by a specified column
}

// Apply method implementation
DataFrame DataFrame::apply(std::function<std::variant<double, std::string>(const std::variant<double, std::string> &)> func) const
{
    DataFrame result = copy(); // Create a copy to store results
    for (size_t col = 0; col < columns.size(); ++col)
    {
        std::visit([this, &result, col, &func](auto &array)
                   {
            for (size_t i = 0; i < array.size(); ++i) {
                result.columns[col].getArray()[i] = func(array[i]); // Apply the function to each element
            } }, columns[col]);
    }
    return result;
}

// Unique method implementation
std::vector<std::string> DataFrame::unique(size_t col) const
{
    std::vector<std::string> uniqueValues;
    if (col >= columns.size())
    {
        std::cout << "Column index out of bounds!" << std::endl;
        return uniqueValues;
    }
    std::visit([&uniqueValues](const auto &array)
               {
        std::set<std::string> uniqueSet;
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
    std::vector<size_t> indices(indexLabels.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::random_shuffle(indices.begin(), indices.end());
    for (size_t i = 0; i < std::min(sampleSize, indices.size()); ++i)
    {
        sampledData.indexLabels.push_back(indexLabels[indices[i]]);
        // Add the corresponding row to sampledData
    }
    return sampledData;
}

// Export to CSV method implementation
void DataFrame::to_csv(const std::string &filePath) const
{
    std::ofstream file(filePath);
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
                std::visit([i](const auto &array)
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