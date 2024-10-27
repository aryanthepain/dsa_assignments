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
void copy_array(int8_t *src, int8_t *dest, ll n);

// sorting functions
void insertion_sort(int8_t *arr, ll n);
void bubble_sort(int8_t *arr, ll n);
void selection_sort(int8_t *arr, ll n);
void quick_sort(int8_t *arr, ll n, ll l = 0);
void merge_sort(int8_t *arr, ll n, ll l = 0);
void radix_sort(int8_t *arr, ll n);
void bucket_sort(int8_t *arr, ll n);

#endif