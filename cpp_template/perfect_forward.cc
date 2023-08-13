/**
 * Perfect forwarding is used to forward arguments from one function to another,
 * typically in the context of template functions or classes. When forwarding,
 * you want to maintain the original value category of the arguments so that the
 * appropriate constructor (copy or move) is called in the destination function.
 */

#include <iostream>
#include <utility>
#include <vector>

template <typename T>
class Wrapper {
 public:
  template <typename... Args>
  Wrapper(Args&&... args) : data_(std::forward<Args>(args)...) {
    std::cout << "Wrapper constructor" << std::endl;
  }

 private:
  T data_;
};

int main() {
  int x = 42;
  Wrapper<int> w1(x);
  Wrapper<double> w2(3000.0);
  Wrapper<std::vector<int>> w3(10, 20);

  return 0;
}
