#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  int x;
  for (int i = 0; i < 10001; ++i) {
    scanf("%d", &x);
    if (x == 0) {
      return 0;
    } else {
      printf("Case %d: %d\n", i + 1, x);
    }
  }
}
