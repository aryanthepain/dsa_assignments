#include "../include/df.h"

// Print function
void DataFrame::print() const
{
    // Print column names
    cout << setw(10) << ""; // Space for row labels
    for (const auto &colName : columnNames)
    {
        cout << setw(10) << colName; // Adjust width as needed
    }
    cout << endl;

    // Print data rows
    for (size_t i = 0; i < indexLabels.size(); ++i)
    {
        cout << setw(10) << indexLabels[i]; // Print row label
        for (size_t col = 0; col < columns.size(); ++col)
        {
            // Use visit to handle the variant type
            visit([i](auto &&arg)
                  {
                      cout << setw(10) << arg[i]; // Access the i-th element of the column
                  },
                  columns[col]);
        }
        cout << endl; // New line after each row
    }
}