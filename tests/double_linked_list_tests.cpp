#include "../lib/lib.hpp"
#include <cassert>
#include "./helper.cpp"

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
  INIT_TEST();

  // negative pos, should fail
  dll.insert_after(-1, 1);

  // insert on empty list, should fail
  dll.insert_after(0, 1);

  dll.insert_tail(1);

  // insert tail
  dll.insert_after(0, 3);
  assert(dll.tail->data == 3);
  INIT_NODES(dll.tail);
  assert(current_node->data == 3);
  assert(next_node == NULL);
  assert(prev_node->data == 1);

  // insert intermediate
  dll.insert_after(0, 2);
  INIT_NODES(dll.head->next);
  assert(current_node->data == 2);
  assert(next_node->data == 3);
  assert(prev_node->data == 1);

  dll.insert_after(2, 5);
  INIT_NODES(dll.tail);
  assert(current_node->data == 5);
  assert(next_node == NULL);
  assert(prev_node->data == 3);

  // insert at pos > len, should fail
  dll.insert_after(2, 5);

  dll.deinit();
}

void test_insert_before() {
}

void test_delete_head() {
  INIT_TEST();

  dll.insert_tail(1);
  dll.insert_tail(2);
  dll.insert_tail(3);

  dll.delete_head();
  assert(dll.head->data == 2);
  assert(dll.tail->data == 3);
  INIT_NODES(dll.head);
  assert(current_node->data == 2);
  assert(next_node->data == 3);
  assert(prev_node == NULL);

  dll.delete_head();
  assert(dll.head->data == 3);
  assert(dll.tail->data == 3);
  INIT_NODES(dll.head);
  assert(current_node->data == 3);
  assert(next_node == NULL);
  assert(prev_node == NULL);

  // in case of one element
  dll.delete_head();
  assert(dll.is_empty());

  // in case of empty list
  dll.delete_head();
  assert(dll.is_empty());
}

void test_delete_tail() {
  INIT_TEST();

  dll.insert_tail(1);
  dll.insert_tail(2);
  dll.insert_tail(3);

  dll.delete_tail();
  assert(dll.head->data == 1);
  assert(dll.tail->data == 2);
  INIT_NODES(dll.tail);
  assert(current_node->data == 2);
  assert(next_node == NULL);
  assert(prev_node->data == 1);

  dll.delete_tail();
  assert(dll.head->data == 1);
  assert(dll.tail->data == 1);
  INIT_NODES(dll.tail);
  assert(current_node->data == 1);
  assert(next_node == NULL);
  assert(prev_node == NULL);

  // in case of one element
  dll.delete_tail();
  assert(dll.is_empty());

  // in case of empty list
  dll.delete_tail();
  assert(dll.is_empty());
}

void test_delete_after() {
}

void test_delete_before() {
}

void test_delete_data() {
}

void test_insertion_sort() {
  int n = 1000;
  for (int i = 0; i < n; i++) {
    INIT_TEST();

    int n = 8;
    for (int i = 0; i < n; i++) {
      dll.insert_tail(gen_rand());
    }

    dll.insertion_sort();

    INIT_NODES(dll.head->next);
    for (int i = 1; i < n; i++) {
      assert(current_node->data >= current_node->prev->data);
      current_node = current_node->next;
    }

    delete dll.head;
  }
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
  test_insertion_sort();

  return 0;
}
