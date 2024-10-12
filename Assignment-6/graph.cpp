// author: Aryanthepain
#include "graph.h"

graph::graph(int n)
{
    // make a n*n map
    adj_mat.resize(n, vector<int>(n, 0));
    size = n;
}

bool graph::outsideBounds(int x)
{
    return (x >= size || x < 0);
}

void graph::addEdge(int first, int second)
{
    if (first >= size || second >= size || first < 0 || second < 0)
        return;

    adj_mat[first][second] = 1;
    adj_mat[second][first] = 1;

    return;
}
void graph::deleteEdge(int first, int second)
{
    if (first >= size || second >= size || first < 0 || second < 0)
        return;

    adj_mat[first][second] = 0;
    adj_mat[second][first] = 0;

    return;
}

void graph::addNode()
{
    for (int i = 0; i < size; i++)
    {
        adj_mat[i].push_back(0);
    }

    size++;
    adj_mat.push_back(vector<int>(size, 0));

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
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return;
}

bool graph::searchEdge(int i, int j)
{
    if (outsideBounds(i) || outsideBounds(j))
        return false;
    return (adj_mat[i][j] && adj_mat[i][j]);
}

void graph::printNeighbours(int x)
{
    if (outsideBounds(x))
        return;

    for (int i = 0; i < size; i++)
    {
        if (adj_mat[x][i])
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
        if (adj_mat[x][i] && !visited[i])
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
            if (adj_mat[foo][i] && !visited[i])
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

/*
int main()
{
    cout << "graph size" << endl;
    int n;
    cin >> n;
    graph hi(n);

    for (int i = 0; i < n * 2; i++)
    {
        hi.addEdge(rand() % n, rand() % n);
    }

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
        if (me == -1)
        {
            break;
        }

        cout << "Node:" << endl;
        int i, j;
        cin >> i;
        // cin >> j;

        hi.deleteNode(i);
    }

    hi.connectedComponents();
}
*/