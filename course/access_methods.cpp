#include "include/Array.h"

// Subscript operator for read/write access
template <typename T>
T &Array<T>::operator[](size_t index)
{
    if (index >= data.size())
    {
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

// Subscript operator for read-only access
template <typename T>
const T &Array<T>::operator[](size_t index) const
{
    if (index >= data.size())
    {
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

// print function
template <typename T>
void Array<T>::print() const
{
    for (const T val : data)
    {
        cout << val << " ";
    }
    cout << endl;
}

// Return the data
template <typename T>
vector<T> Array<T>::getData() const
{
    return data;
}

// template instantiations
template class Array<double>;
template class Array<std::string>;