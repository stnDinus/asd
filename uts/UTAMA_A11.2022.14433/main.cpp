// Steven Nugraha
// A11.2022.14433

#include <iostream>
#include <cstddef> // untuk tipe NULL di linux

using namespace std;

struct Node {
  int data;
  Node* next;
};

struct LinkedList {
  Node* HEAD = NULL;

  void pop_head() {
    if (HEAD != NULL) {
      Node* temp = HEAD->next;
      delete HEAD;
      HEAD = temp;
    };
  }

  void insert_tail(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (HEAD == NULL) {
      HEAD = temp;
      return;
    }

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

  int sum() {
    int sum = 0;

    for (Node* i = HEAD; i != NULL; i = i->next) {
      sum += i->data;
    }

    return sum;
  }

  int len() {
    int i = 0;
    for (Node* n = HEAD; n != NULL; n = n->next, i++) {};
    return i;
  }

  float avg() {
    float fsum = sum();
    float flen = len();
    return fsum / flen;
  }

  int at(int at) {
    int i = 0;
    for (Node* n = HEAD; n != NULL; n = n->next, i++) {
      if (i == at) {
        return n->data;
      }
    }

    return -1;
  }

  int min_idx() {
    if (HEAD == NULL) {
      return -1;
    }

    int i = 0;
    int min = HEAD->data;
    int idx = 0;

    for (Node* n = HEAD; n != NULL; n = n->next, i++) {
      if (n->data < min) {
        idx = i;
        min = n->data;
      }
    };

    return idx;
  }

  int max_idx() {
    if (HEAD == NULL) {
      return -1;
    }

    int i = 0;
    int max = HEAD->data;
    int idx = 0;

    for (Node* n = HEAD; n != NULL; n = n->next, i++) {
      if (n->data > max) {
        idx = i;
        max = n->data;
      }
    };

    return idx;
  }
};

int main() {
  LinkedList ll;

  // input penambahan belakang
  while (true) {
    int x;
    cout << "Masukan bilangan: "; cin >> x;
    ll.insert_tail(x);
    ll.print();

    char c_done = 'n';
    while (true) {
      cout << "Selesai? (y/n)"; cin >> c_done;
      if (c_done == 'y' || c_done == 'n') {
        break;
      }
    }
    if (c_done == 'y') {
      break;
    }
  }

  // input penghapusan depan
  while (true) {
    char c_del = 'n';
    while (true) {
      cout << "Hapus depan? (y/n)"; cin >> c_del;
      if (c_del == 'y' || c_del == 'n') {
        break;
      }
    }

    if (c_del == 'n') {
      break;
    }

    ll.pop_head();
    ll.print();
  }

  ll.print();

  if (ll.len() == 0) {
    cerr << "List kosong!" << endl;
    return -1;
  }

  cout << "\nTotal: " << ll.sum() << endl;
  cout << "Rata-rata: " << ll.avg() << endl;

  int min_idx = ll.min_idx();
  cout << "Bliangan terkecil terletak pada posisi: " << min_idx << " dengan nilai: " << ll.at(min_idx) << endl;

  int max_idx = ll.max_idx();
  cout << "Bliangan terbesar terletak pada posisi: " << max_idx << " dengan nilai: " << ll.at(max_idx) << endl;

  cout << "*posisi dimulai dari 0 seperti array" << endl;

  delete ll.HEAD;

  return 0;
}
