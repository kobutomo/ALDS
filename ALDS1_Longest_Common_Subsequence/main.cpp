#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int c[1001][1001];

int LCS(string x, string y) {
  int m = x.size(), n = y.size();
  x = " " + x;
  y = " " + y;
  for (int j = 0; j < m; ++j) c[j][0] = 0;
  for (int k = 0; k < n; ++k) c[k][0] = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (x[i] == y[j]) {
        c[i][j] = c[i - 1][j - 1] + 1;
      } else {
        c[i][j] = max(c[i - 1][j], c[i][j - 1]);
      }
    }
  }
  return c[m][n];
}

int main() {
  int q;
  string x, y;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    cin >> x >> y;
    cout << LCS(x, y) << endl;
  }
}
