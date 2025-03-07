// author: Aryanthepain
#ifndef DF_H
#define DF_H

#include <bits/stdc++.h>
#include "Array.h"
using namespace std;

// Define a variant type for the DataFrame columns
using ColumnType = variant<Array<double>, Array<string>>;

/**
 * @brief A class representing a DataFrame, which can hold multiple columns of data.
 *
 * This class can handle both numeric and string data types and provides various methods for data manipulation,
 * statistical analysis, and visualization.
 */
class DataFrame
{
private:
    vector<ColumnType> columns; ///< Each column can be either Array<double> or Array<string>
    vector<string> columnNames; ///< Names of the columns
    vector<size_t> indexLabels; ///< Row index labels

    // Helper functions
    void describeNumericColumn(size_t index) const;
    void describeStringColumn(size_t index) const;
    bool OutOfBounds(size_t num) const;
    DataFrame concatColumns(const DataFrame &other) const;
    DataFrame concatRows(const DataFrame &other) const;

public:
    // Constructors

    /**
     * @brief Default constructor that initializes an empty DataFrame.
     */
    DataFrame();

    /**
     * @brief Constructor that initializes the DataFrame with input data and column names.
     *
     * @param inputData A 2D vector containing the data for the DataFrame.
     * @param colNames A vector of strings containing the names of the columns.
     */
    DataFrame(const vector<vector<variant<double, string>>> &inputData,
              const vector<string> &colNames);

    /**
     * @brief Constructor that initializes the DataFrame from a CSV file.
     *
     * @param csvFilePath The path to the CSV file.
     */
    DataFrame(const string &csvFilePath);

    /**
     * @brief Adds a new column to the DataFrame.
     *
     * @param name The name of the new column.
     * @param data The data for the new column.
     */
    void addColumn(const string &name, const ColumnType &data);

    /**
     * @brief Adds a new column of double values to the DataFrame.
     *
     * @param name The name of the new column.
     * @param data The Array<double> containing the data for the new column.
     */
    void addColumn(const string &name, const Array<double> &data);

    /**
     * @brief Adds a new column of string values to the DataFrame.
     *
     * @param name The name of the new column.
     * @param data The Array<string> containing the data for the new column.
     */
    void addColumn(const string &name, const Array<string> &data);

    // Access methods

    /**
     * @brief Prints the entire DataFrame to the console.
     */
    void print() const;

    /**
     * @brief Returns the top n rows of the DataFrame.
     *
     * @param n The number of rows to return (default is 5).
     */
    void head(size_t n = 5) const;

    /**
     * @brief Returns the bottom n rows of the DataFrame.
     *
     * @param n The number of rows to return (default is 5).
     */
    void tail(size_t n = 5) const;

    /**
     * @brief Returns the names of the columns in the DataFrame.
     *
     * @return A vector of strings containing the column names.
     */
    vector<string> getColumns() const;

    /**
     * @brief Returns the row index labels of the DataFrame.
     *
     * @return A vector of size_t containing the index labels.
     */
    vector<size_t> getIndex() const;

    /**
     * @brief Creates a copy of the DataFrame.
     *
     * @return A new DataFrame that is a copy of the current one.
     */
    DataFrame copy() const;

    /**
     * @brief Accesses a specific entry in the DataFrame using integer-location based indexing.
     *
     * @param row The row index.
     * @param col The column index.
     * @return A variant containing the value at the specified location.
     */
    variant<double, string> iloc(size_t row, size_t col) const;

    /**
     * @brief Accesses a specific entry in the DataFrame using label-based indexing.
     *
     * @param rowLabel The label of the row.
     * @param colLabel The label of the column.
     * @return A variant containing the value at the specified location.
     */
    variant<double, string> loc(size_t rowLabel, const string &colLabel) const;

    /**
     * @brief Searches for a value in a specified column and returns the row index.
     *
     * @param colLabel The label of the column to search.
     * @param value The value to search for.
     * @return The index of the row containing the value, or -1 if not found.
     */
    int searchRowByColumn(const string &colLabel, const variant<double, string> &value) const;

