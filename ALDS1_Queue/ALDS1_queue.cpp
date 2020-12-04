#include <iostream>
#include <stdio.h>

using namespace std;

static const int MAX = 120000;

typedef struct proc {
  char name[100];
  int time;
} PROC;

int head, tail;
PROC Q[MAX];

PROC dequeue() {
  PROC x = Q[head];
  head = (head + 1) % MAX;
  return x;
}

void enqueue(PROC v) {
  Q[tail] = v;
  tail = (tail + 1) % MAX;
}

int main() {
  int t = 0, n, q;
  cin >> n;
  cin >> q;
  PROC u;

  for (size_t i = 1; i <= n; i++) {
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].time);
  }
  head = 1;
  tail = n + 1;

  while (tail != head) {
    u = dequeue();
    if (u.time > q) {
      t += q;
      u.time -= q;
      enqueue(u);
    } else {
      t += u.time;
      u.time -= u.time;
      printf("%s %d\n", u.name, t);
    }
  }

  return 0;
}