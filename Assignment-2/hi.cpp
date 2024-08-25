// author: Aryanthepain
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

//done
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

//done
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

//done
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

//done
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

//not done
void update(Node *head, int i, int x)
{
    while (i > 0 && head->next != NULL)
    {
        i--;
        head = head->next;
    }
    //if there is nothing on the position
    if (head->next == NULL)
    {
        cout << "List not long enough" << endl;
        return;
    }
    Node *next = (Node *)malloc(sizeof(Node));
    next->val = x;
    next->next = head->next;
    head->next = next;

    return;
}
void update() {}
void sort() {}
void reverse() {}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->val = NULL;
    head->next = NULL;

    for (int i = 0; i < 3; i++)
    {
        int n;
        cin >> n;
        insertAtPos(head, n, 1);
    }
    traverse(head);

    //	int n; cin>>n;
    search(head, 3);

    return 0;
}
