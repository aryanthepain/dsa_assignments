#include "include/testing.h" // Include your DataFrame class definition

int main()
{
    // Sample data for testing
    DataFrame df("./data.csv");

    df.print();

    // Test search functions
    cout << "Testing searchRowByColumn:" << endl;
    cout << "Searching for Age 30.0: Column Index = " << df.searchRowByColumn("Age", 30.0) << endl;                              // Expected: 0
    cout << "Searching for Age 25.0: Column Index = " << df.searchRowByColumn("Age", 25.0) << endl;                              // Expected: 1
    cout << "Searching for Height 5.5: Column Index = " << df.searchRowByColumn("Height", 5.5) << endl;                          // Expected: 0
    cout << "Searching for Name 'Alice': Column Index = " << df.searchRowByColumn("Name", std::string("Alice")) << endl;         // Expected: 0
    cout << "Searching for Name 'NotInList': Column Index = " << df.searchRowByColumn("Name", std::string("NotInList")) << endl; // Expected: -1

    // Out of bounds test for searchRowByColumn
    cout << "Searching for non-existent column 'NonExistent': Column Index = " << df.searchRowByColumn("NonExistent", 30.0) << endl; // Expected: -1

    cout << "\nTesting searchColumn ByRow:" << endl;
    cout << "Searching for 'Bob' in row 1: Result = " << df.searchColumnByRow(1, std::string("Bob")) << endl;         // Expected: 0
    cout << "Searching for 'Alice' in row 0: Result = " << df.searchColumnByRow(0, std::string("Alice")) << endl;     // Expected: 0
    cout << "Searching for 'Charlie' in row 2: Result = " << df.searchColumnByRow(2, std::string("Charlie")) << endl; // Expected: 0

    // Out of bounds test for searchColumnByRow
    cout << "Searching in out of bounds row 10: Result = " << df.searchColumnByRow(10, std::string("Bob")) << endl;   // Expected: -1
    cout << "Searching in out of bounds row -1: Result = " << df.searchColumnByRow(-1, std::string("Alice")) << endl; // Expected: -1

    return 0;
}