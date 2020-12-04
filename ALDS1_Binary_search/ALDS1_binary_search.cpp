#include <stdio.h>
using namespace std;

int main() {
  int n, q, ans = 0, s;
  int S[1000000];

  scanf("%d", &n);
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);

  for (size_t i = 0; i < q; i++) {
    scanf("%d", &s);
    int left = 0;
    int right = n;

    while (left < right) {
      int mid = (left + right) / 2;
      if (S[mid] == s) {
        ans++;
        break;
      } else if (S[mid] < s) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}