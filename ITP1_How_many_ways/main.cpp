#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int ans = 0, n, x;

void rec(int i, int cnt, int acc) {
  if (cnt == 3) {
    if (acc == x) ans++;
    return;
  }
  if (i > n) return;
  rec(i + 1, cnt, acc);
  rec(i + 1, cnt + 1, acc + i);
}

int main() {
  while (true) {
    cin >> n >> x;
    if (n == 0 && x == 0)break;
    rec(1, 0, 0);
    cout << ans << endl;
    ans = 0;
  }
}
