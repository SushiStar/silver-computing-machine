#include <ios>
#include <iostream>
#include <string>

int main() {
  bool a = true;
  a &= false;
  std::cout << std::boolalpha << a << std::endl;
  return 0;
}
