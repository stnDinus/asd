#include <iostream>
#include <cstddef>

using namespace std;

struct TreeNode {
  int data;
  TreeNode* left = NULL;
  TreeNode* right = NULL;

  TreeNode(int);
};

struct Tree {
  TreeNode* root = NULL;

  void insert(int);
  TreeNode* insert_from(TreeNode*, int);
};

struct QueueNode {
  TreeNode* data;
  QueueNode* next = NULL;

  QueueNode(TreeNode*);
};

struct Queue {
  QueueNode* head = NULL;
  QueueNode* tail = NULL;

  bool is_empty();
  QueueNode* pop();
  void push(TreeNode*);
};

// Breadth first search / Tree level order
void tree_lvl_order(Tree* t) {
  Queue q;

  q.push(t->root);

  while (!q.is_empty()) {
    QueueNode* current_q_node = q.pop();

    if (current_q_node == NULL) {
      break;
    }

    TreeNode* current_t_node = current_q_node->data;

    q.push(current_t_node->left);
    q.push(current_t_node->right);

    cout << current_t_node->data << endl;
  }

  delete q.head;
}

int main() {
  Tree t;

  int n = 7;
  int a[n] = {3, 2, 5, 1, 3, 4, 6};
  for (int i = 0; i < n; i++) {
    t.insert(a[i]);
  }

  tree_lvl_order(&t);

  if (t.root != NULL) {
    delete t.root;
  }

  return 0;
}

TreeNode::TreeNode(int x ) {
  data = x;
}

void Tree::insert(int x) {
  root = insert_from(root, x);
}

TreeNode* Tree::insert_from(TreeNode* t_node, int x) {
    if (t_node == NULL) {
      return new TreeNode(x);
    }

    if (x > t_node->data) {
      t_node->right = insert_from(t_node->right, x);
    } else {
      t_node->left = insert_from(t_node->left, x);
    }

    return t_node;
}

QueueNode::QueueNode(TreeNode* tree_node) {
  data = tree_node;
}

bool Queue::is_empty() {
  return head == NULL;
}

QueueNode* Queue::pop() {
  if (head == NULL) {
    return NULL;
  }

  QueueNode* old_head = head;
  head = head->next;

  if (head == NULL) {
    tail = NULL;
  }

  return old_head;
}

void Queue::push(TreeNode* t_node) {
  if (t_node == NULL) {
    return;
  }

  QueueNode* new_q_node = new QueueNode(t_node);

  if (head == NULL) {
    head = tail = new_q_node;
    return;
  }

  tail->next = new_q_node;
  tail = new_q_node;
}
