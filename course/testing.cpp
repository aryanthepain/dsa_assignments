#include "include/testing.h" // Include your DataFrame class definition

int main()
{
    // Sample data for testing
    DataFrame df("./data.csv");

    df.print();

    // // Test the head method
    // cout << "Head of DataFrame (first 3 rows):" << endl;
    // df.head(3);

    // // Test the tail method
    // cout << "\nTail of DataFrame (last 2 rows):" << endl;
    // df.tail(2);

    // // Test the iloc method
    // cout << "\nElement at iloc(1, 2): " << get<double>(df.iloc(1, 2)) << endl; // Should return 6.0

    // // Test the loc method
    // cout << "\nElement at loc('Charlie', 'Age'): " << get<double>(df.loc("3", "Age")) << endl; // Should return 35

    // // Test invalid indexing
    // cout << "\nTesting invalid iloc (out of bounds):" << endl;
    // df.iloc(10, 2); // Should print "Index out of bounds!"

    // cout << "\nTesting invalid loc (row not found):" << endl;
    // df.loc("Nonexistent", "Age"); // Should print "Row label not found!"

    // cout << "\nTesting invalid loc (column not found):" << endl;
    // df.loc("Alice", "Nonexistent"); // Should print "Column label not found!"

    // // Test the sample method
    // DataFrame sampledDf = df.sample(3);
    // sampledDf.print();

    // Test the copy method
    DataFrame copiedDf = df.copy();
    copiedDf.to_csv("output.csv");

    // // Test the to_csv method
    // df.to_csv("output.csv");
    // cout << "Data exported to output.csv" << endl;

    return 0;
}