// author: Aryanthepain
#ifndef TREE_H
#define TREE_H
#include <bits/stdc++.h>
using namespace std;

class binarySearchTree
{
private:
    int val;
    binarySearchTree *large;
    binarySearchTree *small;

    void deleteHelper(int x, binarySearchTree *curr);

public:
    binarySearchTree(int x = -1)
    {
        val = x;
        large = nullptr;
        small = nullptr;
    }
    ~binarySearchTree()
    {
        if (large)
            delete large;
        if (small)
            delete small;

        large = nullptr;
        small = nullptr;

        delete this;
    }

    // functions
    void insert(int x);
    void deleteElement(int x);
    void printTree(int level = 0);
    bool searchElement(int x);
    void preOrder();
    void inOrder();
    void postOrder();
};

#endif