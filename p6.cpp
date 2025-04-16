// A11.2022.14433

#include <iostream>
#include <cstddef> // untuk tipe NULL

using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* HEAD = NULL;

void insert_depan(Node* temp, int x) {
  temp->data = x;

  if (HEAD != NULL) {
    temp->next = HEAD;
  }

  HEAD = temp;
}

void insert_belakang(Node* temp, int x) {
  temp->data = x;

  Node* tail;
  for (Node* i = HEAD; i != NULL; i = i->next) {
    tail = i;
  }

  tail->next = temp;
}

void cetak() {
  if (HEAD == NULL) {
    cout << "-" << endl;
    return;
  }

  for (Node* i = HEAD; i != NULL; i = i->next) {
    cout << i->data;

    if (i->next != NULL) {
      cout << "->";
    }
  }

  cout << endl;
}

void hapus_depan(Node* temp, int x) {
  if (HEAD != NULL) {
    HEAD = HEAD->next;
  };
}

void hapus_belakang(Node* temp, int x) {
  if (HEAD == NULL) {
    return;
  }
  Node* pre_temp;
  for (Node* i = HEAD; i != NULL ; i = i->next) {
    if (i->next == NULL) {
      break;
    }
    pre_temp = i;
  }
  pre_temp->next = NULL;
}

int main() {
  insert_depan(new Node(), 1);
  insert_depan(new Node(), 2);

  insert_belakang(new Node(), 3);

  cetak();

  hapus_depan(new Node(), 0);

  cetak();

  hapus_belakang(new Node(), 0);

  cetak();

  return 0;
}
