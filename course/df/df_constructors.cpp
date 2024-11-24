#include "../include/df.h"

DataFrame::DataFrame(const vector<vector<variant<double, string>>> &inputData,
                     const vector<string> &colNames)
    : columnNames(colNames), columns(colNames.size()) // Initialize columns with the number of columns
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

        // Automatically assign index labels as "1", "2", "3", ...
        indexLabels.resize(inputData.size());
        for (size_t i = 0; i < inputData.size(); ++i)
        {
            indexLabels[i] = i; // Start indexing from 1
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

        // Automatically assign index labels as 1, 2, 3, ...
        indexLabels.resize(inputData.size());
        for (size_t i = 0; i < inputData.size(); ++i)
        {
            indexLabels[i] = i; // Start indexing from 1
        }
    }
}

void DataFrame::addColumn(const string &name, const ColumnType &data)
{
    columnNames.push_back(name);
    columns.push_back(data);
}

void DataFrame::addIndexLabel(size_t label)
{
    indexLabels.push_back(label);
}