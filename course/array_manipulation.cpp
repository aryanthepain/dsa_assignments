#include "include/Array.h"

// concatenate two arrays
template <typename T>
Array<T> Array<T>::concatenate(const Array<T> &a, const Array<T> &b)
{
    vector<T> newData = a.data;
    newData.insert(newData.end(), b.data.begin(), b.data.end());
    return Array<T>(newData);
}

// split into multiple arrays
template <typename T>
vector<Array<T>> Array<T>::split(const Array<T> &a, size_t num)
{
    vector<Array<T>> result;
    size_t splitSize = a.data.size() / num;
    for (size_t i = 0; i < num; ++i)
    {
        vector<T> subData(a.data.begin() + i * splitSize, a.data.begin() + (i + 1) * splitSize);
        result.push_back(Array<T>(subData));
    }
    return result;
}

// Sort the array in place
template <typename T>
void Array<T>::sort()
{
    std::sort(data.begin(), data.end());
}

// Random array for double
template <>
Array<double> Array<double>::randomRand(size_t size)
{
    vector<double> data(size);
    generate(data.begin(), data.end(), []()
             { return static_cast<double>(rand()) / RAND_MAX; });
    return Array<double>(data);
}

// Sample from the array
template <typename T>
Array<T> Array<T>::sample(size_t sampleSize) const
{
    if (sampleSize > data.size())
    {
        throw std::runtime_error("Sample size cannot be greater than the original array size.");
    }

    vector<T> sampleData;
    sampleData.reserve(sampleSize);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, data.size() - 1);

    for (size_t i = 0; i < sampleSize; ++i)
    {
        sampleData.push_back(data[dist(mt)]);
    }

    return Array<T>(sampleData);
}

// Slice the array
template <typename T>
Array<T> Array<T>::slice(size_t start, size_t end)
{
    if (start >= data.size() || end > data.size() || start > end)
    {
        throw out_of_range("Invalid slice indices.");
    }
    return Array<T>(vector<T>(data.begin() + start, data.begin() + end));
}

// Unique values
template <typename T>
Array<T> Array<T>::unique() const
{
    std::vector<T> uniqueData = data;                              // Create a copy
    std::sort(uniqueData.begin(), uniqueData.end());               // Sort the data
    auto last = std::unique(uniqueData.begin(), uniqueData.end()); // Remove duplicates
    uniqueData.erase(last, uniqueData.end());                      // Erase the "removed" duplicates
    return Array<T>(uniqueData);                                   // Return a new Array containing the unique values
}

// Count occurrences of a value
template <typename T>
size_t Array<T>::count(const T &value) const
{
    return std::count(data.begin(), data.end(), value);
}

// template instantiations
template class Array<double>;
template class Array<std::string>;