// author: Aryanthepain
#include "hash.h"
using namespace std;

int hashValue(int x)
{
    return x % 10;
}

void hashMap::insert(int x)
{
    arr[hashValue(x)].insert(x);

    return;
}

int hashMap::search(int x)
{
    int pos = 0;
    int hashVal = hashValue(x);
    if (pos = arr[hashVal].search(x) < 0)
    {
        return -1;
    }

    for (int i = 0; i < hashVal; i++)
    {
        pos = pos + arr[i].size;
    }

    return pos; // not found
}

void hashMap::printAll()
{
    for (int i = 0; i < 10; i++)
    {
        arr[i].printList();
    }
    cout << endl;

    return;
}

void hashMap::deleteElement(int x)
{
    arr[hashValue(x)].deleteElement(x);

    return;
}

int menu()
{
    cout << "Press the number corresponding to the function you want to execute(-1 to exit)" << endl;
    cout << "1. Insert Element" << endl;
    cout << "2. Print all elements" << endl;
    cout << "3. Delete element" << endl;
    cout << "4. Search element" << endl;

    int n;
    cin >> n;

    return n;
}

int main()
{
    cout << "Functions on hash" << endl;
    hashMap hm;

    while (true)
    {
        int me = menu();
        if (me == -1)
        {
            cout << "Please give full marks :). Exiting..." << endl;

            hm.~hashMap();

            return 0;
        }
        switch (me)
        {
        case 1:
        {
            cout << "Input element: " << endl;
            int n;
            cin >> n;
            hm.insert(n);
            break;
        }
        case 2:
        {
            hm.printAll();
            break;
        }
        case 3:
        {
            cout << "Input element to be deleted:" << endl;
            int n;
            cin >> n;
            hm.deleteElement(n);
            break;
        }
        case 4:
        {
            cout << "Input element to search for" << endl;
            int n;
            cin >> n;
            cout << hm.search(n) << endl;
            break;
        }
        default:
            cout << "Invalid option. Please try again. (-1 to exit)" << endl;
            break;
        }
    }

    return 0;
}