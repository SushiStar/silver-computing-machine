#include <array>
#include <iostream>

// Is std::array value initialized?
// Yes

int main() {
  std::array<int, 3> test_ary;
  for (int i = 0; i < 3; ++i) {
    printf("%d ", test_ary[i]);
  }
  printf("\n");

  std::array<int, 3> test_ary2{};
  for (int i = 0; i < 3; ++i) {
    printf("%d ", test_ary2[i]);
  }
  printf("\n");

  return 0;
}
