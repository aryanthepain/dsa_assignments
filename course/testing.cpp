#include "./include/testing.h"

int main()
{
    // Create a sample DataFrame
    DataFrame df;
    df.columnNames = {"A", "B", "C"};
    df.indexLabels = {"row1", "row2", "row3", "row4"};

    // Sample numeric column
    df.columns.push_back(Array<double>({1.0, 2.0, 3.0, 4.0})); // Column A
    // Sample string column
    df.columns.push_back(Array<string>({"foo", "bar", "baz", "qux"})); // Column B
    // Sample numeric column
    df.columns.push_back(Array<double>({10.0, 20.0, 30.0, 40.0})); // Column C

    cout << "Original DataFrame:\n";
    printDataFrame(df);

    // Test filter method
    cout << "\nFiltered DataFrame (A >= 3.0):\n";
    DataFrame filtered = df.filter(0, 3.0, true);
    printDataFrame(filtered);

    // Test drop method
    cout << "\nDataFrame after dropping column B:\n";
    df.drop(1); // Drop column B
    printDataFrame(df);

    // Create another DataFrame for merging
    DataFrame df2;
    df2.columnNames = {"A", "D"};
    df2.indexLabels = {"row1", "row2", "row3", "row4"};
    df2.columns.push_back(Array<double>({1.0, 2.0, 3.0, 4.0}));                // Column A
    df2.columns.push_back(Array<string>({"alpha", "beta", "gamma", "delta"})); // Column D

    cout << "\nMerged DataFrame:\n";
    DataFrame merged = df.merge(df2, "A");
    printDataFrame(merged);

    // Test concat method
    cout << "\nConcatenated DataFrame:\n";
    DataFrame concatenated = df.concat(df2, 0); // Concatenate along rows
    printDataFrame(concatenated);

    // Test sort_values method
    cout << "\nDataFrame sorted by column A:\n";
    df.sort_values(0, true); // Sort by column A in ascending order
    printDataFrame(df);

    // Test apply method
    cout << "\nDataFrame after applying a function (double * 2):\n";
    DataFrame applied = df.apply([](const variant<double, string> &val)
                                 {
                                     if (holds_alternative<double>(val))
                                     {
                                         return get<double>(val) * 2; // Double the value
                                     }
                                     return val; // Return the original if it's a string
                                 });
    printDataFrame(applied);

    return 0;
}