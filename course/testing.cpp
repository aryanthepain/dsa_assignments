#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>           // Include cmath for std::abs
#include "include/Array.h" // Assuming Array.h is in the include folder

// Assertion functions
void assertEqual(double expected, double actual, const std::string &message, double epsilon = 1e-9)
{
    if (std::abs(expected - actual) > epsilon)
    {
        throw std::runtime_error("Assertion failed: " + message + " | Expected: " + std::to_string(expected) + ", Actual: " + std::to_string(actual));
    }
}

void assertEqual(const std::string &expected, const std::string &actual, const std::string &message)
{
    if (expected != actual)
    {
        throw std::runtime_error("Assertion failed: " + message + " | Expected: " + expected + ", Actual: " + actual);
    }
}

void assertTrue(bool condition, const std::string &message)
{
    if (!condition)
    {
        throw std::runtime_error("Assertion failed: " + message);
    }
}

void testArrayDouble()
{
    // Create an Array of doubles
    Array<double> doubleArray({0.1, 0.2, 0.3, 0.4, 0.5});

    // Test initial values
    for (size_t i = 0; i < doubleArray.getData().size(); ++i)
    {
        assertEqual((i + 1) * 0.1, doubleArray[i], "Initial value mismatch at index " + std::to_string(i));
    }

    // Modify an element
    doubleArray[1] = 2.2; // Change the second element to 2.2

    // Test modified value
    assertEqual(2.2, doubleArray[1], "Modified value mismatch at index 1");

    // Test out-of-bounds access (this should throw an exception)
    try
    {
        doubleArray[10]; // Out of bounds
        assertTrue(false, "Expected out_of_range exception not thrown.");
    }
    catch (const std::out_of_range &e)
    {
        // Exception caught, test passes
    }
}

void testArrayString()
{
    // Create an Array of strings
    Array<std::string> stringArray({"Hello", "World", "Test"});

    // Test initial values
    assertEqual("Hello", stringArray[0], "Initial value mismatch at index 0");
    assertEqual("World", stringArray[1], "Initial value mismatch at index 1");
    assertEqual("Test", stringArray[2], "Initial value mismatch at index 2");

    // Modify an element
    stringArray[1] = "Everyone"; // Change the second element to "Everyone"

    // Test modified value
    assertEqual("Everyone", stringArray[1], "Modified value mismatch at index 1");

    // Test out-of-bounds access (this should throw an exception)
    try
    {
        stringArray[5]; // Out of bounds
        assertTrue(false, "Expected out_of_range exception not thrown.");
    }
    catch (const std::out_of_range &e)
    {
        // Exception caught, test passes
    }
}

int main()
{
    try
    {
        testArrayDouble(); // Run tests for double array
        testArrayString(); // Run tests for string array
        std::cout << "All tests passed!" << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl; // Print the error message
    }
    return 0;
}