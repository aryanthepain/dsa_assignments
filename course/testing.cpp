#include "include/testing.h" // Include your DataFrame class definition

int main()
{
    // Create a sample DataFrame
    DataFrame df;

    // Assume we have methods to add columns to the DataFrame
    // For this example, let's say we have two columns: one with doubles and one with strings
    Array<double> doubleColumn({1.0, 2.0, 2.0, 3.0, 4.0});
    Array<string> stringColumn({"apple", "banana", "apple", "orange", "banana"});

    // Add these columns to the DataFrame
    df.addColumn("Numbers", doubleColumn);
    df.addColumn("Fruits", stringColumn);

    df.print();

    // Test the describe function
    cout << "Describing the DataFrame:" << endl;
    df.describe();
    cout << endl;

    // Test the shape function
    auto shape = df.shape();
    cout << "Shape of the DataFrame: " << shape.first << " rows, " << shape.second << " columns." << endl;
    cout << endl;

    // Test the unique function for the double column
    vector<string> uniqueNumbers = df.unique(0); // Assuming 0 is the index for the "Numbers" column
    cout << "Unique values in the 'Numbers' column: ";
    for (const auto &value : uniqueNumbers)
    {
        cout << value << " ";
    }
    cout << endl;

    // Test the unique function for the string column
    vector<string> uniqueFruits = df.unique(1); // Assuming 1 is the index for the "Fruits" column
    cout << "Unique values in the 'Fruits' column: ";
    for (const auto &value : uniqueFruits)
    {
        cout << value << " ";
    }
    cout << endl;

    // Test the nunique function for the double column
    size_t uniqueCountNumbers = df.nunique(0);
    cout << "Number of unique values in the 'Numbers' column: " << uniqueCountNumbers << endl;

    // Test the nunique function for the string column
    size_t uniqueCountFruits = df.nunique(1);
    cout << "Number of unique values in the 'Fruits' column: " << uniqueCountFruits << endl;

    return 0;
}