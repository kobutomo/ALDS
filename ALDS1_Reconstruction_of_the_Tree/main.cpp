#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define NIL -1

struct Node {
  int parent = NIL, left = NIL, right = NIL;
};
int pos = 0;
vector<int> pre, in, res;

void rec(int start, int end) {
  if (start >= end) return;
  int root = pre.at(pos++);
  int inIdx = distance(in.begin(), find(in.begin(), in.end(), root));
  rec(start, inIdx);
  rec(inIdx + 1, end);
  res.push_back(root);
}

int main() {
  int n, k;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    pre.push_back(k);
  }
  for (int i = 0; i < n; ++i) {
    cin >> k;
    in.push_back(k);
  }
  rec(0, n);
  for (int i = 0; i < n; ++i) {
    if (i != 0) cout << " ";
    cout << res.at(i);
  }
  cout << endl;
}
