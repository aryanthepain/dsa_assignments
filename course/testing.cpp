#include "include/testing.h" // Ensure this includes your DataFrame class definition

void testDataFrameFromCSV(const string &csvFilePath)
{
    // Create a DataFrame from the provided CSV file
    DataFrame df(csvFilePath);

    // Print out the data (assuming a method to access the data exists)
    df.print();
}

int main()
{
    string csvFilePath = "./data.csv";

    // Call the test function with the provided CSV file path
    testDataFrameFromCSV(csvFilePath);

    return 0;
}