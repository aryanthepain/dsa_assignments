#include "graph.h"
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void timeDijkstra(int nodes, int edges, vector<double> &time_vect, graph &g)
{
    auto start = high_resolution_clock::now();
    g.dijkstra(rand() % g.outputSize(), rand() % g.outputSize()); // From node 0 to last node
    auto end = high_resolution_clock::now();

    duration<double, std::micro> duration = end - start;
    time_vect.push_back(duration.count());
}

void timeBellmanFord(int nodes, vector<double> &time_vect, graph &g)
{
    auto start = high_resolution_clock::now();
    g.bellmanFord(rand() % g.outputSize());
    auto end = high_resolution_clock::now();

    duration<double, std::micro> duration = end - start;
    time_vect.push_back(duration.count());
}

void timeFloydWarshall(int nodes, vector<double> &time_vect, graph &g)
{
    auto start = high_resolution_clock::now();
    g.floydWarshall();
    auto end = high_resolution_clock::now();

    duration<double, std::micro> duration = end - start;
    time_vect.push_back(duration.count());
}

int main()
{
    srand(time(0)); // Seed for reproducibility
    vector<double> dijkstraTimes, bellmanTimes, floydTimes;
    vector<int> sizes = {10, 50, 100, 500, 1000}; // Sizes for testing

    for (int size : sizes)
    {
        int edges = size * 10; // Arbitrary number of edges

        // Initialize a graph
        graph g(size);
        g.generateRandomGraph();

        cout << "Measuring time for graph size = " << size << endl;
        timeDijkstra(size, edges, dijkstraTimes, g);
        timeBellmanFord(size, bellmanTimes, g);
        timeFloydWarshall(size, floydTimes, g);

        cout << "Size = " << size << ", Dijkstra Time = " << dijkstraTimes.back() << " micro sec, "
             << "Bellman-Ford Time = " << bellmanTimes.back() << " micro sec, "
             << "Floyd-Warshall Time = " << floydTimes.back() << " micro sec" << endl;
    }

    // Write results to CSV file
    ofstream file("graph_times.csv");
    file << "Size,Dijkstra,Bellman-Ford,Floyd-Warshall\n";
    for (size_t i = 0; i < sizes.size(); ++i)
    {
        file << sizes[i] << "," << dijkstraTimes[i] << "," << bellmanTimes[i] << "," << floydTimes[i] << "\n";
    }
    file.close();

    // Plotting
    if (system("gnuplot time.gp"))
    {
        cerr << "Error running gnuplot for graph_times.gp" << endl;
    }

    return 0;
}
