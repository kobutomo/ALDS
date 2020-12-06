#include <bits/stdc++.h>
using namespace std;
#define OPTIMIZE_STDIO ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed
#define endl '\n'

/**
 * n: 数列Aの長さ
 * q: 数列Mの長さ
 */
int n, q, A[20];

bool rec(int i, int m) {

  // mができたとき
  if (m == 0) return true;
  // 最後まで足してもリターンされなかったとき
  if (i >= n) return false;

  // 前半が今の数字を選ばなかった場合，後半が選んだ場合
  // すべてのパターンの中で一つでも m == 0 になるものがあれば真
  bool res = rec(i + 1, m) || rec(i + 1, m - A[i]);

  return res;
}

void solve(istream &cin, ostream &cout) {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int m;
    cin >> m;
    if (rec(0, m)) cout << "yes" << endl;
    else cout << "no" << endl;;
  }
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
}
#endif
