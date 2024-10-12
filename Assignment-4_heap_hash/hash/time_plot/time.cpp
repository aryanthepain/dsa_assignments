#include "hash.h"
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// my hash
void timeMY(int n, vector<double> &time_vect)
{
    hashMap hm;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; ++i)
    {
        hm.insert(i);
    }
    for (int i = 0; i < n; ++i)
    {
        hm.search(i);
    }
    auto end = high_resolution_clock::now();
    duration<double, std::micro> duration = end - start;
    time_vect.push_back(duration.count());
    return;
}
// STL hash
void timeSTL(int n, vector<double> &time_vect)
{
    map<int, int> m;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; ++i)
    {
        m[i] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        m.find(i);
    }
    auto end = high_resolution_clock::now();
    duration<double, std::micro> duration = end - start;
    time_vect.push_back(duration.count());
    return;
}
int main()
{
    // to store different times
    vector<double> MYhash;
    vector<double> STLhash;
    // different values of n
    vector<int> n = {100, 500, 1000, 2500, 5000, 7500, 10000};
    // measuring time
    for (int i : n)
    {
        cout << "Measuring time for n= " << i << endl;
        timeMY(i, MYhash);
        timeSTL(i, STLhash);
        cout << "n= " << i << ", My hash Time " << MYhash.back() << " micro sec, STL hash Time= " << STLhash.back() << " micro sec" << endl;
    }
    // maintaining CSV file
    ofstream file("time.csv");
    file << "n,MYhash,STLhash\n";
    for (size_t i = 0; i < n.size(); ++i)
    {
        file << n[i] << "," << MYhash[i] << "," << STLhash[i] << "\n";
    }
    file.close();
    // plotting
    if (system("gnuplot time.gp"))
    {
        cerr << "Error running gnuplot for time.gp" << endl;
    }
    return 0;
}