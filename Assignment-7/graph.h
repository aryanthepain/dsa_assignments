// author: Aryanthepain
#ifndef GRAPH_H
#define GRAPH_H
#include <bits/stdc++.h>
#define INF std::numeric_limits<int>::max()
using namespace std;

class graph
{
private:
    /* data */
    vector<vector<int>> adj_mat;
    int size;

    bool outsideBounds(int x);
    void dfsHelper(int x, vector<bool> &visited);

public:
    graph(int n);
    // no need for destructor as we are using vectors

    // functions
    void addEdge(int first, int second, int weight);
    void deleteEdge(int first, int second);

    void addNode();
    void deleteNode(int n);

    bool searchEdge(int i, int j);
    void printNeighbours(int x);

    void bfsearch(int x);
    void dfsearch(int x);

    void printMatrix();
    void connectedComponents();

    int outputSize() { return size; };
};

#endif