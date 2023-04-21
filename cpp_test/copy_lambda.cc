#include <algorithm>
#include <iostream>
#include <vector>

/**
 * When copying a lambda expression, the captured variables are also copied:
 * If captured by value, then copied by value;
 * If cpaptured by reference, then a reference is copied.
 */

void CopyLambda() {
  int count = 0;
  std::vector<int> v = {1, 2, 3, 4, 5};
  auto lambda = [&](int i) {
    ++count;
    v.push_back(i);
  };

  std::vector<int> v2 = {6, 7, 8, 9, 10};
  auto copy = lambda;
  for_each(v2.begin(), v2.end(), copy);

  for (auto i : v) printf("%d ", i);
  std::cout << std::endl << count << '\n';
}

int main() {
  CopyLambda();
  return 0;
}
