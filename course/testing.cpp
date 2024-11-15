#include "include/testing.h"

#include <iostream>
#include "Array.h" // Make sure this header includes the Array class definition

int main()
{
    // Create some non-zero arrays for testing
    Array<double> array1({1.0, 2.0, 3.0, 4.0, 5.0});
    Array<double> array2({5.0, 4.0, 3.0, 2.0, 1.0});

    // Test addition
    Array<double> sumArray = array1.add(array2);
    std::cout << "Sum: ";
    sumArray.print(); // Assuming there's a print method

    // Test subtraction
    Array<double> diffArray = array1.subtract(array2);
    std::cout << "Difference: ";
    diffArray.print();

    // Test multiplication
    Array<double> prodArray = array1.multiply(array2);
    std::cout << "Product: ";
    prodArray.print();

    // Test division
    Array<double> divArray = array1.divide(array2);
    std::cout << "Division: ";
    divArray.print();

    // Test sum
    double totalSum = array1.sum();
    std::cout << "Sum of array1: " << totalSum << std::endl;

    // Test mean
    double meanValue = array1.mean();
    std::cout << "Mean of array1: " << meanValue << std::endl;

    // Test standard deviation
    double stdValue = array1.std();
    std::cout << "Standard Deviation of array1: " << stdValue << std::endl;

    // Test variance
    double varValue = array1.var();
    std::cout << "Variance of array1: " << varValue << std::endl;

    // Test cumulative sum
    Array<double> cumsumArray = array1.cumsum();
    std::cout << "Cumulative Sum of array1: ";
    cumsumArray.print();

    // Test cumulative product
    Array<double> cumprodArray = array1.cumprod();
    std::cout << "Cumulative Product of array1: ";
    cumprodArray.print();

    // Test quartiles
    auto quartiles = array1.quartiles();
    std::cout << "Quartiles (Q1, Q2, Q3): "
              << std::get<0>(quartiles) << ", "
              << std::get<1>(quartiles) << ", "
              << std::get<2>(quartiles) << std::endl;

    // Test max
    double maxValue = array1.max();
    std::cout << "Max of array1: " << maxValue << std::endl;

    // Test min
    double minValue = array1.min();
    std::cout << "Min of array1: " << minValue << std::endl;

    return 0;
}