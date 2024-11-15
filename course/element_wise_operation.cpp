#include "include/Array.h"

// Element-wise operations
template <typename T>
Array<T> Array<T>::elementWiseOperation(const Array<T> &other, function<T(T, T)> op)
{
    if (data.size() != other.data.size())
    {
        throw invalid_argument("Arrays must be of the same size.");
    }
    vector<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i)
    {
        result[i] = op(data[i], other.data[i]);
    }
    return Array<T>(result);
}

template <typename T>
Array<T> Array<T>::elementWiseOperation(function<T(T)> op)
{
    vector<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i)
    {
        result[i] = op(data[i]);
    }
    return Array<T>(result);
}

// template instantiations
template class Array<double>;
template class Array<std::string>;