#pragma once

#include <iostream>
#include <cstddef> // used for NULL type

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

class Node {
public:
  int data;
  Node* next;
};

class LinkedList {
public:
  Node* head = NULL;

  // insert methods
  void insert_head(int x);
  void insert_tail(int x);
  void insert_after(int pos, int x);
  void insert_before(int pos, int x);

  // delete methods
  void delete_head();
  void delete_tail();
  void delete_after(int pos);
  void delete_before(int pos);
  void delete_data(int data);

  // utility methods
  int len();
  void print();
  void deinit();
};
