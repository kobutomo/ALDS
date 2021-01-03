#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define NIL -1

struct Node {
  int parent = NIL, left = NIL, right = NIL;
};

Node nodes[30];
int S[30];
int D[30];
int H[30];
int dMax;
int rootID;

void getDep(int id, int dep) {
  D[id] = dep;
  Node node = nodes[id];
  if (dep > dMax) dMax = dep;
  if (node.left != NIL) getDep(node.left, dep + 1);
  if (node.right != NIL) getDep(node.right, dep + 1);
}

int getDegree(int id) {
  Node node = nodes[id];
  if (node.left != NIL && node.right != NIL)return 2;
  else if (node.left != NIL || node.right != NIL)return 1;
  else return 0;
}

int getHeight(int id) {
  Node node = nodes[id];
  int h1 = 0, h2 = 0;
  if (node.left != NIL)
    h1 = getHeight(node.left) + 1;
  if (node.right != NIL)
    h2 = getHeight(node.right) + 1;
  int h = max(h1, h2);
  H[id] = h;
  return h;
}

string getType(int id) {
  Node node = nodes[id];
  if (id == rootID) return "root";
  else if (node.left == NIL && node.right == NIL) return "leaf";
  else return "internal node";
}

void print(int id) {
  Node node = nodes[id];
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
         id,
         node.parent,
         S[id],
         getDegree(id), D[id], H[id], getType(id).c_str());
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int id, l, r;
    scanf("%d %d %d", &id, &l, &r);
    nodes[id].left = l;
    nodes[id].right = r;
    nodes[l].parent = id;
    nodes[r].parent = id;
    S[l] = r;
    S[r] = l;
  }
  for (int i = 0; i < n; ++i)
    if (nodes[i].parent == NIL) rootID = i;
  S[rootID] = NIL;
  getDep(rootID, 0);
  getHeight(rootID);
  for (int i = 0; i < n; ++i)
    print(i);
}
