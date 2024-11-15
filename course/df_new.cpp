#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <optional>

template <typename T>
class DataFrame
{
public:
    DataFrame(const std::vector<std::string> &columns);

    void addRow(const std::vector<T> &row);
    void removeRow(size_t index);
    std::vector<T> getRow(size_t index) const;
    std::vector<T> filter(std::function<bool(const T &)> predicate) const;

    // Aggregation functions
    T sum(size_t columnIndex) const;
    T mean(size_t columnIndex) const;
    T min(size_t columnIndex) const;
    T max(size_t columnIndex) const;
    size_t count(size_t columnIndex) const;

    // Handling missing data
    void fillna(const T &value);
    void dropna();

    // GroupBy functionality
    // Implement a GroupBy class or method

    // Merging functionality
    DataFrame<T> merge(const DataFrame<T> &other, const std::string &on_column);

    // Descriptive statistics
    void describe() const;

private:
    std::vector<std::string> m_columns;
    std::vector<std::vector<T>> m_data;
};

template <typename T>
class DataFrame
{
public:
    DataFrame(const std::vector<std::string> &columns);

    void addRow(const std::vector<T> &row);
    void removeRow(size_t index);
    std::vector<T> getRow(size_t index) const;
    std::vector<T> filter(std::function<bool(const T &)> predicate) const;

    // Aggregation functions
    T sum(size_t columnIndex) const;
    T mean(size_t columnIndex) const;
    T min(size_t columnIndex) const;
    T max(size_t columnIndex) const;
    size_t count(size_t columnIndex) const;

    // Handling missing data
    void fillna(const T &value);
    void dropna();

    // GroupBy functionality
    // Implement a GroupBy class or method

    // Merging functionality
    DataFrame<T> merge(const DataFrame<T> &other, const std::string &on_column);

    // Descriptive statistics
    void describe() const;

private:
    std::vector<std::string> m_columns;
    std::vector<std::vector<T>> m_data;
};

template <typename T>
class DataFrame
{
public:
    DataFrame(const std::vector<std::string> &columns);

    void addRow(const std::vector<T> &row);
    void removeRow(size_t index);
    std::vector<T> getRow(size_t index) const;
    std::vector<T> filter(std::function<bool(const T &)> predicate) const;

    // Aggregation functions
    T sum(size_t columnIndex) const;
    T mean(size_t columnIndex) const;
    T min(size_t columnIndex) const;
    T max(size_t columnIndex) const;
    size_t count(size_t columnIndex) const;

    // Handling missing data
    void fillna(const T &value);
    void dropna();

    // GroupBy functionality
    // Implement a GroupBy class or method

    // Merging functionality
    DataFrame<T> merge(const DataFrame<T> &other, const std::string &on_column);

    // Descriptive statistics
    void describe() const;

private:
    std::vector<std::string> m_columns;
    std::vector<std::vector<T>> m_data;
};
template <typename T>
DataFrame<T>::DataFrame(const std::vector<std::string> &columns)
    : m_columns(columns) {}

template <typename T>
void DataFrame<T>::addRow(const std::vector<T> &row)
{
    if (row.size() != m_columns.size())
    {
        throw std::invalid_argument("Row size does not match number of columns.");
    }
    m_data.push_back(row);
}

template <typename T>
void DataFrame<T>::removeRow(size_t index)
{
    if (index >= m_data.size())
    {
        throw std::out_of_range("Index out of range.");
    }
    m_data.erase(m_data.begin() + index);
}

template <typename T>
std::vector<T> DataFrame<T>::getRow(size_t index) const
{
    if (index >= m_data.size())
    {
        throw std::out_of_range("Index out of range.");
    }
    return m_data[index];
}
template <typename T>
DataFrame<T>::DataFrame(const std::vector<std::string> &columns)
    : m_columns(columns) {}

template <typename T>
void DataFrame<T>::addRow(const std::vector<T> &row)
{
    if (row.size() != m_columns.size())
    {
        throw std::invalid_argument("Row size does not match number of columns.");
    }
    m_data.push_back(row);
}

template <typename T>
void DataFrame<T>::removeRow(size_t index)
{
    if (index >= m_data.size())
    {
        throw std::out_of_range("Index out of range.");
    }
    m_data.erase(m_data.begin() + index);
}

template <typename T>
std::vector<T> DataFrame<T>::getRow(size_t index) const
{
    if (index >= m_data.size())
    {
        throw std::out_of_range("Index out of range.");
    }
    return m_data[index];
}
template <typename T>
std::vector<T> DataFrame<T>::filter(std::function<bool(const T &)> predicate) const
{
    std::vector<T> filteredData;
    for (const auto &row : m_data)
    {
        for (const auto &item : row)
        {
            if (predicate(item))
            {
                filteredData.push_back(item);
            }
        }
    }
    return filteredData;
}
template <typename T>
std::vector<T> DataFrame<T>::filter(std::function<bool(const T &)> predicate) const
{
    std::vector<T> filteredData;
    for (const auto &row : m_data)
    {
        for (const auto &item : row)
        {
            if (predicate(item))
            {
                filteredData.push_back(item);
            }
        }
    }
    return filteredData;
}
template <typename T>
T DataFrame<T>::sum(size_t columnIndex) const
{
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
    T total = sum(columnIndex);
    return total / count(columnIndex);
}

