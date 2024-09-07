// author: Aryanthepain
#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"
#include <bits/stdc++.h>
using namespace std;

void enqueue(Node *last, int x);

void dequeue(Node *head, Node *last);

int getTop(Node *head);

bool isEmpty(Node *head);

void printQueue(Node *head, Node *last);

#endif