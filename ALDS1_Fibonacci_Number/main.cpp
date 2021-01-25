#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int mem[50];

int fib(int n) {
  if (n == 1 || n == 0) return 1;
  if (mem[n]) return mem[n];
  int res = fib(n - 1) + fib(n - 2);
  mem[n] = res;
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", fib(n));
}
