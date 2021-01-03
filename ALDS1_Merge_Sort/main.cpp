#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define INF 1000000001;
int l[300000], r[300000];

int c;

void merge(int s[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++) {
    l[i] = s[left + i];
  }
  for (int i = 0; i < n2; i++) {
    r[i] = s[mid + i];
  }
  l[n1] = INF;
  r[n2] = INF;
  int i = 0, j = 0;
  for (int k = left; k < right; ++k) {
    c++;
    if (l[i] <= r[j]) {
      s[k] = l[i];
      i++;
    } else {
      s[k] = r[j];
      j++;
    }
  }
}

void mergeSort(int s[], int left, int right) {
  if (right - left <= 1) return;

  int mid = (left + right) / 2;
  mergeSort(s, left, mid);
  mergeSort(s, mid, right);
  merge(s, left, mid, right);
}

int main() {
  c = 0;
  int n;
  int s[600000];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
  }

  mergeSort(s, 0, n);

  for (int i = 0; i < n; ++i) {
    printf("%lld", s[i]);
    if (i != n - 1)
      printf(" ");
    else
      printf("\n");
  }

  printf("%d\n", c);
}
