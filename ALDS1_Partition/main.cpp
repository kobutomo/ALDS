#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int partition(int a[], int p, int r) {
  int x = a[r];
  int i = p;
  for (int j = 0; j < r; ++j) {
    if (a[j] <= x) {
      swap(a[i], a[j]);
      i++;
    }
  }
  swap(a[i], a[r]);
  return i;
}

int main() {
  int n, a[100000], k;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  k = partition(a, 0, n - 1);

  for (int i = 0; i < n; ++i) {
    if (i != 0)
      printf(" ");
    if (i == k)
      printf("[%d]", a[i]);
    else
      printf("%d", a[i]);
  }
  cout << endl;
}
