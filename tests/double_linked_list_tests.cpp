#include "../lib/lib.hpp"
#include <cassert>

#define INIT_TEST() \
  DoubleLinkedList dll; \
  BiNode* current_node; \
  BiNode* next_node; \
  BiNode* prev_node;

#define INIT_NODES(N) \
  current_node = N; \
  next_node = current_node->next; \
  prev_node = current_node->prev;

#define ADVANCE_NODES() \
  current_node = next_node; \
  next_node = current_node->next; \
  prev_node = current_node->prev;

void test_insert_head() {
  INIT_TEST();

  dll.insert_head(3);
  assert(dll.head->data == 3);
  assert(dll.tail->data == 3);
  INIT_NODES(dll.head);
  assert(current_node->data == 3);
  assert(next_node == NULL);
  assert(prev_node == NULL);

  dll.insert_head(2);
  assert(dll.head->data == 2);
  assert(dll.tail->data == 3);
  INIT_NODES(dll.head);
  assert(current_node->data == 2);
  assert(next_node->data == 3);
  assert(prev_node == NULL);

  dll.insert_head(1);
  assert(dll.head->data == 1);
  assert(dll.tail->data == 3);
  INIT_NODES(dll.head);
  assert(current_node->data == 1);
  assert(next_node->data == 2);
  assert(prev_node == NULL);

  dll.deinit();
}

void test_insert_tail() {
  INIT_TEST();

  dll.insert_tail(1);
  assert(dll.head->data == 1);
  assert(dll.tail->data == 1);
  INIT_NODES(dll.tail);
  assert(current_node->data == 1);
  assert(next_node == NULL);
  assert(prev_node == NULL);

  dll.insert_tail(2);
  assert(dll.head->data == 1);
  assert(dll.tail->data == 2);
  INIT_NODES(dll.tail);
  assert(current_node->data == 2);
  assert(next_node == NULL);
  assert(prev_node->data == 1);

  dll.insert_tail(3);
  assert(dll.head->data == 1);
  assert(dll.tail->data == 3);
  INIT_NODES(dll.tail);
  assert(current_node->data == 3);
  assert(next_node == NULL);
  assert(prev_node->data == 2);

  dll.deinit();
}

void test_insert_after() {
}

void test_insert_before() {
}

void test_delete_head() {
}

void test_delete_tail() {
}

void test_delete_after() {
}

void test_delete_before() {
}

void test_delete_data() {
}

int main() {
  test_insert_head();
  test_insert_tail();
  test_insert_after();
  test_insert_before();
  test_delete_head();
  test_delete_tail();
  test_delete_after();
  test_delete_before();
  test_delete_data();

  return 0;
}
