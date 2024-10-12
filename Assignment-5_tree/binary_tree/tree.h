// author: Aryanthepain
#ifndef TREE_H
#define TREE_H
#include <bits/stdc++.h>
using namespace std;

class binaryTree
{
private:
    int *arr;
    int size;
    int maxSize;

    // indice functions
    int parent(int i);
    int left(int i);
    int right(int i);

    int getElementOnPos(int x);
    void deleteHelper(int i);

public:
    // constructor and deconstrutor
    binaryTree(int n)
    {
        maxSize = n;
        size = 0;
        arr = new int[size];
    }
    ~binaryTree()
    {
        delete[] arr;
    }

    // functions
    void insert(int x);
    void deleteElement(int x);
    void printAll();
    void printTree(int index = 0, int level = 0);
    int searchElement(int x);
    void preOrder(int i = 0);
    void inOrder(int i = 0);
    void postOrder(int i = 0);
};

#endif