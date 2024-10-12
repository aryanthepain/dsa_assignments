// author: Aryanthepain
#ifndef MENU_BAR_H
#define MENU_BAR_H
#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int menu()
{
    cout << "Press the number corresponding to the function you want to execute(-1 to exit)" << endl;
    cout << "1. Insert Element" << endl;
    cout << "2. Delete Element" << endl;
    cout << "3. Print all elements" << endl;
    cout << "4. Print elements as tree" << endl;
    cout << "5. Search element" << endl;
    cout << "6. pre order traversal" << endl;
    cout << "7. in order traversal" << endl;
    cout << "8. post order traversal" << endl;

    int n;
    cin >> n;

    return n;
}
// /*
int menuBar()
{
    cout << "Functions on binary tree" << endl;
    cout << "Input some max size for the tree:" << endl;
    int n;
    cin >> n;
    binaryTree h(n);

    while (true)
    {
        int me = menu();
        if (me == -1)
        {
            cout << "Please give full marks :). Exiting..." << endl;
            h.~binaryTree();

            return 0;
        }
        switch (me)
        {
        case 1:
        {
            cout << "Input element(-1 to add empty node): " << endl;
            int n;
            cin >> n;
            h.insert(n);
            break;
        }
        case 2:
        {
            cout << "Input element to be deleted:" << endl;
            int n;
            cin >> n;
            h.deleteElement(n);
            break;
        }
        case 3:
        {
            h.printAll();
            break;
        }
        case 4:
        {
            cout << "---------------" << endl;
            h.printTree();
            break;
        }
        case 5:
        {
            cout << "Input element to search for:" << endl;
            int n;
            cin >> n;
            cout << h.searchElement(n) << endl;
            break;
        }
        case 6:
        {
            h.preOrder();
            break;
        }
        case 7:
        {
            h.inOrder();
            break;
        }
        case 8:
        {
            h.postOrder();
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    return 0;
}
// */
#endif