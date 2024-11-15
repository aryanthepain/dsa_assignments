#include "DataFrame.h"

// Constructor
DataFrame::DataFrame(const vector<vector<double>> &inputData,
                     const vector<string> &colLabels,
                     const vector<string> &rowLabels)
    : data(inputData), columns(colLabels), index(rowLabels) {}

// Constructor to load from CSV
DataFrame::DataFrame(const string &filename)
{
    ifstream file(filename);
    string line;
    if (file.is_open())
    {
        // Read column headers
        getline(file, line);
        stringstream ss(line);
        string col;
        while (getline(ss, col, ','))
        {
            columns.push_back(col);
        }

        // Read data
        while (getline(file, line))
        {
            vector<double> row;
            stringstream rowStream(line);
            string value;
            while (getline(rowStream, value, ','))
            {
                row.push_back(stod(value));
            }
            data.push_back(row);
        }
        file.close();
    }
}

// Print the first n rows
void DataFrame::head(size_t n)
{
    for (size_t i = 0; i < n && i < data.size(); ++i)
    {
        for (const auto &val : data[i])
        {
            cout << setw(10) << val << " ";
        }
        cout << endl;
    }
}

// Calculate the sum of a column
double DataFrame::sum(size_t columnIndex)
{
    double total = 0;
    for (const auto &row : data)
    {
        total += row[columnIndex];
    }
    return total;
}

// Calculate the mean of a column
double DataFrame::mean(size_t columnIndex)
{
    return sum(columnIndex) / data.size();
}

// Calculate the median of a column
double DataFrame::median(size_t columnIndex)
{
    vector<double> columnData;
    for (const auto &row : data)
    {
        columnData.push_back(row[columnIndex]);
    }
    sort(columnData.begin(), columnData.end());
    size_t mid = columnData.size() / 2;
    return (columnData.size() % 2 == 0) ? (columnData[mid - 1] + columnData[mid]) / 2 : columnData[mid];
}

// Filter rows based on a condition
void DataFrame::filter(const string &columnName, double threshold)
{
    size_t columnIndex = distance(columns.begin(), find(columns.begin(), columns.end(), columnName));
    for (const auto &row : data)
    {
        if (row[columnIndex] > threshold)
        {
            for (const auto &val : row)
            {
                cout << setw(10) << val << " ";
            }
            cout << endl;
        }
    }
}

// Print the DataFrame
void DataFrame::print()
{
    for (const auto &col : columns)
    {
        cout << setw(10) << col << " ";
    }
    cout << endl;
    for (const auto &row : data)
    {
        for (const auto &val : row)
        {
            cout << setw(10) << val << " ";
        }
        cout << endl;
    }
}