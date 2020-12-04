#include <stdio.h>
using namespace std;

int main()
{
  int n, q, ans = 0, s;
  int S[10000];

  scanf("%d", &n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for (size_t i = 0; i < q; i++)
  {
    scanf("%d", &s);
    for (size_t i = 0; i < n; i++)
    {
      if (S[i] == s)
      {
        ans += 1;
        break;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}