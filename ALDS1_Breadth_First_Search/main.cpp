#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define white 1
#define gray 2

int n, k, u, v, t = 0, D[101], M[101][101], colors[101];
queue<int> Q;

void bfs() {
  Q.push(0);
  colors[0] = gray;
  D[0] = 0;
  while (!Q.empty()) {
    int i = Q.front();
    Q.pop();
    for (int j = 0; j < n; ++j) {
      if (M[i][j] && colors[j] == white) {
        Q.push(j);
        D[j] = D[i] + 1;
        colors[j] = gray;
      }
    }
  }
}

int main() {
  // 隣接行列 M 作成
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      M[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> u >> k;
    for (int j = 0; j < k; ++j) {
      cin >> v;
      M[i][--v] = 1;
    }
  }
  // bfs 初期化
  for (int i = 0; i < n; ++i) {
    colors[i] = white;
    D[i] = -1;
  }
  // bfs
  bfs();
  // 出力
  for (int i = 0; i < n; ++i) cout << i + 1 << " " << D[i] << endl;
}
