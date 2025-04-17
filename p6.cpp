// A11.2022.14433

#include <iostream>
#include <cstddef> // untuk tipe NULL

using namespace std;

struct Node {
  int data;
  Node* next;
};

struct LinkedList {
  Node* HEAD = NULL;

  void insert_head(int x) {
    Node* temp = new Node();
    temp->data = x;

    if (HEAD != NULL) {
      temp->next = HEAD;
    }

    HEAD = temp;
  }

  void insert_tail(int x) {
    Node* temp = new Node();
    temp->data = x;

    Node* tail;
    for (Node* i = HEAD; i != NULL; i = i->next) {
      tail = i;
    }

    tail->next = temp;
  }

  void print() {
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

  void pop_front() {
    if (HEAD != NULL) {
      HEAD = HEAD->next;
    };
  }

  void pop_back() {
    if (HEAD == NULL) {
      return;
    }
    Node* pre_tail;
    for (Node* i = HEAD; i != NULL ; i = i->next) {
      if (i->next == NULL) {
        break;
      }
      pre_tail = i;
    }
    pre_tail->next = NULL;
  }
};

int main() {
  LinkedList l;
  l.insert_head(1);
  l.insert_head(2);

  l.insert_tail(3);

  l.print();

  l.pop_front();

  l.print();

  l.pop_back();

  l.print();

  return 0;
}
