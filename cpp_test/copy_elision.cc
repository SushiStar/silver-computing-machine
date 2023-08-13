/**
 * The compiler is allowed to elide copies where results are "as if" copies were
 * made. Return Value Optimization (commonly called RVO) is one such instance.
 *
 * RVO is a compile-time optimization because it relies on the copmiler's
 * ability to analyze and transform the code during copmilation. The copmiler's
 * optimization process involves examing the code and making decisions about how
 * to generate the most efficient machine code based on the intended behavior of
 * the program.
 *
 * 1. Caller allocates space on stack for return value, passes the address to
 * callee.
 * 2. Callee constructs the return value in place.
 */

#include <iostream>

struct Holder {
  Holder(int v) : x(v) { std::cout << "Holder(int v) called" << std::endl; }
  Holder(const Holder& h) : x(h.x) {
    std::cout << "Holder(const Holder& h) called" << std::endl;
  }
  int x = 0;
};

Holder get_holder(int x) {
  Holder h0(0);
  if (x > 0) {
    h0.x = 1;
  }

  return h0;
}

int main() {
  Holder h = get_holder(1);
  std::cout << "val is: " << h.x << std::endl;
  return 0;
}
