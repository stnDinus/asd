#include "./lib.hpp"

void LinkedList::insert_head(int x) {
  Node* new_node = new Node();
  new_node->data = x;

  if (head != NULL) {
    new_node->next = head;
  }

  head = new_node;
}

void LinkedList::insert_tail(int x) {
  Node* new_node = new Node();
  new_node->data = x;

  if (head == NULL) {
    head = new_node;
    return;
  }

  Node* tail;
  for (Node* i = head; i != NULL; i = i->next) {
    tail = i;
  }

  tail->next = new_node;
}

void LinkedList::print() {
  if (head == NULL) {
    cout << "-" << endl;
    return;
  }

  for (Node* i = head; i != NULL; i = i->next) {
    cout << i->data;

    if (i->next != NULL) {
      cout << "->";
    }
  }

  cout << endl;
}

void LinkedList::delete_head() {
  if (head != NULL) {
    Node* new_head = head->next;
    delete head;
    head = new_head;
  };
}

void LinkedList::delete_tail() {
  if (head == NULL) {
    return;
  }

  // in case of only one element
  if (head->next == NULL) {
    delete head;
    head = NULL;
    return;
  }

  Node* prev_node = NULL;
  Node* tail = head;
  while (tail->next != NULL) {
    prev_node = tail;
    tail = tail->next;
  }

  delete prev_node->next;
  prev_node->next = NULL;
}

int LinkedList::len() {
  int i = 0;
  for (Node* n = head; n != NULL; n = n->next, i++) {};
  return i;
}

void LinkedList::insert_after(int pos, int x) {
  if (head == NULL) {
    cerr << "calling insert_after on empty list" << endl;
    return;
  }

  int l = len();
  if (pos > l - 1)  {
    cerr << "cannot insert node after position " << pos << " on linked list with length " << l << endl;
    return;
  }

  int i = 0;
  Node* pos_node = head;
  while (pos_node != NULL && i != pos) {
    pos_node = pos_node->next;
    i++;
  }

  Node* new_node = new Node();
  new_node->data = x;
  new_node->next = pos_node->next;

  pos_node->next = new_node;
}

void LinkedList::delete_data(int data) {
  if (head->data == data) {
    delete_head();
  }

  Node* pre;
  for (Node* n = head->next; n != NULL; pre = n, n = n->next) {
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

void LinkedList::delete_at(int at) {
  int l = len();
  if (at > l - 1)  {
    cerr << "invalid position " << at << " on linked list with length " << l << endl;
    return;
  }

  if (at == 0) {
    delete_head();
    return;
  }

  int i = 1;
  Node* pre_at = head;
  for (Node* n = head->next; n != NULL; n = n->next, i++) {
    if (i == at) {
      pre_at->next = n->next;
      delete n;
      break;
    }
    pre_at = n;
  }
}

void LinkedList::deinit() {
  delete head;
}
