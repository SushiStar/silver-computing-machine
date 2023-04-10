
#include <iostream>

#include "cpp_test/linkage/declaration.h"

int main() {
  std::cout << "Hello World!" << std::endl;
  auto v = SomeSpace::RandomVector();
  std::cout << "v.size() = " << v.size() << std::endl;
  return 0;
}
