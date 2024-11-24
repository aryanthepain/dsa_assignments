#include "../include/Array.h"

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

// Function to search for a value in the array
template <typename T>
size_t Array<T>::search(const T &value) const
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        if (data[i] == value)
        {
            return i; // Return the index if found
        }
    }
    return -1; // Indicate not found
}

// Return the size of the array
template <typename T>
size_t Array<T>::size() const
{
    return data.size();
}

// template instantiations
template class Array<double>;
template class Array<std::string>;