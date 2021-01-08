#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Node {
  int key;
  Node *left;
  Node *right;
  Node *parent;
};

Node *NIL;
Node *root = NIL;

void preorder(Node *node) {
  cout << node->key;
  if (node->left != NIL) {
    cout << " ";
    preorder(node->left);
  }
  if (node->right != NIL) {
    cout << " ";
    preorder(node->right);
  }
}

void inorder(Node *node) {
  if (node->left != NIL) {
    inorder(node->left);
    cout << " ";
  }
  cout << node->key;
  if (node->right != NIL) {
    cout << " ";
    inorder(node->right);
  }
}

Node *getNextInorder(Node *node) {
  if (node->left != NIL)
    return getNextInorder(node->left);
  else if (node->right != NIL)
    return getNextInorder(node->right);
  return node;
}

void insert(int key) {
  Node *node;
  node = (Node *) malloc(sizeof(Node));
  node->key = key;
  node->left = NIL;
  node->right = NIL;
  node->parent = NIL;
  if (root == NIL) {
    root = node;
  } else {
    Node *p, *x = root;
    while (x != NIL) {
      p = x;
      if (x->key > key)x = x->left;
      else x = x->right;
    }
    node->parent = p;
    if (p->key > key) p->left = node;
    else p->right = node;
  }
}

Node *find(int key, Node *r) {
  if (r == NIL) return NIL;
  if (key == r->key) return r;
  else if (key < r->key) return find(key, r->left);
  else return find(key, r->right);
}

void del(int key) {
  Node *target = find(key, root);
  if (target == NIL) return;
  Node *p = target->parent;
  if (target->left == NIL && target->right == NIL) {
//      パターン1
    target->parent = NIL;
    if (p->left == target) p->left = NIL;
    else if (p->right == target) p->right = NIL;
    target = NIL;
  } else if (target->left != NIL && target->right == NIL) {
//      パターン2
    if (p->left == target) p->left = target->left;
    else if (p->right == target) p->right = target->left;
    if (target == root) root = target->left;
    target->left->parent = p;
    target = NIL;
  } else if (target->left == NIL && target->right != NIL) {
//      パターン2
    if (p->left == target) p->left = target->right;
    else if (p->right == target) p->right = target->right;
    if (target == root) root = target->right;
    target->right->parent = p;
    target = NIL;
  } else {
    Node *next = getNextInorder(target->right);
    int k = next->key;
    del(next->key);
    target->key = k;
  }
}

int main() {
  int n, k;
  string c;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> c;
    if (c == "insert") {
      cin >> k;
      insert(k);
    } else if (c == "find") {
      cin >> k;
      Node *target = find(k, root);
      if (target != NIL)cout << "yes" << endl;
      else cout << "no" << endl;
    } else if (c == "delete") {
      cin >> k;
      del(k);
    } else {
      cout << " ";
      inorder(root);
      cout << endl;
      cout << " ";
      preorder(root);
      cout << endl;
    }
  }
}
