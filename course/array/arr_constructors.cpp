#include "../include/Array.h"

// Template specializations for double

// create an array with all 0
template <>
Array<double> Array<double>::zeros(size_t size)
{
    return Array<double>(vector<double>(size, 0.0));
}

// create an array with all 1
template <>
Array<double> Array<double>::ones(size_t size)
{
    return Array<double>(vector<double>(size, 1.0));
}

// create array wth start and end range with step
template <>
Array<double> Array<double>::arange(double start, double end, double step)
{
    vector<double> data;
    for (double i = start; i < end; i += step)
    {
        data.push_back(i);
    }
    return Array<double>(data);
}

// create array with start and end range with number of elements
template <>
Array<double> Array<double>::linspace(double start, double end, size_t num)
{
    vector<double> data(num);
    for (size_t i = 0; i < num; ++i)
    {
        data[i] = start + (end - start) * (i / static_cast<double>(num - 1));
    }
    return Array<double>(data);
}

// Specialization for string

// create an array with all 0
template <>
Array<string> Array<string>::zeros(size_t size)
{
    return Array<string>(vector<string>(size, "0"));
}

// create an array with all 1
template <>
Array<string> Array<string>::ones(size_t size)
{
    return Array<string>(vector<string>(size, "1"));
}
