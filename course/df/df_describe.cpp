#include "../include/df.h"

// Implementation of the describe function
void DataFrame::describe() const
{
    for (size_t i = 0; i < columns.size(); ++i)
    {
        visit([this, i](const auto &array)
              {
            using ArrayType = decltype(array);
            if constexpr (std::is_same_v<ArrayType, Array<double>>) {
                describeNumericColumn(i, array);
            } else if constexpr (std::is_same_v<ArrayType, Array<string>>) {
                describeStringColumn(i, array);
            } else {
                cout << "Column: " << columnNames[i] << " has unsupported type." << endl;
            } }, columns[i]);
    }
}

// Function to describe numeric columns
void DataFrame::describeNumericColumn(size_t index, const Array<double> &array) const
{
    cout << "Column: " << columnNames[index] << endl;
    cout << "Count: " << array.size() << endl;
    cout << "Mean: " << array.mean() << endl;
    auto [q1, q2, q3] = array.quartiles(); // Assuming quartiles returns a tuple of Q1, Q2, Q3
    cout << "Quartiles: " << q1 << ", " << q2 << ", " << q3 << endl;
    cout << "Max: " << array.max() << endl;
    cout << "Min: " << array.min() << endl;
}

// Function to describe string columns
void DataFrame::describeStringColumn(size_t index, const Array<string> &array) const
{
    cout << "Column: " << columnNames[index] << endl;
    cout << "Count: " << array.size() << endl;
    cout << "Unique Values: ";
    Array<string> uniqueValues = array.unique(); // Assuming unique() returns unique values
    for (const auto &value : uniqueValues.getData())
    {
        cout << value << " ";
    }
    cout << endl;
}

// Shape method implementation
pair<size_t, size_t> DataFrame::shape() const
{
    return {indexLabels.size(), columns.size()};
}

// Unique method implementation
vector<string> DataFrame::unique(size_t col) const
{
    vector<string> uniqueValues;

    // Check if the column index is valid
    if (col >= columns.size())
    {
        cout << "Column index out of bounds!" << endl;
        return uniqueValues;
    }

    // Use std::visit to handle different types in the columns
    visit([&uniqueValues](const auto &array)
          {
              using T = std::decay_t<decltype(array)>; // Determine the type of the array
              if constexpr (std::is_same_v<T, Array<double>>) 
              {
                  // Handle Array<double>
                  set<string> uniqueSet;
                  for (const auto& value : array.getData()) {
                      uniqueSet.insert(to_string(value)); // Convert double to string
                  }
                  uniqueValues.assign(uniqueSet.begin(), uniqueSet.end());
              }
              else if constexpr (std::is_same_v<T, Array<string>>) 
              {
                  // Handle Array<string>
                  set<string> uniqueSet(array.getData().begin(), array.getData().end());
                  uniqueValues.assign(uniqueSet.begin(), uniqueSet.end());
              } }, columns[col]);

    return uniqueValues;
}

// Nunique method implementation
size_t DataFrame::nunique(size_t col) const
{
    return unique(col).size();
}