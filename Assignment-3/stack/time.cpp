#include "stack.h"
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// my stack
void timeMY(int n, vector<double> &time_vect)
{
    Node *head = new Node;
    head->next = nullptr;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; ++i)
    {
        push(head, i);
    }
    for (int i = 0; i < n; ++i)
    {
        pop(head);
    }
    auto end = high_resolution_clock::now();

    duration<double, std::micro> duration = end - start;
    time_vect.push_back(duration.count());

    return;
}

// STL stack
void timeSTL(int n, vector<double> &time_vect)
{
    stack<int> q;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; ++i)
    {
        q.push(i);
    }
    for (int i = 0; i < n; ++i)
    {
        q.pop();
    }
    auto end = high_resolution_clock::now();

    duration<double, std::micro> duration = end - start;
    time_vect.push_back(duration.count());

    return;
}

int main()
{
    // to store different times
    vector<double> MYstack;
    vector<double> STLstack;

    // different values of n
    vector<int> n = {100, 200, 1000, 2500, 5000, 7500, 10000};

    // measuring time
    for (int i : n)
    {
        cout << "Measuring time for n= " << i << endl;
        timeMY(i, MYstack);
        timeSTL(i, STLstack);

        cout << "n= " << i << ", My stack Time " << MYstack.back() << " micro sec, STL stack Time= " << STLstack.back() << " micro sec" << endl;
    }

    // maintaining CSV file
    ofstream file("time.csv");
    file << "n,MYstack,STLstack\n";
    for (size_t i = 0; i < n.size(); ++i)
    {
        file << n[i] << "," << MYstack[i] << "," << STLstack[i] << "\n";
    }
    file.close();

    // plotting
    if (system("gnuplot time.gp"))
    {
        cerr << "Error running gnuplot for time.gp" << endl;
    }

    return 0;
}
