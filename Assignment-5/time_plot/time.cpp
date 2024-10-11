#include "tree.h"
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    srand(3); // Setting the seed for reproducibility

    const int SIZE = 5; // Size of the array
    double MYbst[SIZE];
    double STLmap[SIZE];
    int n[SIZE] = {10, 50, 100, 500, 1000}; // Use a larger range for better data collection

    // Measure time for n = 10
    int current_n = n[0];
    binarySearchTree tree1;
    unordered_set<int> uniqueValues1; // To ensure unique random values for MYbst

    auto startMY1 = high_resolution_clock::now();
    while (uniqueValues1.size() < current_n)
    {
        int value = rand() % 10000; // Limit the range of random values
        if (uniqueValues1.insert(value).second)
        {
            tree1.insert(value); // Insert into the BST
        }
    }
    auto endMY1 = high_resolution_clock::now();
    MYbst[0] = duration_cast<duration<double, std::micro>>(endMY1 - startMY1).count();
    cout << "timeMY for n = " << current_n << " : " << MYbst[0] << " micro sec" << endl;

    // Measure time for n = 50
    current_n = n[1];
    binarySearchTree tree2;
    unordered_set<int> uniqueValues2; // To ensure unique random values for MYbst

    auto startMY2 = high_resolution_clock::now();
    while (uniqueValues2.size() < current_n)
    {
        int value = rand() % 10000; // Limit the range of random values
        if (uniqueValues2.insert(value).second)
        {
            tree2.insert(value); // Insert into the BST
        }
    }
    auto endMY2 = high_resolution_clock::now();
    MYbst[1] = duration_cast<duration<double, std::micro>>(endMY2 - startMY2).count();
    cout << "timeMY for n = " << current_n << " : " << MYbst[1] << " micro sec" << endl;

    // Measure time for n = 100
    current_n = n[2];
    binarySearchTree tree3;
    unordered_set<int> uniqueValues3; // To ensure unique random values for MYbst

    auto startMY3 = high_resolution_clock::now();
    while (uniqueValues3.size() < current_n)
    {
        int value = rand() % 10000; // Limit the range of random values
        if (uniqueValues3.insert(value).second)
        {
            tree3.insert(value); // Insert into the BST
        }
    }
    auto endMY3 = high_resolution_clock::now();
    MYbst[2] = duration_cast<duration<double, std::micro>>(endMY3 - startMY3).count();
    cout << "timeMY for n = " << current_n << " : " << MYbst[2] << " micro sec" << endl;

    // Measure time for n = 500
    current_n = n[3];
    binarySearchTree tree4;
    unordered_set<int> uniqueValues4; // To ensure unique random values for MYbst

    auto startMY4 = high_resolution_clock::now();
    while (uniqueValues4.size() < current_n)
    {
        int value = rand() % 10000; // Limit the range of random values
        if (uniqueValues4.insert(value).second)
        {
            tree4.insert(value); // Insert into the BST
        }
    }
    auto endMY4 = high_resolution_clock::now();
    MYbst[3] = duration_cast<duration<double, std::micro>>(endMY4 - startMY4).count();
    cout << "timeMY for n = " << current_n << " : " << MYbst[3] << " micro sec" << endl;

    // Measure time for n = 1000
    current_n = n[4];
    binarySearchTree tree5;
    unordered_set<int> uniqueValues5; // To ensure unique random values for MYbst

    auto startMY5 = high_resolution_clock::now();
    while (uniqueValues5.size() < current_n)
    {
        int value = rand() % 10000; // Limit the range of random values
        if (uniqueValues5.insert(value).second)
        {
            tree5.insert(value); // Insert into the BST
        }
    }
    auto endMY5 = high_resolution_clock::now();
    MYbst[4] = duration_cast<duration<double, std::micro>>(endMY5 - startMY5).count();
    cout << "timeMY for n = " << current_n << " : " << MYbst[4] << " micro sec" << endl;

    // Now, measure for STLmap for each n value
    // Measure time for n = 10
    current_n = n[0];
    set<int> v1;

    auto startSTL1 = high_resolution_clock::now();
    while (v1.size() < current_n)
    {
        int value = rand() % 10000; // Limit the range of random values
        v1.insert(value);
    }
    auto endSTL1 = high_resolution_clock::now();
    STLmap[0] = duration_cast<duration<double, std::micro>>(endSTL1 - startSTL1).count();
    cout << "timeSTL for n = " << current_n << " : " << STLmap[0] << " micro sec" << endl;

    // Measure time for n = 50
    current_n = n[1];
    set<int> v2;

    auto startSTL2 = high_resolution_clock::now();
    while (v2.size() < current_n)
    {
        int value = rand() % 10000; // Limit the range of random values
        v2.insert(value);
    }
    auto endSTL2 = high_resolution_clock::now();
    STLmap[1] = duration_cast<duration<double, std::micro>>(endSTL2 - startSTL2).count();
    cout << "timeSTL for n = " << current_n << " : " << STLmap[1] << " micro sec" << endl;

    // Measure time for n = 100
    current_n = n[2];
    set<int> v3;

    auto startSTL3 = high_resolution_clock::now();
    while (v3.size() < current_n)
    {
        int value = rand() % 10000; // Limit the range of random values
        v3.insert(value);
    }
    auto endSTL3 = high_resolution_clock::now();
    STLmap[2] = duration_cast<duration<double, std::micro>>(endSTL3 - startSTL3).count();
    cout << "timeSTL for n = " << current_n << " : " << STLmap[2] << " micro sec" << endl;

    // Measure time for n = 500
    current_n = n[3];
    set<int> v4;

    auto startSTL4 = high_resolution_clock::now();
    while (v4.size() < current_n)
    {
        int value = rand() % 10000; // Limit the range of random values
        v4.insert(value);
    }
    auto endSTL4 = high_resolution_clock::now();
    STLmap[3] = duration_cast<duration<double, std::micro>>(endSTL4 - startSTL4).count();
    cout << "timeSTL for n = " << current_n << " : " << STLmap[3] << " micro sec" << endl;

    // Measure time for n = 1000
    current_n = n[4];
    set<int> v5;

    auto startSTL5 = high_resolution_clock::now();
    while (v5.size() < current_n)
    {
        int value = rand() % 10000; // Limit the range of random values
        v5.insert(value);
    }
    auto endSTL5 = high_resolution_clock::now();
    STLmap[4] = duration_cast<duration<double, std::micro>>(endSTL5 - startSTL5).count();
    cout << "timeSTL for n = " << current_n << " : " << STLmap[4] << " micro sec" << endl;

    // Write results to CSV file
    ofstream file("time.csv");
    if (file.is_open())
    {
        file << "n,MYbst,STLmap\n";
        for (int i = 0; i < SIZE; ++i)
        {
            file << n[i] << "," << MYbst[i] << "," << STLmap[i] << "\n";
        }
        file.close();
        cout << "Results written to time.csv successfully." << endl;
    }
    else
    {
        cerr << "Error opening file for writing" << endl;
    }

    // plotting
    if (system("gnuplot time.gp"))
    {
        cerr << "Error running gnuplot for time.gp" << endl;
    }

    return 0;
}
