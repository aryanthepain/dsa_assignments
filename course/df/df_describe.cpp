#include "../include/df.h"

// Describe method implementation
void DataFrame::describe() const
{
    for (size_t i = 0; i < columns.size(); ++i)
    {
        visit([this, i](const auto &array)
              {
                  // Check if the array is of type Array<double>
                  if constexpr (std::is_same_v<decltype(array), Array<double>>) 
                  {
                      cout << "Column: " << columnNames[i] << endl;
                      cout << "Count: " << array.size() << endl;
                      cout << "Mean: " << array.mean() << endl;
                      cout << "Median: " << array.median() << endl; // Assuming you implement a median function in Array
                      auto [q1, q2, q3] = array.quartiles(); // Assuming quartiles returns a tuple of Q1, Q2, Q3
                      cout << "Quartiles: " << q1 << ", " << q2 << ", " << q3 << endl;
                  }
                  // Check if the array is of type Array<string>
                  else if constexpr (std::is_same_v<decltype(array), Array<string>>) 
                  {
                      cout << "Column: " << columnNames[i] << endl;
                      cout << "Count: " << array.size() << endl;
                      cout << "Unique Values: ";
                      Array<string> uniqueValues = array.unique(); // Assuming unique() returns unique values
                      for (const auto &value : uniqueValues.getData()) {
                          cout << value << " ";
                      }
                      cout << endl;
                  } }, columns[i]);
    }
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