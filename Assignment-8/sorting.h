// author: Aryanthepain
#ifndef SORTING_H
#define SORTING_H
#include <bits/stdc++.h>

#define MAXIMUM std::numeric_limits<int8_t>::max()
typedef long long ll;

using namespace std;

// utility functions
void assignArray(int8_t *arr, ll n);
void printArr(int8_t *arr, ll n);

// sorting functions
void bubble_sort(int8_t *arr, ll n);
void selection_sort(int8_t *arr, ll n);
void insertion_sort(int8_t *arr, ll n);

#endif