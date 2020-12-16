#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

double sin60;
double cos60;

void koch(int n, double p1[2], double p2[2]) {
  if (n == 0) return;
  double s[2], t[2], u[2];

  s[0] = (2 * p1[0] + p2[0]) / 3;
  s[1] = (2 * p1[1] + p2[1]) / 3;
  t[0] = (2 * p2[0] + p1[0]) / 3;
  t[1] = (2 * p2[1] + p1[1]) / 3;
  u[0] = cos60 * (t[0] - s[0]) - sin60 * (t[1] - s[1]) + s[0];
  u[1] = sin60 * (t[0] - s[0]) + cos60 * (t[1] - s[1]) + s[1];

  koch(n - 1, p1, s);
  printf("%.8f ", s[0]);
  printf("%.8f\n", s[1]);
  koch(n - 1, s, u);
  printf("%.8f ", u[0]);
  printf("%.8f\n", u[1]);
  koch(n - 1, u, t);
  printf("%.8f ", t[0]);
  printf("%.8f\n", t[1]);
  koch(n - 1, t, p2);
}

int main() {
  sin60 = sqrt(3.0) / 2;
  cos60 = 1.0 / 2;
  int n;
  cin >> n;
  double p1[2], p2[2];
  p1[0] = 0.0;
  p1[1] = 0.0;
  p2[0] = 100.0;
  p2[1] = 0.0;

  printf("%.8f ", p1[0]);
  printf("%.8f\n", p1[1]);
  koch(n, p1, p2);
  printf("%.8f ", p2[0]);
  printf("%.8f\n", p2[1]);

  return 0;
}
