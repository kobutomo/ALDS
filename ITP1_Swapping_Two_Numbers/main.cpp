#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  int x, y;
  for (int i = 0; i < 10001; ++i) {
    scanf("%d %d", &x, &y);
    if (x == 0 && y == 0) {
      return 0;
    } else {
      if (x > y)
        swap(x, y);
      printf("%d %d\n", x, y);
    }
  }
}
