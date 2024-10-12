// author: Aryanthepain
#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

int menu()
{
    cout << "Press the number corresponding to the function you want to execute(-1 to exit)" << endl;
    cout << "1. Add edge" << endl;
    cout << "2. Delete edge" << endl;
    cout << "3. Add another node" << endl;
    cout << "4. Delete a node" << endl;
    cout << "5. Check if edge exists" << endl;
    cout << "6. Print neighbours of a node" << endl;
    cout << "7. BFS on a node" << endl;
    cout << "8. DFS on a node" << endl;
    cout << "9. Print adjacency matrix" << endl;
    cout << "10. See all connected components" << endl;

    int n;
    cin >> n;

    return n;
}

int menuBar()
{
    cout << "Graphs:" << endl;
    cout << "Input number of nodes in the graph" << endl;
    int n;
    cin >> n;
    graph t(n);

    while (true)
    {
        int me = menu();
        if (me == -1)
        {
            cout << "Please give full marks :). Exiting..." << endl;

            return 0;
        }
        switch (me)
        {
        case 1:
        {
            cout << "Input nodes to draw an edge between: " << endl;
            int m, n;
            cin >> m >> n;
            t.addEdge(m, n);
            break;
        }
        case 2:
        {
            cout << "Input nodes to delete an edge between: " << endl;
            int m, n;
            cin >> m >> n;
            t.deleteEdge(m, n);
            break;
        }
        case 3:
        {
            cout << "Adding a node..." << endl;
            t.addNode();
            cout << "Current size: " << t.outputSize() << endl;
            break;
        }
        case 4:
        {
            cout << "Input node to delete:" << endl;
            int n;
            cin >> n;

            t.deleteNode(n);
            break;
        }
        case 5:
        {
            cout << "Input nodes to check an edge between: " << endl;
            int m, n;
            cin >> m >> n;
            cout << (t.searchEdge(m, n) ? "exists" : "does not exist") << endl;

            break;
        }
        case 6:
        {
            cout << "Input node:" << endl;
            int n;
            cin >> n;

            t.printNeighbours(n);
            break;
        }
        case 7:
        {
            cout << "Input starting node:" << endl;
            int n;
            cin >> n;

            t.bfsearch(n);
            break;
        }
        case 8:
        {
            cout << "Input starting node:" << endl;
            int n;
            cin >> n;

            t.dfsearch(n);
            break;
        }
        case 9:
        {
            cout << "_____________________" << endl;
            t.printMatrix();
            break;
        }
        case 10:
        {
            cout << "_____________________" << endl;
            t.connectedComponents();
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    return 0;
}

int main()
{
    return menuBar();
}