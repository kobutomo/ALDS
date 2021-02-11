#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  int n, k, u, v;
  cin >> n;
  int a[n + 1][n + 1];
  for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= n; ++j) {
	  a[i][j] = 0;
	}
  }
  for (int i = 1; i <= n; ++i) {
	cin >> u >> k;
	for (int j = 0; j < k; ++j) {
	  cin >> v;
	  a[i][v] = 1;
	}
  }

  for (int i = 1; i <= n; ++i) {
	if (i != 1) cout << endl;
	for (int j = 1; j <= n; ++j) {
	  if (j != 1) cout << ' ';
	  cout << a[i][j];
	}
  }
  cout << endl;
}
