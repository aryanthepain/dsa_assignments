#include "queue.h"
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// my queue
void timeMY(int n, vector<double> &time_vect)
{
    Node *head = new Node;
    head->next = nullptr;
    Node *head1 = new Node;
    head1->next = nullptr;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; ++i)
    {
        enqueue(head, head1, i);
    }
    for (int i = 0; i < n; ++i)
    {
        dequeue(head);
    }
    auto end = high_resolution_clock::now();

    duration<double, std::micro> duration = end - start;
    time_vect.push_back(duration.count());

    return;
}

// STL queue
void timeSTL(int n, vector<double> &time_vect)
{
    queue<int> q;
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
    vector<double> MYqueue;
    vector<double> STLqueue;

    // different values of n
    vector<int> n = {10, 50, 100, 200, 1000};

    // measuring time
    for (int i : n)
    {
        cout << "Measuring time for n= " << i << endl;
        timeMY(i, MYqueue);
        timeSTL(i, STLqueue);

        cout << "n= " << i << ", My QueueFromStack Time " << MYqueue.back() << " micro sec, STL Queue Time= " << STLqueue.back() << " micro sec" << endl;
    }

    // maintaining CSV file
    ofstream file("time.csv");
    file << "n,MYqueueFromStack,STLqueue\n";
    for (size_t i = 0; i < n.size(); ++i)
    {
        file << n[i] << "," << MYqueue[i] << "," << STLqueue[i] << "\n";
    }
    file.close();

    // plotting
    //  int plot = system("gnuplot time.gp");
    if (system("gnuplot time.gp"))
    {
        cerr << "Error running gnuplot for time.gp" << endl;
    }

    return 0;
}
