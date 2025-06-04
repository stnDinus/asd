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
}

void DoubleLinkedList::insert_before(int pos, int x) {
}

void DoubleLinkedList::delete_head() {
}

void DoubleLinkedList::delete_tail() {
}

void DoubleLinkedList::delete_after(int pos) {
}

void DoubleLinkedList::delete_before(int pos) {
}

void DoubleLinkedList::delete_data(int data) {
}

int DoubleLinkedList::len() {
}

void DoubleLinkedList::print() {
}

void DoubleLinkedList::deinit() {
}

bool DoubleLinkedList::is_empty() {
  return head == NULL && tail == NULL;
}
