#include "include/Array.h"

// Template specializations for double
template <>
Array<double> Array<double>::zeros(size_t size)
{
    return Array<double>(vector<double>(size, 0.0));
}

template <>
Array<double> Array<double>::ones(size_t size)
{
    return Array<double>(vector<double>(size, 1.0));
}

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
template <>
Array<string> Array<string>::zeros(size_t size)
{
    return Array<string>(vector<string>(size, "0"));
}

template <>
Array<string> Array<string>::ones(size_t size)
{
    return Array<string>(vector<string>(size, "1"));
}

// Array Manipulation
template <typename T>
Array<T> Array<T>::concatenate(const Array<T> &a, const Array<T> &b)
{
    vector<T> newData = a.data;
    newData.insert(newData.end(), b.data.begin(), b.data.end());
    return Array<T>(newData);
}

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

// Mathematical Operations for double
template <>
Array<double> Array<double>::add(const Array<double> &other)
{
    return elementWiseOperation(other, [](double a, double b)
                                { return a + b; });
}

template <>
Array<double> Array<double>::subtract(const Array<double> &other)
{
    return elementWiseOperation(other, [](double a, double b)
                                { return a - b; });
}

template <>
Array<double> Array<double>::multiply(const Array<double> &other)
{
    return elementWiseOperation(other, [](double a, double b)
                                { return a * b; });
}

template <>
Array<double> Array<double>::divide(const Array<double> &other)
{
    return elementWiseOperation(other, [](double a, double b)
                                { return a / b; });
}

template <>
Array<double> Array<double>::power(double exponent)
{
    return elementWiseOperation([exponent](double a)
                                { return pow(a, exponent); });
}

template <>
double Array<double>::sum()
{
    return accumulate(data.begin(), data.end(), 0.0);
}

template <>
double Array<double>::mean()
{
    return sum() / data.size();
}

template <>
double Array<double>::std()
{
    double meanVal = mean();
    double accum = 0.0;
    for (double d : data)
    {
        accum += (d - meanVal) * (d - meanVal);
    }
    return sqrt(accum / data.size());
}

// Variance
template <>
double Array<double>::var()
{
    double meanVal = mean();
    double accum = 0.0;
    for (double d : data)
    {
        accum += (d - meanVal) * (d - meanVal);
    }
    return accum / data.size();
}

// Cumulative Sum
template <>
Array<double> Array<double>::cumsum()
{
    vector<double> result(data.size());
    result[0] = data[0];
    for (size_t i = 1; i < data.size(); ++i)
    {
        result[i] = result[i - 1] + data[i];
    }
    return Array<double>(result);
}

// Cumulative Product
template <>
Array<double> Array<double>::cumprod()
{
    vector<double> result(data.size());
    result[0] = data[0];
    for (size_t i = 1; i < data.size(); ++i)
    {
        result[i] = result[i - 1] * data[i];
    }
    return Array<double>(result);
}

// Sine
template <>
Array<double> Array<double>::sin()
{
    return elementWiseOperation([](double a)
                                { return std::sin(a); });
}

// Cosine
template <>
Array<double> Array<double>::cos()
{
    return elementWiseOperation([](double a)
                                { return std::cos(a); });
}

// Exponential
template <>
Array<double> Array<double>::exp()
{
    return elementWiseOperation([](double a)
                                { return std::exp(a); });
}

// Natural Logarithm
template <>
Array<double> Array<double>::log()
{
    return elementWiseOperation([](double a)
                                { return std::log(a); });
}

// Random Sampling for double
template <>
Array<double> Array<double>::randomRand(size_t size)
{
    vector<double> data(size);
    generate(data.begin(), data.end(), []()
             { return static_cast<double>(rand()) / RAND_MAX; });
    return Array<double>(data);
}

// Print function
template <typename T>
void Array<T>::print() const
{
    for (const T &val : data)
    {
        cout << val << " ";
    }
    cout << endl;
}

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

// Access by label (index)
template <typename T>
T Array<T>::loc(size_t index) const
{
    if (index >= data.size())
    {
        throw out_of_range("Index out of bounds.");
    }
    return data[index]; // Access by index
}

// Access by integer position
template <typename T>
T Array<T>::iloc(size_t index) const
{
    if (index >= data.size())
    {
        throw out_of_range("Index out of bounds.");
    }
    return data[index]; // Access by index
}