    /**
     * @brief Searches for a value in a specified row and returns the column index.
     *
     * @param rowIndex The index of the row to search.
     * @param value The value to search for.
     * @return The index of the column containing the value, or -1 if not found.
     */
    int searchColumnByRow(size_t rowIndex, const variant<double, string> &value) const;

    /**
     * @brief Exports the DataFrame to a CSV file.
     *
     * @param filePath The path to the output CSV file.
     */
    void to_csv(const string &filePath) const;

    // Describe the DataFrame

    /**
     * @brief Describes the DataFrame or a specific column.
     *
     * @param col The index of the column to describe (default is -1 for the entire DataFrame).
     */
    void describe(int col = -1) const;

    /**
     * @brief Returns the shape of the DataFrame as a pair of (rows, columns).
     *
     * @return A pair containing the number of rows and columns.
     */
    pair<size_t, size_t> shape() const;

    /**
     * @brief Returns unique values from a specified column.
     *
     * @param col The index of the column to get unique values from.
     * @return A ColumnType containing the unique values.
     */
    ColumnType unique(size_t col) const;

    /**
     * @brief Returns the number of unique values in a specified column.
     *
     * @param col The index of the column to count unique values.
     * @return The number of unique values in the column.
     */
    size_t nunique(size_t col) const;

    // Statistical methods

    /**
     * @brief Computes the sum of a specified column (for double columns).
     *
     * @param col The index of the column to sum.
     * @return The sum of the column values.
     */
    double sum(size_t col) const;

    /**
     * @brief Computes the mean of a specified column (for double columns).
     *
     * @param col The index of the column to compute the mean.
     * @return The mean of the column values.
     */
    double mean(size_t col) const;

    /**
     * @brief Computes the quartiles of a specified column.
     *
     * @param col The index of the column to compute quartiles.
     * @return A tuple containing the first, second (median), and third quartiles.
     */
    tuple<double, double, double> quartiles(size_t col) const;

    // Manipulate DataFrame

    /**
     * @brief Filters the DataFrame based on a string threshold.
     *
     * @param col The index of the column to filter.
     * @param threshold The threshold value for filtering.
     * @param ifMinimumLimit If true, filters for values greater than or equal to the threshold.
     * @return A new DataFrame containing the filtered results.
     */
    DataFrame filterString(size_t col, string threshold, bool ifMinimumLimit = true) const;

    /**
     * @brief Filters the DataFrame based on a double threshold.
     *
     * @param col The index of the column to filter.
     * @param threshold The threshold value for filtering.
     * @param ifMinimumLimit If true, filters for values greater than or equal to the threshold.
     * @return A new DataFrame containing the filtered results.
     */
    DataFrame filterDouble(size_t col, double threshold, bool ifMinimumLimit = true) const;

    /**
     * @brief Drops a specified column from the DataFrame.
     *
     * @param col The index of the column to drop.
     */
    void drop(size_t col);

    /**
     * @brief Concatenates another DataFrame to the current one.
     *
     * @param other The DataFrame to concatenate.
     * @param axis The axis along which to concatenate (0 for rows, 1 for columns).
     * @return A new DataFrame containing the concatenated results.
     */
    DataFrame concat(const DataFrame &other, bool axis = 0) const;

    /**
     * @ brief Sorts the DataFrame based on the values of a specified column.
     *
     * @param col The index of the column to sort by.
     * @param ascending If true, sorts in ascending order; otherwise, sorts in descending order.
     */
    void sort_values(size_t col, bool ascending = true);

    /**
     * @brief Applies a function to a specified column of the DataFrame.
     *
     * @param col The index of the column to apply the function to.
     * @param func The function to apply to each element in the column.
     * @return A new DataFrame containing the results of the function application.
     */
    DataFrame apply(size_t col, function<variant<double, string>(const variant<double, string> &)> func) const;

    // Plotting methods

    /**
     * @brief Plots the values of a specified column.
     *
     * @param col The index of the column to plot.
     */
    void plot(size_t col) const;

    /**
     * @brief Creates a histogram of the values in a specified column.
     *
     * @param col The index of the column to create a histogram for.
     */
    void hist(size_t col) const;

    /**
     * @brief Creates a boxplot of the values in a specified column.
     *
     * @param col The index of the column to create a boxplot for.
     */
    void boxplot(size_t col) const;
};

#endif // DF_H