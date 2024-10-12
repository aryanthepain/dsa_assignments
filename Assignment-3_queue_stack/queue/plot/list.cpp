// author: Aryanthepain
#include "list.h"

void insertAtPos(Node *head, int x, int i)
{
    while (i > 0 && head->next != NULL)
    {
        i--;
        head = head->next;
    }
    Node *next = (Node *)malloc(sizeof(Node));
    next->val = x;
    next->next = head->next;
    head->next = next;

    return;
}

int size(Node *head)
{
    if (head->next == NULL)
        return 0;
    return size(head->next) + 1;
}

void insertAtLast(Node *last, int x)
{
    Node *next = (Node *)malloc(sizeof(Node));
    next->val = x;
    next->next = nullptr;
    last->next->next = next;
    last->next = next;

    return;
}

void deleteAtPos(Node *head, int i)
{
    while (i-- > 0)
    {
        if (head->next != NULL)
            head = head->next;
    }
    if (head->next == NULL)
    {
        free(head->next);
        head->next = nullptr;
        return;
    }

    if (head->next->next == NULL)
    {
        free(head->next);
        head->next = NULL;
        return;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = head->next->next;
    free(head->next);
    head->next = temp->next;
    free(temp);

    return;
}

void deleteFirst(Node *head, Node *last)
{
    deleteAtPos(head, 0);
    if (head->next == nullptr)
    {
        last->next = head;
    }

    return;
}

void traverse(Node *head)
{
    if (head->next != NULL)
        head = head->next;
    while (head->next != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val << endl;

    return;
}

void deleteListHelp(Node *head)
{
    if (head->next == NULL)
        return;
    deleteListHelp(head->next);
    free(head);
    return;
}
void deleteList(Node *head)
{
    if (head->next == NULL)
        return;
    deleteListHelp(head->next);
    return;
}

int getPos(Node *head, int i)
{
    int n = size(head);
    if (i >= n)
        i = n - 1; // get last element
    i++;
    while (i--)
    {
        head = head->next;
    }

    return head->val;
}
/*
int menu()
{
    cout << "Press the number corresponding to the function you want to execute(-1 to exit)" << endl;
    cout << "1. Input List" << endl;
    cout << "2. Get element at a position" << endl;
    cout << "3. Insert at a position" << endl;
    cout << "4. Delete at a position" << endl;
    cout << "5. Print list" << endl;
    cout << "6. Search for a number" << endl;
    cout << "7. Update a position" << endl;
    cout << "8. Sort the list" << endl;
    cout << "9. Reverse the list" << endl;
    cout << "10. Delete list(head is not deleted in this case)" << endl;
    cout << "11. Merge two lists" << endl;
    cout << "12. Size of list" << endl;

    int n;
    cin >> n;

    return n;
}

int main()
{
    cout << "Functions on singly linked lists" << endl;
    Node *head = (Node *)malloc(sizeof(Node));
    Node *head1 = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head1->next = NULL;

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
                if (head1)
                {
                    deleteList(head1);
                    free(head1);
                }
            }

            return 0;
        }
        switch (me)
        {
        case 1:
            cout << "Size of list you want to input:" << endl;
            int n;
            cin >> n;
            cout << "Elements of list" << endl;
            for (int i = 0; i < n; i++)
            {
                int n;
                cin >> n;
                insertAtLast(head, n);
            }
            break;

        case 2:
        {
            cout << "What position's element do you want to see?" << endl;
            int n;
            cin >> n;
            cout << getPos(head, n) << endl;
            break;
        }
        case 3:
        {
            cout << "Enter the position to insert at and the value to insert:" << endl;
            int pos, val;
            cin >> pos >> val;
            insertAtPos(head, val, pos);
            break;
        }
        case 4:
        {
            cout << "Enter the position to delete at:" << endl;
            int pos;
            cin >> pos;
            deleteAtPos(head, pos);
            break;
        }
        case 5:
        {
            cout << "The current list is:" << endl;
            traverse(head);
            break;
        }
        case 6:
        {
            cout << "Enter the number to search for:" << endl;
            int val;
            cin >> val;
            search(head, val);
            break;
        }
        case 7:
        {
            cout << "Enter the position to update and the new value:" << endl;
            int pos, val;
            cin >> pos >> val;
            update(head, pos, val);
            break;
        }
        case 8:
        {
            cout << "Sorting the list..." << endl;
            sort(head);
            break;
        }
        case 9:
        {
            cout << "Reversing the list..." << endl;
            reverse(head);
            break;
        }
        case 10:
        {
            cout << "Deleting the entire list..." << endl;
            deleteList(head);
            head->next = nullptr;
            break;
        }
        case 11:
        {
            cout << "Merging two lists..." << endl;
            cout << "Size of second list you want to input:" << endl;
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int val;
                cin >> val;
                insertAtLast(head1, val);
            }
            mergeLists(head, head1);
            free(head1);
            break;
        }
        case 12:
        {
            cout << size(head) << endl;
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    return 0;
}
*/