#include "lib/lib.hpp"

int main() {
  int a[] = {3, 1, 2, 5, 4};
  int n = sizeof(a) / sizeof(a[0]);
  Wrapper(a, n);

  return 0;
}
