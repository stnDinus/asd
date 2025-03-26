#pragma once

#include <iostream>

using namespace std;

void swap(int* i, int* j);
bool is_asc(int a[], int n);
void print_arr(int a[], int n);
// searching
int linear_search(int a[], int n, int x);
int binary_search(int sorted_a[], int n, int x);
// sorting
void bubble_sort(int a[], int n);
void selection_sort(int a [], int n);
void insertion_sort(int a[], int n);

class Wrapper {
int* a;
int n;

void modify();
void sort();
void search();
void init();

public:
  Wrapper(int* in_a, int in_n);
  Wrapper();
};
