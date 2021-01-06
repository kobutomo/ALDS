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

int main() {
  int n, k;
  string c;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> c;
    if (c == "insert") {
      scanf("%d", &k);
      insert(k);
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
