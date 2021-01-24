#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  int S;
  cin >> S;
  int h = S / 3600;
  int m = (S % 3600) / 60;
  int s = (S % 3600) % 60;
  printf("%d:%d:%d\n", h, m, s);
}
