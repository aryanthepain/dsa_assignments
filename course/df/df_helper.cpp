// author: Aryanthepain
#include "../include/df.h"

// check if a column is out of bounds
bool DataFrame::OutOfBounds(size_t num) const
{
    if (num >= columns.size() || num < 0)
    {
        throw std::out_of_range("Column index out of bounds");
    }

    return false;
}