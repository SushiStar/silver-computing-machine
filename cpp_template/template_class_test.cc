#include <iostream>

template <typename T>
class Calculator {
 private:
 public:
  Calculator() {}
  ~Calculator() {}
  T add(T a, T b) { return a + b; }
  T sub(T a, T b) { return a - b; }
  T mul(T a, T b) { return a * b; }
  T div(T a, T b) { return a / b; }
};

int main() {
  Calculator<int> int_cal;
  printf("int_cal.add(1, 2) = %d\n", int_cal.add(1, 2));
  return 0;
}
