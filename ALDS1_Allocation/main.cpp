#include <bits/stdc++.h>
using namespace std;
#define OPTIMIZE_STDIO ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed
#define endl '\n'

typedef long long llong;
const int MAX = 100000;

/**
* n: 荷物の数
* k: トラックの数
*/
int n, k;
/**
 * 荷物の重さの配列
 */
llong W[MAX];

// P: トラックの最大積載量
int check(llong P) {
  // 既に積んだ荷物
  int i = 0;
  for (int j = 0; j < k; j++) {
    // 現在の積載量
    llong s = 0;

    while (s + W[i] <= P) {
      s += W[i];
      i++;
      // 載せきった瞬間返す
      if (i == n) return i;
    }
  }
  // 載せきれなかった場合の載せた荷物の数
  return i;
}

void solve(istream &cin, ostream &cout) {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> W[i];
  llong left = 0;
  llong right = MAX * 10000 / k;
  llong mid;
  while (right - left > 1) {
    mid = (right + left) / 2;
    int v = check(mid);
    // 積みきれてたら
    if (v >= n) right = mid;
    else left = mid;
  }

  cout << right << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
}
#endif
