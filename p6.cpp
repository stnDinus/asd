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

  void insert_head(Node* temp, int x) {
    temp->data = x;

    if (HEAD != NULL) {
      temp->next = HEAD;
    }

    HEAD = temp;
  }

  void insert_tail(Node* temp, int x) {
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

  void pop_front(Node* temp, int x) {
    if (HEAD != NULL) {
      HEAD = HEAD->next;
    };
  }

  void pop_back(Node* temp, int x) {
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
};

int main() {
  LinkedList l;
  l.insert_head(new Node(), 1);
  l.insert_head(new Node(), 2);

  l.insert_tail(new Node(), 3);

  l.print();

  l.pop_front(new Node(), 0);

  l.print();

  l.pop_back(new Node(), 0);

  l.print();

  return 0;
}
