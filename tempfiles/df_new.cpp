#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <optional>
using namespace std;

template <typename T>
class DataFrame
{
public:
    DataFrame(const vector<string> &columns);

    void addRow(const vector<T> &row);
    void removeRow(size_t index);
    vector<T> getRow(size_t index) const;
    vector<vector<T>> filter(function<bool(const vector<T> &)> predicate) const;

    // Aggregation functions
    T sum(size_t columnIndex) const;
    T mean(size_t columnIndex) const;
    T min(size_t columnIndex) const;
    T max(size_t columnIndex) const;
    size_t count(size_t columnIndex) const;

    // Handling missing data
    void fillna(const T &value);
    void dropna();

    // Merging functionality
    DataFrame<T> merge(const DataFrame<T> &other, const string &on_column) const;

    // Descriptive statistics
    void describe() const;

private:
    vector<string> m_columns;
    vector<vector<T>> m_data;
};

template <typename T>
DataFrame<T>::DataFrame(const vector<string> &columns)
    : m_columns(columns) {}

template <typename T>
void DataFrame<T>::addRow(const vector<T> &row)
{
    if (row.size() != m_columns.size())
    {
        throw invalid_argument("Row size does not match number of columns.");
    }
    m_data.push_back(row);
}

template <typename T>
void DataFrame<T>::removeRow(size_t index)
{
    if (index >= m_data.size())
    {
        throw out_of_range("Index out of range.");
    }
    m_data.erase(m_data.begin() + index);
}

template <typename T>
vector<T> DataFrame<T>::getRow(size_t index) const
{
    if (index >= m_data.size())
    {
        throw out_of_range("Index out of range.");
    }
    return m_data[index];
}

template <typename T>
vector<vector<T>> DataFrame<T>::filter(function<bool(const vector<T> &)> predicate) const
{
    vector<vector<T>> filteredData;
    for (const auto &row : m_data)
    {
        if (predicate(row))
        {
            filteredData.push_back(row);
        }
    }
    return filteredData;
}

template <typename T>
T DataFrame<T>::sum(size_t columnIndex) const
{
    if (columnIndex >= m_columns.size())
    {
        throw out_of_range("Column index out of range.");
    }
    T total = T();
    for (const auto &row : m_data)
    {
        total += row[columnIndex];
    }
    return total;
}

template <typename T>
T DataFrame<T>::mean(size_t columnIndex) const
{
    return sum(columnIndex) / count(columnIndex);
}

template <typename T>
T DataFrame<T>::min(size_t columnIndex) const
{
    if (columnIndex >= m_columns.size())
    {
        throw out_of_range("Column index out of range.");
    }
    T minimum = m_data[0][columnIndex];
    for (const auto &row : m_data)
    {
        if (row[columnIndex] < minimum)
        {
            minimum = row[columnIndex];
        }
    }
    return minimum;
}

template <typename T>
T DataFrame<T>::max(size_t columnIndex) const
{
    if (columnIndex >= m_columns.size())
    {
        throw out_of_range("Column index out of range.");
    }
    T maximum = m_data[0][columnIndex];
    for (const auto &row : m_data)
    {
        if (row[columnIndex] > maximum)
        {
            maximum = row[columnIndex];
        }
    }
    return maximum;
}

template <typename T>
size_t DataFrame<T>::count(size_t columnIndex) const
{
    if (columnIndex >= m_columns.size())
    {
        throw out_of_range("Column index out of range.");
    }
    return m_data.size();
}

template <typename T>
void DataFrame<T>::fillna(const T &value)
{
    for (auto &row : m_data)
    {
        for (auto &item : row)
        {
            if (isnan(item)) // Assuming T can be NaN
            {
                item = value;
            }
        }
    }
}

template <typename T>
void DataFrame<T>::dropna()
{
    m_data.erase(remove_if(m_data.begin(), m_data.end(),
                           [](const vector<T> &row)
                           {
                               return any_of(row.begin(), row.end(), [](const T &item)
                                             { return isnan(item); });
                           }),
                 m_data.end());
}

template <typename T>
DataFrame<T> DataFrame<T>::merge(const DataFrame<T> &other, const string &on_column) const
{
    // Implement merging logic based on the specified column
    DataFrame<T> mergedDataFrame(m_columns); // Create a new DataFrame for the result
    // Logic to merge based on the specified column
    return mergedDataFrame;
}

template <typename T>
void DataFrame<T>::describe() const
{
    cout << "Descriptive Statistics:\n";
    for (size_t i = 0; i < m_columns.size(); ++i)
    {
        cout << "Column: " << m_columns[i] << "\n";
        cout << "Count: " << count(i) << "\n";
        cout << "Mean: " << mean(i) << "\n";
        cout << "Min: " << min(i) << "\n";
        cout << "Max: " << max(i) << "\n";
        cout << "-------------------\n";
    }
}