#include "include/array.h"

// Constructors
Array Array::zeros(size_t size)
{
    return Array(vector<double>(size, 0));
}

Array Array::ones(size_t size)
{
    return Array(vector<double>(size, 1));
}

Array Array::arange(double start, double end, double step)
{
    vector<double> data;
    for (double i = start; i < end; i += step)
    {
        data.push_back(i);
    }
    return Array(data);
}

Array Array::linspace(double start, double end, size_t num)
{
    vector<double> data(num);
    for (size_t i = 0; i < num; ++i)
    {
        data[i] = start + (end - start) * (i / static_cast<double>(num - 1));
    }
    return Array(data);
}

// Array Manipulation
Array Array::concatenate(const Array &a, const Array &b)
{
    vector<double> newData = a.data;
    newData.insert(newData.end(), b.data.begin(), b.data.end());
    return Array(newData);
}

vector<Array> Array::split(const Array &a, size_t num)
{
    vector<Array> result;
    size_t splitSize = a.data.size() / num;
    for (size_t i = 0; i < num; ++i)
    {
        vector<double> subData(a.data.begin() + i * splitSize, a.data.begin() + (i + 1) * splitSize);
        result.push_back(Array(subData));
    }
    return result;
}

// Mathematical Operations
Array Array::add(const Array &other)
{
    return elementWiseOperation(other, [](double a, double b)
                                { return a + b; });
}
Array Array::subtract(const Array &other)
{
    return elementWiseOperation(other, [](double a, double b)
                                { return a - b; });
}
Array Array::multiply(const Array &other)
{
    return elementWiseOperation(other, [](double a, double b)
                                { return a * b; });
}
Array Array::divide(const Array &other)
{
    return elementWiseOperation(other, [](double a, double b)
                                { return a / b; });
}
Array Array::power(double exponent)
{
    return elementWiseOperation([exponent](double a)
                                { return pow(a, exponent); });
}

double Array::sum()
{
    return accumulate(data.begin(), data.end(), 0);
}

double Array::mean()
{
    return sum() / data.size();
}

double Array::std()
{
    double meanVal = mean();
    double accum = 0;
    for (double d : data)
    {
        accum += (d - meanVal) * (d - meanVal);
    }
    return sqrt(accum / data.size());
}

// Random Sampling
Array Array::randomRand(size_t size)
{
    vector<double> data(size);
    generate(data.begin(), data.end(), []()
             { return static_cast<double>(rand()) / RAND_MAX; });
    return Array(data);
}

// Print function
void Array::print() const
{
    for (const double &val : data)
    {
        cout << fixed << setprecision(2) << val << " ";
    }
    cout << endl;
}

Array Array::elementWiseOperation(const Array &other, function<double(double, double)> op)
{
    if (data.size() != other.data.size())
    {
        throw invalid_argument("Arrays must be of the same size.");
    }
    vector<double> result(data.size());
    for (size_t i = 0; i < data.size(); ++i)
    {
        result[i] = op(data[i], other.data[i]);
    }
    return Array(result);
}

Array Array::elementWiseOperation(function<double(double)> op)
{
    vector<double> result(data.size());
    for (size_t i = 0; i < data.size(); ++i)

        result[i] = op(data[i]);
    return Array(result);
}
