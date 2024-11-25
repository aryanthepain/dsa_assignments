#include "include/testing.h" // Include your DataFrame class definition

int main()
{
    // Create a sample DataFrame
    DataFrame df;

    // Create sample data for the DataFrame
    Array<double> doubleColumn({1.0, 2.0, 2.0, 3.0, 4.0});
    Array<string> stringColumn({"apple", "banana", "apple", "orange", "banana"});

    // Add columns to the DataFrame
    df.addColumn("Numbers", doubleColumn);
    df.addColumn("Fruits", stringColumn);

    // Print the DataFrame
    cout << "DataFrame:" << endl;
    df.print();
    cout << endl;

    // // Describe the DataFrame
    // cout << "Describing the DataFrame:" << endl;
    // df.describe();
    // cout << endl;

    // // Get and print the shape of the DataFrame
    // auto shape = df.shape();
    // cout << "Shape of the DataFrame: " << shape.first << " rows, " << shape.second << " columns." << endl;
    // cout << endl;

    // Get and print unique values for the "Numbers" column
    cout << "Unique values in the 'Numbers' column: ";
    auto uniqueNumbers = df.unique(0); // Assuming 0 is the index for the "Numbers" column
    uniqueNumbers.print();
    cout << endl;

    // Get and print unique values for the "Fruits" column
    cout << "Unique values in the 'Fruits' column: ";
    auto uniqueFruits = df.uniqueString(1); // Assuming 1 is the index for the "Fruits" column
    uniqueFruits.print();
    cout << endl;

    // Get and print the count of unique values for the "Numbers" column
    size_t uniqueCountNumbers = df.nunique(0);
    cout << "Number of unique values in the 'Numbers' column: " << uniqueCountNumbers << endl;

    // Get and print the count of unique values for the "Fruits" column
    size_t uniqueCountFruits = df.nunique(1);
    cout << "Number of unique values in the 'Fruits' column: " << uniqueCountFruits << endl;

    return 0;
}