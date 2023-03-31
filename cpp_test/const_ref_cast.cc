#include <iostream>

struct A {
  int i;
  A(int i) : i(i) {}
};

struct B : A {
  int j;
  B(int i, int j) : A(i), j(j) {}
};

void printA(const A& a) { std::cout << a.i << std::endl; }

void printB(const B& b) { std::cout << b.i << " " << b.j << std::endl; }

int main() {
  B b(1, 2);
  printA(b);
  printB(b);
  return 0;
}
