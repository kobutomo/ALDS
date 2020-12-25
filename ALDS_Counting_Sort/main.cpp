#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int n, a[2100000], b[2100000];

void countingSort(int a[], int b[], int k, int n) {
  int c[k + 1];
  for (int i = 0; i <= k; ++i) c[i] = 0;
  for (int i = 0; i < n; ++i) {
    c[a[i]]++;
  }
  for (int i = 1; i <= k; ++i) c[i] += c[i - 1];
  for (int i = n - 1; i >= 0; --i) {
    b[c[a[i]] - 1] = a[i];
    c[a[i]]--;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    b[i] = a[i] = v;
  }
  countingSort(a, b, 10000, n);
  for (int i = 0; i < n; ++i) {
    if (i != 0)
      printf(" ");
    printf("%d", b[i]);
  }
  cout << endl;
}
