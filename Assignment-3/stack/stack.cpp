#include "stack.h"

void push(Node *head, int x)
{
    insertAtFirst(head, x);
}

void pop(Node *head)
{
    deleteFirst(head);
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

void printStack(Node *head)
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
    cout << "6. Print stack(delete Stack)" << endl;

    int n;
    cin >> n;

    return n;
}

int main()
{
    cout << "Functions on stack" << endl;
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;

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
            cout << "Input element:" << endl;
            int n;
            cin >> n;
            push(head, n);
            break;
        }
        case 2:
        {
            pop(head);
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
            printStack(head);
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    return 0;
}