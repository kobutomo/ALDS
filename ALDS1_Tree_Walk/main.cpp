#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define NIL -1

struct Node {
  int parent = NIL, left = NIL, right = NIL;
};

Node nodes[25];
int root;

void preorder(int id) {
  Node node = nodes[id];
  cout << id;
  if (node.left != NIL) {
    cout << " ";
    preorder(node.left);
  }
  if (node.right != NIL) {
    cout << " ";
    preorder(node.right);
  }
}

void inorder(int id) {
  Node node = nodes[id];
  if (node.left != NIL) {
    inorder(node.left);
    cout << " ";
  }
  cout << id;
  if (node.right != NIL) {
    cout << " ";
    inorder(node.right);
  }
}

void postorder(int id) {
  Node node = nodes[id];
  if (node.left != NIL) {
    postorder(node.left);
    cout << " ";
  }
  if (node.right != NIL) {
    postorder(node.right);
    cout << " ";
  }
  cout << id;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int id, l, r;
    scanf("%d %d %d", &id, &l, &r);
    nodes[id].left = l;
    nodes[id].right = r;
    if (l != NIL)
      nodes[l].parent = id;
    if (r != NIL)
      nodes[r].parent = id;
  }
  for (int i = 0; i < n; ++i) {
    if (nodes[i].parent == NIL) root = i;
  }

  cout << "Preorder" << endl << " ";
  preorder(root);
  cout << "\nInorder" << endl << " ";
  inorder(root);
  cout << "\nPostorder" << endl << " ";
  postorder(root);
  cout << endl;
}
