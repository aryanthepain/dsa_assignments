// author: Aryanthepain
#include "hash.h"
using namespace std;

int hashValue(int x)
{
    return x % 10;
}

void hashMap::insert(int x)
{
    arr[hashValue(x)].insert(x);

    return;
}

void search(int x);

void printAll();

void deleteElement(int x);

int main();