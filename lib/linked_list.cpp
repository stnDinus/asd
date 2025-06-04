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

void LinkedList::insert_after(int pos, int x) {
  if (head == NULL) {
    cerr << "cannot call insert_after on empty list" << endl;
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

void LinkedList::insert_before(int pos, int x) {
  if (head == NULL) {
    cerr << "cannot call insert_before on empty list" << endl;
    return;
  }

  int l = len();
  if (pos > l - 1)  {
    cerr << "cannot insert node before position " << pos << " on linked list with length " << l << endl;
    return;
  }

  if (pos == 0) {
    insert_head(x);
    return;
  }

  int i = 1;
  Node* prev_node = head;
  Node* pos_node = head->next;
  while (pos_node != NULL && i != pos) {
    prev_node = pos_node;
    pos_node = pos_node->next;
    i++;
  }

  Node* new_node = new Node();
  new_node->data = x;
  new_node->next = pos_node;

  prev_node->next = new_node;
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

void LinkedList::delete_after(int pos) {
  if (head == NULL) {
    cerr << "cannot call delete_after on empty list" << endl;
    return;
  }

  int l = len();
  if (pos > l - 2)  {
    cerr << "cannot delete node after position " << pos << " on linked list with length " << l << endl;
    return;
  }

  int i = 0;
  Node* pos_node = head;
  while (pos_node != NULL && i != pos) {
    pos_node = pos_node->next;
    i++;
  }

  Node* to_delete = pos_node->next;
  pos_node->next = to_delete->next;
  delete to_delete;
}

void LinkedList::delete_before(int pos) {
  if (head == NULL) {
    cerr << "cannot call delete_before on empty list" << endl;
    return;
  }

  int l = len();
  if (pos > l - 1)  {
    cerr << "cannot delete node before position " << pos << " on linked list with length " << l << endl;
    return;
  }

  if (pos == 0) {
    cerr << "cannot delete node before head" << endl;
    return;
  }

  if (pos == 1) {
    delete_head();
    return;
  }

  int i = 0;
  Node* prev_node = head;
  while (prev_node != NULL && i != pos - 2) {
    prev_node = prev_node->next;
    i++;
  }

  Node* to_delete = prev_node->next;
  prev_node->next = to_delete->next;
  delete to_delete;
}

void LinkedList::delete_data(int data) {
  if (head == NULL) {
    cerr << "calling delete_data on empty list" << endl;
    return;
  }

  bool recheck = true;
  while (recheck && head != NULL) {
    recheck = false;

    if (head->data == data) {
      Node* old_head = head;
      head = head->next;
      recheck = true;
      delete old_head;
      continue;
    }

    Node* prev_node = head;
    Node* current_node = head->next;
    while (current_node != NULL) {
      if (current_node->data == data) {
        prev_node->next = current_node->next;
        delete current_node;
        recheck = true;
        break;
      }
      prev_node = current_node;
      current_node = current_node->next;
    }
  }
}

int LinkedList::len() {
  int i = 0;
  for (Node* n = head; n != NULL; n = n->next, i++) {};
  return i;
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

void LinkedList::deinit() {
  delete head;
}
