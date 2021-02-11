#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  int n;
  cin >> n;
  int memo[n][n];
  // 同じ行列同士の積はカウントしない。
  for (int i = 0; i < n; ++i) memo[i][i] = 0;

  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; ++i) {
	cin >> P.at(i).first >> P.at(i).second;
  }
  for (int r = 1; r < n; ++r) {
	for (int i = 0; i < r; ++i) {
	  int l = r - i - 1;
	  memo[l][r] = 1 << 21;
	  for (int m = l; m < r; ++m) {
		memo[l][r] = min(
			memo[l][r],
			memo[l][m]
				+ memo[m + 1][r]
				+ P.at(l).first * P.at(m).second * P.at(r).second
		);
	  }
	}
  }
  cout << memo[0][n - 1] << endl;
}
