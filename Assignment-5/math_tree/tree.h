// author: Aryanthepain
#ifndef TREE_H
#define TREE_H
#include <bits/stdc++.h>
using namespace std;

class mathTreeNode
{
private:
    // void deleteHelper(int x, mathTreeNode *curr);

public:
    char val;
    mathTreeNode *right;
    mathTreeNode *left;
    mathTreeNode(char x);
    ~mathTreeNode();

    // functions
    void printTree(int level = 0);
    // void insertOp(char b, char next, stack<char> &numstack, stack<char> &opstack, mathTreeNode *&current, mathTreeNode *&root);
    // void insert(int x);
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

public:
    mathTree(string n);
    ~mathTree();

    void printTree();
};

#endif