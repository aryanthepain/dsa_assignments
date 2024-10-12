// author: Aryanthepain
#include <bits/stdc++.h>
#include "queue.h"
#include "stack.h"
using namespace std;

void push(Node *head, Node *head1, Node *last, Node *last1, int x)
{
    while (!isEmpty(head))
    {
        enqueue(last1, getTop(head));
        dequeue(head, last);
    }

    enqueue(last, x);

    while (!isEmpty(head1))
    {
        enqueue(last, getTop(head1));
        dequeue(head1, last1);
    }

    return;
}

void pop(Node *head, Node *last)
{
    dequeue(head, last);
    return;
}

void printStack(Node *head, Node *last)
{
    printQueue(head, last);

    return;
}

int menu()
{
    cout << "Press the number corresponding to the function you want to execute(-1 to exit)" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Get Top element" << endl;
    cout << "4. isEmpty" << endl;
    cout << "5. Size" << endl;
    cout << "6. Print stack(delete Stack)" << endl;

    int n;
    cin >> n;

    return n;
}

/*
int main()
{
    cout << "Functions on stack" << endl;
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *last = (Node *)malloc(sizeof(Node));
    last->next = head;
    Node *head1 = (Node *)malloc(sizeof(Node));
    head1->next = NULL;
    Node *last1 = (Node *)malloc(sizeof(Node));
    last1->next = head1;

    while (true)
    {
        int me = menu();
        if (me == -1)
        {
            cout << "Please give full marks :). Exiting..." << endl;
            if (head)
            {
                deleteList(head);
                free(head);
            }
            if (head1)
            {
                deleteList(head1);
                free(head1);
            }

            return 0;
        }
        switch (me)
        {
        case 1:
        {
            cout << "Input element:" << endl;
            int n;
            cin >> n;
            push(head, head1, last, last1, n);
            break;
        }
        case 2:
        {
            pop(head, last);
            cout << "deleting first element" << endl;
            break;
        }
        case 3:
        {
            cout << "Top element: ";
            cout << getTop(head) << endl;
            break;
        }
        case 4:
        {
            cout << "The stack is ";
            if (!isEmpty(head))
                cout << "not ";
            cout << "empty" << endl;
            break;
        }
        case 5:
        {
            cout << "The current size is: " << size(head) << endl;
            break;
        }
        case 6:
        {
            cout << "Stack:" << endl;
            printStack(head, last);
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    return 0;
}*/