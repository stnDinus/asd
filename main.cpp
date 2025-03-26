#include "lib/lib.hpp"
#include <vector>

class Wrapper {
public:
  int* a;
  int n;

  void modify() {
    char mod_arr;
    while(true) {
      cout << "Modify array? (y/n): " << flush; cin >> mod_arr;
      if (mod_arr != 'y') {
        break;
      }

      int mod_idx;
      cout << "Modify index: " << flush; cin >> mod_idx;
      if (mod_idx > n) {
        cout << "Cannot index " << mod_idx << " on array with length " << n << endl;
      } else {
        cout << "Modify value: " << flush; cin >> a[mod_idx];
      }

      cout << "Modified array" << endl;
      print_arr(a, n);
      cout << endl;
    };
  }

  void sort() {
    while (!is_asc(a, n)) {
      cout << "Unsorted array" << endl;
      print_arr(a, n);
      cout << endl;

      int sort_method;
      cout << "Pick sorting algorithm:\n1. Bubble sort\n2. Selection sort\n3. Insertion sort\n>> " << flush; cin >> sort_method;

      switch (sort_method) {
        case 1:
          bubble_sort(a, n);
          break;
        case 2:
          selection_sort(a, n);
          break;
        case 3:
          insertion_sort(a, n);
          break;
      }
    }

    cout << "Sorted array:" << endl;
    print_arr(a, n);
    cout << endl;
  }

  void search() {
    int f;
    int f_idx;
    int search_method;
    char do_search;

    do {
      cout << "Current array" << endl;
      print_arr(a, n);
      cout << endl;

      cout << "Search for: " << flush; cin >> f;

      cout << "Pick searching algorithm:\n1. Linear search\n2. Binary search\n>> " << flush; cin >> search_method;

      switch (search_method) {
        case 1:
          f_idx = linear_search(a, n, f);
          break;
        case 2:
          sort();
          f_idx = binary_search(a, n, f);
          break;
      }

      if (f_idx == -1) {
        cout << "Cannot find " << f << endl;
      } else {
        cout << "Found " << f << " at index " << f_idx << endl;
      }

      cout << "Search again? (y/n): " << flush; cin >> do_search;
    } while (do_search == 'y');
  }

  void init() {
    cout << "Initial array" << endl;
    print_arr(a, n);
    cout << endl;

    modify();
    search();
  }

  Wrapper(int* in_a, int in_n) {
    a = in_a;
    n = in_n;
    init();
  }

  Wrapper() {
    while(true) {
      cout << "Array length: " << flush; cin >> n;
      if (n < 1) {
        cout << "Cannot create array with length " << n << endl;
        continue;
      }
      break;
    };

    vector<int> v{};
    int j;
    for (int i = 0; i < n; i++) {
      cout << "Insert into index " << i << ": " << flush; cin >> j;
      v.push_back(j);
    }

    a = &v[0];
    n = v.size();

    init();
  }
};

int main() {
  int a[] = {5, 7, 8, 100, 1001};
  Wrapper(a, sizeof(a) / sizeof(a[0]));

  // Wrapper();

  return 0;
}
