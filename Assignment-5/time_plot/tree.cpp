// author: Aryanthepain
#include "tree.h"
using namespace std;

void binarySearchTree::insert(int x)
{
    if (x == val)
    {
        return;
    }
    else if (x > val)
    {
        if (large)
        {
            large->insert(x);
        }
        else
        {
            large = new binarySearchTree(x);
        }
    }
    else
    {
        if (small)
        {
            small->insert(x);
        }
        else
        {
            small = new binarySearchTree(x);
        }
    }

    return;
}

bool binarySearchTree::searchElement(int x)
{
    if (x < 0)
        return false;
    if (x == val)
    {
        return true;
    }
    if (x > val && large)
    {
        return large->searchElement(x);
    }
    else if (x < val && small)
    {
        return small->searchElement(x);
    }

    return false;
}

void binarySearchTree::deleteHelper(int x, binarySearchTree *curr)
{
    if (!curr)
        return;

    if (x < 0) // only deleting, no finding
    {
        // leaf node
        if (!curr->large && !curr->small)
        {
            if (large == curr)
            {
                large = nullptr;
            }
            else if (small == curr)
            {
                small = nullptr;
            }
            else
            {
                cerr << "Logic error in deleting leaf node" << endl;
            }

            delete curr;
            return;
        }

        // two children
        else if (curr->large && curr->small)
        {
            if (large == curr)
            {
                curr->val = curr->small->val;
                curr->deleteHelper(-1, curr->small);
            }
            else if (small == curr)
            {
                curr->val = curr->large->val;
                curr->deleteHelper(-1, curr->large);
            }
            else
            {
                cerr << "Logic error in deleting node with two children" << endl;
            }
            return;
        }

        // one child
        else
        {
            binarySearchTree *child = curr->large ? curr->large : curr->small;
            if (curr == large)
            {
                large = child; // Update root reference
            }
            else if (curr == small)
            {
                small = child; // Update root reference
            }

            curr->large = nullptr;
            curr->small = nullptr;
            // this has to be done otherwise the delete will call the destructor
            // which is not good
            delete curr;
            return;
        }
    }
    // only finding, no deleting
    else
    {
        if (x == curr->val)
        {
            this->deleteHelper(-1, curr);
        }
        else if (x > curr->val && curr->large)
        {
            curr->deleteHelper(x, curr->large);
        }
        else if (x < curr->val && curr->small)
        {
            curr->deleteHelper(x, curr->small);
        }
        else
        {
            cerr << "No such element found" << endl;
        }

        return;
    }

    return;
}
void binarySearchTree::deleteElement(int x)
{
    if (x < 0 || !large)
        return;
    binarySearchTree *curr = large;
    // we can do this as root node is always -1
    // due to the initialisation
    if (x == curr->val)
    {
        this->deleteHelper(-1, curr);
    }
    else if (x < curr->val && curr->small)
    {
        curr->deleteHelper(x, curr->small);
    }
    else if (x > curr->val && curr->large)
    {
        curr->deleteHelper(x, curr->large);
    }

    return;
}

void binarySearchTree::printTree(int level)
{

    // Print the large child recursively
    if (large)
        large->printTree(level + 1);

    if (val >= 0)
    {
        // Print current node with indentation based on the level
        for (int i = 0; i < level; i++)
        {
            cout << "\t";
        }
        cout << val << endl;

        // debug code
        // cout << val << " " << large << " " << small << endl;
    }

    // Print the left child recursively
    if (small)
        small->printTree(level + 1);

    return;
}

void binarySearchTree::preOrder()
{
    if (val >= 0)
        cout << val << " ";
    if (small)
        small->preOrder();
    if (large)
        large->preOrder();

    if (val < 0)
        cout << endl;

    return;
}

void binarySearchTree::inOrder()
{
    if (small)
        small->inOrder();
    if (val >= 0)
        cout << val << " ";

    // debug code
    // cout << val << " " << large << " " << small << endl;
    if (large)
        large->inOrder();

    if (val < 0)
        cout << endl;

    return;
}

void binarySearchTree::postOrder()
{
    if (small)
        small->postOrder();
    if (large)
        large->postOrder();
    if (val >= 0)
    {
        cout << val << " ";
    }
    if (val < 0)
        cout << endl;

    return;
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