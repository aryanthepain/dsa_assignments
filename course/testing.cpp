#include "include/testing.h" // Adjust the path as necessary

int main()
{
    // Create an Array of doubles
    Array<double> doubleArray(vector<double>{1.1, 2.2, 3.3, 4.4, 5.5});

    // Test print() method for doubles
    cout << "Double Array: ";
    doubleArray.print(); // Should print: 1.1 2.2 3.3 4.4 5.5

    // Test loc() method for doubles
    try
    {
        cout << "Accessing index 2 using loc (double): " << doubleArray.loc(2) << endl; // Should print 3.3
        cout << "Accessing index 5 using loc (double): " << doubleArray.loc(5) << endl; // Should throw an exception
    }
    catch (const out_of_range &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    // Test getData() method for doubles
    vector<double> doubleData = doubleArray.getData();
    cout << "Data from getData (double): ";
    for (const double &val : doubleData)
    {
        cout << val << " "; // Should print: 1.1 2.2 3.3 4.4 5.5
    }
    cout << endl;

    // Create an Array of strings
    Array<string> stringArray(vector<string>{"one", "two", "three", "four", "five"});

    // Test print() method for strings
    cout << "String Array: ";
    stringArray.print(); // Should print: one two three four five

    // Test loc() method for strings
    try
    {
        cout << "Accessing index 2 using loc (string): " << stringArray.loc(2) << endl; // Should print "three"
        cout << "Accessing index 5 using loc (string): " << stringArray.loc(5) << endl; // Should throw an exception
    }
    catch (const out_of_range &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    // Test getData() method for strings
    vector<string> stringData = stringArray.getData();
    cout << "Data from getData (string): ";
    for (const string &val : stringData)
    {
        cout << val << " "; // Should print: one two three four five
    }
    cout << endl;

    return 0;
}