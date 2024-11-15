#include "include/testing.h"

int main()
{
    // Test with Array of doubles
    Array<double> doubleArray1({1.1, 2.2, 3.3, 4.4, 5.5});
    Array<double> doubleArray2({6.6, 7.7, 8.8, 9.9, 10.0});

    // Test concatenation
    Array<double> concatenatedDoubleArray = Array<double>::concatenate(doubleArray1, doubleArray2);
    std::cout << "Concatenated Double Array: ";
    concatenatedDoubleArray.print();

    // Test splitting
    size_t numSplits = 2;
    std::vector<Array<double>> splitDoubleArrays = Array<double>::split(concatenatedDoubleArray, numSplits);
    std::cout << "Split Double Arrays: \n";
    for (const auto &arr : splitDoubleArrays)
    {
        arr.print();
    }

    // Test sorting
    Array<double> unsortedDoubleArray({5.5, 3.3, 1.1, 4.4, 2.2});
    std::cout << "Unsorted Double Array: ";
    unsortedDoubleArray.print();
    unsortedDoubleArray.sort();
    std::cout << "Sorted Double Array: ";
    unsortedDoubleArray.print();

    // Test random array generation
    Array<double> randomDoubleArray = Array<double>::randomRand(5);
    std::cout << "Random Double Array: ";
    randomDoubleArray.print();

    // Test sampling with valid size
    try
    {
        Array<double> sampledDoubleArray = concatenatedDoubleArray.sample(3);
        std::cout << "Sampled Double Array: ";
        sampledDoubleArray.print();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test sampling with invalid size
    try
    {
        Array<double> sampledDoubleArray = concatenatedDoubleArray.sample(100); // Invalid size
        std::cout << "Sampled Double Array: ";
        sampledDoubleArray.print();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl; // Expecting an error here
    }

    // Test with Array of strings
    Array<string> stringArray1({"apple", "banana", "cherry"});
    Array<string> stringArray2({"date", "elderberry", "fig"});

    // Test concatenation
    Array<string> concatenatedStringArray = Array<string>::concatenate(stringArray1, stringArray2);
    std::cout << "Concatenated String Array: ";
    concatenatedStringArray.print();

    // Test splitting
    std::vector<Array<string>> splitStringArrays = Array<string>::split(concatenatedStringArray, 2);
    std::cout << "Split String Arrays: \n";
    for (const auto &arr : splitStringArrays)
    {
        arr.print();
    }

    // Test sampling with valid size
    try
    {
        Array<string> sampledStringArray = concatenatedStringArray.sample(2);
        std::cout << "Sampled String Array: ";
        sampledStringArray.print();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test sampling with invalid size
    try
    {
        Array<string> sampledStringArray = concatenatedStringArray.sample(100); // Invalid size
        std::cout << "Sampled String Array: ";
        sampledStringArray.print();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl; // Expecting an error here
    }

    return 0;
}