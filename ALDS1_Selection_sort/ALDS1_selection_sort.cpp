#include <stdio.h>
using namespace std;

int selectionSort(int A[], int N) {
  int c = 0;
  for (size_t i = 0; i < N; i++) {
    int minIndex = i;
    for (size_t j = i; j < N; j++) {
      if (A[j] < A[minIndex]) {
        minIndex = j;
      }
    }
    if (i != minIndex) {
      int tmp = A[i];
      A[i] = A[minIndex];
      A[minIndex] = tmp;
      c++;
    }
  }
  return c;
}

void printArray(int A[], int N) {
  for (size_t i = 0; i < N; i++) {
    printf("%d", A[i]);
    if (i == N - 1)
      printf("%s", "\n");
    else
      printf("%s", " ");
  }
}

int main() {
  int N, R[100];
  scanf("%d", &N);
  for (size_t i = 0; i < N; i++)
    scanf("%d", &R[i]);

  int c = selectionSort(R, N);
  printArray(R, N);
  printf("%d\n", c);
  return 0;
}
