#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define INF numeric_limits<int>::max()

int n, u, k, v, c;

// color[v]: 頂点vの訪問状態
// M[u][v] : 隣接行列M．M[u][v]は隣接するuからvへのコスト
// d[v]    : 始点sからvまでの最短コスト
int color[100], d[100], M[100][100];

// s: 始点
auto dijkstra(int s) {
  // 初期化
  for (int i = 0; i < n; ++i) {
    // 訪問状態をクリア
    color[i] = WHITE;
    // すべての頂点への最短コストを大きな数値に
    d[i] = INF;
  }
  // 始点への最短コストは0
  d[s] = 0;

  // 計算
  while (true) {
    int min = INF;
    // cur: 処理中の頂点
    int cur;
    for (int i = 0; i < n; ++i) {
      // 訪問したことがあり,
      // まだfixされてない頂点の中で一番コストの低い頂点を探す
      if (color[i] != BLACK && d[i] < min) {
        min = d[i];
        cur = i;
      }
    }
    // すべて訪問し終えたら終了
    if (min == INF) break;
    // まだfixされてない頂点の中で一番コストが低い
    // → fixできる
    color[cur] = BLACK;
    for (int i = 0; i < n; ++i) {
      // iがcurとつながっているか
      if (M[cur][i] > 0) {
        if (d[cur] + M[cur][i] < d[i]) {
          // 現状のiへの最短コストより
          // curから行くルートのほうがコストが低い場合
          d[i] = d[cur] + M[cur][i];
          color[i] = GRAY;
        }
      }
    }
  }
}

int main() {
  cin >> n;
  // 隣接行列作成
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      M[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> u >> k;
    for (int j = 0; j < k; ++j) {
      cin >> v >> c;
      M[u][v] = c;
    }
  }

  dijkstra(0);

  for (int i = 0; i < n; ++i) {
    cout << i << " " << d[i] << endl;
  }
}
