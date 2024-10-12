// author: Aryanthepain
#include "menubar.h"

int menu()
{
    cout << "Press the number corresponding to the function you want to execute(-1 to exit)" << endl;
    cout << "1. Insert Element" << endl;
    cout << "2. Delete Element" << endl;
    cout << "3. Print elements as tree" << endl;
    cout << "4. Search element" << endl;
    cout << "5. pre order traversal" << endl;
    cout << "6. in order traversal" << endl;
    cout << "7. post order traversal" << endl;

    int n;
    cin >> n;

    return n;
}
// /*
int menuBar()
{
    cout << "Functions on binary search tree" << endl;
    binarySearchTree t;

    while (true)
    {
        int me = menu();
        if (me == -1)
        {
            cout << "Please give full marks :). Exiting..." << endl;
            t.~binarySearchTree();
            delete &t;

            return 0;
        }
        switch (me)
        {
        case 1:
        {
            cout << "Input element(number>=0): " << endl;
            int n;
            cin >> n;
            t.insert(n);
            break;
        }
        case 2:
        {
            cout << "Input element to be deleted:" << endl;
            int n;
            cin >> n;
            t.deleteElement(n);
            break;
        }
        case 3:
        {
            cout << "---------------" << endl;
            t.printTree();
            break;
        }
        case 4:
        {
            cout << "Input element to search for:" << endl;
            int n;
            cin >> n;

            if (t.searchElement(n))
                cout << "found" << endl;
            else
                cout << "not found" << endl;
            break;
        }
        case 5:
        {
            t.preOrder();
            break;
        }
        case 6:
        {
            t.inOrder();
            break;
        }
        case 7:
        {
            t.postOrder();
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    return 0;
}