#include "lib.hpp"

void print_arr(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    cout << a[i] << ", ";
  }
  cout << a[n - 1] << endl;
}
