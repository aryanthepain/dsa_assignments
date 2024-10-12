// author: Aryanthepain
#include "heap.h"
using namespace std;

int maxHeap::parent(int i)
{
    return (i - 1) / 2;
}
int maxHeap::left(int i)
{
    return 2 * i + 1;
}
int maxHeap::right(int i)
{
    return 2 * i + 2;
}

void maxHeap::insertHelper(int x, int i)
{
    if (i == 0)
    {
        arr[i] = x;
        return;
    }

    int p = parent(i);

    if (arr[p] >= x)
    {
        arr[i] = x;
        return;
    }

    arr[i] = arr[p];
    insertHelper(x, p);

    return;
}
void maxHeap::insert(int x)
{
    if (size >= maxSize)
    {
        cerr << "max size reached" << endl;
        return;
    }
    insertHelper(x, size);

    size++;

    return;
}

void maxHeap::printAll()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return;
}

int maxHeap::searchElement(int x)
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

void maxHeap::deleteHelper(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (arr[i] < arr[l] && l < size)
    {
        largest = l;
    }
    if (arr[largest] < arr[r] && r < size)
    {
        largest = r;
    }
    if (largest == i)
    {
        return;
    }
    else
    {
        swap(arr[largest], arr[i]);
        deleteHelper(largest);
    }

    return;
}

void maxHeap::deleteElement(int x)
{
    int i = searchElement(x);
    if (i < 0)
    {
        cerr << "element not found" << endl;
        return;
    }

    size--;
    arr[i] = arr[size];

    int p = parent(i);

    if (arr[p] < arr[i])
    {
        insertHelper(arr[i], i);
        return;
    }

    deleteHelper(i);

    return;
}

int maxHeap::getElementOnPos(int x)
{
    return arr[x];
}

void maxHeap::printTree(int index, int level)
{
    // Base case: if index is out of bounds of the array
    if (index >= size)
    {
        return;
    }

    // Print the right child first
    printTree(2 * index + 2, level + 1);

    // Print current node with indentation based on the level
    for (int i = 0; i < level; i++)
    {
        cout << "\t";
    }
    cout << arr[index] << endl;

    // Print the left child
    printTree(2 * index + 1, level + 1);
}

int menu()
{
    cout << "Press the number corresponding to the function you want to execute(-1 to exit)" << endl;
    cout << "1. Insert Element" << endl;
    cout << "2. Delete Element" << endl;
    cout << "3. Print all elements" << endl;
    cout << "4. Print elements as tree" << endl;
    cout << "5. Search element" << endl;
    cout << "6. Size" << endl;

    int n;
    cin >> n;

    return n;
}
// /*
int main()
{
    cout << "Functions on heap" << endl;
    cout << "Input max size for the heap:" << endl;
    int n;
    cin >> n;
    maxHeap h(n);

    while (true)
    {
        int me = menu();
        if (me == -1)
        {
            cout << "Please give full marks :). Exiting..." << endl;
            h.~maxHeap();

            return 0;
        }
        switch (me)
        {
        case 1:
        {
            cout << "Input element: " << endl;
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
            cout << "The current size is: " << h.heapSize() << endl;
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
/*
int main()
{
    int n;
    cin >> n;
    maxHeap h(2 * n);

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