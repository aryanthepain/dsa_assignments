#include "include/Array.h"

// Element-wise operations
template <typename T>
Array<T> Array<T>::elementWiseOperation(const Array<T> &other, std::function<T(T, T)> op) const
{
    if (data.size() != other.data.size())
    {
        throw std::invalid_argument("Arrays must be of the same size.");
    }
    std::vector<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i)
    {
        result[i] = op(data[i], other.data[i]);
    }
    return Array<T>(result);
}

template <typename T>
Array<T> Array<T>::elementWiseOperation(std::function<T(T)> op) const
{
    std::vector<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i)
    {
        result[i] = op(data[i]);
    }
    return Array<T>(result);
}

// Template instantiations
template class Array<double>;
template class Array<std::string>;