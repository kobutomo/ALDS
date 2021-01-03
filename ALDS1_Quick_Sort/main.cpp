#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Card {
  char suit;
  int value;
};

#define INF 100001;
Card l[100000], r[100000];

void merge(Card s[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++) {
    l[i] = s[left + i];
  }
  for (int i = 0; i < n2; i++) {
    r[i] = s[mid + i];
  }
  l[n1].value = INF;
  r[n2].value = INF;
  int i = 0, j = 0;
  for (int k = left; k < right; ++k) {
    if (l[i].value <= r[j].value) {
      s[k] = l[i];
      i++;
    } else {
      s[k] = r[j];
      j++;
    }
  }
}

void mergeSort(Card s[], int left, int right) {
  if (right - left <= 1) return;

  int mid = (left + right) / 2;
  mergeSort(s, left, mid);
  mergeSort(s, mid, right);
  merge(s, left, mid, right);
}

int partition(Card a[], int p, int r) {
  int x = a[r].value;
  int i = p;
  for (int j = p; j < r; ++j) {
    if (a[j].value <= x) {
      swap(a[i], a[j]);
      i++;
    }
  }
  swap(a[i], a[r]);
  return i;
}

void quickSort(Card a[], int p, int r) {
  if (p >= r) return;
  int q = partition(a, p, r);
  quickSort(a, p, q - 1);
  quickSort(a, q + 1, r);
}

int main() {
  int n, v;
  Card a[100000], b[200000];
  char s[1];
  bool stable = true;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%s %d", s, &v);
    a[i].suit = b[i].suit = s[0];
    a[i].value = b[i].value = v;
  }

  quickSort(a, 0, n - 1);
  mergeSort(b, 0, n);

  for (int i = 0; i < n; ++i) {
    if (a[i].suit != b[i].suit) {
      stable = false;
      break;
    }
  }

  if (stable) printf("%s\n", "Stable");
  else printf("%s\n", "Not stable");
  for (int i = 0; i < n; ++i) {
    cout << a[i].suit << " " << a[i].value << endl;
  }

  return 0;
}
