// author: Aryanthepain
#ifndef ARRAY_H
#define ARRAY_H
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief A template class for a dynamic array that supports various mathematical and array operations. Only handles double and string.
 *
 * @tparam T The type of elements in the array.
 */
template <typename T>
class Array
{
private:
    vector<T> data; ///< Internal storage for the array elements.

    // Helper functions
    Array<T> elementWiseOperation(const Array<T> &other, std::function<T(T, T)> op) const;
    Array<T> elementWiseOperation(std::function<T(T)> op) const;

public:
    // Constructors
    /**
     * @brief Default constructor that initializes an empty array.
     */
    Array() : data() {}

    /**
     * @brief Constructor that initializes the array with the given vector.
     *
     * @param data The vector to initialize the array with.
     */
    Array(const vector<T> &data) : data(data) {}

    /**
     * @brief Creates an array filled with zeros.
     *
     * @param size The size of the array.
     * @return An Array<T> filled with zeros.
     */
    static Array<T> zeros(size_t size);

    /**
     * @brief Creates an array filled with ones.
     *
     * @param size The size of the array.
     * @return An Array<T> filled with ones.
     */
    static Array<T> ones(size_t size);

    /**
     * @brief Creates an array with a range of values from start to end with a specified step.
     *
     * @param start The starting value.
     * @param end The ending value.
     * @param step The step size.
     * @return An Array<T> containing the range of values.
     */
    static Array<T> arange(double start, double end, double step);

    /**
     * @brief Creates an array with evenly spaced values between start and end.
     *
     * @param start The starting value.
     * @param end The ending value.
     * @param num The number of samples to generate.
     * @return An Array<T> containing the evenly spaced values.
     */
    static Array<T> linspace(double start, double end, size_t num);

    // Access methods
    /**
     * @brief Access an element by index.
     *
     * @param index The index of the element to access.
     * @return A reference to the element at the specified index.
     */
    T &operator[](size_t index);

    /**
     * @brief Access an element by index (const version).
     *
     * @param index The index of the element to access.
     * @return A const reference to the element at the specified index.
     */
    const T &operator[](size_t index) const;

    /**
     * @brief Prints the contents of the array.
     */
    void print() const;

    /**
     * @brief Returns the internal data vector.
     *
     * @return A vector<T> containing the data.
     */
    vector<T> getData() const;

    /**
     * @brief Searches for a value in the array and returns its index.
     *
     * @param value The value to search for.
     * @return The index of the value, or size() if not found.
     */
    size_t search(const T &value) const;

    /**
     * @brief Returns the size of the array.
     *
     * @return The number of elements in the array.
     */
    size_t size() const;

    // Array Manipulation
    /**
     * @brief Concatenates two arrays.
     *
     * @param a The first array.
     * @param b The second array.
     * @return An Array<T> containing the concatenated result.
     */
    static Array<T> concatenate(const Array<T> &a, const Array<T> &b);

    /**
     * @brief Splits an array into multiple arrays.
     *
     * @param a The array to split.
     * @param num The number of splits.
     * @return A vector of Array<T> containing the split arrays.
     */
    static vector<Array<T>> split(const Array<T> &a, size_t num);

    /**
     * @brief Generates an array of random samples.
     *
     * @param size The number of random samples.
     * @return An Array<T> containing random samples.
     */
    static Array<T> randomRand(size_t size);

    /**
     * @brief Sorts the array in place.
     */
    void sort();

    /**
     * @brief Samples a specified number of elements from the array.
     *
     * @param sampleSize The number of elements to sample.
     * @return An Array<T> containing the sampled elements.
     */
    Array<T> sample(size_t sampleSize) const;

    /**
     * @brief Slices the array from start to end.
     *
     * @param start The starting index of the slice.
     * @param end The ending index of the slice.
     * @return An Array<T> containing the sliced elements.
     */
    Array<T> slice(size_t start, size_t end) const;

    /**
     * @brief Returns unique values from the array.
     *
     * @return An Array<T> containing unique values.
     */
    Array<T> unique() const;

    /**
     * @brief Counts occurrences of a specified value in the array.
     *
     * @param value The value to count.
     * @return The number of occurrences of the value.
     */
    size_t count(const T &value) const;

    // Mathematical Operations for double
    /**
     * @brief Adds two arrays element-wise.
     *
     * @param other The array to add.
     * @return An Array<double> containing the result of the addition.
     */
    Array<double> add(const Array<double> &other) const;

    /**
     * @brief Subtracts one array from another element-wise.
     *
     * @param other The array to subtract.
     * @return An Array<double> containing the result of the subtraction.
     */
    Array<double> subtract(const Array<double> &other) const;

    /**
     * @brief Multiplies two arrays element-wise.
     *
     * @param other The array to multiply.
     * @return An Array<double> containing the result of the multiplication.
     */
    Array<double> multiply(const Array<double> &other) const;

    /**
     * @brief Divides one array by another element-wise.
     *
     * @param other The array to divide by.
     * @return An Array<double> containing the result of the division.
     */
    Array<double> divide(const Array<double> &other) const;

    /**
     * @brief Raises each element of the array to a specified exponent.
     *
     * @param exponent The exponent to raise the elements to.
     * @return An Array<double> containing the result of the power operation.
     */
    Array<double> power(double exponent) const;

    /**
     * @brief Computes the sum of the elements in the array.
     *
     * @return The sum of the elements.
     */
    double sum() const;

    /**
     * @brief Computes the mean of the elements in the array.
     *
     * @return The mean of the elements.
     */
    double mean() const;

    /**
     * @brief Computes the standard deviation of the elements in the array.
     *
     * @return The standard deviation of the elements.
     */
    double std() const;

    /**
     * @brief Computes the variance of the elements in the array.
     *
     * @return The variance of the elements.
     */
    double var() const;

    /**
     * @brief Computes the cumulative sum of the elements in the array.
     *
     * @return An Array<double> containing the cumulative sum.
     */
    Array<double> cumsum() const;

    /**
     * @brief Computes the cumulative product of the elements in the array.
     *
     * @return An Array<double> containing the cumulative product.
     */
    Array<double> cumprod() const;

    /**
     * @brief Computes the sine of each element in the array.
     *
     * @return An Array<double> containing the sine values.
     */
    Array<double> sin() const;

    /**
     * @brief Computes the cosine of each element in the array.
     *
     * @return An Array<double> containing the cosine values.
     */
    Array<double> cos() const;

    /**
     * @brief Computes the exponential of each element in the array.
     *
     * @return An Array<double> containing the exponential values.
     */
    Array<double> exp() const;

    /**
     * @brief Computes the natural logarithm of each element in the array.
     *
     * @return An Array<double> containing the logarithm values.
     */
    Array<double> log() const;

    /**
     * @brief Computes the quartiles of the elements in the array.
     *
     * @return A tuple containing Q1, Q2, and Q3 quartiles.
     */
    std::tuple<double, double, double> quartiles() const;

    /**
     * @brief Finds the maximum value in the array.
     *
     * @return The maximum value.
     */
    double max() const;

    /**
     * @brief Finds the minimum value in the array.
     *
     * @return The minimum value.
     */
    double min() const;
};

#endif // ARRAY_H