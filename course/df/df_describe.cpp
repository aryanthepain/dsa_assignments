#include "../include/df.h"

// Implementation of the describe function
void DataFrame::describe() const
{
    cout << "DataFrame Description:" << endl;
    cout << "----------------------" << endl;

    for (size_t i = 0; i < columns.size(); ++i)
    {
        cout << "Column: " << columnNames[i] << endl;

        // Check the type of the column and call the appropriate describe function
        if (holds_alternative<Array<double>>(columns[i]))
        {
            describeNumericColumn(i);
        }
        else if (holds_alternative<Array<string>>(columns[i]))
        {
            describeStringColumn(i);
        }
        else
        {
            cout << "Unsupported column type." << endl;
        }

        cout << endl; // Add a newline for better readability between columns
    }
}

// Function to describe numeric columns
void DataFrame::describeNumericColumn(size_t index) const
{
    const Array<double> &array = get<Array<double>>(columns[index]);
    cout << "Type: Numeric" << endl;
    cout << "Count: " << array.size() << endl;
    cout << "Mean: " << array.mean() << endl;

    auto [q1, q2, q3] = array.quartiles(); // Assuming quartiles returns a tuple of Q1, Q2, Q3
    cout << "Quartiles: Q1 = " << q1 << ", Q2 (Median) = " << q2 << ", Q3 = " << q3 << endl;

    cout << "Max: " << array.max() << endl;
    cout << "Min: " << array.min() << endl;
}

// Function to describe string columns
void DataFrame::describeStringColumn(size_t index) const
{
    const Array<string> &array = get<Array<string>>(columns[index]);
    cout << "Type: Categorical" << endl;
    cout << "Count: " << array.size() << endl;

    Array<string> uniqueValues = array.unique(); // Assuming unique() returns unique values
    cout << "Unique Values: ";
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

Array<double> DataFrame::unique(size_t col) const
{
    // Check if the column index is valid
    if (col >= columns.size())
    {
        cout << "Column index out of bounds!" << endl;
        return Array<double>(); // Return an empty Array<double> as a fallback
    }

    // Check the type of the column and handle accordingly
    if (holds_alternative<Array<double>>(columns[col]))
    {
        // Handle Array<double>
        const Array<double> &array = get<Array<double>>(columns[col]);
        return array.unique(); // Use the unique method from Array<double>
    }
    else
    {
        cout << "Unsupported column type. Expected Array<double>." << endl;
        return Array<double>(); // Return an empty Array<double> as a fallback
    }
}

Array<string> DataFrame::uniqueString(size_t col) const
{
    // Check if the column index is valid
    if (col >= columns.size())
    {
        cout << "Column index out of bounds!" << endl;
        return Array<string>(); // Return an empty Array<string> as a fallback
    }

    // Check the type of the column and handle accordingly
    if (holds_alternative<Array<string>>(columns[col]))
    {
        // Handle Array<string>
        const Array<string> &array = get<Array<string>>(columns[col]);
        return array.unique(); // Use the unique method from Array<string>
    }
    else
    {
        cout << "Unsupported column type. Expected Array<string>." << endl;
        return Array<string>(); // Return an empty Array<string> as a fallback
    }
}

// Nunique method implementation
size_t DataFrame::nunique(size_t col) const
{
    // Check if the column index is valid
    if (col >= columns.size())
    {
        cout << "Column index out of bounds!" << endl;
        return 0; // Return 0 as a fallback for invalid column index
    }

    // Check the type of the column and handle accordingly
    if (holds_alternative<Array<double>>(columns[col]))
    {
        // Handle Array<double>
        const Array<double> &array = get<Array<double>>(columns[col]);
        return array.unique().size(); // Call nunique on Array<double>
    }
    else if (holds_alternative<Array<string>>(columns[col]))
    {
        // Handle Array<string>
        const Array<string> &array = get<Array<string>>(columns[col]);
        return array.unique().size(); // Call nunique on Array<string>
    }
    else
    {
        cout << "Unsupported column type." << endl; // Handle unsupported types
        return 0;                                   // Return 0 for unsupported types
    }
}