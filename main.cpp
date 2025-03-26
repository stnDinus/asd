#include "lib/lib.hpp"

int main() {
  int a[] = {5, 7, 8, 100, 1001};
  Wrapper(a, sizeof(a) / sizeof(a[0]));

  // Wrapper();

  return 0;
}
