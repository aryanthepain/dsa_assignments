// author: Aryanthepain
#include "queue.h"

void enqueue(Node *last, int x)
{
    insertAtLast(last, x);
}

void dequeue(Node *head, Node *last)
{
    deleteFirst(head, last);
}

int getTop(Node *head)
{
    return getPos(head, 0);
}

bool isEmpty(Node *head)
{
    if (head->next == NULL)
        return true;
    return false;
}

void printQueue(Node *head, Node *last)
{
    while (!isEmpty(head))
    {
        cout << getTop(head) << " ";
        dequeue(head, last);
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

int main()
{
    cout << "Functions on queue" << endl;
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *last = (Node *)malloc(sizeof(Node));
    last->next = head;

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

            return 0;
        }
        switch (me)
        {
        case 1:
        {
            cout << "Input element: " << endl;
            int n;
            cin >> n;
            enqueue(last, n);
            break;
        }
        case 2:
        {
            dequeue(head, last);
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
            printQueue(head, last);
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    return 0;
}