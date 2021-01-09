#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define NIL 2000000001

void print(int i, int H[]) {
  printf("node %d: key = %d, ", i, H[i]);
  if (H[i / 2] != NIL)
    printf("parent key = %d, ", H[i / 2]);
  if (H[i * 2] != NIL)
    printf("left key = %d, ", H[i * 2]);
  if (H[i * 2 + 1] != NIL)
    printf("right key = %d, ", H[i * 2 + 1]);
  printf("\n");
}

int main() {
  int n, k, H[501];
  cin >> n;
  for (int & i : H) {
    i = NIL;
  }
  for (int i = 1; i < n + 1; ++i) {
    cin >> k;
    H[i] = k;
  }
  for (int i = 1; i < n + 1; ++i) {
    print(i, H);
  }
}
