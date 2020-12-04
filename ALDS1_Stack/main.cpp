#include <bits/stdc++.h>
using namespace std;
#define OPTIMIZE_STDIO ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed
#define endl '\n'

int top, A[101];

int pop() {
  top--;
  return A[top + 1];
}

void push(int v) {
  A[++top] = v;
}

void solve(istream &cin, ostream &cout) {
  top = 0;
  int a, b;
  char s[8];

  while (cin >> s) {
    if (s[0] == '+') {
      b = pop();
      a = pop();
      push(a + b);
    } else if (s[0] == '-') {
      b = pop();
      a = pop();
      push(a - b);
    } else if (s[0] == '*') {
      b = pop();
      a = pop();
      push(a * b);
    } else {
      push(atoi(s));
    }
  }

  cout << pop() << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
}
#endif