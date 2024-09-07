// author: Aryanthepain
#include <bits/stdc++.h>
#include "stack.h"
#include "queue.h"

void enqueue(Node *head, Node *head1, int x)
{
    while (!isEmpty(head))
    {
        push(head1, getTop(head));
        pop(head);
    }

    push(head, x);

    while (!isEmpty(head1))
    {
        push(head, getTop(head1));
        pop(head1);
    }

    return;
}

void dequeue(Node *head)
{
    pop(head);
}

void printQueue(Node *head)
{
    while (!isEmpty(head))
    {
        cout << getTop(head) << " ";
        pop(head);
    }
    cout << " " << endl;

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
    cout << "6. Print queue(delete queue)" << endl;

    int n;
    cin >> n;

    return n;
}

// comment out while calculating time
int main()
{
    cout << "Functions on queue" << endl;
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *head1 = (Node *)malloc(sizeof(Node));
    head1->next = nullptr;

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
            cout << "Input element: " << endl;
            int n;
            cin >> n;
            enqueue(head, head1, n);
            break;
        }
        case 2:
        {
            dequeue(head);
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
            cout << "The queue is ";
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
            cout << "Queue:" << endl;
            printQueue(head);
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    return 0;
}