template <typename T>
T DataFrame<T>::min(size_t columnIndex) const
{
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
    return m_data.size();
}
template <typename T>
T DataFrame<T>::sum(size_t columnIndex) const
{
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
    T total = sum(columnIndex);
    return total / count(columnIndex);
}

template <typename T>
T DataFrame<T>::min(size_t columnIndex) const
{
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
    return m_data.size();
}
template <typename T>
T DataFrame<T>::sum(size_t columnIndex) const
{
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
    T total = sum(columnIndex);
    return total / count(columnIndex);
}

template <typename T>
T DataFrame<T>::min(size_t columnIndex) const
{
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
    return m_data.size();
}
template <typename T>
void DataFrame<T>::fillna(const T &value)
{
    for (auto &row : m_data)
    {
        for (auto &item : row)
        {
            if (std::isnan(item))
            { // Assuming T can be NaN
                item = value;
            }
        }
    }
}

template <typename T>
void DataFrame<T>::dropna()
{
    m_data.erase(std::remove_if(m_data.begin(), m_data.end(),
                                [](const std::vector<T> &row)
                                {
                                    return std::any_of(row.begin(), row.end(), [](const T &item)
                                                       { return std::isnan(item); });
                                }),
                 m_data.end());
}
template <typename T>
void DataFrame<T>::fillna(const T &value)
{
    for (auto &row : m_data)
    {
        for (auto &item : row)
        {
            if (std::isnan(item))
            { // Assuming T can be NaN
                item = value;
            }
        }
    }
}

template <typename T>
void DataFrame<T>::dropna()
{
    m_data.erase(std::remove_if(m_data.begin(), m_data.end(),
                                [](const std::vector<T> &row)
                                {
                                    return std::any_of(row.begin(), row.end(), [](const T &item)
                                                       { return std::isnan(item); });
                                }),
                 m_data.end());
}
template <typename T>
void DataFrame<T>::fillna(const T &value)
{
    for (auto &row : m_data)
    {
        for (auto &item : row)
        {
            if (std::isnan(item))
            { // Assuming T can be NaN
                item = value;
            }
        }
    }
}

template <typename T>
void DataFrame<T>::dropna()
{
    m_data.erase(std::remove_if(m_data.begin(), m_data.end(),
                                [](const std::vector<T> &row)
                                {
                                    return std::any_of(row.begin(), row.end(), [](const T &item)
                                                       { return std::isnan(item); });
                                }),
                 m_data.end());
}
// GroupBy class implementation would go here
template <typename T>
DataFrame<T> DataFrame<T>::merge(const DataFrame<T> &other, const std::string &on_column)
{
    // Implement merging logic based on the specified column
    DataFrame<T> mergedDataFrame(m_columns); // Create a new DataFrame for the result
    // Logic to merge based on the specified column
    return mergedDataFrame;
}
template <typename T>
DataFrame<T> DataFrame<T>::merge(const DataFrame<T> &other, const std::string &on_column)
{
    // Implement merging logic based on the specified column
    DataFrame<T> mergedDataFrame(m_columns); // Create a new DataFrame for the result
    // Logic to merge based on the specified column
    return mergedDataFrame;
}
template <typename T>
DataFrame<T> DataFrame<T>::merge(const DataFrame<T> &other, const std::string &on_column)
{
    // Implement merging logic based on the specified column
    DataFrame<T> mergedDataFrame(m_columns); // Create a new DataFrame for the result
    // Logic to merge based on the specified column
    return mergedDataFrame;
}
template <typename T>
void DataFrame<T>::describe() const
{
    std::cout << "Descriptive Statistics:\n";
    for (size_t i = 0; i < m_columns.size(); ++i)
    {
        std::cout << "Column: " << m_columns[i] << "\n";
        std::cout << "Count: " << count(i) << "\n";
        std::cout << "Mean: " << mean(i) << "\n";
        std::cout << "Min: " << min(i) << "\n";
        std::cout << "Max: " << max(i) << "\n";
        std::cout << "-------------------\n";
    }
}
template <typename T>
void DataFrame<T>::describe() const
{
    std::cout << "Descriptive Statistics:\n";
    for (size_t i = 0; i < m_columns.size(); ++i)
    {
        std::cout << "Column: " << m_columns[i] << "\n";
        std::cout << "Count: " << count(i) << "\n";
        std::cout << "Mean: " << mean(i) << "\n";
        std::cout << "Min: " << min(i) << "\n";
        std::cout << "Max: " << max(i) << "\n";
        std::cout << "-------------------\n";
    }
}
template <typename T>
void DataFrame<T>::describe() const
{
    std::cout << "Descriptive Statistics:\n";
    for (size_t i = 0; i < m_columns.size(); ++i)
    {
        std::cout << "Column: " << m_columns[i] << "\n";
        std::cout << "Count: " << count(i) << "\n";
        std::cout << "Mean: " << mean(i) << "\n";
        std::cout << "Min: " << min(i) << "\n";
        std::cout << "Max: " << max(i) << "\n";
        std::cout << "-------------------\n";
    }
}