#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INFTY (1<<30)

int head = 0, Q[2000001];

void maxHeapify(int i) {
  int l = i * 2;
  int r = l + 1;
  int large = i;
  if (l <= head && Q[l] > Q[i])
    large = l;
  if (l <= head && Q[r] > Q[large])
    large = r;

  if (large != i) {
    swap(Q[i], Q[large]);
    maxHeapify(large);
  }
}

void insert(int key) {
  head++;
  Q[head] = key;
  int i = head;
  while (i > 1 && Q[i] > Q[i / 2]) {
    swap(Q[i], Q[i / 2]);
    i = i / 2;
  }
}

int extract() {
  if (head < 1)
    return -INFTY;
  int target = Q[1];
  Q[1] = Q[head];
  head--;
  maxHeapify(1);
  return target;
};

int main() {
  char com[10];
  int k;
  while (true) {
    scanf("%s", com);
    if (com[0] == 'i') {
      scanf("%d", &k);
      insert(k);
    } else if (com[0] == 'e' && com[1] == 'x') {
      cout << extract() << endl;
    } else if (com[0] == 'e' && com[1] == 'n') break;
  }
  return 0;
}
