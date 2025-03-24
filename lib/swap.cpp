#include "lib.hpp"

void swap(int* i, int* j) {
  int tmp = *i;
  *i = *j;
  *j = tmp;
}
