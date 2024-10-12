// author: Aryanthepain
#ifndef STACK_H
#define STACK_H

#include <bits/stdc++.h>
#include "list.h"
using namespace std;

void push(Node *head, int x);

void pop(Node *head);

int getTop(Node *head);

bool isEmpty(Node *head);

void printStack(Node *head);

#endif