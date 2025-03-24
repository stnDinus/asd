#include "lib.hpp"

int binary_search(int sorted_a[], int n, int x) {
  int start_idx = 0;
  int end_idx = n - 1;

  while (start_idx <= end_idx) {
    int mid_idx = (start_idx + end_idx) / 2;
    if (sorted_a[mid_idx] == x) {
      return mid_idx;
    } else if (sorted_a[mid_idx] > x) {
      end_idx = mid_idx - 1;
    } else {
      start_idx = mid_idx + 1;
    }
  }

  return -1;
}
