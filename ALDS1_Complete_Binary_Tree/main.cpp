#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void print(int i, int max, int H[]) {
  printf("node %d: key = %d, ", i, H[i]);
  if (i / 2 >= 1)
    printf("parent key = %d, ", H[i / 2]);
  if (i * 2 <= max)
    printf("left key = %d, ", H[i * 2]);
  if (i * 2 + 1 <= max)
    printf("right key = %d, ", H[i * 2 + 1]);
  printf("\n");
}

int main() {
  int n, k, H[501];
  cin >> n;
  for (int i = 1; i < n + 1; ++i) {
    cin >> k;
    H[i] = k;
  }
  for (int i = 1; i < n + 1; ++i) {
    print(i, n, H);
  }
}
