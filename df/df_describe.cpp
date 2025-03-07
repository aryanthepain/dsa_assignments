// author: Aryanthepain
#include "../include/df.h"

// Describe the dataframe
void DataFrame::describe(int col) const
{
    // -1 for all columns
    if (col != -1)
    {
        this->OutOfBounds(col);
    }
    else
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
        return;
    }

    int i = col;

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

// Function to describe numeric columns
void DataFrame::describeNumericColumn(size_t index) const
{
    const Array<double> &array = get<Array<double>>(columns[index]);
    cout << "Type: Numeric" << endl;
    cout << "Count: " << array.size() << endl;
    cout << "Mean: " << array.mean() << endl;

    auto [q1, q2, q3] = array.quartiles();
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
    cout << "Unique Values: " << array.unique().size();
    cout << endl;
}

// get the dimensions of the DataFrame
pair<size_t, size_t> DataFrame::shape() const
{
    return {indexLabels.size(), columns.size()};
}

// get unique values of a column
ColumnType DataFrame::unique(size_t col) const
{
    try
    {
        this->OutOfBounds(col);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
        return Array<double>();
    }

    // Check the type of the column and handle accordingly
    if (holds_alternative<Array<double>>(columns[col]))
    {
        // Handle Array<double>
        const Array<double> &array = get<Array<double>>(columns[col]);
        return array.unique();
    }
    else if (holds_alternative<Array<string>>(columns[col]))
    {
        // Handle Array<string>
        const Array<string> &array = get<Array<string>>(columns[col]);
        return array.unique();
    }
    else
    {
        throw std::invalid_argument("Unsupported column type. String or double column only");
        return Array<double>(); // Return an empty Array as a fallback
    }
}

// Number of unique values in a column
size_t DataFrame::nunique(size_t col) const
{
    try
    {
        this->OutOfBounds(col);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
        return 0;
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
        throw std::invalid_argument("Unsupported column type. String or Double only");
        return 0; // Return 0 for unsupported types
    }
}