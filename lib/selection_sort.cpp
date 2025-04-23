#include "lib.hpp"

void selection_sort(int a[], int n) {
  for (int i = 0; i < n; i++) {
    int smallest_idx = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[smallest_idx]) {
        smallest_idx = j;
      }
    }
    swap(&a[i], &a[smallest_idx]);
  }
}
