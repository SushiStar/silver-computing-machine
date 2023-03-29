#include <iostream>

class Base {
 public:
  Base(int a) : a_(a) {}

  // getter of a_
  int a() const { return a_; }

 private:
  int a_;
};

class Deirved : public Base {
 public:
  Deirved(int a, int b) : Base(a), b_(b) {}

  // getter of b_
  int b() const { return b_; }

 private:
  int b_;
};

void PrintBase(const Base& base) {
  std::cout << "PrintBase" << std::endl;
  std::cout << "a: " << base.a() << std::endl;
}

void PrintDeirved(const Deirved& deirved) {
  std::cout << "PrintDeirved" << std::endl;
  std::cout << "a: " << deirved.a() << std::endl;
  std::cout << "b: " << deirved.b() << std::endl;
}

int main() {
  Deirved d(1, 2);

  PrintBase(d);
  PrintDeirved(d);
  return 0;
}
