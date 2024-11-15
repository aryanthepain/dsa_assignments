#include "DataFrame.h"

// Constructor
template <typename T>
DataFrame<T>::DataFrame(const vector<vector<T>> &inputData,
                        const vector<string> &colLabels,
                        const vector<string> &rowLabels)
    : data(inputData), columns(colLabels), index(rowLabels) {}

// Constructor to load from CSV
template <typename T>
DataFrame<T>::DataFrame(const string &filename)
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
            vector<T> row;
            stringstream rowStream(line);
            string value;
            while (getline(rowStream, value, ','))
            {
                if constexpr (is_same<T, double>::value)
                {
                    row.push_back(stod(value)); // Convert to double
                }
                else if constexpr (is_same<T, int>::value)
                {
                    row.push_back(stoi(value)); // Convert to int
                }
                else
                {
                    row.push_back(value); // For string or other types
                }
            }
            data.push_back(row);
        }
        file.close();
    }
}

// Print the first n rows
template <typename T>
void DataFrame<T>::head(size_t n)
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
template <typename T>
T DataFrame<T>::sum(size_t columnIndex)
{
    T total = T(); // Initialize total to the default value of T
    for (const auto &row : data)
    {
        total += row[columnIndex];
    }
    return total;
}

// Calculate the mean of a column
template <typename T>
double DataFrame<T>::mean(size_t columnIndex)
{
    return static_cast<double>(sum(columnIndex)) / data.size();
}

// Calculate the median of a column
template <typename T>
double DataFrame<T>::median(size_t columnIndex)
{
    vector<T> columnData;
    for (const auto &row : data)
    {
        columnData.push_back(row[columnIndex]);
    }
    sort(columnData.begin(), columnData.end());
    size_t mid = columnData.size() / 2;
    return (columnData.size() % 2 == 0) ? (static_cast<double>(columnData[mid - 1]) + static_cast<double>(columnData[mid])) / 2 : static_cast<double>(columnData[mid]);
}

// Filter rows based on a condition
template <typename T>
void DataFrame<T>::filter(const string &columnName, T threshold)
{
    size_t columnIndex = find(columns.begin(), columns.end(), columnName) - columns.begin();
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
template <typename T>
void DataFrame<T>::print()
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

// Get the shape of the DataFrame
template <typename T>
pair<size_t, size_t> DataFrame<T>::shape()
{
    return {data.size(), columns.size()};
}

// Get the column names
template <typename T>
vector<string> DataFrame<T>::getColumns()
{
    return columns;
}

// Get the index (row labels)
template <typename T>
vector<string> DataFrame<T>::getIndex()
{
    return index;
}

// Describe the DataFrame (basic statistics)
template <typename T>
void DataFrame<T>::describe()
{
    for (size_t i = 0; i < columns.size(); ++i)
    {
        cout << "Column: " << columns[i] << endl;
        cout << "Sum: " << sum(i) << endl;
        cout << "Mean: " << mean(i) << endl;
        cout << "Median: " << median(i) << endl;
        cout << endl;
    }
}

// Explicit template instantiation for common types
template class DataFrame<int>;
template class DataFrame<double>;
template class DataFrame<string>;

// Constructor for generic DataFrame
template <typename T>
DataFrame<T>::DataFrame(const vector<vector<T>> &inputData,
                        const vector<string> &colLabels,
                        const vector<string> &rowLabels)
    : data(inputData), columns(colLabels), index(rowLabels) {}

// Specialization constructor for Array
DataFrame<Array>::DataFrame(const vector<vector<Array>> &inputData,
                            const vector<string> &colLabels,
                            const vector<string> &rowLabels)
    : data(inputData), columns(colLabels), index(rowLabels) {}

// Print the first n rows for Array DataFrame
void DataFrame<Array>::head(size_t n)
{
    for (size_t i = 0; i < n && i < data.size(); ++i)
    {
        for (const auto &val : data[i])
        {
            val.print(); // Assuming Array has a print function
        }
        cout << endl;
    }
}

// Calculate the sum of a column for Array DataFrame
Array DataFrame<Array>::sum(size_t columnIndex)
{
    Array total = Array::zeros(data[0][columnIndex].getData().size());
    for (const auto &row : data)
    {
        Array temp = row[columnIndex];
        total = total.add(temp); // Assuming add method exists in Array
    }
    return total;
}

// Calculate the mean of a column for Array DataFrame
double DataFrame<Array>::mean(size_t columnIndex)
{
    Array columnSum = sum(columnIndex);
    return columnSum.mean(); // Assuming mean method exists in Array
}

// Print the DataFrame for Array DataFrame
void DataFrame<Array>::print()
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
            val.print(); // Assuming Array has a print function
        }
        cout << endl;
    }
}

