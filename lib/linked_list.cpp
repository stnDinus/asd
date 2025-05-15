#include "./lib.hpp"

void LinkedList::insert_head(int x) {
  Node* temp = new Node();
  temp->data = x;

  if (HEAD != NULL) {
    temp->next = HEAD;
  }

  HEAD = temp;
}

void LinkedList::insert_tail(int x) {
  Node* temp = new Node();
  temp->data = x;

  Node* tail;
  for (Node* i = HEAD; i != NULL; i = i->next) {
    tail = i;
  }

  tail->next = temp;
}

void LinkedList::print() {
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

void LinkedList::pop_head() {
  if (HEAD != NULL) {
    Node* temp = HEAD->next;
    delete HEAD;
    HEAD = temp;
  };
}

void LinkedList::pop_tail() {
  if (HEAD == NULL) {
    return;
  }
  Node* pre_tail;
  for (Node* i = HEAD; i != NULL ; i = i->next) {
    if (i->next == NULL) {
      delete i;
      break;
    }
    pre_tail = i;
  }
  pre_tail->next = NULL;
}

int LinkedList::len() {
  int i = 0;
  for (Node* n = HEAD; n != NULL; n = n->next, i++) {};
  return i;
}

void LinkedList::insert_at(int at, int x) {
  int l = len();
  if (at > l - 1)  {
    cerr << "invalid position " << at << " on linked list with length " << l << endl;
    return;
  }

  if (at == 0) {
    insert_head(x);
  }

  int i = 1;
  Node* pre_at = HEAD;
  for (Node* n = HEAD->next; n != NULL; n = n->next, i++) {
    if (i == at) {
      Node* temp = new Node();
      temp->data = x;
      temp->next = n;
      pre_at->next = temp;
      break;
    }
    pre_at = n;
  }
}

void LinkedList::pop(int data) {
  if (HEAD->data == data) {
    pop_head();
  }

  Node* pre;
  for (Node* n = HEAD->next; n != NULL; pre = n, n = n->next) {
    if (n->data != data) {
      continue;
    }

    if (n->next == NULL) {
      delete n;
      pre->next = NULL;
      break;
    }

    pre->next = n->next;
  }
}

void LinkedList::pop_at(int at) {
  int l = len();
  if (at > l - 1)  {
    cerr << "invalid position " << at << " on linked list with length " << l << endl;
    return;
  }

  if (at == 0) {
    pop_head();
    return;
  }

  int i = 1;
  Node* pre_at = HEAD;
  for (Node* n = HEAD->next; n != NULL; n = n->next, i++) {
    if (i == at) {
      pre_at->next = n->next;
      delete n;
      break;
    }
    pre_at = n;
  }
}

void LinkedList::deinit() {
  delete HEAD;
}
