#include "include/df.h"

DataFrame::DataFrame(const std::vector<std::vector<std::variant<double, std::string>>> &inputData,
                     const std::vector<std::string> &colNames,
                     const std::vector<std::string> &rowLabels)
    : columnNames(colNames), indexLabels(rowLabels), columns(colNames.size()) // Initialize columns with the number of columns
{
    if (!inputData.empty())
    {
        size_t numCols = inputData[0].size();

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

// Print function
void DataFrame::print() const
{
    // Print column names
    std::cout << std::setw(10) << ""; // Space for row labels
    for (const auto &colName : columnNames)
    {
        std::cout << std::setw(10) << colName; // Adjust width as needed
    }
    std::cout << std::endl;

    // Print data rows
    for (size_t i = 0; i < indexLabels.size(); ++i)
    {
        std::cout << std::setw(10) << indexLabels[i]; // Print row label
        for (size_t col = 0; col < columns.size(); ++col)
        {
            // Use std::visit to handle the variant type
            std::visit([i](auto &&arg)
                       {
                           std::cout << std::setw(10) << arg[i]; // Access the i-th element of the column
                       },
                       columns[col]);
        }
        std::cout << std::endl; // New line after each row
    }
}