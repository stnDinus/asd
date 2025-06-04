#include "../lib/lib.hpp"
#include <cassert>

void test_insert_head() {
  LinkedList ll;

  ll.insert_head(2);
  ll.insert_head(1);

  Node* current_node = ll.head;
  assert(current_node->data == 1);

  current_node = current_node->next;
  assert(current_node->data == 2);

  ll.deinit();
}

void test_insert_tail() {
  LinkedList ll;

  ll.insert_tail(1);
  ll.insert_tail(2);

  Node* current_node = ll.head;
  assert(current_node->data == 1);

  current_node = current_node->next;
  assert(current_node->data == 2);

  ll.deinit();
}

void test_delete_head() {
  LinkedList ll;
  ll.insert_tail(1);
  ll.insert_tail(2);

  ll.delete_head();
  Node* current_node = ll.head;
  assert(current_node->data == 2);
  assert(current_node->next == NULL);

  ll.delete_head();
  current_node = ll.head;
  assert(current_node == NULL);

  // check in case of empty list
  ll.delete_head();

  ll.deinit();
}

void test_delete_tail() {
  LinkedList ll;
  ll.insert_tail(1);
  ll.insert_tail(2);

  ll.delete_tail();
  Node* current_node = ll.head;
  assert(current_node->data == 1);
  assert(current_node->next == NULL);

  ll.delete_tail();
  current_node = ll.head;
  assert(current_node == NULL);

  // check in case of empty list
  ll.delete_tail();

  ll.deinit();
}

void test_insert_after() {
  LinkedList ll;

  // should fail
  ll.insert_after(0, 1);

  ll.insert_head(1);

  ll.insert_after(0, 2);
  Node* current_node = ll.head->next;
  assert(current_node->data == 2);

  ll.insert_after(1, 3);
  current_node = current_node->next;
  assert(current_node->data == 3);

  // should fail
  ll.insert_after(3, 5);

  ll.deinit();
}

void test_delete_after() {
  LinkedList ll;

  // should fail
  ll.delete_after(1);

  ll.insert_tail(1);
  ll.insert_tail(2);
  ll.insert_tail(3);
  ll.insert_tail(4);

  ll.delete_after(1);
  Node* current_node = ll.head->next->next;
  assert(current_node->data == 4);

  // should fail
  ll.delete_after(2);

  ll.delete_after(1);
  current_node = ll.head->next->next;
  assert(current_node == NULL);

  ll.deinit();
}

void test_insert_before() {
  LinkedList ll;

  // should fail
  ll.insert_before(0, 1);

  ll.insert_tail(3);

  ll.insert_before(0, 1);
  Node* current_node = ll.head;
  assert(current_node->data == 1);

  ll.insert_before(1, 2);
  current_node = ll.head->next;
  assert(current_node->data == 2);

  ll.deinit();
}

void test_delete_before() {
  LinkedList ll;

  // should fail
  ll.delete_before(0);

  ll.insert_tail(1);
  ll.insert_tail(2);
  ll.insert_tail(3);
  ll.insert_tail(4);

  ll.delete_before(1);
  Node* current_node = ll.head;
  assert(current_node->data == 2);

  ll.delete_before(2);
  current_node = ll.head->next;
  assert(current_node->data == 4);

  ll.deinit();
}

void test_delete_data() {
  LinkedList ll;

  // should fail
  ll.delete_data(0);

  ll.insert_tail(1);
  ll.insert_tail(2);
  ll.insert_tail(3);
  ll.insert_tail(2);
  ll.insert_tail(1);

  ll.delete_data(1);
  Node* current_node = ll.head;
  assert(current_node->data == 2);

  ll.delete_data(2);
  assert(ll.head->data == 3);

  ll.deinit();
}

int main() {
  test_insert_head();
  test_insert_tail();
  test_delete_head();
  test_delete_tail();
  test_insert_after();
  test_delete_after();
  test_insert_before();
  test_delete_before();
  test_delete_data();

  return 0;
}
