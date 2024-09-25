// author: Aryanthepain
#ifndef LIST_H
#define LIST_H
#include <bits/stdc++.h>
#include "node.h"
using namespace std;

class sll
{
public:
    Node *head = NULL;

    void insert(int x);

    void printList();

    int size();

    void deleteAtPos(int i);

    void search(int x);

    void update(int i, int x);

    void deleteList();

    int getPos(int i);
};

#endif