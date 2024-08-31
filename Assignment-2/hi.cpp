// author: Aryanthepain
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;
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
    next->prev = head;
    next->next = head->next;
    if (head->next != NULL)
        head->next->prev = next;
    head->next = next;

    return;
}

int size(Node *head)
{
    if (head->next == NULL)
        return 0;
    return size(head->next) + 1;
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

    Node *temp = head->next;
    temp->next->prev = head;
    head->next = temp->next;
    free(temp);

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
    if (head->next != NULL)
        head = head->next;
    while (head->next != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val << endl;

    // debug code
    while (head->prev != NULL)
    {
        cout << head->val << " ";
        head = head->prev;
    }
    cout << "" << endl;

    return;
}

void search(Node *head, int x)
{
    int count = 0;
    while (head->next != NULL)
    {
        head = head->next;
        if (head->val == x)
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

void changeHeadPos(Node *head, int i)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = head->next;
    while (i > 0)
    {
        i--;
        if (temp->next == NULL)
        { // list not long enough, head not changed
            return;
        }
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
    head->next->prev = first;
    first->prev = NULL;
    // int firstSize = listSize - listSize / 2;
    Node *second = (Node *)malloc(sizeof(Node));
    second->next = first->next;
    second->prev = NULL;
    changeHeadPos(second, listSize / 2);
    second->next->prev->next = NULL;
    second->next->prev = second;

    /*    // debug code
        cout << "first" << endl;
        traverse(first);
        cout << "second" << endl;
        traverse(second);
        cout << "temp" << endl;
        traverse(temp); */

    sort(first);
    sort(second);

    while (true)
    {
        if (first->next->val >= second->next->val)
        {
            if (second->next->next == NULL)
            {
                head->next = second->next;
                head->next->prev = head;
                second->next->next = first->next;
                first->next->prev = second->next;
                break;
            }
            head->next = second->next;
            second->next = second->next->next;
            second->next->prev = second;
            head->next->next = NULL;
            head->next->prev = head;
            head = head->next;
        }
        else
        {
            if (first->next->next == NULL)
            {
                head->next = first->next;
                head->next->prev = head;
                first->next->next = second->next;
                second->next->prev = first->next;
                break;
            }
            head->next = first->next;
            first->next = first->next->next;
            first->next->prev = first;
            head->next->next = NULL;
            head->next->prev = head;
            head = head->next;
        }
    }

    free(first);
    free(second);

    return;
}

void reverseMain(Node *head, Node *last)
{
    if (head->next == NULL)
    {
        last->next = head;
        head->next = head->prev;
        head->prev = nullptr;
        return;
    }

    reverseMain(head->next, last);

    // switch previous and next
    last->prev = last->next->next; // last->prev used as temp
    last->next->next = last->next->prev;
    last->next->prev = last->prev;
    last->prev = nullptr;
    last->next = last->next->next;

    return;
}

void reverse(Node *head)
{
    if (head->next == NULL || head->next->next == nullptr)
        return;

    Node *last = (Node *)malloc(sizeof(Node));
    last->next = nullptr;
    last->prev = nullptr;

    reverseMain(head->next, last);

    if (last->next == head)
    {
        free(last);
        return;
    }
    head->next->next = nullptr;
    last->next->prev = head;
    last->next->prev->next = last->next;
    // head->next = last->next;
    // if (head->next != nullptr)
    // head->next->prev = head;

    free(last);
    return;
}
/*
void reverse(Node *head)
{
    if (head->next == nullptr || head->next->next == nullptr)
        return;

    Node *temp = head->next->next;
    head->next->next = head->next->prev;
    head->next->prev = temp;

    reverse(head->next);
}
*/
void mergeLists(Node *first, Node *second)
{
    while (first->next != NULL)
    {
        first = first->next;
    }
    first->next = second->next;
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    // Node *head1 = (Node *)malloc(sizeof(Node));
    //    head->val = NULL;
    head->next = NULL;
    head->prev = NULL;
    // head1->next = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n;
        cin >> n;
        insertAtPos(head, n, 10);
        // cin >> n;
        // insertAtPos(head1, n, 10);
    }
    cout << "before" << endl;
    traverse(head);
    // traverse(head1);

    reverse(head);

    cout << "after" << endl;
    traverse(head);

    return 0;
}
