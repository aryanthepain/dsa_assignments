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
    void insert(int x);

    void search(int x);

    void printAll();

    void deleteElement(int x);
};

#endif