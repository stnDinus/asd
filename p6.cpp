// A11.2022.14433

#include "./lib/lib.hpp"

using namespace std;

int main() {
  LinkedList l;
  l.insert_head(1);
  l.insert_head(2);
  l.insert_head(4);
  l.insert_head(7);

  l.insert_tail(3);

  l.print();

  l.pop_head();

  l.print();

  l.pop_tail();

  l.print();

  l.insert_at(0, 9);

  l.print();

  l.insert_at(2, 8);

  l.print();

  l.insert_at(l.len(), 0);

  l.print();

  l.insert_head(8);
  l.insert_tail(8);

  l.print();

  l.pop(8);

  l.print();

  l.pop_at(1);

  l.print();

  l.pop_at(l.len()-1);

  l.print();

  l.pop_at(0);

  l.print();

  l.deinit();

  return 0;
}
