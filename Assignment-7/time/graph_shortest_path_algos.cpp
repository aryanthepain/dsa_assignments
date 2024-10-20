// author: Aryanthepain
#include "graph.h"

void graph::dijkstra(int src, int dest)
{
    if (outsideBounds(src) || outsideBounds(dest))
    {
        cerr << "Start or end nodes out of bounds" << endl;
        return;
    }

    vector<int> dist(size, INF);
    vector<int> parent(size, -1); // To store the shortest path tree
    dist[src] = 0;
    vector<bool> visited(size, false);

    for (int i = 0; i < size - 1; ++i)
    {
        int u = -1;

        // Find the unvisited node with the smallest distance
        for (int j = 0; j < size; ++j)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }

        if (dist[u] == INF)
        {
            break;
        }

        visited[u] = true;

        // Update the distance for each neighbor of u
        for (int v = 0; v < size; ++v)
        {
            if (adj_mat[u][v] != INF && !visited[v])
            {
                int newDist = dist[u] + adj_mat[u][v];
                if (newDist < dist[v])
                {
                    dist[v] = newDist;
                    parent[v] = u; // Update parent
                }
            }
        }
    }

    if (dist[dest] == INF)
    {
        cout << "No path found" << endl;
        return;
    }

    // output not required for time
    /*
        // Output the distance from source to destination
        cout << "Distance from node " << src << " to node " << dest << " is " << dist[dest] << endl;

        // Output the path from source to destination
        vector<int> path;
        for (int v = dest; v != -1; v = parent[v])
        {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (int v : path)
        {
            cout << v << " ";
        }
        cout << endl;
    */
    return;
}

void graph::bellmanFord(int src)
{
    if (outsideBounds(src))
    {
        return;
    }

    vector<int> dist(size, INF);
    vector<int> parent(size, -1); // To track the shortest path tree
    dist[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i < size; ++i)
    {
        for (int u = 0; u < size; ++u)
        {
            for (int v = 0; v < size; ++v)
            {
                if (adj_mat[u][v] != INF)
                {
                    int weight = adj_mat[u][v];
                    if (dist[u] != INF && dist[u] + weight < dist[v])
                    {
                        dist[v] = dist[u] + weight;
                        parent[v] = u;
                    }
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < size; ++u)
    {
        for (int v = 0; v < size; ++v)
        {
            if (adj_mat[u][v] != INF)
            {
                int weight = adj_mat[u][v];
                if (dist[u] != INF && dist[u] + weight < dist[v])
                {
                    cout << "Graph contains a negative-weight cycle" << endl;
                    return;
                }
            }
        }
    }

    // output not required for time
    /*
        // Output the distances from the source to each node
        cout << "Distances from node " << src << ":" << endl;
        for (int i = 0; i < size; ++i)
        {
            if (dist[i] == INF)
            {
                cout << i << ": I" << endl;
            }
            else
            {
                cout << i << ": " << dist[i] << endl;
            }
        }
    */
    return;
}

void graph::floydWarshall()
{
    vector<vector<int>> dist = adj_mat; // Initialize distance matrix with adjacency matrix

    for (int k = 0; k < size; ++k)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // output not required for time
    /*
        // Output the shortest distances between all pairs of nodes
        cout << "Shortest distances between every pair of nodes:" << endl;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (dist[i][j] == INF)
                {
                    cout << "I ";
                }
                else
                {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    */
    return;
}
