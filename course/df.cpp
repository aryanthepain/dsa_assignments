#include "include/df.h"

// Constructor
DataFrame::DataFrame(const vector<vector<double>> &inputData, const vector<string> &colLabels, const vector<string> &rowLabels)
    : columns(colLabels), index(rowLabels)
{
    for (const auto &col : inputData)
    {
        data.emplace_back(col);
    }
}

// Get the first n rows of the DataFrame
DataFrame DataFrame::head(size_t n)
{
    n = min(n, index.size()); // Ensure we don't exceed the number of rows
    vector<vector<double>> headData;
    for (size_t i = 0; i < n; ++i)
    {
        headData.push_back(data[i].getData());
    }
    return DataFrame(headData, columns, vector<string>(index.begin(), index.begin() + n));
}

// Get the last n rows of the DataFrame
DataFrame DataFrame::tail(size_t n)
{
    n = min(n, index.size()); // Ensure we don't exceed the number of rows
    vector<vector<double>> tailData;
    for (size_t i = index.size() - n; i < index.size(); ++i)
    {
        tailData.push_back(data[i].getData());
    }
    return DataFrame(tailData, columns, vector<string>(index.end() - n, index.end()));
}

// Get the shape of the DataFrame
pair<size_t, size_t> DataFrame::shape()
{
    return {index.size(), columns.size()};
}

// Get column names
vector<string> DataFrame::getColumns()
{
    return columns;
}

// Get index (row labels)
vector<string> DataFrame::getIndex()
{
    return index;
}

// Describe statistics of the DataFrame
map<string, double> DataFrame::describe()
{
    map<string, double> stats;
    for (size_t i = 0; i < columns.size(); ++i)
    {
        double mean = accumulate(data[i].getData().begin(), data[i].getData().end(), 0.0) / data[i].getData().size();
        stats[columns[i]] = mean; // You can add more statistics here
    }
    return stats;
}

// Print the DataFrame
void DataFrame::print() const
{
    // Print column names
    for (const auto &col : columns)
    {
        cout << setw(15) << col;
    }
    cout << endl;

    // Print data rows
    for (size_t i = 0; i < index.size(); ++i)
    {
        cout << setw(15) << index[i]; // Print row label
        for (const auto &array : data)
        {
            cout << setw(15) << array.getData()[i];
        }
        cout << endl;
    }
}

// Read CSV file and return a DataFrame
DataFrame DataFrame::read_csv(const string &filename)
{
    ifstream file(filename);
    string line;
    vector<vector<double>> inputData;
    vector<string> colLabels;
    vector<string> rowLabels;

    if (file.is_open())
    {
        // Read the first line for column labels
        if (getline(file, line))
        {
            stringstream ss(line);
            string col;
            while (getline(ss, col, ','))
            {
                colLabels.push_back(col);
            }
        }

        // Read the rest of the lines for data
        while (getline(file, line))
        {
            stringstream ss(line);
            vector<double> rowData;
            string value;
            rowLabels.push_back(to_string(inputData.size())); // Simple index as row label
            while (getline(ss, value, ','))
            {
                rowData.push_back(stod(value));
            }
            inputData.push_back(rowData);
        }
        file.close();
    }

    return DataFrame(inputData, colLabels, rowLabels);
}