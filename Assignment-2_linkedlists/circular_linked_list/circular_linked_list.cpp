// author: Aryanthepain
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

void insertAtPos(Node *head, int x, int i)
{
    Node *temp = head;
    while (i > 0 && temp->next != head)
    {
        i--;
        temp = temp->next;
    }
    Node *next = (Node *)malloc(sizeof(Node));
    next->val = x;
    next->next = temp->next;
    temp->next = next;

    return;
}

int size(Node *head)
{
    if (head->next == head)
        return 0;

    int count = 0;

    Node *temp = head;

    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void insertAtFirst(Node *head, int x)
{
    insertAtPos(head, x, 0);
}

void insertAtLast(Node *head, int x)
{
    insertAtPos(head, x, size(head));
}

void deleteAtPos(Node *head, int i)
{
    if (size(head) <= i)
        return;

    if (i == 0 && head->next->next == head)
    {
        free(head->next);
        head->next = head;
        return;
    }
    // i--;
    Node *temp = head;
    while (i-- > 0)
    {
        if (temp->next->next != head)
            temp = temp->next;
    }
    /*   if (temp->next->next == head)
       {
    Node *foo = temp->next->next;
    free(temp->next);
    temp->next = foo;
    return;
     }

    if (head->next->next == NULL)
    {
        free(head->next);
        head->next = NULL;
        return;
    }*/

    Node *foo = (Node *)malloc(sizeof(Node));
    foo->next = temp->next->next;
    free(temp->next);
    temp->next = foo->next;
    free(foo);

    return;
}

void deleteFirst(Node *head)
{
    deleteAtPos(head, 0);
}

void deleteLast(Node *head)
{
    deleteAtPos(head, size(head) - 1);
}

void traverse(Node *head)
{
    if (head->next == head)
        return;

    Node *temp = head;
    if (temp->next != head)
        temp = temp->next;
    while (temp->next != head)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << temp->val << endl;

    // debug code
    /*    temp = temp->next->next;
        while (temp->next != head)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << temp->val << endl;*/

    return;
}

void search(Node *head, int x)
{
    int count = 0;
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        if (temp->val == x)
        {
            cout << count << endl;
            return;
        }
        count++;
    }

    cout << "not found" << endl;

    return;
}

void update(Node *head, int i, int x)
{
    Node *last = head;
    while (i > 0 && head->next != last)
    {
        i--;
        head = head->next;
    }
    // if position is larger than list size
    if (head->next == last)
    {
        cerr << "error while updating list. List not long enough" << endl;
        return;
    }
    head->next->val = x;

    return;
}

void deleteList(Node *head)
{
    while (head->next != head)
        deleteFirst(head);
    // free(head);
    return;
}

void reverse(Node *head)
{
    Node *last = head;
    if (head->next == last)
    {
        cerr << "list is empty" << endl;
        return;
    }
    Node *prev = head->next;
    if (prev->next == last)
    { // only one element
        return;
    }
    Node *curr = prev->next;
    if (curr->next == last)
    { // only two elements
        curr->next = head->next;
        head->next = prev->next;
        prev->next = last;
        return;
    }
    Node *next = (Node *)malloc(sizeof(Node));
    next = curr->next;

    curr->next = prev;
    head->next = curr;
    prev->next = last;
    prev = curr;
    curr = next;
    if (next->next != last)
        next = next->next;

    while (next->next != last)
    {
        curr->next = prev;
        head->next = curr;
        prev = curr;
        curr = next;
        next = next->next;
    }

    curr->next = prev;
    if (curr != next)
        next->next = curr;
    head->next = next;

    return;
}

/*void mergeLists(Node *first, Node *second)
{
    Node *head = first;
    while (first->next != head)
    {
        first = first->next;
    }
    first->next = second;
    while (second->next != first->next)
    {
        second = second->next;
    }

    second->next = head;
    head = first->next->next;
    free(first->next);
    first->next = head;

    return;
}*/

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
    // cout << "8. Sort the list" << endl;
    cout << "8. Size of list" << endl;
    cout << "9. Reverse the list" << endl;
    cout << "10. Delete list(head is not deleted in this case)" << endl;
    // cout << "11. Merge two lists" << endl;

    int n;
    cin >> n;

    return n;
}

int main()
{
    cout << "Functions on circularly linked lists" << endl;
    Node *head = (Node *)malloc(sizeof(Node));
    Node *head1 = (Node *)malloc(sizeof(Node));
    head->next = head;
    head1->next = head1;

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
        /*case 11:
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
        }*/
        case 8:
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