#include "../include/df.h"

DataFrame::DataFrame(const vector<vector<variant<double, string>>> &inputData,
                     const vector<string> &colNames,
                     const vector<string> &rowLabels)
    : columnNames(colNames), indexLabels(rowLabels), columns(colNames.size()) // Initialize columns with the number of columns
{
    if (!inputData.empty())
    {
        size_t numCols = inputData[0].size();

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
        vector<vector<variant<double, string>>> inputData;
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

        // Initialize columns based on input data
        size_t numCols = columnNames.size();
        columns.resize(numCols);

        // Populate each column
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

        // Optionally, you can initialize indexLabels if needed
        indexLabels.resize(inputData.size());
        for (size_t i = 0; i < inputData.size(); ++i)
        {
            indexLabels[i] = to_string(i); // or any other logic for row labels
        }
    }
}