// author: Aryanthepain
#ifndef NODE_H
#define NODE_H
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val = 0;
    Node *next;

    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

#endif