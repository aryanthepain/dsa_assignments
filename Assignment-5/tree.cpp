// author: Aryanthepain
#include "tree.h"
using namespace std;

int binaryTree::parent(int i)
{
    return (i - 1) / 2;
}
int binaryTree::left(int i)
{
    return 2 * i + 1;
}
int binaryTree::right(int i)
{
    return 2 * i + 2;
}

void binaryTree::insert(int x)
{
    if (size >= maxSize)
    {
        size = maxSize;
        int p = this->searchElement(-1); // empty nodes are denoted by -1
        if (p >= 0)                      // empty node exists
        {
            arr[p] = x;
            return;
        }

        cerr << "max size reached" << endl;
        return;
    }

    // put at last visited node
    arr[size] = x;
    size++;

    return;
}

void binaryTree::printAll()
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0) // empty node, defined as -1
            continue;
        cout << arr[i] << " ";
    }

    cout << endl;

    return;
}

int binaryTree::searchElement(int x)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

void binaryTree::deleteHelper(int i)
{
    int l = left(i);
    int r = right(i);

    if (l < size && arr[])
}
void binaryTree::deleteElement(int x)
{
    int i = searchElement(x);
    if (i < 0)
    {
        cerr << "element not found" << endl;
        return;
    }

    if (i == (size - 1)) // last visited node
    {
        size--;
        return;
    }
    // else if node somewhere in the middle
    deleteHelper(i);

    return;
}

int binaryTree::getElementOnPos(int x)
{
    return arr[x];
}

void binaryTree::printTree(int index, int level)
{
    // Base case: if index is out of bounds of the array
    if (index >= size)
    {
        return;
    }

    // Print the right child recursively
    printTree(2 * index + 2, level + 1);

    // Print current node with indentation based on the level
    for (int i = 0; i <= level; i++)
    {
        cout << "\t";
    }
    if (arr[index] >= 0) // if node is not empty node
    {
        cout << arr[index] << endl;
    }
    else
    {
        cout << endl;
    }

    // Print the left child recursively
    printTree(2 * index + 1, level + 1);
}

/*
int main()
{
    int n;
    cin >> n;
    binaryTree h(2 * n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        h.insert(a);
    }

    h.printAll();
    cout << "----------------" << endl;
    h.printTree();
    // int b;
    // cin >> b;
    // h.deleteElement(b);

    // h.printAll();
    // cout << "----------------" << endl;
    // printTree(h.arr, h.size);

    return 0;
}
*/