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

  void pop_head() {
    if (HEAD != NULL) {
      HEAD = HEAD->next;
    };
  }

  void pop_tail() {
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

  int len() {
    int i = 0;
    for (Node* n = HEAD; n != NULL; n = n->next, i++) {};
    return i;
  }

  void insert_at(int at, int x) {
    int l = len();
    if (at > l - 1)  {
      cerr << "invalid position " << at << " on linked list with length " << l << endl;
      return;
    }

    if (at == 0) {
      insert_head(x);
    }

    Node* temp = new Node();
    temp->data = x;

    int i = 0;
    Node* pre_at;
    for (Node* n = HEAD->next; n != NULL; n = n->next, i++) {
      if (i == at) {
        pre_at->next = temp;
        temp->next = n;
        break;
      }
      pre_at = n;
    }
  }

  void pop(int data) {
    if (HEAD->data == data) {
      pop_head();
    }

    Node* pre;
    for (Node* n = HEAD->next; n != NULL; pre = n, n = n->next) {
      if (n->data != data) {
        continue;
      }

      if (n->next == NULL) {
        pre->next = NULL;
        break;
      }

      pre->next = n->next;
    }
  }
};

int main() {
  LinkedList l;
  l.insert_head(1);
  l.insert_head(2);
  l.insert_head(4);
  l.insert_head(7);

  l.insert_tail(3);

  l.print();

  l.pop_head();

  l.print();

  l.pop_tail();

  l.print();

  l.insert_at(0, 9);

  l.print();

  l.insert_at(2, 8);

  l.print();

  l.insert_at(l.len(), 0);

  l.print();

  l.insert_head(8);
  l.insert_tail(8);

  l.print();

  l.pop(8);

  l.print();

  return 0;
}
