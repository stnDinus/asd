#include "lib.hpp"

bool is_asc(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] > a[i + 1]) {
      return false;
    }
  }
  return true;
}
