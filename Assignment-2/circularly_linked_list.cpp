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
    insertAtPos(head, x, size(head) + 1);
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

void mergeLists(Node *first, Node *second)
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
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *head1 = (Node *)malloc(sizeof(Node));
    //    head->val = NULL;
    head->next = head;
    head1->next = head1;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n;
        cin >> n;
        insertAtPos(head, n, 10);
        cin >> n;
        insertAtPos(head1, n, 10);
    }
    cout << "before" << endl;
    traverse(head);
    traverse(head1);

    mergeLists(head, head1);

    cout << "after" << endl;
    traverse(head);

    return 0;
}
