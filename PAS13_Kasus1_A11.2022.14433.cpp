// A11.2022.14433
#include <iostream>
#include <cstddef> // import NULL

using namespace std;

class BiNode {
public:
  int data;
  BiNode* next = NULL;
  BiNode* prev = NULL;
};

class DoubleLinkedList {
public:
  BiNode* head = NULL;
  BiNode* tail = NULL;

  // insert methods
  void insert_head(int x);
  void insert_tail(int x);

  // delete methods
  void delete_head();
  void delete_tail();

  // utility methods
  int len();
  void print();
  void deinit();
  bool is_empty();
};

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

enum QueueListError {
  OK,
  IS_FULL,
  IS_EMPTY
};

const char* map_queue_list_error(QueueListError err) {
  switch (err) {
    case QueueListError::IS_FULL:
      return "QueueList full";
    case QueueListError::IS_EMPTY:
      return "QueueList empty";
  }
  return "";
}

class QueueList {
  DoubleLinkedList dll;
public:
  int capacity;

  QueueList(int p_capacity);

  void enqueue(int x);
  tuple<QueueListError, int> dequeue();

  void print();
  void deinit();
  int len();
  bool is_empty();
  bool is_full();
};

QueueList::QueueList(int p_capacity) {
  capacity = p_capacity;
}

void QueueList::enqueue(int x) {
  if (dll.len() >= capacity) {
    return;
  };

  dll.insert_tail(x);
}

tuple<QueueListError, int> QueueList::dequeue() {
  if (is_empty()) {
    return {QueueListError::IS_EMPTY, 0};
  }

  int x = dll.head->data;

  dll.delete_head();

  return {QueueListError::OK, x};
}

void QueueList::print() {
  if (dll.head == NULL) {
    cout << "-" << endl;
    return;
  }

  for (BiNode* i = dll.head; i != NULL; i = i->next) {
    cout << i->data;

    if (i->next != NULL) {
      cout << "->";
    }
  }

  cout << endl;
}

void QueueList::deinit() {
  dll.deinit();
}

int QueueList::len() {
  return dll.len();
}

bool QueueList::is_empty() {
  return dll.is_empty();
}

bool QueueList::is_full() {
  return len() >= capacity;
}

int main() {
  QueueList ql = QueueList(3);
  cout << "init QueueList with capacity: " << ql.capacity << endl;

  int n = 4;
  int a[n] = {1, 2, 3, 4};

  cout << "\nEnqueue test\n===" << endl;
  for (int i = 0; i < n; i++) {
    cout << "len:\t" << ql.len() << endl;
    cout << "full?\t" << (ql.is_full() ? 'y' : 'n') << endl;
    cout << "empty?\t" << (ql.is_empty() ? 'y' : 'n') << endl;
    cout << "enqueue\t" << a[i] << endl;
    ql.enqueue(a[i]);
    cout << "state: ";
    ql.print();
    cout << endl;
  }

  cout << "\nDequeue test\n===" << endl;
  for (int i = 0; i < n; i++) {
    cout << "len:\t\t" << ql.len() << endl;
    cout << "full?\t\t" << (ql.is_full() ? 'y' : 'n') << endl;
    cout << "empty?\t\t" << (ql.is_empty() ? 'y' : 'n') << endl;

    tuple<QueueListError, int> dq_res = ql.dequeue();

    QueueListError err = get<0>(dq_res);
    if (err != QueueListError::OK) {
      cerr << "Error: " << map_queue_list_error(err) << endl;
      continue;
    }

    cout << "dequeued:\t" << get<1>(dq_res) << endl;
    cout << "state: ";
    ql.print();
    cout << endl;
  }

  ql.deinit();
}
