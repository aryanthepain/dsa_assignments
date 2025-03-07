// author: Aryanthepain
#include "../include/df.h"

// return sum of a column
double DataFrame::sum(size_t col) const
{
    if (col >= columns.size())
    {
        throw std::out_of_range("Column index out of range");
    }

    if (holds_alternative<Array<double>>(columns[col]))
    {
        const auto &arrayData = get<Array<double>>(columns[col]);
        return arrayData.sum();
    }
    else
    {
        throw std::invalid_argument("Column is not of type double");
    }
}

// return mean of a column
double DataFrame::mean(size_t col) const
{
    if (col >= columns.size())
    {
        throw std::out_of_range("Column index out of range");
    }

    if (holds_alternative<Array<double>>(columns[col]))
    {
        const auto &arrayData = get<Array<double>>(columns[col]);
        return arrayData.mean();
    }
    else
    {
        throw std::invalid_argument("Column is not of type double");
    }
}

// return quartiles of a column
tuple<double, double, double> DataFrame::quartiles(size_t col) const
{
    if (col >= columns.size())
    {
        throw std::out_of_range("Column index out of range");
    }

    if (holds_alternative<Array<double>>(columns[col]))
    {
        const auto &arrayData = get<Array<double>>(columns[col]);
        return arrayData.quartiles();
    }
    else
    {
        throw std::invalid_argument("Column is not of type double");
    }
}