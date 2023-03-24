#include <iostream>
#include <vector>

class Foo {
public:
  // Foo() : a_(0), b_(0) {}
  Foo() = default;

  const double a() const { return a_; }
  const int b() const { return b_; }

private:
  double a_ = 0;
  int b_ = 0;
};

// Create another class Bar that has a Foo member.
class Bar {
public:
  Bar() = default;

  const double a() const { return f_.a(); }
  const int b() const { return f_.b(); }

private:
  Foo f_;
};

// Create another class Baz that contains a vector of Bars.
/**
 * @brief
 * The default constructor of Baz will call the default constructor of Bar,
 * which will call the default constructor of Foo.
 * The default constructor of Foo will initialize a_ and b_ to 0.
 */
class Baz {
public:
  Baz() = default;

  const double a() const { return bars_[0].a(); }
  const int b() const { return bars_[0].b(); }

private:
  std::vector<Bar> bars_;
}; // class Baz

int main() {
  Foo f;
  printf("a is %.3f, b is %d\n", f.a(), f.b());

  Foo ff;
  printf("a is %.3f, b is %d\n", ff.a(), ff.b());

  return 0;
}
