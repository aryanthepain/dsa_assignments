// author: Aryanthepain
#include "include/testing.h"

int main()
{
    // Test with double
    vector<double> darr = {1, 2, 3, 4, 5, 6};
    Array<double> arrayFromDoubleVector(darr);
    cout << "Array from double Vector: ";
    arrayFromDoubleVector.print();

    // Test with int
    vector<int> iarr = {1, 2, 3, 4, 5, 6};
    Array<int> arrayFromIntVector(iarr);
    cout << "Array from int Vector: ";
    arrayFromIntVector.print();

    // Test with string
    vector<string> sarr = {"1", "2", "3", "4", "5", "6", "a", "b", "c"};
    Array<string> arrayFromStringVector(sarr);
    cout << "Array from string Vector: ";
    arrayFromStringVector.print();

    // Test with char
    vector<char> carr = {'1', '2', '3', '4', '5', '6', 'a', 'b', 'c'};
    Array<char> arrayFromCharVector(carr);
    cout << "Array from char Vector: ";
    arrayFromCharVector.print();

    // Create an array of zeros
    Array<double> zerosArray = Array<double>::zeros(5);
    cout << "Zeros Array: ";
    zerosArray.print();

    // Create an array of ones
    Array<double> onesArray = Array<double>::ones(5);
    cout << "Ones Array: ";
    onesArray.print();

    // Create an array with arange
    Array<double> rangeArray = Array<double>::arange(0.0, 5.0, 0.5);
    cout << "Arange Array: ";
    rangeArray.print();

    // Create an array with linspace
    Array<double> linspaceArray = Array<double>::linspace(0.0, 1.0, 5);
    cout << "Linspace Array: ";
    linspaceArray.print();

    // Create an array of zeros
    Array<string> szerosArray = Array<string>::zeros(5);
    cout << "Zeros Array(string): ";
    szerosArray.print();

    // Create an array of ones
    Array<string> sonesArray = Array<string>::ones(5);
    cout << "Ones Array(string): ";
    sonesArray.print();

    return 0;
}