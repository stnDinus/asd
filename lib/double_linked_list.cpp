#include "./lib.hpp"

void DoubleLinkedList::insert_head(int x) {
  BiNode* new_head = new BiNode();
  new_head->data = x;

  if (is_empty()) {
    head = tail = new_head;
    return;
  }

  new_head->next = head;
  head->prev = new_head;
  head = new_head;
}

void DoubleLinkedList::insert_tail(int x) {
  BiNode* new_tail = new BiNode();
  new_tail->data = x;

  if (is_empty()) {
    head = tail = new_tail;
    return;
  }

  new_tail->prev = tail;
  tail->next = new_tail;
  tail = new_tail;
}

void DoubleLinkedList::insert_after(int pos, int x) {
  if (pos < 0) {
    return;
  }

  if (is_empty()) {
    return;
  }

  int i = 0;
  BiNode* current_node = head;
  while (i != pos && current_node->next != NULL) {
    current_node = current_node->next;
    i++;
  }

  if (i != pos) {
    return;
  }

  BiNode* new_node = new BiNode();
  new_node->data = x;
  new_node->next = current_node->next;
  new_node->prev = current_node;

  current_node->next = new_node;

  if (new_node->next == NULL) {
    tail = new_node;
  }
}

void DoubleLinkedList::insert_before(int pos, int x) {
}

void DoubleLinkedList::delete_head() {
  if (is_empty()) {
    return;
  }

  BiNode* old_head = head;

  if (len() == 1) {
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

void DoubleLinkedList::delete_tail() {
  if (is_empty()) {
    return;
  }

  BiNode* old_tail = tail;

  if (len() == 1) {
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

void DoubleLinkedList::delete_after(int pos) {
}

void DoubleLinkedList::delete_before(int pos) {
}

void DoubleLinkedList::delete_data(int data) {
}

int DoubleLinkedList::len() {
  int i = 0;
  for (BiNode* n = head; n != NULL; n = n->next, i++) {};
  return i;
}

void DoubleLinkedList::print() {
  if (is_empty()) {
    cout << "-" << endl;
    return;
  }

  for (BiNode* i = head; i != NULL; i = i->next) {
    cout << i->data;

    if (i->next != NULL) {
      cout << "<->";
    }
  }

  cout << endl;
}

void DoubleLinkedList::deinit() {
  delete head;
}

bool DoubleLinkedList::is_empty() {
  return head == NULL && tail == NULL;
}

void DoubleLinkedList::insertion_sort() {
  BiNode* current_node = head->next;

  while (current_node != NULL) {
    int key = current_node->data;

    BiNode* pivot_node = current_node->prev;
    while (pivot_node != NULL && pivot_node->data > key) {
      pivot_node->next->data = pivot_node->data;
      pivot_node = pivot_node->prev;
    }

    if (pivot_node == NULL) {
      head->data = key;
    } else {
      pivot_node->next->data = key;
    }

    current_node = current_node->next;
  }
}