// Other methods like tail, shape, getColumns, getIndex, describe can be implemented similarly.
#include "DataFrame.h"

// Constructor for generic DataFrame
template <typename T>
DataFrame<T>::DataFrame(const vector<vector<T>> &inputData,
                        const vector<string> &colLabels,
                        const vector<string> &rowLabels)
    : data(inputData), columns(colLabels), index(rowLabels) {}

// Specialization constructor for Array
DataFrame<Array>::DataFrame(const vector<vector<Array>> &inputData,
                            const vector<string> &colLabels,
                            const vector<string> &rowLabels)
    : data(inputData), columns(colLabels), index(rowLabels) {}

// Print the first n rows for Array DataFrame
void DataFrame<Array>::head(size_t n)
{
    for (size_t i = 0; i < n && i < data.size(); ++i)
    {
        for (const auto &val : data[i])
        {
            val.print(); // Assuming Array has a print function
        }
        cout << endl;
    }
}

// Calculate the sum of a column for Array DataFrame
Array DataFrame<Array>::sum(size_t columnIndex)
{
    Array total = Array::zeros(data[0][columnIndex].getData().size());
    for (const auto &row : data)
    {
        Array temp = row[columnIndex];
        total = total.add(temp); // Assuming add method exists in Array
    }
    return total;
}

// Calculate the mean of a column for Array DataFrame
double DataFrame<Array>::mean(size_t columnIndex)
{
    Array columnSum = sum(columnIndex);
    return columnSum.mean(); // Assuming mean method exists in Array
}

// Print the DataFrame for Array DataFrame
void DataFrame<Array>::print()
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
            val.print(); // Assuming Array has a print function
        }
        cout << endl;
    }
}

// Other methods like tail, shape, getColumns, getIndex, describe can be implemented similarly.
#include "DataFrame.h"

// Constructor for generic DataFrame
template <typename T>
DataFrame<T>::DataFrame(const vector<vector<T>> &inputData,
                        const vector<string> &colLabels,
                        const vector<string> &rowLabels)
    : data(inputData), columns(colLabels), index(rowLabels) {}

// Specialization constructor for Array
DataFrame<Array>::DataFrame(const vector<vector<Array>> &inputData,
                            const vector<string> &colLabels,
                            const vector<string> &rowLabels)
    : data(inputData), columns(colLabels), index(rowLabels) {}

// Print the first n rows for Array DataFrame
void DataFrame<Array>::head(size_t n)
{
    for (size_t i = 0; i < n && i < data.size(); ++i)
    {
        for (const auto &val : data[i])
        {
            val.print(); // Assuming Array has a print function
        }
        cout << endl;
    }
}

// Calculate the sum of a column for Array DataFrame
Array DataFrame<Array>::sum(size_t columnIndex)
{
    Array total = Array::zeros(data[0][columnIndex].getData().size());
    for (const auto &row : data)
    {
        Array temp = row[columnIndex];
        total = total.add(temp); // Assuming add method exists in Array
    }
    return total;
}

// Calculate the mean of a column for Array DataFrame
double DataFrame<Array>::mean(size_t columnIndex)
{
    Array columnSum = sum(columnIndex);
    return columnSum.mean(); // Assuming mean method exists in Array
}

// Print the DataFrame for Array DataFrame
void DataFrame<Array>::print()
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
            val.print(); // Assuming Array has a print function
        }
        cout << endl;
    }
}

// Other methods like tail, shape, getColumns, getIndex, describe can be implemented similarly.
