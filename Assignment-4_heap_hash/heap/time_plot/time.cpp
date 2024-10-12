#include "heap.h"
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// my heap
void timeMY(int n, vector<double> &time_vect)
{
    maxHeap hm(n);

    auto start = high_resolution_clock::now();
    for (int i = 1; i < n; ++i)
    {
        hm.insert(i);
        // cout << i << " inserted" << endl;
    }
    auto end = high_resolution_clock::now();
    // cout << "ended" << endl;
    // hm.~maxHeap();

    duration<double, std::micro> duration = end - start;
    hm.printAll();
    // cout << "duration" << endl;
    // cout << duration.count() << endl;
    time_vect.push_back(duration.count());
    // cout << "hello" << endl;
    return;
}
// STL heap
void timeSTL(int n, vector<double> &time_vect)
{
    vector<int> v;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; ++i)
    {
        v.push_back(i);
    }
    make_heap(v.begin(), v.end());
    auto end = high_resolution_clock::now();

    duration<double, std::micro> duration = end - start;
    time_vect.push_back(duration.count());
    return;
}
int main()
{
    // to store different times
    vector<double> MYheap;
    vector<double> STLheap;
    // different values of n
    vector<int> n = {1, 2, 3, 4, 5, 6, 7, 8, 10, 20};
    // measuring time
    for (int i : n)
    {
        cout << "Measuring time for n= " << i << endl;
        timeMY(i, MYheap);
        timeSTL(i, STLheap);
        cout << "n= " << i << ", My heap Time " << MYheap.back() << " micro sec, STL heap Time= " << STLheap.back() << " micro sec" << endl;
    }
    // maintaining CSV file
    ofstream file("time.csv");
    file << "n,MYheap,STLheap\n";
    for (size_t i = 0; i < n.size(); ++i)
    {
        file << n[i] << "," << MYheap[i] << "," << STLheap[i] << "\n";
    }
    file.close();
    // plotting
    if (system("gnuplot time.gp"))
    {
        cerr << "Error running gnuplot for time.gp" << endl;
    }
    return 0;
}