// author: Aryanthepain
#ifndef HEAP_H
#define HEAP_H
#include <bits/stdc++.h>
using namespace std;

char operators[4] = {'+', '-', '*', '/'};

class mathTreeNode
{
private:
    // void deleteHelper(int x, mathTreeNode *curr);

public:
    char val;
    mathTreeNode *right;
    mathTreeNode *left;
    mathTreeNode(char x = '.');
    ~mathTreeNode();

    // functions
    // void insertOp(char b, char next, stack<char> &numstack, stack<char> &opstack, mathTreeNode *&current, mathTreeNode *&root);
    void insert(int x);
    void printTree(int level = 0);
    // void deleteElement(int x);
    // bool searchElement(int x);
    // void preOrder();
    // void inOrder();
    // void postOrder();
};

class mathTree
{
private:
    mathTreeNode *ptr;
    mathTreeNode *curr;
    stack<mathTreeNode *> opStack;
    stack<char> numberStack;

public:
    mathTree(string n);
    ~mathTree();

    void printTree();
};

#endif