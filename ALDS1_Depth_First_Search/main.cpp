#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define white 1
#define gray 2
#define black 3

int n, k, u, v, t = 0;
int d[101], f[101];
int M[101][101];
int colors[101];

void dfs(int i) {
  colors[i] = gray;
  d[i] = ++t;
  for (int j = 0; j < n; ++j) {
	if (M[i][j] && colors[j] == white) dfs(j);
  }
  colors[i] = black;
  f[i] = ++t;
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
  // dfs 初期化
  for (int i = 0; i < n; ++i) colors[i] = white;
  // 2つ以上の独立したグラフが存在する可能性があるのでループする
  for (int i = 0; i < n; ++i) {
	if (colors[i] == white) dfs(i);
  }
  // 出力
  for (int i = 0; i < n; ++i)
	cout << i + 1 << " " << d[i] << " " << f[i] << endl;
}
