#include "../include/Array.h"

// Mathematical Operations
template <>
Array<double> Array<double>::add(const Array &other) const
{
    return elementWiseOperation(other, [](double a, double b)
                                { return a + b; });
}

template <>
Array<double> Array<double>::subtract(const Array &other) const
{
    return elementWiseOperation(other, [](double a, double b)
                                { return a - b; });
}

template <>
Array<double> Array<double>::multiply(const Array &other) const
{
    return elementWiseOperation(other, [](double a, double b)
                                { return a * b; });
}

template <>
Array<double> Array<double>::divide(const Array &other) const
{
    return elementWiseOperation(other, [](double a, double b)
                                {
        if (b == 0) throw runtime_error("Division by zero");
        return a / b; });
}

template <>
Array<double> Array<double>::power(double exponent) const
{
    return elementWiseOperation([exponent](double a)
                                { return pow(a, exponent); });
}

template <>
double Array<double>::sum() const
{
    return accumulate(data.begin(), data.end(), 0.0);
}

template <>
double Array<double>::mean() const
{
    return sum() / data.size();
}

template <>
double Array<double>::std() const
{
    double meanVal = mean();
    double accum = 0.0;
    for (double d : data)
    {
        accum += (d - meanVal) * (d - meanVal);
    }
    return sqrt(accum / data.size());
}

template <>
double Array<double>::var() const
{
    return std() * std();
}

template <>
Array<double> Array<double>::cumsum() const
{
    vector<double> result(data.size());
    result[0] = data[0];
    for (size_t i = 1; i < data.size(); ++i)
    {
        result[i] = result[i - 1] + data[i];
    }
    return Array(result);
}

template <>
Array<double> Array<double>::cumprod() const
{
    vector<double> result(data.size());
    result[0] = data[0];
    for (size_t i = 1; i < data.size(); ++i)
    {
        result[i] = result[i - 1] * data[i];
    }
    return Array(result);
}

template <>
Array<double> Array<double>::sin() const
{
    return elementWiseOperation([](double a)
                                { return std::sin(a); });
}

template <>
Array<double> Array<double>::cos() const
{
    return elementWiseOperation([](double a)
                                { return std::cos(a); });
}

template <>
Array<double> Array<double>::exp() const
{
    return elementWiseOperation([](double a)
                                { return std::exp(a); });
}

template <>
Array<double> Array<double>::log() const
{
    return elementWiseOperation([](double a)
                                {
        if (a <= 0) throw runtime_error("Logarithm of non-positive value");
        return std::log(a); });
}

template <>
tuple<double, double, double> Array<double>::quartiles() const
{
    if (data.empty())
        throw invalid_argument("Array is empty.");

    vector<double> sortedData = data;
    std::sort(sortedData.begin(), sortedData.end());

    double Q1, Q2, Q3;
    size_t n = sortedData.size();

    // Calculate Q2 (median)
    Q2 = (n % 2 == 0) ? (sortedData[n / 2 - 1] + sortedData[n / 2]) / 2.0 : sortedData[n / 2];

    // Calculate Q1 (median of the first half)
    vector<double> lowerHalf(sortedData.begin(), sortedData.begin() + n / 2);
    Q1 = (lowerHalf.size() % 2 == 0) ? (lowerHalf[lowerHalf.size() / 2 - 1] + lowerHalf[lowerHalf.size() / 2]) / 2.0 : lowerHalf[lowerHalf.size() / 2];

    // Calculate Q3 (median of the second half)
    vector<double> upperHalf(sortedData.begin() + (n + 1) / 2, sortedData.end());
    Q3 = (upperHalf.size() % 2 == 0) ? (upperHalf[upperHalf.size() / 2 - 1] + upperHalf[upperHalf.size() / 2]) / 2.0 : upperHalf[upperHalf.size() / 2];

    return make_tuple(Q1, Q2, Q3);
}

template <>
double Array<double>::max() const
{
    if (data.empty())
        throw invalid_argument("Array is empty.");
    return *max_element(data.begin(), data.end());
}

template <>
double Array<double>::min() const
{
    if (data.empty())
        throw invalid_argument("Array is empty.");
    return *min_element(data.begin(), data.end());
}