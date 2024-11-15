#include "include/Array.h"

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

// Access by label (index)
template <typename T>
T Array<T>::loc(size_t index) const
{
    if (index >= data.size())
    {
        throw out_of_range("Index " + to_string(index) + " is out of bounds. Valid range is 0 to " + to_string(data.size() - 1) + ".");
    }
    return data[index]; // Access by index
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