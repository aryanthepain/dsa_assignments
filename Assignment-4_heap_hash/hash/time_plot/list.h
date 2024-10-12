// author: Aryanthepain
#ifndef LIST_H
#define LIST_H
#include <bits/stdc++.h>
#include "node.h"
using namespace std;

class sll
{
public:
    int size = 0;
    Node *head = NULL;

    void insert(int x);

    void printList();

    int listSize();

    void deleteAtPos(int i);

    int search(int x);

    void update(int i, int x);

    void deleteList();

    int getPos(int i);

    bool isEmpty();

    void deleteElement(int x);
};

#endif