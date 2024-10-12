// author: Aryanthepain
#include <bits/stdc++.h>
#define MAX 10
using namespace std;

struct Column
{
    int val;
    Column *next;
};

struct Row
{
    Column *col;
    Row *next;
};

int getVal()
{
    return rand() % MAX;
}

void inputMatrix(Row *head, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        Column *col = new Column();
        head->col = col;
        col->val = getVal();
        col->next = nullptr;

        for (int j = 1; j < n; j++)
        {
            Column *next = new Column();
            next->next = nullptr;
            next->val = getVal();
            col->next = next;
            col = col->next;
        }

        if (i < m - 1)
        {
            Row *nextRow = new Row();
            nextRow->next = nullptr;
            head->next = nextRow;
            head = head->next;
        }
    }
    head->next = nullptr;
}

void traverse(Column *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void printMatrix(Row *head)
{
    while (head != nullptr)
    {
        traverse(head->col);
        head = head->next;
    }
}

void printTranspose(Row *head, int m, int n)
{
    n++; // not working without this
    for (int j = 0; j < n; j++)
    {
        Row *currentRow = head;
        for (int i = 0; i < m; i++)
        {
            Column *currentCol = currentRow->col;
            for (int k = 0; k < j; k++)
            {
                if (currentCol != nullptr)
                {
                    currentCol = currentCol->next;
                }
            }

            if (currentCol != nullptr)
            {
                cout << currentCol->val << " ";
            }
            currentRow = currentRow->next;
        }
        cout << endl;
    }

    return;
}

void multiply(Row *prod, Row *first, Row *second)
{
    Row *crow = prod;
    Row *frow = first;
    while (frow)
    {
        Row *srow = second;
        Column *ccol = new Column();
        crow->col = ccol;

        while (srow)
        {
            int sum = 0;
            Column *fcol = frow->col;
            Column *scol = srow->col;

            // get one element of product
            while (fcol)
            {
                sum += fcol->val * scol->val;
                fcol = fcol->next;
                scol = scol->next;
            }
            ccol->val = sum;

            srow = srow->next;
            if (srow)
            {
                Column *next = new Column();
                ccol->next = next;
                ccol = next;
            }
            else
            {
                ccol->next = nullptr;
            }
        }

        frow = frow->next;
        if (frow)
        {
            Row *nextRow = new Row();
            nextRow->next = nullptr;
            crow->next = nextRow;
            crow = nextRow;
        }
        else
        {
            crow->next = nullptr;
        }
    }

    return;
}

int main()
{
    cout << "Matrix multiplication using linked list\n========================" << endl;
    Row *first = new Row();
    Row *second = new Row();
    Row *prod = new Row();

    cout << "Input m, n, and p for m*n and n*p matrix:" << endl;
    int m, n, p;
    cin >> m >> n >> p;

    inputMatrix(first, m, n);
    inputMatrix(second, p, n);

    cout << "First Matrix:" << endl;
    printMatrix(first);

    cout << "Second Matrix:" << endl;
    printTranspose(second, p, n);

    multiply(prod, first, second);

    cout << "Multiplied matrix:" << endl;
    printMatrix(prod);

    return 0;
}