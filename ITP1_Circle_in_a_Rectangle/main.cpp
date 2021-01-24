#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  int W, H, x, y, r;
  scanf("%d %d %d %d %d", &W, &H, &x, &y, &r);
  if (x + r <= W && x - r >= 0) {
    if (y + r <= H && y - r >= 0) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
}