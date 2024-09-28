// author: Aryanthepain
#include "list.h"
using namespace std;

/*
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
*/

int sll::listSize()
{
    Node *temp = head;
    int l = 0;
    while (temp)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

void sll::insert(int x)
{
    Node *newnode = new Node(x);
    Node *temp = head;
    head = newnode;
    size++;
    if (temp != NULL)
    {
        head->next = temp;
    }
}

/*
void insertAtLast(Node *head, int x)
{
    insertAtPos(head, x, listSize(head) + 1);
}
*/

void sll::deleteAtPos(int i)
{
    Node *temp = head->next;

    if (i == 0)
    {
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            size--;
            return;
        }
        delete head;
        head = temp;
        size--;
        return;
    }

    Node *prev = head;

    while (i > 1)
    {
        i--;
        prev = temp;
        if (temp->next)
            temp = temp->next;
    }

    // i>=size of list
    if (temp == prev)
    {
        return;
    }

    // last element
    if (temp->next == NULL)
    {
        delete temp;
        prev->next = NULL;
        size--;
        return;
    }

    prev->next = temp->next;
    delete temp;
    size--;

    return;
}

/*
void deleteFirst(Node *head)
{
    deleteAtPos(head, 0);
}

void deleteLast(Node *head)
{
    deleteAtPos(head, listSize(head) - 1);
}
*/

void sll::printList()
{
    if (!head)
    {
        return;
    }

    Node *temp = head;

    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    // cout << temp->val << " ";

    return;
}

int sll::search(int x)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        if (temp->val == x)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }

    return -1;
}

bool sll::isEmpty()
{
    if (head)
        return false;
    return true;
}

void sll::update(int pos, int val)
{
    Node *temp = head;
    while (pos && temp)
    {
        pos--;
        if (!temp->next)
        {
            cerr << "error while updating list. List not long enough" << endl;
            return;
        }
        temp = temp->next;
    }
    temp->val = val;

    return;
}

void deleteListHelp(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    deleteListHelp(head->next);
    delete head;

    return;
}
void sll::deleteList()
{
    if (head == NULL)
        return;
    deleteListHelp(head);
    head = nullptr;
    size = 0;

    return;
}

/*
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
    int listSize = listSize(head);
    if (listSize == 1)
        return;
    Node *first = (Node *)malloc(sizeof(Node));
    first->next = head->next;
    // int firstSize = listSize - listSize / 2;
    Node *second = (Node *)malloc(sizeof(Node));
    second->next = head->next;
    changeHeadPos(second, listSize / 2);
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = head->next;
    changeHeadPos(temp, listSize / 2 - 1);
    temp->next->next = NULL;

    /*    // debug code
        cout << "first" << endl;
        traverse(first);
        cout << "second" << endl;
        traverse(second);
        cout << "temp" << endl;
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

    free(first);
    free(second);
    free(temp);

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

void mergeLists(Node *first, Node *second)
{
    while (first->next != NULL)
    {
        first = first->next;
    }
    first->next = second->next;
}
*/

int sll::getPos(int i)
{
    int n = listSize();
    Node *temp = head;
    if (i >= n)
        i = n - 1; // get last element

    while (i--)
    {
        temp = temp->next;
    }

    return temp->val;
}

void sll::deleteElement(int x)
{
    if (!head)
    {
        return;
    } // empty list

    Node *temp = head->next;

    // first element
    if (head->val == x)
    {
        delete head;
        head = temp;
        size--;
        return;
    }

    Node *prev = head;

    while (temp)
    {
        if (temp->val == x)
        {
            prev->next = temp->next;
            delete temp;
            size--;
            break;
        }
        temp = temp->next;
        prev = prev->next;
    }

    return;
}
/*
int main()
{
    int n;
    cin >> n;
    sll arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.insert(a);
    }

    arr.printList();

    cin >> n;
    // int a;
    // cin >> a;
    cout << arr.getPos(n) << endl;

    arr.printList();

    return 0;
}
*/
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
            cout << listSize(head) << endl;
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