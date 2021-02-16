#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m, s, t, q;
int colors[100001];
vector<int> G[100001];

void dfs(int i, int color) {
  colors[i] = color;
  auto children = G[i];
  for (auto child : children) {
    if (colors[child] == 0) dfs(child, color);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  cin >> q;

  for (int i = 0; i < n; ++i) {
    if (colors[i] == 0)dfs(i, i + 1);
  }

  for (int i = 0; i < q; ++i) {
    cin >> s >> t;
    if (colors[s] == colors[t]) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
