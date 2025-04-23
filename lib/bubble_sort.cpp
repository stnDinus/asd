#include "lib.hpp"

void bubble_sort(int a[], int n) {
  bool sorted = false;
  while (!sorted) {
    sorted = true;
    for (int j = 0; j < n - 1; j++) {
      if (a[j] > a[j + 1]) {
        sorted = false;
        swap(&a[j], &(a[j + 1]));
      }
    }
  }
}
