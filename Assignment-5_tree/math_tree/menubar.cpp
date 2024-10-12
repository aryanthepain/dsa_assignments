// author: Aryanthepain
#include "menubar.h"

/*
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
*/
// /*
int menuBar()
{

    while (true)
    {
        cout << "Make a math tree from an infix expreesion" << endl;
        cout << "You can use digits 0-9 and operators +, -, *, /, (, and )" << endl;
        cout << "Enter -1 to exit" << endl;
        string n;
        cin >> n;
        if (n == "-1")
        {
            cout << "Please give full marks :). Exiting..." << endl;
            break;
        }

        mathTree tree(n);

        tree.printTree();
    }

    cout << "Thank you\n~Aryan" << endl;
    return 0;
}

int main()
{
    return menuBar();
}