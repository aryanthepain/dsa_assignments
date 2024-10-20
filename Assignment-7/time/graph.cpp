// author: Aryanthepain
#include "graph.h"

graph::graph(int n)
{
    // make a n*n map
    adj_mat.resize(n, vector<int>(n, INF));
    size = n;

    for (int i = 0; i < size; i++)
    {
        adj_mat[i][i] = 0;
    }
}

graph::~graph()
{
    adj_mat.clear();
    size = 0;
}

bool graph::outsideBounds(int x)
{
    return (x >= size || x < 0);
}

void graph::addEdge(int first, int second, int weight)
{
    if (outsideBounds(first) || outsideBounds(second))
        return;

    adj_mat[first][second] = weight;

    return;
}

void graph::deleteEdge(int first, int second)
{
    if (outsideBounds(first) || outsideBounds(second))
        return;

    adj_mat[first][second] = INF;

    return;
}

void graph::addNode()
{
    for (int i = 0; i < size; i++)
    {
        adj_mat[i].push_back(INF);
    }

    size++;
    adj_mat.push_back(vector<int>(size, INF));
    adj_mat[size - 1][size - 1] = 0;

    return;
}

void graph::deleteNode(int n)
{
    if (outsideBounds(n))
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        adj_mat[i].erase(adj_mat[i].begin() + n);
    }
    adj_mat.erase(adj_mat.begin() + n);
    size--;

    return;
}

void graph::printMatrix()
{
    cout << "Adjacency matrix:" << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (adj_mat[i][j] == INF)
            {
                cout << "i" << " ";
            }
            else
            {
                cout << adj_mat[i][j] << " ";
            }
        }
        cout << endl;
    }

    return;
}

bool graph::searchEdge(int i, int j)
{
    if (outsideBounds(i) || outsideBounds(j))
        return false;

    if (adj_mat[i][j] == INF)
    {
        return false;
    }

    return true;
}

void graph::printNeighbours(int x)
{
    if (outsideBounds(x))
        return;

    for (int i = 0; i < size; i++)
    {
        if (adj_mat[x][i] != INF)
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

void graph::dfsHelper(int x, vector<bool> &visited)
{
    if (visited[x])
    {
        return;
    }

    visited[x] = true;
    cout << x << " ";

    for (int i = 0; i < size; i++)
    {
        if (adj_mat[x][i] != INF && !visited[i])
        {
            dfsHelper(i, visited);
        }
    }
}
void graph::dfsearch(int x)
{
    if (outsideBounds(x))
    {
        return;
    }

    vector<bool> visited(size, false);

    cout << "dfs: ";
    dfsHelper(x, visited);

    cout << endl;
}

void graph::bfsearch(int x)
{
    if (outsideBounds(x))
    {
        return;
    }

    vector<bool> visited(size, false);
    queue<int> visStack;

    cout << "bfs: ";

    cout << x << " ";
    visStack.push(x);
    visited[x] = true;

    while (!visStack.empty())
    {
        int foo = visStack.front();
        visStack.pop();

        for (int i = 0; i < size; i++)
        {
            if (adj_mat[foo][i] != INF && !visited[i])
            {
                visited[i] = true;
                visStack.push(i);
                cout << i << " ";
            }
        }
    }

    cout << endl;
}

void graph::connectedComponents()
{
    vector<bool> visited(size, false);
    int component = 0;

    for (int i = 0; i < size; i++)
    {
        if (!visited[i])
        {
            cout << "Component " << ++component << ": ";
            dfsHelper(i, visited);
            cout << endl;
        }
    }
}

void graph::generateRandomGraph()
{
    srand(time(0)); // Seed for random number generation

    int numEdges = rand() % size + size;

    for (int i = 0; i < numEdges; ++i)
    {
        int u = rand() % size;
        int v = rand() % size;
        int weight = rand() % 8 + 1; // Weights between 1 and 9

        if (u != v)
        {
            addEdge(u, v, weight);
        }
        else
        {
            i--;
        }
    }
}

/*
int main()
{
    cout << "graph size" << endl;
    int n;
    cin >> n;
    graph hi(n);

    // hi.generateRandomGraph();

    hi.printMatrix();

    while (true)
    {
        cout << "function:";
        int me;
        cin >> me;
        if (me == 1)
        {
            hi.printMatrix();
            continue;
        }
        if (me == 0)
        {
            int m, n, w;
            cin >> m >> n >> w;
            hi.addEdge(m, n, w);
            continue;
        }
        if (me == -1)
        {
            break;
        }

        // cout << "Node:" << endl;
        // int i, j;
        // cin >> i;
        // // cin >> j;

        if (me == 2)
        {
            cout << "Input nodes to check shortest distance between: " << endl;
            int m, n;
            cin >> m >> n;
            hi.dijkstra(m, n);
        }
        if (me == 3)
        {
            cout << "Input source node:" << endl;
            int m;
            cin >> m;
            hi.bellmanFord(m);
        }
        if (me == 4)
        {
            cout << "____________________________" << endl;
            hi.floydWarshall();
        }
    }
}
*/