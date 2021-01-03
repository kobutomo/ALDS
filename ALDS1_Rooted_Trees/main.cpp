#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Node {
  int parent;
  int depth;
  string type;
  string child;
};

Node nodes[120000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int id, k, c;
    scanf("%d %d", &id, &k);
    if (k > 0) {
      nodes[id].type = "internal node";
    } else {
      nodes[id].type = "leaf";
    }
    if (k > 0) {
      nodes[id].child = "[";
    } else {
      nodes[id].child = "[]";
    }
    for (int j = k; j > 0; --j) {
      scanf("%d", &c);
      nodes[c].parent = id;
      nodes[c].depth = nodes[id].depth + 1;
      if (j == 1) {
        nodes[id].child += to_string(c);
        nodes[id].child += "]";
      } else {
        nodes[id].child += to_string(c);
        nodes[id].child += ", ";
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    Node node = nodes[i];
    if (!node.depth) {
      node.parent = -1;
      node.depth = 0;
      node.type = "root";
    } else {
      node.depth = nodes[node.parent].depth + 1;
    }
    printf("node %d: parent = %d, depth = %d, %s, %s\n",
           i,
           node.parent,
           node.depth,
           node.type.c_str(),
           node.child.c_str());
  }
}
