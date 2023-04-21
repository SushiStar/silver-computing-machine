#include <iostream>
#include <algorithm>
#include <vector>

int find_just_less_than(const std::vector<double>& v, double x) {
  std::size_t l = 0;
  std::size_t r = v.size() - 1;
  while (l < r) {
    std::size_t m = (l + r) / 2;
    if (v[m] < x) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l - 1;
}

int main() {
  std::vector<double> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("lower bound of 3.5 is located at index: %d\n", find_just_less_than(v, 3.5));
  printf("lower bound of 1 is located at index: %d\n", find_just_less_than(v, 1));

  printf("lower bound of 10 is located at index: %d\n", find_just_less_than(v, 10));
  printf("lower bound of 9 is located at index: %ld\n", std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), 9)));
  printf("%.3f\n", *std::upper_bound(v.begin(), v.end(), 9));

  printf("The distance between the first and second iterator is %ld\n", std::distance(v.begin(), ++v.begin()));

  return 0;
}
