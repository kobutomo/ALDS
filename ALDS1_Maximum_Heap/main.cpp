#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void maxHeapify(int H[], int i, int max) {
  int l = i * 2;
  int r = l + 1;
  int large = i;
  if (l <= max && H[l] > H[i])
    large = l;
  if (l <= max && H[r] > H[large])
    large = r;

  if (large != i) {
    swap(H[i], H[large]);
    maxHeapify(H, large, max);
  }
}

void buildMaxHeap(int H[], int max) {
  int first = max / 2;
  for (int i = first; i > 0; --i) {
    maxHeapify(H, i, max);
  }
}

int main() {
  int max, H[500001];
  cin >> max;
  for (int i = 1; i < max + 1; ++i) {
    cin >> H[i];
  }
  buildMaxHeap(H, max);
  for (int i = 1; i < max + 1; ++i) {
    cout << " " << H[i];
  }
  cout << endl;
}
