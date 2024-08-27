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

void search(Node *head, int x)
{
    int count = 0;
    while (head->next != NULL)
    {
        count++;
        head = head->next;
        if (head->val == x)
        {
            cout << count - 1 << endl;
            return;
        }
    }

    cout << "not found" << endl;

    return;
}

void update(Node *head, int i, int x)
{
    while (i > 0 && head->next != NULL)
    {
        i--;
        head = head->next;
    }
    // if position is larger than list size
    if (head->next == NULL)
    {
        cerr << "error while updating list. List not long enough" << endl;
        return;
    }
    head->next->val = x;

    return;
}

void deleteList(Node *head)
{
    if (head->next == NULL)
        return;
    deleteList(head->next);
    free(head);
    return;
}

int size(Node *head)
{
    if (head->next == NULL)
        return 0;
    return size(head->next) + 1;
}

void changeHeadPos(Node *head, int i)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = head->next;
    while (i > 0)
    {
        i--;
        if (temp->next == NULL) // list not long enough, head not changed
            return;
        temp = temp->next;
    }
    head->next = temp->next;

    return;
}

void sort(Node *head)
{
    int listSize = size(head);
    if (listSize == 1)
        return;
    Node *first = (Node *)malloc(sizeof(Node));
    first->next = head->next;
    // int firstSize = listSize - listSize / 2;
    Node *second = (Node *)malloc(sizeof(Node));
    second->next = head->next;
    changeHeadPos(second, listSize / 2);
    Node *temp = (Node *)malloc(sizeof(Node));
    changeHeadPos(temp, listSize / 2 - 1);
    temp->next->next = NULL;

    // debug code
    traverse(first);
    traverse(second);
    traverse(temp);

    sort(first);
    sort(second);

    while (true)
    {
        if (first->next->val >= second->next->val)
        {
            if (second->next->next == NULL)
            {
                head->next = second->next;
                second->next->next = first->next;
                break;
            }
            head->next = second->next;
            second->next = second->next->next;
            head->next->next = NULL;
            head = head->next;
        }
        else
        {
            if (first->next->next == NULL)
            {
                head->next = first->next;
                first->next->next = second->next;
                break;
            }
            head->next = first->next;
            first->next = first->next->next;
            head->next->next = NULL;
            head = head->next;
        }
    }

    return;
}

void reverse(Node *head)
{
    if (head->next == NULL)
    {
        cerr << "list is empty" << endl;
        return;
    }
    Node *prev = (Node *)malloc(sizeof(Node));
    prev = head->next;
    if (prev->next == NULL)
    { // only one element
        return;
    }
    Node *curr = (Node *)malloc(sizeof(Node));
    curr = prev->next;
    if (curr->next == NULL)
    { // only two elements
        curr->next = head->next;
        head->next = prev->next;
        prev->next = NULL;
        return;
    }
    Node *next = (Node *)malloc(sizeof(Node));
    next = curr->next;

    curr->next = prev;
    head->next = curr;
    prev->next = NULL;
    prev = curr;
    curr = next;
    if (next->next != NULL)
        next = next->next;

    while (next->next != NULL)
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

void mergeLists() {}
void createList() {}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    //    head->val = NULL;
    head->next = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n;
        cin >> n;
        insertAtPos(head, n, 10);
    }
    traverse(head);

    sort(head);

    // traverse(head);

    return 0;
}
