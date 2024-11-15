#include "include/testing.h"

int main()
{
    // Test case 1: Unique values
    Array<double> intArray({1, 2, 2, 3, 4, 4, 5});
    Array<double> uniqueIntArray = intArray.unique();
    std::cout << "Unique integers: ";
    uniqueIntArray.print(); // Expected output: 1 2 3 4 5

    // Test case 2: All unique values
    Array<double> doubleArray({0.1, 0.2, 0.3, 0.4});
    Array<double> uniqueDoubleArray = doubleArray.unique();
    std::cout << "Unique doubles: ";
    uniqueDoubleArray.print(); // Expected output: 0.1 0.2 0.3 0.4

    // Test case 3: All elements are the same
    Array<std::string> stringArray({"test", "test", "test"});
    Array<std::string> uniqueStringArray = stringArray.unique();
    std::cout << "Unique strings: ";
    uniqueStringArray.print(); // Expected output: test

    // Test case 4: Mixed values with duplicates
    Array<double> mixedArray({5, 1, 2, 5, 3, 2, 1});
    Array<double> uniqueMixedArray = mixedArray.unique();
    std::cout << "Unique mixed integers: ";
    uniqueMixedArray.print(); // Expected output: 1 2 3 5

    return 0;
}