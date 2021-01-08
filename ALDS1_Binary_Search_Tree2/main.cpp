#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Node {
  int key;
  Node *left;
  Node *right;
};

Node *NIL;
vector<Node *> nodes;
bool exist = false;

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

void insert(int key) {
  Node *node;
  node = (Node *) malloc(sizeof(Node));
  node->key = key;
  node->left = NIL;
  node->right = NIL;
  if (!nodes.empty()) {
    Node *p, *x = nodes.at(0);
    while (x != NIL) {
      p = x;
      if (x->key > key)x = x->left;
      else x = x->right;
    }
    if (p->key > key) p->left = node;
    else p->right = node;
  }
  nodes.push_back(node);
}

void find(int key, Node *root) {
  if (root == NIL) return;
  if (key == root->key) {
    exist = true;
    return;
  } else if (key < root->key) find(key, root->left);
  else find(key, root->right);
}

int main() {
  int n, k;
  string c;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> c;
    if (c == "insert") {
      scanf("%d", &k);
      insert(k);
    } else if (c == "find") {
      exist = false;
      scanf("%d", &k);
      if (nodes.at(0) == NIL) cout << "no\n";
      else {
        find(k, nodes.at(0));
        if (exist)cout << "yes\n";
        else cout << "no\n";
      }
    } else {
      cout << " ";
      inorder(nodes.at(0));
      cout << endl;
      cout << " ";
      preorder(nodes.at(0));
      cout << endl;
    }
  }
}
