// author: Aryanthepain
#ifndef HEAP_H
#define HEAP_H
#include <bits/stdc++.h>
using namespace std;

class maxHeap
{
private:
    int *arr;
    int size;
    int maxSize;

    // indice functions
    int parent(int i);
    int left(int i);
    int right(int i);

    void insertHelper(int x, int i);
    void deleteHelper(int i);
    int getElementOnPos(int x);

public:
    // constructor and deconstrutor
    maxHeap(int size);
    ~maxHeap();

    // functions
    void insert(int x);
    void deleteElement(int x);
    void printAll();
    void printTree(int index = 0, int level = 0);
    int searchElement(int x);
    int heapSize() { return size; }
};

maxHeap::maxHeap(int n)
{
    maxSize = n;
    size = 0;
    arr = new int[size];
}

maxHeap::~maxHeap()
{
    delete[] arr;
}

#endif