// Fast access by index
template <typename T>
T Array<T>::at(size_t index) const
{
    if (index >= data.size())
    {
        throw out_of_range("Index out of bounds.");
    }
    return data[index]; // Access by index
}

// Fast access by integer position
template <typename T>
T Array<T>::iat(size_t index) const
{
    if (index >= data.size())
    {
        throw out_of_range("Index out of bounds.");
    }
    return data[index]; // Access by index
}

// Calculate Quartiles
template <>
tuple<double, double, double> Array<double>::quartiles() const
{
    if (data.empty())
    {
        throw invalid_argument("Array is empty.");
    }

    // Sort the data to calculate quartiles
    vector<double> sortedData = data; // Create a copy to sort
    std::sort(sortedData.begin(), sortedData.end());

    double Q1, Q2, Q3;

    // Calculate Q2 (median)
    size_t n = sortedData.size();
    if (n % 2 == 0) // Even number of elements
    {
        Q2 = (sortedData[n / 2 - 1] + sortedData[n / 2]) / 2.0;
    }
    else // Odd number of elements
    {
        Q2 = sortedData[n / 2];
    }

    // Calculate Q1 (median of the first half)
    vector<double> lowerHalf(sortedData.begin(), sortedData.begin() + n / 2);
    if (lowerHalf.size() % 2 == 0) // Even number of elements
    {
        Q1 = (lowerHalf[lowerHalf.size() / 2 - 1] + lowerHalf[lowerHalf.size() / 2]) / 2.0;
    }
    else // Odd number of elements
    {
        Q1 = lowerHalf[lowerHalf.size() / 2];
    }

    // Calculate Q3 (median of the second half)
    vector<double> upperHalf(sortedData.begin() + (n + 1) / 2, sortedData.end());
    if (upperHalf.size() % 2 == 0) // Even number of elements
    {
        Q3 = (upperHalf[upperHalf.size() / 2 - 1] + upperHalf[upperHalf.size() / 2]) / 2.0;
    }
    else // Odd number of elements
    {
        Q3 = upperHalf[upperHalf.size() / 2];
    }

    return make_tuple(Q1, Q2, Q3);
}

// Sort the array in place
template <typename T>
void Array<T>::sort()
{
    std::sort(data.begin(), data.end());
} // Calculate Quartiles
template <>
tuple<double, double, double> Array<double>::quartiles() const
{
    if (data.empty())
    {
        throw invalid_argument("Array is empty.");
    }

    // Sort the data to calculate quartiles
    vector<double> sortedData = data; // Create a copy to sort
    std::sort(sortedData.begin(), sortedData.end());

    double Q1, Q2, Q3;

    // Calculate Q2 (median)
    size_t n = sortedData.size();
    if (n % 2 == 0) // Even number of elements
    {
        Q2 = (sortedData[n / 2 - 1] + sortedData[n / 2]) / 2.0;
    }
    else // Odd number of elements
    {
        Q2 = sortedData[n / 2];
    }

    // Calculate Q1 (median of the first half)
    vector<double> lowerHalf(sortedData.begin(), sortedData.begin() + n / 2);
    if (lowerHalf.size() % 2 == 0) // Even number of elements
    {
        Q1 = (lowerHalf[lowerHalf.size() / 2 - 1] + lowerHalf[lowerHalf.size() / 2]) / 2.0;
    }
    else // Odd number of elements
    {
        Q1 = lowerHalf[lowerHalf.size() / 2];
    }

    // Calculate Q3 (median of the second half)
    vector<double> upperHalf(sortedData.begin() + (n + 1) / 2, sortedData.end());
    if (upperHalf.size() % 2 == 0) // Even number of elements
    {
        Q3 = (upperHalf[upperHalf.size() / 2 - 1] + upperHalf[upperHalf.size() / 2]) / 2.0;
    }
    else // Odd number of elements
    {
        Q3 = upperHalf[upperHalf.size() / 2];
    }

    return make_tuple(Q1, Q2, Q3);
}

// Sort the array in place
template <typename T>
void Array<T>::sort()
{
    std::sort(data.begin(), data.end());
}
// Note: For string operations, you may want to implement specific functions as needed,
// since mathematical operations like add, subtract, etc., do not apply to strings.