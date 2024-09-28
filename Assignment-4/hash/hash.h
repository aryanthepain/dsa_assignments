// author: Aryanthepain
#ifndef HASH_H
#define HASH_H
#include <bits/stdc++.h>
#include "list.h"
using namespace std;

class hashMap
{
private:
    sll arr[10];

public:
    ~hashMap()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i].deleteList();
        }
    }

    void insert(int x);

    void printAll();

    void deleteElement(int x);

    int search(int x);
};

#endif