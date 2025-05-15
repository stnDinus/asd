#include <iostream>
#include <cstddef>

using namespace std;

class BiNode {
public:
  int data;
  BiNode* next;
  BiNode* prev;
};

class DoubleLinkedList {
public:
  BiNode* head = NULL;
  BiNode* tail = NULL;

  bool is_empty();
  void insert_head(BiNode*);
  void insert_tail(BiNode*);
  void pop_head();
  void pop_tail();

  void print() {
    if (is_empty()) {
      cout << "head:\tNULL" << endl;
      cout << "tail:\tNULL" << endl;
      return;
    }

    cout << "head:\t" << head->data << endl;
    cout << "tail:\t" << tail->data << endl;
  };
};

bool DoubleLinkedList::is_empty() {
  return head == NULL || tail == NULL;
}

void DoubleLinkedList::insert_head(BiNode* new_head) {
  if (is_empty()) {
    head = new_head;
    tail = new_head;
    return;
  }

  // link new_head's neighbors
  new_head->next = head;
  new_head->prev = NULL;

  // link initial head's previous node to new_head
  head->prev = new_head;

  // assign new head
  head = new_head;
}

void DoubleLinkedList::insert_tail(BiNode* new_tail) {
  if (is_empty()) {
    head = new_tail;
    tail = new_tail;
    return;
  }

  // link new_tail's neighbors
  new_tail->next = NULL;
  new_tail->prev = tail;

  // link initial tail's next node to new_tail
  tail->next = new_tail;

  // asign new tail
  tail = new_tail;
}

void DoubleLinkedList::pop_head() {
  if (is_empty()) return;

  BiNode* old_head = head;

  // in case only one node is left
  if (head == tail) {
    head = NULL;
    tail = NULL;
    delete old_head;
    return;
  }

  BiNode* new_head = old_head->next;
  new_head->prev = NULL;

  head = new_head;

  delete old_head;
}

void DoubleLinkedList::pop_tail() {
  if (is_empty()) return;

  BiNode* old_tail = tail;

  // in case only one node is left
  if (head == tail) {
    head = NULL;
    tail = NULL;
    delete old_tail;
    return;
  }

  BiNode* new_tail = old_tail->prev;
  new_tail->next = NULL;

  tail = new_tail;

  delete old_tail;
}

int main() {
  DoubleLinkedList dll;

  cout << "insert head test" << endl;
  BiNode* new_head = new BiNode();
  new_head->data = 5;
  dll.insert_head(new_head);
  dll.print();
  cout << endl;

  cout << "insert tail test" << endl;
  BiNode* new_tail = new BiNode();
  new_tail->data = 7;
  dll.insert_tail(new_tail);
  dll.print();
  cout << endl;

  cout << "pop head test" << endl;
  dll.pop_head();
  dll.print();
  cout << endl;

  cout << "pop tail test" << endl;
  dll.pop_tail();
  dll.print();
}
