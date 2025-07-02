#include "../lib/lib.hpp"
#include <time.h>
#include <stdlib.h>

unsigned int gen_rand() {
  timespec ts;
  timespec_get(&ts, TIME_UTC);
  srand(ts.tv_nsec);
  return rand() % 100;
}
