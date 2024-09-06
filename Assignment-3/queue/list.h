// author: Aryanthepain
#ifndef LIST_H
#define LIST_H
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

void insertAtPos(Node *head, int x, int i);

int size(Node *head);

void insertAtLast(Node *last, int x);

void deleteAtPos(Node *head, int i);

void deleteFirst(Node *head, Node *last);

void traverse(Node *head);

void deleteList(Node *head);

int getPos(Node *head, int i);

#endif